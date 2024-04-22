#include "Repository.h"

namespace Lumen {
    template <typename K, typename V>
    void Repository<K, V>::insert(const K& key, const V& value) {
        m_dataMap.insert(key, QSharedPointer<V>(new V(value)));
    }

    template <typename K, typename V>
    void Repository<K, V>::insert(const K& key, V* value) {
        m_dataMap.insert(key, QSharedPointer<V>(value));
    }

    template <typename K, typename V>
    QList<QSharedPointer<V>> Repository<K, V>::getAll() const {
        return m_dataMap.values();
    }

    template <typename K, typename V>
    QSharedPointer<V> Repository<K, V>::get(const K& key) const {
        return m_dataMap.value(key);
    }

    template <typename K, typename V>
    size_t Repository<K, V>::remove(const K& key) {
        return m_dataMap.remove(key);
    }
}

