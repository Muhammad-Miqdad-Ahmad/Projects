#pragma once
#include <iostream>
using namespace std;
template <class datatype>
class Display
{
public:
    Display(datatype *data)
    {
        cout << *(data) << endl;
        data=nullptr;
    }
};
