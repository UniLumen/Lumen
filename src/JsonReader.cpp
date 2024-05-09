#include "JsonReader.h"

namespace Lumen {
    JsonReader::JsonReader(QJsonValue value) : QJsonValue(value) {}

    bool JsonReader::isDependencyResolved() {
        return m_patchMap.empty();
    }

    bool JsonReader::resolveDependencies() {
        auto it = m_patchMap.begin();
        while (it != m_patchMap.end()) {
            if (resolvePointer(it.value(), it.key())) {
                it = m_patchMap.erase(it);
            } else {
                it++;
            }
        }

        return isDependencyResolved();
    }
}

