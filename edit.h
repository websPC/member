#ifndef EDIT_H
#define EDIT_H

#include "main.h"

namespace Ui {
class edit;
}

class edit : public QWidget
{
    Q_OBJECT

public:
    explicit edit(QWidget *parent = 0, QSqlTableModel *model = 0);
    ~edit();
    QSqlTableModel *model;

private slots:
    void on_pushButton_clicked();

private:
    Ui::edit *ui;
};

#endif // EDIT_H
