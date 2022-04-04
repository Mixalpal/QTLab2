#include "editcafedialog.h"
#include "cafe.h"
EditCafeDialog::EditCafeDialog(QWidget* parentWidget): QDialog(parentWidget)
{
    editID = new QLineEdit();
    editName = new QLineEdit();
    editAddress = new QLineEdit();
    editKitchenType = new QLineEdit();
    editTime = new QLineEdit();

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("ID"),1,1);
    mainLayout->addWidget(editID,1,2);
    mainLayout->addWidget(new QLabel("Название"),2,1);
    mainLayout->addWidget(editName,2,2);
    mainLayout->addWidget(new QLabel("Адрес"),3,1);
    mainLayout->addWidget(editAddress,3,2);
    mainLayout->addWidget(new QLabel("Тип кухни"),4,1);
    mainLayout->addWidget(editKitchenType,4,2);
    mainLayout->addWidget(new QLabel("Время работы"),5,1);
    mainLayout->addWidget(editTime,5,2);


    QPushButton* btnOk = new QPushButton("&ОК");

     mainLayout->addWidget(btnOk,6,1,1,2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Данные о кафе");

    int gx = 100;
    int gy = 100;
    if (parentWidget!=nullptr)
    {
        gx = parentWidget->geometry().x();
        gy = parentWidget->geometry().y();

    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditCafeDialog::id() const
{
    return editID->text();
}
QString EditCafeDialog::name() const
{
    return editName->text();
}
QString EditCafeDialog::address() const
{
    return editAddress->text();
}
QString EditCafeDialog::kitchenType() const
{
    return editKitchenType->text();
}
QString EditCafeDialog::time() const
{
    return editTime->text();
}

void EditCafeDialog::SetUpDialog(QString id, QString name, QString address, QString kitchenType, QString time)
{
    editID->setText(id);
    editName->setText(name);
    editAddress->setText(address);
    editKitchenType->setText(kitchenType);
    editTime->setText(time);
}
