#pragma once

#include <QAbstractListModel>

#include "Models/Instructor.h"

using namespace Lumen;

class InstructorListView : public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles{
        Name = Qt::UserRole,
        Email,
        IsDoc
    };

    InstructorListView(QObject* parent = nullptr);
    InstructorListView(const QList<Instructor*>& instructors);
    InstructorListView(const QList<const Instructor*>& instructors);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

public:
    void setInstructors(const QList<const Instructor*>& instructors);

public slots:
    void addInstructor(const Instructor* location);
    const Instructor* removeInstructor(int index);

signals:
    void createInstructorRequest(const QString& name, const QString& email, bool isDoc);
    void removeInstructorRequest(int index);

signals:
    void emailVerificationDone(bool isValidEmail);

private:
    QList<const Instructor*> m_instructors;
};
