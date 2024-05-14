#pragma once

#include <QObject>

#include "Models/Instructor.h"
#include "Repository.h"
#include "Views/InstructorListView.h"

namespace Lumen {
    class InstructorController : public QObject {
        Q_OBJECT
    public:
        InstructorController(Repository<QUuid, Instructor>* repository, InstructorListView* instructorListView);
        ~InstructorController();

    private:
        Repository<QUuid, Instructor>* m_repository;
        InstructorListView* m_instructorListView;
    };
}
