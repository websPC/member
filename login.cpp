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
    model->setTable("person");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Major"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Graduate"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Level"));

    QSqlTableModel *board = new QSqlTableModel();
    Form *new_page = new Form(0, model, board);

    new_page->show();
    this->close();

}
