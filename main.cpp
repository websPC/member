#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login l;

    l.show();

    return a.exec();
}
