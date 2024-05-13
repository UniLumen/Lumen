#ifndef TIMESLOTMODEL_H
#define TIMESLOTMODEL_H
#include <vector>
#include <QAbstractListModel>
#include <QObject>
#include <QString>
#include "timeslot.h"
#include <QVector>
// #include <QtCore>
// #include <QQmlListElement>
class TimeSlotModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(double rows READ getRows NOTIFY rowCountChanged);
    Q_PROPERTY(int currentDay  READ getDay WRITE setDay NOTIFY dayChanged);
public:
    enum Roles{
        Place = Qt::UserRole,
        Day,
        timePeriod,
        SectionNumbers,
        Type,
        PrimaryInstructor,
        SecondaryInstructor
    };
    // void setData(const int &day);
    void setDay(const int &day);
    int getDay();
    explicit TimeSlotModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    double getRows() const;

public slots:
    void editSelectedCell(int indexInGrid, QString lmao);
    void addRow();
signals:
    void rowCountChanged();
    void dayChanged();
private:
    std::vector<TimeSlot> timeSlot_data;
    std::vector<TimeSlot> timeSlot_data_sun;
    int currentDay;
};

#endif // TIMESLOTMODEL_H
