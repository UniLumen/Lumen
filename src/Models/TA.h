#pragma once

#include <QtCore>

#include "JsonReader.h"
#include "JsonWriter.h"

namespace Lumen {
    struct TA {
        QString name;
        QString email;

        inline bool operator==(const TA& other) const {
            return name == other.name && email == other.email;
        }

        inline bool operator!=(const TA& other) const {
            return !(*this == other);
        }
    };

    static JsonWriter& operator<<(JsonWriter& writer, const TA* data) {
        writer.includeMetaData(data);

        writer["name"] = data->name;
        writer["email"] = data->email;

        return writer;
    }

    static JsonReader& operator>>(JsonReader& reader, TA* data) {
        Q_ASSERT(reader.isObject());

        QJsonObject obj = reader.toObject();

        Q_ASSERT(obj.contains("name"));
        Q_ASSERT(obj.contains("email"));

        reader.parseObject(data);

        data->name = obj.value("name").toString();
        data->email = obj.value("email").toString();

        return reader;
    }
}

