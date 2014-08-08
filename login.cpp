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


    QSqlTableModel *board = new QSqlTableModel();
    board->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    board->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    board->setHeaderData(2, Qt::Horizontal, QObject::tr("Major"));
    board->setHeaderData(3, Qt::Horizontal, QObject::tr("Graduate"));
    board->setHeaderData(4, Qt::Horizontal, QObject::tr("Level"));
    Form *new_page = new Form(0, model, board);

    new_page->show();
    this->close();

}
