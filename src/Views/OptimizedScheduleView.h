#pragma once

#include <QtCore>
#include <Models/OptimizedSchedule.h>
#include <stack>
#include "UserConf.h"

using namespace Lumen;

class OptimizedScheduleView : public QAbstractListModel {
    Q_OBJECT

    Q_PROPERTY(QString inputValidationNote MEMBER m_inputValidationNote NOTIFY postValidation)
public:
    enum Roles {
        SelectedGroupRole = Qt::UserRole,
        SelectedSectionRole,
        SaturdayAttendanceRole,
        SundayAttendanceRole,
        MondayAttendanceRole,
        TuesdayAttendanceRole,
        WednesdayAttendanceRole,
        ThursdayAttendanceRole,
        NumberOfDaysToAttendRole
    };

    static Lumen::UserConf *userConf;

    OptimizedScheduleView(QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    void addOptimizedSchedule(OptimizedSchedule optimizedSchedule);

public slots:
    void createOptimizedSchedules(int selectedGroup, int selectedSection);
    void removeOptimizedSchedule(int index);
    void undoAddedOptimizedSchedules();

signals:
    void postValidation();

private:
    QVector<OptimizedSchedule> m_optimizedSchedules;
    QString m_inputValidationNote;
    std::stack<int> m_numberOfOptimizedSchedulesAdded;
};
