#ifndef INSTRUCTORMODEL_H
#define INSTRUCTORMODEL_H

#include <vector>
#include <QAbstractListModel>
#include "Instructor.h"

class InstructorModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles{
        Name = Qt::UserRole,
        Email
    };

    InstructorModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void onAddInstructor(QString name, QString email);
    void onRemoveInstructor(int index);

private:
    std::vector<Instructor> m_data;
};

#endif // INSTRUCTORMODEL_H
