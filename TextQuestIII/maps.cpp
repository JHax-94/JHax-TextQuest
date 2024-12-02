#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

#include "Screens.h"

#include "maps.h"

spell NullSpells[11];

//=====================================================================================================================
//=============================WORLD===================================================================================
//=====================================================================================================================

int OryTrainingCampLocation[3] = {1, 0, 2};
int OryBarracksLocation[3] = {1, 0, 3};
int OryArcheryRangeLocation[3] = {1, 0, 4};
int OryWizardTowerLocation[3] = {1, 0, 5};

character NullResidents[1] =
{
    character()
};

int WorldML[2] = {0, 0};

building WorldTown[1] =
{
    building()
};

town WorldTowns[1] =
{
    town()
};

string WorldName = "WORLD";

string WorldMap[42] =
{
    "                   _ _ _ _                                                     \n",
    "           _ _ _ _/        \\ _ _ _ _          _ _ _       _ _ _ _ _ _          \n",
    "          / .           X           \\        /     \\_ _ _/           \\         \n",
    "         /    . . . .               /       /                        |         \n",
    "        /            . REIDLOSIA  /        |                        /          \n",
    "       /      X       . . . . . .|          \\        OREMUS        .\\          \n",
    "      |  DWEMHILL                \\          |                  . .   |         \n",
    "      |                           \\         |               .         \\        \n",
    "       \\                           \\       /            X .            |       \n",
    "        \\           . . .          |      /             .               \\      \n",
    "         \\        .       .        |     /. .         .                  \\     \n",
    "         |       .          . ..   |     |    . .   .                     |    \n",
    "         |     .     LUPESCRIA  . /      |        .        THE            |    \n",
    "        /     .      X           /       /          .          WASTES     |    \n",
    "       /     .               . ./       /             .                  /     \n",
    "       |   . . .          . .   |      /               .                 |     \n",
    "       | .       .       .      |     |                  . .             |     \n",
    "       /           . . .       /      |                       .        . |     \n",
    "      /                       /       \\                         .    .    \\    \n",
    "     |    ORYNDEL       _ _ _/         \\_ _         FYNDREL      .  .      \\   \n",
    "     |                 /                   \\                               |   \n",
    "     |                /                     \\_ _                           |   \n",
    "     \\     X        _/                  _ _ _    \\          _ _ _          |   \n",
    "      \\            /                   /      \\    \\ _ _ _ /      \\        |   \n",
    "       \\          |                  /         |                   |        \\  \n",
    "        \\_        |       _ _       /           \\_ _               |    X   |  \n",
    "           \\_ _ _/       /    \\ _ _/                \\              /       /   \n",
    "                        /                            |            /        |   \n",
    "                       |         ANCIENT'S      X    |           /        /    \n",
    "                       |            ISLAND      _ _ /            |       /     \n",
    "                        \\ _ _ _ _ _ _ _ _ _ _ /                   \\ _ _ /      \n",
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

region World(0, WorldName, WorldMap, 1, WorldTowns);

//=====================================================================================================================
//=============================ORYNDEL=================================================================================
//=====================================================================================================================

int OryldeburgML[2] = {33, 16};

int OryldeburgCompass[4][2] =
{
    {1, 4},
    {1, 5},
    {-1, -1},
    {-1, -1}
};

bool OryAdj[6][9] =
{
    {false, true, false, false, false, false, false, false, false},
    {true, false, true, false, false, false, false, false, false},
    {false, true, false, true, true, true, false, false, false},
    {false, false, true, false, false, false, false, false, false},
    {false, false, true, false, false, false, false, false, false},
    {false, false, true, false, false, false, false, false, false}
};

character OryTrainingCampRes[2] =
{
    character(false, 3, 150, 0, OryTrainingCampLocation, 70, 45, 35, 0, 45, "Captain", "Helx", "Human", "Male", NullQuests, NullSpells),
    character(false, 0, 100, 0, OryTrainingCampLocation, 0, 0, 0, 7, 0, "Dummy", "", "Dummy", "Neither", NullQuests, NullSpells)
};

character OryBarracksRes[2] =
{
    character(false, 4, 175, 0, OryBarracksLocation, 90, 50, 10, 4, 30, "Gomlij", "Brokentooth", "Orc", "Male", NullQuests, NullSpells),
    character(false, 7, 175, 0, OryBarracksLocation, 90, 50, 10, 4, 30, "Asdodsaodo", "", "Orc", "Male", NullQuests, NullSpells)
};

character OryArcheryRangeRes[2] =
{
    character(false, 5, 150, 0, OryArcheryRangeLocation, 70, 70, 10, 1, 40, "Elsi", "Swifteye", "Lupine", "Female", NullQuests, NullSpells),
    character(false, 8, 150, 0, OryArcheryRangeLocation, 70, 70, 10, 1, 40, "Crunch", "Byte", "Lupine", "Male", NullQuests, NullSpells)
};

character OryWizardTowerRes[2] =
{
    character(false, 6, 100, 200, OryWizardTowerLocation, 20, 20, 110, 3, 25, "Battlemage", "Lucius", "Ancient", "Male", NullQuests, NullSpells),
    character(false, 9, 125, 100, OryWizardTowerLocation, 30, 60, 60, 5, 40, "Illuvia", "Fuviel", "Elf", "Female", NullQuests, NullSpells)
};

building OryldeburgTown[6] =
{
    building(0, "Oryx's Palace", "ORYX'S PALACE", OryAdj[0], 1, NullResidents),
    building(1, "Town Square", "TOWN SQUARE", OryAdj[1], 1, NullResidents),
    building(2, "Training Camp" ,"TRAINING CAMP", OryAdj[2], 2, OryTrainingCampRes),
    building(3, "Barracks", "BARRACKS", OryAdj[3], 2, OryBarracksRes),
    building(4,"Archery Range", "ARCHERY RANGE", OryAdj[4], 2, OryArcheryRangeRes),
    building(5, "Wizard's Tower", "WIZARD'S TOWER", OryAdj[5], 2, OryWizardTowerRes)
};



int BreakwaterML[2] = {49, 21};

int BreakwaterCompass[4][2] =
{
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {1, 5}
};

building BreakwaterTown[1] =
{
    building()
};

int RoothillML[2] = {27, 6};

int RoothillCompass[4][2] =
{
    {-1, -1},
    {1, 4},
    {-1, -1},
    {-1, -1}
};

building RoothillTown[1] =
{
    building()
};

int GonhintonML[2] = {47, 8};

int GonhintonCompass[4][2] =
{
    {-1, -1},
    {-1, -1},
    {1, 5},
    {1, 4}
};

bool NullAdj[9] = {false, false, false, false, false, false, false, false, false};

building GonhintonTown[1] =
{
    building()
};

int OryndelNCrossML[2] = {32, 6};

int OryndelNCrossCompass[4][2] =
{
    {3, 1},
    {1, 3},
    {1, 0},
    {1, 2}
};

building OryndelNCrossTown[1] =
{
    building(0, "Crossroads", "CROSSROADS", NullAdj, 1, NullResidents)
};

int OryndelECrossML[2] = {43, 16};

int OryndelECrossCompass[4][2] =
{
    {1, 6},
    {-1, -1},
    {1, 1},
    {1, 0}
};

building OryndelECrossTown[1] =
{
    building(0, "Crossroads", "CROSSROADS", NullAdj, 1, NullResidents)
};

int OryndelNECrossML[2] = {47, 11};

int OryndelNECrossCompass[4][2] =
{
    {1, 3},
    {2, 3},
    {1, 5},
    {-1, -1}
};

building OryndelNECrossTown[1] =
{
    building(0, "Crossroads", "CROSSROADS", NullAdj, 1, NullResidents)
};

town OryndelTowns[7] =
{
    town(0, OryldeburgML, OryldeburgCompass, 6, "ORYLDEBURG", OryldeburgTown),
    town(1, BreakwaterML, BreakwaterCompass, 1, "BREAKWATER", BreakwaterTown),
    town(2, RoothillML, RoothillCompass, 1, "ROOTHILL", RoothillTown),
    town(3, GonhintonML, GonhintonCompass, 1, "GONHINTON", GonhintonTown),
    town(4, OryndelNCrossML, OryndelNCrossCompass, 1, "NORTH WEST CROSSROAD", OryndelNCrossTown),
    town(5, OryndelECrossML, OryndelECrossCompass, 1, "EAST CROSSROAD", OryndelECrossTown),
    town(6, OryndelNECrossML, OryndelNECrossCompass, 1, "NORTH EAST CROSSROAD", OryndelNECrossTown)
};

string OryndelMap[42] =
{
    "                                                                         _ _ _ \n",
    "                                                              LUPESCRIA /     |\n",
    "                                        _ _ _                     _ ||_/      |\n",
    "                              DWEMHILL /     \\                   /  ||        |\n",
    "                   _ _ _ _ _ _ _|| _ _/       \\                 /   //        |\n",
    "                  /             ||             \\               /   //        / \n",
    "                 /         o - -||              \\_ _ _ _ _ _ _/   //        /  \n",
    "                /     ROOTHILL  ||- -\\      GONHINTON            //        /   \n",
    "               /                ||    \\- - - -o                 //        /    \n",
    "              |                 ||            |         /=======/        /     \n",
    "              |                 ||            |        //   _ _ _ _ _ _ /      \n",
    "              |                 ||            /========/   /                   \n",
    "              |                 ||           //           /                    \n",
    "              |                 ||          //           /                     \n",
    "              |                 ||         //           /                      \n",
    "               \\                ||        //           /                       \n",
    "                \\               O=========/        _ _/                        \n",
    "                 \\           ORYLDEBURG   |       /                            \n",
    "                  \\                       |      /                             \n",
    "                   \\                      |     |                              \n",
    "                    \\                     |     |                              \n",
    "                     \\                    \\- - o|                              \n",
    "                      \\_ _               BREAKWATER                            \n",
    "                           \\                    /                              \n",
    "                            \\_ _ _ _ _ _ _ _ _ /                               \n",
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

region Oryndel(1, "ORYNDEL", OryndelMap, 7, OryndelTowns);

//=====================================================================================================================
//=============================LUPESCRIA=============================================================================
//=====================================================================================================================

int ValdyreikML[2] = {20, 8};

int ValdyreikCompass[4][2] =
{
    {-1, -1},
    {2, 4},
    {2, 1},
    {3, 4}
};

building ValdyreikTown[1] =
{
    building()
};

int YewvaleML[2] = {12, 12};

int YewvaleCompass[4][2] =
{
    {-1, -1},
    {2, 0},
    {-1, -1},
    {-1, -1}
};

building YewvaleTown[1] =
{
    building()
};

int AegirsideML[2] = {43, 8};

int AegirsideCompass[4][2] =
{
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {2, 4}
};


building AegirsideTown[1] =
{
    building()
};

int VegrenML[2] = {30, 11};

int VegrenCompass[4][2] =
{
    {2, 4},
    {-1, -1},
    {1, 6},
    {-1, -1}
};

building VegrenTown[1] =
{
    building()
};

int LupECrossML[2] = {8, 30};

int LupECrossCompass[4][2] =
{
    {-1, -1},
    {2, 2},
    {2, 3},
    {2, 0}
};

building LupECrossTown[1] =
{
    building(0, "Crossroads", "CROSSROADS", NullAdj, 1, NullResidents)
};

town LupescriaTowns[5] =
{
    town(0, ValdyreikML, ValdyreikCompass, 1, "VALDYREIK", ValdyreikTown),
    town(1, YewvaleML, YewvaleCompass, 1, "YEWVALE", YewvaleTown),
    town(2, AegirsideML, AegirsideCompass, 1, "AEGIRSIDE", AegirsideTown),
    town(3, VegrenML, VegrenCompass, 1, "VEGREN", VegrenTown),
    town(4, LupECrossML, LupECrossCompass, 1, "EAST CROSSROAD", LupECrossTown)
};

string LupescriaMap[42] =
{
    "   DEWMHILL _ _ _ _ _ _ _ _ _ _                                                \n",
    "         \\\\/                   \\                                               \n",
    "          \\\\                    \\                                              \n",
    "         / \\\\                    \\                                             \n",
    "        /   \\\\                    \\_ _ _                                       \n",
    "       /    ||                           \\                                     \n",
    "      /     ||                            \\                                    \n",
    "     /      ||  VALDYREIK          AEGIRSIDE                                   \n",
    "    /        \\\\== O ========\\\\- - - - -o /                                     \n",
    "   /              |          ||         /                                      \n",
    "  /               |          ||   _ _ _/                                       \n",
    " /      YEWVALE   |   VEGREN |o  /                                             \n",
    "/_ _ _      o - - |        _ ||_/                                              \n",
    "      \\                   /  ||                                                \n",
    "       \\                 /   ORYNDEL                                           \n",
    "        \\               /                                                      \n",
    "         \\_ _ _ _ _ _ _/                                                       \n",
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
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n",
    "                                                                               \n"
};

region Lupescria(2, "LUPESCRIA", LupescriaMap, 5, LupescriaTowns);

//=====================================================================================================================
//=============================DWEMHILL================================================================================
//=====================================================================================================================


int DwemenheimML[2] = {12, 7};

int DwemenheimCompass[4][2] =
{
    {-1, -1},
    {3, 1},
    {-1, -1},
    {-1, -1}
};

building DwemenheimTown[1] =
{
    building()
};

int NotchkreuzML[2] = {16, 10};

int NotchkreuzCompass[4][2] =
{
    {3, 0},
    {3, 4},
    {1, 4},
    {-1, -1}
};

building NotchkreuzTown[1] =
{
    building()
};

int AnkrFjorML[2] = {41, 10};

int AnkrFjorCompass[4][2] =
{
	{-1, -1},
	{-1, -1},
	{3, 5},
	{-1, -1}
};

building AnkrFjorTown[1] =
{
    building()
};

int OzebruckeML[2] = {74, 14};

int OzebruckeCompass[4][2] =
{
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{3, 5}
};


building OzebruckeTown[1] =
{
    building()
};

int DwemCCrossML[2] = {33, 14};

int DwemCCrossCompass[4][2] =
{
    {3, 1},
    {3, 5},
    {2, 0},
    {-1, -1}
};

building DwemCCrossTown[1] =
{
    building(0, "Crossroads", "CROSSROADS", NullAdj, 1, NullResidents)
};

int DwemECrossML[2] = {42, 14};

int DwemECrossCompass[4][2] =
{
    {-1, -1},
    {2, 2},
    {2, 3},
    {2, 0}
};

building DwemECrossTown[1] =
{
    building(0, "Crossroads", "CROSSROADS", NullAdj, 1, NullResidents)
};

string DwemhillMap[42] =
{
    "        /\\                                                                     \n",
    "       /  \\                                                                    \n",
    "      /    \\                         REIDLOSIA                                 \n",
    "     /      \\_ _ _ _ _ _ _ _                                                   \n",
    "    /                       \\                                                  \n",
    "   /                         \\                                                 \n",
    "  /        DWEMENHEIM         \\                                                \n",
    " /          O===\\              \\_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _            \n",
    "|              ||                                                  \\           \n",
    "|           NOTCHKREUZ                  ANKR-FJOR                   \\          \n",
    "|              |o==========\\            o                            \\         \n",
    "|              ||          \\\\           |                             \\        \n",
    " \\             ||           \\\\          |                              \\       \n",
    "  \\            ||            \\\\         |                     OZEBRUCKE \\      \n",
    "   \\           ||             \\\\- - - - - - - - - - - - - - - - - - - -o|      \n",
    "    \\          ||              \\\\  _ _ _ _ _ _ _ _ _ _                  |      \n",
    "     \\         ||               \\\\/                    \\                |      \n",
    "      \\        ||                \\\\                     \\               |      \n",
    "      |        ||               / \\\\                     \\              |      \n",
    "      |        ||              /  LUPESCRIA               \\_ _ _ _      |      \n",
    "      |        ||             /                                    \\   /       \n",
    "      |        ||            /                                      \\_/        \n",
    "     /         ||           /                                                  \n",
    "    /          ||          /                                                   \n",
    "   /           ||         /                                                    \n",
    "  /            ||        /                                                     \n",
    " |             ||       /                                                      \n",
    " |             ||      /                                                       \n",
    " |             ||     /                                                        \n",
    " |_ _ _ _ _ _ _|| _ _/                                                         \n",
    "               ||                                                              \n",
    "             ORYNDEL                                                           \n",
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


town DwemhillTowns[6] =
{
    town(0, DwemenheimML, DwemenheimCompass, 1, "DWEMENHEIM", DwemenheimTown),
    town(1, NotchkreuzML, NotchkreuzCompass, 1, "NOTCHKREUZ", NotchkreuzTown),
    town(2, AnkrFjorML, AnkrFjorCompass, 1, "ANKR-FJOR", AnkrFjorTown),
    town(3, OzebruckeML, OzebruckeCompass, 1, "OZEBRUKE", OzebruckeTown),
    town(4, DwemCCrossML, DwemCCrossCompass, 1, "CENTRAL CROSSROAD", DwemCCrossTown),
    town(5, DwemECrossML, DwemECrossCompass, 1, "EASTERN CROSSROAD", DwemECrossTown)
};

region Dwemhill(3, "DWEMHILL", DwemhillMap, 6, DwemhillTowns);

//=====================================================================================================================
//=============================ANCIENT'S ISLAND=======================================================================
//=====================================================================================================================

int AntiquusCuoreML[2] = {48, 13};

int AntiquusCuoreCompass[4][2] =
{
	{4, 3},
	{4, 4},
	{4, 1},
	{-1, -1}
};

building AntiquusCuoreTown[1] =
{
    building()
};

int ProlixusAciesML[2] = {20, 15};

building ProlixusAciesTown[1] =
{
    building()
};

int ProlixusAciesCompass[4][2] =
{
	{-1, -1},
	{4, 0},
	{-1, -1},
	{4, 2}
};

int AmbitusOccidensML[2] = {6, 8};

int AmbitusOccidensCompass[4][2] =
{
	{-1, -1},
	{-1, -1},
	{4, 1},
	{-1, -1}
};

building AmbitusOccidensTown[1] =
{
    building()
};

int CultellusML[2] = {36, 9};

int CultellusCompass[4][2] =
{
	{-1, -1},
	{4, 0},
	{-1, -1},
	{-1, -1}
};

building CultellusTown[1] =
{
    building()
};

int AmbitusOrientML[2] = {54, 8};

int AmbitusOrientCompass[4][2] =
{
	{-1, -1},
	{-1, -1},
	{4, 0},
	{-1, -1}
};

building AmbitusOrientTown[1] =
{
    building()
};

string AncientMap[42] =
{
    "                                                                           \n",
    "                                _ _ _ _ _ _                                \n",
    "                              /             \\                              \n",
    "                             /               \\                             \n",
    "                            /                |                             \n",
    "                           /                 |                             \n",
    "                          /                   \\                            \n",
    "     _ _ _ _             /                     \\_ _ _ _                    \n",
    "    / o      \\          /     CULTELLUS              o \\ AMBITUS-ORIENT    \n",
    "   /  |AMBITUS\\ _ _ _ _/           o - - - - - -\\     \\ \\                  \n",
    "  /   |  -OCCIDENS                              |     | |                  \n",
    " /    |                                         |     | |                  \n",
    "|     |                                 ANTIQUUS-CUORE| |                  \n",
    "|     |                                 /- - - -O- - -/ |                  \n",
    "|      \\                                |               /                  \n",
    "|       \\- - - - - o - - - - - - - - - -/      _ _ _ _ /                   \n",
    " \\           PROLIXUS-ACIES                  /                             \n",
    "  \\ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ /                              \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n"
};

town AncientTowns[5] =
{
    town(0, AntiquusCuoreML, AntiquusCuoreCompass, 1, "ANTIQUUS-CUORE", AntiquusCuoreTown),
    town(1, ProlixusAciesML, ProlixusAciesCompass, 1, "PROLIXUS-ACIES", ProlixusAciesTown),
    town(2, AmbitusOccidensML, AmbitusOccidensCompass, 1, "AMBITUS-OCCIDENS", AmbitusOccidensTown),
    town(3, CultellusML, CultellusCompass, 1, "CULTELLUS", CultellusTown),
    town(4, AmbitusOrientML, AmbitusOrientCompass, 1, "AMBITUS-ORIENT", AmbitusOrientTown)
};

region AncientIsland(4, "ANCIENT'S ISLAND", AncientMap, 5, AncientTowns);

//=====================================================================================================================
//=============================OREMUS==================================================================================
//=====================================================================================================================

int WastesEdgeML[2] = {29, 14};

int WastesEdgeCompass[4][2] =
{
	{5, 4},
	{-1, -1},
	{-1, -1},
	{6, 4}
};

building WastesEdgeTown[1] =
{
    building()
};

int OremheadML[2] = {12, 9};

int OremheadCompass[4][2] =
{
	{-1, -1},
	{5, 4},
	{-1, -1},
	{-1, -1}
};

building OremheadTown[1] =
{
    building()
};

int SkullsRestML[2] = {44, 9};

int SkullsRestCompass[4][2] =
{
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{5, 4}
};

building SkullsRestTown[1] =
{
    building()
};

int SkheidCreekML[2] = {29, 4};

int SkheidCreekCompass[4][2] =
{
	{-1, -1},
	{-1, -1},
	{5, 4},
	{-1, -1}
};


building SkheidCreekTown[1] =
{
    building()
};

int OreCrossML[2] = {29, 9};

int OreCrossCompass[4][2] =
{
	{5, 3},
	{5, 2},
	{5, 0},
	{5, 1}
};


building OreCrossTown[1] =
{
    building(0, "Crossroad", "CROSSROAD", NullAdj, 1, NullResidents)
};

string OremusMap[42] =
{
    "                                                                               \n",
    "       _ _ _ _ _ _               _ _ _ _ _ _ _ _ _ _ _ _                       \n",
    "      /           \\             /                       \\                      \n",
    "     /             \\_ _ _ _ _ _/                         \\                     \n",
    "    |                        o                           |                     \n",
    "    |                       SKHEID-CREEK                 |                     \n",
    "     \\                       |                          /                      \n",
    "      \\                      |                         /                       \n",
    "      |   OREMHEAD           |            SKULL'S REST \\                       \n",
    "      |     o - - - - - - - -|- - - - - - - o        _ _\\                      \n",
    "      |                      |                      /                          \n",
    "      |                      |     _ _ _ _ _ _ _ _ /                           \n",
    "     /                       |   /                                             \n",
    "    /                     WASTE'S EDGE                                         \n",
    "   /         //==============O /                                               \n",
    "  /          ||               /                                                \n",
    " /           ||              /                                                 \n",
    "/_ _ _ _     ||             /                                                  \n",
    "        \\    ||            /                                                   \n",
    "         \\   ||           /           THE                                      \n",
    "          \\  ||          /                WASTES                               \n",
    "           \\_|| _ _     /                                                      \n",
    "             ||     \\  /                                                       \n",
    "           FYNDREL   \\/                                                        \n",
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

town OremusTowns[5] =
{
    town(0, WastesEdgeML, WastesEdgeCompass, 1,  "WASTE'S EDGE", WastesEdgeTown),
    town(1, OremheadML, OremheadCompass, 1, "OREMHEAD", OremheadTown),
    town(2, SkullsRestML, SkullsRestCompass, 1, "SKULL'S REST", SkullsRestTown),
    town(3, SkheidCreekML, SkheidCreekCompass, 1, "SKHEID-CREEK", SkheidCreekTown),
    town(4, OreCrossML, OreCrossCompass, 1, "CENTRAL CROSSROADS", OreCrossTown)
};

region Oremus(5, "OREMUS", OremusMap, 5, OremusTowns);

//=====================================================================================================================
//=============================FYNDREL=================================================================================
//=====================================================================================================================

int GreycoveML[2] = {53, 30};

int GreycoveCompass[4][2] =
{
	{-1, -1},
	{6, 5},
	{6, 1},
	{-1, -1}
};

building GreycoveTown[1] =
{
    building()
};

int SouthseaML[2] = {55, 38};

int SouthseaCompass[4][2] =
{
	{6, 0},
	{-1, -1},
	{-1, -1},
	{-1, -1}
};

building SouthseaTown[1] =
{
    building()
};

int CliffwatchML[2] = {29, 15};

int CliffwatchCompass[4][2] =
{
	{6, 5},
	{-1, -1},
	{-1, -1},
	{-1, -1}
};


building CliffwatchTown[1] =
{
    building()
};

int OremClearingML[2] = {14, 7};

int OremClearingCompass[4][2] =
{
	{-1, -1},
	{6, 3},
	{-1, -1},
	{-1, -1}
};


building OremClearingTown[1] =
{
    building()
};

int FynNWCrossML[2] = {21, 7};

int FynNWCrossCompass[4][2] =
{
	{5, 0},
	{-1, -1},
	{6, 5},
	{6, 3}
};

building FynNWCrossTown[1] =
{
    building(0, "Crossroad", "CROSSROAD", NullAdj, 1, NullResidents)
};

int FynCCrossML[2] = {35, 23};

int FynCCrossCompass[4][2] =
{
	{6, 4},
	{6, 0},
	{-1, -1},
	{6, 2}
};

building FynCCrossTown[1] =
{
    building(0, "Crossroad", "CROSSROAD", NullAdj, 1, NullResidents)
};

string FyndrelMap[42] =
{
    "                                                                           \n",
    "        _ _ _ _                                                            \n",
    "       |       \\                                                           \n",
    "       |        \\                                                          \n",
    "       |         \\     OREMUS                                              \n",
    "       |          \\_|| _ _                                                 \n",
    "      /             ||     \\             THE                               \n",
    "     /        o- - -||      \\                WASTES                        \n",
    "    / OREM-CLEARING ||       \\                                             \n",
    "   /                ||        \\                                            \n",
    "  /                 ||         \\                                           \n",
    " /                  ||          \\                                          \n",
    "|                   ||           \\                                         \n",
    "|                   ||            \\                                        \n",
    "|                   ||             \\                                       \n",
    "|                   ||              \\_ _ _                _ _              \n",
    "\\                   \\\\=====\\\\              \\             /    \\            \n",
    " \\                          \\\\              \\_ _        /      \\           \n",
    "  \\                          \\\\                  \\     /        \\          \n",
    "   \\_ _ _ _                   \\\\                  \\_ _/          \\         \n",
    "           \\                   \\\\                                |         \n",
    "            \\                   \\\\                               |         \n",
    "             \\                   \\\\                              |         \n",
    "              \\_ _           /- - \\\\======================\\\\     |         \n",
    "                   \\        /                              \\\\    |         \n",
    "                     \\      o           _ _ _ _ _ _          \\\\   |         \n",
    "                      \\  CLIFFWATCH   /            \\\\        ||   |         \n",
    "                       \\ _ _ _ _ _ _ /              \\\\       ||   |         \n",
    "                                                    |       ||    \\        \n",
    "                                                    |       ||     \\       \n",
    "                                                    |O======//     |       \n",
    "                                                    |GREYCOVE      |       \n",
    "                                                    /|            /        \n",
    "                                                   /  \\          /         \n",
    "                                                  /    \\         |         \n",
    "                                                 /     |         |         \n",
    "                                                /      |        /          \n",
    "                                               /       |       /           \n",
    "                                               |       o      /            \n",
    "                                               |  SOUTHSEA   /             \n",
    "                                                \\           /              \n",
    "                                                 \\ _ _ _ _ /               \n"
};

town FyndrelTowns[6] =
{
    town(0, GreycoveML, GreycoveCompass, 1, "GREYCOVE", GreycoveTown),
    town(1, SouthseaML, SouthseaCompass, 1, "SOUTHSEA", SouthseaTown),
    town(2, CliffwatchML, CliffwatchCompass, 1, "CLIFFWATCH", CliffwatchTown),
    town(3, OremClearingML, OremClearingCompass, 1, "OREM-CLEARING", OremClearingTown),
    town(4, FynNWCrossML, FynNWCrossCompass, 1, "NORTH WEST CROSSROAD", FynNWCrossTown),
    town(5, FynCCrossML, FynCCrossCompass, 1, "CENTRAL CROSSROAD", FynCCrossTown)
};

region Fyndrel(6, "FYNDREL", FyndrelMap, 6, FyndrelTowns);

//=====================================================================================================================
//=============================THE WASTES==============================================================================
//=====================================================================================================================

int TheWastesML[2] = {0, 0};

int TheWastesCompass[4][2] =
{
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1}
};

building TheWastesTown[1] =
{
    building()
};

string WastesMap[42] =
{
    "                                _ _                                            \n",
    "                               /   |                                           \n",
    "              _ _ _ _ _ _ _ _ /    |                                           \n",
    "            /                       \\                                          \n",
    "           /                         \\                                         \n",
    "          /                           |                                        \n",
    "         /                            |                                        \n",
    "        /                              \\                                       \n",
    "       /                                \\                                      \n",
    "      /                                  \\                                     \n",
    "     /                                    \\                                    \n",
    "    /                                     |                                    \n",
    "   /              THE                     |                                    \n",
    "  /                   WASTES              |                                    \n",
    " /                                        |                                    \n",
    " \\                                        |                                    \n",
    "  \\                                       |                                    \n",
    "   \\                                      /                                    \n",
    "    \\                                    /                                     \n",
    "     \\                                   |                                     \n",
    "      \\                                  |                                     \n",
    "       \\                                 |                                     \n",
    "        \\                                |                                     \n",
    "         \\                           _ _ /                                     \n",
    "          \\_ _ _                _ _ /                                          \n",
    "                 \\             /                                               \n",
    "                  \\_ _        /                                                \n",
    "                       \\     /                                                 \n",
    "                        \\_ _/                                                  \n",
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

town TheWastesTowns[1] =
{
    town(0, TheWastesML, TheWastesCompass, 1, "", TheWastesTown)
};

region TheWastes(7, "THE WASTES", WastesMap, 1, TheWastesTowns);

//=====================================================================================================================
//=============================REIDLOSIA===============================================================================
//=====================================================================================================================

int CataclysmML[2] = {30, 3};

int CataclysmCompass[4][2] =
{
	{-1, -1},
	{8, 2},
	{-1, -1},
	{8, 1}
};

building CataclysmTown[1] =
{
    building()
};

int EndworldML[2] = {5, 3};

int EndworldCompass[4][2] =
{
	{-1, -1},
	{-1, -1},
	{8, 0},
	{-1, -1}
};

building EndworldTown[1] =
{
    building()
};

int DoomgladeML[2] = {45, 9};

int DoomgladeCompass[4][2] =
{
	{8, 0},
	{-1, -1},
	{-1, -1},
	{-1, -1}
};

building DoomgladeTown[1] =
{
    building()
};

string ReidlosiaMap[42] =
{
    "                  _ _ _ _ _ _ _ _                                          \n",
    "                 /                \\                                        \n",
    "_ _ _ _ _ _ _ _ /                  \\_ _ _ _ _ _ _ _ _ _ _ _                \n",
    "\\   o ENDWORLD             /-O- - - - - -\\                  \\              \n",
    " \\  |- - - - - - - - - - -/CATACLYSM      \\                  \\             \n",
    "  \\                                        \\                 /             \n",
    "   \\_ _ _ _ _ _ _ _                         \\               /              \n",
    "                   \\                        |              /               \n",
    "                    \\                       |             /                \n",
    "                     \\                      o DOOMGLADE  |                 \n",
    "                      \\_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |                 \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n",
    "                                                                           \n"
};

town ReidlosiaTowns[3] =
{
    town(0, CataclysmML, CataclysmCompass, 1, "CATACLYSM", CataclysmTown),
    town(1, EndworldML, EndworldCompass, 1, "ENDWORLD", EndworldTown),
    town(2, DoomgladeML, DoomgladeCompass, 1, "DOOMGLADE", DoomgladeTown)
};

region Reidlosia(8, "REIDLOSIA", ReidlosiaMap, 3, ReidlosiaTowns);

region Atlas[9] = {World, Oryndel, Lupescria, Dwemhill, AncientIsland, Oremus, Fyndrel, TheWastes, Reidlosia};

void MapMenu()
{

    bool MenuOn;

    int ID;
    int i;
    int Choice;

    MenuOn = true;



    string Options[9] =
    {
        "Back to World Map", "Oryndel", "Lupescria", "Dwemhill", "Ancient Island", "Oremus", "Fyndrel", "The Wastes", "Reidlosia"
    };

    string Available[9];

    ID = 0;

    while(MenuOn == true)
    {
        Atlas[(ID)].ViewMap();

        int j = 0;

        for(i = 0; i < 9; i ++)
        {

            if(i != (ID))
            {
                Available[j] = Options[i];

                j++;
            }
        }

        cout << "  1 - " << Available[0] << endl;
        cout << "  2 - " << Available[1] << endl;
        cout << "  3 - " << Available[2] << endl;
        cout << "  4 - " << Available[3] << endl;
        cout << "  5 - " << Available[4] << endl;
        cout << "  6 - " << Available[5] << endl;
        cout << "  7 - " << Available[6] << endl;
        cout << "  8 - " << Available[7] << endl;
        cout << "  9 - Back to Menu" << endl << endl;

        cin >> Choice;

        if(Choice == 9)
        {
            MenuOn = false;
            break;
        }
        else if(Choice > 9)
        {
            cout << "This is not an option!\n\n";
            system("PAUSE");
        }
        else if(Choice > ID)
        {
            ID = Choice;
        }
        else if(Choice <= ID)
        {
            ID = Choice - 1;
        }
    }
    return;
}

void region::ViewMap()
{
    DrawScreen("MAPS", Name, Map, 42, true);

   // system("PAUSE");
}
