#include "mymodel.h"

MyModel::MyModel(QObject *parent) : QAbstractTableModel(parent)
{
    Cafe* cafe1 = new Cafe("1","Ну первое кафе","пл. Будапештсткая, 56","Японская","9:00-21:00",this);
    Cafe* cafe2 = new Cafe("2","Второе еще есть","бульвар Гагарина, 30","Пиццер","8:00-23:00",this);
    Cafe* cafe3 = new Cafe("3","И такое еще","пер. Ленина, 66","Там льют кофий","7:00-17:00",this);
    AddCafe(cafe1);
    AddCafe(cafe2);
    AddCafe(cafe3);
}

int MyModel::rowCount(const QModelIndex &) const
{
   return cafes.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 5;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        Cafe* cafe = cafes.at(index.row());
        if (index.column() == 0){Value = cafe->ID();}
        else if (index.column() == 1){Value = cafe->Name();}
        else if (index.column() == 2){Value = cafe->Address();}
        else if (index.column() == 3){Value = cafe->KitchenType();}
        else if (index.column() == 4){Value = cafe->Time();}
        else {Value = "";};
        return Value;
    }
    return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Название");
            case 2:
                return QString("Адрес");
            case 3:
                return QString("Тип кухни");
            case 4:
                return QString("Время работы");
            }
        }
    }
    return QVariant();
}

bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (role == Qt::EditRole)
    {
        Cafe* cafe = cafes.at(index.row());
        if (index.column() == 0){cafe->SetID(value.toString());}
        else if (index.column() == 1){cafe->SetName(value.toString());}
        else if (index.column() == 2){cafe->SetAddress(value.toString());}
        else if (index.column() == 3){cafe->SetType(value.toString());}
        else if (index.column() == 4){cafe->SetTime(value.toString());}
    }
    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void MyModel::AddCafe(Cafe* cafe)
{
    beginInsertRows(QModelIndex(),cafes.size(),cafes.size());
    cafes.append(cafe);
    endInsertRows();
}

void MyModel::DeleteCafe(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    cafes.removeAt(row);
    endRemoveRows();
}
