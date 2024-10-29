#pragma once
#include <iostream>
#include<fstream>
using namespace std;

class Person {
public:
    string userName;
    string passWord;
    int wins,losses;
    Person() 
    {
        wins = 0;
        losses = 0;
    }
    friend istream& operator>>(istream& in, Person& data);
    friend ostream& operator<<(ostream& out, const Person& data);
    friend ofstream& operator<<(ofstream &out, Person &d);
    friend ifstream& operator>>(ifstream &in, Person &d);
};