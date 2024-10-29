#include "Header.h"

istream& operator>>(istream& in, Name& name)
{
    cout << "Enter the first name: ";
    in >>name.FirstName;
    cout << "Enter the last name: "; 
    in >> name.LastName;
    return in;
}

ostream& operator<<(ostream& out, const Name& name)
{
    out<< "Name is: " <<name.FirstName << " " << name.LastName << endl;
    return out;
}

ifstream& operator>>(ifstream &in, Name &d)
{
    in >> d.FirstName >> d.LastName;
    return in;
}

ofstream& operator<<(ofstream &out, Name &d)
{
    out << d.FirstName << " " << d.LastName << endl;
    return out;
}
