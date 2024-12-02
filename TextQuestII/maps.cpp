#include<string>
#include<cstdlib>

using namespace std;

#include"screens.h"

//===================================================================================================================================================
// LEVEL 0
//===================================================================================================================================================

int LevelSize0 = 15;

string Level0[] =
{
        "                           _ _ _            _                                  \n",
        "              |   |_ _ _ _|     |          | |                                 \n",
        "              |    _ _ _ _      |          | |                                 \n",
        "       _ _    |   |       |_ _ _|     _ _ _| |_ _       _ _ _                  \n",
        "      |   |_ _|   |                  |           |_ _ _|     |                 \n",
        "      |    _ _    |        _ _ _     |            _ _ _      |                 \n",
        " _ _ _|_ _|   |   |_ _ _ _|     |    |_ _ _   _ _|     |_ _ _|                 \n",
        "|     |_ _ _ _|    _ _ _ _      |          | |                                 \n",
        "|      _ _ _ _    |       |_ _ _|          | |                                 \n",
        "|_ _ _|       |   |_ _ _ _ _ _ _ _ _ _ _ _ | |                                 \n",
        "              |_ _ _ _ _ _ _ _ _ _ _ _ _ _   |                                 \n",
        "                                           | |                                 \n",
        "                                           | |                                 \n",
        "                                           | |                                 \n",
        "                                           |=| \\/                              \n"
};



//===================================================================================================================================================
// LEVEL 1
//===================================================================================================================================================

int LevelSize1 = 17;

string Level1[] =
{
       "     |===| \\/                              |=| /\\                              \n",
       "     |   |                                 | |                                 \n",
       "     |   |                _ _ _ _          | |                                 \n",
       "     |   |               |       |         | |                                 \n",
       "     |   |               |       |         | |                                 \n",
       "     |   |               |_     _|         | |                                 \n",
       "     |   |                 |   |           | |                                 \n",
       "     |   |                 |   |           | |                                 \n",
       "     |   |                _|   |_          | |                                 \n",
       "     |   |_ _ _ _ _ _ _ _|       |_ _ _ _ _| |                                 \n",
       "     |    _ _ _ _ _ _ _ _         _ _ _ _ _  |                                 \n",
       "     |   |               |       |         | |                                 \n",
       "     |   |               |_ _ _ _|         | |                                 \n",
       "    _|   |_                                |_|                                 \n",
       "   |       |                                                                   \n",
       "   |       |                                                                   \n",
       "   |_ _ _ _|                                                                   \n"
};

//===================================================================================================================================================
// LEVEL 2
//===================================================================================================================================================

int LevelSize2 = 19;

string Level2[] =
{
    "     |===| /\\                                                                  \n",
    "     |   |                                                                     \n",
    "     |   |              _ _ _                                                  \n",
    "     |   |             |     |                                                 \n",
    "     |   |_ _ _ _ _ _ _|     |                                                 \n",
    "     |    _ _ _ _ _ _ _      |_ _ _ _                                          \n",
    "     |   |             |     |       |                                         \n",
    "     |   |             |_ _ _|_ _    |                                         \n",
    "     |   |                       |   |                                         \n",
    "    _|   |_                      |   |                                         \n",
    "   |       |                     |   |                                         \n",
    "   |       |_ _ _ _ _ _ _ _ _ _ _|   |                                         \n",
    "   |  _ _  |_ _ _ _ _ _ _ _ _ _ _    |                                         \n",
    "   |_|_ _|_|                     |   |                                         \n",
    "                                 |   |                                         \n",
    "                                 |   |                                         \n",
    "                                 \\   /                                         \n",
    "                                  | |                                          \n",
    "                                  |=| \\/                                       \n"
};

//===================================================================================================================================================
// LEVEL 3
//===================================================================================================================================================

int LevelSize3 = 14;

string Level3[] =
{
    "                                 |=|  /\\                                       \n",
    "   |=| /\\                        | |                                           \n",
    "   | |                           | |                                           \n",
    "   | |                           | |                                           \n",
    "   | |                           | |                                           \n",
    "   |_|_ _ _ _ _ _ _ _ _ _ _ _ _ _| |                                           \n",
    "   |                               |                                           \n",
    "   |   ||    ||        ||   ||     |                                           \n",
    "   |   ||    ||        ||   ||     |                                           \n",
    "   |                               |                                           \n",
    "   |   ||    ||        ||   ||     |                                           \n",
    "   |   ||    ||        ||   ||     |                                           \n",
    "   |  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|                                           \n",
    "   |=| \\/                                                                      \n"
};
//===================================================================================================================================================
// WARLOCK DEN
//===================================================================================================================================================

int WarlockDenSize = 5;
string WarlockDen[] =
{
    "         _ _ _ _ _ _ _                                                         \n",
    "        |             |                                                        \n",
    "        |             |                                                        \n",
    "        |_ _ _   _ _ _|                                                        \n",
    "              |=| \\/                                                           \n"
};

//===================================================================================================================================================
// LEVEL 4 MAZE 1
//===================================================================================================================================================

int LevelSize4 = 15;

string Level4[] =
{
    "                                                           _ _                 \n",
    "                                         _ _ _ _ _ _ _ _ _|   |                \n",
    "                        |=|/\\           |  _ _ _ _ _ _ _ _    |                \n",
    "         _              | |             | |               |_ _|                \n",
    "        | |             | |             | |                  _                 \n",
    " _      | |             | |             | |                 | |                \n",
    "| |_ _ _| |_ _ _ _ _ _ _| |_ _ _ _ _ _ _| |_                | |                \n",
    "|  _ _ _   _ _ _ _ _ _ _ _ _ _ _ _   _ _    |               | |                \n",
    "|_|     | |     |_   _|           | |   |_ _|               | |                \n",
    "        | |       | |             | |_ _ _ _ _ _ _ _ _ _ _ _| |                \n",
    "        | |_ _ _ _| |_ _ _ _ _ _ _|    _ _ _ _ _ _ _ _ _ _    |                \n",
    "        |_ _ _ _ _ _ _ _ _ _ _ _  |_ _|      _ _ _        |_ _|                \n",
    "                       _ _ _ _ _| |_ _ _ _ _|     |                            \n",
    "                      |  _ _ _ _ _ _ _ _ _ _      |                            \n",
    "                      |=|\\/                 |_ _ _|                            \n"
};

//===================================================================================================================================================
// LEVEL 5 MAZE 2
//===================================================================================================================================================

int LevelSize5 = 20;

string Level5[] =
{
    "          |=| /\\                                                               \n",
    "          | |                                                                  \n",
    "          | |                                                                  \n",
    "          | |              _ _                                                 \n",
    " _ _ _ _ _| |_ _ _ _ _ _ _|   |                                                \n",
    "| |_ _ _ _   _ _ _ _ _ _ _    |                                                \n",
    "| |       | |             |_ _|_ _                                             \n",
    "| |       | |             |       |                                            \n",
    "| |       | |             |_   _ _|                                            \n",
    "| |       | |               | |                                                \n",
    "| |       | |_ _ _ _ _ _ _ _| |_ _ _ _ _ _ _                                   \n",
    "|=| \\/    |      _ _ _ _ _ _ _ _ _ _ _ _ _  |                                  \n",
    "          |_ _ _|           | |           | |                                  \n",
    "               _ _ _ _ _ _ _| |_ _ _ _ _ _| |                                  \n",
    "              |  _ _ _ _ _ _   _ _ _ _ _    |                                  \n",
    "              | |           | |         |_ _|                                  \n",
    "              | |           | |                                                \n",
    "           _ _| |           | |_ _ _ _ _ _ _ _ _|=| \\/                         \n",
    "          |     |           |_ _ _ _ _ _ _ _ _ _ _|                            \n",
    "          |_ _ _|                                                              \n"
};

//===================================================================================================================================================
// RUSTY SPOON TROVE
//===================================================================================================================================================

int SpoonTroveSize = 5;

string SpoonTrove[] =
{
    "             |=| /\\                                                            \n",
    "      _ _ _ _| |_ _ _ _ _                                                      \n",
    "     |                   |                                                     \n",
    "     |                   |                                                     \n",
    "     |_ _ _ _ _ _ _ _ _ _|                                                     \n"
};

//===================================================================================================================================================
// LEVEL 6 MAZE 3
//===================================================================================================================================================

int LevelSize6 = 18;

string Level6[] =
{
    "        |=| /\\                      |=| /\\                                     \n",
    "       _| |_                       _| |_ _ _                                   \n",
    "      |     |_ _ _ _ _ _ _ _ _ _ _|         |                                  \n",
    "      |      _ _ _ _ _ _ _ _ _ _|_          |                                  \n",
    " _ _ _|_   _|                     |_   _ _ _|                                  \n",
    "|     | | |                        _| |_ _ _                                   \n",
    "|_   _| | |_ _ _ _                |         |                                  \n",
    "  | |   |_ _ _ _  |               |_ _ _ _ _|                                  \n",
    "  | |           | |                                                            \n",
    "  | |_ _ _ _ _ _| |_ _ _ _ _ _ _ _                                             \n",
    "  |_ _ _ _ _ _       _ _ _ _ _ _  |                                            \n",
    "    |_   _|   |_ _ _|           | |                                            \n",
    "      | |     | |               | |                                            \n",
    "      | |     | |               | |                                            \n",
    "      | |_ _ _| |_ _ _ _ _ _ _ _| |_                                           \n",
    "      |  _ _ _ _ _ _ _ _ _ _ _      |                                          \n",
    "      | |                     |_ _ _|                                          \n",
    "      |=| \\/                                                                  \n"
};

//===================================================================================================================================================
// WIZARD'S TOWER 0
//===================================================================================================================================================

int WizardTowerSize = 9;


string WizardTower0[] =
{
    "     _ _ _ _ _                                                               \n",
    "    /   4   3 \\                                                             \n",
    "   /           \\                                                            \n",
    "  |  ||  ||   |=| /\\                                                        \n",
    "  |  || 5||    2|                                                            \n",
    "  |  ||  ||     |                                                            \n",
    "   \\           /                                                             \n",
    "    \\_ _0_ _1_/                                                              \n",
    "        |=| \\/                                                                \n"
};

//===================================================================================================================================================
// WIZARD'S TOWER 1
//===================================================================================================================================================

string WizardTower1[] =
{
    "      _ _ _ _ _                                                              \n",
    "     /         \\                                                             \n",
    "    /           \\                                                            \n",
    "   |    _ _    |=| \\/                                                        \n",
    "   | 2 |   | 1  0|                                                            \n",
    " /\\|=| |_ _|     |                                                            \n",
    "    \\           /                                                             \n",
    "     \\_ _ _ _ _/                                                              \n",
    "                                                                              \n"
};

//===================================================================================================================================================
// WIZARD'S TOWER 2
//===================================================================================================================================================

string WizardTower2[] =
{
    "      _ _ _ _ _                                                                \n",
    "     /         \\                                                               \n",
    "    /           \\                                                              \n",
    "   |             |                                                              \n",
    "   |      0      |                                                             \n",
    " \\/|=|           |                                                             \n",
    "    \\           /                                                              \n",
    "     \\_ _ _ _ _/                                                               \n",
    "                                                                                \n"
};

//===================================================================================================================================================
// LEVEL 7 MAP 4
//===================================================================================================================================================

int LevelSize7 = 20;


string Level7[] =
{
    "                                     _ _ _                                     \n",
    "|=|      _ _ _ _ _ _ _ _ _ _ _ _ _ _|     |                                    \n",
    "| |     |  _ _ _ _   _ _ _ _ _ _ _ _      |                                    \n",
    "| |     | |       | |               |_   _|                                    \n",
    "| |_ _ _| |_ _    | |                 | |                                      \n",
    "| |           |   | |                 | |                                      \n",
    "| |_ _ _ _ _ _|   | |                 | |                                      \n",
    "| |               | |_                | |                                      \n",
    "| |_ _ _ _ _ _ _ _|   |               | |                                      \n",
    "|      _ _ _ _ _ _ _ _|               | |                                      \n",
    "|_ _ _|            _ _ _ _ _ _ _ _ _ _| |                                      \n",
    "                  |  _ _ _ _ _ _ _ _ _ _|                                      \n",
    "                  | |                                                          \n",
    "           _ _ _ _| |_ _ _ _ _ _                                               \n",
    "          |                     |                                              \n",
    "          |                     |                                              \n",
    "          |                     |                                              \n",
    "          |_ _ _ _ _ _ _ _ _ _ _|                                              \n",
    "                  | |                                                          \n",
    "                  | |                                                          \n"
};

