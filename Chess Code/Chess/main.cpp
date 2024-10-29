#include "Game.h"
Game *Game::instance = nullptr;

int main()
{
    Person *person1 = nullptr;
    Person *person2 = nullptr;
    Name *name1 = nullptr;
    Name *name2 = nullptr;
    DataBase *data1 = nullptr;
    DataBase *data2 = nullptr;
    int choices, n;
    system("clear");
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "                               |.........................................................|               "
         << endl;
    cout << "                               |.......................---------.........................|               "
         << endl;
    cout << "                               |~~~~~~~~~~~~~~~~~~~~~~ | CHESS | ~~~~~~~~~~~~~~~~~~~~~~~~|               "
         << endl;
    cout << "                               |.......................---------.........................|               "
         << endl;
    cout << "                               |.........................................................|               "
         << endl;
    cout << endl;
    system("cmd /C pause");
    system("clear");

    for (int i = 0; i < 3; i++)
    {
        cout << "\n\n\n\t\t\tLoading ";
        for (int j = 0; j < 5; j++)
        {
            cout << ". ";
            cout.flush();
            Sleep(500);
        }        
        system("clear");
    }
    
    do
    {
    system("clear");
    cout << "\n\n\n\t\t\tPress (1) to access the admin menu " << endl;
    cout << "\t\t\tpress (2) to access the player 1 menu " << endl;
    cout << "\t\t\tpress (3) to access the player 2 menu " << endl;
    cout << "\t\t\tPress (0) to play the game" << endl;
    cout << "\t\t\tEnter your input here: ";
    try
    {
        cin >> choices;
    }
    catch (...)
    {
        system("clear");
        cout << "The input was invalid\n";
        break;;
    }
    switch (choices)
    {
        case 1:
        {
            system("clear");
            DataBase d;
            d.Admin();
            cout << endl;
            system("cmd /C pause");
            break;
        }
        case 2:
        {
        // person 1
        do{
            int a;
        input:
            system("clear");
            cout << "\n\n\n\t\t\t1. LOGIN " << endl;
            cout << "\t\t\t2. SIGN UP " << endl;
            cout << "\t\t\t3. FORGET PASSWORD " << endl;
            cout << "\t\t\t4. PLAY AS A GUEST: ";
            try
            {
                cin >> a;
            }
            catch (...)
            {
                cout << "invalid input: ";
                goto input;
            }
            if (a == 1)
            {
                system("clear");
                if (data1 == nullptr)
                {
                    data1 = new DataBase;
                    data1->LoginInput();
                    data1->return_everything(name1, person1);
                    system("cmd /C pause");
                    break; // jumps to line 24
                }
                else
                {
                    cout << "there is already an account account associated with the current player\n";
                    break; // jumps to line 24
                }
            }
            else if (a == 2)
            {
                system("clear");
                if (data1 == nullptr)
                {
                    name1 = new Name;
                    person1 = new Person;
                    cin >> *(name1);
                    cin >> *(person1);
                    cout << *(name1);
                    cout << *(person1);
                    cout << person1->userName << endl;
                    data1 = new DataBase(person1, name1);
                    data1->fileout.open(person1->userName + ".txt");
                    data1->fileout << *(data1) << endl;
                    data1->fileout.close();
                    system("cmd /C pause");
                    break;;// jumps to line 24
                }
                else
                {
                    cout << "there is already an account account associated with the current player\n";
                    break; // jumps to line 24
                }
            }
            else if (a == 3)
            {
                system("clear");
                DataBase Db;
                Db.forgetPassword();
                cout << endl;
                cout << "Note the username and password as you will have to login again\n";
                system("cmd /C pause");
                break;
            }
            else if (a == 4)
            {
                system("clear");
                data1 = new DataBase;
                name1 = new Name;
                person1 = new Person;
                data1->InputGuest(name1, person1);
                system("cmd /C pause");
                break;;
            }
            else
            {
                cout << "invalid input\n";
                system("cmd /C pause");
                goto input;
            }
        }while(true);
        break;
        }
        case 3:
        {
            // person 2
            do{
            int a;
        input1:
            system("clear");
            cout << "\n\n\n\t\t\t1. LOGIN " << endl;
            cout << "\t\t\t2. SIGN UP " << endl;
            cout << "\t\t\t3. FORGET PASSWORD " << endl;
            cout << "\t\t\t4. PLAY AS A GUEST: ";
            try
            {
                cin >> a;
            }
            catch (...)
            {
                system("clear");
                cout << "input is invalid\n";
                system("cmd /C pause");
                goto input1;
            }
            if (a == 1)
            {
                if (data2 == nullptr)
                {
                    system("clear");
                    data2 = new DataBase;
                    data2->LoginInput();
                    data2->return_everything(name2, person2);
                    system("cmd /C pause");
                    break; // jumps to line 24
                }
                else
                {
                    system("clear");
                    cout << "there is already an account account associated with the current player\n";
                    system("cmd /C pause");
                    break; // jumps to line 24
                }
            }
            else if (a == 2)
            {
                if (data2 == nullptr)
                {
                    system("clear");
                    name2 = new Name;
                    person2 = new Person;
                    cin >> *(name2);
                    cin >> *(person2);
                    data2 = new DataBase(person2, name2);
                    data2->fileout.open(person2->userName + ".txt");
                    data2->fileout << *(data2) << endl;
                    data2->fileout.close();
                    cout << endl;
                    system("cmd /C pause");
                    break; // jumps to line 24
                }
                else
                {
                    system("clear");
                    cout << "there is already an account account associated with the current player\n";
                    system("cmd /C pause");
                    break; // jumps to line 24
                }
            }
            else if (a == 3)
            {
                system("clear");
                DataBase Db;
                Db.forgetPassword();
                cout << endl;
                cout << "Note the username and password as you will have to login again\n";
                system("cmd /C pause");
                break;
            }
            else if (a == 4)
            {
                system("clear");
                data2 = new DataBase;
                name2 = new Name;
                person2 = new Person;
                data2->InputGuest(name2, person2);
                system("cmd /C pause");
                break;
            }
            else
            {
                system("clear");
                cout << "Invalid input\n";
                system("cmd /C pause");
                goto input1;
            }
            }while(true);
            break;
        }
        case 0:
        {
            if (data1 != nullptr)
            {
                if (data2 != nullptr)
                    break;
                else
                {
                    system("clear");
                    cout << "There is no account associated with player 2\n";
                    system("cmd /C pause");
                    break;
                }
            }
            else
            {
                system("clear");
                cout << "There is no account associated with player 1\n";
                system("cmd /C pause");
            }
        }
        default:
        {
            cout << "The input was invalid\n";
            break;
        }
    }
    }while(choices != 0);
    Piece player1(0, "W", data1);
    Piece player2(6, "B", data2);
    Game *game;
    
    do{
    system("clear");
    cout << "\n\n\n\t\t\tPress (1) for NEW GAME " << endl;
    cout << "\t\t\tPress (2) for GAME INSTRUCTIONS  " << endl;
    cout << "\t\t\tPress (3) to DISPLAY THE DATA " << endl;
    cout << "\t\t\tPress (0) to EXIT: ";
    try
    {
        cin >> n;
    }
    catch (...)
    {
        system("clear");
        cout << "invalid input" << endl;
        system("cmd /C pause");
        n = -1;
    }
    switch (n)
    {
        case 1:
        {
            if (game == nullptr)
                game = Game::get_instance(player1, player2);
            else
                game->recreate(player1, player2);
            system("clear");
            game->release_instance();
            game->game_play();
            break;
        }
        case 2:
        {
            system("clear");                                    // this will clear the terminal
            string instructions_print;                        // we take a string
            ifstream instructions("INSTRUCTIONS.txt");        // open the file instructions.txt
            while (getline(instructions, instructions_print)) // read it line by line and store in an array
            {
                for (int x = 0; x < instructions_print.length(); x++) // run a loop till the length of the string
                {
                    cout << instructions_print[x];
                    cout.flush();                     // we print each letter separately. (just for the effect)
                    if (instructions_print[x] != ' ') // if there is not a space then it will be accessed
                        Sleep(10);                    // after each letter there will be a delay of 10 miliseconds
                }
                cout << endl; // we go to a new line after each line.
            }
            instructions.close(); // close the file.
            system("cmd /C pause");
            break;
        }
        case 3:
        {
            system("clear");
            Display<DataBase> display1(data1);
            cout << endl;
            Display<DataBase> display2(data2);
            cout << endl;
            system("cmd /C pause");
            break;
        }
        case 0:
        {
            system("clear");
            cout << "\n\n\n\t\t\tBye see you soon\n\n\n";
            delete game;
            game = nullptr;
            delete data1;
            data1 = nullptr;
            delete data2;
            data2 = nullptr;
            delete name1;
            name1 = nullptr;
            delete name2;
            name2 = nullptr;
            delete person1;
            person1 = nullptr;
            delete person2;
            person2 = nullptr;
            break;
        }
        default:
        {
            system("clear");
            cout << "The input is invalid\n";
            system("cmd /C pause");
            break;
        }
    }
    }while(n != 0);
    return 0;
}
