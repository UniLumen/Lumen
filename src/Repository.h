#pragma once

#include <QtCore>
#include <qshareddata.h>

#include "JsonReader.h"
#include "JsonWriter.h"

namespace Lumen {
    template <typename K, typename V>
    class Repository {
    public:
        Repository() = default;
        virtual ~Repository() = default;

        virtual void insert(const K& key, const V& value);
        virtual void insert(const K& key, V* value);
        virtual QList<QSharedPointer<V>> getAll() const;
        virtual QSharedPointer<V> get(const K& key) const;
        virtual size_t remove(const K& key);

        friend JsonWriter& operator<<(JsonWriter& writer, const Repository<K, V>* data) {
            for (auto it = data->m_dataMap.constBegin(); it != data->m_dataMap.constEnd(); ++it) {
                const K& key = it.key();
                const QSharedPointer<V>& value = it.value();
                writer[key] = writer.toJsonObject(value.data());
            }

            return writer;
        }

        friend JsonReader& operator>>(JsonReader& reader, Repository<K, V>* data) {
            Q_ASSERT(reader.isObject());

            QJsonObject obj = reader.toObject();

            for (auto it = obj.begin(); it != obj.end(); ++it) {
                K key = it.key();
                V* valuePtr = new V();
                reader.fromJsonObject(it.value().toObject(), valuePtr);
                data->insert(key, valuePtr);
            }

            return reader;
        }

    private:
        QMap<K, QSharedPointer<V>> m_dataMap;
    };
}

#include "Repository.inl"

