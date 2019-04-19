#include "database.h"
#include <QFile>
#include <QDebug>
#include <cctype>

DataBase::DataBase()
{

}
/*bool DataBase::open(QFile file){
    if((file.exists())&&(file.open(QIODevice::ReadOnly))){
        return true;
    } else {
        qDebug() << "Error";
        return false;
    }
}*/

/*(bool checkTour(std::string tour){
    if(tour = NULL)
        return false;
    else return true;
}*/
bool checkFio(std::string fio){
    QString up = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString down = "abcdefghijklmnopqrstuvwxyz";
    if(!(up.contains(fio[0]))){
            if(down.contains(fio[0]))
                fio[0]=toupper(fio[0]);
            else return false;
    }
    for(int i = 1;i<fio.length();i++){
            if(!(down.contains(fio[i]))){
                if(up.contains(fio[i]))
                    fio[i] = tolower(fio[i]);
                else return false;
            }
    }
    return true;


  /*  QString q_First_Letter;
    QString q_Last_Letters;
    q_First_Letter = fio[0];
    for (int i = 1;fio.length();i++) {
        q_Last_Letters += fio[i];
    }
    q_First_Letter.toUpper();
    q_Last_Letters.toLower();
    fio = (q_First_Letter + q_Last_Letters).toStdString();
    return true;*/

}
bool checkCoun(std::string fio){
    for(int i = 0;i<fio.length();i++){
        QString up = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        QString down = "abcdefghijklmnopqrstuvwxyz";
        if (i==0){
            if(!(up.contains(fio[i]))){
                if(down.contains(fio[i]))
                fio[i] = toupper(fio[i]);
                else return false;
            }
        } else {
            if(!(down.contains(fio[i]))){
                if(up.contains(fio[i]))
                    fio[i] = tolower(fio[i]);
                else return false;
            }
        }
    }
    return true;
}
bool checkTour(std::string tour){
    QString up = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString down = "abcdefghijklmnopqrstuvwxyz";
    if((tour[0]>9||tour[0]<0)&&(!(up.contains(tour[0]))&&(!(down.contains(tour[0])))))
        return false;
    else return true;
}
//bool checkMag(std::string mag){}
void DataBase::download(){
    std::string res;
    download(res);
    transformStr2BD(res);
}
bool DataBase::download(std::string & res)
{
    QFile file("DataBase.txt");

    if((file.exists())&&(file.open(QIODevice::ReadOnly | QIODevice::Text))){
        res = file.readAll();
        file.close();
        return true;
    } else return false;
}

bool DataBase::add_data(data tempData)
{
    db.push_back(tempData);
    return true;
}

bool DataBase::del_data(int id)
{
    if(id==0)
        return false;
    db.erase(db.begin() + id);
    return true;
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

bool DataBase::write2file()
{

    QFile file("DataBase.txt");
    if((file.exists())&&(file.open(QIODevice::WriteOnly | QIODevice::Text))){
        QTextStream writeStream(&file);
        db_string.clear();
        for (int i = 0; i<db.size(); i++)
        {
            db_string += db[i].tour + "\t" + db[i].fio + "\t" + db[i].coun + "\t" + db[i].mag + "\n";
        }
        QString str = str.fromStdString(db_string);
        writeStream << str;
        file.close();
        return true;
    } else return false;
}
DataBase::~DataBase(){}

QString authorizing(QString log, QString pass){
    QFile file("text.txt");
    QString wfile;
    QString message = "Auth&"+log+" "+pass;

    if((file.exists())&&(file.open(QIODevice::ReadOnly))){
        while(!file.atEnd()){
            wfile = file.readLine();
            if(wfile.contains(" "+pass+" ")&&wfile.contains(" "+log+" ")){
                if(log=="admin"){
                    file.close();
                    return "1";
                } else if(wfile.contains("level2")){
                    file.close();
                    return "2";
                } else if(wfile.contains("level3")){
                    file.close();
                    return "3";
                }
            }
        }
    }
    return "0";
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
