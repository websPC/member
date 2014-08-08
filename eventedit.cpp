#include "main.h"
#include "eventedit.h"
#include "ui_eventedit.h"

EventEdit::EventEdit(QWidget *parent, QString title, QSqlTableModel *board, QString date, int row) :
    QWidget(parent),
    ui(new Ui::EventEdit)
{
    ui->setupUi(this);
    this->title = title;
    this->board = board;
    this->date = date;
    this->row = row;
    QSqlQueryModel *query = new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from board where title = ?");
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
    int count = board->rowCount();
    if(row != NULL)
    {

        board->setData(board->index(row, 0), row);
        board->setData(board->index(row, 1), title);
        board->setData(board->index(row, 2), contents);
        board->setData(board->index(row, 3), "A");
        board->setData(board->index(row, 4), date);
        board->submitAll();
    }
    else
    {
        board->insertRows(count, 1);
        board->setData(board->index(count, 0), count);
        board->setData(board->index(count, 1), title);
        board->setData(board->index(count, 2), contents);
        board->setData(board->index(count, 3), "A");
        board->setData(board->index(count, 4), date);
        board->submitAll();
    }
}

void EventEdit::on_textEdit_textChanged()
{

    ui->label_4->setNum(ui->textEdit->toPlainText().length());
}
