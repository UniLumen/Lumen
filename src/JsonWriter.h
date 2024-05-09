#pragma once

#include <QtCore>

namespace Lumen {
    class JsonWriter {
    public:
        JsonWriter() = default;

        const QJsonObject& object() const { return m_context; }

        void includeMetaData(const void* value);

        QJsonValue toJsonPointer(const void* value);

        template <typename T>
        QJsonArray toJsonArray(const QList<T>& list);
        template <typename T>
        QJsonObject toJsonObject(const T* value);
        template <typename T>
        QJsonArray toJsonPointer(const QList<T*>& list);
        template <typename T>
        QJsonArray toJsonPointer(const QList<QSharedPointer<T>>& list);
        template <typename T>
        QJsonArray toJsonPointer(const QList<QWeakPointer<T>>& list);

        QJsonValueRef operator[](const QString& key) { return m_context[key]; }
        JsonWriter& operator<<(const QJsonValue& value);
        template <typename T>
        JsonWriter& operator<<(const T* value);

    private:
        JsonWriter(const QHash<const void*, int>& refIdMap);

    private:
        QJsonObject m_context;
        QJsonValue m_value;
        QHash<const void*, int> m_refIdMap;
    };
}

#include "JsonWriter.inl"

