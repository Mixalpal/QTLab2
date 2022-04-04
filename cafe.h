#ifndef CAFE_H
#define CAFE_H

#include "QString"
#include <QObject>

class Cafe: public QObject
{
    Q_OBJECT

public:
    Cafe(QString ID, QString Name, QString Address, QString kitchenType, QString Time, QObject *parent = nullptr );
    virtual ~Cafe();
    void SetID(QString ID);
    void SetName(QString Name);
    void SetAddress(QString Address);
    void SetType(QString kitchenType);
    void SetTime(QString Time);

    QString ID();
    QString Name();
    QString Address();
    QString KitchenType();
    QString Time();
private:
    QString id;
    QString name;
    QString address;
    QString kitchenType;
    QString time;
};

#endif // CAFE_H
