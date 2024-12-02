#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;




string EnemyName[] =
{
    " ",
    "Dummy",
    "Goblin",
    "Troll",
    "Skeleton",
    "Warlock",
    "Ogre",
    "Dragon",
    "Hellhound",
    "Pirate"
};
int EnemyNameLength[] = {1, 5, 6, 5, 8, 7, 4, 6, 9, 6};



void AddCharacter(string CharacterInfo[3][3], int nCC, string Screen[])
{
    int i;

    int stringLength;
    int Spaces;
    int NameEnd;
    int WriteAt;

    stringLength = CharacterInfo[nCC][0].length();

    Spaces = 10 - stringLength;

    NameEnd = 13 + stringLength;

    Screen[2].replace(2, 11, "Character: ");
    Screen[2].replace(13, stringLength, CharacterInfo[nCC][0]);

    for(i = 0; i < Spaces; i ++)
    {
        WriteAt = NameEnd + i;

        Screen[2].replace(WriteAt, 1, "=");
    }
}


//===================================================================================================================================================
//===========================================================EMPTY SCREEN FUNCTION===================================================================
//===================================================================================================================================================

void EmptyScreen(string Screen[])
{

    int i;

    for(i = 0; i < 32; i++)
    {
        Screen[i] = "                                                                               \n";
    }
}


//===================================================================================================================================================
//===========================================================DRAW SCREEN FUNCTION====================================================================
//===================================================================================================================================================

void drawScreen(string Screen[], int ScreenSize)
{
    int i;
    system("CLS");
    for(i = 0; i < ScreenSize; i ++)
    {
        cout << Screen[i];
    }

    return;
}

//===================================================================================================================================================
//==========================================================FIGHT SCREEN FUNCTION====================================================================
//===================================================================================================================================================
void fightScreen(string CharacterInfo[3][3], int CharacterStats[3][7], int Enemy[3][8], int Turn)
{
    int i;
    int s;
    int nameLength[3];
    string Screen[32];
    EmptyScreen(Screen);

    system("CLS");

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "====================================BATTLE=====================================\n";
        Screen[2]  = "===============================================================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "                                                                               \n";
        Screen[5]  = "                                                                               \n";
        Screen[6]  = "   _ _ _ _ _ _ _ _ _ _                                   _ _ _ _ _ _ _ _ _ _   \n";
        Screen[7]  = "  |           |";
        Screen[8]  = "  |           |";
        Screen[9]  = "  |           |";

        Screen[10] = "                                 ";

        Screen[11] = "  |===================|                                 |===================|  \n";

        Screen[12] = "               Vs.               ";

        Screen[13] = "|           |  \n";
        Screen[14] = "|           |  \n";
        Screen[15] = "|           |  \n";

    for(i = 0; i <= 2; i++)
    {
        if(i == 0)
        {
            s = 13;
        }
        else if(i == 1)
        {
            s = 14;
        }
        else if(i == 2)
        {
            s = 15;
        }

        if(Enemy[i][5] == 1)
        {
            Screen[s].replace(1, EnemyNameLength[1], EnemyName[1]);
        }
        else if(Enemy[i][5] == 2)
        {
            Screen[s].replace(1, EnemyNameLength[2], EnemyName[2]);
        }
        else if(Enemy[i][5] == 3)
        {
            Screen[s].replace(1, EnemyNameLength[3], EnemyName[3]);
        }
        else if(Enemy[i][5] == 4)
        {
            Screen[s].replace(1, EnemyNameLength[4], EnemyName[4]);
        }
        else if(Enemy[i][5] == 5)
        {
            Screen[s].replace(1, EnemyNameLength[5], EnemyName[5]);
        }
        else if(Enemy[i][5] == 6)
        {
            Screen[s].replace(1, EnemyNameLength[6], EnemyName[6]);
        }
        else if(Enemy[i][5] == 7)
        {
            Screen[s].replace(1, EnemyNameLength[7], EnemyName[7]);
        }
        else if(Enemy[i][5] == 8)
        {
            Screen[s].replace(1, EnemyNameLength[8], EnemyName[8]);
        }
        else if(Enemy[i][5] == 9)
        {
            Screen[s].replace(1, EnemyNameLength[9], EnemyName[9]);
        }
        else
        {
            Screen[s].replace(1, EnemyNameLength[0], EnemyName[0]);
        }
    }



    for(i = 0; i <= 2; i++)
    {
        nameLength[i] = CharacterInfo[i][0].length();
    }

    Screen[7].replace(3, nameLength[0], CharacterInfo[0][0]);
    Screen[8].replace(3, nameLength[1], CharacterInfo[1][0]);
    Screen[9].replace(3, nameLength[2], CharacterInfo[2][0]);

    if(Turn == 0)
    {
        Screen[7].replace(1, 1, " ");
        Screen[8].replace(1, 1, " ");
        Screen[9].replace(1, 1, " ");
        Screen[13].replace(13, 1, " ");
        Screen[14].replace(13, 1, " ");
        Screen[15].replace(13, 1, " ");
    }
    if(Turn == 1)
    {
        Screen[13].replace(13, 1, " ");
        Screen[7].replace(1, 1, ">");
    }
    else if(Turn == 2)
    {
        Screen[7].replace(1, 1, " ");
        Screen[13].replace(13, 1, "<");
    }
    else if(Turn == 3)
    {
        Screen[13].replace(13, 1, " ");
        Screen[8].replace(1, 1, ">");
    }
    else if(Turn == 4)
    {
        Screen[8].replace(1, 1, " ");
        Screen[14].replace(13, 1, "<");
    }
    else if(Turn == 5)
    {
        Screen[14].replace(13, 1, " ");
        Screen[9].replace(1, 1, ">");
    }
    else if(Turn == 6)
    {
        Screen[9].replace(1, 1, " ");
        Screen[15].replace(13, 1, "<");
    }


    for(i = 0; i <= 6; i ++)
    {
        cout << Screen[i];
    }
//==================================ROW 1============================================================================================================

         cout << Screen[7]; cout.width(3); cout << CharacterStats[0][0]; cout << "|"; cout.width(3); cout << CharacterStats[0][1]; cout << "|";
         cout << Screen[10] << "|"; cout.width(3); cout << Enemy[0][0]; cout << "|"; cout.width(3); cout << Enemy[0][1]; cout << Screen[13];
//===================================================================================================================================================
         cout << Screen[11];
//==================================ROW 2============================================================================================================
         cout << Screen[8]; cout.width(3); cout << CharacterStats[1][0]; cout << "|"; cout.width(3); cout << CharacterStats[1][1]; cout << "|";
         cout << Screen[12] << "|"; cout.width(3); cout << Enemy[1][0]; cout << "|"; cout.width(3); cout << Enemy[1][1]; cout << Screen[14];
//===================================================================================================================================================
         cout << Screen[11];
//==================================ROW 3============================================================================================================
         cout << Screen[9]; cout.width(3); cout << CharacterStats[2][0]; cout << "|"; cout.width(3); cout << CharacterStats[2][1]; cout << "|";
         cout << Screen[10] << "|"; cout.width(3); cout << Enemy[2][0]; cout << "|"; cout.width(3); cout << Enemy[2][1]; cout << Screen[15];
//===================================================================================================================================================
         cout << Screen[11];



    for(i = 16; i < 32; i ++)
    {
        cout << Screen[i];
    }
}
