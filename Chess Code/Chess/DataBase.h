#ifndef CHESS_CLASS_H
#define CHESS_CLASS_H

#pragma once
#include "Name.h"
#include "person.h"
using namespace std;

class DataBase
{
public:
    Name *name; // aggregation
    Person *person;
    string time;
    ifstream filein;
    ofstream fileout;
    DataBase()
    {
        name = nullptr;
        person = nullptr;
    };
    inline DataBase(Person *p, Name *n)
    {
        person = p;
        name = n;
    }
    ~DataBase()
    {
        if(name!=nullptr&&person!=nullptr)
        {
            this->override();
        }
        name = nullptr;
        person = nullptr;
    }
    void LoginInput();
    void forgetPassword();
    void Admin();
    void InputGuest(Name* &naam, Person* &person);
    void return_everything(Name* &naam, Person* &person)
    {
        naam = this->name;
        person = this->person;
    }
    void override();
    friend ifstream &operator>>(ifstream &in, DataBase &d);
    friend ofstream &operator<<(ofstream &out, DataBase &d);
    friend ostream &operator << (ostream &in, const DataBase& data);
    friend istream &operator >> (istream &in, DataBase& data);
};

#endif // CHESS_CLASS_H