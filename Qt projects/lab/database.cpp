#include "database.h"
#include <sstream>

DataBase::DataBase()
{
}

bool DataBase::add_data(data tempData)
{
    db.push_back(tempData);
    return true;
}
void DataBase::download(){
    std::string res;
    download(res);
    transformStr2BD(res);
}
void DataBase::download1(){
    std::string res;
    download1(res);
    transformStr2BD1(res);
}
/*void DataBase::transformStr2BD1()
{
    int i = 0;
        data data;
        std::string temp;
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("Avia");
        if(!db.open())
            qDebug()<<db.lastError().text();
        QSqlQuery query(db);
        query.exec("CREATE TABLE Aero("
                   "FIO VARCHAR(20) NOT NULL, "
                   "Tour VARCHAR(20) NOT NULL,"
                   "Country VARCHAR(20) NOT NULL,"
                   "Magazine VARCHAR(20) NOT NULL"
                   ")");
        query.exec("SELECT * FROM Aero");
            while(query.next()){
                data.fio = query.value(0).String;
                data.tour = query.value(1).String;
                data.coun = query.value(2).String;
                data.mag = query.value(3).String;
                add_data(data);
            }

    }

void DataBase::transformStr2BD()
{
    int i = 0;
        data data;
        std::string temp;
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("Test");
        if(!db.open())
            qDebug()<<db.lastError().text();
        QSqlQuery query(db);
        query.exec("CREATE TABLE User("
                   "login VARCHAR(20) NOT NULL, "
                   "password VARCHAR(20) NOT NULL,"
                   "level VARCHAR(20) NOT NULL"
                   ")");
        query.exec("SELECT * FROM User");
            while(query.next()){
                data.fio = query.value(0).String;
                data.tour = query.value(1).String;
                data.coun = query.value(2).String;
                add_data(data);
            }
}*/
void DataBase::download(std::string & res){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Test");
    if(!db.open())
        qDebug()<<db.lastError().text();
    QSqlQuery query(db);
    query.exec("CREATE TABLE User("
               "login VARCHAR(20) NOT NULL, "
               "password VARCHAR(20) NOT NULL,"
               "level VARCHAR(20) NOT NULL"
               ")");
    query.exec("SELECT * FROM User");
        while(query.next()){
            res+=query.value(0).toString().toStdString()+'\t'+query.value(1).toString().toStdString()+'\t'+query.value(2).toString().toStdString()+'\n';
        }
}
void DataBase::download1(std::string & res){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Tour");
    if(!db.open())
        qDebug()<<db.lastError().text();
    QSqlQuery query(db);
    query.exec("CREATE TABLE User("
                "tour VARCHAR(20) NOT NULL, "
                "fio VARCHAR(20) NOT NULL,"
                "country VARCHAR(20) NOT NULL,"
                "magazine VARCHAR(20) NOT NULL"
                ")");
    query.exec("SELECT * FROM User");
        while(query.next()){
            res+=query.value(0).toString().toStdString()+'\t'+query.value(1).toString().toStdString()+'\t'+query.value(2).toString().toStdString()+'\t'+query.value(3).toString().toStdString()+'\n';
        }
}
void DataBase::transformStr2BD(std::string db_string)
{
    int i = 0;
        data data;
        std::string temp;
        for (;;){

            if (i >= db_string.size())
                break;
            while (db_string[i] != '\t') {
                temp += db_string[i];
                i++;
            }
            data.tour = temp;
            temp.clear();
            i++;
            if (i >= db_string.size())
                break;
            while (db_string[i] != '\t') {
                temp += db_string[i];
                i++;
            }
            data.fio = temp;
            temp.clear();
            i++;
            if (i >= db_string.size())
                break;
            while (db_string[i] != '\n') {
                temp += db_string[i];
                i++;
            }
            data.coun = temp;
            temp.clear();
            i++;

            add_data(data);
        }
    }
void DataBase::transformStr2BD1(std::string db_string){
    int i = 0;
        data data;
        std::string temp;
        for (;;){
            if (i >= db_string.size())
                break;
            while (db_string[i] != '\t') {
                temp += db_string[i];
                i++;
            }
            data.tour = temp;
            temp.clear();
            i++;
            if (i >= db_string.size())
                break;
            while (db_string[i] != '\t') {
                temp += db_string[i];
                i++;
            }
            data.fio = temp;
            temp.clear();
            i++;
            if (i >= db_string.size())
                break;
            while (db_string[i] != '\t') {
                temp += db_string[i];
                i++;
            }
            data.coun = temp;
            temp.clear();
            i++;
            if (i >= db_string.size())
                break;
            while (db_string[i] != '\n') {
                temp += db_string[i];
                i++;
                if (i >= db_string.size())
                    break;
            }
            data.mag = temp;
            temp.clear();
            i++;
            add_data(data);
        }
}
void DataBase::finding(std::string word){
    std::string t;
    for(int i = 0; i<db.size();i++){
        if(db[i].fio==word||db[i].mag==word||db[i].coun==word||db[i].tour==word){
           t += db[i].tour +'\t'+ db[i].fio+'\t'+db[i].coun+'\t'+db[i].mag+'\n';
        }
    }
    db.clear();
    transformStr2BD(t);
}
void DataBase::finding1(std::string word){
    std::string t;
    for(int i = 0; i<db.size();i++){
        if(db[i].fio==word||db[i].mag==word||db[i].coun==word||db[i].tour==word){
           t += db[i].tour +'\t'+ db[i].fio+'\t'+db[i].coun+'\t'+db[i].mag+'\n';
        }
    }
    db.clear();
    transformStr2BD1(t);
}
/*void DataBase::del(QString id){
    id = id.toInt();
    if((id-1)<=db.size()){

    }
}*/
DataBase::~DataBase(){}
