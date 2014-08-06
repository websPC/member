#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "main.h"
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QApplication>



namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void imgload();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
