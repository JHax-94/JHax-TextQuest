#include <iostream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <time.h>

using namespace std;

#include"screens.h"
#include"Info.h"
#include"Input.h"
#include"RaceApplication.h"
#include"fight.h"
#include"SaveGame.h"
#include"LoadGame.h"
#include"maps.h"
#include"dice.h"
#include"Puzzles.h"
#include"WorldInteraction.h"
#include"Traps.h"
#include"Investigations.h"
#include"BattleCommands.h"

int nCC;

//===================================================================================================================================================
//=========================================CHARACTER INFO============================================================================================
//===================================================================================================================================================

int CharacterStats[3][7] =
{
    {100, 0, 65, 50, 50, 100, 0},
    {0, 0, 50, 65, 50, 0, 0},
    {0, 0, 50, 50, 65, 0, 100}
};

int CharacterInventory[3][14] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 5, 0, 0},
    {0, 1, 0, 0, 1, 0, 30, 0, 0, 1, 0, 3, 2, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 5, 0}
};

int Keys[] = {0, 0, 0, 0};

string CharacterInfo[3][3] =
{
    {" ", " ", " "},
    {" ", " ", " "},
    {" ", " ", " "}
};



//===================================================================================================================================================
//====================================ROOM ITEMS=====================================================================================================
//===================================================================================================================================================

