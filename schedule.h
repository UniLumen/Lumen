#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QObject>

class Schedule : public QObject
{
    Q_OBJECT
public:
    explicit Schedule(QObject *parent = nullptr);

signals:
};

#endif // SCHEDULE_H
