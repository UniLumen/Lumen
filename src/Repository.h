#pragma once

#include <QtCore>

#include "JsonSerializable.h"

namespace Lumen {
    template <typename V>
    class Repository : public JsonSerializable {
    public:
        Repository() = default;
        virtual ~Repository() {
            qDeleteAll(m_dataMap);
            m_dataMap.clear();
        }

        virtual void insert(V* value);
        template <typename... Args>
        V* insert(Args... args);

        virtual QList<V*> getAll();
        virtual bool contains(V* value);
        virtual size_t remove(V* value);

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
            m_dataMap.reserve(arr.count());
            for (auto v : arr) {
                V* vPtr = new V();
                vPtr->fromJson(reader, v);
                m_dataMap.insert(vPtr);
            }
        }

    private:
        QSet<V*> m_dataMap;
    };
}

#include "Repository.inl"

