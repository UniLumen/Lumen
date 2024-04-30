#ifndef COURSEMODEL_H
#define COURSEMODEL_H

#include <vector>
#include <QAbstractListModel>
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
    // void onAddCourse(Course course);
    void onRemoveCourse(int index);


private:
    std::vector<Course> m_data;
};

#endif // COURSEMODEL_H
