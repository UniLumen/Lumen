#include "CourseController.h"

CourseController::CourseController(Repository<QUuid, Course>* repository, UserConf* userConf, CourseListView* courseListView)
    : m_repository(repository), m_userConf(userConf), m_courseListView(courseListView) {
    QVector<const ICourse*> courses;
    for (const auto& ca : repository->getAll()) {
        courses.push_back(ca);
    }
    m_courseListView->setCourses(courses);

    QObject::connect(m_courseListView, &CourseListView::createCourseRequest, this, [&](const CourseCreationDTO& dto) {
        Course* course = dto.toCourse();
        if (!m_repository->contains(course)) {
            m_repository->insert(course->id(), course);
            m_courseListView->addCourse(course);
        } else {
            delete course;
        }
    });

    QObject::connect(m_courseListView, &CourseListView::removeCourseRequest, this, [&](int index) {
        const ICourse* removedCoures = m_courseListView->removeCourse(index);

        if (removedCoures) {
            // Should find a better solution, but this works for now.
            for (auto& ca : m_userConf->courseAttendances()) {
                if (ca->course() == removedCoures) {
                    m_userConf->removeCourseAttendance(ca);
                    break;
                }
            }

            m_repository->remove(removedCoures->id());
        }
    });
}

CourseController::~CourseController() {
    QObject::disconnect(m_courseListView, nullptr, this, nullptr);
}
