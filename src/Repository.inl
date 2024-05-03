#include "Repository.h"

namespace Lumen {
    template <typename V>
    void Repository<V>::insert(V* value) {
        m_dataMap.insert(value);
    }

    template <typename V>
    template <typename... Args>
    V* Repository<V>::insert(Args... args) {
        V* ptr = new V(args...);
        m_dataMap.insert(ptr);
        return ptr;
    }

    template <typename V>
    QList<V*> Repository<V>::getAll() {
        return m_dataMap.values();
    }

    template <typename V>
    bool Repository<V>::contains(V* value) {
        return m_dataMap.contains(value);
    }

    template <typename V>
    size_t Repository<V>::remove(V* value) {
        return m_dataMap.remove(value);
    }
}

