#include "JsonReader.h"

namespace Lumen {
    template <typename T>
    void JsonReader::fromJsonArray(const QJsonArray& src, QList<T>& dst) {
        // NOTE: Pointer invalidation might be a problem
        dst.resize(src.count());

        auto dstIt = dst.begin();
        for (auto& v : src) {
            JsonReader reader(v);
            reader >> &(*dstIt);

            // Track new ids, and unresolved dependencies
            m_idRefMap.insert(reader.m_idRefMap);
            m_patchMap.insert(reader.m_patchMap);

            dstIt++;
        }

        resolveDependencies();
    }

    template <typename T>
    void JsonReader::fromJsonArray(const QJsonArray& src, QList<T*>& dst) {
        // NOTE: Pointer invalidation might be a problem
        dst.reserve(src.count());

        for (auto& v : src) {
            JsonReader reader(v);
            T* ptr = new T;
            reader >> ptr;
            dst.push_back(ptr);

            // Track new ids, and unresolved dependencies
            m_idRefMap.insert(reader.m_idRefMap);
            m_patchMap.insert(reader.m_patchMap);
        }

        resolveDependencies();
    }

    template <typename T>
    void JsonReader::fromJsonObject(const QJsonObject& src, T* dst) {
        Q_ASSERT(dst);

        JsonReader reader(src);
        reader >> dst;

        // Track new ids, and unresolved dependencies
        m_idRefMap.insert(reader.m_idRefMap);
        m_patchMap.insert(reader.m_patchMap);

        resolveDependencies();
    }

    template <typename T>
    bool JsonReader::fromJsonPointer(const QJsonValue& src, T** dst) {
        Q_ASSERT(dst);

        *dst = nullptr;
        if (!src.isDouble()) {
            qCritical() << "pointer resolution error:" << src.toString("JsonValue") << "is not a JsonPointer";
            return false;
        }

        return resolvePointer(src.toInt(), dst);
    }

    template <typename T>
    bool JsonReader::fromJsonPointer(const QJsonArray& src, QList<T*>& dst) {
        // NOTE: Pointer invalidation might be a problem
        dst.resize(src.count());

        auto dstIt = dst.begin();
        for (auto& v : src) {
            fromJsonPointer(v, &(*dstIt));
            dstIt++;
        }

        return isDependencyResolved();
    }

    template <typename T>
    void JsonReader::parseObject(T* obj) {
        Q_ASSERT(obj);

        int id = this->toObject().value("_id").toInt();
        m_idRefMap.insert(id, obj);
    }

    template <typename T>
    bool JsonReader::resolvePointer(int id, T** dst) {
        Q_ASSERT(dst);

        if (!m_idRefMap.contains(id)) {
            m_patchMap.insert(reinterpret_cast<void**>(dst), id);
            return false;
        }

        *dst = static_cast<T*>(m_idRefMap.value(id));

        return true;
    }

    template <typename T>
    JsonReader& JsonReader::operator>>(T* dst) {
        if constexpr (std::is_same_v<T, int>) {
            *dst = static_cast<T>(this->toInt());
        } else if constexpr (std::is_same_v<T, double>) {
            *dst = static_cast<T>(this->toDouble());
        } else if constexpr (std::is_same_v<T, bool>) {
            *dst = static_cast<T>(this->toBool());
        } else if constexpr (std::is_same_v<T, QString>) {
            *dst = static_cast<T>(this->toString());
        } else {
            Q_ASSERT_X(false, "operator>>", "Type is not supported.");
        }

        return *this;
    }
}

