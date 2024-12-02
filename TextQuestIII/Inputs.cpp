#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <sstream>

#include "string.h"
#include "Screens.h"

using namespace std;

int NumChoice(int Choice)
{
    cin >> Choice;

    return Choice;
}

string UpShift(string input)
{
    int StrLength;
    int i;

    StrLength = input.length();

    for(i = 0; i < StrLength; i ++)
    {
        input.at(i) = toupper(input.at(i));
    }

    return input;
}

bool YesNo()
{
    bool yn;
    bool Loop;

    string input;

    Loop = true;

    while(Loop == true)
    {
        cin.sync();

        cin >> input;

        input = UpShift(input);

        if(input == "Y" || input == "YES")
        {
            yn = true;
            Loop = false;
        }
        else if(input == "N" || input == "NO")
        {
            yn = false;
            Loop = false;
        }
        else
        {
            cout << "This isn't a valid input!\n\n";
            system("PAUSE");


        }
    }
    return yn;
}
/*
int NumericMenu(int Sections);
{
    int Option;

    bool Loop;

    Loop = true;

    while(Loop == true)
    {
        cin.sync();

        cin >> Option;

        if(Option )
    }

}
*/

string InterpretWord(string Input)
{
    int StrLength = Input.length();
    string NewString;

    for(int i = 0; i < StrLength; i ++)
    {
        char Letter = Input.at(i);

        if(Letter != ' ')
        {
            NewString += Letter;
        }
        else
        {
            i = StrLength;
        }
    }

   // cout << "NewString: " << NewString << endl;

//    system("PAUSE");

    return NewString;
}

int InterpretNumber(string Input)
{
    int StrLength = Input.length();
    int NewInt = -1;
    int NumStart;
    string NewString;

   // stringstream convert;

    for(int i = 0; i < StrLength; i ++)
    {
        char Letter = Input.at(i);

        if(Letter == ' ')
        {
            NumStart = i+1;
        }

        if(i >= NumStart)
        {
            NewString += Letter;
        }
    }

    istringstream convert(NewString);
    if( !(convert >> NewInt) ) NewInt = 0;

   /* cout << "NewInt: " << NewInt << endl;

    system("PAUSE");
*/
    return NewInt;
}



void OpenWorldInput(string Input, int command[2])
{
    string Word = InterpretWord(Input);
    int Number;

    Word = UpShift(Word);

    if(Word == "GO")
    {
        Number = InterpretNumber(Input);
        command[0] = 0;
    }
    else if(Word == "STATS" || Word == "ST")
    {
        Number = 0;
        command[0] = 1;
    }
    else if(Word == "INVENTORY" || Word == "INV")
    {
        Number = 0;
        command[0] = 2;
    }
    else if(Word == "QUESTS" || Word == "QUEST" || Word == "QU")
    {
        Number = 0;
        command[0] = 3;
    }
    else if(Word == "EQUIPMENT" || Word == "EQU")
    {
        Number = 0;
        command[0] = 4;
    }
    else if(Word == "SPELLS" || Word == "SPELL")
    {
        Number = 0;
        command[0] = 5;
    }
    else if(Word == "TALK")
    {
        Number = InterpretNumber(Input) - 1;
        command[0] = 6;
    }
    else if(Word == "EQUIP")
    {
        Number = InterpretNumber(Input) - 1;
        command[0] = 7;
    }
    else if(Word == "DROP")
    {
        Number = InterpretNumber(Input) - 1;
        command[0] = 8;
    }
    else if(Word == "UNEQUIP")
    {
        Number = InterpretNumber(Input);
        command[0] = 9;
    }
    else if(Word == "EXIT")
    {
        Number = 0;
        command[0] = -1;
    }
    else
    {
        Number = 0;
        command[0] = -2;
    }


    command[1] = Number;
}

int TalkInput()
{
    cin.sync();
    int Choice;
//   int TrueChoice;
    cin >> Choice;

    Choice --;


    return Choice;
}

    //FIGHT MENUS


int BaseInput(character Player[], int nCC, int command[2])
{
    bool MenuOn = true;
    bool YN;
    int fScreenType = 0;

    while(MenuOn == true)
    {
        int Choice;

        cout << "Command: ";
        cin.sync();
        cin >> Choice;

        if(Choice == 1)
        {
            command[0] = 1;
            fScreenType = 1;
            MenuOn = false;
        }
        else if(Choice == 2)
        {
            command[0] = 2;

            if(Player[nCC].EquipSpell.Cost > Player[nCC].Magic[0])
            {
                cout << "Not enough magic to cast this spell!\n\n";
                system("PAUSE");
            }
            else if(Player[nCC].EquipSpell.Type > 0)
            {
                fScreenType = 1;
            }
            else if(Player[nCC].EquipSpell.Type < 0)
            {
                fScreenType = 2;
            }
            else
            {
                cout << "No spell equipped!\n";
                cout << "Would you like to equip a spell? ";
                YN = YesNo();

                if(YN == true)
                {
                    fScreenType = 7;
                }
            }
            MenuOn = false;
        }
        else if(Choice == 3)
        {
            command[0] = 3;

            fScreenType = 2;

            MenuOn = false;
        }
        else if(Choice == 4)
        {
            command[0] = 4;

            fScreenType = 3;

            MenuOn = false;
        }
        else if(Choice == 5)
        {
            command[0] = 5;

            fScreenType = 4;

            MenuOn = false;
        }
        else if(Choice == 6)
        {
            command[0] = 6;

            fScreenType = 5;

            MenuOn = false;
        }
        else if(Choice == 7)
        {
            command[0] = 7;

            fScreenType = 6;

            MenuOn = false;
        }
        else if(Choice == 8)
        {
            command[0] = 8;

            fScreenType = 7;

            MenuOn = false;
        }
        else if(Choice == 9)
        {
            command[0] = 9;
            fScreenType = -1;
            MenuOn = false;
        }
        else if(Choice == 0)
        {
            MenuOn = false;
            fScreenType = -1;
        }
    }
    return fScreenType;
}

