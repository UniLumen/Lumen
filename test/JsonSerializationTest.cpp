#include <gtest/gtest.h>
#include <QtCore>
#include <qjsondocument.h>
#include <qjsonobject.h>

#include "JsonReader.h"
#include "JsonWriter.h"

struct InnerStruct {
    QString string;

    bool operator==(const InnerStruct& other) const {
        return string == other.string;
    };

    bool operator!=(const InnerStruct& other) const {
        return !(*this == other);
    };
};

struct OuterStruct {
    QString string;
    InnerStruct inner;
    InnerStruct* ptr;
    QVector<InnerStruct*> ptrs;
    QVector<int> stackAllocatedInts;
    QVector<int*> heapAllocatedInts;

    bool operator==(const OuterStruct& other) const {
        return (string == other.string) && (inner == other.inner) && (*ptr == *other.ptr) 
            && (std::equal(stackAllocatedInts.begin(), stackAllocatedInts.end(), other.stackAllocatedInts.begin()))
            && (std::equal(heapAllocatedInts.begin(), heapAllocatedInts.end(), other.heapAllocatedInts.begin(), [](int* a, int* b) {
                if (a && b) {
                    return *a == *b; 
                } else if (!a && !b) {
                    return true;
                }
                return false;
            }))
            && (std::equal(ptrs.begin(), ptrs.end(), other.ptrs.begin(), [](InnerStruct* a, InnerStruct* b) {
                if (a && b) {
                    return *a == *b; 
                } else if (!a && !b) {
                    return true;
                }
                return false;
            }));
    };

    bool operator!=(const OuterStruct& other) const {
        return !(*this == other);
    };
};

Lumen::JsonWriter& operator<<(Lumen::JsonWriter& writer, const InnerStruct* data) {
    writer.includeMetaData(data);

    writer["string"] = data->string;
    return writer;
}

Lumen::JsonReader& operator>>(Lumen::JsonReader& reader, InnerStruct* data) {
    Q_ASSERT(reader.isObject());

    reader.parseObject(data);
    QJsonObject obj = reader.toObject();

    Q_ASSERT(obj.contains("string"));

    data->string = obj.value("string").toString();

    return reader;
}

Lumen::JsonWriter& operator<<(Lumen::JsonWriter& writer, const OuterStruct* data) {
    writer.includeMetaData(data);

    writer["string"] = data->string;
    writer["inner"] = writer.toJsonObject(&data->inner);
    writer["innerPtr"] = writer.toJsonPointer(data->ptr);
    writer["innerPtrs"] = writer.toJsonPointer(data->ptrs);
    writer["stackAllocatedInts"] = writer.toJsonArray(data->stackAllocatedInts);
    writer["heapAllocatedInts"] = writer.toJsonArray(data->heapAllocatedInts);

    return writer;
}

Lumen::JsonReader& operator>>(Lumen::JsonReader& reader, OuterStruct* data) {
    Q_ASSERT(reader.isObject());

    reader.parseObject(data);
    QJsonObject obj = reader.toObject();

    Q_ASSERT(obj.contains("string"));
    Q_ASSERT(obj.contains("inner"));
    Q_ASSERT(obj.contains("innerPtr"));
    Q_ASSERT(obj.contains("innerPtrs"));
    Q_ASSERT(obj.contains("stackAllocatedInts"));
    Q_ASSERT(obj.contains("heapAllocatedInts"));

    data->string = obj.value("string").toString();
    reader.fromJsonObject(obj.value("inner").toObject(), &data->inner);
    reader.fromJsonPointer(obj.value("innerPtr"), &data->ptr);
    reader.fromJsonPointer(obj.value("innerPtrs").toArray(), data->ptrs);
    reader.fromJsonArray(obj.value("stackAllocatedInts").toArray(), data->stackAllocatedInts);
    reader.fromJsonArray(obj.value("heapAllocatedInts").toArray(), data->heapAllocatedInts);

    return reader;
}

TEST(JsonSerialization, Serialize) {
    QString expectedJson = R"(
    {
        "_id": 0,
        "string": "Outer",
        "innerPtr": 1,
        "innerPtrs": [ 1 ],
        "inner": {
            "_id": 1,
            "string": "Inner"
        },
        "stackAllocatedInts": [ 0 ],
        "heapAllocatedInts": [ 1 ]
    })";


    OuterStruct obj = {};
    obj.string = "Outer";
    obj.inner = { "Inner"};
    obj.ptr = &obj.inner;
    obj.ptrs.append(&obj.inner);
    obj.stackAllocatedInts.push_back(0);
    obj.heapAllocatedInts.push_back(new int(1));

    Lumen::JsonWriter writer;
    writer << &obj;

    QJsonObject expected = QJsonDocument::fromJson(expectedJson.toUtf8()).object();
    QJsonObject actual = writer.object();
    
    for (auto it = expected.begin(); it != expected.end(); it++) {
        EXPECT_TRUE(actual.contains(it.key()));
        EXPECT_EQ(actual.value(it.key()), it.value());
    }
}

TEST(JsonSerialization, Deserialize) {
    QString json = R"(
    {
        "_id": 0,
        "string": "Outer",
        "innerPtr": 1,
        "innerPtrs": [ 1 ],
        "inner": {
            "_id": 1,
            "string": "Inner"
        },
        "stackAllocatedInts": [ 0 ],
        "heapAllocatedInts": [ 1 ]
    })";


    OuterStruct expected = {};
    expected.string = "Outer";
    expected.inner = { "Inner" };
    expected.ptr = &expected.inner;
    expected.ptrs.append(&expected.inner);
    expected.stackAllocatedInts.push_back(0);
    expected.heapAllocatedInts.push_back(new int(1));

    QJsonObject jsonObj = QJsonDocument::fromJson(json.toUtf8()).object();

    OuterStruct actual;
    Lumen::JsonReader reader(jsonObj);
    reader >> &actual;
    
    EXPECT_EQ(expected, actual);
}
