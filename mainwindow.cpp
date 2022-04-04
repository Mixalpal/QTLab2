#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include "mymodel.h"
#include "QGridLayout"
#include "linedelegate.h"
#include "editcafedialog.h"
#include "dialogdelegate.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Панфилов 2 Лаб.");
    tableView = new QTableView();
    myModel = new MyModel(this);
    tableView->setModel( myModel );

    DialogDelegate* ddel = new DialogDelegate(nullptr,this);

    lineDelegate* ldel = new lineDelegate();
    tableView->setItemDelegateForColumn(0,ddel);
    tableView->setItemDelegateForColumn(1,ldel);
    tableView->setItemDelegateForColumn(2,ldel);
    tableView->setItemDelegateForColumn(3,ldel);
    tableView->setItemDelegateForColumn(4,ldel);
    tableView->viewport()->setAttribute(Qt::WA_Hover);

    QGridLayout* layout= new QGridLayout();
    layout->addWidget(tableView,1,1,1,2);

    QPushButton* addButton = new QPushButton("Добавить");
    QPushButton* deleteButton = new QPushButton("Удалить");

    layout->addWidget(addButton,2,1);
    layout->addWidget(deleteButton,2,2);

    QObject::connect(addButton,SIGNAL(clicked(bool)),this,SLOT(AddRow()));
    QObject::connect(deleteButton,SIGNAL(clicked(bool)),this,SLOT(DeleteRow()));

    QWidget* wdg=new QWidget();
    wdg->setLayout(layout);

    this->setCentralWidget(wdg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddRow()
{
    EditCafeDialog* addDialog = new EditCafeDialog(this);
    if (addDialog->exec() == QDialog::Accepted)
    {
        Cafe* cafe = new Cafe(addDialog->id(),addDialog->name(),addDialog->address(),addDialog->kitchenType(),addDialog->time(),this);
        myModel->AddCafe(cafe);
    }
    addDialog->deleteLater();
}

void MainWindow::DeleteRow()
{
    QModelIndex selectedRow = tableView->currentIndex();
    myModel->DeleteCafe(selectedRow.row());
}
