#pragma once //The header file that contains all libraries to be used
#include "King.h"//it will be included in the function.cpp and the Functions.h file and 
#include "Queen.h"//in the main only functions.h will be included
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Abstract.h"
#include "DataBase.h"
#include "Name.h"
#include "person.h"
#include "Display.h"
#include <fstream>
#include <windows.h>  
#include <map>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;
namespace relations
{
    static map<int, int> digit_map;//in ko static is liye kiya he q k header boht si jaga included he to is ki multiple difinitions ho jati hain.
    static map<char, int> letter_map;
    static map<char, int> chess_digit_map;
    static map<string, Abstract*> pointer_map;
} // namespace maps
namespace chess
{
    static string white = "\033[1;47m      \033[0m";//prints white color in the between space
    static string whiten = "\033[1;47m  \033[0m";//also prints white color
    static string black = "\033[1;40m      \033[0m";//prints black
    static string blackn = "\033[1;40m  \033[0m";
    static string blues = "\033[1;45m      \033[0m";//prints the purple color
    static string bluen = "\033[34;45m  \033[0m";//also the same
    static string black_n_white_pieces[12] = {"\033[44;37m\U0001F934\033[0m", //?king blue 0
                                              "\033[44;37m\U0001F478\033[0m", //?queen blue 1
                                              "\033[44;37m\U0001F3F0\033[0m", //?rook blue 2
                                              "\033[44;37m\U0001F432\033[0m", //?knight blue 3
                                              "\033[44;37m\U0000265F \033[0m",//?bishop blue 4
                                              "\033[44;37m\U00002659 \033[0m",//?pawn blue 5
                                              "\033[41;37m\U0001F934\033[0m", //!king red 6
                                              "\033[41;37m\U0001F478\033[0m", //!queen red 7
                                              "\033[41;37m\U0001F3F0\033[0m", //!rook red 8
                                              "\033[41;37m\U0001F432\033[0m", //!knight red 9
                                              "\033[41;37m\U0000265F \033[0m",//!bishop red 10
                                              "\033[41;37m\U00002659 \033[0m" //!pawn red 11
                                            };
} // namespace chess