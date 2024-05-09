#pragma once

#include <QtCore>

namespace Lumen {
    template <typename V>
    class Repository {
    public:
        Repository() = default;
        virtual ~Repository() = default;

        virtual void insert(const V& value);
        virtual void insert(V* value);
        virtual QList<QSharedPointer<V>> getAll() const;
        virtual QSharedPointer<V> get(const V& value) const;
        virtual size_t remove(const V& value);

    private:
        QSet<QSharedPointer<V>> m_dataMap;
    };
}

#include "Repository.inl"

