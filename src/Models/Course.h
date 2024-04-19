#pragma once

#include <QtCore>
#include <algorithm>

#include "Doctor.h"
#include "JsonReader.h"
#include "JsonWriter.h"

namespace Lumen {
    class Location;
    class TA;

    struct Lecture {
        int group;
        QDateTime dateTime;
        Location* location;

        inline bool operator==(const Lecture& other) const {
            return group == other.group && dateTime == other.dateTime && location == other.location;
        }

        inline bool operator!=(const Lecture& other) const {
            return !(*this == other);
        }
    };

    struct Section {
        int number;
        QDateTime dateTime;
        Location* location;
        TA* ta;

        inline bool operator==(const Section& other) const {
            return number == other.number && dateTime == other.dateTime && location == other.location && ta == other.ta;
        }

        inline bool operator!=(const Section& other) const {
            return !(*this == other);
        }
    };

    struct Course {
        QString name;
        QString code;
        int creditHours;
        QVector<Lecture> lectures;
        QVector<Section> sections;
        QVector<Doctor*> doctors;

        inline bool operator==(const Course& other) const {
            return name == other.name && code == other.code && creditHours == other.creditHours &&
                   std::equal(lectures.cbegin(), lectures.cend(), other.lectures.cbegin()) &&
                   std::equal(sections.cbegin(), sections.cend(), other.sections.cbegin()) &&
                   std::equal(doctors.cbegin(), doctors.cend(), other.doctors.cbegin());
        }

        inline bool operator!=(const Course& other) const {
            return !(*this == other);
        }
    };

    static JsonWriter& operator<<(JsonWriter& writer, const Course* data) {
        writer.includeMetaData(data);

        writer["name"] = data->name;
        writer["code"] = data->code;
        writer["creditHours"] = data->creditHours;
        writer["lectures"] = writer.toJsonArray(data->lectures);
        writer["sections"] = writer.toJsonArray(data->sections);
        writer["doctors"] = writer.toJsonPointer(data->doctors);

        return writer;
    }

    static JsonReader& operator>>(JsonReader& reader, Course* data) {
        Q_ASSERT(reader.isObject());

        QJsonObject obj = reader.toObject();

        Q_ASSERT(obj.contains("name"));
        Q_ASSERT(obj.contains("code"));
        Q_ASSERT(obj.contains("creditHours"));
        Q_ASSERT(obj.contains("lectures"));
        Q_ASSERT(obj.contains("sections"));
        Q_ASSERT(obj.contains("doctors"));

        reader.parseObject(data);

        data->name = obj.value("name").toString();
        data->code = obj.value("code").toString();
        data->creditHours = obj.value("creditHours").toInt();
        reader.fromJsonArray(obj.value("lectures").toArray(), data->lectures);
        reader.fromJsonArray(obj.value("sections").toArray(), data->sections);
        reader.fromJsonPointer(obj.value("doctors").toArray(), data->doctors);

        return reader;
    }

    static JsonWriter& operator<<(JsonWriter& writer, const Lecture* data) {
        writer.includeMetaData(data);

        writer["group"] = data->group;
        writer["dateTime"] = data->dateTime.toString();
        writer["location"] = writer.toJsonPointer(data->location);

        return writer;
    }

    static JsonReader& operator>>(JsonReader& reader, Lecture* data) {
        Q_ASSERT(reader.isObject());

        QJsonObject obj = reader.toObject();

        Q_ASSERT(obj.contains("group"));
        Q_ASSERT(obj.contains("dateTime"));
        Q_ASSERT(obj.contains("location"));

        reader.parseObject(data);

        data->group = obj.value("group").toInt();
        data->dateTime = QDateTime::fromString(obj.value("dateTime").toString());
        reader.fromJsonPointer(obj.value("location"), &data->location);

        return reader;
    }

    static JsonWriter& operator<<(JsonWriter& writer, const Section* data) {
        writer.includeMetaData(data);

        writer["number"] = data->number;
        writer["dateTime"] = data->dateTime.toString();
        writer["location"] = writer.toJsonPointer(data->location);
        writer["ta"] = writer.toJsonPointer(data->ta);

        return writer;
    }

    static JsonReader& operator>>(JsonReader& reader, Section* data) {
        Q_ASSERT(reader.isObject());

        QJsonObject obj = reader.toObject();

        Q_ASSERT(obj.contains("number"));
        Q_ASSERT(obj.contains("dateTime"));
        Q_ASSERT(obj.contains("location"));
        Q_ASSERT(obj.contains("ta"));

        reader.parseObject(data);

        data->number = obj.value("number").toInt();
        data->dateTime = QDateTime::fromString(obj.value("dateTime").toString());
        reader.fromJsonPointer(obj.value("location"), &data->location);
        reader.fromJsonPointer(obj.value("ta"), &data->ta);

        return reader;
    }
}

