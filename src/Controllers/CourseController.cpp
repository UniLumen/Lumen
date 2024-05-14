#include "CourseController.h"

CourseController::CourseController(Repository<QUuid, Course>* repository, CourseListView* courseListView)
    : m_repository(repository), m_courseListView(courseListView) {
    QVector<const ICourse*> courses;
    for (const auto& ca : repository->getAll()) {
        courses.push_back(ca);
    }
    m_courseListView->setCourses(courses);

    QObject::connect(m_courseListView, &CourseListView::createCourseRequest, this, [&](const CourseCreationDTO& dto) {
        Course* course = dto.toCourse();
        m_repository->insert(course->id(), course);
        m_courseListView->addCourse(course);
    });

    QObject::connect(m_courseListView, &CourseListView::removeCourseRequest, this, [&](int index) {
        const ICourse* removedCoures = m_courseListView->removeCourse(index);
        m_repository->remove(removedCoures->id());
    });
}

CourseController::~CourseController() {
    QObject::disconnect(m_courseListView, nullptr, this, nullptr);
}
