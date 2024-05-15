#pragma once

#include <QtCore>

#include "JsonSerializable.h"

namespace Lumen {
    template <typename K, typename V>
    class Repository : public JsonSerializable {
    public:
        Repository() = default;
        virtual ~Repository() {
            qDeleteAll(m_dataMap);
            m_dataMap.clear();
        }

        virtual void insert(const K& key, V* value);
        template <typename... Args>
        V* insert(const K& key, Args... args);

        virtual QList<V*> getAll();
        virtual V* get(const K& key);
        virtual bool contains(const K& key);
        virtual size_t remove(const K& key);

        template <typename Predicate>
        size_t removeIf(Predicate pred);

        QJsonValue toJson() const override {
            QJsonArray arr;
            for (const auto& v : m_dataMap) {
                arr.push_back(v->toJson());
            }
            return arr;
        }

        void fromJson(JsonReader& reader, const QJsonValue& json) override {
            Q_ASSERT(json.isArray());

            QJsonArray arr = json.toArray();
            for (auto v : arr) {
                V* vPtr = new V();
                vPtr->fromJson(reader, v);
                m_dataMap.insert(vPtr->id(), vPtr);
            }
        }

    private:
        QMap<K, V*> m_dataMap;
    };
}

#include "Repository.inl"

