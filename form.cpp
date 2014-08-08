#include "main.h"
#include "ui_form.h"
#include <time.h>

Form::Form(QWidget *parent, QSqlTableModel *model, QSqlTableModel *board) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->model = model;
    QSqlQueryModel *Main = new QSqlQueryModel();
    Main->setQuery("select ID,Name,Major,SEX,Birth,HP,FEES,Grd from member where Level > 1");
    ui->tableView_6->setModel(Main);
    this->board = board;

    QSqlQueryModel *view_OB = new QSqlQueryModel();
    QSqlQueryModel *view_YB = new QSqlQueryModel();
    QSqlQueryModel *view_NotMember = new QSqlQueryModel();

    view_OB->setQuery("select ID,Name,Major,SEX,Birth,HP,FEES,Grd from member where Grd = 'YES'");
    ui->tableView_5->setModel(view_OB);

    view_YB->setQuery("select ID,Name,Major,SEX,Birth,HP,FEES,Grd from member where Grd = 'NO'");
    ui->tableView_3->setModel(view_YB);

    view_NotMember->setQuery("select ID,Name,Major,SEX,Birth,HP,FEES,Grd from member where level = 1");
    ui->tableView_4->setModel(view_NotMember);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    edit *new_edit = new edit(0, model);
    new_edit->show();
}

void Form:: on_listWidget_2_itemClicked(QListWidgetItem *item){
   if(item->text() == "+"){
        EventEdit *new_page = new EventEdit();
        new_page->show();
   }
   else if(item->text() == "Today"){
       EventPlus *new_page = new EventPlus();
       new_page->show();
   }
}

void Form::on_calendarWidget_clicked(const QDate &date)
{
    QString day = date.toString("yyyyMMdd");
    EventPlus *new_page = new EventPlus(0, day, board);
    new_page->show();
}

void Form::on_listWidget_clicked(const QModelIndex &index)
{
    EventEdit *new_page = new EventEdit();
    new_page->show();
}

void Form::on_pushButton_5_clicked()
{
    QString temp;
    temp = ui->lineEdit_2->text();

    //QSqlQueryModel *temp = new QSqlQueryModel();
    QSqlQueryModel *view_FindMember = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery;

    query->prepare("select * from member where name = ? ");
    query->addBindValue(temp);
    query->exec();
    view_FindMember->setQuery(*query);
    ui->tableView_6->setModel(view_FindMember);
    ui->lineEdit_2->setText("");
}
void Form::on_pushButton_6_clicked()
{
    QSqlQueryModel *view_returntable = new QSqlQueryModel();
    view_returntable->setQuery("select ID,Name,Major,SEX,Birth,HP,FEES,Grd from member ");
//    ui->tableView_6->setModel(view_returntable);
    ui->tableView_6->setModel(view_returntable);
}

 void Form::on_listWidget_2_activated(const QModelIndex &index)
 {

 }
