#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "cafe.h"

class EditCafeDialog : public QDialog
{
  Q_OBJECT

private:
    QLineEdit* editID;
    QLineEdit* editName;
    QLineEdit* editAddress;
    QLineEdit* editKitchenType;
    QLineEdit* editTime;

public:
    EditCafeDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString name() const;
    QString address() const;
    QString kitchenType() const;
    QString time() const;

    void SetUpDialog(QString id, QString name, QString address, QString kitchenType, QString time);
};

#endif // INPUTDIALOG_H
