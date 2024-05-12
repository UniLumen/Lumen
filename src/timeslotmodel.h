#ifndef TIMESLOTMODEL_H
#define TIMESLOTMODEL_H
#include <vector>
#include <QAbstractListModel>
#include <QObject>
#include <QString>
#include "timeslot.h"
#include <QVector>
class TimeSlotModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(double rows READ getRows NOTIFY rowCountChanged);
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
private:
    std::vector<TimeSlot> timeSlot_data;
};

#endif // TIMESLOTMODEL_H