int TargetInput(int command[2], character Targets[])
{
    bool MenuOn = true;
    int Count = CountAlive(Targets);
    int fScreenType;
    while(MenuOn == true)
    {
        cout << "Target: ";
        cin.sync();
        cin >> command[1];

        if(command[1] < 1 || command[1] > Count+1)
        {
            cout << "Invalid target!\n\n";
        }
        else if(Targets[(command[1])-1].Health[0] == 0 && command[1] <= Count && command[1] >= 1)
        {
            cout << "Target is dead!\n\n";
        }
        else
        {
            MenuOn = false;



            if(command[1] == Count + 1)
            {
                fScreenType = 0;
            }
            else
            {
                command[1] -= 1;

                fScreenType = -1;
            }
        }
    }
    return fScreenType;
}

int ItemInput(int command[2], character Player[], int nCC, int TestType)
{
    bool MenuOn = true;
    int Choice;
    int InvIndex[10];
    int Count = 0;
    int fScreenType;

    command[0] = 4;

    for(int i = 0; i < 10; i ++)
    {
        if(Player[nCC].Inventory[i]->iType == TestType)
        {
            InvIndex[Count] = i;
            Count ++;
        }
    }

    while(MenuOn == true)
    {
        cout << "Item: ";
        cin.sync();
        cin >> Choice;

        if(Choice <= Count)
        {
            Choice = InvIndex[Choice-1];
            MenuOn = false;

            fScreenType = -1;
        }
        else if(Choice == Count+1)
        {
            Choice = 0;
            MenuOn = false;
            fScreenType = 0;
        }
        else
        {
            cout << "Invalid choice!\n\n";
        }
    }

    command[1] = Choice;
    return fScreenType;
}

int InteractInput()
{
   // bool MenuOn = true;
    int Count = 0;
    cout << "Don't forget to program this!\n\n";
    return Count;
}

int MoveInput(arena Arena, int command[2])
{
    command[0] = 6;

    bool MenuOn = true;
    int Count = 0;
    int fScreenType;
    int Choice;
    for(int i = 0; i < Arena.Size; i ++)
    {
        if(Arena.IsEmpty(i) == true)
        {
            Count ++;
        }
    }
    while(MenuOn == true)
    {
        cout << "Move: ";
        cin.sync();
        cin >> Choice;



        if(Arena.IsEmpty(Choice-1) == false)
        {
            cout << "Invalid location!\n\n";
        }
        else if(Choice > Count + 1)
        {
            cout << "Invalid location!\n\n";
        }
        else
        {
            MenuOn = false;
            if(Choice == Count + 1)
            {
                fScreenType = 0;
            }
            else
            {
                for(int i = 0; i < Choice; i ++)
                {
                    if(Arena.IsEmpty(i) == false)
                    {
                        Choice ++;
                    }
                    command[1] = i;
                }

                fScreenType = -1;
            }
        }
    }
    return fScreenType;
}

int EquipInput()
{
    int Choice = 0;
    int fScreenType;
    bool MenuOn = true;

    while(MenuOn == true)
    {
        cout << "Equip: ";
        cin.sync();
        cin >> Choice;

        if(Choice > 3 || Choice < 1)
        {
            cout << "Invalid input!\n\n";
        }
        else
        {
            MenuOn = false;
        }


        if(Choice == 1)
        {
            fScreenType = 8;
        }
        else if(Choice == 2)
        {
            fScreenType = 9;
        }
        else if(Choice == 3)
        {
            fScreenType = 0;
        }
    }
    return fScreenType;
}

int SpellInput(int command[], int nCC, character Player[])
{
    command[0] = 8;

    bool MenuOn = true;
    int Count = Player[nCC].KnownSpells();
    int Choice;
    int fScreenType;

    while(MenuOn == true)
    {
        cout << "Spell: ";
        cin.sync();
        cin >> Choice;

        if(Choice > Count+1 || Choice < 1)
        {
            cout << "Invalid input!\n\n";
        }
        else if(Choice == Count + 1)
        {
            fScreenType = 0;
            MenuOn = false;
        }
        else
        {
            for(int i = 0; i < Choice; i ++)
            {
                if(Player[nCC].Spells[i].Type == 0)
                {
                    Choice ++;
                }

                command[1] = i;

                fScreenType = -1;
            }

            //command[1] = Choice;

            MenuOn = false;
        }
    }
    return fScreenType;
}