//===================================================================================================================================================
//LEVEL 8 DOCK
//===================================================================================================================================================

int LevelSize8 = 15;

string Level8[] =
{
    "\\                                                                    /        \n",
    " \\_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ /         \n",
    "     .|                                               |\\ _ _/| .              \n",
    "     .|    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|/ _ _\\| .              \n",
    "     .|   |. . . . . . . . . . . . . . . . . . . . . . . . . . . .             \n",
    "     .|   |.                                                                   \n",
    "     .|   |.                                                                   \n",
    "     .|   |.                                                                   \n",
    "     .|_ _|.                                                                   \n",
    "       _ _ _ /|_ _ _ _                                                         \n",
    "     /      | |        \\                                                       \n",
    " _ _/   /|  | |    /|  |                                                       \n",
    "    \\   \\|  | |    \\|  |                                                       \n",
    "     \\ _ _ _| |_ _ _ _ /                                                       \n",
    "             \\|                                                                \n"
};



void GetMap(string Screen[], string PlayerMap[], int Floor, int Room)
{

    Screen[4].replace(2, 12, "CURRENT ROOM");
    Screen[5].replace(2, 12, "============");


    if(Floor == 0)
    {
        if(Room == 0)
        {
            Screen[7].replace(4, 6, "|   |_");
            Screen[8].replace(4, 6, "| X  _");
            Screen[9].replace(4, 6, "|   | ");

            PlayerMap[1].replace(14, 6, "|   |_");
            PlayerMap[2].replace(14, 6, "|    _");
            PlayerMap[3].replace(14, 6, "|   | ");
        }

        else if(Room == 1)
        {
             Screen[7].replace(2, 8, "  _ _ _ ");
             Screen[8].replace(2, 8, "_|     |");
             Screen[9].replace(2, 8, "_   X  |");
            Screen[10].replace(2, 8, " |_ _ _|");

            PlayerMap[0].replace(20, 13, "       _ _ _ ");
            PlayerMap[1].replace(20, 13, " _ _ _|     |");
            PlayerMap[2].replace(20, 13, " _ _ _      |");
            PlayerMap[3].replace(20, 13, "      |_ _ _|");
        }

        else if(Room == 2)
        {
            Screen[7].replace(2, 6, "_|   |");
            Screen[8].replace(2, 6, "_  X |");
            Screen[9].replace(2, 6, " |   |");

            PlayerMap[4].replace(13, 6, "_|   |");
            PlayerMap[5].replace(13, 6, "_    |");
            PlayerMap[6].replace(13, 6, " |   |");
        }

        else if(Room == 3)
        {
            Screen[7].replace(2, 6,  " _ _  ");
            Screen[8].replace(2, 6,  "|   |_");
            Screen[9].replace(2, 6,  "| X  _");
            Screen[10].replace(2, 6, "|_ _| ");

            PlayerMap[3].replace(6, 6, " _ _  ");
            PlayerMap[4].replace(6, 6, "|   |_");
            PlayerMap[5].replace(6, 6, "|    _");
            PlayerMap[6].replace(6, 6, "|_ _| ");
        }

        else if(Room == 4)
        {
            Screen[7].replace(2, 6, "|   |_");
            Screen[8].replace(2, 6, "| X  _");
            Screen[9].replace(2, 6, "    | ");

            PlayerMap[6].replace(14, 6, "|   |_");
            PlayerMap[7].replace(14, 6, "|    _");
            PlayerMap[8].replace(14, 6, "    | ");
        }

        else if(Room == 5)
        {
            Screen[7].replace(2, 8,  "  _ _ _ ");
            Screen[8].replace(2, 8,  "_|     |");
            Screen[9].replace(2, 8,  "_   X  |");
            Screen[10].replace(2, 8, " |_ _ _|");

            PlayerMap[5].replace(20, 13, "       _ _ _ ");
            PlayerMap[6].replace(20, 13, " _ _ _|     |");
            PlayerMap[7].replace(20, 13, " _ _ _      |");
            PlayerMap[8].replace(20, 13, "      |_ _ _|");
        }

        else if(Room == 6)
        {
            Screen[7].replace(2, 6,  "_|    ");
            Screen[8].replace(2, 6,  "_  X |");
            Screen[9].replace(2, 6,  " |   |");

            PlayerMap[7].replace(13, 6, "_|    ");
            PlayerMap[8].replace(13, 6, "_    |");
            PlayerMap[9].replace(13, 6, " |   |");
        }

        else if(Room == 7)
        {
            Screen[7].replace(2, 6,  " _ _ _");
            Screen[8].replace(2, 8,  "|     |_");
            Screen[9].replace(2, 8,  "|  X   _");
            Screen[10].replace(2, 8, "|_ _ _| ");

            PlayerMap[6].replace(0, 6, " _ _ _");
            PlayerMap[7].replace(0, 13,"|     |_ _ _ ");
            PlayerMap[8].replace(0, 13,"|      _ _ _ ");
            PlayerMap[9].replace(0, 13,"|_ _ _|      ");
        }
        else if(Room == 8)
        {
            Screen[7].replace(2, 6, "|   |_");
            Screen[8].replace(2, 6, "|_X_ _");

            PlayerMap[9].replace(14, 6,  "|   |_");
            PlayerMap[10].replace(14, 6, "|_ _ _");
        }
        else if(Room == 9)
        {
            Screen[7].replace(2, 5, "_ | |");
            Screen[8].replace(2, 5, "_  X|");
            Screen[9].replace(2, 5, "  | |");

            PlayerMap[9].replace(20, 26,  " _ _ _ _ _ _ _ _ _ _ _ | |");
            PlayerMap[10].replace(20, 26, " _ _ _ _ _ _ _ _ _ _ _   |");
            PlayerMap[11].replace(20, 26, "                       | |");
        }
        else if(Room == 10)
        {
            Screen[7].replace(2, 14,  " _ _ _| |_ _  ");
            Screen[8].replace(2, 14,  "|           |_");
            Screen[9].replace(2, 14,  "|      X     _");
            Screen[10].replace(2, 14, "|_ _ _   _ _| ");
            Screen[11].replace(2, 14, "      | |     ");

            PlayerMap[3].replace(37, 14, " _ _ _| |_ _  ");
            PlayerMap[4].replace(37, 14, "|           |_");
            PlayerMap[5].replace(37, 14, "|            _");
            PlayerMap[6].replace(37, 14, "|_ _ _   _ _| ");
            PlayerMap[7].replace(43, 3,        "| |");
            PlayerMap[8].replace(43, 3,        "| |");
        }
        else if(Room == 11)
        {
            Screen[7].replace(2, 5, "  _  ");
            Screen[8].replace(2, 5, " |X| ");
            Screen[9].replace(2, 5, " | | ");

            PlayerMap[0].replace(43, 3, " _ ");
            PlayerMap[1].replace(43, 3, "| |");
            PlayerMap[2].replace(43, 3, "| |");
        }
        else if(Room == 12)
        {
            Screen[7].replace(2, 8,  "  _ _ _ ");
            Screen[8].replace(2, 8,  "_|     |");
            Screen[9].replace(2, 8,  "_   X  |");
            Screen[10].replace(2, 8, " |_ _ _|");

            PlayerMap[3].replace(51, 11, "     _ _ _ ");
            PlayerMap[4].replace(51, 11, " _ _|     |");
            PlayerMap[5].replace(51, 11, " _ _      |");
            PlayerMap[6].replace(51, 11, "    |_ _ _|");
        }
        else if(Room == 13)
        {
            Screen[7].replace(2, 8, "| |     ");
            Screen[8].replace(2, 8, "|X|     ");
            Screen[9].replace(2, 8, "|=| \\/ ");

            PlayerMap[12].replace(43, 8, "| |     ");
            PlayerMap[13].replace(43, 8, "| |     ");
            PlayerMap[14].replace(43, 8, "|=| \\/ ");
        }
    }
    else if(Floor == 1)
    {
        if(Room == 0)
        {
            Screen[7].replace(2, 7, "|=| /\\");
            Screen[8].replace(2, 3, "|X|");
            Screen[9].replace(2, 3, "| |");

            PlayerMap[0].replace(43, 7, "|=| /\\");
            PlayerMap[1].replace(43, 3, "| |");
            PlayerMap[2].replace(43, 3, "| |");
        }
        else if(Room == 1)
        {
            Screen[7].replace(2, 4, "_| |");
            Screen[8].replace(2, 4, "_ X|");
            Screen[9].replace(2, 4, " | |");

            PlayerMap[3].replace(43, 3,   "| |");
            PlayerMap[4].replace(43, 3,   "| |");
            PlayerMap[5].replace(43, 3,   "| |");
            PlayerMap[6].replace(43, 3,   "| |");
            PlayerMap[7].replace(43, 3,   "| |");
            PlayerMap[8].replace(43, 3,   "| |");
            PlayerMap[9].replace(42, 4,  "_| |");
            PlayerMap[10].replace(42, 4, "_  |");
            PlayerMap[11].replace(42, 4, " | |");
        }
        else if(Room == 2)
        {
            Screen[7].replace(2, 11,  "  _|   |_  ");
            Screen[8].replace(2, 11,  "_|       |_");
            Screen[9].replace(2, 11,  "_    X    _");
            Screen[10].replace(2, 11, " |       | ");
            Screen[11].replace(2, 11, " |_ _ _ _| ");

            PlayerMap[8].replace(24, 11,  "  _|   |_  ");
            PlayerMap[9].replace(24, 17,  "_|       |_ _ _ _");
            PlayerMap[10].replace(24, 17, "_         _ _ _ _");
            PlayerMap[11].replace(24, 11, " |       | ");
            PlayerMap[12].replace(24, 11, " |_ _ _ _| ");
        }
        else if(Room == 3)
        {
            Screen[7].replace(2, 3, "| |");
            Screen[8].replace(2, 3, "|X|");
            Screen[9].replace(2, 3, "|_|");

            PlayerMap[12].replace(43, 3, "| |");
            PlayerMap[13].replace(43, 3, "|_|");
        }
        else if(Room == 4)
        {
            Screen[7].replace(2, 9,  " _ _ _ _ ");
            Screen[8].replace(2, 9,  "|       |");
            Screen[9].replace(2, 9,  "|   X   |");
            Screen[10].replace(2, 9, "|_     _|");
            Screen[11].replace(2, 9, "  |   |  ");

            PlayerMap[2].replace(25, 9, " _ _ _ _ ");
            PlayerMap[3].replace(25, 9, "|       |");
            PlayerMap[4].replace(25, 9, "|       |");
            PlayerMap[5].replace(25, 9, "|_     _|");
            PlayerMap[6].replace(25, 9, "  |   |  ");
            PlayerMap[7].replace(25, 9, "  |   |  ");

        }
        else if(Room == 5)
        {
            Screen[7].replace(2, 6, "|   |_");
            Screen[8].replace(2, 6, "| X  _");
            Screen[9].replace(2, 6, "|   | ");

            PlayerMap[9].replace(5, 19,  "|   |_ _ _ _ _ _ _ ");
            PlayerMap[10].replace(5, 19, "|    _ _ _ _ _ _ _ ");
            PlayerMap[11].replace(5, 19, "|   |              ");
        }
        else if(Room == 6)
        {
            Screen[7].replace(2, 9,  " _|   |_ ");
            Screen[8].replace(2, 9,  "|       |");
            Screen[9].replace(2, 9,  "|   X   |");
            Screen[10].replace(2, 9, "|_ _ _ _|");

            PlayerMap[12].replace(5, 5,   "|   |");
            PlayerMap[13].replace(3, 9, " _|   |_ ");
            PlayerMap[14].replace(3, 9, "|       |");
            PlayerMap[15].replace(3, 9, "|       |");
            PlayerMap[16].replace(3, 9, "|_ _ _ _|");
        }
        else if(Room == 7)
        {
            Screen[7].replace(2, 9, "|===| \\/");
            Screen[8].replace(2, 5, "| X |");
            Screen[9].replace(2, 5, "|   |");

            PlayerMap[0].replace(5, 9, "|===| \\/"); PlayerMap[0].insert(14, " ");
            PlayerMap[1].replace(5, 5, "|   |");
            PlayerMap[2].replace(5, 5, "|   |");
            PlayerMap[3].replace(5, 5, "|   |");
            PlayerMap[4].replace(5, 5, "|   |");
            PlayerMap[5].replace(5, 5, "|   |");
            PlayerMap[6].replace(5, 5, "|   |");
            PlayerMap[7].replace(5, 5, "|   |");
            PlayerMap[8].replace(5, 5, "|   |");
        }
    }
    else if(Floor == 2)
    {
        if(Room == 0)
        {
            Screen[7].replace(2, 9, "|===| /\\");
            Screen[8].replace(2, 5, "| X |");
            Screen[9].replace(2, 5, "|   |");

            PlayerMap[0].replace(5, 9, "|===| /\\");
            PlayerMap[1].replace(5, 5, "|   |");
            PlayerMap[2].replace(5, 5, "|   |");
        }
        else if(Room == 1)
        {
            Screen[7].replace(5, 6, "|   |_");
            Screen[8].replace(5, 6, "| X  _");
            Screen[9].replace(5, 6, "|   | ");

            PlayerMap[3].replace(5, 5, "|   |");
            PlayerMap[4].replace(5, 6, "|   |_");
            PlayerMap[5].replace(5, 6, "|    _");
            PlayerMap[6].replace(5, 5, "|   |");
        }
        else if(Room == 2)
        {
            Screen[7].replace(2, 5, "|   |");
            Screen[8].replace(2, 5, "| X |");
            Screen[9].replace(2, 5, "|_ _|");

            PlayerMap[7].replace(5, 5, "|   |");
            PlayerMap[8].replace(5, 5, "|   |");
            PlayerMap[9].replace(5, 5, "|_ _|");
        }
        else if(Room == 3)
        {
            Screen[7].replace(2, 5, "|   |");
            Screen[8].replace(2, 5, "| X |");
            Screen[9].replace(2, 5, "|   |");

            PlayerMap[7].replace(5, 5, "|   |");
            PlayerMap[8].replace(5, 5, "|   |");
            PlayerMap[9].replace(5, 5, "|   |");
        }
        else if(Room == 4)
        {
            Screen[7].replace(2, 9,  " _|   |_ ");
            Screen[8].replace(2, 9,  "|       |");
            Screen[9].replace(2, 9,  "|   X   |");
            Screen[10].replace(2, 9, "|  _ _  |");
            Screen[11].replace(2, 9, "|_|_ _|_|");

            PlayerMap[9].replace(3, 9,  " _|   |_ ");
            PlayerMap[10].replace(3, 9, "|       |");
            PlayerMap[11].replace(3, 9, "|       |");
            PlayerMap[12].replace(3, 9, "|  _ _  |");
            PlayerMap[13].replace(3, 9, "|_|_ _|_|");
        }
        else if(Room == 5)
        {
            Screen[7].replace(2, 8,  "  _ _ _ ");
            Screen[8].replace(2, 8,  " |     |");
            Screen[9].replace(2, 8,  "_|     |");
            Screen[10].replace(2, 8, "_   X  |");
            Screen[11].replace(2, 8, " |     |");
            Screen[12].replace(2, 8, " |_ _ _|");

            PlayerMap[2].replace(22, 8,            "  _ _ _ ");
            PlayerMap[3].replace(22, 8,            " |     |");
            PlayerMap[4].replace(12, 18, "_ _ _ _ _ _|     |");
            PlayerMap[5].replace(12, 18, "_ _ _ _ _ _      |");
            PlayerMap[6].replace(22, 8,            " |     |");
            PlayerMap[7].replace(22, 8,            " |_ _ _|");
        }
        else if(Room == 6)
        {
            Screen[7].replace(2, 6, "_|   |");
            Screen[8].replace(2, 6, "_  X |");
            Screen[9].replace(2, 6, " |   |");

            PlayerMap[11].replace(12, 26, "_ _ _ _ _ _ _ _ _ _ _|   |");
            PlayerMap[12].replace(12, 26, "_ _ _ _ _ _ _ _ _ _ _    |");
            PlayerMap[13].replace(33, 5,                       "|   |");
        }
        else if(Room == 7)
        {
            Screen[7].replace(2, 9,  " _ _ _ _ ");
            Screen[8].replace(2, 9,  "|   X   |");
            Screen[9].replace(2, 9,  "|_ _    |");
            Screen[10].replace(2, 9, "    |   |");

            PlayerMap[5].replace(30, 8,   "_ _ _ _ ");
            PlayerMap[6].replace(29, 9,  "|       |");
            PlayerMap[7].replace(29, 9,  "|_ _    |");
            PlayerMap[8].replace(29, 9,  "    |   |");
            PlayerMap[9].replace(29, 9,  "    |   |");
            PlayerMap[10].replace(29, 9, "    |   |");
        }
        else if(Room == 8)
        {
            Screen[7].replace(2, 5, "|   |");
            Screen[8].replace(2, 6, "\\   /");
            Screen[9].replace(2, 5, " |X| ");
            Screen[10].replace(2, 8, " |=| \\/");

            PlayerMap[14].replace(33, 5, "|   |");
            PlayerMap[15].replace(33, 5, "|   |");
            PlayerMap[16].replace(33, 6, "\\   /");
            PlayerMap[17].replace(33, 5, " | | ");
            PlayerMap[18].replace(33, 8, " |=| \\/");
        }
    }
    else if(Floor == 3)
    {
        if(Room == 0)
        {
            Screen[7].replace(2, 6, "|=| /\\");
            Screen[8].replace(2, 3, "|X|");
            Screen[9].replace(2, 3, "| |");

            PlayerMap[0].replace(33, 6, "|=| /\\");
            PlayerMap[1].replace(33, 3, "| |");
            PlayerMap[2].replace(33, 3, "| |");
        }
        else if(Room == 1)
        {
            Screen[7].replace(2, 7, " _ _| |");
            Screen[8].replace(2, 7, "     X|");
            Screen[9].replace(2, 7, "|     |");

            PlayerMap[3].replace(33, 3,    "| |");
            PlayerMap[4].replace(33, 3,    "| |");
            PlayerMap[5].replace(29, 7, " _ _| |");
            PlayerMap[6].replace(29, 7, "      |");
            PlayerMap[7].replace(29, 7, "|     |");
        }
        else if(Room == 2)
        {
            Screen[7].replace(2, 5, "_ _ _");
            Screen[8].replace(2, 5, "  X  ");
            Screen[9].replace(2, 5, "|   |");

            PlayerMap[5].replace(24, 5, "_ _ _");
            PlayerMap[6].replace(24, 5, "     ");
            PlayerMap[7].replace(24, 5, "|   |");
        }
        else if(Room == 3)
        {
            Screen[7].replace(2, 7, "|     |");
            Screen[8].replace(2, 7, "    X |");
            Screen[9].replace(2, 7, "|     |");

            PlayerMap[8].replace(29, 7,  "|     |");
            PlayerMap[9].replace(29, 7,  "      |");
            PlayerMap[10].replace(29, 7, "|     |");
        }
        else if(Room == 4)
        {
            Screen[7].replace(2, 7, "|     |");
            Screen[8].replace(2, 7, " _ _X_|");

            PlayerMap[11].replace(29, 7, "|     |");
            PlayerMap[12].replace(29, 7, " _ _ _|");
        }
        else if(Room == 5)
        {
            Screen[7].replace(2, 5, "|   |");
            Screen[8].replace(2, 5, "_ _X_");

            PlayerMap[11].replace(24, 5, "|   |");
            PlayerMap[12].replace(24, 5, "_ _ _");
        }
        else if(Room == 6)
        {
            Screen[7].replace(2, 10, "_ _ _ _ _ ");
            Screen[8].replace(2, 10, "    X     ");
            Screen[9].replace(2, 10, "|        |");

            PlayerMap[5].replace(14, 10, "_ _ _ _ _ ");
            PlayerMap[6].replace(14, 10, "          ");
            PlayerMap[7].replace(14, 10, "|        |");
        }
        else if(Room == 7)
        {
            Screen[7].replace(2, 10, "|        |");
            Screen[8].replace(2, 10, "    X     ");
            Screen[9].replace(2, 10, "|        |");

            PlayerMap[8].replace(14, 10,  "|        |");
            PlayerMap[9].replace(14, 10,  "          ");
            PlayerMap[10].replace(14, 10, "|        |");
        }
        else if(Room == 8)
        {
            Screen[7].replace(2, 10, "|        |");
            Screen[8].replace(2, 10, "_ _ _X_ _ ");

            PlayerMap[11].replace(14, 10, "|        |");
            PlayerMap[12].replace(14, 10, "_ _ _ _ _ ");
        }
        else if(Room == 9)
        {
            Screen[7].replace(2, 6, "|    |");
            Screen[8].replace(2, 6, "_ _X_ ");

            PlayerMap[11].replace(8, 6, "|    |");
            PlayerMap[12].replace(8, 6, "_ _ _ ");
        }
        else if(Room == 10)
        {
            Screen[7].replace(2, 6, "_ _ _ ");
            Screen[8].replace(2, 6, "  X   ");
            Screen[9].replace(2, 6, "|    |");

            PlayerMap[5].replace(8, 6, "_ _ _ ");
            PlayerMap[6].replace(8, 6, "      ");
            PlayerMap[7].replace(8, 6, "|    |");
        }
        else if(Room == 11)
        {
            Screen[7].replace(2, 5, " _ _ ");
            Screen[8].replace(2, 5, "|X   ");
            Screen[9].replace(2, 5, "|   |");

            PlayerMap[5].replace(4, 1,  "_"); PlayerMap[5].replace(6, 1, "_");
            PlayerMap[6].replace(3, 5, "|    ");
            PlayerMap[7].replace(3, 5, "|   |");
        }
        else if(Room == 12)
        {
            Screen[7].replace(2, 5, "|   |");
            Screen[8].replace(2, 5, "|X   ");
            Screen[9].replace(2, 5, "|   |");

            PlayerMap[8].replace(3, 5,  "|   |");
            PlayerMap[9].replace(3, 5,  "|    ");
            PlayerMap[10].replace(3, 5, "|   |");
        }
        else if(Room == 13)
        {
            Screen[7].replace(2, 5, "|   |");
            Screen[8].replace(2, 5, "|X _ ");
            Screen[9].replace(2, 7, "|=| \\/");

            PlayerMap[11].replace(3, 5, "|   |");
            PlayerMap[12].replace(3, 5, "|  _ ");
            PlayerMap[13].replace(3, 7, "|=| \\/");

        }
        else if(Room == 14)
        {
            Screen[7].replace(2, 7, "|=| /\\");
            Screen[8].replace(2, 3, "|X|");
            Screen[9].replace(2, 3, "| |");

            PlayerMap[1].replace(3, 7, "|=| /\\"); PlayerMap[1].insert(11, " ");
            PlayerMap[2].replace(3, 3, "| |");
            PlayerMap[3].replace(3, 3, "| |");
            PlayerMap[4].replace(3, 3, "| |");
            PlayerMap[5].replace(3, 3, "| |");
        }
        else if(Room == 15)
        {
            Screen[7].replace(2, 5, "|   |");
            Screen[8].replace(2, 5, "  X  ");
            Screen[9].replace(2, 5, "|   |");

            PlayerMap[8].replace(24, 5, "|   |");
            PlayerMap[9].replace(24, 5, "     ");
            PlayerMap[10].replace(24,5, "|   |");
        }
        else if(Room == 16)
        {
            Screen[7].replace(2, 6, "|    |");
            Screen[8].replace(2, 6, "   X  ");
            Screen[9].replace(2, 6, "|    |");

            PlayerMap[8].replace(8, 6, "|    |");
            PlayerMap[9].replace(8, 6, "      ");
            PlayerMap[10].replace(8,6, "|    |");
        }
    }
    else if(Floor == 4)
    {
        if(Room == 0)
        {
            Screen[7].replace(2, 7, "|=| /\\");
            Screen[8].replace(2, 3, "|X|");
            Screen[9].replace(2, 3, "| |");

            PlayerMap[2].replace(24, 7, "|=| /\\"); PlayerMap[2].insert(32, " ");
            PlayerMap[3].replace(24, 3, "| |");
            PlayerMap[4].replace(24, 3, "| |");
        }
        else if(Room == 1)
        {
            Screen[7].replace(2, 7, "_ _| |_");
            Screen[8].replace(2, 7, "_   X _");
            Screen[9].replace(3, 5,  "|_ _|");

            PlayerMap[5].replace(24, 3,    "| |");
            PlayerMap[6].replace(21, 7, "_ _| |_");
            PlayerMap[7].replace(21, 7, "_     _");
            PlayerMap[8].replace(22, 5,  "|_ _|");
        }
        else if(Room == 2)
        {
            Screen[7].replace(2, 5, "_ _ _");
            Screen[8].replace(2, 5, "_ X _");
            Screen[9].replace(2, 5, " | | ");

            PlayerMap[6].replace(28, 10, " _ _ _ _ _");
            PlayerMap[7].replace(28, 10, " _ _ _   _");
            PlayerMap[8].replace(28, 10, "      | | ");
        }
        else if(Room == 3)
        {
            Screen[7].replace(2, 6, "_| |_ ");
            Screen[8].replace(2, 6, "_ X  |");
            Screen[9].replace(2, 6, " |_ _|");

            PlayerMap[6].replace(39, 6, "_| |_ ");
            PlayerMap[7].replace(39, 6, "_    |");
            PlayerMap[8].replace(39, 6, " |_ _|");
        }
        else if(Room == 4)
        {
            Screen[7].replace(2, 4, " _ _");
            Screen[8].replace(2, 4, "|X _");
            Screen[9].replace(2, 4, "| | ");

            PlayerMap[1].replace(40, 4, " _ _");
            PlayerMap[2].replace(40, 4, "|  _");
            PlayerMap[3].replace(40, 4, "| | ");
            PlayerMap[4].replace(40, 4, "| | ");
            PlayerMap[5].replace(40, 4, "| | ");
        }
        else if(Room == 5)
        {
            Screen[7].replace(2, 6,  "  _ _ ");
            Screen[8].replace(2, 6,  "_|   |");
            Screen[9].replace(2, 6,  "_  X |");
            Screen[10].replace(2, 6, " |_ _|");

            PlayerMap[0].replace(57,  6,             "  _ _ ");
            PlayerMap[1].replace(45, 18, "_ _ _ _ _ _ _|   |");
            PlayerMap[2].replace(45, 18, "_ _ _ _ _ _ _    |");
            PlayerMap[3].replace(57,  6,             " |_ _|");
        }
        else if(Room == 6)
        {
            Screen[7].replace(2, 5, "_| |_");
            Screen[8].replace(2, 5, "_ X _");
            Screen[9].replace(2, 5, " | | ");

            PlayerMap[6].replace(7, 13, "_| |_ _ _ _ _");
            PlayerMap[7].replace(7, 13, "_   _ _ _ _ _");
            PlayerMap[8].replace(7, 5,  " | | ");
        }
        else if(Room == 7)
        {
            Screen[7].replace(2, 3, " _ ");
            Screen[8].replace(2, 3, "|X|");
            Screen[9].replace(2, 3, "| |");

            PlayerMap[3].replace(8, 3, " _ ");
            PlayerMap[4].replace(8, 3, "| |");
            PlayerMap[5].replace(8, 3, "| |");
        }
        else if(Room == 8)
        {
            Screen[7].replace(2, 6, " _| |_");
            Screen[8].replace(2, 6, "|  X  ");
            Screen[9].replace(2, 6, "|_ _ _");

            PlayerMap[9].replace(8, 3,    "| |");
            PlayerMap[10].replace(6, 6, " _| |_");
            PlayerMap[11].replace(6, 6, "|     ");
            PlayerMap[12].replace(6, 6, "|_ _ _");
        }
        else if(Room == 9)
        {
            Screen[7].replace(2, 4,  " _  ");
            Screen[8].replace(2, 4,  "| |_");
            Screen[9].replace(2, 4,  "|X _");
            Screen[10].replace(2, 4, "|_| ");

            PlayerMap[5].replace(0, 4, " _  ");
            PlayerMap[6].replace(0, 6, "| |_ _");
            PlayerMap[7].replace(0, 6, "|  _ _");
            PlayerMap[8].replace(0, 4, "|_| ");
        }
        else if(Room == 10)
        {
           Screen[7].replace(2, 5, "_| |_");
           Screen[8].replace(2, 5, "  X  ");
           Screen[9].replace(2, 5, "_ _ _");

           PlayerMap[10].replace(13, 9, "_ _ _| |_");
           PlayerMap[11].replace(13, 9, "         ");
           PlayerMap[12].replace(13, 9, "_ _ _ _ _");
        }
        else if(Room == 11)
        {
            Screen[7].replace(2, 7, " _ _ _ ");
            Screen[8].replace(2, 7, "|_ X _|");
            Screen[9].replace(2, 7, "  | |  ");

            PlayerMap[8].replace(16, 6,  " _ _ _");
            PlayerMap[9].replace(16, 7,  "|_   _|");
            PlayerMap[10].replace(18, 3,   "| |");
        }
        else if(Room == 12)
        {
            Screen[7].replace(2, 4, "_ _ ");
            Screen[8].replace(2, 4, "  X|");
            Screen[9].replace(2, 4, "_  |");

            PlayerMap[10].replace(23, 11, "_ _ _ _ _ _");
            PlayerMap[11].replace(23, 12, "           |");
            PlayerMap[12].replace(23, 12, "_ _ _ _ _  |");
        }
        else if(Room == 13)
        {
            Screen[7].replace(2, 5, "_  |_");
            Screen[8].replace(2, 5, "_X_ _");

            PlayerMap[12].replace(31, 5, "_  |_");
            PlayerMap[13].replace(31, 5, "_ _ _");
        }
        else if(Room == 14)
        {
            Screen[7].replace(2, 4, " _ _");
            Screen[8].replace(2, 4, "|X _");
            Screen[9].replace(2, 6, "|=|\\/");

            PlayerMap[12].replace(22, 8, " _ _ _ _");
            PlayerMap[13].replace(22, 8, "|  _ _ _");
            PlayerMap[14].replace(22, 6, "|=|\\/"); PlayerMap[14].insert(28, " ");
        }
        else if(Room == 15)
        {
            Screen[7].replace(2, 8,  "  _ _ _ ");
            Screen[8].replace(2, 8,  "_|     |");
            Screen[9].replace(2, 8,  "_   X  |");
            Screen[10].replace(2, 8, " |_ _ _|");

            PlayerMap[11].replace(44, 8,         " _ _ _ ");
            PlayerMap[12].replace(37, 14, "_ _ _ _|     |");
            PlayerMap[13].replace(37, 14, "_ _ _ _      |");
            PlayerMap[14].replace(44, 8,         "|_ _ _|");
        }
        else if(Room == 16)
        {
            Screen[7].replace(2, 6, "| |_ _");
            Screen[8].replace(2, 6, "|X   _");
            Screen[9].replace(2, 6, "|_ _| ");

            PlayerMap[9].replace(34, 6, "| |_ _");
            PlayerMap[10].replace(34, 6, "|    _");
            PlayerMap[11].replace(34, 6, "|_ _| ");
        }
        else if(Room == 17)
        {
            Screen[7].replace(2, 6, "_ _| |");
            Screen[8].replace(2, 6, "_   X|");
            Screen[9].replace(2, 6, " |_ _|");

            PlayerMap[9].replace(41, 22, "_ _ _ _ _ _ _ _ _ _| |");
            PlayerMap[10].replace(41, 22, "_ _ _ _ _ _ _ _ _    |");
            PlayerMap[11].replace(57, 6,                  " |_ _|");
        }
        else if(Room == 18)
        {
            Screen[7].replace(2, 3, " _ ");
            Screen[8].replace(2, 3, "|X|");
            Screen[9].replace(2, 3, "| |");

            PlayerMap[4].replace(60, 3, " _ ");
            PlayerMap[5].replace(60, 3, "| |");
            PlayerMap[6].replace(60, 3, "| |");
            PlayerMap[7].replace(60, 3, "| |");
            PlayerMap[8].replace(60, 3, "| |");
        }
    }
    else if(Floor == 5)
    {
        if(Room == 0)
        {
            Screen[7].replace(2, 7, "|=| /\\");
            Screen[8].replace(2, 3, "|X|");
            Screen[9].replace(2, 3, "| |");

            PlayerMap[0].replace(10, 7, "|=| /\\");
            PlayerMap[1].replace(10, 3, "| |");
            PlayerMap[2].replace(10, 3, "| |");
        }
        else if(Room == 1)
        {
            Screen[7].replace(2, 5, "_| |_");
            Screen[8].replace(2, 5, "_ X _");
            Screen[9].replace(2, 5, " | | ");

            PlayerMap[3].replace(10, 3, "| |");
            PlayerMap[4].replace(9, 5, "_| |_");
            PlayerMap[5].replace(9, 5, "_   _");
            PlayerMap[6].replace(9, 5, " | | ");
        }
        else if(Room == 2)
        {
            Screen[7].replace(2, 5, " _ _ ");
            Screen[8].replace(2, 5, "|_X_ ");

            PlayerMap[4].replace(2, 6, " _ _ _");
            PlayerMap[5].replace(2, 6, "|_ _ _");
        }
        else if(Room == 3)
        {
            Screen[7].replace(2, 6,  "  _ _ ");
            Screen[8].replace(2, 6,  "_|   |");
            Screen[9].replace(2, 6,  "_  X |");
            Screen[10].replace(2, 6, " |_ _|");

            PlayerMap[3].replace(15, 16, "            _ _ ");
            PlayerMap[4].replace(15, 16, "_ _ _ _ _ _|   |");
            PlayerMap[5].replace(15, 16, "_ _ _ _ _ _    |");
            PlayerMap[6].replace(15, 16, "           |_ _|");
        }
        else if(Room == 4)
        {
            Screen[7].replace(2, 8, "| |_ _ _");
            Screen[8].replace(2, 8, "|X     _");
            Screen[9].replace(2, 8, "|_ _ _| ");

            PlayerMap[7].replace(10, 3,  "| |");
            PlayerMap[8].replace(10, 3,  "| |");
            PlayerMap[9].replace(10, 3,  "| |");
            PlayerMap[10].replace(10, 8, "| |_ _ _");
            PlayerMap[11].replace(10, 8, "|      _");
            PlayerMap[12].replace(10, 8, "|_ _ _| ");
        }
        else if(Room == 5)
        {
            Screen[7].replace(2, 5, "_| |_");
            Screen[8].replace(2, 5, "_ _X_");

            PlayerMap[10].replace(19, 13, "_ _ _ _ _| |_");
            PlayerMap[11].replace(19, 13, "_ _ _ _ _ _ _");
        }
        else if(Room == 6)
        {
            Screen[7].replace(2, 9,  " _ _ _ _ ");
            Screen[8].replace(2, 9,  "|   X   |");
            Screen[9].replace(2, 9,  "|_   _ _|");
            Screen[10].replace(2, 9, "  | |    ");

            PlayerMap[6].replace(27, 3,  "_ _"); PlayerMap[6].replace(31, 4, "_ _ ");
            PlayerMap[7].replace(26, 9, "|       |");
            PlayerMap[8].replace(26, 9, "|_   _ _|");
            PlayerMap[9].replace(26, 9, "  | |    ");
        }
        else if(Room == 7)
        {
            Screen[7].replace(2, 4, "_ _ ");
            Screen[8].replace(2, 4, "_ X|");
            Screen[9].replace(2, 4, " | |");

            PlayerMap[10].replace(33, 12, "_ _ _ _ _ _ ");
            PlayerMap[11].replace(33, 12, "_ _ _ _ _  |");
            PlayerMap[12].replace(33, 12, "         | |");
        }
        else if(Room == 8)
        {
            Screen[7].replace(2, 6, "_ _| |");
            Screen[8].replace(2, 6, "_  X |");
            Screen[9].replace(2, 6, " |_ _|");

            PlayerMap[13].replace(39, 6, "_ _| |");
            PlayerMap[14].replace(39, 6, "_    |");
            PlayerMap[15].replace(39, 6, " |_ _|");
        }
        else if(Room == 9)
        {
            Screen[7].replace(2, 5, "_| |_");
            Screen[8].replace(2, 5, "_ X _");
            Screen[9].replace(2, 5, " | | ");

            PlayerMap[13].replace(27, 11, "_| |_ _ _ _");
            PlayerMap[14].replace(27, 11, "_   _ _ _ _");
            PlayerMap[15].replace(27, 11, " | |       ");
        }
        else if(Room == 10)
        {
            Screen[7].replace(2, 3, " _ ");
            Screen[8].replace(2, 3, "|X|");
            Screen[9].replace(2, 3, "| |");

            PlayerMap[12].replace(28, 3, "| |");
        }
        else if(Room == 11)
        {
            Screen[7].replace(2, 4, " _ _");
            Screen[8].replace(2, 4, "|X _");
            Screen[9].replace(2, 4, "| | ");

            PlayerMap[13].replace(14, 12, " _ _ _ _ _ _");
            PlayerMap[14].replace(14, 12, "|  _ _ _ _ _");
            PlayerMap[15].replace(14, 12, "| |         ");
        }
        else if(Room == 12)
        {
            Screen[7].replace(2, 7, " _ _| |");
            Screen[8].replace(2, 7, "|  X  |");
            Screen[9].replace(2, 7, "|_ _ _|");

            PlayerMap[16].replace(14, 3,     "| |");
            PlayerMap[17].replace(10, 7, " _ _| |");
            PlayerMap[18].replace(10, 7, "|     |");
            PlayerMap[19].replace(10, 7, "|_ _ _|");
        }
        else if(Room == 13)
        {
            Screen[7].replace(2, 6, "| |_ _");
            Screen[8].replace(2, 6, "|X    ");
            Screen[9].replace(2, 6, "|_ _ _");

            PlayerMap[16].replace(28, 3, "| |");
            PlayerMap[17].replace(28, 6, "| |_ _");
            PlayerMap[18].replace(28, 6, "|     ");
            PlayerMap[19].replace(28, 6, "|_ _ _");
        }
        else if(Room == 14)
        {
            Screen[7].replace(2, 10, "_ _|=| \\/");
            Screen[8].replace(2, 6,  "    X|");
            Screen[9].replace(2, 6,  "_ _ _|");

            PlayerMap[17].replace(35, 20,  "_ _ _ _ _ _ _|=| \\/");
            PlayerMap[18].replace(35, 16,  "               |");
            PlayerMap[19].replace(35, 16,  "_ _ _ _ _ _ _ _|");
        }
        else if(Room == 15)
        {
            Screen[7].replace(0, 4, " _ _");
            Screen[8].replace(0, 4, "|X|_");
            Screen[9].replace(0, 4, "| | ");

            PlayerMap[4].replace(0, 3, " _ ");
            PlayerMap[5].replace(0, 3, "| |");
            PlayerMap[6].replace(0, 3, "| |");
        }
        else if(Room == 16)
        {
            Screen[7].replace(0, 3, "| |");
            Screen[8].replace(0, 3, "|X|");
            Screen[9].replace(0, 6, "|=| \\/");

            PlayerMap[7].replace(0, 3, "| |");
            PlayerMap[8].replace(0, 3, "| |");
            PlayerMap[9].replace(0, 3, "| |");
            PlayerMap[10].replace(0, 3,"| |");
            PlayerMap[11].replace(0, 7,"|=| \\/"); PlayerMap[11].insert(7, " ");
        }
    }
    else if(Floor == 6)
    {
        if(Room == 0)
        {
            Screen[7].replace(2, 9, "  |=| /\\");
            Screen[8].replace(2, 7, " _|X|_ ");
            Screen[9].replace(2, 7, "|     |");

            PlayerMap[0].replace(6, 9, "  |=| /\\"); PlayerMap[0].insert(15, " ");
            PlayerMap[1].replace(6, 7, " _| |_ ");
            PlayerMap[2].replace(6, 7, "|     |");
        }
        else if(Room == 1)
        {
            Screen[7].replace(2, 7,  " _| |_ ");
            Screen[8].replace(2, 8,  "|     |_");
            Screen[9].replace(2, 8,  "|  X   _");
            Screen[10].replace(2, 7, "|_   _|");
            Screen[11].replace(4, 3,   "| |");

            PlayerMap[2].replace(6, 8, "|     |_");
            PlayerMap[3].replace(6, 8, "|      _");
            PlayerMap[4].replace(6, 7, "|_   _|");
            PlayerMap[5].replace(8, 3,   "| |");
        }
        else if(Room == 2)
        {
            Screen[7].replace(2, 5, " _ _ ");
            Screen[8].replace(2, 5, " _X_ ");

            PlayerMap[2].replace(15, 18, "_ _ _ _ _ _ _ _ _ ");
            PlayerMap[3].replace(15, 18, "_ _ _ _ _ _ _ _ _ ");
        }
        else if(Room == 3)
        {
            char test;

            test = PlayerMap[3].at(15);

            if(test == ' ')
            {
                Screen[7].replace(2, 13,  "   _| |_ _ _ ");
                Screen[8].replace(2, 13,  " _|         |");
                Screen[9].replace(2, 13,  "|_    X     |");
                Screen[10].replace(2, 13, "  |_   _ _ _|");
                Screen[11].replace(2, 13, "    | |      ");

                PlayerMap[1].replace(32, 13, "   _| |_ _ _ ");
                PlayerMap[2].replace(32, 13, " _|         |");
                PlayerMap[3].replace(32, 13, "|_          |");
                PlayerMap[4].replace(32, 13, "  |_   _ _ _|");
                PlayerMap[5].replace(36, 3,      "| |");
            }
            else
            {
                Screen[7].replace(2, 13,  "   _| |_ _ _ ");
                Screen[8].replace(2, 13,  " _|         |");
                Screen[9].replace(2, 13,  " _    X     |");
                Screen[10].replace(2, 13, "  |_   _ _ _|");
                Screen[11].replace(2, 13, "    | |      ");

                PlayerMap[1].replace(34, 13, "   _| |_ _ _ ");
                PlayerMap[2].replace(34, 13, " _|         |");
                PlayerMap[3].replace(34, 13, " _          |");
                PlayerMap[4].replace(34, 13, "  |_   _ _ _|");
                PlayerMap[5].replace(36, 3,      "| |");
            }
        }
        else if(Room == 4)
        {
            Screen[7].replace(2, 11, " _| |_ _ _ ");
            Screen[8].replace(2, 11, "|  X      |");
            Screen[9].replace(2, 11, "|_ _ _ _ _|");

            PlayerMap[5].replace(34, 11, " _| |_ _ _ ");
            PlayerMap[6].replace(34, 11, "|         |");
            PlayerMap[7].replace(34, 11, "|_ _ _ _ _|");
        }
        else if(Room == 5)
        {
            Screen[7].replace(2, 6, "| |_ _");
            Screen[8].replace(2, 6, "|X    ");
            Screen[9].replace(2, 6, "|_ _ _");

            PlayerMap[6].replace(8, 6, "| |_ _");
            PlayerMap[7].replace(8, 6, "|     ");
            PlayerMap[8].replace(8, 6, "|_ _ _");
        }
        else if(Room == 6)
        {
            Screen[7].replace(2, 6,  "_ _ _ ");
            Screen[8].replace(2, 6,  "    X|");
            Screen[9].replace(2, 6,  "_ _  |");
            Screen[10].replace(2, 6, "   | |");

            PlayerMap[6].replace(15, 4, "_ _ ");
            PlayerMap[7].replace(15, 4, "   |");
            PlayerMap[8].replace(15, 4, "_  |");
            PlayerMap[9].replace(16, 3,  "| |");
        }
        else if(Room == 7)
        {
            Screen[7].replace(2, 9, "_ _| |_ _");
            Screen[8].replace(2, 9, "_   X   _");
            Screen[9].replace(2, 9, " |_ _ _| ");

            PlayerMap[9].replace(13, 9,  "_ _| |_ _");
            PlayerMap[10].replace(13, 9, "_       _");
            PlayerMap[11].replace(13, 9, " |_ _ _| ");
        }
        else if(Room == 8)
        {
            Screen[7].replace(2, 4, "| |_");
            Screen[8].replace(2, 4, "|X _");
            Screen[9].replace(2, 3, "|_|");

            PlayerMap[9].replace(2, 10,  "| |_ _ _ _");
            PlayerMap[10].replace(2, 10, "|  _ _ _ _");
            PlayerMap[11].replace(2, 3,  "|_|");
        }
        else if(Room == 9)
        {
            Screen[7].replace(2, 6,  " _ _ _");
            Screen[8].replace(2, 7,  "|  X  |");
            Screen[9].replace(2, 7,  "|_   _|");
            Screen[10].replace(2, 7, "  | |  ");

            PlayerMap[4].replace(0, 6, " _ _ _");
            PlayerMap[5].replace(0, 7, "|     |");
            PlayerMap[6].replace(0, 7, "|_   _|");
            PlayerMap[7].replace(0, 7, "  | |  ");
            PlayerMap[8].replace(0, 7, "  | |  ");
        }
        else if(Room == 10)
        {
            Screen[7].replace(2, 4, "_ _ ");
            Screen[8].replace(2, 4, "_ X|");
            Screen[9].replace(2, 4, " | |");

            PlayerMap[9].replace(23, 12,  "_ _ _ _ _ _ ");
            PlayerMap[10].replace(23, 12, "_ _ _ _ _  |");
            PlayerMap[11].replace(32, 3,           "| |");
        }
        else if(Room == 11)
        {
            Screen[7].replace(2, 8, "_ _| |_ ");
            Screen[8].replace(2, 8, "    X  |");
            Screen[9].replace(2, 8, "_ _ _ _|");

            PlayerMap[12].replace(32, 3,    "| |");
            PlayerMap[13].replace(32, 3,    "| |");
            PlayerMap[14].replace(29, 8, "_ _| |_ ");
            PlayerMap[15].replace(29, 8, "       |");
            PlayerMap[16].replace(29, 8, "_ _ _ _|");
        }
        else if(Room == 12)
        {
            Screen[7].replace(2, 9, "_ _| |_ _");
            Screen[8].replace(2, 9, "    X    ");
            Screen[9].replace(2, 9, "_ _ _ _ _");

            PlayerMap[14].replace(11, 17, "_ _| |_ _ _ _ _ _");
            PlayerMap[15].replace(11, 17, "                 ");
            PlayerMap[16].replace(11, 17, "_ _ _ _ _ _ _ _ _");
        }
        else if(Room == 13)
        {
           Screen[7].replace(2, 3, " _ ");
           Screen[8].replace(2, 3, "|X|");
           Screen[9].replace(2, 3, "| |");

           PlayerMap[12].replace(14, 3, "| |");
           PlayerMap[13].replace(14, 3, "| |");
        }
        else if(Room == 14)
        {
            Screen[7].replace(2, 6,  "| |_ _");
            Screen[8].replace(2, 6,  "|     ");
            Screen[9].replace(2, 6,  "|X _ _");
            Screen[10].replace(2, 7, "|=| \\/");

            PlayerMap[14].replace(6, 4, "| |_");
            PlayerMap[15].replace(6, 4, "|   ");
            PlayerMap[16].replace(6, 4, "|  _");
            PlayerMap[17].replace(6, 7, "|=| \\/");
        }
        else if(Room == 15)
        {
            Screen[7].replace(2, 7, " _ _ _ ");
            Screen[8].replace(2, 7, "|_ X _|");
            Screen[9].replace(2, 7, "  | |  ");

            PlayerMap[10].replace(5, 5,  "_ _ _");
            PlayerMap[11].replace(4, 7, "|_   _|");
            PlayerMap[12].replace(6, 3,   "| |");
            PlayerMap[13].replace(6, 3,   "| |");
        }
        else if(Room == 16)
        {
            Screen[7].replace(3, 7,  "|=| /\\");
            Screen[8].replace(2, 5, "_|X|_");

            PlayerMap[0].replace(36, 7,  "|=| /\\");
            PlayerMap[1].replace(35, 5, "_| |_");
        }
    }
    else if(Floor == 7)
    {
        if(Room == 0)
        {
            Screen[7].replace(2, 7, "|=| /\\");
            Screen[8].replace(2, 3, "|X|");
            Screen[9].replace(2, 3, "| |");

            PlayerMap[1].replace(0, 7, "|=| /\\"); PlayerMap[1].insert(7, " ");
            PlayerMap[2].replace(0, 3, "| |");
            PlayerMap[3].replace(0, 3, "| |");
        }
        else if(Room == 1)
        {
            Screen[7].replace(2, 8, "| |_ _ _");
            Screen[8].replace(2, 8, "|X     _");
            Screen[9].replace(2, 8, "|_ _ _| ");

            PlayerMap[4].replace(0, 3,  "| |");
            PlayerMap[5].replace(0, 3,  "| |");
            PlayerMap[6].replace(0, 3,  "| |");
            PlayerMap[7].replace(0, 3,  "| |");
            PlayerMap[8].replace(0, 8,  "| |_ _ _");
            PlayerMap[9].replace(0, 8,  "|      _");
            PlayerMap[10].replace(0, 8, "|_ _ _| ");
        }
        else if(Room == 2)
        {
            Screen[7].replace(2, 6, " | |_ ");
            Screen[8].replace(2, 6, "_| X |");
            Screen[9].replace(2, 6, "_ _ _|");

            PlayerMap[7].replace(17, 6,         " | |_ ");
            PlayerMap[8].replace(9, 14, "_ _ _ _ _|   |");
            PlayerMap[9].replace(9, 14, "_ _ _ _ _ _ _|");
        }
        else if(Room == 3)
        {
            Screen[7].replace(2, 5, "_ _ _");
            Screen[8].replace(2, 5, "_ X _");
            Screen[9].replace(2, 5, " | | ");

            PlayerMap[1].replace(17, 5, "_ _ _");
            PlayerMap[2].replace(17, 5, "_   _");
            PlayerMap[3].replace(17, 5, " | | ");
            PlayerMap[4].replace(17, 5, " | | ");
            PlayerMap[5].replace(17, 5, " | | ");
            PlayerMap[6].replace(17, 5, " | | ");

        }
        else if(Room == 4)
        {
            Screen[7].replace(2, 4, " _ _");
            Screen[8].replace(2, 4, "|X _");
            Screen[9].replace(2, 4, "| | ");

            PlayerMap[1].replace(8, 8, " _ _ _ _");
            PlayerMap[2].replace(8, 8, "|  _ _ _");
            PlayerMap[3].replace(8, 4, "| | ");
        }
        else if(Room == 5)
        {
            Screen[7].replace(3, 12,  "_ _ _| |_ _ ");
            Screen[8].replace(2, 13, "|      X    |");
            Screen[9].replace(2, 13, "|_ _ _ _ _ _|");

            PlayerMap[4].replace(3, 12,  "_ _ _| |_ _ ");
            PlayerMap[5].replace(2, 13, "|           |");
            PlayerMap[6].replace(2, 13, "|_ _ _ _ _ _|");
        }
        else if(Room == 6)
        {
            Screen[7].replace(2, 8,  "  _ _ _ ");
            Screen[8].replace(2, 8,  "_|     |");
            Screen[9].replace(2, 8,  "_   X  |");
            Screen[10].replace(2, 8, " |_   _|");
            Screen[11].replace(2, 8, "   | |  ");

            PlayerMap[0].replace(36, 7,               " _ _ _ ");
            PlayerMap[1].replace(23, 20, "_ _ _ _ _ _ _|     |");
            PlayerMap[2].replace(23, 20, "_ _ _ _ _ _ _      |");
            PlayerMap[3].replace(23, 20, "             |_   _|");
            PlayerMap[4].replace(23, 20, "               | |  ");
        }
        else if(Room == 7)
        {
            Screen[7].replace(2, 6, "_ _| |");
            Screen[8].replace(2, 6, "    X|");
            Screen[9].replace(2, 6, "_ _ _|");

            PlayerMap[5].replace(38, 3,     "| |");
            PlayerMap[6].replace(38, 3,     "| |");
            PlayerMap[7].replace(38, 3,     "| |");
            PlayerMap[8].replace(38, 3,     "| |");
            PlayerMap[9].replace(38, 3,     "| |");
            PlayerMap[10].replace(35, 6, "_ _| |");
            PlayerMap[11].replace(35, 6, "     |");
            PlayerMap[12].replace(35, 6, "_ _ _|");
        }
        else if(Room == 8)
        {
            Screen[7].replace(2, 6,  " _ _ _");
            Screen[8].replace(2, 6,  "|X    ");
            Screen[9].replace(2, 6,  "|  _ _");
            Screen[10].replace(2, 6, "| |");

            PlayerMap[10].replace(18, 16, " _ _ _ _ _ _ _ _");
            PlayerMap[11].replace(18, 16, "|               ");
            PlayerMap[12].replace(18, 16, "|  _ _ _ _ _ _ _");
            PlayerMap[13].replace(18, 3,  "| |");
        }
        else if(Room == 9)
        {
            Screen[7].replace(2, 23,  " _ _ _ _| |_ _ _ _ _ _ ");
            Screen[8].replace(2, 23,  "|                     |");
            Screen[9].replace(2, 23,  "|        X            |");
            Screen[10].replace(2, 23, "|                     |");
            Screen[11].replace(2, 23, "|_ _ _ _ _ _ _ _ _ _ _|");

            PlayerMap[13].replace(10, 23, " _ _ _ _| |_ _ _ _ _ _ ");
            PlayerMap[14].replace(10, 23, "|                     |");
            PlayerMap[15].replace(10, 23, "|                     |");
            PlayerMap[16].replace(10, 23, "|                     |");
            PlayerMap[17].replace(10, 23, "|_ _ _ _ _ _ _ _ _ _ _|");
        }
        if(Room == 10)
        {
            Screen[7].replace(2, 5, "_ _ _");
            Screen[8].replace(2, 5, " |X| ");
            Screen[9].replace(2, 5, " | | ");

            PlayerMap[18].replace(18, 3, "| |");
            PlayerMap[19].replace(18, 3, "| |");
        }
    }
    else if(Floor == 8)
    {
        if(Room == 0)
        {
            Screen[7].replace(2, 71, "\\                                                                    /");
            Screen[8].replace(2, 71, " \\_ _ _ _ _ _ _ _ _ _ _ _ _X_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ / ");

            PlayerMap[0].replace(0, 71, "\\                                                                    /");
            PlayerMap[1].replace(0, 71, " \\_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ / ");
        }
        else if(Room == 1)
        {
            Screen[7].replace(2, 15,  "_ _ _ _ _ _ _ _");
            Screen[8].replace(2, 15,  "       X       ");
            Screen[9].replace(2, 15,  "_ _ _ _ _ _ _ _");
            Screen[10].replace(2, 15, ". . . . . . . .");

            PlayerMap[2].replace(21, 15, "               ");
            PlayerMap[3].replace(21, 15, "_ _ _ _ _ _ _ _");
            PlayerMap[4].replace(21, 15, ". . . . . . . ." );
        }
        else if(Room == 2)
        {
            Screen[7].replace(2, 20,  "_ _ _ _ _ _ _ _ _ _ ");
            Screen[8].replace(2, 20,  "        X|\\ _ _/| .");
            Screen[9].replace(2, 20,  "_ _ _ _ _|/ _ _\\| .");
            Screen[10].replace(2, 20, ". . . . . . . . . . ");

            PlayerMap[2].replace(36, 29, "                  |\\ _ _/| .");
            PlayerMap[3].replace(36, 29, " _ _ _ _ _ _ _ _ _|/ _ _\\| .");
            PlayerMap[4].replace(36, 29, " . . . . . . . . . . . . . . ");
        }
        else if(Room == 3)
        {
            Screen[7].replace(2, 11,  "_ _ _ _ _ _");
            Screen[8].replace(2, 11,  ".| X       ");
            Screen[9].replace(2, 11,  ".|    _ _ _");
            Screen[10].replace(2, 11, ".|   |. . .");

            PlayerMap[2].replace(5, 16, ".|              ");
            PlayerMap[3].replace(5, 16, ".|    _ _ _ _ _ ");
            PlayerMap[4].replace(5, 16, ".|   |. . . . . ");
        }
        else if(Room == 4)
        {
            Screen[7].replace(2, 7, ".|   |.");
            Screen[8].replace(2, 7, ".|   |.");
            Screen[9].replace(2, 7, ".|_X_|.");

            PlayerMap[5].replace(5, 7, ".|   |.");
            PlayerMap[6].replace(5, 7, ".|   |.");
            PlayerMap[7].replace(5, 7, ".|   |.");
            PlayerMap[8].replace(5, 7, ".|_ _|.");
        }
        else if(Room == 5)
        {
            Screen[7].replace(2, 16,  "    .|_ _|.     ");
            Screen[8].replace(2, 16,  "      _ _ _ /|_ ");
            Screen[9].replace(2, 16,  "    /      | |  ");
            Screen[10].replace(2, 16, "_ _/ X /|  | |  ");
            Screen[11].replace(2, 16, "   \\   \\|  | |");
            Screen[12].replace(2, 16, "    \\ _ _ _| |_");
            Screen[13].replace(2, 16, "            \\| ");

            PlayerMap[9].replace(1, 16,  "      _ _ _ /|_ ");
            PlayerMap[10].replace(1, 16, "    /      | |  ");
            PlayerMap[11].replace(1, 16, "_ _/   /|  | |  ");
            PlayerMap[12].replace(1, 16, "   \\   \\|  | |  "); //PlayerMap[12].insert(17, "  ");
            PlayerMap[13].replace(1, 16, "    \\ _ _ _| |_ "); //PlayerMap[12].insert(17, " ");
            PlayerMap[14].replace(1, 16, "            \\| "); //PlayerMap[12].insert(17, " ");
        }
        else if(Room == 6)
        {
            Screen[7].replace(2, 13,  " /|_ _ _ _   ");
            Screen[8].replace(2, 13,  "| |        \\");
            Screen[9].replace(2, 13,  "| |  X /|  | ");
            Screen[10].replace(2, 13, "| |    \\|  |");
            Screen[11].replace(2, 13, "| |_ _ _ _ / ");
            Screen[12].replace(2, 13, " \\|         ");

            PlayerMap[9].replace(17, 8,  "_ _ _   ");
            PlayerMap[10].replace(17, 8, "      \\");
            PlayerMap[11].replace(17, 8, "  /|  | ");
            PlayerMap[12].replace(17, 8, "  \\|  |");
            PlayerMap[13].replace(17, 8, "_ _ _ / ");
        }
    }
    else if(Floor == 9)
    {
        if(Room == 0)
        {
            Screen[7].replace(2, 15,  " _ _ _ _ _ _ _ ");
            Screen[8].replace(2, 15,  "|             |");
            Screen[9].replace(2, 15,  "|      X      |");
            Screen[10].replace(2, 15, "|_ _ _   _ _ _|");
            Screen[11].replace(2, 15, "      |=| \\/  ");

            PlayerMap[1].replace(8, 15, " _ _ _ _ _ _ _ ");
            PlayerMap[2].replace(8, 15, "|             |");
            PlayerMap[3].replace(8, 15, "|             |");
            PlayerMap[4].replace(8, 15, "|_ _ _   _ _ _|");
            PlayerMap[5].replace(8, 15, "      |=| \\/  ");
        }
    }
    else if(Floor == 10)
    {
        if(Room == 0)
        {
            Screen[7].replace(2, 21,  "        |=| /\\      ");
            Screen[8].replace(2, 21,  " _ _ _ _| |_ _ _ _ _ ");
            Screen[9].replace(2, 21,  "|                   |");
            Screen[10].replace(2, 21, "|        X          |");
            Screen[11].replace(2, 21, "|_ _ _ _ _ _ _ _ _ _|");

            PlayerMap[0].replace(5, 21, "        |=| /\\      ");
            PlayerMap[1].replace(5, 21, " _ _ _ _| |_ _ _ _ _ ");
            PlayerMap[2].replace(5, 21, "|                   |");
            PlayerMap[3].replace(5, 21, "|                   |");
            PlayerMap[4].replace(5, 21, "|_ _ _ _ _ _ _ _ _ _|");
        }
    }
    else if(Floor == 11)
    {
        Screen[7].replace(3, 20,  "   _ _ _ _ _        ");
        Screen[8].replace(3, 20,  "  /         \\      ");
        Screen[9].replace(3, 20,  " /           \\     ");
        Screen[10].replace(3, 20, "|  ||  ||   |=| /\\ ");
        Screen[11].replace(3, 20, "|  ||  ||     |     ");
        Screen[12].replace(3, 20, "|  ||  ||     |     ");
        Screen[13].replace(3, 20, " \\           /     ");
        Screen[14].replace(3, 20, "  \\_ _ _ _ _/      ");
        Screen[15].replace(3, 20, "      |=| \\/       ");

        PlayerMap[0].replace(3, 20, "   _ _ _ _ _        ");
        PlayerMap[1].replace(3, 20, "  /         \\      ");
        PlayerMap[2].replace(3, 20, " /           \\     ");
        PlayerMap[3].replace(3, 20, "|  ||  ||   |=| /\\ ");
        PlayerMap[4].replace(3, 20, "|  ||  ||     |     ");
        PlayerMap[5].replace(3, 20, "|  ||  ||     |     ");
        PlayerMap[6].replace(3, 20, " \\           /     ");
        PlayerMap[7].replace(3, 20, "  \\_ _ _ _ _/      ");
        PlayerMap[8].replace(3, 20, "      |=| \\/       ");

        if(Room == 0)
        {
            Screen[14].replace(10, 1, "X");
        }
        else if(Room == 1)
        {
            Screen[14].replace(13, 1, "X");
        }
        else if(Room == 2)
        {
            Screen[11].replace(16, 1, "X");
        }
        else if(Room == 3)
        {
            Screen[8].replace(13, 1, "X");
        }
        else if(Room == 4)
        {
            Screen[8].replace(9, 1, "X");
        }
        else if(Room == 5)
        {
            Screen[11].replace(9, 1, "X");
        }
    }
    else if(Floor == 12)
    {
        Screen[7].replace(1, 21,  "     _ _ _ _ _       ");
        Screen[8].replace(1, 21,  "    /         \\     ");
        Screen[9].replace(1, 21,  "   /           \\    ");
        Screen[10].replace(1, 21, "  |    _ _    |=| \\/");
        Screen[11].replace(1, 21, "  |   |   |     |    ");
        Screen[12].replace(1, 21, "/\\|=| |_ _|     |   ");
        Screen[13].replace(1, 21, "   \\           /    ");
        Screen[14].replace(1, 21, "    \\_ _ _ _ _/     ");

        PlayerMap[0].replace(1, 21,  "     _ _ _ _ _       ");
        PlayerMap[1].replace(1, 21,  "    /         \\     ");
        PlayerMap[2].replace(1, 21,  "   /           \\    ");
        PlayerMap[3].replace(1, 21,  "  |    _ _    |=| \\/");
        PlayerMap[4].replace(1, 21,  "  |   |   |     |    ");
        PlayerMap[5].replace(1, 21,  "/\\|=| |_ _|     |   ");
        PlayerMap[6].replace(1, 21,  "   \\           /    ");
        PlayerMap[7].replace(1, 21,  "    \\_ _ _ _ _/     ");

        if(Room == 0)
        {
            Screen[11].replace(16, 1, "X");
        }
        else if(Room == 1)
        {
            Screen[11].replace(13, 1, "X");
        }
        else if(Room == 2)
        {
            Screen[11].replace(4, 1, "X");
        }
    }
    else if(Floor == 13)
    {
        Screen[7].replace(2, 18,  "     _ _ _ _ _    ");
        Screen[8].replace(2, 18,  "    /         \\  ");
        Screen[9].replace(2, 18,  "   /           \\ ");
        Screen[10].replace(2, 18, "  |             | ");
        Screen[11].replace(2, 18, "  |      X      | ");
        Screen[12].replace(2, 18, "\\/|=|           |");
        Screen[13].replace(2, 18, "   \\           / ");
        Screen[14].replace(2, 18, "    \\_ _ _ _ _/  ");

        PlayerMap[0].replace(2, 18, "     _ _ _ _ _    ");
        PlayerMap[1].replace(2, 18, "    /         \\  ");
        PlayerMap[2].replace(2, 18, "   /           \\ ");
        PlayerMap[3].replace(2, 18, "  |             | ");
        PlayerMap[4].replace(2, 18, "  |             | ");
        PlayerMap[5].replace(2, 18, "\\/|=|           |");
        PlayerMap[6].replace(2, 18, "   \\           / ");
        PlayerMap[7].replace(2, 18, "    \\_ _ _ _ _/  ");
    }
}

