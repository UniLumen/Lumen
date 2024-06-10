#ifndef TIMESLOTMODEL_H
#define TIMESLOTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QString>

#include <QList>
#include <QtGlobal>

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

    TimeSlotModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    void setCurrentDay(const int &day);
    void setCurrentTable(const int &table);
    bool exist(const QString &place) const;
    double getRows() const;
    int getCurrentDay() const;
    int getCurrentTable() const;

public slots:
    void editSelectedCell(int indexInGrid,const int &day,const int &sectionNum,const QString &type,const QString &primaryInstructor
                          ,const QString &secondaryInstructor
                          ,const QString &course
                          ,const QString &displayText);
    void addRow(const QString &place);
    void removeRow();
    void onRemoveTimeSlot(int index);

signals:
    void rowCountChanged();
    void currentDayChanged();
    void currentTableChanged();

private:
    int m_currentDay;
    int m_currentTable;
};

#endif // TIMESLOTMODEL_H
