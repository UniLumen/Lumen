#pragma once

#include <QtCore>

namespace Lumen {
    class JsonReader {
    public:
        bool contains(const QUuid& id) const {
            return m_idRefMap.contains(id);
        }

        void registerObject(const QUuid& id, void* address) {
            m_idRefMap.insert(id, address);
        }

        template <typename T>
        T* get(const QUuid& id) const {
            return static_cast<T*>(m_idRefMap.value(id));
        }

    private:
        QHash<QUuid, void*> m_idRefMap;
    };
}
