#include "database.h"
#include <QFile>
#include <QDebug>

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

