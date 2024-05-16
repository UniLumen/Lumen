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
    Q_PROPERTY(double rows READ getRows NOTIFY rowCountChanged);
    Q_PROPERTY(int currentDay  READ getCurrentDay WRITE setCurrentDay NOTIFY currentDayChanged);
    Q_PROPERTY(int currentTable  READ getCurrentTable WRITE setCurrentTable NOTIFY currentTableChanged);

public:
    enum Roles {
        Place = Qt::UserRole,
        Day,
        TimePeriod,
        SectionNumbers,
        Type,
        PrimaryInstructor,
        SecondaryInstructor,
        Course,
        DisplayText
    };

    static std::unordered_map<int, std::vector<TimeSlot>> dataSet;
    //std::unordered_map<int, std::vector<TimeSlot>> dayGrid;
    std::vector<TimeSlot> dayGrid;
    TimeSlotModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    void setGridDays();
    double getRows() const;
    int getCurrentDay() const;
    void setCurrentDay(const int &day);
    int getCurrentTable() const;
    void setCurrentTable(const int &table);

public slots:
    void editSelectedCell(int indexInGrid,const int &day,const int &sectionNum,const QString &type,const QString &primaryInstructor
                          ,const QString &secondaryInstructor
                          ,const QString &course
                          ,const QString &displayText, const int &timePeriod);
    void addRow(const QString &place);
    void removeRow();
    void onRemoveTimeSlot(int index);
    void addToSchedule();

signals:
    void rowCountChanged();
    void currentDayChanged();
    void currentTableChanged();

private:
    int m_currentDay;
    int m_currentTable;

};

#endif // TIMESLOTMODEL_H
