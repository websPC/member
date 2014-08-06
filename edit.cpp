#include "main.h"
#include "edit.h"
#include "ui_edit.h"

edit::edit(QWidget *parent, QSqlTableModel *model) :
    QWidget(parent),
    ui(new Ui::edit)
{
    ui->setupUi(this);
    this->model = model;
}

edit::~edit()
{
    delete ui;
}

void edit::on_pushButton_clicked()
{
    QString ID = ui->textEdit->toPlainText();
    QString Name = ui->textEdit_2->toPlainText();
    QString Major = ui->textEdit_3->toPlainText();
    QString Grade = ui->comboBox_3->currentText();

    model->insertRows(1, 1);
    model->setData(model->index(1, 0), ID);
    model->setData(model->index(1, 1), Name);
    model->setData(model->index(1, 2), Major);
    model->setData(model->index(1, 3), Grade);
    model->submitAll();
    //Row Insert 하는거.
}
