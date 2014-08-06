#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "main.h"
#include "ui_form.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0, QSqlTableModel *model = 0, QSqlTableModel *board = 0);
    ~Form();
    QSqlTableModel *model;
    QSqlTableModel *board;

    Ui::Form *ui;

private slots:
    void on_pushButton_clicked();
    void on_listWidget_2_itemClicked(QListWidgetItem *item);

    void on_calendarWidget_clicked(const QDate &date);

    void on_listWidget_clicked(const QModelIndex &index);


    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();
};

#endif // FORM_H
