#include "main.h"
#include "eventplus.h"
#include "ui_eventplus.h"

EventPlus::EventPlus(QWidget *parent, QString date, QSqlTableModel *board) :
    QWidget(parent),
    ui(new Ui::EventPlus)
{
    ui->setupUi(this);
    this->date = date;
    this->board = board;
    for(int i = 0; i < board->rowCount(); i++){
        if(board->record(i).value("date").toString() == date){
            ui->listWidget->addItem(board->record(i).value("title").toString());

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
    QSqlQueryModel *board3 = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery;

    query->prepare("select * from board where title = ? ");
    query->addBindValue(title);
    query->exec();
    board3->setQuery(*query);

    this->row=board3->record(0).value("id").toInt();
    EventEdit *new_page = new EventEdit(0, title, board, date, row);
    new_page->show();
}
