#ifndef TIMESLOTMODEL_H
#define TIMESLOTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QString>
#include <vector>
#include <unordered_map>

#include <QList>
#include <QtGlobal>
#include "timeslot.h"

class TimeSlotModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(double rows READ getRows NOTIFY rowCountChanged);//gives no of rows per day
    Q_PROPERTY(int currentDay  READ getCurrentDay WRITE setCurrentDay NOTIFY currentDayChanged);//the day u r on

public:
    enum Roles {
        Place = Qt::UserRole,
        Day,
        TimePeriod,
        SectionNumbers,
        Type,
        PrimaryInstructor,
        SecondaryInstructor
    };

    explicit TimeSlotModel(QObject *parent = nullptr);
    static std::unordered_map<int, std::vector<TimeSlot>> dayGrid;
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    double getRows() const;
    int getCurrentDay() const;
    void setCurrentDay(const int &day);

public slots:
    void editSelectedCell(int indexInGrid, QString lmao);
    void addRow(const QString &place);
    void removeRow();

signals:
    void rowCountChanged();
    void currentDayChanged();

private:
    //will be 12 schedules array
    int m_currentDay;
};

#endif // TIMESLOTMODEL_H
