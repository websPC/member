#include "main.h"
#include "eventplus.h"
#include "ui_eventplus.h"

EventPlus::EventPlus(QWidget *parent, QString date, QSqlTableModel *schedule) :
    QWidget(parent),
    ui(new Ui::EventPlus)
{
    ui->setupUi(this);
    this->date = date;
    this->schedule =schedule;
    for(int i = 0; i < schedule->rowCount(); i++){
        if(schedule->record(i).value("date").toString() == date){
            ui->listWidget->addItem(schedule->record(i).value("title").toString());

        }
    }
}

EventPlus::~EventPlus()
{
    delete ui;
}

void EventPlus::on_listWidget_itemClicked(QListWidgetItem *item)
{
    this->title = item->text();
    QSqlQueryModel *schedule3 = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery;

    query->prepare("select * from board where title = ? ");
    query->addBindValue(title);
    query->exec();
    schedule3->setQuery(*query);

    this->row=schedule3->record(0).value("id").toInt();
    EventEdit *new_page = new EventEdit(0, title, schedule, date, row);
    new_page->show();
}
