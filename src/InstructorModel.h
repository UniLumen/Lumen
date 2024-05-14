#pragma once

#include <QAbstractListModel>

#include "Models/Instructor.h"
#include "RepositoryManager.h"

class InstructorModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles{
        Name = Qt::UserRole,
        Email
    };

    InstructorModel(QObject* parent = nullptr);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void onAddInstructor(QString name, QString email, bool isDoc);
    void onRemoveInstructor(int index);

signals:
    void emailVerificationDone(bool isValidEmail);

private:
    QList<Lumen::Instructor*> m_data;
    Lumen::RepositoryManager& repoManager = Lumen::RepositoryManager::instance();
};
