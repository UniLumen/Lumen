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
    std::unordered_map<int, std::vector<TimeSlot>> dayGrid;
    int m_currentDay;
};

#endif // TIMESLOTMODEL_H
