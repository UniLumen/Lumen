#ifndef COURSEMODEL_H
#define COURSEMODEL_H

#include <vector>
#include <QAbstractListModel>
#include <QString>
#include "Course.h"


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
    std::vector<Course> m_data;
};

#endif // COURSEMODEL_H
