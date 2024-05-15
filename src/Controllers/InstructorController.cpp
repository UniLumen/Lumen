#include "InstructorController.h"

InstructorController::InstructorController(Repository<QUuid, Instructor>* repository, InstructorListView* instructorListView)
    : m_repository(repository), m_instructorListView(instructorListView) {
    QVector<const Instructor*> instructors;
    for (const auto& i : repository->getAll()) {
        instructors.push_back(i);
    }
    m_instructorListView->setInstructors(instructors);

    QObject::connect(m_instructorListView, &InstructorListView::createInstructorRequest, this,
                     [&](const QString& name, const QString& email, bool isDoc) {
                         Instructor* instructor = new Instructor(name, email, isDoc);
                         m_repository->insert(instructor->id(), instructor);
                         m_instructorListView->addInstructor(instructor);
                     });

    QObject::connect(m_instructorListView, &InstructorListView::removeInstructorRequest, this, [&](int index) {
        const Instructor* removedInstructor = m_instructorListView->removeInstructor(index);
        if (removedInstructor) {
            m_repository->remove(removedInstructor->id());
        }
    });
}

InstructorController::~InstructorController() {
    QObject::disconnect(m_instructorListView, nullptr, this, nullptr);
}
