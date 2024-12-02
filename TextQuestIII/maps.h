#ifndef MAPS_H_INCLUDED
#define MAPS_H_INCLUDED

#include <string>
#include "towns.h"


void MapMenu();

class region
{
    private:

    void init(int NewID, string NewName, string NewMap[42], int NewRegionSize, town NewTowns[])
    {
        int i;

        ID = NewID;
        Name = NewName;
        for(i = 0; i < 42; i ++)
        {
            Map[i] = NewMap[i];
        }

        Towns = new town[NewRegionSize];

        for(i = 0; i < NewRegionSize; i ++)
        {
            Towns[i] = NewTowns[i];
        }
    }

    public:

    int ID;

    string Name;
    string Map[42];

    int RegionSize;
    //town Towns[32];
    town * Towns;

    void ViewMap();

    string RegionInfo();

    region(int NewID, string NewName, string NewMap[42], int NewRegionSize, town NewTowns[])
    {
        init(NewID, NewName, NewMap, NewRegionSize, NewTowns);
    }

};

extern region Atlas[9];


/*

//=====================================================================================================================
//=============================WORLD===================================================================================
//=====================================================================================================================

int WorldML[2] = {0, 0};

building WorldTown[2] =
{
    building()
};

town WorldTowns[1] =
{
    town(-1, WorldML, 1, "", WorldTown)
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

region World(-1, WorldName, WorldMap, 1, WorldTowns);

//=====================================================================================================================
//=============================ORYNDEL=================================================================================
//=====================================================================================================================

int OryldeburgML[2] = {33, 16};

building OryldeburgTown[3] =
{
    building("Oryx's Palace", "ORYX'S PALACE"),
    building("Town Square", "TOWN SQUARE"),
    building("Training Camp" ,"TRAINING CAMP")
};

int BreakwaterML[2] = {49, 21};

building BreakwaterTown[1] =
{
    building()
};

int RoothillML[2] = {27, 6};

building RoothillTown[1] =
{
    building()
};

int GonhintonML[2] = {47, 8};

building GonhintonTown[1] =
{
    building()
};

town OryndelTowns[4]
{
    town(0, OryldeburgML, 3, "ORYLDEBURG", OryldeburgTown),
    town(1, BreakwaterML, 1, "BREAKWATER", BreakwaterTown),
    town(2, RoothillML, 1, "ROOTHILL", RoothillTown),
    town(3, GonhintonML, 1, "GONHINTON", GonhintonTown)
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

region Oryndel(0, "ORYNDEL", OryndelMap, 4, OryndelTowns);

//=====================================================================================================================
//=============================LUPESCRIA=============================================================================
//=====================================================================================================================

int ValdyreikML[2] = {20, 8};

building ValdyreikTown[1] =
{
    building()
};

int YewvaleML[2] = {12, 12};

building YewvaleTown[1] =
{
    building()
};

int AegirsideML[2] = {43, 8};

building AegirsideTown[1] =
{
    building()
};

int VegrenML[2] = {30, 11};

building VegrenTown[1] =
{
    building()
};

town LupescriaTowns[4] =
{
    town(0, ValdyreikML, 1, "VALDYREIK", ValdyreikTown),
    town(1, YewvaleML, 1, "YEWVALE", YewvaleTown),
    town(2, AegirsideML, 1, "AEGIRSIDE", AegirsideTown),
    town(3, VegrenML, 1, "VEGREN", VegrenTown)
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

region Lupescria(1, "LUPESCRIA", LupescriaMap, 4, LupescriaTowns);

//=====================================================================================================================
//=============================DWEMHILL================================================================================
//=====================================================================================================================


int DwemenheimML[2] = {12, 7};

building DwemenheimTown[1] =
{
    building()
};

int NotchkreuzML[2] = {16, 10};

building NotchkreuzTown[1] =
{
    building()
};

int AnkrFjorML[2] = {41, 10};

building AnkrFjorTown[1] =
{
    building()
};

int OzebruckeML[2] = {74, 14};

building OzebruckeTown[1] =
{
    building()
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


town DwemhillTowns[4] =
{
    town(0, DwemenheimML, 1, "DWEMENHEIM", DwemenheimTown),
    town(1, NotchkreuzML, 1, "NOTCHKREUZ", NotchkreuzTown),
    town(2, AnkrFjorML, 1, "ANKR-FJOR", AnkrFjorTown),
    town(3, OzebruckeML, 1, "OZEBRUKE", OzebruckeTown)
};

region Dwemhill(2, "DWEMHILL", DwemhillMap, 4, DwemhillTowns);

//=====================================================================================================================
//=============================ANCIENT'S ISLAND=======================================================================
//=====================================================================================================================

int AntiquusCuoreML[2] = {48, 13};

building AntiquusCuoreTown[1] =
{
    building()
};

int ProlixusAciesML[2] = {20, 15};

building ProlixusAciesTown[1] =
{
    building()
};

int AmbitusOccidensML[2] = {6, 8};

building AmbitusOccidensTown[1] =
{
    building()
};

int CultellusML[2] = {36, 9};

building CultellusTown[1] =
{
    building()
};

int AmbitusOrientML[2] = {54, 8};

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
    town(0, AntiquusCuoreML, 1, "ANTIQUUS-CUORE", AntiquusCuoreTown),
    town(1, ProlixusAciesML, 1, "PROLIXUS-ACIES", ProlixusAciesTown),
    town(2, AmbitusOccidensML, 1, "AMBITUS-OCCIDENS", AmbitusOccidensTown),
    town(3, CultellusML, 1, "CULTELLUS", CultellusTown),
    town(4, AmbitusOrientML, 1, "AMBITUS-ORIENT", AmbitusOrientTown)
};

region AncientIsland(3, "ANCIENT'S ISLAND", AncientMap, 5, AncientTowns);

//=====================================================================================================================
//=============================OREMUS==================================================================================
//=====================================================================================================================

int WastesEdgeML[2] = {29, 14};

building WastesEdgeTown[1] =
{
    building()
};

int OremheadML[2] = {12, 9};

building OremheadTown[1] =
{
    building()
};

int SkullsRestML[2] = {44, 9};

building SkullsRestTown[1] =
{
    building()
};

int SkheidCreekML[2] = {29, 4};

building SkheidCreekTown[1] =
{
    building()
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

town OremusTowns[4] =
{
    town(0, WastesEdgeML, 1,  "WASTE'S EDGE", WastesEdgeTown),
    town(1, OremheadML, 1, "OREMHEAD", OremheadTown),
    town(2, SkullsRestML, 1, "SKULL'S REST", SkullsRestTown),
    town(3, SkheidCreekML, 1, "SKHEID-CREEK", SkheidCreekTown)
};

region Oremus(4, "OREMUS", OremusMap, 4, OremusTowns);

//=====================================================================================================================
//=============================FYNDREL=================================================================================
//=====================================================================================================================

int GreycoveML[2] = {53, 30};

building GreycoveTown[1] =
{
    building()
};

int SouthseaML[2] = {55, 38};

building SouthseaTown[1] =
{
    building()
};

int CliffwatchML[2] = {29, 15};

building CliffwatchTown[1] =
{
    building()
};

int OremClearingML[2] = {14, 7};

building OremClearingTown[1] =
{
    building()
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

town FyndrelTowns[4] =
{
    town(0, GreycoveML, 1, "GREYCOVE", GreycoveTown),
    town(1, SouthseaML, 1, "SOUTHSEA", SouthseaTown),
    town(2, CliffwatchML, 1, "CLIFFWATCH", CliffwatchTown),
    town(3, OremClearingML, 1, "OREM-CLEARING", OremClearingTown)
};

region Fyndrel(5, "FYNDREL", FyndrelMap, 4, FyndrelTowns);

//=====================================================================================================================
//=============================THE WASTES==============================================================================
//=====================================================================================================================

int TheWastesML[2] = {0, 0};

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
    town(-1, TheWastesML, 1, "", TheWastesTown)
};

region TheWastes(6, "THE WASTES", WastesMap, 1, TheWastesTowns);

//=====================================================================================================================
//=============================REIDLOSIA===============================================================================
//=====================================================================================================================

int CataclysmML[2] = {30, 3};

building CataclysmTown[1] =
{
    building()
};

int EndworldML[2] = {5, 3};

building EndworldTown[1] =
{
    building()
};

int DoomgladeML[2] = {45, 9};

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
    town(0, CataclysmML, 1, "CATACLYSM", CataclysmTown),
    town(1, EndworldML, 1, "ENDWORLD", EndworldTown),
    town(2, DoomgladeML, 1, "DOOMGLADE", DoomgladeTown)
};

region Reidlosia(7, "REIDLOSIA", ReidlosiaMap, 3, ReidlosiaTowns);
*/
#endif // MAPS_H_INCLUDED
