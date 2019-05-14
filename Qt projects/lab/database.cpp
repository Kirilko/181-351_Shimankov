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
void DataBase::download(QString name){
    std::string res;
    download(name,res);
    transformStr2BD(name,res);
}
/*void DataBase::download(){
    std::string res;
    download(res);
    transformStr2BD(res);
}
void DataBase::download1(){
    std::string res;
    download1(res);
    transformStr2BD1(res);
}*/

void DataBase::download(QString name,std::string & res){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(name);
    if(!db.open())
        qDebug()<<db.lastError().text();
    QSqlQuery query(db);
    if (name == "Test"){
        query.exec("CREATE TABLE User("
                   "login VARCHAR(20) NOT NULL, "
                   "password VARCHAR(20) NOT NULL,"
                   "level VARCHAR(20) NOT NULL"
                   ")");
        query.exec("SELECT * FROM User");
            while(query.next()){
                res+=query.value(0).toString().toStdString()+'\t'+query.value(1).toString().toStdString()+'\t'+query.value(2).toString().toStdString()+'\n';
            }
    } else if(name == "Tour"){
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
}
/*void DataBase::download(std::string & res){
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
}*/
void DataBase::transformStr2BD(QString name,std::string db_string){
    int i = 0;
        data data;
        std::string temp;
        if(name == "Test"){
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
        } else if(name == "Tour"){
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
}
/*void DataBase::transformStr2BD(std::string db_string)
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
}*/
void DataBase::finding(QString name, std::string word){
    std::string t;
    if(name == "Test"){
        for(int i = 0; i<db.size();i++){
            if(db[i].fio==word||db[i].mag==word||db[i].coun==word||db[i].tour==word){
               t += db[i].tour +'\t'+ db[i].fio+'\t'+db[i].coun+'\t'+db[i].mag+'\n';
            }
        }
    } else if(name == "Tour"){
        for(int i = 0; i<db.size();i++){
            if(db[i].fio==word||db[i].mag==word||db[i].coun==word||db[i].tour==word){
               t += db[i].tour +'\t'+ db[i].fio+'\t'+db[i].coun+'\t'+db[i].mag+'\n';
            }
        }
    }
    db.clear();
    transformStr2BD(name,t);
}
/*void DataBase::finding(std::string word){
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
}*/
/*void DataBase::del(QString id){
    id = id.toInt();
    if((id-1)<=db.size()){

    }
}*/
DataBase::~DataBase(){}

QString authorizing(QString log, QString pass){
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
        query.prepare("INSERT INTO User(login, password, level) "
                          "VALUES (:login, :password, :level)");

        query.clear();
        //QString res = "SELECT * FROM User WHERE login = \'" + log + "\' and password = \'" + pass + "\'";
        //res = "SELECT * FROM User WHERE login = \'admin\'";
        //query.bindValue(":login", log);
        //query.bindValue(":password",pass);
        //qDebug()<<res<<"\n";
        /*if(query.exec("SELECT * FROM User WHERE login = \"admin\"")){
            qDebug()<<query.record().value("login").toString()<<"\n";
            //query.next();
            res = query.value(2).toString();
            db.close();
            return res;
        }*/

        if(query.exec("SELECT * FROM User")){
            while (query.next()) {
                if((log==query.value(0).toString())&&(pass==query.value(1).toString())){
                    if(query.value(2)=="3"){
                        db.close();
                        return "3";
                    }
                    else if(query.value(2)=="2"){
                        db.close();
                        return "2";
                    }
                    else if(query.value(2)=="1"){
                        db.close();
                        return "1";
                    }
                }
            }
        }

        db.close();
        return "0";
}
