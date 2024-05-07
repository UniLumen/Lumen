#pragma once

#include <QtCore>

#include "JsonReader.h"

namespace Lumen {
    class JsonSerializable {
    public:
        ~JsonSerializable() = default;
        virtual QJsonValue toJson() const = 0;
        virtual void fromJson(JsonReader& reader, const QJsonValue& json) = 0;
    };
}
