#pragma once
#include <iostream>
using namespace std;

class Name{
    string FirstName;
    string LastName;
public:
    Name() = default;
    Name(string f,string l)
    {
        FirstName =f;
        LastName =l;
    }

    string GetFirstNAME()  {
        return FirstName;
    }

    string GetLastName(){
        return LastName;
    }
    void SetFirstName(string f)
    {
        FirstName=f;
    }
    void SetLastName(string l)
    {
        LastName =l;
    }
    ~Name(){}
    friend istream& operator>>(istream& in, Name& name);
    friend ostream& operator<<(ostream& out,const Name& name);
    friend ifstream& operator>>(ifstream &in, Name &d);
    friend ofstream& operator<<(ofstream &out, Name &d);
};