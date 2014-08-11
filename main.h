#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <QApplication>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QWidget>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>
#include "form.h"
#include "eventplus.h"
#include "eventedit.h"
#include "edit.h"
#include "login.h"
#include <QFontDatabase>
static bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={SQL Server};Server=tcp:q07m0fx4lg.database.windows.net;Port=1433;Database=WPG_DB;Uid=WPG_DB@q07m0fx4lg;Pwd=!Greatewebs;Encrypt=yes;Connection Timeout=30;");
    if(!db.open()) return false;
    return true;
}


#endif // MAIN_H
