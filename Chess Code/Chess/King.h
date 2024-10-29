#pragma once
#include <iostream>
#include "Abstract.h"
using namespace std;

class King:public Abstract
{
private:
    
public:
    int row,colomn;
    string *badsha; 
    bool access(string*** board,int index_from_1,int index_from_2,int index_to_1, int index_to_2) override;
    King() 
    {
        this->badsha = new string[2];//ye mn ne 2 is liye li he space k dosre index pe main ik letter store kr wa doon ga to agar wo B hoa
        //to black ka piece and agar W hoa to white a piece. is tarha pta chal jaya kare ga k piece kone color ka he 
    };
    void is_kind_of(string kind)//ye function pieces ko letter assign krta he
    {
        this->count=0;
        this->badsha[1] = kind;
    }
    ~King();

};




