#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>


using namespace std;

#include "Inputs.h"
#include "Screens.h"
#include "CharacterCreation.h"
#include "Save.h"
#include "Information.h"
#include "characters.h"
#include "maps.h"
#include "LevelControl.h"
#include "quests.h"
#include "items.h"
#include "Combat.h"

void Load();
void Save();

arena Arena;

character Player[3];

string FileName[3] =
{
    "Character1.tqs",
    "Character2.tqs",
    "Character3.tqs"
};

int Party[3] = {0, 0, 0};

int Stage;

int ScreenType = 1;

void ResetQuests()
{
    for(int i = 0; i < 1; i ++)
    {
        CompletedQuests[i] = false;
    }
}

void LevelTest()
{
    //cout << Atlas[1].Towns[0].Name;
/*
    stringstream convert;
    int nCC = 0;
    int ScreenType = 1;
    bool Bum = false;
    Player[nCC].Location[0] = 1;
    Player[nCC].Location[1] = 0;
    Player[nCC].Location[2] = 2;
    Player[nCC].Health[0] = 50;
    Player[nCC].Health[1] = 100;
    Player[nCC].Magic[0] = 70;
    Player[nCC].Magic[1] = 100;
    Player[nCC].Str = 50;
    Player[nCC].Agi = 50;
    Player[nCC].Int = 50;
    Player[nCC].RaceID = 0;
    Player[nCC].FirstName = "Joe";
    Player[nCC].Surname = "Wilde";
    Player[nCC].Race = "Human";
    Player[nCC].Gender = "Male";

    //string Screen[32];

    OpenWorld(ScreenType, Player, nCC, Bum);
*/

/*
    int Reg;
    int Twn;
    int Bld;
*//*
    int Choice[2];
    int TrueChoice;

    bool LevelOn = true;

    string Input;
    string Screen[32];
    ClearScreen(Screen, 32);

while(LevelOn == true)
{
    OpenWorldScreen(Screen, ScreenType, Player, nCC);

    cin.sync();

    getline(cin, Input);

    OpenWorldInput(Input, Choice);

    int Reg;
    int Twn;
    int Bld;

    Player[nCC].GetLocation(Reg, Twn, Bld);

    if(Choice[0] == -1)
    {
        LevelOn = false;
    }
    else if(Choice[0] == 0)
    {
        if(Choice[1] != 0)
        {
            int j = 0;
            for(int i = 0; i < 9; i ++)
            {
                if(Atlas[Reg].Towns[Twn].Town[Bld].Adj[i] == true)
                {
                    j ++;

                    TrueChoice = i;
                }

                if(j == (Choice[1]))
                {
                    i = 9;
                }
            }

            //cout << "TrueChoice = " << TrueChoice << endl;
            Player[nCC].Location[2] = TrueChoice;
            Player[nCC].GetLocation(Reg, Twn, Bld);
            cout << "Going to: " << Atlas[Reg].Towns[Twn].Town[Bld].Name << endl;

            system("PAUSE");
        }
        else if(Choice[1] == 0)
        {
            LevelOn = false;
        }
    }
    else if(Choice[0] == 1)
    {
        ScreenType = 1;
    }
    else if(Choice[0] == 2)
    {
        ScreenType = 2;
    }
    else if(Choice[0] == 3)
    {

    }


}*/
/*
    weapon Sword("Sword", 50, 1, 50, 50);
    potion WeakHealth("Weak Health Potion", 50, 1, 1, 25);
    armour ChainMail("Chain Mail", 50, 1, 50, 50);

    cout << Sword.Name << endl;
    cout << Sword.Value << endl;
    cout << Sword.Damage << endl;
    cout << Sword.Weight << endl;

    cout << WeakHealth.Name << endl;
    cout << WeakHealth.Value << endl;
    cout << WeakHealth.Type << endl;
    cout << WeakHealth.Modifier << endl;

    cout << ChainMail.Name << endl;
    cout << ChainMail.Value << endl;
    cout << ChainMail.Defence << endl;
    cout << ChainMail.Weight << endl;

    system("PAUSE");
*/
/*
    weapon Sword("Sword", 50, 1, 50, 50, false);
    Player[0].AddWeapon(Sword);
    Player[0].Equip(0, 3);
    system("PAUSE");
*/
    Load();

    //Player[nCC].AddPotion(TestPotionA);
   // Player[nCC].AddPotion(TestPotionB);

   // Player[nCC].AddPotion(TestPotionC);
   // Player[nCC].AddPotion(TestPotionD);

  //    Player[nCC].AddPotion(TestPotionE);

  //  Player[nCC].AddPotion(TestPotionF);

  //Player[nCC].AddPotion(TestPotionG);
  //Player[nCC].AddPotion(TestPotionH);

  //Player[nCC].AddPotion(TestPotionI);
   // Player[nCC].AddPotion(TestPotionJ);


    character Enemy[3];
    Enemy[0] = Atlas[1].Towns[0].Town[2].Residents[1];

    fight(Player, Enemy, TrainingCampArena);
    Save();

}


