#include "Header.h"

istream& operator>>(istream& in, Person& data)
{
    cout << "Enter the user name: ";
    in >> data.userName;
    cout << "Enter the password: ";
    in >> data.passWord;
    return in;
}

ostream& operator<<(ostream& out, const Person& data)
{
    cout << "The user name is: " << data.userName << endl;
    return out;
}

ifstream& operator>>(ifstream &in, Person &d)
{
    in >> d.userName >> d.passWord;
    in >> d.wins >> d.losses;
    return in;
}

ofstream& operator<<(ofstream &out, Person &d)
{
    out << d.userName << " " << d.passWord << endl << d.wins << " " << d.losses << endl;
    return out;
}
