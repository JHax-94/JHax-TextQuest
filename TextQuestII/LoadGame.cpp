#include<string>
#include<fstream>
#include<cstdlib>
#include<iostream>

using namespace std;

void LoadGame(int& nCC, int& Level, bool& Dock, bool& DockHouse, bool& HasSpoon, int& Room00, int& Throne, int& LibraryTime, int& BlackKnight,
              bool& Puzzle0Solved, bool& Puzzle1Solved, bool& Riddle0Solved, bool& Riddle1Solved, bool& Riddle2Solved,
              bool& trapA, bool& trapB, bool& trapC, bool& trapD, bool& trapE, bool& trapF, bool& trapG, bool&trapH, bool& trapI,
              string CharacterInfo[3][3], int CharacterStats[3][7], int CharacterInventory[3][14], int Keys[],
              int CampItems[14], int Room01Items[14], int Room03Items[14], int Room12Items[14], int WizardTower0Items[14], int WizardTower2Items[14],
              int TrainingDummy[3][8], int Goblin[3][8], int BowGoblin[3][8], int BarrackGoblins[3][8], int LibraryGoblin[3][8],
              int LibraryGoblins[3][8], int CaveTroll[3][8], int SleepingQSkeleton[3][8], int ArmourySkeleton[3][8], int GuardSkeletons[3][8],
              int LibrarySkeleton[3][8], int GMTFHellHound[3][8], int GMTFSkeletonA[3][8], int GMTFSkeletonB[3][8], int GMTFGoblins[3][8], int GMTFTrollCrew[3][8],
              int GMUMTroll[3][8], int GMUMTrolls[3][8], int GMUMSkeletons[3][8], int GMLMTroll[3][8], int GMBFSkeletonA[3][8], int GMBFSkeletonB[3][8],
              int GMBFHellHoundPack[3][8], int GMBFHellHound[3][8], int GMBFOgre[3][8], int GMBFDragon[3][8], int Warlock[3][8], int Wizard[3][8],
              int PiratesA[3][8], int PiratesB[3][8], int WeakDragon[3][8],
              string PlayerMap0[], string PlayerMap1[], string PlayerMap2[], string PlayerMap3[], string PlayerMap4[], string PlayerMap5[], string PlayerMap6[], string PlayerMap7[], string PlayerMap8[], string WarlockDenMap[], string SpoonTroveMap[], string WizardTowerMap0[], string WizardTowerMap1[], string WizardTowerMap2[])
{
    int i;
    int j;

    string TempLine;

    ifstream loadgame;
    ifstream loadmaps;

    loadgame.open("save.tqs");
//===================================================================================================================================================
//====================================nCC VALUE======================================================================================================
//===================================================================================================================================================

    loadgame >> nCC;

//===================================================================================================================================================
//====================================LEVEL VALUE====================================================================================================
//===================================================================================================================================================

    loadgame >> Level;

    loadgame >> Dock;

    loadgame >> DockHouse;

    loadgame >> HasSpoon;

//===================================================================================================================================================
//====================================ROOM 0 0 VALUE=================================================================================================
//===================================================================================================================================================

    loadgame >> Room00;

//===================================================================================================================================================
//====================================THRONE ROOM PASSAGE============================================================================================
//===================================================================================================================================================

    loadgame >> Throne;

//===================================================================================================================================================
//====================================LIBRARY TIME===================================================================================================
//===================================================================================================================================================

    loadgame >> LibraryTime;

    loadgame >> BlackKnight;

//===================================================================================================================================================
//====================================SOLVED PUZZLES=================================================================================================
//===================================================================================================================================================

    loadgame >> Puzzle0Solved;

    loadgame >> Puzzle1Solved;

//===================================================================================================================================================
//====================================SOLVED RIDDLES=================================================================================================
//===================================================================================================================================================

    loadgame >> Riddle0Solved;

    loadgame >> Riddle1Solved;

    loadgame >> Riddle2Solved;

//===================================================================================================================================================
//====================================SOLVED RIDDLES=================================================================================================
//===================================================================================================================================================

    loadgame >> trapA;

    loadgame >> trapB;

    loadgame >> trapC;

    loadgame >> trapD;

    loadgame >> trapE;

    loadgame >> trapF;

    loadgame >> trapG;

    loadgame >> trapH;

    loadgame >> trapI;

    loadgame.close();
//===================================================================================================================================================
//===================================CHARACTER ARRAYS================================================================================================
//===================================================================================================================================================
    loadgame.open("charactersave.tqs");

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 3; j ++)
        {
            loadgame >> CharacterInfo[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 7; j ++)
        {
            loadgame >> CharacterStats[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 14; j ++)
        {
            loadgame >> CharacterInventory[i][j];
        }
    }
    for(i = 0; i < 4; i ++)
    {
        loadgame >> Keys[i];
    }

    loadgame.close();
//===================================================================================================================================================
//=================================LOCATION ARRAYS===================================================================================================
//===================================================================================================================================================
    loadgame.open("worldsave.tqs");

    for(i = 0; i < 14; i++)
    {
        loadgame >> CampItems[i];
    }

    for(i = 0; i < 14; i++)
    {
        loadgame >> Room01Items[i];
    }

    for(i = 0; i < 14; i ++)
    {
        loadgame >> Room03Items[i];
    }

    for(i = 0; i < 14; i ++)
    {
        loadgame >> Room12Items[i];
    }

    for(i = 0; i < 14; i ++)
    {
        loadgame >> WizardTower0Items[i];
    }
    for(i = 0; i < 14; i ++)
    {
        loadgame >> WizardTower2Items[i];
    }

//===================================================================================================================================================
//==================================ENEMY ARRAYS=====================================================================================================
//===================================================================================================================================================

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> TrainingDummy[i][j];
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> Goblin[i][j];
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> BowGoblin[i][j];
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> BarrackGoblins[i][j];
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> LibraryGoblin[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> LibraryGoblins[i][j];
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j++)
        {
            loadgame >> CaveTroll[i][j];
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> SleepingQSkeleton[i][j];
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> ArmourySkeleton[i][j];
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GuardSkeletons[i][j];
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> LibrarySkeleton[i][j];
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GMTFHellHound[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GMTFSkeletonA[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GMTFSkeletonB[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GMTFGoblins[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GMTFTrollCrew[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GMUMTroll[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GMUMTrolls[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GMUMSkeletons[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GMLMTroll[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GMBFSkeletonA[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GMBFSkeletonB[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GMBFHellHoundPack[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GMBFHellHound[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GMBFOgre[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> GMBFDragon[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> Warlock[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> Wizard[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> PiratesA[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> PiratesB[i][j];
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            loadgame >> WeakDragon[i][j];
        }
    }



    loadgame.close();
//===================================================================================================================================================
//==================================PLAYER MAPS======================================================================================================
//===================================================================================================================================================
    loadmaps.open("mapsave.tqs");

    for(i = 0; i < 15; i ++)
    {
        loadmaps.sync();

        getline(loadmaps, TempLine);
        PlayerMap0[i].replace(0, 79, TempLine);

    }
    for(i = 0; i < 17; i ++)
    {
        loadmaps.sync();

        getline(loadmaps, TempLine);
        PlayerMap1[i].replace(0, 79, TempLine);
    }

    for(i = 0; i < 19; i ++)
    {
        loadmaps.sync();

        getline(loadmaps, TempLine);
        PlayerMap2[i].replace(0, 79, TempLine);
    }
    for(i = 0; i < 14; i ++)
    {
        loadmaps.sync();

        getline(loadmaps, TempLine);
        PlayerMap3[i].replace(0, 79, TempLine);
    }

    for(i = 0; i < 15; i ++)
    {
        loadmaps.sync();

        getline(loadmaps, TempLine);
        PlayerMap4[i].replace(0, 79, TempLine);
    }
    for(i = 0; i < 20; i ++)
    {
        loadmaps.sync();

        getline(loadmaps, TempLine);
        PlayerMap5[i].replace(0, 79, TempLine);
    }
    for(i = 0; i < 18; i ++)
    {
        loadmaps.sync();

        getline(loadmaps, TempLine);
        PlayerMap6[i].replace(0, 79, TempLine);
    }
    for(i = 0; i < 20; i ++)
    {
        loadmaps.sync();

        getline(loadmaps, TempLine);
        PlayerMap7[i].replace(0, 79, TempLine);
    }
    for(i = 0; i < 15; i ++)
    {
        loadmaps.sync();

        getline(loadmaps, TempLine);
        PlayerMap8[i].replace(0, 79, TempLine);
    }
    for(i = 0; i < 5; i ++)
    {
        loadmaps.sync();

        getline(loadmaps, TempLine);
        WarlockDenMap[i].replace(0, 79, TempLine);
    }
    for(i = 0; i < 5; i ++)
    {
        loadmaps.sync();

        getline(loadmaps, TempLine);
        SpoonTroveMap[i].replace(0, 79, TempLine);
    }
    for(i = 0; i < 9; i ++)
    {
        loadmaps.sync();

        getline(loadmaps, TempLine);
        WizardTowerMap0[i].replace(0, 79, TempLine);
    }
    for(i = 0; i < 9; i ++)
    {
        loadmaps.sync();

        getline(loadmaps, TempLine);
        WizardTowerMap1[i].replace(0, 79, TempLine);
    }
    for(i = 0; i < 9; i ++)
    {
        loadmaps.sync();

        getline(loadmaps, TempLine);
        WizardTowerMap2[i].replace(0, 79, TempLine);
    }

//===================================================================================================================================================
//==================================CLOSE FILESTREAM=================================================================================================
//===================================================================================================================================================

    system("PAUSE");

    loadgame.close();
}
