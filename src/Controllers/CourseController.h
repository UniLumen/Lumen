#pragma once

#include <QObject>

#include "Views/CourseListView.h"
#include "Repository.h"

namespace Lumen {
    class CourseController : public QObject {
        Q_OBJECT

    public:
        CourseController(Repository<QUuid, Course>* repository, CourseListView* courseListView);
        ~CourseController();

    private:
        Repository<QUuid, Course>* m_repository;
        CourseListView* m_courseListView;
    };
}
