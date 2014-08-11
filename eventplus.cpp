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
            QLabel *label;
            label = new QLabel;

            label->setStyleSheet("font: 13pt");

            label->setText(schedule->record(i).value("Type").toString()+"\n"+schedule->record(i).value("Contents").toString());
            ui->toolBox_2->addItem(label ,schedule->record(i).value("Title").toString());

        }
    }
}

EventPlus::~EventPlus()
{
    delete ui;
}

void EventPlus::on_pushButton_3_clicked()
{
    this->title = "";
    this->row = 0;
    EventEdit *new_page = new EventEdit(0, title, schedule, date, row);
    new_page->show();
}

void EventPlus::on_pushButton_clicked()
{
    int item = ui->toolBox_2->currentIndex();
    this->title = ui->toolBox_2->itemText(item);
    for(int i = 0; i < schedule->rowCount(); i++){
        if(title == schedule->record(i).value("title").toString() && date == schedule->record(i).value("date").toString())
            this->row = i;
    }
    EventEdit *new_page = new EventEdit(0, title, schedule, date, row);
    new_page->show();
}

void EventPlus::on_pushButton_2_clicked()
{
    int item = ui->toolBox_2->currentIndex();
    this->title = ui->toolBox_2->itemText(item);
    QSqlQuery qry;
    qry.prepare("delete from schedule where title = ? and date = ?");
    qry.addBindValue(title);
    qry.addBindValue(date);
    qry.exec();
    ui->toolBox_2->removeItem(item);
    for(int i = 0; i < schedule->rowCount(); i++){
        if(title == schedule->record(i).value("title").toString() && date == schedule->record(i).value("date").toString())
            schedule->removeRow(i);
    }
}
