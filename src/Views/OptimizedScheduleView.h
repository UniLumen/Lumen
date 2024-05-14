#pragma once

#include <QtCore>
#include <Models/OptimizedSchedule.h>

using namespace Lumen;

class OptimizedScheduleView : public QAbstractListModel {
    Q_OBJECT

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

    OptimizedScheduleView(QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    void addOptimizedSchedule(OptimizedSchedule optimizedSchedule);

public slots:
    void createOptimizedSchedules(int selectedGroup, int selectedSection);

private:
    QVector<OptimizedSchedule> m_optimizedSchedules;
};
