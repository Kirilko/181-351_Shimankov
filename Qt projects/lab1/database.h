#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>
#include <QFile>




struct data{
    std::string tour;
    std::string fio;
    std::string coun;
    std::string mag;
};

bool checkTour(std::string tour);
bool checkFio(std::string fio);
bool checkCoun(std::string coun);
bool checkMag(std::string mag);

class DataBase{

public:
    std::vector<data> db;
    DataBase();//конструктор
    DataBase(std::string* tempDB); //конструктор по строке: т.е. по строке, в которой записана БД, формируем БД
    ~DataBase();//деструктор*
    bool add_data(data tempData);// добавить строку данных в БД
    bool open(QFile file);//открываем файл
    bool download(std::string & res);//загружаем данные из файла в строку
    bool close();// закрытие файла
    void download();
    data parsing(std::string line);
    void transformStr2BD(std::string bd);// преобразует строку в БД

    bool del_data(int id);//удалить запись с заданным id

    template<typename T>
    std::vector<data> find(int criterior, T data2find);//удалить запись с заданным id


    bool write2file();

private:
    std::string db_string;

protected:


};


#endif // DATABASE_H
