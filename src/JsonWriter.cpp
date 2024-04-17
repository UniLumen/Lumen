#include "JsonWriter.h"

namespace Lumen {
    JsonWriter::JsonWriter(const QHash<const void*, int>& refIdMap) : m_refIdMap(refIdMap) {}

    void JsonWriter::includeMetaData(const void* value) {
        Q_ASSERT(value);

        int id = m_refIdMap.size();
        m_refIdMap.insert(value, id);
        m_context.insert("_id", id);
    }

    QJsonValue JsonWriter::toJsonPointer(const void* value) {
        Q_ASSERT(value);
        return m_refIdMap.value(value);
    }

    JsonWriter& JsonWriter::operator<<(const QJsonValue& value) {
        m_value = value;
        return *this;
    }
}

