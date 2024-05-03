#include "Repository.h"

namespace Lumen {
    template <typename V>
    void Repository<V>::insert(const V& value) {
        m_dataMap.insert(QSharedPointer<V>(new V(value)));
    }

    template <typename V>
    void Repository<V>::insert(V* value) {
        m_dataMap.insert(QSharedPointer<V>(value));
    }

    template <typename V>
    QList<QSharedPointer<V>> Repository<V>::getAll() const {
        return m_dataMap.values();
    }

    template <typename V>
    QSharedPointer<V> Repository<V>::get(const V& value) const {
        // return m_dataMap.(value);
    }

    template <typename V>
    size_t Repository<V>::remove(const V& value) {
        // return m_dataMap.remove(value);
    }
}

