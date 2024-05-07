#pragma once

#include <QtCore>

#include "JsonSerializable.h"

namespace Lumen {
    class TA : public JsonSerializable {
    public:
        TA();
        TA(const QString& name, const QString& email);
        TA(const QUuid& id, const QString& name, const QString& email);

        QUuid id() const;
        QString name() const;
        QString email() const;

        void setName(const QString& name);
        bool setEmail(const QString& email);

        QJsonValue toJson() const override;
        void fromJson(JsonReader& reader, const QJsonValue& json) override;

        inline bool operator==(const TA& other) const {
            return m_name == other.m_name && m_email == other.m_email;
        }

        inline bool operator!=(const TA& other) const {
            return !(*this == other);
        }

    private:
        QUuid m_id;
        QString m_name;
        QString m_email;
    };
}

