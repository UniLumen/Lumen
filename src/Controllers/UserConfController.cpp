#include "UserConfController.h"

#include "Models/Course.h"
#include "Models/CourseAttendance.h"
#include "Models/ICourse.h"
#include "RepositoryManager.h"
#include "UserConf.h"
#include "Views/CourseListView.h"

namespace Lumen {
    UserConfController::UserConfController(UserConf* userConf, CourseListView* courseListView)
        : m_userConf(userConf), m_courseListView(courseListView) {

        QVector<const ICourse*> courses;
        for (const auto& ca : m_userConf->courseAttendances()) {
            courses.push_back(ca);
        }
        m_courseListView->setCourses(courses);

        QObject::connect(m_userConf, &UserConf::courseAttendanceAdded, m_courseListView, &CourseListView::addCourse);
        QObject::connect(m_userConf, &UserConf::courseAttendanceRemoved, m_courseListView, [&](const CourseAttendance* ca) {
            m_courseListView->removeCourse(ca);
        });

        QObject::connect(m_courseListView, &CourseListView::removeCourseRequest, m_userConf, [&](int index) {
            // CAUTION: userView.removeCourse is invoked twice
            const ICourse* removedCourse = m_courseListView->removeCourse(index);
            if (removedCourse) {
                m_userConf->removeCourseAttendance(static_cast<const CourseAttendance*>(removedCourse));
            }
        });

        QObject::connect(m_courseListView, &CourseListView::addCourseAttendanceRequest, this, &UserConfController::addCourseAttendance);
    }

    UserConfController::~UserConfController() {
        QObject::disconnect(m_userConf, &UserConf::courseAttendanceAdded, m_courseListView, &CourseListView::addCourse);
        QObject::disconnect(m_userConf, &UserConf::courseAttendanceRemoved, m_courseListView, nullptr);
        QObject::disconnect(m_courseListView, &CourseListView::removeCourseRequest, m_userConf, nullptr);
        QObject::disconnect(m_courseListView, &CourseListView::addCourseAttendanceRequest, this, &UserConfController::addCourseAttendance);
    }

    void UserConfController::addCourseAttendance(const QUuid& id, bool lecture, bool lab, bool tutorial) {
        RepositoryManager& repoManager = RepositoryManager::instance();

        if (repoManager.courseRepo.contains(id)) {
            Course* course = repoManager.courseRepo.get(id);
            unsigned int attendance = 0;

            if (lecture) {
                attendance |= Course::LectureComponent;
            }
            if (lab) {
                attendance |= Course::LabComponent;
            }
            if (tutorial) {
                attendance |= Course::TutorialComponent;
            }

            CourseAttendance* ca = new CourseAttendance(course, attendance);
            m_userConf->addCourseAttendance(ca);
        }
    }
}
