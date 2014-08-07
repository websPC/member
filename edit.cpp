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
    QString Sex = ui->comboBox->currentText();
    QString HP = ui->textEdit_5->toPlainText();
    QString Birth = ui->textEdit_4->toPlainText();
    QString Fee = ui->comboBox_2->currentText();

    model->insertRows(1, 1);
    model->setData(model->index(1, 0), ID);
    model->setData(model->index(1, 2), Sex);
    model->setData(model->index(1, 3), HP);
    model->setData(model->index(1, 4), Fee);
    model->setData(model->index(1, 6), Grade);
    model->setData(model->index(1, 7), Birth);
    model->setData(model->index(1, 8), Major);
    model->setData(model->index(1, 9), Name);

    model->submitAll();
    //Row Insert 하는거.
}
