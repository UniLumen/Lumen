#pragma once

#include <QtCore>

#include "Models/Models.h"
#include "Repository.h"

namespace Lumen {
    class RepositoryManager {
    public:
        RepositoryManager(RepositoryManager&&) = delete;
        RepositoryManager(const RepositoryManager&) = delete;
        RepositoryManager& operator=(RepositoryManager&&) = delete;
        RepositoryManager& operator=(const RepositoryManager&) = delete;

        static RepositoryManager& instance();

        void loadFromMemory(const QByteArray& data);
        void loadFromDisk(const QString& file);
        void saveToDisk(const QString& file);

    public:
        Repository<Location> locationRepo;
        Repository<Doctor> doctorRepo;
        Repository<TA> taRepo;
        Repository<Course> courseRepo;

    private:
        RepositoryManager() = default;

    private:
        static QSharedPointer<RepositoryManager> s_instance;
    };
}

