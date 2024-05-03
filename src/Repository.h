#pragma once

#include <QtCore>

namespace Lumen {
    template <typename V>
    class Repository {
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

    private:
        QSet<V*> m_dataMap;
    };
}

#include "Repository.inl"