void Save()
{
    int i;

    cout << "Saving game..." << endl << endl;

    SaveWorld(Party, Stage, ScreenType, CompletedQuests);

    for(i = 0; i < 3; i ++)
    {
        if(Party[i] == 1)
        {
            Player[i].SaveData(FileName, i);
        }
    }

    cout << "Game Saved." << endl << endl;
    system("PAUSE");
}

void Load()
{
    int i;

    LoadWorld(Party, Stage, ScreenType, CompletedQuests);

    for(i = 0; i < 3; i ++)
    {
        if(Party[i] == 1)
        {
            Player[i].LoadData(FileName, i);
        }
    }
}

string title[] =
    {
        "                                                                              \n",
        "                                /|                                            \n",
        "  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _/ |                                            \n",
        " /  _ _     _ _     _ _     _ _ _/                                            \n",
        " | /   |   |   |   |   |   |  _ _ _ _ _                                       \n",
        " |/    |   |   |   |   |   | |_ _   _ _|_                                     \n",
        "       |   |   |   |   |   |     | |  _ _| _    _  _ _ _                      \n",
        "       |   |   |   |   |   |     | | |_   \\ \\  / /|_   _|                     \n",
        "       |   |   |   |   |   |     | |  _|   \\ \\/ /   | |                       \n",
        "       |   |   |   |   |   |     | | |_ _  / /\\ \\   | |                       \n",
        "       |   |   |   |   |   |     |_|_ _ _|/_/  \\_\\  |_|                       \n",
        "       |   |   |   |   |   |    /|    /   \\    _  _   _ _   _ _ _   _ _ _    \n",
        "  _ _ _|   |_ _|   |_ _|   |_ _/ |   |  /\\ |  | || | |  _| |  _ _| |_   _|   \n",
        " /  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _/   | |_/  \\ | \\/ | |  _| |_ _  |   | |     \n",
        " | /                                  \\_ _/\\_\\ \\_ _/ |_ _| |_ _ _|   |_|      \n",
        " |/                                                                           \n",
        "                                                                              \n",
        "                                                    1 - New Game              \n",
        "                                                      2 - Load Game           \n",
        "                                                        3 - Information       \n",
        "                                                          4 - Quit            \n",
        "                                                                              \n",
        "                                                                              \n",
        "                                                                              \n",

    };

void StartGame()
{
    bool StageSwitch = true;
    bool yn;

    int nCC = 0;

    while(StageSwitch == true)
    {
        switch(Stage)
        {
            case 0:
            {

                Intro(Player);
                Party[0] = 1;
                Stage = 1;
                Save();

                cout << "Would you like to continue? ";
                yn = YesNo();

                if(yn == false)
                {
                    StageSwitch = false;
                }

            break;
            }
            case 1:
            {
                Tutorial(Player);
                Stage = 2;
                Save();

            break;
            }
            case 2:
            {
                Atlas[1].Towns[0].Town[2].Adj[1] = false;
                if(Player[0].ActiveQuests[0].QuestID == -1)
                {
                    Player[0].AddQuest(SigningUp);
                    ScreenType = 3;
                }
                OpenWorld(ScreenType, Player, nCC, StageSwitch);

                if(CompletedQuests[0] == true)
                {
                    Atlas[1].Towns[0].Town[2].Adj[1] = true;
                    Stage = 3;
                }
                Save();


            break;
            }
        }



    }

}

void LoadGame()
{
    Load();
    StartGame();
}

void Info()
{
    Menu();
}

bool QuitGame()
{
    bool yn;

    cout << "Are you sure you want to quit? ";

    yn = YesNo();

    if(yn == true)
    {
        yn = false;
    }
    else if(yn == false)
    {
        yn = true;
    }

    return yn;
}


int main()
{
    int MenuChoice;
    bool GameOn = true;

    srand(time(NULL));

    while(GameOn == true)
    {
      //
        cin.sync();
        DrawScreen(title, 24);

        cin >> MenuChoice;

        switch(MenuChoice)
        {
            case 1:
            {

                Stage = 0;
                ResetQuests();
                StartGame();

            break;
            }
            case 2:
            {
                LoadGame();

            break;
            }
            case 3:
            {
                Info();

            break;
            }
            case 4:
            {
                GameOn = QuitGame();

            break;
            }
            case 5:
            {
                LevelTest();
            break;
            }
            default:
            {
                cout << "Unrecognised command!\nPlease enter again!\n\n";
                system("PAUSE");
                cin.clear();
            break;
            }
        }
    }

    cout << "Exiting game...\n\n";

    system("PAUSE");

    return 0;
}
