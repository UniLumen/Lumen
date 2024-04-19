#pragma once

#include <QtCore>

#include "JsonReader.h"
#include "JsonWriter.h"

namespace Lumen {
    struct Location {
        QString name;
        QString detailedDescription;

        inline bool operator==(const Location& other) const {
            return name == other.name && detailedDescription == other.detailedDescription;
        }

        inline bool operator!=(const Location& other) const {
            return !(*this == other);
        }
    };

    static JsonWriter& operator<<(JsonWriter& writer, const Location* data) {
        writer.includeMetaData(data);

        writer["name"] = data->name;
        writer["detailedDescription"] = data->detailedDescription;

        return writer;
    }

    static JsonReader& operator>>(JsonReader& reader, Location* data) {
        Q_ASSERT(reader.isObject());

        QJsonObject obj = reader.toObject();

        Q_ASSERT(obj.contains("name"));
        Q_ASSERT(obj.contains("detailedDescription"));

        reader.parseObject(data);

        data->name = obj.value("name").toString();
        data->detailedDescription = obj.value("detailedDescription").toString();

        return reader;
    }
}
