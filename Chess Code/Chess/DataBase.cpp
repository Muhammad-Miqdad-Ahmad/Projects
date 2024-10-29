#include "Header.h"

ostream &operator << (ostream &out, const DataBase& data)
{
    cout << *(data.name) << *(data.person) << "The last time of login is: " <<data.time << endl;
    return out;
}

istream &operator >> (istream &in, DataBase& data)
{
    cin >> *(data.name) >> *(data.person);
    return in;
}

ifstream &operator>>(ifstream &in, DataBase &d)
{
    string f, l;
    in >> f >> l;
    d.name->SetFirstName(f);
    d.name->SetLastName(l);
    in >> d.person->userName >> d.person->passWord;
    in >> d.person->wins >> d.person->losses;
    in >> d.time;
    return in;
}

ofstream &operator<<(ofstream &out, DataBase &d)
{
    auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
    d.time = ctime(&timenow);
    out << *(d.name) << *(d.person) << endl
        << d.time;
    return out;
}

void DataBase::InputGuest(Name* &naam, Person* &per)
{
    this->name=naam;
    this->person=per;
    cin >> *(this->name);
    cout << "you have been loged in as guest Mr." << *(this->name);
    this->person->userName = "GUEST";
    this->person->wins = 0;
    this->person->losses = 0;
    this->return_everything(naam,per);
    return;
}

void DataBase::LoginInput()
{
    this->name = new Name;
    this->person = new Person;
    string n, pass;
    int chose;
    try
    {
        cout << "Enter username: ";
        cin >> n;
        cout << "Enter password: ";
        cin >> pass;
    }
    catch (...)
    {
        cout << "invalid input\n";
        this->LoginInput();
        return;
    }
    filein.open(n + ".txt");
    if (filein.is_open())
    {
        filein >> *(this->name) >> *(this->person) >> this->time;
        if (this->person->passWord == pass)
        {
            cout << "The login was successful.\n\n";
            filein.close();
        }
        else
        {
            try
            {
            input:
                cout << "The password was in correct\nWhould you like us to search for your password(1 or 0):";
                cin >> chose;
            }
            catch (...)
            {
                cout << "The input is invalid\n";
                this->LoginInput();
                return;
            }
            if (chose == 1)
            {
                filein.close();
                this->forgetPassword();
                return;
            }
            else
            {
                filein.close();
                return;
            }
        }
    }
    else
    {
        cout << "Login failed.\n\n";
        cout << " PLEASE GO TO THE MENU AND REGISTER YOUR DETAILS " << endl;
    }
}

void DataBase::forgetPassword()
{
    string naam, n, a, b;
    ifstream find;
    cout << "Did you forget your password?\nWE ARE HERE TO HELP YOU..." << endl;
    cout << " ENTER YOUR USERNAME :" << endl;
    cin >> naam;
    naam = naam + ".txt";
    find.open(naam);
    if (find.is_open())
    {
        cout << " CONGRATULATION YOUR ACCOUNT FOUND :" << endl;
        getline(find, n);
        find >> a >> b;
        cout << "YOUR PASSWORD IS: " << b << endl;
    }
    else
    {
        cout << " SORRY YOUR ACCOUNT WAS NOT FOUND" << endl;
    }
    find.close();
    return;
}

void DataBase::Admin()
{
    int n;
    cout << " VIEW FILE " << endl;
    cout << " DELETE FILE " << endl;
    cin >> n;
    if (n == 1)
    {
        string nam, a, i, j, k;
        ifstream file;
        Person user;
        cout << " ENTER NAME OF FILE " << endl;
        cin >> nam;
        nam = nam + ".txt";
        file.open(nam);
        if (file.is_open())
        {
            while (file)
            {
                getline(file, a);
                cout << a << endl;
            }
        }
    }
    if (n == 2)
    {
        cout << " ENTER FILE NAME WHICH YOU WANT TO REMOVE " << endl;

        string filename;

        cout << "Enter the filename to delete: ";
        cin >> filename;
        filename = filename + ".txt";

        if (remove(filename.c_str()) != 0)
        {
            perror("Error deleting file");
        }
        else
        {
            cout << "File successfully deleted" << std::endl;
        }
        cout << endl;
    }
}

void DataBase::override()
{
    auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
    this->time = ctime(&timenow);
    fileout.open(person->userName+".txt", ios::trunc);
    fileout << name << person << time;
    fileout.close();
}
