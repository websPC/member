#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

static bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if(!db.open()) return false;

    QSqlQuery query;
    query.exec("create table person(id varchar(20) primary key, name varchar(20), major varchar(20),"
               "graduate varchar(20), level int)");
    query.exec("insert into person values('12', '12', 'CSE', 'No', 4)");
    query.exec("insert into person values('00000000', 'AAAAAAAAAA', 'CSE', 'Yes', 2)");
    query.exec("insert into person values('11111111', 'BBBBBBBBBB', 'CSE', 'Yes', 2)");
    query.exec("insert into person values('22222222', 'CCCCCCCCCC', 'CSE', 'No', 2)");
    query.exec("insert into person values('33333333', 'DDDDDDDDDD', 'CSE', 'No', 2)");
    query.exec("insert into person values('44444444', 'EEEEEEEEEE', 'CSE', 'No', 1)");
    query.exec("insert into person values('55555555', 'FFFFFFFFFF', 'CSE', 'Yes', 3)");

    query.exec("create table board(id int primary key, title varchar(20), contents varchar(255),"
               "type varchar(20), date varchar(20))");
    query.exec("insert into board values(0, 'Test1', 'Hello World', 'A', '20140709')");
    query.exec("insert into board values(1, 'Test2', 'Hello World', 'A', '20140709')");
    query.exec("insert into board values(2, 'Test3', 'Hello World', 'A', '20140710')");
    query.exec("insert into board values(3, 'Test4', 'Hello World', 'A', '20140711')");
    query.exec("insert into board values(4, 'Test5', 'Hello World', 'A', '20140712')");

    return true;
}


Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString ID1;
    QString PW1;
    ID1 = ui->lineEdit->text();
    PW1 = ui->lineEdit_2->text();
    createConnection();

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("person");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Major"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Graduate"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Level"));

    QSqlTableModel *board = new QSqlTableModel();
    board->setTable("board");
    board->select();

    QString ID = model->record(0).value("name").toString();
    QString PW = model->record(0).value("id").toString();

    if(ID1 == ID && PW1 == PW && ID1 != NULL)
    {
        createConnection();

        //QSqlQueryModel *QueryModel = new QSqlQueryModel();
        //QueryModel->setQuery("select * from person");

        // model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    Form *new_page = new Form(0, model, board);

   // new_page->ui->tableView_6->setModel(model);

    new_page->show();
    this->close();
    }

    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("Invalid access"));
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
     }
}
