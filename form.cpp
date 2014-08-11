#include "main.h"
#include "ui_form.h"
#include <time.h>


Form::Form(QWidget *parent, QSqlTableModel *model, QSqlTableModel *schedule, QSqlTableModel *Sonjinho) :
    QWidget(parent),
    ui(new Ui::Form)
{

    ui->setupUi(this);

    this->model = model;
    this->Sonjinho = Sonjinho;
    this->schedule = schedule;
    this->Id = "";

    QSqlQueryModel *Main = new QSqlQueryModel();
    Main->setQuery("select ID,Name,Major,SEX,Birth,HP,FEES,Grd from member where Level > 1");
    ui->tableView_6->setModel(Main);
    ui->tableView_6->resizeColumnsToContents();

    QSqlQueryModel *view_OB = new QSqlQueryModel();
    QSqlQueryModel *view_YB = new QSqlQueryModel();
    QSqlQueryModel *view_NotMember = new QSqlQueryModel();

    view_OB->setQuery("select ID,Name,Major,SEX,Birth,HP,FEES,Grd from member where Level > 1 and Grd = 'YES'");
    ui->tableView_5->setModel(view_OB);
    ui->tableView_5->resizeColumnsToContents();
    view_YB->setQuery("select ID,Name,Major,SEX,Birth,HP,FEES,Grd from member where Level > 1 and Grd = 'NO'");
    ui->tableView_3->setModel(view_YB);
    ui->tableView_3->resizeColumnsToContents();
    view_NotMember->setQuery("select ID,Name,Major,SEX,Birth,HP,FEES,Grd from member where level = 1");
    ui->tableView_4->setModel(view_NotMember);
    ui->tableView_4->resizeColumnsToContents();

    QSqlQueryModel *hello1 = new QSqlQueryModel();
    hello1->setQuery("select distinct GName from Sonjinho");
    for(int i = 0; i < hello1->rowCount(); i++){

        QTabWidget *hu = new QTabWidget();
        hu->setTabPosition(hu->West);
        ui->hello->addTab(hu,hello1->record(i).value("GName").toString());

        QString A[3] ={"Member" ,"Schedule" , "Edit" };
        QTableView *Mem = new QTableView();
        QCalendarWidget *Sch = new QCalendarWidget();
        QTableView *Edi = new QTableView();
        hu->addTab(Mem,A[0]);
        hu->addTab(Sch,A[1]);
        hu->addTab(Edi,A[2]);

        QSqlQueryModel *qMem = new QSqlQueryModel();
        QSqlQuery *qMem1 = new QSqlQuery;
        qMem1->prepare("select * from Sonjinho where GName = ?");
        qMem1->addBindValue(hello1->record(i).value("GName").toString());
        qMem1->exec();
        qMem->setQuery(*qMem1);
        Mem->setModel(qMem);
        Mem->resizeColumnsToContents();

        QSqlQueryModel *qEdi = new QSqlQueryModel();
        qEdi->setQuery("select ID,Name,Major,SEX,Birth,HP,FEES,Grd from member ");
        Edi->setModel(qEdi);
        Edi->resizeColumnsToContents();
        }

    ui->toolBox_2->removeItem(0);
    ui->toolBox_3->removeItem(0);
    ui->toolBox_4->removeItem(0);
    QDate date = QDate::currentDate();
    QString current = date.toString("yyyyMMdd");

    for(int i = 0; i < schedule->rowCount(); i++){
          if(schedule->record(i).value("Date").toString() == current){
            QLabel *label;
            label = new QLabel;

            label->setStyleSheet("font: 13pt");

            label->setText(schedule->record(i).value("Type").toString()+"\n"+schedule->record(i).value("Contents").toString());
            ui->toolBox_2->addItem(label ,schedule->record(i).value("Title").toString());
        }
    }

    current = date.addDays(1).toString("yyyyMMdd");

    for(int i = 0; i < schedule->rowCount(); i++){
          if(schedule->record(i).value("Date").toString() == current){
            QLabel *label;
            label = new QLabel;

            label->setStyleSheet("font: 13pt");

           label->setText(schedule->record(i).value("Type").toString()+"\n"+schedule->record(i).value("Contents").toString());
            ui->toolBox_3->addItem(label ,schedule->record(i).value("Title").toString());
        }
    }
    date.addDays(1);
    current = date.addDays(2).toString("yyyyMMdd");

    for(int i = 0; i < schedule->rowCount(); i++){
          if(schedule->record(i).value("Date").toString() == current){
            QLabel *label;
            label = new QLabel;
            label->setStyleSheet("font: 13pt");

            label->setText(schedule->record(i).value("Type").toString()+"\n"+schedule->record(i).value("Contents").toString());
            ui->toolBox_4->addItem(label ,schedule->record(i).value("Title").toString());
        }
    }


}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    edit *new_edit = new edit(0, model, Id);
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
    EventPlus *new_page = new EventPlus(0, day, schedule);
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
    ui->tableView_6->resizeColumnsToContents();
    ui->lineEdit_2->setText("");
}

void Form::on_pushButton_6_clicked()
{
    QSqlQueryModel *view_returntable = new QSqlQueryModel();
    view_returntable->setQuery("select ID,Name,Major,SEX,Birth,HP,FEES,Grd from member where Level > 1");
    ui->tableView_6->setModel(view_returntable);
    QSqlQueryModel *view_OB = new QSqlQueryModel();
    QSqlQueryModel *view_YB = new QSqlQueryModel();
    QSqlQueryModel *view_NotMember = new QSqlQueryModel();
    view_OB->setQuery("select ID,Name,Major,SEX,Birth,HP,FEES,Grd from member where Level > 1 and Grd = 'YES'");
    ui->tableView_5->setModel(view_OB);
    ui->tableView_5->resizeColumnsToContents();
    view_YB->setQuery("select ID,Name,Major,SEX,Birth,HP,FEES,Grd from member where Level > 1 and Grd = 'NO'");
    ui->tableView_3->setModel(view_YB);
    ui->tableView_3->resizeColumnsToContents();
    view_NotMember->setQuery("select ID,Name,Major,SEX,Birth,HP,FEES,Grd from member where level = 1");
    ui->tableView_4->setModel(view_NotMember);
    ui->tableView_4->resizeColumnsToContents();
}

void Form::on_tableView_6_clicked(const QModelIndex &index)
{
    if(index.column() == 0){
        this->Id = index.data().toString();
    }
}

void Form::on_tableView_5_clicked(const QModelIndex &index)
{
    if(index.column() == 0){
        this->Id = index.data().toString();
    }
}

void Form::on_tableView_3_clicked(const QModelIndex &index)
{
    if(index.column() == 0){
        this->Id = index.data().toString();
    }
}

void Form::on_tableView_4_doubleClicked(const QModelIndex &index)
{
    int count = 0;
    if(index.column() == 0){
        this->Id = index.data().toString();
        for(int i = 0; i < model->rowCount(); i++){
            if(model->record(i).value("ID").toString() == this->Id)
                count = i;
        }
        model->setData(model->index(count, 4), 2);
        model->submitAll();
    }
}

 void Form::on_listWidget_2_activated(const QModelIndex &index)
 {

 }
