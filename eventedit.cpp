#include "main.h"
#include "eventedit.h"
#include "ui_eventedit.h"

EventEdit::EventEdit(QWidget *parent, QString title, QSqlTableModel *schedule, QString date, int row) :
    QWidget(parent),
    ui(new Ui::EventEdit)
{
    ui->setupUi(this);
    this->title = title;
    this->schedule = schedule;
    this->date = date;
    this->row = row;
    QSqlQueryModel *query = new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from schedule where title = ?");
    qry.addBindValue(title);
    qry.exec();
    query->setQuery(qry);
    ui->lineEdit->setText(query->record(0).value("title").toString());
    ui->textEdit->setText(query->record(0).value("contents").toString());
}

EventEdit::~EventEdit()
{
    delete ui;
}

void EventEdit::on_pushButton_clicked()
{
    QString title = ui->lineEdit->text();
    QString contents = ui->textEdit->toPlainText();
    int count = schedule->rowCount();
    int max = count;
    int type = 0;
    if(ui->radioButton->isChecked())
        type = 0;
    else if(ui->radioButton_2->isChecked())
        type = 1;
    else if(ui->radioButton_3->isChecked())
        type = 2;
    else if(ui->radioButton_4->isChecked())
        type = 3;
    if(max != 0){
        for(int i = 0; i < schedule->rowCount(); i++){
            if(max < schedule->record(i).value("ID").toInt())
                max = schedule->record(i).value("ID").toInt();
        }
        max++;
    }
    else
        max = 0;
    if(row != NULL)
    {
        schedule->setData(schedule->index(row, 0), row);
        schedule->setData(schedule->index(row, 1), row);
        schedule->setData(schedule->index(row, 2), date);
        schedule->setData(schedule->index(row, 3), title);
        schedule->setData(schedule->index(row, 4), type);
        schedule->setData(schedule->index(row, 5), contents);
        schedule->submitAll();
    }
    else
    {
        schedule->insertRows(count, 1);
        schedule->setData(schedule->index(count, 0), max);
        schedule->setData(schedule->index(count, 1), max);
        schedule->setData(schedule->index(count, 2), date);
        schedule->setData(schedule->index(count, 3), title);
        schedule->setData(schedule->index(count, 4), type);
        schedule->setData(schedule->index(count, 5), contents);
        schedule->submitAll();
    }
}

void EventEdit::on_textEdit_textChanged()
{
    ui->label_4->setNum(ui->textEdit->toPlainText().length());
}
