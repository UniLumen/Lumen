#pragma once

#include <QObject>

#include "Repository.h"
#include "UserConf.h"
#include "Views/CourseListView.h"

namespace Lumen {
    class CourseController : public QObject {
        Q_OBJECT

    public:
        CourseController(Repository<QUuid, Course>* repository, UserConf* userConf, CourseListView* courseListView);
        ~CourseController();

    private:
        Repository<QUuid, Course>* m_repository;
        CourseListView* m_courseListView;
        UserConf* m_userConf;
    };
}
