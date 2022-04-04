#include "cafe.h"

Cafe::Cafe(QString ID, QString Name, QString Address, QString KitchenType, QString Time, QObject *parent): QObject(parent)
{
    id = ID;
    name = Name;
    address = Address;
    kitchenType = KitchenType;
    time = Time;
}

void Cafe::SetID(QString ID)
{
    id = ID;
}
void Cafe::SetName(QString Name)
{
    name = Name;
}
void Cafe::SetAddress(QString Address)
{
    address = Address;
}
void Cafe::SetType(QString Type)
{
    kitchenType = Type;
}
void Cafe::SetTime(QString Time)
{
    time = Time;
}
QString Cafe::ID()
{
    return id;
}
QString Cafe::Name()
{
    return name;
}
QString Cafe::Address()
{
    return address;
}
QString Cafe::KitchenType()
{
    return kitchenType;
}
QString Cafe::Time()
{
    return time;
}
 Cafe::~Cafe()
{
}