int CampItems[14] =   {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int Room01Items[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int Room03Items[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int Room12Items[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int WizardTower0Items[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0};

int WizardTower2Items[14] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};

//===================================================================================================================================================
//===================================ENEMY STATS=====================================================================================================
//===================================================================================================================================================

int Enemy[3][8] =
{
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int TrainingDummy[3][8] =
{
    {50, 0, 0, 0, 0, 1, 50, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int Goblin[3][8] =
{
    {50, 0, 20, 40, 5, 2, 50, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int BowGoblin[3][8] =
{
    {50, 0, 15, 45, 5, 2, 50, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int BarrackGoblins[3][8] =
{
    {50, 0, 20, 40, 5, 2, 50, 0},
    {50, 0, 15, 45, 5, 2, 50, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int LibraryGoblin[3][8] =
{
    {75, 0, 25, 40, 10, 2, 75, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int LibraryGoblins[3][8] =
{
    {75, 0, 25, 40, 10, 2, 75, 0},
    {90, 0, 30, 45, 15, 2, 90, 0},
    {90, 0, 30, 40, 15, 2, 90, 0}
};

int CaveTroll[3][8] =
{
    {100, 0, 100, 10, 0, 3, 100, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int SleepingQSkeleton[3][8] =
{
    {100, 0, 75, 60, 20, 4, 100, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int ArmourySkeleton[3][8] =
{
    {100, 0, 75, 60, 20, 4, 100, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int GuardSkeletons[3][8] =
{
    {100, 0, 75, 60, 20, 4, 100, 0},
    {100, 0, 75, 60, 20, 4, 100, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int LibrarySkeleton[3][8] =
{
    {100, 0, 80, 60, 20, 4, 100, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int GMTFHellHound[3][8] =
{
    {150, 0, 100, 100, 5, 8, 150, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int GMTFSkeletonA[3][8] =
{
    {100, 0, 80, 60, 20, 4, 100, 0},
    {100, 0, 80, 60, 20, 4, 100, 0},
    {200, 0, 90, 60, 20, 4, 100, 0},
};

int GMTFSkeletonB[3][8] =
{
    {100, 0, 80, 60, 20, 4, 100, 0},
    {100, 0, 80, 60, 20, 4, 100, 0},
    {200, 0, 90, 60, 20, 4, 200, 0}
};

int GMTFGoblins[3][8] =
{
    {90, 0, 65, 45, 10, 2, 90, 0},
    {100, 0, 75, 50, 15, 2, 100, 0},
    {90, 0, 65, 45, 10, 2, 90, 0}
};

int GMTFTrollCrew[3][8] =
{
    {250, 0, 120, 10, 0, 3, 250, 0},
    {90, 0, 65, 45, 10, 2, 90, 0},
    {150, 0, 100, 100, 5, 8, 150, 0}
};

int GMUMTroll[3][8] =
{
    {250, 0, 120, 10, 0, 3, 250, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int GMUMTrolls[3][8] =
{
    {250, 0, 120, 10, 0, 3, 250, 0},
    {250, 0, 120, 10, 0, 3, 250, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int GMUMSkeletons[3][8] =
{
    {200, 0, 90, 60, 20, 4, 200, 0},
    {200, 0, 90, 60, 20, 4, 200, 0},
    {100, 0, 80, 60, 20, 4, 100, 0}
};

int GMLMTroll[3][8] =
{
    {300, 0, 120, 10, 0, 3, 300, 0},
    {0,   0,   0,  0, 0, 0, 0, 0},
    {0,   0,   0,  0, 0, 0, 0, 0}
};

int GMBFSkeletonA[3][8] =
{
    {250, 0, 100, 70, 30, 4, 250, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int GMBFSkeletonB[3][8] =
{
    {250, 0, 110, 60, 30, 4, 250, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int GMBFHellHoundPack[3][8] =
{
    {150, 0, 100, 100, 5, 8, 150, 0},
    {150, 0, 100, 100, 5, 8, 150, 0},
    {200, 0, 100, 100, 5, 8, 200, 0}
};

int GMBFHellHound[3][8] =
{
    {100, 0, 50, 50, 5, 8, 100, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int GMBFOgre[3][8] =
{
    {400, 0, 300, 5, 5, 6, 400, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int GMBFDragon[3][8] =
{
    {999, 500, 125, 100, 80, 7, 999, 500},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int Warlock[3][8] =
{
    {150, 150, 60, 40, 100, 5, 150, 150},
    {50, 0, 20, 40, 5, 2, 50, 0},
    {50, 0, 20, 40, 5, 2, 50, 0}
};

int Wizard[3][8] =
{
    {250, 250, 60, 40, 150, 5, 250, 250},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int PiratesA[3][8] =
{
    {70, 50, 50, 50, 65, 9, 70, 50},
    {70, 0, 65, 50, 50, 9, 70, 0},
    {80, 50, 65, 50, 65, 9, 80, 50}
};

int PiratesB[3][8] =
{
    {150, 75, 75, 60, 75, 9, 150, 75},
    {80, 50, 65, 50, 65, 9, 80, 50},
    {80, 0, 70, 50, 50, 9, 80, 0}
};

int WeakDragon[3][8] =
{
    {300, 100, 110, 80, 60, 7, 300, 100},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

//===================================================================================================================================================
//==================================CONTROL VARIABLES================================================================================================
//===================================================================================================================================================
int Level;
int command;

bool Floor0 = false;
bool Dock = false;
bool DockHouse = false;
bool HasSpoon = false;

int Room00 = 0;
int Throne = 0;
int LibraryTime = 20;
int BlackKnight = 0;

bool Puzzle0Solved = false;
bool Puzzle1Solved = false;
bool Riddle0Solved = false;
bool Riddle1Solved = false;
bool Riddle2Solved = false;

bool trapA = true;
bool trapB = true;
bool trapC = true;
bool trapD = true;
bool trapE = true;
bool trapF = true;
bool trapG = true;
bool trapH = true;
bool trapI = true;

//===================================================================================================================================================
//==================================SCREENS==========================================================================================================
//===================================================================================================================================================
string LevelScreen[32];

void Reset()
{

    int i;
    int j;

    nCC = 0;
//===================================================================================================================================================
    CharacterStats[0][0] = 100;
    CharacterStats[0][1] = 0;
    CharacterStats[0][2] = 65;
    CharacterStats[0][3] = 50;
    CharacterStats[0][4] = 50;
    CharacterStats[0][5] = 100;
    CharacterStats[0][6] = 0;

    CharacterStats[1][0] = 0;
    CharacterStats[1][1] = 0;
    CharacterStats[1][2] = 50;
    CharacterStats[1][3] = 65;
    CharacterStats[1][4] = 50;
    CharacterStats[1][5] = 0;
    CharacterStats[1][6] = 0;

    CharacterStats[2][0] = 0;
    CharacterStats[2][1] = 0;
    CharacterStats[2][2] = 50;
    CharacterStats[2][3] = 65;
    CharacterStats[2][4] = 50;
    CharacterStats[2][5] = 0;
    CharacterStats[2][6] = 100;
//===================================================================================================================================================
    CharacterInventory[0][0] = 0;
    CharacterInventory[0][1] = 0;
    CharacterInventory[0][2] = 0;
    CharacterInventory[0][3] = 0;
    CharacterInventory[0][4] = 0;
    CharacterInventory[0][5] = 0;
    CharacterInventory[0][6] = 0;
    CharacterInventory[0][7] = 0;
    CharacterInventory[0][8] = 0;
    CharacterInventory[0][9] = 1;
    CharacterInventory[0][10] = 0;
    CharacterInventory[0][11] = 0;
    CharacterInventory[0][12] = 0;
    CharacterInventory[0][13] = 0;

    CharacterInventory[1][0] = 0;
    CharacterInventory[1][1] = 1;
    CharacterInventory[1][2] = 0;
    CharacterInventory[1][3] = 0;
    CharacterInventory[1][4] = 1;
    CharacterInventory[1][5] = 0;
    CharacterInventory[1][6] = 20;
    CharacterInventory[1][7] = 0;
    CharacterInventory[1][8] = 0;
    CharacterInventory[1][9] = 1;
    CharacterInventory[1][10] = 0;
    CharacterInventory[1][11] = 0;
    CharacterInventory[1][12] = 0;
    CharacterInventory[1][13] = 0;

    CharacterInventory[2][0] = 0;
    CharacterInventory[2][1] = 0;
    CharacterInventory[2][2] = 0;
    CharacterInventory[2][3] = 0;
    CharacterInventory[2][4] = 0;
    CharacterInventory[2][5] = 0;
    CharacterInventory[2][6] = 0;
    CharacterInventory[2][7] = 1;
    CharacterInventory[2][8] = 0;
    CharacterInventory[2][9] = 1;
    CharacterInventory[2][10] = 0;
    CharacterInventory[2][11] = 0;
    CharacterInventory[2][12] = 0;
    CharacterInventory[2][13] = 0;
//===================================================================================================================================================

    Keys[0] = 0;
    Keys[1] = 0;
    Keys[2] = 0;

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 3; j ++)
        {
            CharacterInfo[i][j] = " ";
        }
    }



//===================================================================================================================================================
//====================================ROOM ITEMS=====================================================================================================
//===================================================================================================================================================
    CampItems[0] = 1;
    CampItems[1] = 0;
    CampItems[2] = 1;
    CampItems[3] = 0;
    CampItems[4] = 0;
    CampItems[5] = 0;
    CampItems[6] = 0;
    CampItems[7] = 0;
    CampItems[8] = 0;
    CampItems[9] = 0;
    CampItems[10] = 0;
    CampItems[11] = 0;
    CampItems[12] = 0;
    CampItems[13] = 0;

//===================================================================================================================================================

    Room01Items[0] = 0;
    Room01Items[1] = 0;
    Room01Items[2] = 0;
    Room01Items[3] = 0;
    Room01Items[4] = 0;
    Room01Items[5] = 0;
    Room01Items[6] = 0;
    Room01Items[7] = 0;
    Room01Items[8] = 0;
    Room01Items[9] = 0;
    Room01Items[10] = 0;
    Room01Items[11] = 0;
    Room01Items[12] = 0;
    Room01Items[13] = 0;



    Room03Items[0] = 0;
    Room03Items[1] = 0;
    Room03Items[2] = 0;
    Room03Items[3] = 0;
    Room03Items[4] = 0;
    Room03Items[5] = 0;
    Room03Items[6] = 0;
    Room03Items[7] = 0;
    Room03Items[8] = 0;
    Room03Items[9] = 0;
    Room03Items[10] = 0;
    Room03Items[11] = 0;
    Room03Items[12] = 0;
    Room03Items[13] = 0;


    Room12Items[0] = 0;
    Room12Items[1] = 0;
    Room12Items[2] = 0;
    Room12Items[3] = 0;
    Room12Items[4] = 0;
    Room12Items[5] = 0;
    Room12Items[6] = 0;
    Room12Items[7] = 0;
    Room12Items[8] = 0;
    Room12Items[9] = 0;
    Room12Items[10] = 0;
    Room12Items[11] = 0;
    Room12Items[12] = 0;
    Room12Items[13] = 0;

    WizardTower0Items[0] = 0;
    WizardTower0Items[1] = 0;
    WizardTower0Items[2] = 0;
    WizardTower0Items[3] = 0;
    WizardTower0Items[4] = 0;
    WizardTower0Items[5] = 0;
    WizardTower0Items[6] = 0;
    WizardTower0Items[7] = 0;
    WizardTower0Items[8] = 0;
    WizardTower0Items[9] = 0;
    WizardTower0Items[10] = 0;
    WizardTower0Items[11] = 5;
    WizardTower0Items[12] = 5;
    WizardTower0Items[13] = 0;

    WizardTower2Items[0] = 0;
    WizardTower2Items[1] = 0;
    WizardTower2Items[2] = 0;
    WizardTower2Items[3] = 0;
    WizardTower2Items[4] = 0;
    WizardTower2Items[5] = 0;
    WizardTower2Items[6] = 0;
    WizardTower2Items[7] = 0;
    WizardTower2Items[8] = 1;
    WizardTower2Items[9] = 0;
    WizardTower2Items[10] = 0;
    WizardTower2Items[11] = 0;
    WizardTower2Items[12] = 0;
    WizardTower2Items[13] = 0;

//===================================================================================================================================================
//===================================ENEMY STATS=====================================================================================================
//===================================================================================================================================================


    TrainingDummy[0][0] = 50;
    TrainingDummy[0][1] = 0;
    TrainingDummy[0][2] = 0;
    TrainingDummy[0][3] = 0;
    TrainingDummy[0][4] = 0;
    TrainingDummy[0][5] = 1;
    for(i = 1; i < 3; i ++)
    {
        for(j = 0; j < 6; j ++)
        {
            TrainingDummy[i][j] = 0;
        }
    }

    Goblin[0][0] = 50;
    Goblin[0][1] = 0;
    Goblin[0][2] = 20;
    Goblin[0][3] = 40;
    Goblin[0][4] = 5;
    Goblin[0][5] = 2;
    for(i = 1; i < 3; i ++)
    {
        for(j = 0; j < 6; j ++)
        {
            Goblin[i][j] = 0;
        }
    }


    BowGoblin[0][0] = 50;
    BowGoblin[0][1] = 0;
    BowGoblin[0][2] = 15;
    BowGoblin[0][3] = 45;
    BowGoblin[0][4] = 5;
    BowGoblin[0][5] = 2;
    for(i = 1; i < 3; i ++)
    {
        for(j = 0; j < 6; j ++)
        {
            BowGoblin[i][j] = 0;
        }
    }



    BarrackGoblins[0][0] = 50;
    BarrackGoblins[0][1] = 0;
    BarrackGoblins[0][2] = 20;
    BarrackGoblins[0][3] = 40;
    BarrackGoblins[0][4] = 5;
    BarrackGoblins[0][5] = 2;

    BarrackGoblins[1][0] = 50;
    BarrackGoblins[1][1] = 0;
    BarrackGoblins[1][2] = 15;
    BarrackGoblins[1][3] = 45;
    BarrackGoblins[1][4] = 5;
    BarrackGoblins[1][5] = 2;
    for(i = 0; i < 6; i ++)
    {
        BarrackGoblins[2][i] = 0;
    }

    LibraryGoblin[0][0] = 75;
    LibraryGoblin[0][1] = 0;
    LibraryGoblin[0][2] = 25;
    LibraryGoblin[0][3] = 40;
    LibraryGoblin[0][4] = 10;
    LibraryGoblin[0][5] = 2;

    for(i = 0; i<6; i++)
    {
        LibraryGoblin[1][i] =0;
        LibraryGoblin[2][i] =0;
    }

    LibraryGoblins[0][0] = 75;
    LibraryGoblins[0][1] = 0;
    LibraryGoblins[0][2] = 25;
    LibraryGoblins[0][3] = 40;
    LibraryGoblins[0][4] = 10;
    LibraryGoblins[0][5] = 2;
    LibraryGoblins[1][0] = 90;
    LibraryGoblins[1][1] = 0;
    LibraryGoblins[1][2] = 30;
    LibraryGoblins[1][3] = 45;
    LibraryGoblins[1][4] = 15;
    LibraryGoblins[1][5] = 2;
    LibraryGoblins[2][0] = 90;
    LibraryGoblins[2][1] = 0;
    LibraryGoblins[2][2] = 30;
    LibraryGoblins[2][3] = 40;
    LibraryGoblins[2][4] = 15;
    LibraryGoblins[2][5] = 2;

    CaveTroll[0][0] = 100;
    CaveTroll[0][1] = 0;
    CaveTroll[0][2] = 100;
    CaveTroll[0][3] = 10;
    CaveTroll[0][4] = 0;
    CaveTroll[0][5] = 3;
    for(i = 1; i < 3; i ++)
    {
        for(j = 0; j < 6; j ++)
        {
            CaveTroll[i][j] = 0;
        }
    }



    SleepingQSkeleton[0][0] = 100;
    SleepingQSkeleton[0][1] = 0;
    SleepingQSkeleton[0][2] = 75;
    SleepingQSkeleton[0][3] = 60;
    SleepingQSkeleton[0][4] = 20;
    SleepingQSkeleton[0][5] = 4;
    for(i = 1; i < 3; i ++)
    {
        for(j = 0; j < 6; j ++)
        {
            SleepingQSkeleton[i][j] = 0;
        }
    }


    ArmourySkeleton[0][0] = 100;
    ArmourySkeleton[0][1] = 0;
    ArmourySkeleton[0][2] = 75;
    ArmourySkeleton[0][3] = 60;
    ArmourySkeleton[0][4] = 20;
    ArmourySkeleton[0][5] = 4;
    for(i = 1; i < 3; i ++)
    {
        for(j = 0; j < 6; j ++)
        {
            ArmourySkeleton[i][j] = 0;
        }
    }

    GuardSkeletons[0][0] = 100;
    GuardSkeletons[0][1] = 0;
    GuardSkeletons[0][2] = 75;
    GuardSkeletons[0][3] = 60;
    GuardSkeletons[0][4] = 20;
    GuardSkeletons[0][5] = 4;

    GuardSkeletons[1][0] = 100;
    GuardSkeletons[1][1] = 0;
    GuardSkeletons[1][2] = 75;
    GuardSkeletons[1][3] = 60;
    GuardSkeletons[1][4] = 20;
    GuardSkeletons[1][5] = 4;
    for(i = 0; i < 6; i ++)
    {
        GuardSkeletons[2][i] = 0;
    }

    LibrarySkeleton[0][0] = 100;
    LibrarySkeleton[0][1] = 0;
    LibrarySkeleton[0][2] = 80;
    LibrarySkeleton[0][3] = 60;
    LibrarySkeleton[0][4] = 20;
    LibrarySkeleton[0][5] = 4;
    for(i = 0; i < 6; i ++)
    {
        LibrarySkeleton[1][i] = 0;
        LibrarySkeleton[2][i] = 0;
    }

    GMTFHellHound[0][0] = 150;
    GMTFHellHound[0][1] = 0;
    GMTFHellHound[0][2] = 100;
    GMTFHellHound[0][3] = 100;
    GMTFHellHound[0][4] = 5;
    GMTFHellHound[0][5] = 8;
    for(i = 0; i < 6; i ++)
    {
        GMTFHellHound[1][i] = 0;
        GMTFHellHound[2][i] = 0;
    }

    GMTFSkeletonA[0][0] = 100;
    GMTFSkeletonA[0][1] = 0;
    GMTFSkeletonA[0][2] = 80;
    GMTFSkeletonA[0][3] = 60;
    GMTFSkeletonA[0][4] = 20;
    GMTFSkeletonA[0][5] = 4;
    GMTFSkeletonA[1][0] = 100;
    GMTFSkeletonA[1][1] = 0;
    GMTFSkeletonA[1][2] = 80;
    GMTFSkeletonA[1][3] = 60;
    GMTFSkeletonA[1][4] = 20;
    GMTFSkeletonA[1][5] = 4;
    GMTFSkeletonA[2][0] = 200;
    GMTFSkeletonA[2][1] = 0;
    GMTFSkeletonA[2][2] = 90;
    GMTFSkeletonA[2][3] = 60;
    GMTFSkeletonA[2][4] = 20;
    GMTFSkeletonA[2][5] = 4;

    GMTFSkeletonB[0][0] = 100;
    GMTFSkeletonB[0][1] = 0;
    GMTFSkeletonB[0][2] = 80;
    GMTFSkeletonB[0][3] = 60;
    GMTFSkeletonB[0][4] = 20;
    GMTFSkeletonB[0][5] = 4;
    GMTFSkeletonB[1][0] = 100;
    GMTFSkeletonB[1][1] = 0;
    GMTFSkeletonB[1][2] = 80;
    GMTFSkeletonB[1][3] = 60;
    GMTFSkeletonB[1][4] = 20;
    GMTFSkeletonB[1][5] = 4;
    GMTFSkeletonB[2][0] = 200;
    GMTFSkeletonB[2][1] = 0;
    GMTFSkeletonB[2][2] = 90;
    GMTFSkeletonB[2][3] = 60;
    GMTFSkeletonB[2][4] = 20;
    GMTFSkeletonB[2][5] = 4;

    GMTFGoblins[0][0] = 90;
    GMTFGoblins[0][1] = 0;
    GMTFGoblins[0][2] = 65;
    GMTFGoblins[0][3] = 45;
    GMTFGoblins[0][4] = 10;
    GMTFGoblins[0][5] = 2;
    GMTFGoblins[1][0] = 100;
    GMTFGoblins[1][1] = 0;
    GMTFGoblins[1][2] = 75;
    GMTFGoblins[1][3] = 50;
    GMTFGoblins[1][4] = 15;
    GMTFGoblins[1][5] = 2;
    GMTFGoblins[2][0] = 90;
    GMTFGoblins[2][1] = 0;
    GMTFGoblins[2][2] = 65;
    GMTFGoblins[2][3] = 45;
    GMTFGoblins[2][4] = 10;
    GMTFGoblins[2][5] = 2;

    GMTFTrollCrew[0][0] = 250;
    GMTFTrollCrew[0][1] = 0;
    GMTFTrollCrew[0][2] = 120;
    GMTFTrollCrew[0][3] = 10;
    GMTFTrollCrew[0][4] = 0;
    GMTFTrollCrew[0][5] = 3;
    GMTFTrollCrew[1][0] = 90;
    GMTFTrollCrew[1][1] = 0;
    GMTFTrollCrew[1][2] = 65;
    GMTFTrollCrew[1][3] = 45;
    GMTFTrollCrew[1][4] = 10;
    GMTFTrollCrew[1][5] = 2;
    GMTFTrollCrew[2][0] = 150;
    GMTFTrollCrew[2][1] = 0;
    GMTFTrollCrew[2][2] = 100;
    GMTFTrollCrew[2][3] = 100;
    GMTFTrollCrew[2][4] = 5;
    GMTFTrollCrew[2][5] = 8;

    GMUMTroll[0][0] = 250;
    GMUMTroll[0][1] = 0;
    GMUMTroll[0][2] = 120;
    GMUMTroll[0][3] = 10;
    GMUMTroll[0][4] = 0;
    GMUMTroll[0][5] = 3;
    for(i = 1; i < 6; i++)
    {
        GMUMTroll[1][i] = 0;
        GMUMTroll[2][i] = 0;
    }

    for(i = 0; i < 2; i ++)
    {
        GMUMTrolls[i][0] = 250;
        GMUMTrolls[i][1] = 0;
        GMUMTrolls[i][2] = 120;
        GMUMTrolls[i][3] = 10;
        GMUMTrolls[i][4] = 0;
        GMUMTrolls[i][5] = 3;
    }
    for(i = 0; i < 6; i ++)
    {
        GMUMTrolls[2][i] = 0;
    }

    for(i = 0; i < 2; i ++)
    {
        GMUMSkeletons[i][0] = 200;
        GMUMSkeletons[i][1] = 0;
        GMUMSkeletons[i][2] = 90;
        GMUMSkeletons[i][3] = 60;
        GMUMSkeletons[i][4] = 20;
        GMUMSkeletons[i][5] = 4;
    }
    GMUMSkeletons[2][0] = 100;
    GMUMSkeletons[2][1] = 0;
    GMUMSkeletons[2][2] = 80;
    GMUMSkeletons[2][3] = 60;
    GMUMSkeletons[2][4] = 20;
    GMUMSkeletons[2][5] = 4;

    GMLMTroll[0][0] = 300;
    GMLMTroll[0][1] = 0;
    GMLMTroll[0][2] = 120;
    GMLMTroll[0][3] = 10;
    GMLMTroll[0][4] = 0;
    GMLMTroll[0][5] = 3;

    for(i = 0; i < 5; i ++)
    {
        GMLMTroll[1][i] = 0;
        GMLMTroll[2][i] = 0;
    }

    GMBFSkeletonA[0][0] = 250;
    GMBFSkeletonA[0][1] = 0;
    GMBFSkeletonA[0][2] = 100;
    GMBFSkeletonA[0][3] = 70;
    GMBFSkeletonA[0][4] = 30;
    GMBFSkeletonA[0][5] = 4;

    for(i = 0; i < 5; i ++)
    {
        GMBFSkeletonA[1][i] = 0;
        GMBFSkeletonA[2][i] = 0;
    }

    GMBFSkeletonB[0][0] = 250;
    GMBFSkeletonB[0][1] = 0;
    GMBFSkeletonB[0][2] = 100;
    GMBFSkeletonB[0][3] = 70;
    GMBFSkeletonB[0][4] = 30;
    GMBFSkeletonB[0][5] = 4;

    for(i = 0; i < 5; i ++)
    {
        GMBFSkeletonB[1][i] = 0;
        GMBFSkeletonB[2][i] = 0;
    }


    for(i = 0; i < 3; i ++)
    {
        GMBFHellHoundPack[i][0] = 100;
        GMBFHellHoundPack[i][1] = 0;
        GMBFHellHoundPack[i][2] = 100;
        GMBFHellHoundPack[i][3] = 100;
        GMBFHellHoundPack[i][4] = 5;
        GMBFHellHoundPack[i][5] = 8;
    }
    GMBFHellHoundPack[2][0] = 200;


    GMBFHellHound[0][0] = 100;
    GMBFHellHound[0][1] = 0;
    GMBFHellHound[0][2] = 50;
    GMBFHellHound[0][3] = 50;
    GMBFHellHound[0][4] = 5;
    GMBFHellHound[0][5] = 8;
    for(i = 0; i < 6; i ++)
    {
        GMBFHellHound[1][i] = 0;
        GMBFHellHound[2][i] = 0;
    }

    GMBFOgre[0][0] = 400;
    GMBFOgre[0][1] = 0;
    GMBFOgre[0][2] = 300;
    GMBFOgre[0][3] = 5;
    GMBFOgre[0][4] = 5;
    GMBFOgre[0][5] = 6;
    for(i = 0; i < 6; i ++)
    {
        GMBFOgre[1][i] = 0;
        GMBFOgre[2][i] = 0;
    }

    GMBFDragon[0][0] = 999;
    GMBFDragon[0][1] = 500;
    GMBFDragon[0][2] = 150;
    GMBFDragon[0][3] = 100;
    GMBFDragon[0][4] = 80;
    GMBFDragon[0][5] = 7;
    for(i = 0; i < 6; i ++)
    {
        GMBFDragon[1][i] = 0;
        GMBFDragon[2][i] = 0;
    }

    Warlock[0][0] = 150;
    Warlock[0][1] = 150;
    Warlock[0][2] = 60;
    Warlock[0][3] = 40;
    Warlock[0][4] = 100;
    Warlock[0][5] = 5;
    Warlock[1][0] = 50;
    Warlock[1][1] = 0;
    Warlock[1][2] = 20;
    Warlock[1][3] = 40;
    Warlock[1][4] = 5;
    Warlock[1][5] = 2;
    Warlock[2][0] = 50;
    Warlock[2][1] = 0;
    Warlock[2][2] = 20;
    Warlock[2][3] = 40;
    Warlock[2][4] = 5;
    Warlock[2][5] = 2;

    Wizard[0][0] = 250;
    Wizard[0][1] = 250;
    Wizard[0][2] = 60;
    Wizard[0][3] = 40;
    Wizard[0][4] = 150;
    Wizard[0][5] = 5;
    for(i = 0; i < 6; i ++)
    {
        Wizard[1][i] = 0;
        Wizard[2][i] = 0;
    }

    PiratesA[0][0] = 70;
    PiratesA[0][1] = 50;
    PiratesA[0][2] = 50;
    PiratesA[0][3] = 50;
    PiratesA[0][4] = 65;
    PiratesA[0][5] = 9;
    PiratesA[1][0] = 70;
    PiratesA[1][1] = 0;
    PiratesA[1][2] = 65;
    PiratesA[1][3] = 50;
    PiratesA[1][4] = 50;
    PiratesA[1][5] = 9;
    PiratesA[2][0] = 80;
    PiratesA[2][1] = 50;
    PiratesA[2][2] = 65;
    PiratesA[2][3] = 50;
    PiratesA[2][4] = 65;
    PiratesA[2][5] = 9;

    PiratesB[0][0] = 150;
    PiratesB[0][1] = 75;
    PiratesB[0][2] = 75;
    PiratesB[0][3] = 60;
    PiratesB[0][4] = 75;
    PiratesB[0][5] = 9;
    PiratesB[1][0] = 80;
    PiratesB[1][1] = 50;
    PiratesB[1][2] = 65;
    PiratesB[1][3] = 50;
    PiratesB[1][4] = 65;
    PiratesB[1][5] = 9;
    PiratesB[2][0] = 80;
    PiratesB[2][1] = 0;
    PiratesB[2][2] = 70;
    PiratesB[2][3] = 50;
    PiratesB[2][4] = 50;
    PiratesB[2][5] = 9;

    WeakDragon[0][0] = 300;
    WeakDragon[0][1] = 100;
    WeakDragon[0][2] = 125;
    WeakDragon[0][3] = 80;
    WeakDragon[0][4] = 60;
    WeakDragon[0][5] = 7;
    for(i = 0; i < 6; i ++)
    {
        WeakDragon[1][i] = 0;
        WeakDragon[2][i] = 0;
    }

    Floor0 = false;
    Dock = false;
    DockHouse = false;
    HasSpoon = false;

    Room00 = 0;
    Throne = 0;
    LibraryTime = 20;

    Puzzle0Solved = false;
    Puzzle1Solved = false;
    Riddle0Solved = false;
    Riddle1Solved = false;
    Riddle2Solved = false;

    trapA = true;
    trapB = true;
    trapC = true;
    trapD = true;
    trapE = true;
    trapF = true;
    trapG = true;
    trapH = true;
    trapI = true;
}

void Switch()
{
    bool Loop;
    nCC ++;

    Loop = true;

    if(nCC == 3)
    {
        nCC = 0;
    }

    while(Loop == true)
    {
        if(nCC == 3)
        {
            nCC = 0;
        }
        if(CharacterStats[nCC][0] == 0)
        {
            nCC ++;
        }
        else if(CharacterStats[nCC][0] != 0)
        {
            Loop = false;
        }
    }
    AddCharacter(CharacterInfo, nCC, LevelScreen);
    drawScreen(LevelScreen, 32);
}



string TitleScreen[] =
{
        "                                                                               \n",
        "    _ _ _ _ _ _                                                                \n",
        "   /          /                                                               \n",
        "  /_ _    _ _/_ _                                                              \n",
        "     /   /  _ _ _/ _ _     _ _    _ _ _ _ _                               \n",
        "    /   /  /_      \\   \\  /  /   /_ _  _ _/                                \n",
        "   /   /   _ /      \\   \\/  /      / /                                   \n",
        "  /   /   /_ _      /   /\\   \\    / /                 _ _ _ _ _ _ _ _ _ _  \n",
        " /_ _/_ _ _ _/     /_ _/  \\_ _\\  /_/                 /_ _    _ _     _ _ /  \n",
        "                                                        /   /   /   /       \n",
        "           _ _                                         /   /   /   /       \n",
        "          /    \\                                      /   /   /   /       \n",
        "         |  / \\ \\           _ _  _ _ _  _ _ _        /   /   /   /       \n",
        "         |  | | |   | | || |  _||  _ _\\|_   _|      /   /   /   /          \n",
        "          \\  \\/  \\  | \\/ | |  _||_ _  |  | |    _ _/   /_ _/   /_ _      \n",
        "           \\_ _ /\\\\  \\__/  |_ _|\\_ _ _|  |_|   /_ _ _ _ _ _ _ _ _ /      \n",
        "                                                                            \n",
        "                                                                            \n",
        "                                                                               \n",
        "                                     1 -  New Game                        \n",
        "                                        2 - Load Game                          \n",
        "                                           3 - Information                     \n",
        "                                             4 - Exit                          \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n"
};

string PlayerMap0[] =
{
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n"
};

string PlayerMap1[] =
{
       "                                                                               \n",
       "                                                                               \n",
       "                                                                               \n",
       "                                                                               \n",
       "                                                                               \n",
       "                                                                               \n",
       "                                                                               \n",
       "                                                                               \n",
       "                                                                               \n",
       "                                                                               \n",
       "                                                                               \n",
       "                                                                               \n",
       "                                                                               \n",
       "                                                                               \n",
       "                                                                               \n",
       "                                                                               \n",
       "                                                                               \n"
};

string PlayerMap2[] =
{
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n"
};

string PlayerMap3[] =
{
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n"
};

string PlayerMap4[] =
{
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n"
};

string PlayerMap5[] =
{
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n"
};

string PlayerMap6[] =
{
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n"
};

string PlayerMap7[] =
{
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n"
};

string PlayerMap8[] =
{
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n"
};

string WarlockDenMap[] =
{
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n"
};

string SpoonTroveMap[] =
{
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n",
        "                                                                               \n"
};

string WizardTowerMap0[] =
{
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n"
};

string WizardTowerMap1[] =
{
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n"
};

string WizardTowerMap2[] =
{
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n"
};

void ResetMap(string Map[], int MapSize)
{
    int i;

    for(i = 0; i < MapSize; i ++)
    {
        Map[i] = "                                                                               \n";
    }
}

void ResetMaps()
{
    ResetMap(PlayerMap0, 15);
    ResetMap(PlayerMap1, 17);
    ResetMap(PlayerMap2, 19);
    ResetMap(PlayerMap3, 14);
    ResetMap(PlayerMap4, 15);
    ResetMap(PlayerMap5, 20);
    ResetMap(PlayerMap6, 18);
    ResetMap(PlayerMap7, 20);
    ResetMap(PlayerMap8, 15);
    ResetMap(WarlockDenMap, 5);
    ResetMap(SpoonTroveMap, 5);
    ResetMap(WizardTowerMap0, 9);
    ResetMap(WizardTowerMap1, 9);
    ResetMap(WizardTowerMap2, 9);
}
//===================================================================================================================================================
//=========================================START GAME FUNCTION=======================================================================================
//===================================================================================================================================================

void Save()
{
    SaveGame(nCC, Level, Dock, DockHouse, HasSpoon, Room00, Throne, LibraryTime, BlackKnight,
              Puzzle0Solved, Puzzle1Solved, Riddle0Solved, Riddle1Solved, Riddle2Solved,
              trapA, trapB, trapC, trapD, trapE, trapF, trapG, trapH, trapI,
              CharacterInfo, CharacterStats, CharacterInventory, Keys,
              CampItems, Room01Items, Room03Items, Room12Items, WizardTower0Items, WizardTower2Items,
              TrainingDummy, Goblin, BowGoblin, BarrackGoblins, LibraryGoblin, LibraryGoblins, CaveTroll, SleepingQSkeleton, ArmourySkeleton, GuardSkeletons, LibrarySkeleton, GMTFHellHound, GMTFSkeletonA, GMTFSkeletonB, GMTFGoblins, GMTFTrollCrew,
              GMUMTroll, GMUMTrolls, GMUMSkeletons, GMLMTroll, GMBFSkeletonA, GMBFSkeletonB, GMBFHellHoundPack, GMBFHellHound, GMBFOgre, GMBFDragon, Warlock, Wizard,
              PiratesA, PiratesB, WeakDragon,
              PlayerMap0, PlayerMap1, PlayerMap2, PlayerMap3, PlayerMap4, PlayerMap5, PlayerMap6, PlayerMap7, PlayerMap8, WarlockDenMap, SpoonTroveMap, WizardTowerMap0, WizardTowerMap1, WizardTowerMap2);
}

void CheckLibraryTime()
{
    int Dice;

    if(LibraryTime == 0)
    {
        cout << "You have gained great knowledge from your time spent in the Library!\n\n";
        system("PAUSE");

        LibraryTime = -1;

        Dice = RollDice(10);

        if(Dice == 1)
        {
            CharacterStats[0][2] += 20;
            CharacterStats[1][3] += 20;
            CharacterStats[2][4] += 20;
        }
        else if(Dice == 2)
        {
            CharacterStats[0][2] += 10;
            CharacterStats[1][2] += 10;
            CharacterStats[2][2] += 10;
        }
        else if(Dice == 3)
        {
            CharacterStats[0][3] += 10;
            CharacterStats[1][3] += 10;
            CharacterStats[2][3] += 10;
        }
        else if(Dice == 4)
        {
            CharacterStats[0][4] += 10;
            CharacterStats[1][4] += 10;
            CharacterStats[2][4] += 10;
        }
    }
    else if(LibraryTime > 0)
    {
        LibraryTime --;
    }
}

bool CheckAlive()
{
    bool alive;

    if(CharacterStats[0][0] != 0 || CharacterStats[1][0] != 0 || CharacterStats[2][0] != 0)
    {
        alive = true;
    }
    else
    {
        alive = false;
    }

    if(alive == true)
    {
        if(CharacterStats[nCC][0] == 0)
        {
            Switch();
        }
    }

    return alive;
}

void UsePotion()
{
    int potion;

    if(CharacterInventory[nCC][11] != 0 || CharacterInventory[nCC][12] != 0)
    {
        potion = Use(nCC, CharacterInventory);
    }
    else
    {
        cout << "You don't have any potions!\n\n";
        system("PAUSE");
    }


    if(potion != -1)
    {
        if(potion == 1)
        {
            cout << CharacterInfo[nCC][0] << " uses a health potion!\n\n";

            RestoreHealth((nCC + 1), 25, CharacterStats, Enemy, true);

            system("PAUSE");
        }
        else if(potion == 2)
        {
            cout << CharacterInfo[nCC][0] << " uses a magic potion!\n\n";

            RestoreMagic(nCC, CharacterStats);

            system("PAUSE");
        }
    }
    return;
}



void StartGame()
{
    bool GameOn = true;
    string tempName;
    bool Loop;
    bool ForceFight;
    bool alive;

    int NameLength;
    int BattleResult;
    int PuzzleResult;
    int Roll;
    int sneak;
    int world;
    int YN;
    int i;

    int Floor;
    int Room;


    while(GameOn == true)
    {
        EmptyScreen(LevelScreen);

      //  Save();

        switch(Level)
        {
            case 0:
            {
                nCC = 0;

                LevelScreen[0]  = "===============================================================================\n";
                LevelScreen[1]  = "=============================ARMY CAMP=========================================\n";
                LevelScreen[2]  = "================================TENT===========================================\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "  ...                                                                          \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";

                drawScreen(LevelScreen, 32);
                system("PAUSE");

                LevelScreen[7] = "  You hear rain drops hitting the side of your tent...                        \n";

                drawScreen(LevelScreen, 32);
                system("PAUSE");

                LevelScreen[7] = "  A voice calls out from outside...                                           \n";

                drawScreen(LevelScreen, 32);
                system("PAUSE");

                LevelScreen[7] = "Commander: SOLDIER!                                                            \n";
                LevelScreen[8] = "           Get up!                                                             \n";

                drawScreen(LevelScreen, 32);
                system("PAUSE");

                LevelScreen[3] = " * * * To follow the Commander's orders, simply type the action he asks * * *  \n";
                LevelScreen[4] = " * * * and press enter!                                                 * * *  \n";



                Loop = true;

                while(Loop == true)
                {
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 0)
                    {
                        Loop = false;
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        LevelScreen[5] = " * * * This is not a valid command at the moment!                        * * * \n";
                    }
                }

                Level = 1;

            break;
            }
            case 1:
            {
                    LevelScreen[0]  = "===============================================================================\n";
                    LevelScreen[1]  = "=============================ARMY CAMP=========================================\n";
                    LevelScreen[2]  = "================================TENT===========================================\n";
                    LevelScreen[3]  = "                                                                               \n";
                    LevelScreen[4]  = "                                                                               \n";
                    LevelScreen[5]  = "                                                                               \n";
                    LevelScreen[6]  = "                                                                               \n";
                    LevelScreen[7]  = "                                                                               \n";
                    LevelScreen[8]  = "                                                                               \n";
                    LevelScreen[9]  = "                                                                               \n";
                    LevelScreen[10] = "                                                                               \n";
                    LevelScreen[11] = "  ------: I'm up sir!                                                          \n";
                    LevelScreen[12] = "                                                                               \n";
                    LevelScreen[13] = "  Commander: Alright Private. Pick up your Armour!                             \n";
                    LevelScreen[14] = "                                                                               \n";
                    LevelScreen[15] = "                                                                               \n";

                    drawScreen(LevelScreen, 32);

                    system("PAUSE");

                    LevelScreen[4] = " * * * Use the INVESTIGATE command to have a look around the room.       * * *\n";
                    LevelScreen[5] = " * * * The INVESTIGATE command can be used to have a take a closer look  * * *\n";
                    LevelScreen[6] = " * * * at something, or to discover vital information about the room     * * *\n";
                    LevelScreen[7] = " * * * you are in.                                                       * * *\n";


                    drawScreen(LevelScreen, 32);

                    system("PAUSE");

                    Loop = true;

                    while(Loop == true)
                    {
                        command = Input();

                        if(command == 9)
                        {
                            Loop = false;
                            cout << "A set of armour and a sword lie in the corner of the tent.\n\n";
                            system("PAUSE");
                        }
                        else
                        {
                            cout << "You must look around the room first!\n\n";

                            system("PAUSE");
                        }
                    }

                    LevelScreen[3] = " * * * Some commands require 2 parts, such as the 'Pick up' command.     * * * \n";
                    LevelScreen[4] = " * * * First, type 'Pick up', then you will be prompted to enter an      * * * \n";
                    LevelScreen[5] = " * * * object to pick up. For potions and arrows type the plural         * * * \n";
                    LevelScreen[6] = " * * * to pick up all of that item in the room, or the singular to pick  * * * \n";
                    LevelScreen[7] = " * * * to pick up just one!                                              * * * \n";

                    Loop = true;

                    while(Loop == true)
                    {
                        drawScreen(LevelScreen, 32);
                        command = Input();

                        if(command == 1)
                        {
                            PickUp(CharacterInventory, CampItems, nCC);

                            if(CharacterInventory[0][2] == 1)
                            {
                                CampItems[2] ++;
                                CharacterInventory[0][2] --;
                                LevelScreen[8] = " * * * You must pick up the Plate Armour! The sword has been put back.   * * * \n";
                            }
                            else if(CharacterInventory[0][0] == 1)
                            {
                                Level = 2;
                                Loop = false;
                            }
                        }
                        else if(command == 13)
                        {
                            info();
                        }
                        else if(command == -1)
                        {
                            return;
                        }
                        else
                        {
                            LevelScreen[8] = " * * * This is not a valid command at the moment!                        * * * \n";
                        }
                    }
            break;
            }
            case 2:
            {
                LevelScreen[0]  = "===============================================================================\n";
                LevelScreen[1]  = "=============================ARMY CAMP=========================================\n";
                LevelScreen[2]  = "================================TENT===========================================\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "  Commander: Alright then soldier, pick up your sword and get out here,        \n";
                LevelScreen[11] = "             and we'll do some drills!                                         \n";
                LevelScreen[12] = "                                                                               \n";
                LevelScreen[13] = "                                                                               \n";
                LevelScreen[14] = "                                                                               \n";
                LevelScreen[15] = "                                                                               \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");




                LevelScreen[4] = " * * * Pick up your sword using the same command you used to pick up     * * * \n";
                LevelScreen[5] = " * * * your armour.                                                      * * * \n";

                Loop = true;

                while(Loop == true)
                {
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 1)
                    {
                        PickUp(CharacterInventory, CampItems, nCC);

                        if(CharacterInventory[0][2] == 1)
                        {
                            Level = 3;
                            Loop = false;
                        }
                        else
                        {
                            LevelScreen[6] = " * * * You must pick up your sword to continue!                        * * * \n";
                        }
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        LevelScreen[6] = " * * * This is not a valid command at the moment!                        * * * \n";
                    }
                }
            break;
            }
            case 3:
            {

                LevelScreen[0] = "===============================================================================\n";
                LevelScreen[1] = "=============================ARMY CAMP=========================================\n";
                LevelScreen[2] = "================================TENT===========================================\n";
                LevelScreen[3] = " * * * To leave your tent you need to move south, move commands don't    * * * \n";
                LevelScreen[4] = " * * * require you to specify that you're moving! Simply type the        * * * \n";
                LevelScreen[5] = " * * * compass direction in which you want to move! (For more            * * * \n";
                LevelScreen[6] = " * * * information on commands type info and select the command option)  * * * \n";
                LevelScreen[10]= " Commander: All right, now get out here soldier, we haven't got all day!       \n";
                LevelScreen[11]= "                                                                               \n";
                Loop = true;

                while (Loop == true)
                {
                    drawScreen(LevelScreen, 32);
                    command = Input();

                    if(command == 4)
                    {
                        Level = 4;
                        Loop = false;
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else if((command == 2) || (command == 3) || (command == 5))
                    {
                        LevelScreen[8] = " * * * You can only leave the tent to the south!                         * * * \n";
                    }
                    else
                    {
                        LevelScreen[8] = " * * * This is not a valid command at the moment!                        * * * \n";
                    }
                }
            break;
            }
            case 4:
            {

                LevelScreen[0]  = "===============================================================================\n";
                LevelScreen[1]  = "=============================ARMY CAMP=========================================\n";
                LevelScreen[2]  = "===========================TRAINING YARD=======================================\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = " You step outside the tent and into the training yard. Field extends far       \n";
                LevelScreen[5]  = " to the South, the army camp stretches out to the North and mountains surround \n";
                LevelScreen[6]  = " you to the east and dense forest to the west.                                 \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "  Commander: Alright soldier, before we get started, our records were lost in  \n";
                LevelScreen[8]  = "             the last retreat. So, what's your name?                           \n";
                LevelScreen[9]  = "                                                                               \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                CharacterInfo[0][0] = InputName();


                LevelScreen[4] = "                                                                               \n";
                LevelScreen[5] = "                                                                               \n";
                LevelScreen[6] = "                                                                               \n";
                LevelScreen[7] = "  Commander: Hard to see past the armour, are you male or female?              \n";
                LevelScreen[8] = "                                                                               \n";
                LevelScreen[9] = "                                                                               \n";

                drawScreen(LevelScreen, 32);

                CharacterInfo[0][1] = InputGender();

                LevelScreen[4] = "                                                                               \n";
                LevelScreen[7] = "  Commander: Alright, one last part of our records which of the 6 races do you \n";
                LevelScreen[8] = "             belong to?                                                        \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[4] = " * * * The 6 Races of the TextQuest universe are Human, Elf, Orc, Dwarf, * * * \n";
                LevelScreen[5] = " * * * Lupine and Ancient. For more information on races, type 'INFO'    * * * \n";
                LevelScreen[6] = " * * * to continue to choosing you race type 'SKIP'.                     * * * \n";

                Loop = true;

                while(Loop == true)
                {
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 13)
                    {
                        info();
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else if(command == 6)
                    {
                        Loop = false;
                    }
                    else
                    {
                        LevelScreen[7] = " * * * This is not a valid command at the moment!                        * * * \n";
                    }
                }

                CharacterInfo[0][2] = InputRace();

                ApplyRace(CharacterInfo, CharacterStats, 0);

                cout << "Name: " << CharacterInfo[0][0] << endl;
                cout << "Gender: " << CharacterInfo[0][1] << endl;
                cout << "Race: " << CharacterInfo[0][2] << endl;


                system("PAUSE");

                Level = 5;

            break;
            }
            case 5:
            {
                LevelScreen[0]  = "===============================================================================\n";
                LevelScreen[1]  = "=============================ARMY CAMP=========================================\n";
                LevelScreen[2]  = "===========================TRAINING YARD=======================================\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "  Commander: Alright then soldier. Time to practice your swordplay!            \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[5]  = " Commander: Use this training dummy here and show me what you can do!          \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, TrainingDummy, 1);
                if(BattleResult == 0)
                {
                    return;
                }
                else if(BattleResult == 1)
                {
                    alive = CheckAlive();
                    if(alive == false)
                    {
                        return;
                    }
                    Save();

                    Level = 6;
                }
            break;
            }
            case 6:
            {
                LevelScreen[0]  = "===============================================================================\n";
                LevelScreen[1]  = "=============================ARMY CAMP=========================================\n";
                LevelScreen[2]  = "===========================TRAINING YARD=======================================\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "  Commander: Well done private. With skills like that, as long as our enemy is \n";
                LevelScreen[6]  = "             made out of wood, and isn't capable of moving. You'll be fine.    \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[8].replace(2, CharacterInfo[0][0].length(), CharacterInfo[0][0]);


                LevelScreen[8]  = "            : Thank you sir!                                                   \n";

                LevelScreen[8].replace(2, 10, CharacterInfo[0][0]);

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[5]  = "  ...                                                                          \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[5]  = "  An arrow flies into the training dummy. A second whistles past your head and \n";
                LevelScreen[6]  = "  into the tent behind you.                                                    \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[5]  = "  Commander: ...black fletching! It's the Reidlos!                             \n";
                LevelScreen[6]  = "                                                                               \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[5]  = "  Commander: Troops! Get moving, follow me, into the trees!                    \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[3]  = " * * * The commander runs off to the West.                               * * * \n";

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    command = Input();

                    if(command == 5)
                    {
                        Level = 7;
                        Loop = false;
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        LevelScreen[4]  = " * * * You must follow the commander West!                               * * * \n";

                        system("PAUSE");
                    }
                }
            break;
            }
            case 7:
            {
                LevelScreen[0]  = "===============================================================================\n";
                LevelScreen[1]  = "=============================ARMY CAMP=========================================\n";
                LevelScreen[2]  = "==============================FOREST===========================================\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "  Inside the forest you meet with a group of allied rangers. Through the breaks\n";
                LevelScreen[6]  = "  in the tree line you can see the army of the Reidlos advancing towards the   \n";
                LevelScreen[7]  = "  tents. The rest of your unit follows you rapidly into the trees.             \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[5]  = "  Commander: Rangers! Fire on the enemy!                                       \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[3]  = "  A ranger walks up to the commander...                                        \n";
                LevelScreen[5]  = "                                                                               \n";


                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[5]  = "  Ranger: Are you mad?! They outnumber us and their weaponry is superior! If   \n";
                LevelScreen[6]  = "          we open fire then it'll give away our position! We would be better   \n";
                LevelScreen[7]  = "          off sneaking round the back of their army and following the mountains\n";
                LevelScreen[8]  = "          back to Oryldeburg where we can meet with the rest of the order!     \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");


                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[5]  = "  Commander: I am in command of this army! And I say fire! Just who do you     \n";
                LevelScreen[6]  = "             think you are?!                                                   \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[3]  = " * * * Please type the name of the ranger.                               * * * \n";

                drawScreen(LevelScreen, 32);

                CharacterStats[1][0] += 100;

                CharacterInfo[1][0] = InputName();

                NameLength = CharacterInfo[1][0].length();

                LevelScreen[3]  = "                                                                               \n";

                LevelScreen[5]  = "            : My name is             , and I don't care if you're in charge I'm\n";
                LevelScreen[6]  = "              not putting the lives of my men at risk unnecessarily!           \n";

                LevelScreen[5].replace(2, 10, CharacterInfo[1][0]);
                LevelScreen[5].replace(25 - (10-NameLength), 10, CharacterInfo[1][0]);

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[5]  = "  Commander: Well I'm not going to take orders from some lowly ranger elf or   \n";
                LevelScreen[6]  = "             whatever you are!                                                 \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[3]  = " * * * Please type in the race of the ranger.                            * * * \n";

                drawScreen(LevelScreen, 32);

                CharacterInfo[1][2] = InputRace();

                ApplyRace(CharacterInfo, CharacterStats, 1);

                LevelScreen[3]  = "                                                                               \n";

                if(CharacterInfo[1][2] == "Elf")
                {
                    LevelScreen[5] = "            : So what if I'm an elf?                                           \n";
                }
                else if(CharacterInfo[1][2] == "Human")
                {
                    LevelScreen[5] = "            : I'm a human. Just like you.                                      \n";
                }
                else if(CharacterInfo[1][2] == "Orc")
                {
                    LevelScreen[5] = "            : Elf?! How dare you?! I'm an Orc!                                 \n";
                }
                else if(CharacterInfo[1][2] == "Dwarf")
                {
                    LevelScreen[5] = "            : I'm not an elf you fool, I'm Dwarvish!                           \n";
                }
                else if(CharacterInfo[1][2] == "Lupine")
                {
                    LevelScreen[5] = "            : The Elves are a dying race. We Lupine will replace them.         \n";
                }
                else if(CharacterInfo[1][2] == "Ancient")
                {
                    LevelScreen[5] = "            : Don't compare me to those upstarts. We Ancients are far superior.\n";
                }

                LevelScreen[6] = "                                                                               \n";

                LevelScreen[5].replace(2, 10, CharacterInfo[1][0]);

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[5]  = "  Commander: Right that's it! Fight me! Come on, are you a man or a mouse?!    \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[3]  = " * * * Please type the gender of the ranger.                             * * * \n";

                drawScreen(LevelScreen, 32);

                CharacterInfo[1][1] = InputGender();

                LevelScreen[3] = "                                                                               \n";

                if(CharacterInfo[1][1] == "Male")
                {
                    LevelScreen[5] = "            : A man. But I'm not an idiot, if we fight it'll give away our     \n";
                    LevelScreen[6] = "              position and we'll all die. I only want to kill you.             \n";
                }
                else if(CharacterInfo[1][1] == "Female")
                {
                    LevelScreen[5] = "            : A woman. But I'm not an idiot, if we fight it'll give away our   \n";
                    LevelScreen[6] = "              position and we'll all die. I only want to kill you.             \n";
                }

                LevelScreen[5].replace(2, 10, CharacterInfo[1][0]);

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[5] = "            : Rangers, we're heading South then round the back of the Reidlos. \n";
                LevelScreen[6] = "              Any of you soldiers want to come with us, feel free.             \n";
                LevelScreen[8] = "  Commander: Anyone with honour and strength should follow me and hit the enemy\n";
                LevelScreen[9] = "             in the flank! Come on,           , you're with me.                \n";

                LevelScreen[5].replace(2, 10, CharacterInfo[1][0]);
                LevelScreen[9].replace(36, 10, CharacterInfo[0][0]);

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[3] = " The ranger leads his archers to the South, and the Commander prepares to head \n";
                LevelScreen[4] = " East. Where will you go?                                                      \n";

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    command = Input();

                    if(command == 3)
                    {
                        Level = 8;
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 9;
                        Loop = false;
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!";
                    }
                }
            break;
            }
            case 8:
            {
                LevelScreen[0]  = "===============================================================================\n";
                LevelScreen[1]  = "=============================ARMY CAMP=========================================\n";
                LevelScreen[2]  = "===============================================================================\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "  You charge with the commander towards the war machine that is the army of    \n";
                LevelScreen[6]  = "  Reidlos. Despite your valiant efforts, you are cut down and the commander    \n";
                LevelScreen[7]  = "  is taken prisoner.                                                           \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                            YOU ARE DEAD!                                      \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                return;

            break;
            }
            case 9:
            {
                LevelScreen[0]  = "===============================================================================\n";
                LevelScreen[1]  = "=============================ARMY CAMP=========================================\n";
                LevelScreen[2]  = "==============================FOREST===========================================\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "             leads you South, behind enemy lines. You look across out of the   \n";
                LevelScreen[5]  = "  trees and see the Reidlos swarming over the tents of the camp. Everyone left \n";
                LevelScreen[6]  = "  is surely dead.                                                              \n";
                LevelScreen[7]  = "             : The Reidlos won't stop here. They're going to head straight for \n";
                LevelScreen[8]  = "               Oryldeburg. We can't beat them back there through the mountains \n";
                LevelScreen[9]  = "               the only way we could get there faster is by sea.               \n";
                LevelScreen[11] = "             crouches down and draws a quick map of the area with a pointed    \n";
                LevelScreen[12] = "  stick.                                                                       \n";
                LevelScreen[14] = "             : The coast is right over those montains. We can try to climb over\n";
                LevelScreen[15] = "               them. However, it will be faster to try and find a cave that    \n";
                LevelScreen[16] = "               leads down to the coast, we can follow the beach until we reach \n";
                LevelScreen[17] = "               a port town, grab a ship and sail home in time to warn people   \n";
                LevelScreen[18] = "               and fingers crossed, have enough time to prepare for the        \n";
                LevelScreen[19] = "               invasion.                                                       \n";

                LevelScreen[4].replace(2, 10, CharacterInfo[1][0]);
                LevelScreen[7].replace(2, 10, CharacterInfo[1][0]);
                LevelScreen[11].replace(2, 10, CharacterInfo[1][0]);
                LevelScreen[14].replace(2, 10, CharacterInfo[1][0]);

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                EmptyScreen(LevelScreen);


                LevelScreen[0]  = "===============================================================================\n";
                LevelScreen[1]  = "=============================ARMY CAMP=========================================\n";
                LevelScreen[2]  = "==============================FOREST===========================================\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "            : Alright, sounds like a plan! I'll follow your lead.              \n";
                LevelScreen[6]  = "            : Rangers, move out!                                               \n";

                LevelScreen[4].replace(2, 10, CharacterInfo[0][0]);
                LevelScreen[6].replace(2, 10, CharacterInfo[1][0]);

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[0]  = "===============================================================================\n";
                LevelScreen[1]  = "=============================ARMY CAMP=========================================\n";
                LevelScreen[2]  = "===============================PLAINS==========================================\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "  A small group of Reidlosian cavalry turns around and sees you and the rangers\n";
                LevelScreen[5]  = "  and begin to charge.                                                         \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "  Ranger: Captain, you take the private and head for the caves. We'll hold off \n";
                LevelScreen[8]  = "          the cavalry! Now go!                                                 \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[0]  = "===============================================================================\n";
                LevelScreen[1]  = "=============================ARMY CAMP=========================================\n";
                LevelScreen[2]  = "===============================PLAINS==========================================\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "            : Alright, if that's what you want to do. I'll make sure you are   \n";
                LevelScreen[5]  = "              honoured.                                                        \n";
                LevelScreen[7]  = "  Ranger: Thank you captain.                                                   \n";
                LevelScreen[8]  = "                                                                               \n";

                LevelScreen[4].replace(2, 10, CharacterInfo[1][0]);

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                Level = 10;

            break;
            }
            case 10:
            {

                LevelScreen[0]  = "===============================================================================\n";
                LevelScreen[1]  = "==============================FOOTHILLS========================================\n";
                LevelScreen[2]  = "==============================CAVE MOUTH=======================================\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[12]  = "  You arrive at the mouth of a cave, overlooked by snow capped mountains. A    \n";
                LevelScreen[13]  = "  mysterious figure is sitting by an open fire.                                \n";


                LevelScreen[4]  = " * * * From now on, at the top of the page, you will see a character     * * * \n";
                LevelScreen[5]  = " * * * name. This is the active character. The active character will be  * * * \n";
                LevelScreen[6]  = " * * * character that uses commands, for example if using the pick up    * * * \n";
                LevelScreen[7]  = " * * * command, the item picked up will be added to the active           * * * \n";
                LevelScreen[8]  = " * * * character's inventory. If you want to change character use the    * * * \n";
                LevelScreen[9]  = " * * * switch command. If at any point you don't know what to do use     * * * \n";
                LevelScreen[10] = " * * * HELP or INFO to see if there are any commands you haven't tried!  * * * \n";

                AddCharacter(CharacterInfo, nCC, LevelScreen);
                drawScreen(LevelScreen, 32);

                system("PAUSE");

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "===============================================================================\n";
                LevelScreen[1]  = "==============================FOOTHILLS========================================\n";
                LevelScreen[2]  = "==============================CAVE MOUTH=======================================\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "  Mysterious Figure: If you're venturing into that cave, you're going to need  \n";
                LevelScreen[5]  = "                     a mage.                                                   \n";

                AddCharacter(CharacterInfo, nCC, LevelScreen);
                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[4]  = "            : I suppose it can't hurt to have an extra pair of hands. Tell us  \n";
                LevelScreen[5]  = "              about yourself.                                                  \n";

                LevelScreen[4].replace(2, 10, CharacterInfo[1][0]);
                AddCharacter(CharacterInfo, nCC, LevelScreen);
                drawScreen(LevelScreen, 32);

                LevelScreen[5] = "                                                                               \n";

                system("PAUSE");

                LevelScreen[4]  = " * * * Please enter the name of the mage.                                * * * \n";

                drawScreen(LevelScreen, 32);

                CharacterStats[2][0] += 100;
                CharacterStats[2][1] += 100;

                CharacterInfo[2][0] = InputName();

                LevelScreen[4]  = " * * * Please enter the gender of the mage                               * * * \n";

                CharacterInfo[2][1] = InputGender();

                LevelScreen[4]  = " * * * Please enter the race of the mage                                 * * * \n";

                CharacterInfo[2][2] = InputRace();

                ApplyRace(CharacterInfo, CharacterStats, 2);

                LevelScreen[4]  = "  And so the brave adventurers stepped into the cave...                        \n";

                CharacterStats[2][1] = CharacterStats[2][6];

                AddCharacter(CharacterInfo, nCC, LevelScreen);
                drawScreen(LevelScreen, 32);

                system("PAUSE");

                Level = 11;

                Save();

                EmptyScreen(LevelScreen);

            break;
            }
            case 11:
            {/*
                cout << "Warrior: " << endl;
                cout << "========" << endl;
                cout << "Name: " << CharacterInfo[0][0] << endl;
                cout << "Gender: " << CharacterInfo[0][1] << endl;
                cout << "Race: " << CharacterInfo[0][2] << endl;
                cout << "Strength: " << CharacterStats[0][2] << endl;
                cout << "Agility: " << CharacterStats[0][3] << endl;
                cout << "Intellgence: " << CharacterStats[0][4] << endl;
                cout << endl;


                cout << "Ranger: " << endl;
                cout << "=======" << endl;
                cout << "Name: " << CharacterInfo[1][0] << endl;
                cout << "Gender: " << CharacterInfo[1][1] << endl;
                cout << "Race: " << CharacterInfo[1][2] << endl;
                cout << "Strength: " << CharacterStats[1][2] << endl;
                cout << "Agility: " << CharacterStats[1][3] << endl;
                cout << "Intellgence: " << CharacterStats[1][4] << endl;
                cout << endl;

                cout << "Mage: " << endl;
                cout << "====="  << endl;
                cout << "Name: " << CharacterInfo[2][0] << endl;
                cout << "Gender: " << CharacterInfo[2][1] << endl;
                cout << "Race: " << CharacterInfo[2][2] << endl;
                cout << "Strength: " << CharacterStats[2][2] << endl;
                cout << "Agility: " << CharacterStats[2][3] << endl;
                cout << "Intellgence: " << CharacterStats[2][4] << endl;
                cout << endl;

            system("PAUSE");
            */
            Level = 12;
            break;
            }
            case 12:  //==============================FLOOR 0 ROOM 0=================================================================================
            {
                Floor0 = true;
                Floor = 0;
                Room = 0;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================MYSTERIOUS CAVE==========================W + E=====\n";
                LevelScreen[2]  = "=============================MAIN CORRIDOR=============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "                                                                               \n";
                LevelScreen[13] = "                                                                               \n";
                LevelScreen[14] = "                                                                               \n";
                LevelScreen[15] = "                                                                               \n";
                LevelScreen[16] = "                                                                               \n";
                LevelScreen[17] = "                                                                               \n";

                if(Room00 == 0)
                {
                    LevelScreen[15] = "  You enter the cave and walk down a dark corridor.                            \n";
                    LevelScreen[16] = " * * * To view your map and inventory use the VIEW MAP, and               * * *\n";
                    LevelScreen[17] = " * * * VIEW INVENTORY commands.                                           * * *\n";
                    Room00 ++;
                }
                else
                {
                    LevelScreen[11] = "  You return to the entrance of the cave.                                      \n";
                }

                LevelScreen[12] = "  The corridor continues to the south, there is also a side path going off     \n";
                LevelScreen[13] = "  to the east. You cannot see anything useful.                                 \n";

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 1)
                    {
                        cout << "There is nothing to pick up in this room!\n" << endl;

                        system("PAUSE");
                    }
                    else if(command == 3)
                    {
                        Level = 13;
                        cout << "You head east down the side corridor...\n" << endl;
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 14;
                        cout << "You head south down the main corridor...\n" << endl;
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                       ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);

                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 13:  //==============================FLOOR 0 ROOM 1=================================================================================
            {
                Floor = 0;
                Room = 1;

                EmptyScreen(LevelScreen);
                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================MYSTERIOUS CAVE==========================W + E=====\n";
                LevelScreen[2]  = "===============================SIDE ROOM===============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";

                GetMap(LevelScreen, PlayerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                LevelScreen[12] = "  You enter a dark room.                                                       \n";

                if(Goblin[0][0] != 0)
                {
                    LevelScreen[13] = "  You see a Goblin charge towards you!                                         \n";


                    drawScreen(LevelScreen, 32);

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, Goblin, 0);

                    if(BattleResult == 1)
                    {
                        LevelScreen[13] = "  You dump the goblin's body in a corner and examine the rest of the room.     \n";
                        LevelScreen[14] = "  The goblin's sword lies on the floor. The only exit is to the west.          \n";

                        Room01Items[2] = 1;

                        drawScreen(LevelScreen, 32);

                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                    else if(BattleResult == 0)
                    {
                        return;
                    }
                }
                else if(Goblin[0][0] == 0)
                {
                    LevelScreen[13] = "  There is very little in the room. It's dark and cold.                        \n";
                    LevelScreen[14] = "  The only exit is to the West.                                                \n";

                    drawScreen(LevelScreen, 32);

                }

                Loop = true;

                while(Loop == true)
                {

                    GetMap(LevelScreen, PlayerMap0, Floor, Room);
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 1)
                    {
                        PickUp(CharacterInventory, Room01Items, nCC);
                    }
                    else if(command == 5)
                    {
                        Level = 12;
                        cout << "You head West down the corridor...\n\n";

                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 14:  //==============================FLOOR 0 ROOM 2=================================================================================
            {
                Floor = 0;
                Room = 2;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================MYSTERIOUS CAVE==========================W + E=====\n";
                LevelScreen[2]  = "=============================MAIN CORRIDOR=============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";

                GetMap(LevelScreen, PlayerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                LevelScreen[12] = "  A small corridor leads to the West. The main corridor continues to the South \n";
                LevelScreen[13] = "  and the North.                                                               \n";

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);


                    command = Input();
                    if(command == 2)
                    {
                        Level = 12;
                        cout << "You head North up the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 16;
                        cout << "You head South down the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 15;
                        cout << "You head West down the side corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }



            break;
            }
            case 15:  //==============================FLOOR 0 ROOM 3=================================================================================
            {

                Floor = 0;
                Room = 3;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================MYSTERIOUS CAVE==========================W + E=====\n";
                LevelScreen[2]  = "===============================SIDE ROOM===============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";


                GetMap(LevelScreen, PlayerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);


                if(BowGoblin[0][0] != 0)
                {
                    LevelScreen[12] = " An arrow clatters to the floor as you step into the room. Another whizzes into\n";
                    LevelScreen[13] = " the wall. You see a Goblin's eyes staring at you from the darkness!           \n\n";

                    Room03Items[6] += 2;

                    drawScreen(LevelScreen, 32);

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, BowGoblin, 0);



                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else if(BattleResult == 1)
                    {
                        Roll = RollDice(14);

                        Room03Items[6] += Roll;

                        Roll = 0;

                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                        cout << "The Goblin drops some arrows!\n\n";
                        system("PAUSE");

                        LevelScreen[12] = " The Goblin's corpse lies on the floor.                                        \n";
                        LevelScreen[13] = "                                                                               \n";
                    }
                }
                else
                {
                    LevelScreen[12] = " The Goblin's corpse lies on the floor.                                        \n";
                    LevelScreen[13] = "                                                                               \n";
                }

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();


                    if(command == 1)
                    {
                        PickUp(CharacterInventory, Room03Items, nCC);
                    }
                    else if(command == 3)
                    {
                        Level = 14;
                        cout << "You head East down the side corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 16:  //==============================FLOOR 0 ROOM 4=================================================================================
            {
                Floor = 0;
                Room = 4;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================MYSTERIOUS CAVE==========================W + E=====\n";
                LevelScreen[2]  = "=============================MAIN CORRIDOR=============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";


                GetMap(LevelScreen, PlayerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                LevelScreen[12] = "  You see a corridor going off to the East. The Main Corridor continues North  \n";
                LevelScreen[13] = "  and South.                                                                   \n";

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 14;
                        cout << "You head North up the main corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 17;
                        cout << "You head East down the side corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 18;
                        cout << "You head South down the main corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }

            break;
            }
            case 17:  //==============================FLOOR 0 ROOM 5=================================================================================
            {
                Floor = 0;
                Room = 5;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================MYSTERIOUS CAVE==========================W + E=====\n";
                LevelScreen[2]  = "===============================SIDE ROOM===============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";


                GetMap(LevelScreen, PlayerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                LevelScreen[12] = "  You see a mysterious pattern on the wall. Beneath it there is an inscription.\n";

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 5)
                    {
                        Level = 16;
                        cout << "You head West down the side corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap0, Floor, Room);
                    }
                    else if(command == 9)
                    {

                        if(Puzzle0Solved == false)
                        {
                            PuzzleResult = Puzzle0(LevelScreen, CharacterInfo, CharacterStats);

                            if(PuzzleResult == 1)
                            {
                                Puzzle0Solved = true;
                                Level = 16;
                                Loop = false;
                            }
                        }
                        else
                        {
                            cout << "This puzzle has already been solved!";

                            system("PAUSE");
                        }
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 18:  //==============================FLOOR 0 ROOM 6=================================================================================
            {
                Floor = 0;
                Room = 6;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================MYSTERIOUS CAVE==========================W + E=====\n";
                LevelScreen[2]  = "=============================MAIN CORRIDOR=============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";


                GetMap(LevelScreen, PlayerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 16;
                        cout << "You head North up the main corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    if(command == 5)
                    {
                        Level = 19;
                        cout << "You head West down the side corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 20;
                        cout << "You head South down the main corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 19:  //==============================FLOOR 0 ROOM 7=================================================================================
            {

                Floor = 0;
                Room = 7;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================MYSTERIOUS CAVE==========================W + E=====\n";
                LevelScreen[2]  = "===============================SIDE ROOM===============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";


                GetMap(LevelScreen, PlayerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                LevelScreen[12] = " There is an inscription on the wall...                                        \n";

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 3)
                    {
                        Level = 18;
                        cout << "You head East down the side corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap0, Floor, Room);
                    }
                    else if(command == 9)
                    {
                        if(Riddle0Solved == false)
                        {
                            PuzzleResult = Riddle0(LevelScreen);

                            if(PuzzleResult == 1)
                            {
                                Keys[0] = 1;

                                LevelScreen[0]  = "=======================================================================N=======\n";
                                LevelScreen[1]  = "============================MYSTERIOUS CAVE==========================W + E=====\n";
                                LevelScreen[2]  = "===============================SIDE ROOM===============================S=======\n";
                                LevelScreen[3]  = "                                                                               \n";
                                LevelScreen[4]  = "                                                                               \n";
                                LevelScreen[5]  = "                                                                               \n";
                                LevelScreen[6]  = "                                                                               \n";
                                LevelScreen[7]  = "                                                                               \n";
                                LevelScreen[8]  = "                                                                               \n";
                                LevelScreen[9]  = "                                                                               \n";
                                LevelScreen[10] = "                                                                               \n";
                                LevelScreen[11] = "                                                                               \n";

                                GetMap(LevelScreen, PlayerMap0, Floor, Room);
                                AddCharacter(CharacterInfo, nCC, LevelScreen);

                                LevelScreen[12] = "  One of the bricks in the wall slides out and falls to the floor. Revealing a \n";
                                LevelScreen[13] = "  rusty old key. You pick up the key.                                          \n";

                                drawScreen(LevelScreen, 32);
                            }

                        }
                        else
                        {
                            cout << "You have already solved this riddle!\n\n";
                            system("PAUSE");
                        }
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 20:  //==============================FLOOR 0 ROOM 8=================================================================================
            {

                Floor = 0;
                Room = 8;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================MYSTERIOUS CAVE==========================W + E=====\n";
                LevelScreen[2]  = "=============================MAIN CORRIDOR=============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = " The corridor extends North and East.                                          \n";


                GetMap(LevelScreen, PlayerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);



                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 18;
                        cout << "You head North up the main corridor...\n\n";
                        system("PAUSE");

                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 21;
                        cout << "You head East down the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 21:  //==============================FLOOR 0 ROOM 9=================================================================================
            {
                Floor = 0;
                Room = 9;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================MYSTERIOUS CAVE==========================W + E=====\n";
                LevelScreen[2]  = "=============================MAIN CORRIDOR=============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";


                GetMap(LevelScreen, PlayerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 22;
                        cout << "You head North up the corridor...\n\n";
                        system("PAUSE");

                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 25;
                        cout << "You head South down the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 20;
                        cout << "You head West down the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 22:  //==============================FLOOR 0 ROOM 10================================================================================
            {
                Floor = 0;
                Room = 10;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================MYSTERIOUS CAVE==========================W + E=====\n";
                LevelScreen[2]  = "=============================TROLL'S CAVERN============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";



                GetMap(LevelScreen, PlayerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                if(CaveTroll[0][0] != 0)
                {
                    LevelScreen[13] = "  A troll lumbers past. It doesn't seem to have spotted your group. Would you  \n";
                    LevelScreen[14] = "  like to charge straight for it. Or try to sneak past?                        \n";

                    Loop = true;
                    while(Loop == true)
                    {
                        AddCharacter(CharacterInfo, nCC, LevelScreen);
                        drawScreen(LevelScreen, 32);

                        command = Input();

                        if(command == 7 || command == 19)
                        {
                            ForceFight = true;
                            Loop = false;
                        }
                        else if(command == 4)
                        {
                            Level = 21;
                            cout << "You head South...\n\n";
                            system("PAUSE");
                            ForceFight = false;
                            Loop = false;
                        }
                        else if(command == 11)
                        {
                            UsePotion();
                        }
                        else if(command == 16)
                        {
                            Switch();
                        }
                        else if(command == 18)
                        {
                            sneak = Sneak(CharacterStats, CharacterInventory, CaveTroll, nCC);

                            if(sneak == 0)
                            {
                                cout << "The troll spots you!\n\n";
                                ForceFight = true;
                                Loop = false;
                                system("PAUSE");
                            }
                            else if(sneak == 1)
                            {
                                cout << "You successfully sneak past the troll!\n\n";
                                ForceFight = false;
                                Loop = false;
                                system("PAUSE");
                            }
                        }
                        else if(command == 23)
                        {
                            ViewStats(CharacterStats, CharacterInfo);
                        }
                        else
                        {
                            cout << "This is not a valid command! \n\n";
                            system("PAUSE");

                        }
                    }
                    if(ForceFight == true)
                    {
                        BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, CaveTroll, 0);
                        if(BattleResult == 0)
                        {
                            return;
                        }
                        else
                        {
                            Loop = true;

                            alive = CheckAlive();
                            if(alive == false)
                            {
                                return;
                            }
                            Save();

                            LevelScreen[13] = "  The troll lies defeated!                                                     \n";
                            LevelScreen[14] = "  Would you like to leave to the North, East or South?                         \n";
                        }
                    }
                    else if(ForceFight == false && Level != 21)
                    {

                        cout << "Leave to the North, East, or South? ";

                        Loop = true;

                        while(Loop == true)
                        {
                            command = Input();

                            if(command == 2)
                            {
                                Level = 23;
                                Loop = false;
                            }
                            else if(command == 3)
                            {
                                Level = 24;
                                Loop = false;
                            }
                            else if(command == 4)
                            {
                                Level = 21;
                                Loop = false;
                            }
                            else
                            {
                                cout << "This is not a valid command at the moment!\n\n";
                                system("PAUSE");
                            }
                        }
                        break;
                    }

                }
                else
                {
                    LevelScreen[13] = "  The troll's corpse fills a surprisingly large amount of the room. It smells  \n";
                    LevelScreen[14] = "  of old lard, and a little bit of cheese.                                     \n";
                }



                drawScreen(LevelScreen, 32);

                Loop = true;

                if(Level == 21)
                {
                    Loop = false;
                }

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 23;
                        cout << "You head North up the corridor...\n\n";
                        system("PAUSE");

                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 24;
                        cout << "You head East along the corridor...\n\n";
                        system("PAUSE");

                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 21;
                        cout << "You head South down the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 23:  //==============================FLOOR 0 ROOM 11================================================================================
            {
                Floor = 0;
                Room = 11;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================MYSTERIOUS CAVE==========================W + E=====\n";
                LevelScreen[2]  = "===============================DEAD END================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";


                GetMap(LevelScreen, PlayerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 4)
                    {
                        Level = 22;
                        cout << "You head South down the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }

            break;
            }
            case 24:  //==============================FLOOR 0 ROOM 12================================================================================
            {
                Floor = 0;
                Room = 12;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================MYSTERIOUS CAVE==========================W + E=====\n";
                LevelScreen[2]  = "=================================TRAP==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";

                if(trapA == true)
                {
                    trapA = TrapA(nCC, CharacterStats);


                    LevelScreen[12] = "  Rubble begins to fall from the ceiling...                                   \n";

                    drawScreen(LevelScreen, 32);
                    system("PAUSE");

                    LevelScreen[12] = "  Suddenly the rubble gives way to huge boulders!                              \n";

                    drawScreen(LevelScreen, 32);
                    system("PAUSE");

                    if(trapA == true)
                    {
                        LevelScreen[12] = "             is trapped beneath them, and lost forever!                        \n";

                        LevelScreen[12].replace(2, 10, CharacterInfo[nCC][0]);

                        CharacterStats[nCC][0] = 0;

                        Save();
                    }
                    else if(trapA == false)
                    {
                        LevelScreen[12] = "             struggles out of the rubble and manages to escape without being   \n";
                        LevelScreen[13] = "  trapped!                                                                     \n";

                        LevelScreen[12].replace(2, 10, CharacterInfo[nCC][0]);
                    }

                    alive = CheckAlive();
                    if(alive == false)
                    {
                        return;
                    }
                    Save();

                    drawScreen(LevelScreen, 32);

                }
                else
                {
                    LevelScreen[12] = "  You search through the rocks, but you find nothing.                          \n";
                }


                GetMap(LevelScreen, PlayerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                LevelScreen[14] = "  The only exit is to the West.                                                \n";

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 5)
                    {
                        Level = 22;
                        cout << "You head West down the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 25:  //==============================FLOOR 0 ROOM 13================================================================================
            {

                Floor = 0;
                Room = 13;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================MYSTERIOUS CAVE==========================W + E=====\n";
                LevelScreen[2]  = "================================STAIRS=================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = " The corridor continues to the North, you see stairs leading to the South.     \n";

                GetMap(LevelScreen, PlayerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 21;
                        cout << "You head North up the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    if(command == 4)
                    {
                       Level = 26;
                       cout << "You head South down the stairs...\n\n";
                       system("PAUSE");
                       Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 26:  //==============================FLOOR 1 ROOM 0=================================================================================
            {
                Floor = 1;
                Room = 0;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==========================OLD BURIED BARRACKS========================W + E=====\n";
                LevelScreen[2]  = "================================STAIRS=================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The stairs lead to the North, and the corridor leads to the South.           \n";

                GetMap(LevelScreen, PlayerMap1, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap1, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 25;
                        cout << "You head North up the stairs...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 27;
                        cout << "You head South down the stairs...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap1, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 27:  //==============================FLOOR 1 ROOM 1=================================================================================
            {
                Floor = 1;
                Room = 1;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==========================OLD BURIED BARRACKS========================W + E=====\n";
                LevelScreen[2]  = "===============================CORRIDOR================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  A small corridor heads off to the West, there is also a path to the North    \n";
                LevelScreen[13] = "  and the South.                                                               \n";

                GetMap(LevelScreen, PlayerMap1, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap1, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 26;
                        cout << "You head North up the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 29;
                        cout << "You head South down the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 28;
                        cout << "You head West down the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap1, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 28:  //==============================FLOOR 1 ROOM 2=================================================================================
            {
                Floor = 1;
                Room = 2;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==========================OLD BURIED BARRACKS========================W + E=====\n";
                LevelScreen[2]  = "===============================MESS HALL===============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  You enter a large room. Corridors lead out of the room to the North, East and\n";
                LevelScreen[13] = "  West.                                                                        \n";


                GetMap(LevelScreen, PlayerMap1, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                if(BarrackGoblins[0][0] != 0)
                {
                    LevelScreen[14] = "  You hear the screeching of goblins! Two jump out of the darkness and attack! \n";

                    drawScreen(LevelScreen, 32);

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, BarrackGoblins, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        LevelScreen[14] = "  The goblins lie dead.                                                        \n";

                        Roll = RollDice(14);

                        Room12Items[6] += Roll;

                        Roll = 0;

                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();

                    }
                }
                else
                {
                    LevelScreen[14] = "  The goblins lie dead.                                                        \n";
                }

                AddCharacter(CharacterInfo, nCC, LevelScreen);
                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap1, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 30;
                        cout << "You head North out of the room...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 27;
                        cout << "You head East out of the room...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 31;
                        cout << "You head West out of the room...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap1, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }

            break;
            }
            case 29:  //==============================FLOOR 1 ROOM 3=================================================================================
            {
                Floor = 1;
                Room = 3;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==========================OLD BURIED BARRACKS========================W + E=====\n";
                LevelScreen[2]  = "=================================TRAP==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only way out is to the North.                                            \n";

                if(trapB == true)
                {
                    trapB = TrapB(nCC, CharacterInventory);

                    LevelScreen[12] = "  Suddenly, the wall behind you begins too fall! You begin to run for it but   \n";
                    LevelScreen[13] = "  you can tell it will close before you are out.                               \n";

                    drawScreen(LevelScreen, 32);

                    system("PAUSE");

                    if(trapB == true)
                    {
                        LevelScreen[12] = "  You are trapped permanently.                                                 \n";
                        LevelScreen[13] = "                                                                               \n";

                        CharacterStats[nCC][0] = 0;

                    }
                    else if(trapB == false)
                    {
                        LevelScreen[12] = "  You jam the gap between the falling wall and the floor with an item from     \n";
                        LevelScreen[13] = "  your inventory. You manage to slip out, but your item is severely damaged!   \n";
                        LevelScreen[14] = "  The only exit is to the North.                                               \n";
                    }

                    alive = CheckAlive();
                    if(alive == false)
                    {
                        return;
                    }
                    Save();

                    drawScreen(LevelScreen, 32);
                }



                GetMap(LevelScreen, PlayerMap1, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap1, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 27;
                        cout << "You head North up the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap1, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 30:  //==============================FLOOR 1 ROOM 4=================================================================================
            {
                Floor = 1;
                Room = 4;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==========================OLD BURIED BARRACKS========================W + E=====\n";
                LevelScreen[2]  = "===========================SLEEPING QUARTERS===========================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The room has clearly been abandoned for a long time. Skeletons lie in old    \n";
                LevelScreen[13] = "  worn beds.                                                                   \n";
                LevelScreen[14] = "  The only exit is to the South.                                               \n";

                GetMap(LevelScreen, PlayerMap1, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                if(SleepingQSkeleton[0][0] != 0)
                {
                    LevelScreen[14] = "  One of the skeletons begins to stir...                                       \n";

                    drawScreen(LevelScreen, 32);

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, SleepingQSkeleton, 0);
                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        LevelScreen[14] = "                                                                               \n";

                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                }

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap1, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 4)
                    {
                        Level = 28;
                        cout << "You South back into the Mess Hall...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap1, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }

            break;
            }
            case 31:  //==============================FLOOR 1 ROOM 5=================================================================================
            {
                Floor = 1;
                Room = 5;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==========================OLD BURIED BARRACKS========================W + E=====\n";
                LevelScreen[2]  = "===============================CORRIDOR================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The corridor stretches out North, East and South.                            \n";

                GetMap(LevelScreen, PlayerMap1, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap1, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command  == 2)
                    {
                        Level = 33;
                        cout << "You head North up the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 28;
                        cout << "You head East along the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 32;
                        cout << "You head South down the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap1, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 32:  //==============================FLOOR 1 ROOM 6=================================================================================
            {
                Floor = 1;
                Room = 6;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==========================OLD BURIED BARRACKS========================W + E=====\n";
                LevelScreen[2]  = "===============================ARMOURY=================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  You enter an old armoury filled with rusty weapons and decaying wooden       \n";
                LevelScreen[13] = "  training dummies.                                                            \n";
                LevelScreen[14] = "  The only exit is to the North.                                               \n";

                GetMap(LevelScreen, PlayerMap1, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                if(ArmourySkeleton[0][0] != 0)
                {
                    LevelScreen[14] = "  A skeleton jumps out from behind a Training Dummy and attacks!               \n";

                    drawScreen(LevelScreen, 32);

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, ArmourySkeleton, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();

                        LevelScreen[14] = "  The only exit is to the North.                                               \n";
                    }
                }

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap1, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command  == 2)
                    {
                        Level = 31;
                        cout << "You head North up the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap1, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 33:  //==============================FLOOR 1 ROOM 7=================================================================================
            {
                Floor = 1;
                Room = 7;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==========================OLD BURIED BARRACKS========================W + E=====\n";
                LevelScreen[2]  = "===============================STAIRS==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The stairs lead to the North, the corridor leads to the South.               \n";

                GetMap(LevelScreen, PlayerMap1, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap1, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 34;
                        cout << "You head down the stairs to the North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 31;
                        cout << "You head South down the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap1, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }

            break;
            }
            case 34:  //==============================FLOOR 2 ROOM 0=================================================================================
            {
                Floor = 2;
                Room = 0;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================KING'S RETREAT============================W + E=====\n";
                LevelScreen[2]  = "===============================STAIRS==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The stairs lead to the North, the corridor leads to the South.               \n";

                GetMap(LevelScreen, PlayerMap2, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap2, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 33;
                        cout << "You head up the stairs to the North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 35;
                        cout << "You head South down the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap2, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 35:  //==============================FLOOR 2 ROOM 1=================================================================================
            {
                Floor = 2;
                Room = 1;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================KING'S RETREAT============================W + E=====\n";
                LevelScreen[2]  = "=============================CORRIDOR==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The stairs lead to the North, the corridor leads to the South. There is a    \n";
                LevelScreen[13] = "  small passageway to the East.                                                \n";

                GetMap(LevelScreen, PlayerMap2, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap2, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 34;
                        cout << "You head North up the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 38;
                        cout << "You head East down the passageway...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 36;
                        cout << "You head South down the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap2, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 36:  //==============================FLOOR 2 ROOM 2/3===============================================================================
            {
                Floor = 2;
                if(Keys[1] == 0)
                {
                    Room = 2;
                }
                else if(Keys[1] != 0)
                {
                    Room = 3;
                }
                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================KING'S RETREAT============================W + E=====\n";
                LevelScreen[2]  = "==========================THRONE ROOM DOOR=============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The corridor leads North.                                                    \n";

                if(Keys[1] != 0)
                {
                    LevelScreen[12].replace(28, 49, "The doors open onto the throne room to the South.");
                }

                if(GuardSkeletons[0][0] != 0)
                {
                    LevelScreen[13] = "  Two skeletons stand guard by the door.                                       \n";

                    drawScreen(LevelScreen, 32);
                }
                else if(GuardSkeletons[0][0] == 0)
                {
                    LevelScreen[13] = "  The skeletons lie crumpled on the floor!                                     \n";

                    drawScreen(LevelScreen, 32);

                }

                GetMap(LevelScreen, PlayerMap2, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap2, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 35;
                        cout << "You head North up the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        if(Keys[1] != 0)
                        {
                            Level = 37;
                            cout << "You head South down the corridor...\n\n";
                            system("PAUSE");
                            Loop = false;
                        }
                        else
                        {
                            cout << "You cannot go this way, the door is locked!\n\n";
                            system("PAUSE");
                        }
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap2, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 20)
                    {
                        if(GuardSkeletons[0][0] != 0)
                        {
                            cout << "You challenge the Skeletons to a fight!\n\n";

                            system("PAUSE");
                            BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GuardSkeletons, 0);

                            if(BattleResult == 0)
                            {
                                return;
                            }
                            else
                            {
                                LevelScreen[13] = "  The skeletons lie crumpled on the floor!                                     \n";

                                alive = CheckAlive();
                                if(alive == false)
                                {
                                    return;
                                }
                                Save();

                                drawScreen(LevelScreen, 32);
                            }
                        }
                        else
                        {
                            cout << "This is not a valid command!\n\n";
                            system("PAUSE");
                        }
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 37:  //==============================FLOOR 2 ROOM 4=================================================================================
            {
                Floor = 2;
                Room = 4;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================KING'S RETREAT============================W + E=====\n";
                LevelScreen[2]  = "============================THRONE ROOM================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "                                                                               \n";
                LevelScreen[13] = "  The only exit is to the North.                                               \n";

                GetMap(LevelScreen, PlayerMap2, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    if(Throne == 1)
                    {
                        LevelScreen[13].replace(34, 37, "The secret passage leads to the East.");
                    }

                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap2, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 35;
                        cout << "You head North up the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        if(Throne != 1)
                        {
                            cout << "This is not a valid command!\n\n";
                            system("PAUSE");
                        }
                        else if(Throne == 1)
                        {
                            Level = 39;
                            cout << "You head East down the secret passage...\n\n";
                            system("PAUSE");
                            Loop = false;
                        }
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap2, Floor, Room);
                    }
                    else if(command == 9)
                    {
                            if(Throne == 0)
                            {
                                Throne = InvestigateThroneRoom();
                            }
                            else if(Throne == -1)
                            {
                                CharacterStats[nCC][0] = 0;
                                CharacterStats[nCC][5] = 0;

                                alive = CheckAlive();
                                if(alive == false)
                                {
                                    return;
                                }
                                Save();
                            }
                            else if(Throne == 1)
                            {
                                cout << "There is no more investigating to be done!\n\n";
                                system("PAUSE");

                            }


                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 38:  //==============================FLOOR 2 ROOM 5=================================================================================
            {
                Floor = 2;
                Room = 5;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================KING'S RETREAT============================W + E=====\n";
                LevelScreen[2]  = "============================KING'S STUDY===============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "                                                                               \n";
                LevelScreen[13] = "                                                                               \n";
                LevelScreen[14] = "  In the room you see book cases and tables covered in old scrolls.            \n";
                LevelScreen[15] = "  The only exit is to the West.                                                \n";

                if(Keys[1] == 0)
                {
                    LevelScreen[16] = "  You see something shining on the top shelf.                                  \n";
                }
                else if(Keys[1] != 0)
                {
                    LevelScreen[16] = "                                                                               \n";
                }
                GetMap(LevelScreen, PlayerMap2, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap2, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 5)
                    {
                        Level = 35;
                        cout << "You head West along the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap2, Floor, Room);
                    }
                    else if(command == 9)
                    {
                        if(Keys[1] == 0)
                        {
                            cout << "You cannot get high enough to examine the shiny thing.\n";
                            cout << "The table in the centre of the room looks light enough to move.\n\n";
                        }
                        else
                        {
                            cout << "You see nothing unusual about the room.\n\n";
                        }
                        system("PAUSE");

                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 21)
                    {
                        if(Keys[1] == 0)
                        {
                            world = MoveTable();

                            if(world == -2)
                            {
                                CharacterStats[nCC][5] -= 30;
                            }
                            else if(world == -1)
                            {
                                alive = CheckAlive();
                                if(alive == false)
                                {
                                    return;
                                }
                                Save();
                            }
                            else if(world == 1)
                            {
                                cout << "The shiny object turns out to be a key!\n";
                                cout << "You add the shiny key to your inventory.\n\n";
                                Keys[1] ++;

                                LevelScreen[16] = "                                                                               \n";

                                system("PAUSE");
                            }


                        }
                        else
                        {
                            cout << "You cannot do this right now!\n\n";
                            system("PAUSE");
                        }
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 39:  //==============================FLOOR 2 ROOM 6=================================================================================
            {
                Floor = 2;
                Room = 6;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================KING'S RETREAT============================W + E=====\n";
                LevelScreen[2]  = "===========================SECRET PASSAGE==============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The secret passage continues North and South.                                \n";

                GetMap(LevelScreen, PlayerMap2, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap2, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 40;
                        cout << "You head North up the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 41;
                        cout << "You head South down the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap2, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 40:  //==============================FLOOR 2 ROOM 7=================================================================================
            {
                Floor = 2;
                Room = 7;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================KING'S RETREAT============================W + E=====\n";
                LevelScreen[2]  = "=========================SECRET PASSAGE - TRAP=========================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only exit is to the South.                                               \n";

                GetMap(LevelScreen, PlayerMap2, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(trapC == true)
                {
                    cout << endl << endl;
                    cout << "You feel the floor give slightly beneath your weight. You look down to see   \n";
                    cout << "the rock floor descend into quicksand!" << endl << endl;

                    system("PAUSE");
                    trapC = TrapC(nCC, CharacterStats);

                    if(trapC == true)
                    {
                        cout << endl << endl;
                        cout << "You struggle against the pull of the quicksand but your efforts only serve \n";
                        cout << "to drag you down further!" << endl << endl;
                        cout << "You are dead!" << endl << endl;

                        system("PAUSE");

                        CharacterStats[nCC][0] = 0;
                        CharacterStats[nCC][5] = 0;

                        if(CharacterStats[0][0] == 0 && CharacterStats[1][0] == 0 && CharacterStats[2][0])
                        {
                            return;
                        }
                        else
                        {
                            Switch();
                        }



                    }
                    else
                    {
                        cout << "Your lightning reflexes kick in! You quickly jump off the floor stone before\n";
                        cout << "your foot becomes trapped in the quicksand!" << endl << endl;

                        system("PAUSE");
                    }

                    alive = CheckAlive();
                    if(alive == false)
                    {
                        return;
                    }
                    Save();


                    trapC = false;
                }
                else
                {
                    LevelScreen[13] = "  All that remains is a pit of sand and a few stone tiles by the walls.        \n";
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap2, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 4)
                    {
                        Level = 39;
                        cout << "You head South down the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap2, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 41:  //==============================FLOOR 2 ROOM 8=================================================================================
            {

                Floor = 2;
                Room = 8;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================KING'S RETREAT============================W + E=====\n";
                LevelScreen[2]  = "===============================STAIRS==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The corridor leads North, the stairs lead to the South.                      \n";

                GetMap(LevelScreen, PlayerMap2, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap2, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 39;
                        cout << "You head North up the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 42;
                        cout << "You head South down the stairs...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap2, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 42:  //==============================FLOOR 3 ROOM 0=================================================================================
            {
                Floor = 3;
                Room = 0;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "===============================STAIRS==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The stairs lead to the North, and a corridor extends to the south.           \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 41;
                        cout << "You head North up the stairs...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 43;
                        cout << "You head South down the stairs...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }

            break;
            }
            case 43:  //==============================FLOOR 3 ROOM 1=================================================================================
            {
                Floor = 3;
                Room = 1;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "==============================ENTRANCE=================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The library continues South and West. A corridor leads to the North.         \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 42;
                        cout << "You head North up the corridor...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 45;
                        cout << "You head South through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 44;
                        cout << "You head West through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }

            break;
            }
            case 44:  //==============================FLOOR 3 ROOM 2=================================================================================
            {
                Floor = 3;
                Room = 2;

                CheckLibraryTime();

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "==============================SHELVES==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The library continues East, South and West.                                  \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 3)
                    {
                        Level = 43;
                        cout << "You head East through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 57;
                        cout << "You head South through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 48;
                        cout << "You head West through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 45:  //==============================FLOOR 3 ROOM 3=================================================================================
            {
                Floor = 3;
                Room = 3;

                CheckLibraryTime();

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "==============================SHELVES==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The library continues North, South and West.                                 \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 43;
                        cout << "You head North through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 46;
                        cout << "You head South through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 57;
                        cout << "You head West through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 46:  //==============================FLOOR 3 ROOM 4=================================================================================
            {
                Floor = 3;
                Room = 4;

                CheckLibraryTime();

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "==============================SHELVES==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The library continues North and West.                                        \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 45;
                        cout << "You head North through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 47;
                        cout << "You head West through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 47:  //==============================FLOOR 3 ROOM 5=================================================================================
            {
                Floor = 3;
                Room = 5;

                CheckLibraryTime();

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "==============================SHELVES==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The library continues East, North and West.                                  \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 57;
                        cout << "You head North through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 46;
                        cout << "You head East through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 50;
                        cout << "You head West through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 48:  //==============================FLOOR 3 ROOM 6=================================================================================
            {

                Floor = 3;
                Room = 6;

                CheckLibraryTime();

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "==============================SHELVES==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The library continues East, South and West.                                  \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 3)
                    {
                        Level = 44;
                        cout << "You head East through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 49;
                        cout << "You head South through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 52;
                        cout << "You head West through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 49:  //==============================FLOOR 3 ROOM 7=================================================================================
            {
                Floor = 3;
                Room = 7;

                CheckLibraryTime();

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "==============================SHELVES==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The library continues North, East, South and West.                           \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);


                if(LibraryGoblin[0][0] != 0)
                {
                    cout << "You feel something wet drop onto your head.\nYou look up to see a Goblin fall towards you and attack!\n\n";

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, LibraryGoblin, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 48;
                        cout << "You head North through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 57;
                        cout << "You head East through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 50;
                        cout << "You head South through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 58;
                        cout << "You head West through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 50:  //==============================FLOOR 3 ROOM 8=================================================================================
            {
                Floor = 3;
                Room = 8;

                CheckLibraryTime();

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "==============================SHELVES==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The library continues North, East and West.                                  \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 49;
                        cout << "You head North through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 47;
                        cout << "You head East through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 51;
                        cout << "You head West through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 51:  //==============================FLOOR 3 ROOM 9=================================================================================
            {
                Floor = 3;
                Room = 9;

                CheckLibraryTime();

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "==============================SHELVES==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The library continues North, East and West.                                  \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(LibrarySkeleton[0][0] != 0)
                {
                    cout << "You see a pile of books begin to shift.\nA skeleton suddenly bursts from the old tomes and charges!\n\n";

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, LibrarySkeleton, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 2)
                    {
                        Level = 58;
                        cout << "You head North through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 50;
                        cout << "You head East through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 55;
                        cout << "You head West through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 52:  //==============================FLOOR 3 ROOM 10================================================================================
            {
                Floor = 3;
                Room = 10;

                CheckLibraryTime();

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "==============================SHELVES==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The library continues East, South and West.                                  \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(LibraryGoblins[0][0] != 0)
                {
                    cout << "You see a group of goblins trying to eat the ancient scripts.\nEnraged by this crime against the written word, you attack!\n\n";

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, LibraryGoblins, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 3)
                    {
                        Level = 48;
                        cout << "You head East through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 58;
                        cout << "You head South through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 53;
                        cout << "You head West through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 53:  //==============================FLOOR 3 ROOM 11================================================================================
            {
                Floor = 3;
                Room = 11;

                CheckLibraryTime();

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "==============================SHELVES==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The library continues East and South.                                        \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 56;
                        cout << "You head North through the secret passage...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 52;
                        cout << "You head East through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 54;
                        cout << "You head South through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 54:  //==============================FLOOR 3 ROOM 12================================================================================
            {
                Floor = 3;
                Room = 12;

                CheckLibraryTime();

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "==============================SHELVES==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The library continues North, East and South.                                 \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 53;
                        cout << "You head North through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 58;
                        cout << "You head East through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 55;
                        cout << "You head South through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 55:  //==============================FLOOR 3 ROOM 13================================================================================
            {
                Floor = 3;
                Room = 13;

                CheckLibraryTime();

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "===========================SHELVES/STAIRS==============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The library continues North and East. Stairs lead to the South.              \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 54;
                        cout << "You head North through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 51;
                        cout << "You head East through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 59;
                        cout << "You head South down the stairs...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 56:  //==============================FLOOR 3 ROOM 14================================================================================
            {
                Floor = 3;
                Room = 14;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "===========================SECRET PASSAGE==============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  Stairs lead to the North, the door at the end with a black keyhole. The      \n";
                LevelScreen[13] = "  secret passage continues to the South.                                       \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        if(Keys[2] != 0)
                        {
                            Level = 129;
                            cout << "You head North up the stairs...\n\n";
                            system("PAUSE");
                            Loop = false;
                        }
                        else
                        {
                            cout << "You cannot open the door, it is locked!\n\n";
                            system("PAUSE");
                        }
                    }
                    else if(command == 4)
                    {
                        Level = 53;
                        cout << "You head South down the secret passage...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 57:  //==============================FLOOR 3 ROOM 15================================================================================
            {
                Floor = 3;
                Room = 15;

                CheckLibraryTime();

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "==============================SHELVES==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The library continues North, East, South and West.                           \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 44;
                        cout << "You head North through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 45;
                        cout << "You head East through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 47;
                        cout << "You head South through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 49;
                        cout << "You head West through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 58:  //==============================FLOOR 3 ROOM 16================================================================================
            {
                Floor = 3;
                Room = 16;

                CheckLibraryTime();

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================LIBRARY================================W + E=====\n";
                LevelScreen[2]  = "==============================SHELVES==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The library continues North, East, South and West.                           \n";

                GetMap(LevelScreen, PlayerMap3, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap3, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 52;
                        cout << "You head North through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 49;
                        cout << "You head East through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 51;
                        cout << "You head South through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 54;
                        cout << "You head West through the library...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap3, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 59:  //==============================FLOOR 4 ROOM 0=================================================================================
            {
                Floor = 4;
                Room = 0;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "==============================STAIRS===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The stairs lead North, to the South extends a labyrinthian series of         \n";
                LevelScreen[13] = "  passageways.                                                                 \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 55;
                        cout << "You head North up the stairs...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 60;
                        cout << "You head South through the maze...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 60:  //==============================FLOOR 4 ROOM 1=================================================================================
            {
                Floor = 4;
                Room = 1;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The Great Maze stretches to the North, East and West.                        \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(GMTFHellHound[0][0] != 0)
                {
                    cout << "You see a Hell Hound's red eyes stare at you. Blood drips from its fangs\nthen it leaps at you!\n\n";

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GMTFHellHound, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }

                }


                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 59;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 61;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 65;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 61:  //==============================FLOOR 4 ROOM 2=================================================================================
            {
                Floor = 4;
                Room = 2;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  You reach a crossroads, the maze continues East, South and West.             \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 3)
                    {
                        Level = 62;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 75;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 60;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 62:  //==============================FLOOR 4 ROOM 3=================================================================================
            {
                Floor = 4;
                Room = 3;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  You reach a corner in the maze. Paths lead to the North and the West.        \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 63;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 61;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 63:  //==============================FLOOR 4 ROOM 4=================================================================================
            {
                Floor = 4;
                Room = 4;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  You reach a corner in the maze. Paths lead to the East and the South.        \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 3)
                    {
                        Level = 64;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 62;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 64:  //==============================FLOOR 4 ROOM 5=================================================================================
            {
                Floor = 4;
                Room = 5;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "============================DARK ROOM==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  You reach a darkened room, the only exit is to the West.                     \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(GMTFSkeletonA[0][0] != 0)
                {
                    cout << "The door slams shut behind you, three skeletons emerge from the darkness...\n\n";

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GMTFSkeletonA, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 5)
                    {
                        Level = 63;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 65:  //==============================FLOOR 4 ROOM 6=================================================================================
            {
                Floor = 4;
                Room = 6;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  You reach a crossroads. Paths lead North, East, South and West.              \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(GMTFSkeletonB[0][0] != 0)
                {
                    cout << "As you step onto the crossroads, 3 skeletons walk out of the darkness towards \nyou...\n\n";

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GMTFSkeletonB, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 66;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 60;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 67;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 68;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 66:  //==============================FLOOR 4 ROOM 7=================================================================================
            {
                Floor = 4;
                Room = 7;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "=============================DEAD END==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only exit is to the South.                                               \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 4)
                    {
                        Level = 65;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 67:  //==============================FLOOR 4 ROOM 8=================================================================================
            {
                Floor = 4;
                Room = 8;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "==============================CORRIDOR=================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The path widens, torches hang from the walls either side. The corridor       \n";
                LevelScreen[12] = "  continues to the East and a passageway leads to the North.                   \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 65;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 69;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 68:  //==============================FLOOR 4 ROOM 9=================================================================================
            {
                Floor = 4;
                Room = 9;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "===============================TRAP====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only exit is to the East.                                                \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(trapD == true)
                {
                    cout << "As you enter the room you see a cluster of mushrooms on the floor. Your        \n";
                    cout << "journey has been tiring so you decide to risk taking a bite...\n\n";

                    trapD = TrapD(nCC, CharacterStats);

                    cout << "The mushrooms are surprisingly tasty. You take a moment to savour the taste.\n";
                    cout << "Suddenly your stomach feels a jolt of pain!...\n\n";

                    system("PAUSE");

                    cout << "The wall slides open and a Giant Mushroom appears! It swallows you up!...\n\n";
                    if(trapD == true)
                    {
                        cout << "The Mushroom begins to digest you as the wall closes up again.\nYou will eventually die.\n\n";
                        CharacterStats[nCC][0] = 0;
                        system("PAUSE");
                    }
                    else if(trapD == false)
                    {
                        cout << "You use your immense strength to tear your way out of the Mushroom's stomach,  \n";
                        cout << "killing it in the process.\n\n";
                        system("PAUSE");
                    }

                    alive = CheckAlive();
                    if(alive == false)
                    {
                        return;
                    }
                    Save();

                    trapD = false;
                    system("PAUSE");
                }
                else
                {
                    LevelScreen[13] = "  The Giant Mushroom fills the room.                                           \n";
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 3)
                    {
                        Level = 65;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 69:  //==============================FLOOR 4 ROOM 10================================================================================
            {
                Floor = 4;
                Room = 10;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "=============================CORRIDOR==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  You continue down the dark, wet passageway. It seems a little warmer here.  \n";
                LevelScreen[13] = "  The corridor continues East and West. A small passageway leads to the North.\n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 70;

                        if(GMTFGoblins[0][0] != 0)
                        {
                            cout << "You begin to head North, when a trio of Goblins leap from the shadows!\n\n";

                            system("PAUSE");

                            BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GMTFGoblins, 0);

                            if(BattleResult == 0)
                            {
                                return;
                            }
                            else
                            {
                                alive = CheckAlive();
                                if(alive == false)
                                {
                                    return;
                                }
                                Save();
                            }
                        }

                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 71;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 67;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        cout << "You cannot go down at the moment.\n\n";
                        system("PAUSE");
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 9)
                    {
                        cout << "You see the numerals LXIX engraved in the wall...\n\n";
                        system("PAUSE");
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 70:  //==============================FLOOR 4 ROOM 11================================================================================
            {
                Floor = 4;
                Room = 11;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "===============================TRAP====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only exit is to the South.                                               \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(trapE == true)
                {
                    trapE = TrapE(nCC, CharacterStats);

                    cout << "An inscription on the wall reads: 'This statement is a lie.'\n\n";

                    system("PAUSE");

                    if(trapE == false)
                    {
                        cout << "'Oh, that's an odd one!' You exclaim, and think nothing more on the matter.\n\n";
                        system("PAUSE");
                    }
                    else
                    {
                        cout << "Your brain becomes obsessed with the logical impossibility of the inscription.\n";
                        cout << "You suffer an existential crisis, go mad and run off into the distance, you will eventually die.\n\n";

                        CharacterStats[nCC][0] = 0;

                        system("PAUSE");
                    }
                    alive = CheckAlive();
                    if(alive == false)
                    {
                        return;
                    }
                    Save();

                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 4)
                    {
                        Level = 69;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 71:  //==============================FLOOR 4 ROOM 12================================================================================
            {
                Floor = 4;
                Room = 12;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "=============================CORRIDOR==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The corridor continues West. A small passageway leads to the South.          \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 4)
                    {
                        Level = 72;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 69;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 72:  //==============================FLOOR 4 ROOM 13================================================================================
            {
                Floor = 4;
                Room = 13;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "============================CROSSROADS=================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  You reach a crossroads. They feel oddly homely. Paths lead to the North,     \n";
                LevelScreen[13] = "  East and West.                                                               \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 71;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 74;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 73;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 73:  //==============================FLOOR 4 ROOM 14================================================================================
            {
                Floor = 4;
                Room = 14;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "==============================STAIRS===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  A passageway leads to the East. The stairs head down to the South.           \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 3)
                    {
                        Level = 72;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 78;
                        cout << "You head South down the stairs...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 74:  //==============================FLOOR 4 ROOM 15================================================================================
            {
                Floor = 4;
                Room = 15;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "============================THE MAP ROOM===============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  You enter a room with curious maps marked on the walls. The only exit is     \n";
                LevelScreen[13] = "  to the West.                                                                 \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 5)
                    {
                        Level = 72;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 9)
                    {
                        cout << "You examine the maps more closely and notice a secret passage in the Library.\n";
                        cout << "You mark it on your map.\n\n";

                        InvestigateMapRoom(PlayerMap3);

                        system("PAUSE");
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 75:  //==============================FLOOR 4 ROOM 16================================================================================
            {
                Floor = 4;
                Room = 16;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues North and East.                                           \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 62;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 76;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 76:  //==============================FLOOR 4 ROOM 17================================================================================
            {
                Floor = 4;
                Room = 17;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "===========================TROLL'S CORNER==============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues to the North and the West.                                \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(GMTFTrollCrew[0][0] != 0)
                {
                    cout << "A troll steps towards you. A goblin and a hellhound creep out from behind it!\n\n";

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GMTFTrollCrew, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 77;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 75;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 77:  //==============================FLOOR 4 ROOM 18================================================================================
            {
                Floor = 4;
                Room = 18;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "=====================THE GREAT MAZE - TOP FLOOR======================W + E=====\n";
                LevelScreen[2]  = "=============================DEAD END==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  You reach a dead end. The only exit is to the South.                         \n";

                GetMap(LevelScreen, PlayerMap4, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap4, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 4)
                    {
                        Level = 76;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap4, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 78:  //==============================FLOOR 5 ROOM 0=================================================================================
            {
                Floor = 5;
                Room = 0;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "==============================STAIRS===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The stairs lead to the North. The maze continues to the South.               \n";


                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 73;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 79;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 79:  //==============================FLOOR 5 ROOM 1=================================================================================
            {
                Floor = 5;
                Room = 1;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  You reach a crossroads. The maze continues North, East, South and West.      \n";

                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 78;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 81;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 82;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 80;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 80:  //==============================FLOOR 5 ROOM 2=================================================================================
            {
                Floor = 5;
                Room = 2;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "=============================DEAD END==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  You reach a dead end. The only exit is to the East.                          \n";

                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 3)
                    {
                        Level = 79;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 93;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 81:  //==============================FLOOR 5 ROOM 3=================================================================================
            {
                Floor = 5;
                Room = 3;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================TRAP====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only exit is to the West.                                                \n";

                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(trapF == true)
                {
                    cout << "You see a wooden dummy with a sword strapped to it.\nThe sword seems to emanate great power.\nYou think that you should be able to take the sword, after all, the dummy is \nmade of wood and can't move.\n\n";

                    cout << "Take the sword? ";

                    YN = YesNo();

                    if(YN == true)
                    {
                        trapF = TrapF(nCC);

                        if(trapF == true)
                        {
                            cout << "You move to grab the sword and the dummy begins to move!\nThe dummy slices your head clean off!\n\n";

                            system("PAUSE");

                            CharacterStats[nCC][0] = 0;
                        }
                        else
                        {
                            cout << "You move to grab the sword and the dummy begins to move!\n\nYou remember the commander's words, it may be moving, but it's still made of \nwood!\nYou dodge the dummy's attack, take its sword and destroy it!\n\n";

                            system("PAUSE");

                            CharacterInventory[0][3] = 1;
                        }

                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();

                    }
                    else
                    {
                        cout << "You decide to leave the sword for now...\n\n";

                        system("PAUSE");
                    }
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 5)
                    {
                        Level = 79;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 9)
                    {
                        if(trapF == true)
                        {
                            Level = 81;
                            Loop = false;
                        }
                        else
                        {
                            cout << "There is nothing left to investigate...\n\n";

                            system("PAUSE");
                        }
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 82:  //==============================FLOOR 5 ROOM 4=================================================================================
            {
                Floor = 5;
                Room = 4;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues to the North and the East.                                \n";

                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(trapG == true)
                {
                    cout << "A skeleton is propped up in the corner. A bow in its boney hands.\nYou think you could wrestle it free.\n\n";
                    cout << "Would you like to try to take the bow? ";

                    YN = YesNo();

                    if(YN == true)
                    {
                        trapG = TrapG(nCC);

                        if(trapG == true)
                        {
                            cout << "The skeleton stirs and attacks you with the bow!\nIt smashes in two, the skelton quickly goes for a second attack and stabs you with the shattered shaft of the bow!\nYou smash the skeletons head off with a well placed punch, but you are left seriously injured.\n\n";
                            system("PAUSE");

                            CharacterStats[nCC][5] -= 50;

                            if(CharacterStats[nCC][0] >= CharacterStats[nCC][5])
                            {
                                CharacterStats[nCC][0] = CharacterStats[nCC][5];
                            }
                            else
                            {
                                CharacterStats[nCC][0] = CharacterStats[nCC][0]/2;
                            }



                            trapG = false;
                        }
                        else
                        {
                            cout << "The skeleton stirs and attacks you with the bow!\nIt smashes in two but you remain fairly unharmed, you grab take the bow string and trip the skeleton!\nIt falls to the floor and smashes into pieces.\nYou take its quiver of arrows.\n\n";

                            system("PAUSE");

                            CharacterInventory[1][6] += 30;
                        }

                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                    else
                    {
                        cout << "You decide to leave the bow for now...\n\n";

                        system("PAUSE");
                    }


                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 79;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 83;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 83:  //==============================FLOOR 5 ROOM 5=================================================================================
            {
                Floor = 5;
                Room = 5;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues to the North, East and West.                              \n";

                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 84;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 85;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 82;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 84:  //==============================FLOOR 5 ROOM 6=================================================================================
            {
                Floor = 5;
                Room = 6;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "============================SIDE ROOM==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only exit is to the South.                                               \n";

                if(Puzzle1Solved == false)
                {
                    LevelScreen[13] = "  There is a strange inscription on the North Wall.                           \n";
                }
                else
                {
                    LevelScreen[13] = "  An inscription reads 'The spoon will end all that began with the sword'     \n";
                    LevelScreen[14] = "  A carving appears beneath it saying 'To gain the power of the dragon's      \n";
                    LevelScreen[15] = "  strike, go South from until you can go South no longer, then go South a     \n";
                    LevelScreen[16] = "  little further.                                                             \n";
                }


                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 4)
                    {
                        Level = 83;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 9)
                    {

                        if(Puzzle1Solved == false)
                        {
                            Puzzle1Solved = Puzzle1(LevelScreen);

                            if(Puzzle1Solved == true)
                            {
                                for(i = 0; i < 3; i ++)
                                {
                                    CharacterStats[i][6] += 10;
                                    CharacterStats[i][1] = CharacterStats[i][6];
                                }
                            }
                            Loop = false;

                        }
                        else
                        {
                            cout << "There is nothing left to investigate...\n\n";

                            system("PAUSE");
                        }
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 85:  //==============================FLOOR 5 ROOM 7=================================================================================
            {
                Floor = 5;
                Room = 7;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues West and South.                                           \n";

                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(GMUMTroll[0][0] != 0)
                {
                    cout << "As you turn to look around the corner you walk into a troll...\n\n";
                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GMUMTroll, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 4)
                    {
                        Level = 86;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 83;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 86:  //==============================FLOOR 5 ROOM 8=================================================================================
            {
                Floor = 5;
                Room = 8;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues North and West.                                           \n";

                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(GMUMTrolls[0][0] != 0)
                {
                    cout << "You walk into two more trolls, they seemed baffled that there aren't three of \nthem...\n";

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GMUMTrolls, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 85;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 87;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 87:  //==============================FLOOR 5 ROOM 9=================================================================================
            {
                Floor = 5;
                Room = 9;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues North, East, South and West.                              \n";

                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(GMUMSkeletons[0][0] != 0)
                {
                    cout << "Skeletons approach you from the North, South and West...\n\n";

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GMUMSkeletons, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }

                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 88;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 86;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 91;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 89;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 88:  //==============================FLOOR 5 ROOM 10================================================================================
            {
                Floor = 5;
                Room = 10;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "==============================DEAD END=================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only exit is South. There North wall appears to have been bricked up     \n";
                LevelScreen[13] = "  long after the Maze was built. Perhaps once there was a direct route through.\n";

                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 4)
                    {
                        Level = 87;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 89:  //==============================FLOOR 5 ROOM 11================================================================================
            {
                Floor = 5;
                Room = 11;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues to the East and the South.                                \n";

                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 3)
                    {
                        Level = 87;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 90;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 90:  //==============================================================================================================
            {
                Floor = 5;
                Room = 12;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "=============================DEAD END==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only exit is to the North.                                               \n";

                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 89;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 9)
                    {
                        if(Riddle1Solved == false)
                        {
                            Riddle1Solved = Riddle1(LevelScreen);

                            if(Riddle1Solved == true)
                            {
                                cout << "Part of the wall slides away to reveal a black key, you pick it up...\n\n";
                                system("PAUSE");

                                Keys[2] ++;
                            }
                        }
                        else
                        {
                            cout << "There is nothing left to investigate...\n\n";

                            system("PAUSE");
                        }
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 91:  //==============================FLOOR 5 ROOM 13================================================================================
            {
                Floor = 5;
                Room = 13;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues to the North and East.                                    \n";

                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 87;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 92;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        if(CharacterInventory[0][5] == 0 || CharacterInventory[1][5] == 0 || CharacterInventory[2][5] == 0)
                        {
                            cout << "You push the wall a little and it begins to move...\n\n";
                            system("PAUSE");

                            cout << "It leads into a small room with a bow in its centre, the bow seems to be made \nof the horn of a dragon.\n";

                            if(CharacterStats[1][0] != 0)
                            {
                                cout << CharacterInfo[1][0] << " picks up the bow!\n\n";

                                system("PAUSE");

                                CharacterInventory[1][5] ++;
                                CharacterInventory[1][6] += 30;
                            }
                            else if(CharacterStats[0][0] != 0)
                            {
                                cout << CharacterInfo[0][0] << " picks up the bow!\n\n";

                                system("PAUSE");

                                CharacterInventory[0][5] ++;
                                CharacterInventory[0][6] += 30;
                            }
                            else
                            {
                                cout << CharacterInfo[2][0] << " picks up the bow!\n\n";

                                system("PAUSE");

                                CharacterInventory[2][5] ++;
                                CharacterInventory[2][6] += 30;
                            }
                        }
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 92:  //==============================FLOOR 5 ROOM 14================================================================================
            {
                Floor = 5;
                Room = 14;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "==============================STAIRS===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues to the West, the stairs lead down to the North.           \n";

                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 111;
                        cout << "You head North down the stairs...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 91;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 93:  //==============================FLOOR 5 ROOM 15================================================================================
            {
                Floor = 5;
                Room = 15;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "=========================SECRET PASSAGEWAY=============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The secret passageway extends South. The maze is East.                       \n";

                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 3)
                    {
                        Level = 80;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 94;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 94:  //==============================FLOOR 5 ROOM 16================================================================================
            {
                Floor = 5;
                Room = 16;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - UPPER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "=====================SECRET PASSAGEWAY - STAIRS========================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The secret passageway extends to the North. The stairs lead down to the      \n";
                LevelScreen[13] = "  South                                                                        \n";

                GetMap(LevelScreen, PlayerMap5, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap5, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 93;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 130;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap5, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 95:  //==============================FLOOR 6 ROOM 0=================================================================================
            {
                Floor = 6;
                Room = 0;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "==============================STAIRS===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues to the South. The stairs lead up to the North.            \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 131;
                        cout << "You head North up the stairs...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 96;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 96:  //==============================FLOOR 6 ROOM 1=================================================================================
            {
                Floor = 6;
                Room = 1;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues to the North, East and South.                             \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 95;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 97;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 100;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 97:  //==============================FLOOR 6 ROOM 2=================================================================================
            {
                Floor = 6;
                Room = 2;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "==============================STAIRS===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues East and West.                                            \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 3)
                    {
                        Level = 98;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 96;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 98:  //==============================FLOOR 6 ROOM 3=================================================================================
            {
                Floor = 6;
                Room = 3;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "============================LARGE ROOM=================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues to the North, South and West.                             \n";

                if(Keys[3] == 0)
                {
                    LevelScreen[13] = "  To the West there is a grand, Golden Gate.                                   \n";
                }

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 111;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        if(Keys[3] != 0)
                        {
                            Level = 97;
                            cout << "You head West...\n\n";
                            system("PAUSE");
                            Loop = false;
                        }
                        else
                        {
                            cout << "The Gold Gate remains firmly locked...\n\n";
                            system("PAUSE");
                        }
                    }
                    else if(command == 4)
                    {
                        Level = 99;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 99:  //==============================FLOOR 6 ROOM 4=================================================================================
            {
                Floor = 6;
                Room = 4;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "============================ANTE CHAMBER===============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only exit is to the North.                                               \n";
                LevelScreen[13] = "  There is a mysterious carving on the wall.                                   \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 98;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 9)
                    {
                        if(Riddle2Solved == false)
                        {
                            Riddle2Solved = Riddle2(LevelScreen);

                            if(Riddle2Solved == true)
                            {
                                cout << "Part of the wall slides away to reveal a golden key!\n\n";

                                Keys[3] ++;

                                system("PAUSE");
                            }
                            else
                            {
                                cout << "You leave the wall, for now...\n\n";

                                system("PAUSE");

                                Loop = false;
                            }
                        }
                        else
                        {
                            cout << "There is nothing left to investigate...\n\n";

                            system("PAUSE");
                        }
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 100: //==============================FLOOR 6 ROOM 5=================================================================================
            {
                Floor = 6;
                Room = 5;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues North, and East.                                          \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 96;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 101;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 101: //==============================FLOOR 6 ROOM 6=================================================================================
            {
                Floor = 6;
                Room = 6;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "==============================STAIRS===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues South and West.                                           \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 4)
                    {
                        Level = 102;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 100;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 102: //==============================FLOOR 6 ROOM 7=================================================================================
            {
                Floor = 6;
                Room = 7;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues North, East and West.                                     \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 101;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 105;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 103;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 103: //==============================FLOOR 6 ROOM 8=================================================================================
            {
                Floor = 6;
                Room = 8;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues North and East.                                           \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 104;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 102;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 104: //==============================FLOOR 6 ROOM 9=================================================================================
            {
                Floor = 6;
                Room = 9;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "=============================DEAD END==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only exit is South.                                                      \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(GMLMTroll[0][0] != 0)
                {
                    cout << "You reach the end of the passageway, a troll lurches out from the darkness!\n\n";

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GMLMTroll, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 4)
                    {
                        Level = 103;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 105: //==============================FLOOR 6 ROOM 10================================================================================
            {
                Floor = 6;
                Room = 10;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues to the West and South.                                    \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 4)
                    {
                        Level = 106;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 102;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 106: //==============================FLOOR 6 ROOM 11================================================================================
            {
                Floor = 6;
                Room = 11;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues to the North and West.                                    \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 105;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 107;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 107: //==============================FLOOR 6 ROOM 12================================================================================
            {
                Floor = 6;
                Room = 12;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues North, East and West.                                     \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 108;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 106;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 109;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 108: //==============================FLOOR 6 ROOM 13================================================================================
            {
                Floor = 6;
                Room = 13;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "============================DEAD END===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only exit is to the South.                                               \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 4)
                    {
                        Level = 107;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 109: //==============================FLOOR 6 ROOM 14================================================================================
            {
                Floor = 6;
                Room = 14;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "==============================STAIRS===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues to the North and East, the stairs lead down to the South. \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 110;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 107;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 112;
                        cout << "You head South down the stairs...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 110: //==============================FLOOR 6 ROOM 15================================================================================
            {
                Floor = 6;
                Room = 15;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "=============================DEAD END==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only exit is to the South.                                               \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(trapH == true)
                {
                    cout << "You feel a click beneath your foot as you sink into a pressure plate...\n\n";

                    system("PAUSE");

                    cout << "Two axes suddenly swing at you from the walls either side...\n\n";

                    trapH = TrapH(nCC, CharacterStats);

                    if(trapH == true)
                    {
                        cout << "You try to dodge one axe, but whilst doing this you get in the way of the \nother. You are dead!\n\n";

                        system("PAUSE");

                        trapH = false;
                        CharacterStats[nCC][0] = 0;
                        Switch();
                    }
                    else
                    {
                        cout << "You manage to weave your way between the axes and get back to the \ndoorway safely.\n\n";
                        system("PAUSE");
                    }
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 4)
                    {
                        Level = 109;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 111: //==============================FLOOR 6 ROOM 16================================================================================
            {
                Floor = 6;
                Room = 16;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - LOWER MIDDLE=====================W + E=====\n";
                LevelScreen[2]  = "==============================STAIRS===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues to the South, the stairs lead up to the North.            \n";

                GetMap(LevelScreen, PlayerMap6, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap6, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 92;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 98;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap6, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 112: //==============================FLOOR 7 ROOM 0=================================================================================
            {
                Floor = 7;
                Room = 0;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - GROUND FLOOR=====================W + E=====\n";
                LevelScreen[2]  = "==============================STAIRS===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The stairs lead up to the North. The maze continues to the South.            \n";

                GetMap(LevelScreen, PlayerMap7, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap7, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 109;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 113;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap7, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 113: //==============================FLOOR 7 ROOM 1=================================================================================
            {
                Floor = 7;
                Room = 1;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - GROUND FLOOR=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The the maze continues North and East.                                       \n";

                GetMap(LevelScreen, PlayerMap7, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(GMBFSkeletonA[0][0] != 0)
                {
                    cout << "As you walk towards the corner a skeleton senses your approach and begins to \nmove towards you...\n\n";

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GMBFSkeletonA, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap7, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 112;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 114;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap7, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 114: //==============================FLOOR 7 ROOM 2=================================================================================
            {
                Floor = 7;
                Room = 2;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - GROUND FLOOR=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues North and West.                                           \n";

                GetMap(LevelScreen, PlayerMap7, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(GMBFSkeletonB[0][0] != 0)
                {
                    cout << "As you edge down the corridor, a suit of armour begins to move. In the gaps of\nsteel plating you can see bony limbs...\n\n";
                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GMBFSkeletonB, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap7, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 115;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 113;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap7, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 115: //==============================FLOOR 7 ROOM 3=================================================================================
            {
                Floor = 7;
                Room = 3;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - GROUND FLOOR=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues East, South and West.                                     \n";

                GetMap(LevelScreen, PlayerMap7, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(GMBFHellHoundPack[0][0] != 0)
                {
                    cout << "A pack of Hellhounds is devouring the body of a knight. They don't seem to     \ndamage the flesh so much as the soul. They turn and move towards you...\n\n";
                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GMBFHellHoundPack, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap7, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 3)
                    {
                        Level = 118;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 114;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 116;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap7, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 116: //==============================FLOOR 7 ROOM 4=================================================================================
            {
                Floor = 7;
                Room = 4;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - GROUND FLOOR=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues East and South.                                           \n";
                LevelScreen[13] = "  To the South there is a crude barricade that appears to have been attacked   \n";
                LevelScreen[14] = "  by Hellhounds a number of times. But you could easily climb over it.         \n";


                GetMap(LevelScreen, PlayerMap7, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap7, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 3)
                    {
                        Level = 115;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 117;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap7, Floor, Room);
                    }
                    else if(command == 9)
                    {
                        cout << "The barricade is immovable, but climbing over it seems like a relatively       \nsimple task for a person.\n\n";
                        system("PAUSE");
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 117: //==============================FLOOR 7 ROOM 5=================================================================================
            {
                Floor = 7;
                Room = 5;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - GROUND FLOOR=====================W + E=====\n";
                LevelScreen[2]  = "========================BLACK KNIGHT'S LAIR============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only exit is to the North.                                               \n";
                LevelScreen[13] = "  A knight armoured entirely in some strange dark metal stands in the centre   \n";
                LevelScreen[14] = "  of the room. They appear to be very old and very tired.                      \n";


                GetMap(LevelScreen, PlayerMap7, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap7, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 116;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap7, Floor, Room);
                    }
                    else if(command == 9 || command == 22)
                    {
                        cout << "The Black Knight wants to speak to you...\n\n";
                        cout << "Would you like to speak to the Black Knight? ";

                        YN = YesNo();

                        if(YN == true)
                        {
                            BlackKnight = BlackKnightConv(LevelScreen, CharacterInfo, CharacterInventory, nCC);
                        }
                        else
                        {
                            cout << "You ignore the Black Knight...\n\n";

                            system("PAUSE");
                        }

                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 118: //==============================FLOOR 7 ROOM 6=================================================================================
            {
                Floor = 7;
                Room = 6;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - GROUND FLOOR=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues to the West and the South.                                \n";
                LevelScreen[13] = "                                                                               \n";

                if(trapI == true)
                {
                    LevelScreen[12] = "  The maze continues to the West and the South. A magical staff is propped up  \n";
                    LevelScreen[13] = "  in the corner.                                                               \n";
                }

                GetMap(LevelScreen, PlayerMap7, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap7, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 4)
                    {
                        Level = 119;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 115;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap7, Floor, Room);
                    }
                    else if(command == 9)
                    {
                        if(trapI == true)
                        {
                            cout << "You try to pick up the staff to take a closer look at it.\n\n";

                            system("PAUSE");

                            trapI = TrapI(nCC, CharacterStats);

                            if(trapI == true)
                            {
                                cout << "The staff glows with a magical energy! Your magical abilities aren't enough    \n";
                                cout << "to control it. The staff explodes with a magical light and you disappear from  \n";
                                cout << "reality.\n\n                                                                   \n";

                                system("PAUSE");

                                Switch();

                                trapI = false;
                            }
                            else
                            {
                                cout << "The staff glows with a magical energy! Suspecting something's up you banish    \n";
                                cout << "it to another dimension!\n\n";
                                system("PAUSE");
                            }

                            alive = CheckAlive();
                            if(alive == false)
                            {
                                return;
                            }
                            Save();


                            LevelScreen[12] = "  The maze continues to the West and the South.                                \n";
                            LevelScreen[13] = "                                                                               \n";
                        }
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 119: //==============================FLOOR 7 ROOM 7=================================================================================
            {
                Floor = 7;
                Room = 7;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - GROUND FLOOR=====================W + E=====\n";
                LevelScreen[2]  = "===============================MAZE====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continues North and West.                                           \n";

                GetMap(LevelScreen, PlayerMap7, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(GMBFHellHound[0][0] != 0)
                {
                    cout << "You see a Hellhound limping towards you, it is clear that it is the weak\nmember of the pack, but it still intends to attack!\n\n";
                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GMBFHellHound, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                }
                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap7, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 118;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 120;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap7, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 120: //==============================FLOOR 7 ROOM 8=================================================================================
            {
                Floor = 7;
                Room = 8;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - GROUND FLOOR=====================W + E=====\n";
                LevelScreen[2]  = "==============================STAIRS===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The maze continuinues to the East. A massive door lies to the South,         \n";
                LevelScreen[13] = "  it doesn't seem to be locked.                                                \n";

                GetMap(LevelScreen, PlayerMap7, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(GMBFOgre[0][0] != 0)
                {
                    cout << "An Ogre lumbers towards you from the direction of the door...\n\n";
                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GMBFOgre, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();
                    }
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap7, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 3)
                    {
                        Level = 119;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        cout << "Are you sure you want to pass through the door? ";
                        YN = YesNo();

                        if(YN == true)
                        {
                            Level = 121;
                            cout << "You head South...\n\n";
                            system("PAUSE");
                            Loop = false;
                        }
                        else
                        {
                            cout << "You decide not to go through the door for now...\n\n";

                            system("PAUSE");
                        }
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap7, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 121: //==============================FLOOR 7 ROOM 9=================================================================================
            {
                Floor = 7;
                Room = 9;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - GROUND FLOOR=====================W + E=====\n";
                LevelScreen[2]  = "===========================DRAGON'S LAIR===============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The doorway lies to the North.                                               \n";

                GetMap(LevelScreen, PlayerMap7, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(GMBFDragon[0][0] != 0)
                {
                    cout << "As you enter the room, you see a gigantic dragon!\nIt turns towards you and roars!\n\n";

                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, GMBFDragon, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {

                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();

                        cout << "As the dragon falls to its death it knocks down the South wall...\n\n";

                        system("PAUSE");
                    }
                }

                if(GMBFDragon[0][0] == 0)
                {
                    LevelScreen[12] = "  The doorway lies to the North. A path leads beyond the South Wall.           \n";
                }


                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap7, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 120;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {


                        Level = 122;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap7, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 122: //==============================FLOOR 7 ROOM 10================================================================================
            {
                Floor = 7;
                Room = 10;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===================THE GREAT MAZE - GROUND FLOOR=====================W + E=====\n";
                LevelScreen[2]  = "==========================DARK PASSAGEWAY==============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  To the North the passageway opens into a large room. To the South the path   \n";
                LevelScreen[13] = "  darker and becomes more cave like, it is not clear how far it goes.          \n";

                GetMap(LevelScreen, PlayerMap7, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap7, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 121;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        CaveJourney(CharacterStats, CharacterInfo);

                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();

                        Level = 123;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap7, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 123: //==============================FLOOR 8 ROOM 0=================================================================================
            {
                Floor = 8;
                Room = 0;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "================================DOCK=================================W + E=====\n";
                LevelScreen[2]  = "============================CAVE OPENING===============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The the dock continues to the South. A dark cavern leads off to the North.   \n";

                if(Dock == false)
                {
                    cout << "\n  You emerge from the cave into a dock area.\n\n";
                    system("PAUSE");
                    Dock = true;
                }

                GetMap(LevelScreen, PlayerMap8, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap8, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 122;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 124;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap8, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 124: //==============================FLOOR 8 ROOM 1=================================================================================
            {
                Floor = 8;
                Room = 1;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "================================DOCK=================================W + E=====\n";
                LevelScreen[2]  = "===============================JETTY===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The dock continues East and West. The cave opening is to the North.          \n";

                GetMap(LevelScreen, PlayerMap8, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap8, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 123;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 125;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 126;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap8, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 125: //==============================FLOOR 8 ROOM 2=================================================================================
            {
                Floor = 8;
                Room = 2;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "================================DOCK=================================W + E=====\n";
                LevelScreen[2]  = "=============================DOCK HOUSE================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The dock continues to the West. A small house lies to the East.              \n";

                GetMap(LevelScreen, PlayerMap8, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap8, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 3)
                    {
                        InvestigateDockHouse(CharacterStats, CharacterInventory, DockHouse);
                    }
                    else if(command == 5)
                    {
                        Level = 124;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap8, Floor, Room);
                    }
                    else if(command == 9)
                    {
                        InvestigateDockHouse(CharacterStats, CharacterInventory, DockHouse);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 126: //==============================FLOOR 8 ROOM 3=================================================================================
            {
                Floor = 8;
                Room = 3;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "================================DOCK=================================W + E=====\n";
                LevelScreen[2]  = "===============================JETTY===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The the dock continues East and South.                                       \n";

                GetMap(LevelScreen, PlayerMap8, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap8, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 3)
                    {
                        Level = 124;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 127;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap8, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 127: //==============================FLOOR 8 ROOM 4=================================================================================
            {
                Floor = 8;
                Room = 4;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "================================DOCK=================================W + E=====\n";
                LevelScreen[2]  = "===============================JETTY===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The dock continues to the North. A boat is moored to the South side of the   \n";
                LevelScreen[13] = "  jetty.                                                                       \n";

                GetMap(LevelScreen, PlayerMap8, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap8, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 126;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 128;
                        cout << "You head South onto the boat...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap8, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 128: //==============================FLOOR 8 ROOM 5=================================================================================
            {
                Floor = 8;
                Room = 5;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "================================DOCK=================================W + E=====\n";
                LevelScreen[2]  = "=============================BOAT - BOW================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[15] = "  The jetty is to the North. The stern of the boat is to the East.             \n";

                GetMap(LevelScreen, PlayerMap8, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap8, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 127;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 141;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap8, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 129: //==============================FLOOR 9 ROOM 0 - WARLOCK DEN===================================================================
            {
                Floor = 9;
                Room = 0;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================WARLOCK DEN==============================W + E=====\n";
                LevelScreen[2]  = "=======================================================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only exit is to the South.                                               \n";

                GetMap(LevelScreen, WarlockDenMap, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(Warlock[0][0] != 0)
                {
                    cout << "  Warlock: So, you like disco dancing, Ice Cream Cone?\n\nThe mad warlock summons two goblins to fight by his side...\n\n";
                    system("PAUSE");

                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, Warlock, 0);

                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {

                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        Save();

                        WarlockConv(LevelScreen, BlackKnight, CharacterStats);
                    }
                }
                else
                {
                    cout << "Would you like to talk to the Warlock? ";

                    YN = YesNo();

                    if(YN == true)
                    {
                        WarlockConv(LevelScreen, BlackKnight, CharacterStats);
                    }
                }


                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, WarlockDenMap, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 4)
                    {
                        Level = 56;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(WarlockDenMap, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 22)
                    {
                        WarlockConv(LevelScreen, BlackKnight, CharacterStats);
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 130: //==============================FLOOR 10 ROOM 0 - SPOON TROVE==================================================================
            {
                Floor = 10;
                Room = 0;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "============================SPOON TROVE==============================W + E=====\n";
                LevelScreen[2]  = "===========================TREASURE ROOM===============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "  The only exit is North. A treasure chest sits in the centre of the room.     \n";

                GetMap(LevelScreen, SpoonTroveMap, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, SpoonTroveMap, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 94;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(SpoonTroveMap, Floor, Room);
                    }
                    else if(command == 9)
                    {
                        if(HasSpoon == false)
                        {
                            cout << "The chest has a rusty old lock on it.\nWould you like to open the chest? ";
                            YN = YesNo();

                            if(YN == true)
                            {
                                if(Keys[0] != 0)
                                {
                                    HasSpoon = SpoonChest(CharacterStats, CharacterInventory, CharacterInfo);

                                }
                                else
                                {
                                    cout << "You try to force the lock, but it doesn't work.\n\n";
                                    system("PAUSE");
                                }
                            }
                            else
                            {
                                cout << "You decide to leave the chest for now...\n\n";
                                system("PAUSE");
                            }
                        }
                        else
                        {
                            cout << "The chest is still empty...\n\n";
                            system("PAUSE");
                        }
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 131: //==============================FLOOR 11 ROOM 0 - WIZARD'S TOWER (FLOOR 0)=====================================================
            {
                Floor = 11;
                Room = 0;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================WIZARD'S TOWER============================W + E=====\n";
                LevelScreen[2]  = "=============================ENTRANCE==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "                                                                               \n";
                LevelScreen[13] = "                                                                               \n";
                LevelScreen[14] = "                                                                               \n";
                LevelScreen[15] = "                                                                               \n";
                LevelScreen[16] = "                                                                               \n";
                LevelScreen[17] = "  The wizard's tower continues to the North and East. Stairs lead down to the  \n";
                LevelScreen[18] = "  South.                                                                       \n";

                GetMap(LevelScreen, WizardTowerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, WizardTowerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 136;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 3)
                    {
                        Level = 132;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 95;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(WizardTowerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 132: //==============================FLOOR 11 ROOM 1 - WIZARD'S TOWER (FLOOR 0)=====================================================
            {
                Floor = 11;
                Room = 1;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================WIZARD'S TOWER============================W + E=====\n";
                LevelScreen[2]  = "==============================CORNER===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "                                                                               \n";
                LevelScreen[13] = "                                                                               \n";
                LevelScreen[14] = "                                                                               \n";
                LevelScreen[15] = "                                                                               \n";
                LevelScreen[16] = "                                                                               \n";
                LevelScreen[17] = "  The wizard's tower continues to the North and West.                          \n";

                GetMap(LevelScreen, WizardTowerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, WizardTowerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 133;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 131;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(WizardTowerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 133: //==============================FLOOR 11 ROOM 2 - WIZARD'S TOWER (FLOOR 0)=====================================================
            {
                Floor = 11;
                Room = 2;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================WIZARD'S TOWER============================W + E=====\n";
                LevelScreen[2]  = "==============================STAIRS===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "                                                                               \n";
                LevelScreen[13] = "                                                                               \n";
                LevelScreen[14] = "                                                                               \n";
                LevelScreen[15] = "                                                                               \n";
                LevelScreen[16] = "                                                                               \n";
                LevelScreen[17] = "  The wizard's tower continues to the South. Stairs lead to the North.         \n";

                GetMap(LevelScreen, WizardTowerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, WizardTowerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 137;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 132;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(WizardTowerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 134: //==============================FLOOR 11 ROOM 3 - WIZARD'S TOWER (FLOOR 0)=====================================================
            {
                Floor = 11;
                Room = 3;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================WIZARD'S TOWER============================W + E=====\n";
                LevelScreen[2]  = "=============================CORNER====================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "                                                                               \n";
                LevelScreen[13] = "                                                                               \n";
                LevelScreen[14] = "                                                                               \n";
                LevelScreen[15] = "                                                                               \n";
                LevelScreen[16] = "                                                                               \n";
                LevelScreen[17] = "  You enter a dark corner of the wizard's tower. The only way back is to the   \n";
                LevelScreen[18] = "  West.                                                                        \n";

                GetMap(LevelScreen, WizardTowerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    if(WizardTower0Items[11] != 0 || WizardTower0Items[12] != 0)
                    {
                        LevelScreen[18].replace(8, 35, "There are a few potions on a shelf.");
                    }

                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, WizardTowerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 1)
                    {
                        PickUp(CharacterInventory, WizardTower0Items, nCC);
                    }
                    else if(command == 5)
                    {
                        Level = 135;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(WizardTowerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 135: //==============================FLOOR 11 ROOM 4 - WIZARD'S TOWER (FLOOR 0)=====================================================
            {
                Floor = 11;
                Room = 4;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================WIZARD'S TOWER============================W + E=====\n";
                LevelScreen[2]  = "============================NORTH WALL=================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "                                                                               \n";
                LevelScreen[13] = "                                                                               \n";
                LevelScreen[14] = "                                                                               \n";
                LevelScreen[15] = "                                                                               \n";
                LevelScreen[16] = "                                                                               \n";
                LevelScreen[17] = "  The wizard's tower continues East and South.                                 \n";

                GetMap(LevelScreen, WizardTowerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, WizardTowerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 3)
                    {
                        Level = 134;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 136;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(WizardTowerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 136: //==============================FLOOR 11 ROOM 5 - WIZARD'S TOWER (FLOOR 0)=====================================================
            {
                Floor = 11;
                Room = 5;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================WIZARD'S TOWER============================W + E=====\n";
                LevelScreen[2]  = "==============================SHELVES==================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "                                                                               \n";
                LevelScreen[13] = "                                                                               \n";
                LevelScreen[14] = "                                                                               \n";
                LevelScreen[15] = "                                                                               \n";
                LevelScreen[16] = "                                                                               \n";
                LevelScreen[17] = "  Shelves of books tower either side of you. The wizard's tower continues      \n";
                LevelScreen[18] = "  North and South.                                                             \n";

                GetMap(LevelScreen, WizardTowerMap0, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, WizardTowerMap0, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 135;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 131;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(WizardTowerMap0, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 137: //==============================FLOOR 12 ROOM 0 - WIZARD'S TOWER (FLOOR 1)=====================================================
            {
                Floor = 12;
                Room = 0;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================WIZARD'S TOWER============================W + E=====\n";
                LevelScreen[2]  = "==============================STAIRS===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "                                                                               \n";
                LevelScreen[13] = "                                                                               \n";
                LevelScreen[14] = "                                                                               \n";
                LevelScreen[15] = "                                                                               \n";
                LevelScreen[16] = "                                                                               \n";
                LevelScreen[17] = "  The stairs lead down to the North. The wizard's tower continues to the West. \n";

                GetMap(LevelScreen, WizardTowerMap1, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, WizardTowerMap1, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 2)
                    {
                        Level = 133;
                        cout << "You head North...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 138;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(WizardTowerMap1, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 138: //==============================FLOOR 12 ROOM 1 - WIZARD'S TOWER (FLOOR 1)=====================================================
            {
                Floor = 12;
                Room = 1;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================WIZARD'S TOWER============================W + E=====\n";
                LevelScreen[2]  = "===========================WIZARD'S STUDY==============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "                                                                               \n";
                LevelScreen[13] = "                                                                               \n";
                LevelScreen[14] = "                                                                               \n";
                LevelScreen[15] = "                                                                               \n";
                LevelScreen[16] = "                                                                               \n";
                LevelScreen[17] = "  There is a table covered in old manuscripts and ancient tomes. The wizard's  \n";
                LevelScreen[18] = "  tower continues East and West. An old wizard faces the window.               \n";

                GetMap(LevelScreen, WizardTowerMap1, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, WizardTowerMap1, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 3)
                    {
                        Level = 137;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 139;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(WizardTowerMap1, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 20)
                    {
                        if(Wizard[0][0] != 0)
                        {
                            cout << "The wizard hears your challenge. He turns around, brandishing a magical staff...\n\n";
                            system("PAUSE");

                            BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, Wizard, 0);

                            if(BattleResult == 0)
                            {
                                return;
                            }
                            else
                            {

                                alive = CheckAlive();
                                if(alive == false)
                                {
                                    return;
                                }
                                Save();


                                WizardConv(LevelScreen, CharacterInventory, nCC);
                            }
                        }
                        else
                        {
                            cout << "  Wizard: I am too weary to fight any more...\n\n";
                            system("PAUSE");
                        }
                    }
                    else if(command == 22)
                    {
                        if(Wizard[0][0] != 0)
                        {
                            cout << "You call to the wizard and he turns around, brandishing a magical staff...\n\n";

                            system("PAUSE");

                            BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, Wizard, 0);

                            if(BattleResult == 0)
                            {
                                return;
                            }
                            else
                            {
                                alive = CheckAlive();
                                if(alive == false)
                                {
                                    return;
                                }
                                Save();
                                WizardConv(LevelScreen, CharacterInventory, nCC);
                            }
                        }
                        else
                        {
                            WizardConv(LevelScreen, CharacterInventory, nCC);
                        }
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 139: //==============================FLOOR 12 ROOM 2 - WIZARD'S TOWER (FLOOR 1)=====================================================
            {
                Floor = 12;
                Room = 2;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================WIZARD'S TOWER============================W + E=====\n";
                LevelScreen[2]  = "==============================STAIRS===================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "                                                                               \n";
                LevelScreen[13] = "                                                                               \n";
                LevelScreen[14] = "                                                                               \n";
                LevelScreen[15] = "                                                                               \n";
                LevelScreen[16] = "                                                                               \n";
                LevelScreen[17] = "  The wizard's tower continues to the East. Stairs lead up to the South.       \n";

                GetMap(LevelScreen, WizardTowerMap1, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, WizardTowerMap1, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();

                    if(command == 3)
                    {
                        Level = 138;
                        cout << "You head East...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 4)
                    {
                        Level = 140;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(WizardTowerMap1, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 140: //==============================FLOOR 13 ROOM 0 - WIZARD'S TOWER (FLOOR 2)=====================================================
            {
                Floor = 13;
                Room = 0;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "===========================WIZARD'S TOWER============================W + E=====\n";
                LevelScreen[2]  = "=============================TOP FLOOR=================================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[12] = "                                                                               \n";
                LevelScreen[13] = "                                                                               \n";
                LevelScreen[14] = "                                                                               \n";
                LevelScreen[15] = "                                                                               \n";
                LevelScreen[16] = "                                                                               \n";
                LevelScreen[17] = "  The stairs lead down to the West. An ancient staff lies on a rack in the     \n";
                LevelScreen[18] = "  centre of the room.                                                          \n";

                GetMap(LevelScreen, WizardTowerMap2, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                Loop = true;

                while(Loop == true)
                {
                    if(WizardTower2Items[8] == 0)
                    {
                        LevelScreen[17] = "  The stairs lead down to the West.                                            \n";
                        LevelScreen[18] = "                                                                               \n";
                    }

                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, WizardTowerMap2, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 1)
                    {
                        PickUp(CharacterInventory, WizardTower2Items, nCC);
                    }
                    else if(command == 5)
                    {
                        Level = 139;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(WizardTowerMap2, Floor, Room);
                    }
                    else if(command == 9)
                    {
                        if(WizardTower2Items[8] != 0)
                        {
                            cout << "You take a closer look at the ancient staff.\nWould you like to take it? ";
                            YN = YesNo();
                            if(YN == true)
                            {
                                cout << "You take the Ancient Staff...\n\n";

                                system("PAUSE");

                                WizardTower2Items[8] = 0;
                                CharacterInventory[nCC][8] = 1;
                            }
                            else
                            {
                                cout << "You decide to leave the staff for now...\n\n";
                                system("PAUSE");
                            }
                        }
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }

            case 141:
            {
                Floor = 8;
                Room = 6;

                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "================================DOCK=================================W + E=====\n";
                LevelScreen[2]  = "============================BOAT - STERN===============================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                                                                               \n";
                LevelScreen[8]  = "                                                                               \n";
                LevelScreen[9]  = "                                                                               \n";
                LevelScreen[10] = "                                                                               \n";
                LevelScreen[11] = "                                                                               \n";
                LevelScreen[15] = "  Looking out over the water you don't see any exit from the cave. However, an \n";
                LevelScreen[16] = "  inscription on the ship's wheel reads: 'Hold the Spoon aloft to move         \n";
                LevelScreen[17] = "  mountains.' The bow of the boat is to the West.                              \n";

                GetMap(LevelScreen, PlayerMap8, Floor, Room);
                AddCharacter(CharacterInfo, nCC, LevelScreen);

                drawScreen(LevelScreen, 32);

                if(HasSpoon != false)
                {
                    cout << "You hold the Rusty Spoon above your head, it glows a brilliant white light and \n";
                    cout << "the rock wall to the South begins to crumble. Sunlight bursts through cracks   \n";
                    cout << "in the rock. You can now sail out to the South.                                \n";

                    system("PAUSE");

                    LevelScreen[18] = "  There is a sailable route to the South.                                      \n";
                }

                Loop = true;

                while(Loop == true)
                {
                    AddCharacter(CharacterInfo, nCC, LevelScreen);
                    GetMap(LevelScreen, PlayerMap8, Floor, Room);
                    drawScreen(LevelScreen, 32);

                    command = Input();
                    if(command == 4 && HasSpoon == true)
                    {
                        Level = 142;
                        cout << "You head South...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 5)
                    {
                        Level = 128;
                        cout << "You head West...\n\n";
                        system("PAUSE");
                        Loop = false;
                    }
                    else if(command == 8)
                    {
                        ViewMap(PlayerMap8, Floor, Room);
                    }
                    else if(command == 11)
                    {
                        UsePotion();
                    }
                    else if(command == 12)
                    {
                        ViewInventory(CharacterStats, CharacterInfo, CharacterInventory, Keys);
                    }
                    else if(command == 13)
                    {
                        info();
                    }
                    else if(command == 14)
                    {
                        Save();
                    }
                    else if(command == 16)
                    {
                        Switch();
                    }
                    else if(command == 23)
                    {
                        ViewStats(CharacterStats, CharacterInfo);
                    }
                    else if(command == -1)
                    {
                        return;
                    }
                    else
                    {
                        cout << "That is not a valid command at the moment!" << endl << endl;
                        system("PAUSE");
                    }
                }
            break;
            }
            case 142:
            {
                EmptyScreen(LevelScreen);

                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================THE SEA================================W + E=====\n";
                LevelScreen[2]  = "=======================MOUNTAINOUS COASTLINE===========================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "  ...                                                                          \n";
                LevelScreen[5]  = "                                                                               \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[4] = "  The boat sails out of the cave as if carried by some mystical wind. The sea  \n";
                LevelScreen[5] = "  air is refreshing and cool.                                                  \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[4] = "  Several days later...                                                        \n";
                LevelScreen[5] = "                                                                               \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[4] = "  After days of sailing along the coast you spot a ship.                       \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[4] = "  As you approach the ship, you notice it is flying the Jolly Roger! You try   \n";
                LevelScreen[5] = "  to change your course but are too late! Your boat is boarded by pirates!     \n";

                drawScreen(LevelScreen, 32);
                system("PAUSE");

                if(PiratesA[0][0] != 0)
                {
                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, PiratesA, 0);
                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {
                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        //Save();

                    /*
                        cout << "The pirates drop some potions, which you quickly take!\n\n";
                        system("PAUSE");
                        AddPotions(CharacterInventory, CharacterStats); */
                    }
                }

                LevelScreen[4] = "  You have only a moment to catch your breath before the Pirate Captain boards \n";
                LevelScreen[5] = "  your boat with a few of his minions!                                         \n";

                drawScreen(LevelScreen, 32);
                system("PAUSE");
                if(PiratesB[0][0] != 0)
                {
                    BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, PiratesB, 0);
                    if(BattleResult == 0)
                    {
                        return;
                    }
                    else
                    {

                        alive = CheckAlive();
                        if(alive == false)
                        {
                            return;
                        }
                        //Save();
                /*
                        cout << "The captain and his cronies drop even more potions!\n\n";
                        system("PAUSE");

                        Roll = RollDice(11);

                        for(i = 0; i < Roll; i ++)
                        {
                            AddPotions(CharacterInventory, CharacterStats);
                        }
                        */
                    }
                }

                LevelScreen[4] = "  Suddenly, there is a clamour and some screaming! The remaining pirates begin \n";
                LevelScreen[5] = "  to flee...                                                                   \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[4] = "  You watch the pirates abandon their ship as it sinks into the sea...         \n";
                LevelScreen[5] = "                                                                               \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[4] = "  You hear a great crunching noise then see a dragon eating into the pirate    \n";
                LevelScreen[5] = "  ship! It flies out of the water and lands on the deck of your boat...        \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                BattleResult = Fight(CharacterStats, CharacterInventory, CharacterInfo, WeakDragon, 0);

                if(BattleResult == 0)
                {
                    return;
                }
                else
                {
                    alive = CheckAlive();
                    if(alive == false)
                    {
                        return;
                    }
                    Save();

                    Level = 143;
                }
            break;
            }
            case 143:
            {
                LevelScreen[0]  = "=======================================================================N=======\n";
                LevelScreen[1]  = "==============================THE SEA================================W + E=====\n";
                LevelScreen[2]  = "=======================MOUNTAINOUS COASTLINE===========================S=======\n";
                LevelScreen[3]  = "                                                                               \n";
                LevelScreen[4]  = "  The dragon takes off in an attempt to launch a final attack!                 \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[4]  = "  However, it lost too much energy in the battle that it can't maintain its    \n";
                LevelScreen[5]  = "  altitude and it comes crashing down into the side of your boat...            \n";

                drawScreen(LevelScreen, 32);

                system("PAUSE");

                LevelScreen[4]  = "  The waves created by the dragon landing in the sea push your boat further    \n";
                LevelScreen[5]  = "  from the coast and out into the open sea. The boat takes on water and begins \n";
                LevelScreen[6]  = "  to sink...                                                                   \n";

                drawScreen(LevelScreen, 32);
                system("PAUSE");

                LevelScreen[4]  = "                                                                               \n";
                LevelScreen[5]  = "                                                                               \n";
                LevelScreen[6]  = "                                                                               \n";
                LevelScreen[7]  = "                               To be continued...                              \n";

                drawScreen(LevelScreen, 32);
                system("PAUSE");

                LevelScreen[7]  = "                       You have completed TextQuest II.                       \n";


                drawScreen(LevelScreen, 32);

                system("PAUSE");

                return;

            break;
            }
        }
    }
}

//===================================================================================================================================================
//=============================================MAIN FUNCTION=========================================================================================
//===================================================================================================================================================

int main()
{
    srand((unsigned)time(NULL));

    int choice;

    bool SaveYN;

    int Game = 1;

    while(Game == 1)
    {
        drawScreen(TitleScreen, 25);
        //system("PAUSE");
        cin.sync();

        cin >> choice;

        switch(choice)
        {

            case 1:

                Level = 0;
                StartGame();
                if(CharacterStats[0][0] != 0 || CharacterStats[1][0] != 0 || CharacterStats[2][0] != 0)
                {
                    cout << endl << "Would you like to save? ";

                    SaveYN = YesNo();

                    if(SaveYN == true)
                    {
                        Save();
                    }
                }
                else
                {
                    cout << "You have been defeated...\n\n";

                    system("PAUSE");
                }
                Reset();
                ResetMaps();

            break;

            case 2:

                LoadGame(nCC, Level, Dock, DockHouse, HasSpoon, Room00, Throne, LibraryTime, BlackKnight,
                         Puzzle0Solved, Puzzle1Solved, Riddle0Solved, Riddle1Solved, Riddle2Solved,
                         trapA, trapB, trapC, trapD, trapE, trapF, trapG, trapH, trapI,
                         CharacterInfo, CharacterStats, CharacterInventory, Keys,
                         CampItems, Room01Items, Room03Items, Room12Items, WizardTower0Items, WizardTower2Items,
                         TrainingDummy, Goblin, BowGoblin, BarrackGoblins, LibraryGoblin, LibraryGoblins, CaveTroll, SleepingQSkeleton, ArmourySkeleton, GuardSkeletons, LibrarySkeleton, GMTFHellHound, GMTFSkeletonA, GMTFSkeletonB, GMTFGoblins, GMTFTrollCrew,
                         GMUMTroll, GMUMTrolls, GMUMSkeletons, GMLMTroll, GMBFSkeletonA, GMBFSkeletonB, GMBFHellHoundPack, GMBFHellHound,
                         GMBFOgre, GMBFDragon, Warlock, Wizard, PiratesA, PiratesB, WeakDragon,
                         PlayerMap0, PlayerMap1, PlayerMap2, PlayerMap3, PlayerMap4, PlayerMap5, PlayerMap6, PlayerMap7, PlayerMap8, WarlockDenMap, SpoonTroveMap, WizardTowerMap0, WizardTowerMap1, WizardTowerMap2);

                StartGame();

                  if(CharacterStats[0][0] != 0 || CharacterStats[1][0] != 0 || CharacterStats[2][0] != 0)
                  {
                        cout << endl << "Would you like to save? ";

                        SaveYN = YesNo();

                        if(SaveYN == true)
                        {
                            Save();
                        }
                  }
                  else
                  {
                      cout << "You have been defeated...\n\n";

                      system("PAUSE");
                  }

                Reset();
                ResetMaps();

            break;

            case 3:

                info();
            break;

            case 4:

                Game = 0;

            break;

            default:

                cout << "Unrecognised command!" << endl;
                cout << "Please enter again!" << endl;
                system("PAUSE");

            break;
        }
    }
    return 0;
}
