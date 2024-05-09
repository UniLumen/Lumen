#pragma once

#include <QtCore>

namespace Lumen {
    class JsonReader : public QJsonValue {
    public:
        JsonReader(QJsonValue value);

        bool isDependencyResolved();
        bool resolveDependencies();

        template <typename T>
        void fromJsonArray(const QJsonArray& src, QList<T>& dst);
        template <typename T>
        void fromJsonArray(const QJsonArray& src, QList<T*>& dst);
        template <typename T>
        void fromJsonArray(const QJsonArray& src, std::function<void(T*)> func);
        template <typename T>
        void fromJsonObject(const QJsonObject& src, T* dst);
        template <typename T>
        bool fromJsonPointer(const QJsonValue& src, T** dst);
        template <typename T>
        bool fromJsonPointer(const QJsonArray& src, QList<T*>& dst);

        template <typename T>
        void parseObject(T* obj);

        template <typename T>
        JsonReader& operator>>(T* dst);

    private:
        template <typename T>
        bool resolvePointer(int id, T** dst);

    private:
        QHash<int, void*> m_idRefMap;
        QHash<void**, int> m_patchMap;
    };
}

#include "JsonReader.inl"

