#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   Form f;
   Form1 f1;

   f.show();
   f1.show();

    return a.exec();
}
