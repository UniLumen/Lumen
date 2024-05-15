#include "Repository.h"

namespace Lumen {
    template <typename K, typename V>
    void Repository<K, V>::insert(const K& key, V* value) {
        m_dataMap.insert(key, value);
    }

    template <typename K, typename V>
    template <typename... Args>
    V* Repository<K, V>::insert(const K& key, Args... args) {
        V* ptr = new V(args...);
        m_dataMap.insert(key , ptr);
        return ptr;
    }

    template <typename K, typename V>
    QList<V*> Repository<K, V>::getAll() {
        return m_dataMap.values();
    }

    template <typename K, typename V>
    V* Repository<K, V>::get(const K& key) {
        return m_dataMap.value(key);
    }

    template <typename K, typename V>
    bool Repository<K, V>::contains(const K& key) {
        return m_dataMap.contains(key);
    }

    template <typename K, typename V>
    size_t Repository<K, V>::remove(const K& key) {
        return m_dataMap.remove(key);
    }

    template <typename K, typename V>
    template <typename Predicate>
    size_t Repository<K, V>::removeIf(Predicate pred) {
        return m_dataMap.removeIf(pred);
    }
}

