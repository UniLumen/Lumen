#ifndef COURSEMODEL_H
#define COURSEMODEL_H

#include <QAbstractListModel>
#include <QString>
#include "Models/Course.h"
#include "RepositoryManager.h"


class CourseModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles{
        Name = Qt::UserRole,
        CreditHours,
        YearOfStudy,
        Department
    };

    CourseModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void onAddCourse(QString name, QString year, QString dept, QString credits, bool hasLab, bool hasTutorial);
    void onRemoveCourse(int index);


private:
    QList<Lumen::Course*> m_data;
    Lumen::RepositoryManager& repoManager = Lumen::RepositoryManager::instance();
};

#endif // COURSEMODEL_H