void ViewMap(string PlayerMap[], int Floor, int Room)
{
    if(Floor == 0)
    {

        if(Room == 0)
        {
            PlayerMap[2].replace(16, 1, "X");

            drawScreen(PlayerMap, LevelSize0);

            PlayerMap[2].replace(16, 1, " ");
        }
        else if(Room == 1)
        {
            PlayerMap[2].replace(29, 1, "X");

            drawScreen(PlayerMap, LevelSize0);

            PlayerMap[2].replace(29, 1, " ");
        }
        else if(Room == 2)
        {
            PlayerMap[5].replace(16, 1, "X");

            drawScreen(PlayerMap, LevelSize0);

            PlayerMap[5].replace(16, 1, " ");
        }

        else if(Room == 3)
        {
            PlayerMap[5].replace(8, 1, "X");

            drawScreen(PlayerMap, LevelSize0);

            PlayerMap[5].replace(8, 1, " ");
        }

        else if(Room == 4)
        {
            PlayerMap[7].replace(16, 1, "X");

            drawScreen(PlayerMap, LevelSize0);

            PlayerMap[7].replace(16, 1, " ");
        }
        else if(Room == 5)
        {
            PlayerMap[7].replace(29, 1, "X");

            drawScreen(PlayerMap, LevelSize0);

            PlayerMap[7].replace(29, 1, " ");
        }
        else if(Room == 6)
        {
            PlayerMap[8].replace(16, 1, "X");

            drawScreen(PlayerMap, LevelSize0);

            PlayerMap[8].replace(16, 1, " ");
        }
        else if(Room == 7)
        {
            PlayerMap[8].replace(3, 1, "X");

            drawScreen(PlayerMap, LevelSize0);

            PlayerMap[8].replace(3, 1, " ");
        }
        else if(Room == 8)
        {
            PlayerMap[10].replace(16, 1, "X");

            drawScreen(PlayerMap, LevelSize0);

            PlayerMap[10].replace(16, 1, " ");
        }
        else if(Room == 9)
        {
            PlayerMap[10].replace(44, 1, "X");

            drawScreen(PlayerMap, LevelSize0);

            PlayerMap[10].replace(44, 1, " ");
        }
        else if(Room == 10)
        {
            PlayerMap[5].replace(44, 1, "X");

            drawScreen(PlayerMap, LevelSize0);

            PlayerMap[5].replace(44, 1, " ");
        }
        else if(Room == 11)
        {
            PlayerMap[5].replace(58, 1, "X");

            drawScreen(PlayerMap, LevelSize0);

            PlayerMap[5].replace(58, 1, " ");
        }
        else if(Room == 12)
        {
            PlayerMap[10].replace(44, 1, "X");

            drawScreen(PlayerMap, LevelSize0);

            PlayerMap[10].replace(44, 1, " ");
        }
        else if(Room == 13)
        {
            PlayerMap[13].replace(44, 1, "X");

            drawScreen(PlayerMap, LevelSize0);

            PlayerMap[13].replace(44, 1, " ");
        }
    }
    else if(Floor == 1)
    {
        if(Room == 0)
        {
            PlayerMap[1].replace(44, 1, "X");

            drawScreen(PlayerMap, LevelSize1);

            PlayerMap[1].replace(44, 1, " ");
        }
        else if(Room == 1)
        {
            PlayerMap[10].replace(44, 1, "X");

            drawScreen(PlayerMap, LevelSize1);

            PlayerMap[10].replace(44, 1, " ");
        }
        else if(Room == 2)
        {
            PlayerMap[10].replace(29, 1, "X");

            drawScreen(PlayerMap, LevelSize1);

            PlayerMap[10].replace(29, 1, " ");
        }
        else if(Room == 3)
        {
            PlayerMap[12].replace(44, 1, "X");

            drawScreen(PlayerMap, LevelSize1);

            PlayerMap[12].replace(44, 1, " ");
        }
        else if(Room == 4)
        {
            PlayerMap[4].replace(29, 1, "X");

            drawScreen(PlayerMap, LevelSize1);

            PlayerMap[4].replace(29, 1, " ");
        }
        else if(Room == 5)
        {
            PlayerMap[10].replace(7, 1, "X");

            drawScreen(PlayerMap, LevelSize1);

            PlayerMap[10].replace(7, 1, " ");
        }
        else if(Room == 6)
        {
            PlayerMap[15].replace(7, 1, "X");

            drawScreen(PlayerMap, LevelSize1);

            PlayerMap[15].replace(7, 1, " ");
        }
        else if(Room == 7)
        {
            PlayerMap[1].replace(7, 1, "X");

            drawScreen(PlayerMap, LevelSize1);

            PlayerMap[1].replace(7, 1, " ");
        }

    }
    else if(Floor == 2)
    {
        if(Room == 0)
        {
            PlayerMap[1].replace(7, 1, "X");

            drawScreen(PlayerMap, LevelSize2);

            PlayerMap[1].replace(7, 1, " ");
        }
        else if(Room == 1)
        {
            PlayerMap[5].replace(7, 1, "X");

            drawScreen(PlayerMap, LevelSize2);

            PlayerMap[5].replace(7, 1, " ");
        }
        else if(Room == 2 || Room == 3)
        {
            PlayerMap[8].replace(7, 1, "X");

            drawScreen(PlayerMap, LevelSize2);

            PlayerMap[8].replace(7, 1, " ");
        }
        else if(Room == 4)
        {
            PlayerMap[11].replace(7, 1, "X");

            drawScreen(PlayerMap, LevelSize2);

            PlayerMap[11].replace(7, 1, " ");
        }
        else if(Room == 5)
        {
            PlayerMap[5].replace(26, 1, "X");

            drawScreen(PlayerMap, LevelSize2);

            PlayerMap[5].replace(26, 1, " ");
        }
        else if(Room == 6)
        {
            PlayerMap[12].replace(35, 1, "X");

            drawScreen(PlayerMap, LevelSize2);

            PlayerMap[12].replace(35, 1, " ");
        }
        else if(Room == 7)
        {
            PlayerMap[6].replace(33, 1, "X");

            drawScreen(PlayerMap, LevelSize2);

            PlayerMap[6].replace(33, 1, " ");
        }
        else if(Room == 8)
        {
            PlayerMap[17].replace(35, 1, "X");

            drawScreen(PlayerMap, LevelSize2);

            PlayerMap[17].replace(35, 1, " ");
        }
    }
    else if(Floor == 3)
    {
        if(Room == 0)
        {
            PlayerMap[1].replace(34, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[1].replace(34, 1, " ");
        }
        else if(Room == 1)
        {
            PlayerMap[6].replace(34, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[6].replace(34, 1, " ");
        }
        else if(Room == 2)
        {
            PlayerMap[6].replace(26, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[6].replace(26, 1, " ");
        }
        else if(Room == 3)
        {
            PlayerMap[9].replace(34, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[9].replace(34, 1, " ");
        }
        else if(Room == 4)
        {
            PlayerMap[12].replace(33, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[12].replace(33, 1, " ");
        }
        else if(Room == 5)
        {
            PlayerMap[12].replace(27, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[12].replace(27, 1, " ");
        }
        else if(Room == 6)
        {
            PlayerMap[6].replace(18, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[6].replace(18, 1, " ");
        }
        else if(Room == 7)
        {
            PlayerMap[9].replace(18, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[9].replace(18, 1, " ");
        }
        else if(Room == 8)
        {
            PlayerMap[12].replace(19, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[9].replace(18, 1, " ");
        }
        else if(Room == 9)
        {
            PlayerMap[12].replace(11, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[12].replace(11, 1, " ");
        }
        else if(Room == 10)
        {
            PlayerMap[6].replace(11, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[6].replace(11, 1, " ");
        }
        else if(Room == 11)
        {
            PlayerMap[6].replace(4, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[6].replace(4, 1, " ");
        }
        else if(Room == 12)
        {
            PlayerMap[9].replace(4, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[9].replace(4, 1, " ");
        }
        else if(Room == 13)
        {
            PlayerMap[12].replace(4, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[12].replace(4, 1, " ");
        }
        else if(Room == 14)
        {
            PlayerMap[2].replace(4, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[2].replace(4, 1, " ");
        }
        else if(Room == 15)
        {
            PlayerMap[9].replace(26, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[9].replace(26, 1, " ");
        }
        else if(Room == 16)
        {
            PlayerMap[9].replace(11, 1, "X");

            drawScreen(PlayerMap, LevelSize3);

            PlayerMap[9].replace(11, 1, " ");
        }
    }
    else if(Floor == 4)
    {
        if(Room == 0)
        {
            PlayerMap[3].replace(25, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[3].replace(25, 1, " ");
        }
        else if(Room == 1)
        {
            PlayerMap[7].replace(25, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[7].replace(25, 1, " ");
        }
        else if(Room == 2)
        {
            PlayerMap[7].replace(35, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[7].replace(35, 1, " ");
        }
        else if(Room == 3)
        {
            PlayerMap[7].replace(41, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[7].replace(41, 1, " ");
        }
        else if(Room == 4)
        {
            PlayerMap[2].replace(41, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[2].replace(41, 1, " ");
        }
        else if(Room == 5)
        {
            PlayerMap[2].replace(60, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[2].replace(60, 1, " ");
        }
        else if(Room == 6)
        {
            PlayerMap[7].replace(9, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[7].replace(9, 1, " ");
        }
        else if(Room == 7)
        {
            PlayerMap[4].replace(9, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[4].replace(9, 1, " ");
        }
        else if(Room == 8)
        {
            PlayerMap[11].replace(9, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[11].replace(9, 1, " ");
        }
        else if(Room == 9)
        {
            PlayerMap[7].replace(1, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[7].replace(1, 1, " ");
        }
        else if(Room == 10)
        {
            PlayerMap[11].replace(19, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[11].replace(19, 1, " ");
        }
        else if(Room == 11)
        {
            PlayerMap[9].replace(19, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[9].replace(19, 1, " ");
        }
        else if(Room == 12)
        {
            PlayerMap[11].replace(33, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[11].replace(33, 1, " ");
        }
        else if(Room == 13)
        {
            PlayerMap[13].replace(32, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[13].replace(32, 1, " ");
        }
        else if(Room == 14)
        {
            PlayerMap[13].replace(23, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[13].replace(23, 1, " ");
        }
        else if(Room == 15)
        {
            PlayerMap[13].replace(47, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[13].replace(47, 1, " ");
        }
        else if(Room == 16)
        {
            PlayerMap[10].replace(35, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[10].replace(35, 1, " ");
        }
        else if(Room == 17)
        {
            PlayerMap[10].replace(61, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[10].replace(61, 1, " ");
        }
        else if(Room == 18)
        {
            PlayerMap[5].replace(61, 1, "X");

            drawScreen(PlayerMap, LevelSize4);

            PlayerMap[5].replace(61, 1, " ");
        }
    }
    else if(Floor == 5)
    {
        if(Room == 0)
        {
            PlayerMap[1].replace(11, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[1].replace(11, 1, " ");
        }
        else if(Room == 1)
        {
            PlayerMap[5].replace(11, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[5].replace(11, 1, " ");
        }
        else if(Room == 2)
        {
            PlayerMap[5].replace(4, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[5].replace(4, 1, " ");
        }
        else if(Room == 3)
        {
            PlayerMap[5].replace(28, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[5].replace(28, 1, " ");
        }
        else if(Room == 4)
        {
            PlayerMap[11].replace(11, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[11].replace(11, 1, " ");
        }
        else if(Room == 5)
        {
            PlayerMap[11].replace(28, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[11].replace(28, 1, " ");
        }
        else if(Room == 6)
        {
            PlayerMap[7].replace(30, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[7].replace(30, 1, " ");
        }
        else if(Room == 7)
        {
            PlayerMap[11].replace(43, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[11].replace(43, 1, " ");
        }
        else if(Room == 8)
        {
            PlayerMap[14].replace(42, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[14].replace(42, 1, " ");
        }
        else if(Room == 9)
        {
            PlayerMap[14].replace(29, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[14].replace(29, 1, " ");
        }
        else if(Room == 10)
        {
            PlayerMap[12].replace(29, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[12].replace(29, 1, " ");
        }
        else if(Room == 11)
        {
            PlayerMap[14].replace(15, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[14].replace(15, 1, " ");
        }
        else if(Room == 12)
        {
            PlayerMap[18].replace(13, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[18].replace(13, 1, " ");
        }
        else if(Room == 13)
        {
            PlayerMap[18].replace(29, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[18].replace(29, 1, " ");
        }
        else if(Room == 14)
        {
            PlayerMap[18].replace(49, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[18].replace(49, 1, " ");
        }
        else if(Room == 15)
        {
            PlayerMap[5].replace(1, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[5].replace(1, 1, " ");
        }
        else if(Room == 16)
        {
            PlayerMap[10].replace(1, 1, "X");

            drawScreen(PlayerMap, LevelSize5);

            PlayerMap[10].replace(1, 1, " ");
        }
    }
    else if(Floor == 6)
    {
        if(Room == 0)
        {
            PlayerMap[1].replace(9, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[1].replace(9, 1, " ");
        }
        else if(Room == 1)
        {
            PlayerMap[3].replace(9, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[3].replace(9, 1, " ");
        }
        else if(Room == 2)
        {
            PlayerMap[3].replace(30, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[3].replace(30, 1, " ");
        }
        else if(Room == 3)
        {
            PlayerMap[3].replace(38, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[3].replace(38, 1, " ");
        }
        else if(Room == 4)
        {
            PlayerMap[6].replace(37, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[6].replace(37, 1, " ");
        }
        else if(Room == 5)
        {
            PlayerMap[7].replace(9, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[7].replace(9, 1, " ");
        }
        else if(Room == 6)
        {
            PlayerMap[7].replace(17, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[7].replace(17, 1, " ");
        }
        else if(Room == 7)
        {
            PlayerMap[10].replace(17, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[10].replace(17, 1, " ");
        }
        else if(Room == 8)
        {
            PlayerMap[10].replace(3, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[10].replace(3, 1, " ");
        }
        else if(Room == 9)
        {
            PlayerMap[5].replace(3, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[5].replace(3, 1, " ");
        }
        else if(Room == 10)
        {
            PlayerMap[10].replace(33, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[10].replace(33, 1, " ");
        }
        else if(Room == 11)
        {
            PlayerMap[15].replace(33, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[15].replace(33, 1, " ");
        }
        else if(Room == 12)
        {
            PlayerMap[15].replace(15, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[15].replace(15, 1, " ");
        }
        else if(Room == 13)
        {
            PlayerMap[12].replace(15, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[12].replace(15, 1, " ");
        }
        else if(Room == 14)
        {
            PlayerMap[16].replace(7, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[16].replace(7, 1, " ");
        }
        else if(Room == 15)
        {
            PlayerMap[11].replace(7, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[11].replace(7, 1, " ");
        }
        else if(Room == 16)
        {
            PlayerMap[1].replace(37, 1, "X");

            drawScreen(PlayerMap, LevelSize6);

            PlayerMap[1].replace(37, 1, " ");
        }
    }
    else if(Floor == 7)
    {
        if(Room == 0)
        {
            PlayerMap[2].replace(1, 1, "X");

            drawScreen(PlayerMap, LevelSize7);

            PlayerMap[2].replace(1, 1, " ");
        }
        else if(Room == 1)
        {
            PlayerMap[9].replace(1, 1, "X");

            drawScreen(PlayerMap, LevelSize7);

            PlayerMap[9].replace(1, 1, " ");
        }
        else if(Room == 2)
        {
            PlayerMap[8].replace(20, 1, "X");

            drawScreen(PlayerMap, LevelSize7);

            PlayerMap[8].replace(20, 1, " ");
        }
        else if(Room == 3)
        {
            PlayerMap[2].replace(19, 1, "X");

            drawScreen(PlayerMap, LevelSize7);

            PlayerMap[2].replace(19, 1, " ");
        }
        else if(Room == 4)
        {
            PlayerMap[2].replace(9, 1, "X");

            drawScreen(PlayerMap, LevelSize7);

            PlayerMap[2].replace(9, 1, " ");
        }
        else if(Room == 5)
        {
            PlayerMap[5].replace(9, 1, "X");

            drawScreen(PlayerMap, LevelSize7);

            PlayerMap[5].replace(9, 1, " ");
        }
        else if(Room == 6)
        {
            PlayerMap[2].replace(39, 1, "X");

            drawScreen(PlayerMap, LevelSize7);

            PlayerMap[2].replace(39, 1, " ");
        }
        else if(Room == 7)
        {
            PlayerMap[11].replace(39, 1, "X");

            drawScreen(PlayerMap, LevelSize7);

            PlayerMap[11].replace(29, 1, " ");
        }
        else if(Room == 8)
        {
            PlayerMap[11].replace(19, 1, "X");

            drawScreen(PlayerMap, LevelSize7);

            PlayerMap[11].replace(19, 1, " ");
        }
        else if(Room == 9)
        {
            PlayerMap[15].replace(20, 1, "X");

            drawScreen(PlayerMap, LevelSize7);

            PlayerMap[15].replace(20, 1, " ");
        }
        else if(Room == 10)
        {
            PlayerMap[18].replace(19, 1, "X");

            drawScreen(PlayerMap, LevelSize7);

            PlayerMap[18].replace(19, 1, " ");
        }
    }
    else if(Floor == 8)
    {
        if(Room == 0)
        {
            PlayerMap[1].replace(29, 1, "X");

            drawScreen(PlayerMap, LevelSize8);

            PlayerMap[1].replace(29, 1, " ");
        }
        else if(Room == 1)
        {
            PlayerMap[2].replace(28, 1, "X");

            drawScreen(PlayerMap, LevelSize8);

            PlayerMap[2].replace(28, 1, " ");
        }
        else if(Room == 2)
        {
            PlayerMap[2].replace(53, 1, "X");

            drawScreen(PlayerMap, LevelSize8);

            PlayerMap[2].replace(53, 1, " ");
        }
        else if(Room == 3)
        {
            PlayerMap[2].replace(8, 1, "X");

            drawScreen(PlayerMap, LevelSize8);

            PlayerMap[2].replace(8, 1, " ");
        }
        else if(Room == 4)
        {
            PlayerMap[8].replace(8, 1, "X");

            drawScreen(PlayerMap, LevelSize8);

            PlayerMap[8].replace(8, 1, " ");
        }
        else if(Room == 5)
        {
            PlayerMap[11].replace(6, 1, "X");

            drawScreen(PlayerMap, LevelSize8);

            PlayerMap[8].replace(6, 1, " ");
        }
        else if(Room == 6)
        {
            PlayerMap[11].replace(17, 1, "X");

            drawScreen(PlayerMap, LevelSize8);

            PlayerMap[11].replace(17, 1, "X");
        }
    }
    else if(Floor == 9)
    {
        if(Room == 0)
        {
            PlayerMap[2].replace(15, 1, "X");

            drawScreen(PlayerMap, WarlockDenSize);

            PlayerMap[2].replace(15, 1, " ");
        }
    }
    else if(Floor == 10)
    {
        if(Room == 0)
        {
            PlayerMap[3].replace(14, 1, "X");

            drawScreen(PlayerMap, SpoonTroveSize);

            PlayerMap[3].replace(14, 1, " ");
        }
    }
    else if(Floor == 11)
    {
        if(Room == 0)
        {
            PlayerMap[7].replace(10, 1, "X");

            drawScreen(PlayerMap, WizardTowerSize);

            PlayerMap[7].replace(10, 1, " ");
        }
        else if(Room == 1)
        {
            PlayerMap[7].replace(13, 1, "X");

            drawScreen(PlayerMap, WizardTowerSize);

            PlayerMap[7].replace(13, 1, " ");
        }
        else if(Room == 2)
        {
            PlayerMap[4].replace(16, 1, "X");

            drawScreen(PlayerMap, WizardTowerSize);

            PlayerMap[4].replace(16, 1, " ");
        }
        else if(Room == 3)
        {
            PlayerMap[1].replace(13, 1, "X");

            drawScreen(PlayerMap, WizardTowerSize);

            PlayerMap[1].replace(13, 1, " ");
        }
        else if(Room == 4)
        {
            PlayerMap[1].replace(9, 1, "X");

            drawScreen(PlayerMap, WizardTowerSize);

            PlayerMap[1].replace(9, 1, " ");
        }
        else if(Room == 5)
        {
            PlayerMap[4].replace(9, 1, "X");

            drawScreen(PlayerMap, WizardTowerSize);

            PlayerMap[4].replace(9, 1, " ");
        }
    }
    else if(Floor == 12)
    {
        if(Room == 0)
        {
            PlayerMap[4].replace(16, 1, "X");

            drawScreen(PlayerMap, WizardTowerSize);

            PlayerMap[4].replace(16, 1, " ");
        }
        else if(Room == 1)
        {
            PlayerMap[4].replace(13, 1, "X");

            drawScreen(PlayerMap, WizardTowerSize);

            PlayerMap[4].replace(13, 1, " ");
        }
        else if(Room == 2)
        {
            PlayerMap[4].replace(4, 1, "X");

            drawScreen(PlayerMap, WizardTowerSize);

            PlayerMap[4].replace(4, 1, " ");
        }
    }
    else if(Floor == 13)
    {
        if(Room == 0)
        {
            PlayerMap[4].replace(10, 1, "X");

            drawScreen(PlayerMap, WizardTowerSize);

            PlayerMap[4].replace(10, 1, " ");
        }
    }
    system("PAUSE");
}
//    screenwidth = "                                                                               \n",
void InvestigateMapRoom(string PlayerMap[])
{
    PlayerMap[1].replace(3, 7, "|=| /\\"); PlayerMap[1].insert(10, " ");
    PlayerMap[2].replace(3, 3, "| |");
    PlayerMap[3].replace(3, 3, "| |");
    PlayerMap[4].replace(3, 3, "| |");
    PlayerMap[5].replace(3, 3, "|_|");
}
