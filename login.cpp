#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    createConnection();
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("member");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PW"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SEX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("HP"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("FEES"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Level"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Grd"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Birth"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Image"));


    QSqlTableModel *schedule = new QSqlTableModel();
    schedule->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    schedule->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    schedule->setHeaderData(2, Qt::Horizontal, QObject::tr("Major"));
    schedule->setHeaderData(3, Qt::Horizontal, QObject::tr("Graduate"));
    schedule->setHeaderData(4, Qt::Horizontal, QObject::tr("Level"));
    Form *new_page = new Form(0, model, schedule);

    new_page->show();
    this->close();

}
