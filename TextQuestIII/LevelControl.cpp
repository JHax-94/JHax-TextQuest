#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

#include"Screens.h"
#include"maps.h"
#include"Inputs.h"
#include"Dialogue.h"

void OpenWorld(int &ScreenType, character Player[3], int &nCC, bool &StageSwitch)
{
    int Choice[2];
    int TrueChoice;

    string Input;
    string Screen[32];
    ClearScreen(Screen, 32);

    bool LevelOn = true;

    while(LevelOn == true)
    {
        OpenWorldScreen(Screen, ScreenType, Player, nCC);
        Player[nCC].CheckQuest();

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
            StageSwitch = false;
        }
        else if(Choice[0] == 0)
        {
            if(Choice[1] != 0)
            {
                int j = 0;
                bool CycleOut = true;
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
                        CycleOut = false;
                    }
                }
                //cout << "TrueChoice = " << TrueChoice << endl;
                if(CycleOut == false)
                {
                    Player[nCC].Location[2] = TrueChoice;
                    Player[nCC].GetLocation(Reg, Twn, Bld);

                    cout << "Going to: " << Atlas[Reg].Towns[Twn].Town[Bld].Name << endl;

                    system("PAUSE");
                }
                else
                {
                    cout << "No such location!\n\n";
                    system("PAUSE");
                }
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
            ScreenType = 3;
        }
        else if(Choice[0] == 4)
        {
            ScreenType = 4;
        }
        else if(Choice[0] == 5)
        {
            ScreenType = 5;
        }
        else if(Choice[0] == 6)
        {
            if(Atlas[Reg].Towns[Twn].Town[Bld].Residents[Choice[1]].ID != -1)
            {
                int PassID = Atlas[Reg].Towns[Twn].Town[Bld].Residents[Choice[1]].ID;

                character NPC = Atlas[Reg].Towns[Twn].Town[Bld].Residents[Choice[1]];

                Talk(Player, NPC, Screen, PassID, nCC, ScreenType);

                Atlas[Reg].Towns[Twn].Town[Bld].Residents[Choice[1]] = NPC;
            }
            else
            {
                cout << "No such character!\n\n";
                system("PAUSE");
            }
        }
        else if(Choice[0] == 7)
        {
            if(ScreenType == 2)
            {
                if(Choice[1] > -1 && Choice[1] < 10)
                {
                    if(Player[nCC].Inventory[Choice[1]]->Name != "Empty")
                    {
                        ScreenType = 4;

                        OpenWorldScreen(Screen, ScreenType, Player, nCC);

                        cout << "Equip to where? ";

                        Choice[0] = NumChoice(Choice[0]);

                        if(Choice[0] < 4 && Choice[0] > 0)
                        {
                            Player[nCC].Equip(Choice[1], Choice[0]);
                        }
                    }
                }
            }
            else if(ScreenType == 4)
            {
                if(Choice[1] > 0 && Choice[1] < 4)
                {
                    ScreenType = 2;

                    OpenWorldScreen(Screen, ScreenType, Player, nCC);

                    cout << "Equip what? ";

                    Choice[0] = NumChoice(Choice[0]) - 1;

                    if(Choice[0] < 10 && Choice[0] > -1)
                    {
                        Player[nCC].Equip(Choice[0], Choice[1]+1);
                    }
                }
            }
            else
            {
                cout << "Must be on Inventory or Equipment screen!\n\n";
                system("PAUSE");
            }

        }
        else if(Choice[0] == 8)
        {
            if(ScreenType == 2)
            {
                Player[nCC].DropItem(Choice[1]);
            }
            else
            {
                cout << "Must be on Inventory screen!\n\n";
                system("PAUSE");
            }
        }
        else if(Choice[0] == 9)
        {
            if(ScreenType == 4)
            {
                Player[nCC].Unequip(Choice[1]);
            }
            else
            {
                cout << "Must be on Equipment screen!\n\n";
                system("PAUSE");
            }
        }
    }
}
