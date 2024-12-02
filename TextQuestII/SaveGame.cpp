#include <string>
#include <fstream>

using namespace std;

void SaveGame(int nCC, int Level, bool Dock, bool DockHouse, bool HasSpoon, int Room00, int Throne, int LibraryTime, int BlackKnight,
                bool Puzzle0Solved, bool Puzzle1Solved, bool Riddle0Solved, bool Riddle1Solved, bool Riddle2Solved,
                 bool trapA, bool trapB, bool trapC, bool trapD, bool trapE, bool trapF, bool trapG, bool trapH, bool trapI,
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

    ofstream savegame;
    ofstream savemaps;

    savegame.open("save.tqs");
//===================================================================================================================================================
//====================================nCC VALUE======================================================================================================
//===================================================================================================================================================

    savegame << nCC << endl;

//===================================================================================================================================================
//====================================LEVEL VALUE====================================================================================================
//===================================================================================================================================================

    savegame << Level << endl;

    savegame << Dock << endl;

    savegame << DockHouse << endl;

    savegame << HasSpoon << endl;

//===================================================================================================================================================
//===================================ROOM 0 0 VALUE==================================================================================================
//===================================================================================================================================================

    savegame << Room00 << endl;

//===================================================================================================================================================
//====================================THRONE ROOM PASSAGE============================================================================================
//===================================================================================================================================================

    savegame << Throne << endl;

//===================================================================================================================================================
//====================================LIBRARY UPGRADE TIME===========================================================================================
//===================================================================================================================================================

    savegame << LibraryTime << endl;

//===================================================================================================================================================
//====================================BLACK KNIGHT DISPOSITION=======================================================================================
//===================================================================================================================================================

    savegame << BlackKnight << endl;

//===================================================================================================================================================
//====================================SOLVED PUZZLES=================================================================================================
//===================================================================================================================================================

    savegame << Puzzle0Solved << endl;

    savegame << Puzzle1Solved << endl;

//===================================================================================================================================================
//====================================SOLVED RIDDLES=================================================================================================
//===================================================================================================================================================

    savegame << Riddle0Solved << endl;

    savegame << Riddle1Solved << endl;

    savegame << Riddle2Solved << endl;

//===================================================================================================================================================
//=======================================TRAPS=======================================================================================================
//===================================================================================================================================================

    savegame << trapA << endl;

    savegame << trapB << endl;

    savegame << trapC << endl;

    savegame << trapD << endl;

    savegame << trapE << endl;

    savegame << trapF << endl;

    savegame << trapG << endl;

    savegame << trapH << endl;

    savegame << trapI << endl;

    savegame.close();
//===================================================================================================================================================
//===================================CHARACTER ARRAYS================================================================================================
//===================================================================================================================================================

    savegame.open("charactersave.tqs");

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 3; j ++)
        {
            savegame << CharacterInfo[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 7; j ++)
        {
            savegame << CharacterStats[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 14; j ++)
        {
            savegame << CharacterInventory[i][j] << endl;
        }
    }
    for(i = 0; i < 4; i ++)
    {
        savegame << Keys[i] << endl;
    }

    savegame.close();
//===================================================================================================================================================
//=================================LOCATION ARRAYS===================================================================================================
//===================================================================================================================================================
    savegame.open("worldsave.tqs");


    for(i = 0; i < 14; i++)
    {
        savegame << CampItems[i] << endl;
    }

    for(i = 0; i < 14; i ++)
    {
        savegame << Room01Items[i] << endl;
    }

    for(i = 0; i < 14; i ++)
    {
        savegame << Room03Items[i] << endl;
    }

    for(i = 0; i < 14; i ++)
    {
        savegame << Room12Items[i] << endl;
    }

    for(i = 0; i < 14; i ++)
    {
        savegame << WizardTower0Items[i] << endl;
    }

    for(i = 0; i < 14; i ++)
    {
        savegame << WizardTower2Items[i] << endl;
    }
//===================================================================================================================================================
//==================================ENEMY ARRAYS=====================================================================================================
//===================================================================================================================================================

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << TrainingDummy[i][j] << endl;
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << Goblin[i][j] << endl;
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << BowGoblin[i][j] << endl;
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << BarrackGoblins[i][j] << endl;
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << LibraryGoblin[i][j] << endl;
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << LibraryGoblins[i][j] << endl;
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << CaveTroll[i][j] << endl;
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << SleepingQSkeleton[i][j] << endl;
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << ArmourySkeleton[i][j] << endl;
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GuardSkeletons[i][j] << endl;
        }
    }

    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << LibrarySkeleton[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GMTFHellHound[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GMTFSkeletonA[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GMTFSkeletonB[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GMTFGoblins[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GMTFTrollCrew[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GMUMTroll[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GMUMTrolls[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GMUMSkeletons[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GMLMTroll[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GMBFSkeletonA[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GMBFSkeletonB[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GMBFHellHoundPack[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GMBFHellHound[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GMBFOgre[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << GMBFDragon[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << Warlock[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << Wizard[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << PiratesA[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << PiratesB[i][j] << endl;
        }
    }
    for(i = 0; i < 3; i ++)
    {
        for(j = 0; j < 8; j ++)
        {
            savegame << WeakDragon[i][j] << endl;
        }
    }

    savegame.close();
//===================================================================================================================================================
//==================================PLAYER MAPS======================================================================================================
//===================================================================================================================================================
    savemaps.open("mapsave.tqs");

    for(i = 0; i < 15; i ++)
    {
        savemaps << PlayerMap0[i];
    }

    for(i = 0; i < 17; i ++)
    {
        savemaps << PlayerMap1[i];
    }

    for(i = 0; i < 19; i ++)
    {
        savemaps << PlayerMap2[i];
    }

    for(i = 0; i < 14; i ++)
    {
        savemaps << PlayerMap3[i];
    }

    for(i = 0; i < 15; i ++)
    {
        savemaps << PlayerMap4[i];
    }

    for(i = 0; i < 20; i ++)
    {
        savemaps << PlayerMap5[i];
    }

    for(i = 0; i < 18; i ++)
    {
        savemaps << PlayerMap6[i];
    }
    for(i = 0; i < 20; i ++)
    {
        savemaps << PlayerMap7[i];
    }
    for(i = 0; i < 15; i ++)
    {
        savemaps << PlayerMap8[i];
    }

    for(i = 0; i < 5; i ++)
    {
        savemaps << WarlockDenMap[i];
    }
    for(i = 0; i < 5; i ++)
    {
        savemaps << SpoonTroveMap[i];
    }
    for(i = 0; i < 9; i ++)
    {
        savemaps << WizardTowerMap0[i];
    }
    for(i = 0; i < 9; i ++)
    {
        savemaps << WizardTowerMap1[i];
    }
    for(i = 0; i < 9; i ++)
    {
        savemaps << WizardTowerMap2[i];
    }
//===================================================================================================================================================
//==================================CLOSE FILESTREAM=================================================================================================
//===================================================================================================================================================

    savemaps.close();
}
