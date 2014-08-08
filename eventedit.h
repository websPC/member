#ifndef EVENTEDIT_H
#define EVENTEDIT_H

#include "main.h"
#include <QWidget>

namespace Ui {
class EventEdit;
}

class EventEdit : public QWidget
{
    Q_OBJECT

public :
    QString title;
    QSqlTableModel *schedule;
    QString date;
    int row;

public:
    explicit EventEdit(QWidget *parent = 0, QString title = NULL, QSqlTableModel *schedule = 0, QString date = 0, int row = 0);
    ~EventEdit();
    Ui::EventEdit *ui;
private slots:
    void on_pushButton_clicked();
    void on_textEdit_textChanged();
};

#endif // EVENTEDIT_H
