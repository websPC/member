#ifndef EVENTPLUS_H
#define EVENTPLUS_H

#include "main.h"
#include <QWidget>
#include "ui_eventplus.h"

namespace Ui {
class EventPlus;
}

class EventPlus : public QWidget
{
    Q_OBJECT

public:
    QString date;
    QSqlTableModel *schedule;
    QString title;
    int row;

public:
    explicit EventPlus(QWidget *parent = 0, QString date = NULL, QSqlTableModel *schedule = NULL);
    ~EventPlus();
    Ui::EventPlus *ui;

private slots:
   // void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // EVENTPLUS_H
