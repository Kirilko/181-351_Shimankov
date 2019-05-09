#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

struct data{
    std::string tour;
    std::string fio;
    std::string coun;
    std::string mag;
};

bool checkFio(std::string fio);
bool checkCoun(std::string coun);
class DataBase
{
public:
    std::vector<data> db;
    DataBase();//конструктор
    DataBase(std::string* tempDB); //конструктор по строке: т.е. по строке, в которой записана БД, формируем БД
    ~DataBase();//деструктор*
    bool add_data(data tempData);// добавить строку данных в БД
    void download(std::string & res);//загружаем данные из файла в строку
    void download1(std::string & res);
    void download();
    void download1();
    data parsing(std::string line);
    void transformStr2BD(std::string db_string);// преобразует строку в БД
    void transformStr2BD1(std::string db_string);
    void finding(std::string word);
    void finding1(std::string word);
    void del(QString id);
    bool del_data();//удалить запись с заданным id

    bool write2file();

private:
    std::string db_string;

protected:


};

#endif // DATABASE_H
