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
#include<QTableView>
using namespace std;

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC3");
    db.setDatabaseName("Driver={SQL Server};Server=tcp:q07m0fx4lg.database.windows.net;Port=1443;Database=WPG_DB;");
    db.setUserName("WPG_DB@q07m0fx4lg");
    db.setPassword("!Greatewebs");
    if(!db.open()){
        qDebug()<<"ERROR: "<<QSqlError(db.lastError()).text();
    } else {
        qDebug()<<"Ok";
    }
    QSqlQuery qry;
    if(qry.exec("SELECT * FROM person")){
        while(qry.next()){
            qDebug()<<qry.value(1).toString();
        }
    }
    else{
        qDebug() << "Error = " << QSqlError(db.lastError()).text();
    }
    qry.exec("create table pctest(id int primary key, name varchar(20), major varchar(20))");
    /*
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * [WPG_DB].[dbo].[person]", db);
    */
    db.close();
}
