#include "main.h"
#include "edit.h"
#include "ui_edit.h"

edit::edit(QWidget *parent, QSqlTableModel *model, QString Id) :
    QWidget(parent),
    ui(new Ui::edit)
{
    ui->setupUi(this);
    this->model = model;
    this->Id = Id;

    QString Name;
    QString Major;
    QString Grade;
    QString Sex;
    QString HP;
    QString Birth;
    QString Fee;

    for(int i = 0; i < model->rowCount(); i++){
        if(model->record(i).value("ID").toString() == Id){
            Name = model->record(i).value("Name").toString();
            Major = model->record(i).value("Major").toString();
            Grade = model->record(i).value("Grd").toString();
            Sex = model->record(i).value("SEX").toString();
            HP = model->record(i).value("HP").toString();
            Birth = model->record(i).value("Birth").toString();
            Fee = model->record(i).value("FEES").toString();
        }
    }

    ui->textEdit->setText(Id);
    ui->textEdit_2->setText(Name);
    ui->textEdit_3->setText(Major);
    ui->comboBox_3->setCurrentText(Grade);
    ui->comboBox->setCurrentText(Sex);
    ui->textEdit_5->setText(HP);
    ui->textEdit_4->setText(Birth);
    ui->comboBox_2->setCurrentText(Fee);

}

edit::~edit()
{
    delete ui;
}


void edit::on_pushButton_clicked()
{
    int count = 0;
    QString ID = ui->textEdit->toPlainText();
    QString Name = ui->textEdit_2->toPlainText();
    QString Major = ui->textEdit_3->toPlainText();
    QString Grade = ui->comboBox_3->currentText();
    QString Sex = ui->comboBox->currentText();
    QString HP = ui->textEdit_5->toPlainText();
    QString Birth = ui->textEdit_4->toPlainText();
    QString Fee = ui->comboBox_2->currentText();

    if(Id == ""){
        model->insertRows(1, 1);
        model->setData(model->index(1, 0), ID);
        model->setData(model->index(1, 1), Sex);
        model->setData(model->index(1, 2), HP);
        model->setData(model->index(1, 3), Fee);
        model->setData(model->index(1, 4), 1);
        model->setData(model->index(1, 5), Grade);
        model->setData(model->index(1, 6), Birth);
        model->setData(model->index(1, 7), Major);
        model->setData(model->index(1, 8), Name);
    }
    else{
        for(int i = 0; i < model->rowCount(); i++){
            if(model->record(i).value("ID").toString() == this->Id)
                count = i;
        }
        model->setData(model->index(count, 0), ID);
        model->setData(model->index(count, 1), Sex);
        model->setData(model->index(count, 2), HP);
        model->setData(model->index(count, 3), Fee);
        model->setData(model->index(count, 4), 2);
        model->setData(model->index(count, 5), Grade);
        model->setData(model->index(count, 6), Birth);
        model->setData(model->index(count, 7), Major);
        model->setData(model->index(count, 8), Name);
    }

    model->submitAll();
    //Row Insert 하는거.
}
