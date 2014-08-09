#include "main.h"
#include "eventplus.h"
#include "ui_eventplus.h"

EventPlus::EventPlus(QWidget *parent, QString date, QSqlTableModel *schedule) :
    QWidget(parent),
    ui(new Ui::EventPlus)
{
    ui->setupUi(this);
    this->date = date;
    this->schedule = schedule;

    ui->label->setText(date.left(4)+"/"+date.mid(4,2)+"/"+date.right(2));
    ui->toolBox_2->removeItem(0);
    for(int i = 0; i < schedule->rowCount(); i++){
        if(schedule->record(i).value("Date").toString() == date){
//            ui->listWidget->addItem(schedule->record(i).value("Title").toString());
            QLabel *label;
            label = new QLabel;
            label->setStyleSheet("font: 13pt \"1훈버거버거 Regular\";");
            label->setText(schedule->record(i).value("Contents").toString());
            ui->toolBox_2->addItem(label ,schedule->record(i).value("Title").toString());

        }
    }

}

EventPlus::~EventPlus()
{
    delete ui;
}

//void EventPlus::on_listWidget_itemClicked(QListWidgetItem *item)
//{
//    this->title = item->text();
//    QSqlQueryModel *board3 = new QSqlQueryModel();
//    QSqlQuery *query = new QSqlQuery;

//    query->prepare("select * from schedule where Title = ? ");
//    query->addBindValue(title);
//    query->exec();
//    board3->setQuery(*query);

//    this->row=board3->record(0).value("id").toInt();
//    EventEdit *new_page = new EventEdit(0, title, schedule, date, row);
//    new_page->show();
//}

void EventPlus::on_pushButton_3_clicked()
{
        this->title = "";
    this->row = 0;
        EventEdit *new_page = new EventEdit(0, title, schedule, date, row);
        new_page->show();
}
