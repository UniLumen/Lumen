#include "JsonWriter.h"

#include <algorithm>

namespace Lumen {
    template <typename T>
    QJsonArray JsonWriter::toJsonArray(const QList<T>& list) {
        QJsonArray arr;

        for (auto it = list.cbegin(); it != list.cend(); it++) {
            JsonWriter writer(m_refIdMap);

            if constexpr (std::is_pointer_v<T>) {
                writer << *it;
            } else {
                writer << &(*it);
            }

            if (!writer.m_context.isEmpty()) {
                arr.append(writer.m_context);
            } else {
                arr.append(writer.m_value);
            }

            // Track new refIds
            m_refIdMap.insert(writer.m_refIdMap);
        }

        return arr;
    }

    template <typename T>
    QJsonObject JsonWriter::toJsonObject(const T* value) {
        Q_ASSERT(value);

        JsonWriter writer(m_refIdMap);
        writer << value;

        // Track new refIds
        m_refIdMap.insert(writer.m_refIdMap);

        return writer.object();
    }

    template <typename T>
    QJsonArray JsonWriter::toJsonPointer(const QList<T*>& list) {
        QJsonArray arr;
        for (const T* t : list) {
            arr.append(m_refIdMap.value(t));
        }
        return arr;
    }

    template <typename T>
    QJsonArray JsonWriter::toJsonPointer(const QList<QSharedPointer<T>>& list) {
        QVector<T*> raw;
        std::transform(list.cbegin(), list.cend(), std::back_inserter(raw),
                       [](const QSharedPointer<T>& ptr) { return ptr.data(); });
        return toJsonPointer(raw);
    }

    template <typename T>
    QJsonArray JsonWriter::toJsonPointer(const QList<QWeakPointer<T>>& list) {
        QVector<T*> raw;
        QWeakPointer<int> p;
        std::transform(list.cbegin(), list.cend(), std::back_inserter(raw),
                       [](const QWeakPointer<T>& ptr) { return ptr.lock().data(); });
        return toJsonPointer(raw);
    }

    template <typename T>
    JsonWriter& JsonWriter::operator<<(const T* value) {
        Q_ASSERT(value);

        if constexpr (std::is_constructible_v<QJsonValue, T>) {
            m_value = *value;
        } else {
            Q_ASSERT_X(false, "operator<<", "Type is not supported");
        }

        return *this;
    }
}

