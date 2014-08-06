#include <QtCore/QCoreApplication>
#include<QWidget>
#include<ostream>
#include<iostream>
#include<QFile>
#include<QTime>
#include <stdio.h>
#include <QTextStream>
#include<QSqlDatabase>
#include<QSqlDriver>
#include<QSqlError>
#include<QSqlQuery>
#include<QDebug>
using namespace std;

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={SQL Server Native Client 10.0};Server=tcp:q07m0fx4lg.database.windows.net;1433;Database=WPG_DB;Uid=WPG_DB@q07m0fx4lg;Pwd=!Greatewebs;Encrypt=yes;Connection Timeout=30;");
    //db.setPort(1443);
    //db.setUserName("WPG_DB@q07m0fx4lg");
    //db.setPassword("!Greatewebs");
    if(!db.open()){
        qDebug()<<"ERROR: "<<QSqlError(db.lastError()).text();
    } else {
        qDebug()<<"Ok";
    }
    QSqlQuery query;
    if(query.exec("SELECT * FROM [WPG_DB].[dbo].[person]")){
        while(query.next()){
            qDebug()<<query.value(1).toString();
        }
    }
    else{
        qDebug() << "Error = " << QSqlError(db.lastError()).text();
    }
    db.close();
         return true;
}
