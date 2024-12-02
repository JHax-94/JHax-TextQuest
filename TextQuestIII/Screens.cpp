#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <math.h>

#include"screens.h"

using namespace std;

#include"Inputs.h"
#include"maps.h"

int CountAlive(character TestParty[3])
{
    int Count = 0;

    for(int i = 0; i < 3; i ++)
    {
        if(TestParty[i].Health[0] != 0)
        {
            Count ++;
        }
    }

    return Count;
}

void DrawScreen(string Screen[], int ScreenSize)
{
    system("CLS");

    int i;

    for(i = 0; i < ScreenSize; i ++)
    {
        cout << Screen[i];
    }
}

void DrawScreen(string Heading, string Screen[], int ScreenSize)
{
    system("CLS");

    int HeadLength;
    int i;

    string Banner[3] =
    {
        "================================================================================",
        "================================================================================",
        "================================================================================"
    };

    HeadLength = Heading.length();
/*
    cout << "Heading length: " << HeadLength << endl;

    cout << "Half Heading Length: " << HeadLength/2 << endl;
*/
    Banner[1].replace((40-(HeadLength/2)), HeadLength, Heading);

    for(i = 0; i < 3; i ++)
    {
        cout << Banner[i];
    }
    for(i = 0; i < ScreenSize; i ++)
    {
        cout << Screen[i];
    }
}

void DrawScreen(string Heading, string SubHeading, string Screen[], int ScreenSize)
{
    system("CLS");

    int HeadLength;
    int SubHeadLength;
    int i;

    string Banner[3] =
    {
        "================================================================================",
        "================================================================================",
        "================================================================================"
    };

    HeadLength = Heading.length();
    SubHeadLength = SubHeading.length();

    Banner[1].replace((40-(HeadLength/2)), HeadLength, Heading);
    Banner[2].replace((40-(SubHeadLength/2)), SubHeadLength, SubHeading);

    for(i = 0; i < 3; i ++)
    {
        cout << Banner[i];
    }
    for(i = 0; i < ScreenSize; i ++)
    {
        cout << Screen[i];
    }
}

void DrawScreen(string Heading, string SubHeading, string Screen[], int ScreenSize, bool compass)
{
    system("CLS");

    int HeadLength;
    int SubHeadLength;
    int i;

    string Banner[3] =
    {
        "================================================================================",
        "================================================================================",
        "================================================================================"
    };

    if(compass == true)
    {
        Banner[0] = "===========================================================================N====";
        Banner[1] = "=========================================================================W + E==";
        Banner[2] = "===========================================================================S====";
    }


    HeadLength = Heading.length();
    SubHeadLength = SubHeading.length();

    Banner[1].replace((40-(HeadLength/2)), HeadLength, Heading);
    Banner[2].replace((40-(SubHeadLength/2)), SubHeadLength, SubHeading);

    for(i = 0; i < 3; i ++)
    {
        cout << Banner[i];
    }
    for(i = 0; i < ScreenSize; i ++)
    {
        cout << Screen[i];
    }
}

void DrawScreen(string Heading, string SubHeading, string Screen[], string Name, int ScreenSize, bool compass)
{
    system("CLS");

    int HeadLength;
    int SubHeadLength;
    int NameLength;
    int i;

    string Banner[3] =
    {
        "================================================================================",
        "================================================================================",
        "================================================================================"
    };

    if(compass == true)
    {
        Banner[0] = "===========================================================================N====";
        Banner[1] = "=========================================================================W + E==";
        Banner[2] = "===========================================================================S====";
    }

    NameLength = Name.length();
    HeadLength = Heading.length();
    SubHeadLength = SubHeading.length();

    Banner[0].replace(2, 11+NameLength, "Character: " + Name);
    Banner[1].replace((40-(HeadLength/2)), HeadLength, Heading);
    Banner[2].replace((40-(SubHeadLength/2)), SubHeadLength, SubHeading);

    for(i = 0; i < 3; i ++)
    {
        cout << Banner[i];
    }
    for(i = 0; i < ScreenSize; i ++)
    {
        cout << Screen[i];
    }
}


void ClearScreen(string Screen[], int ScreenSize)
{
    int i;

    for(i = 0; i < ScreenSize; i ++)
    {
        Screen[i] = "                                                                               \n";
    }
}

void ClearScreen(string Screen[], int Start, int Finish)
{
    int i;

    for(i = Start; i < (Finish); i ++)
    {
        Screen[i] = "                                                                               \n";
    }
}

void WriteStats(string Screen[], character Player[3], int nCC)
{
    string sHealthCur = Player[nCC].WriteCurHealth();
    string sHealthMax = Player[nCC].WriteMaxHealth();
    string sMagicCur = Player[nCC].WriteCurMagic();
    string sMagicMax = Player[nCC].WriteMaxMagic();
    string sStr = Player[nCC].WriteStr();
    string sAgi = Player[nCC].WriteAgi();
    string sInt = Player[nCC].WriteInt();

    Screen[4].replace(0, 5, "STATS");
    Screen[5].replace(0, 5, "=====");
    Screen[6].replace(0, 6, "Race: "); Screen[6].replace(6, Player[0].Race.length(), Player[0].Race);
    Screen[7].replace(0, 8, "Health: "); Screen[7].replace(9, 3, sHealthCur);
    Screen[7].replace(12, 1, "/"); Screen[7].replace(13, 3, sHealthMax);
    Screen[8].replace(0,  7, "Magic: "); Screen[8].replace(9, 3, sMagicCur);
    Screen[8].replace(12, 1, "/"); Screen[8].replace(13, 3, sMagicMax);
    Screen[9].replace(0, 10, "Strength: "); Screen[9].replace(14, 3, sStr);
    Screen[10].replace(0, 9, "Agility: "); Screen[10].replace(14, 3, sAgi);
    Screen[11].replace(0, 14, "Intelligence: "); Screen[11].replace(14, 3, sInt);

    Screen[13].replace(0, 6, "TRAITS");
    Screen[14].replace(0, 6, "======");
    Screen[15].replace(0, 5, "Empty");
    Screen[16].replace(0, 5, "Empty");
    Screen[17].replace(0, 5, "Empty");


}

void WriteInventory(string Screen[], character Player[3], int nCC)
{

    stringstream convert;

    Screen[4].replace(0, 9, "INVENTORY");
    Screen[5].replace(0, 9, "=========");
    int j = 1;
    int k = 0;
    for(int i = 6; i < 16; i ++)
    {
        string sIndex;
        convert << j;

        sIndex = convert.str();
        convert.str("");
        int IndexLength = sIndex.length();

        Screen[i].replace(0, IndexLength, sIndex);
        Screen[i].replace(2, 3, " - ");

        Player[nCC].Inventory[k]->WriteItem(Screen, i);

        j++;
        k++;
    }
}

void WriteQuests(string Screen[], character Player[3], int nCC)
{
    int j = 0;
    Screen[4].replace(0, 6, "QUESTS");
    Screen[5].replace(0, 6, "======");
    for(int i = 6; i < 18; i += 4)
    {
        Player[nCC].ActiveQuests[j].WriteStage(Screen, i);
        j ++;
    }
}

void WriteEquip(string Screen[], character Player[3], int nCC)
{
    stringstream convert;
    string sStatA;
    string sStatB;

    Screen[4].replace(0, 9, "EQUIPMENT");
    Screen[5].replace(0, 9, "=========");

    Screen[6].replace(0, 10, "1 - Body: ");
    Screen[6].replace(16, Player[nCC].Equipment.Body.Name.length(), Player[nCC].Equipment.Body.Name);

    convert << Player[nCC].Equipment.Body.Defence;
    sStatA = convert.str();
    convert.str("");

    convert << Player[nCC].Equipment.Body.Weight;
    sStatB = convert.str();
    convert.str("");

    Screen[7].replace(4, 9,"Defence: ");
    Screen[7].replace(16, sStatA.length(), sStatA);

    Screen[8].replace(4, 8, "Weight: ");
    Screen[8].replace(16, sStatB.length(), sStatB);

    Screen[10].replace(0, 15, "2 - Left Hand: ");
    if(Player[nCC].Equipment.LeftHandState() != 1)
    {
        convert << Player[nCC].Equipment.aLeftHand.Defence;
        sStatA = convert.str();
        convert.str("");

        convert << Player[nCC].Equipment.aLeftHand.Weight;
        sStatB = convert.str();
        convert.str();

        convert.str("");

        Screen[10].replace(16, Player[nCC].Equipment.aLeftHand.Name.length(), Player[nCC].Equipment.aLeftHand.Name);
        Screen[11].replace(4, 9, "Defence: ");
        Screen[11].replace(16, sStatA.length(), sStatA);
        Screen[12].replace(4, 8, "Weight: ");
        Screen[12].replace(16, sStatB.length(), sStatB);
    }
    else
    {
        convert << Player[nCC].Equipment.wLeftHand.Damage;
        sStatA = convert.str();
        convert.str("");

        convert << Player[nCC].Equipment.wLeftHand.Weight;
        sStatB = convert.str();
        convert.str();

        convert.str("");

        Screen[10].replace(16, Player[nCC].Equipment.wLeftHand.Name.length(), Player[nCC].Equipment.wLeftHand.Name);
        Screen[11].replace(4, 8, "Damage: ");
        Screen[11].replace(16, sStatA.length(), sStatA);
        Screen[12].replace(4, 8, "Weight: ");
        Screen[12].replace(16, sStatB.length(), sStatB);
    }

    Screen[14].replace(0, 16, "3 - Right Hand: ");
    convert << Player[nCC].Equipment.RightHand.Damage;
    sStatA = convert.str();
    convert.str("");

    convert << Player[nCC].Equipment.RightHand.Weight;
    sStatB = convert.str();
    convert.str("");


    Screen[14].replace(16, Player[nCC].Equipment.RightHand.Name.length(), Player[nCC].Equipment.RightHand.Name);
    Screen[15].replace(4, 8, "Damage: ");
    Screen[15].replace(16, sStatA.length(), sStatA);
    Screen[16].replace(4, 8, "Weight: ");
    Screen[16].replace(16, sStatB.length(), sStatB);

}

void WriteSpells(string Screen[], character Player[], int nCC)
{
    Screen[4].replace(0, 6, "SPELLS");
    Screen[5].replace(0, 6, "======");

    for(int i = 0; i < Player[nCC].KnownSpells(); i ++)
    {
        Screen[6+i].replace(0, Player[nCC].Spells[i].Name.length(), Player[nCC].Spells[i].Name);
    }
}

void OpenWorldScreen(string Screen[], int ScreenType, character Player[3], int nCC)
{
    ClearScreen(Screen, 32);
    int Reg;
    int Twn;
    int Bld;

    Player[nCC].GetLocation(Reg, Twn, Bld);
    string sReg = Atlas[Reg].Name;
    string sTwn = UpShift(Atlas[Reg].Towns[Twn].Name);
    string sBld = UpShift(Atlas[Reg].Towns[Twn].Town[Bld].Name);

    string LevelTitle = UpShift(sReg);
    string LevelSub = sTwn + " - " + sBld;

    string Name = Player[nCC].GetName();
    int NameLength = Name.length();
    string Input;



    Screen[1].replace(0, NameLength, Name);

    for(int i = 0; i < NameLength; i ++)
    {
        Screen[2].replace(i, 1, "=");
    }

    if(ScreenType == 1)
    {
        WriteStats(Screen, Player, nCC);
    }
    else if(ScreenType == 2)
    {
        WriteInventory(Screen, Player, nCC);
    }
    else if(ScreenType == 3)
    {
        WriteQuests(Screen, Player, nCC);
    }
    else if(ScreenType == 4)
    {
        WriteEquip(Screen, Player, nCC);
    }
    else if(ScreenType == 5)
    {
        WriteSpells(Screen, Player, nCC);
    }


    Screen[21].replace(0, 13, "NEARBY AREAS:");
    Screen[22].replace(0, 13, "=============");
    int j = 0;

    for(int i = 0; i < 9; i ++)
    {
        if(Atlas[Reg].Towns[Twn].Town[Bld].Adj[i] == true)
        {
            stringstream subconvert;

            int Index;// = j + 1;
            Index = j + 1;
            string sIndex;
            subconvert << Index;
            sIndex = subconvert.str();

            Screen[23+j].replace(0, 1, sIndex);
            Screen[23+j].replace(1, 3, " - ");
            Screen[23+j].replace(4, Atlas[Reg].Towns[Twn].Town[i].Name.length(), Atlas[Reg].Towns[Twn].Town[i].Name);
            j++;


        }
    }

    Screen[1].replace(49, 6, "PEOPLE");
    Screen[2].replace(49, 6, "======");

    for(int i = 0; i < Atlas[Reg].Towns[Twn].Town[Bld].nResidents; i ++)
    {
        stringstream subconvert;

        int Index;
        Index = i + 1;
        string sIndex;
        subconvert << Index;
        sIndex = subconvert.str();

        string FirstName = Atlas[Reg].Towns[Twn].Town[Bld].Residents[i].FirstName;
        string Surname = Atlas[Reg].Towns[Twn].Town[Bld].Residents[i].Surname;

        int FnLength = FirstName.length();
        int SnLength = Surname.length();
        if(FnLength != 0)
        {
            Screen[i+3].replace(49, 1, sIndex);
            Screen[i+3].replace(50, 3, " - ");
            Screen[i+3].replace(53, FnLength, FirstName);
            Screen[i+3].replace(54 + FnLength, SnLength, Surname);

        }
    }


    DrawScreen(LevelTitle, LevelSub, Screen, Player[nCC].FirstName, 32, true);
}


void RedrawScreen(string Screen[], int ScreenType, character Player[3], int nCC)
{
    int Reg;
    int Twn;
    int Bld;

    Player[nCC].GetLocation(Reg, Twn, Bld);
    string sReg = Atlas[Reg].Name;
    string sTwn = UpShift(Atlas[Reg].Towns[Twn].Name);
    string sBld = UpShift(Atlas[Reg].Towns[Twn].Town[Bld].Name);

    string LevelTitle = UpShift(sReg);
    string LevelSub = sTwn + " - " + sBld;

    string Name = Player[nCC].GetName();
    int NameLength = Name.length();
    string Input;


    Screen[1].replace(0, NameLength, Name);

    for(int i = 0; i < NameLength; i ++)
    {
        Screen[2].replace(i, 1, "=");
    }

    if(ScreenType == 1)
    {
        WriteStats(Screen, Player, nCC);
    }
    else if(ScreenType == 2)
    {
        WriteInventory(Screen, Player, nCC);
    }
    else if(ScreenType == 3)
    {
        WriteQuests(Screen, Player, nCC);
    }


    Screen[21].replace(0, 13, "NEARBY AREAS:");
    Screen[22].replace(0, 13, "=============");
    int j = 0;

    for(int i = 0; i < 9; i ++)
    {
        if(Atlas[Reg].Towns[Twn].Town[Bld].Adj[i] == true)
        {
            stringstream subconvert;

            int Index;// = j + 1;
            Index = j + 1;
            string sIndex;
            subconvert << Index;
            sIndex = subconvert.str();

            Screen[23+j].replace(0, 1, sIndex);
            Screen[23+j].replace(1, 3, " - ");
            Screen[23+j].replace(4, Atlas[Reg].Towns[Twn].Town[i].Name.length(), Atlas[Reg].Towns[Twn].Town[i].Name);
            j++;


        }
    }

    Screen[1].replace(49, 6, "PEOPLE");
    Screen[2].replace(49, 6, "======");

    for(int i = 0; i < Atlas[Reg].Towns[Twn].Town[Bld].nResidents; i ++)
    {
        stringstream subconvert;

        int Index;
        Index = i + 1;
        string sIndex;
        subconvert << Index;
        sIndex = subconvert.str();

        string FirstName = Atlas[Reg].Towns[Twn].Town[Bld].Residents[i].FirstName;
        string Surname = Atlas[Reg].Towns[Twn].Town[Bld].Residents[i].Surname;

        int FnLength = FirstName.length();
        int SnLength = Surname.length();
        if(FnLength != 0)
        {
            Screen[i+3].replace(49, 1, sIndex);
            Screen[i+3].replace(50, 3, " - ");
            Screen[i+3].replace(53, FnLength, FirstName);
            Screen[i+3].replace(54 + FnLength, SnLength, Surname);

        }
    }


    DrawScreen(LevelTitle, LevelSub, Screen, Player[nCC].FirstName, 32, true);
}

//====================================================================================================
//============================COMBAT MENUS============================================================
//====================================================================================================

void BaseMenu(string Screen[])
{
    Screen[26].replace(3, 62,  "==============================================================");
    Screen[27].replace(2, 64, "|1 - ATTACK          |2 - CAST            |3 - DEFEND          |");
    Screen[28].replace(2, 64, "|4 - USE             |5 - INTERACT        |6 - MOVE            |");
    Screen[29].replace(2, 64, "|7 - EQUIPMENT       |8 - SPELLS          |9 - SKIP            |");
    Screen[30].replace(3, 62,  "==============================================================");
}

void DrawGrid(string Screen[], string sOptions[], int nOptions)
{
    Screen[26].replace(3, 62, "==============================================================");

    double dRows = (double(nOptions)+1 )/3;
    int nRows = ceil(dRows);

    for(int i = 0; i < nRows; i ++)
    {
        int nColumns;

        Screen[27+i].replace(2, 64, "|                    |                    |                    |");

        if(nOptions-i*3 >= 3)
        {
            nColumns = 3;
        }
        else
        {
            nColumns = nOptions % 3;
        }

        for(int j = 0; j < nColumns; j ++)
        {
            int Index = (3*i)+j;
            int mIndex = Index + 1;
            stringstream convert;
            convert << mIndex;

            string sIndex = convert.str();
            convert.str("");
            Screen[27+i].replace((j*21)+3, sIndex.length(), sIndex);
            Screen[27+i].replace((j*21)+5, 1, "-");
            Screen[27+i].replace((j*21)+7, sOptions[Index].length(), sOptions[Index]);
        }

    }
    stringstream convert;
    convert << nOptions + 1;
    string sIndex = convert.str();
    convert.str("");
    Screen[26+nRows].replace((nOptions%3)*21+3, sIndex.length(), sIndex);
    Screen[26+nRows].replace((nOptions%3)*21+5, 1, "-");
    Screen[26+nRows].replace((nOptions%3)*21+7, 4, "Back");

    if((nOptions+1)%3 != 0)
    {

        int EmptyColumns = 3 - (nOptions+1)%3;
        int nEmpty = (EmptyColumns)*21;

        for(int i = 0; i < nEmpty-1; i ++)
        {
            Screen[26+nRows].replace(64-i, 1, "-");
        }
    }

    Screen[27+nRows].replace(3, 64, "==============================================================");
}

void Target(string Screen[], character Player[3])
{
    string sNames[3];
    int Count = CountAlive(Player);

    for(int i = 0; i < Count; i ++)
    {
        sNames[i] = Player[i].FirstName;
    }

    DrawGrid(Screen, sNames, Count);

}

void ItemChoice(string Screen[], character Player[3], int nCC, int TestType)
{
    int nItems = 0;
    string sItems[10];

    for(int i = 0; i < 10; i ++)
    {
       /* cout << Player[nCC].Inventory[i]->Name;
        cout << endl << "Type: " << Player[nCC].Inventory[i]->iType;

        system("PAUSE");*/

        if(Player[nCC].Inventory[i]->iType == TestType)
        {
            sItems[nItems] = Player[nCC].Inventory[i]->Name;
            nItems ++;
        }
    }

    DrawGrid(Screen, sItems, nItems);

}

void InteractMenu(string Screen[])
{
    Screen[26].replace(3, 50,  "==================================================");
    Screen[27].replace(2, 52, "|1 -             |2 -             |3 -             |");
    Screen[28].replace(2, 52, "|4 - Back        |---------------------------------|");
    Screen[29].replace(3, 50,  "==================================================");
}

void Movement(string Screen[], arena Arena)
{

    int Count = 0;
    string sPos[11];

    for(int i = 0; i < Arena.Size; i ++)
    {
        if(Arena.IsEmpty(i) == true)
        {
            sPos[Count] = Arena.Objects[i].Name;
            Count ++;
        }
    }
    DrawGrid(Screen, sPos, Count);
}

void EquipMenu(string Screen[])
{
    Screen[26].replace(3, 62,  "==============================================================");
    Screen[27].replace(2, 64, "|1 - WEAPONS         |2 - ARMOUR          |3 - BACK            |");
    Screen[28].replace(3, 62,  "==============================================================");
}

void SpellMenu(string Screen[], character Player[3], int nCC)
{
    string sSpells[12];

    for(int i = 0; i < Player[nCC].KnownSpells(); i ++)
    {
            sSpells[i] = Player[nCC].Spells[i].Name;
    }

    DrawGrid(Screen, sSpells, Player[nCC].KnownSpells());


}

void FightScreen(character Player[3], character Enemy[3], arena Arena, int nCC, bool PlayerOn, int command[2])
{
    string Screen[32];

    int fScreenType = 0;
    bool Fight = true;
    ClearScreen(Screen, 32);
    int Reg;
    int Twn;
    int Bld;
    int Pos;
    int Count = 0;


    Player[nCC].GetLocation(Reg, Twn, Bld);
    string sReg = Atlas[Reg].Name;
    string sTwn = UpShift(Atlas[Reg].Towns[Twn].Name);
    string sBld = UpShift(Atlas[Reg].Towns[Twn].Town[Bld].Name);

    string LevelTitle = UpShift(sReg);
    string LevelSub = sTwn + " - " + sBld;

    string CharacterStats[7];

    string sCost;

    Screen[4].replace(5, 28, "____________________________");
    Screen[4].replace(47, 28, "____________________________");

    for(int i = 0; i < 3; i ++)
    {
        Screen[(2*i)+5].replace(4, 30, "|            |   /   |   /   |");
        Screen[(2*i)+6].replace(4, 30, "|============================|");

        Player[i].WriteStats(CharacterStats);

        Screen[(2*i)+5].replace(5, Player[i].FirstName.length(), Player[i].FirstName);
        Screen[(2*i)+5].replace(18, CharacterStats[0].length(), CharacterStats[0]); Screen[(2*i)+5].replace(22, CharacterStats[1].length(), CharacterStats[1]);
        Screen[(2*i)+5].replace(26, CharacterStats[2].length(), CharacterStats[2]); Screen[(2*i)+5].replace(30, CharacterStats[3].length(), CharacterStats[3]);

        Screen[(2*i)+5].replace(46, 30, "|            |   /   |   /   |");
        Screen[(2*i)+6].replace(46, 30, "|============================|");

        Enemy[i].WriteStats(CharacterStats);

        Screen[(2*i)+5].replace(47, Enemy[i].FirstName.length(), Enemy[i].FirstName);
        Screen[(2*i)+5].replace(60, CharacterStats[0].length(), CharacterStats[0]); Screen[(2*i)+5].replace(64, CharacterStats[1].length(), CharacterStats[1]);
        Screen[(2*i)+5].replace(68, CharacterStats[2].length(), CharacterStats[2]); Screen[(2*i)+5].replace(72, CharacterStats[3].length(), CharacterStats[3]);
    }


    if(PlayerOn == true)
    {
        Screen[5+nCC].replace(3, 1, ">");


        int NameLength = (Player[nCC].FirstName.length() + Player[nCC].Surname.length() + 1);

        string NameHead = Player[nCC].FirstName + ' ' + Player[nCC].Surname + ':';

        Screen[13].replace(0, NameLength + 1, NameHead);

        for(int i = 0; i < NameLength+1; i ++)
        {
            Screen[14].replace(i, 1, "=");
        }

        Player[nCC].WriteStats(CharacterStats);

        Screen[15].replace(0, 7, "Health:");        Screen[15].replace(9, CharacterStats[0].length(), CharacterStats[0]);
                                                    Screen[15].replace(12, 1, "/");
                                                    Screen[15].replace(13, CharacterStats[1].length(), CharacterStats[1]);

        Screen[16].replace(0, 6, "Magic:");         Screen[16].replace(9, CharacterStats[2].length(), CharacterStats[2]);
                                                    Screen[16].replace(12, 1, "/");
                                                    Screen[16].replace(13, CharacterStats[3].length(), CharacterStats[3]);

        Screen[18].replace(0, 5, "Body:");          Screen[18].replace(13, Player[nCC].Equipment.Body.Name.length(), Player[nCC].Equipment.Body.Name);

        Screen[19].replace(0, 10, "Left Hand:");    if(Player[nCC].Equipment.LeftHandState() == -1)
                                                    {
                                                        Screen[19].replace(13, Player[nCC].Equipment.wLeftHand.Name.length(), Player[nCC].Equipment.wLeftHand.Name);
                                                    }
                                                    else if(Player[nCC].Equipment.LeftHandState() == 0)
                                                    {
                                                        Screen[19].replace(13, 5, "Empty");
                                                    }
                                                    else if(Player[nCC].Equipment.LeftHandState() == 1)
                                                    {
                                                        Screen[19].replace(13, Player[nCC].Equipment.aLeftHand.Name.length(), Player[nCC].Equipment.aLeftHand.Name);
                                                    }

        Screen[20].replace(0, 11, "Right Hand:");   Screen[20].replace(13, Player[nCC].Equipment.RightHand.Name.length(), Player[nCC].Equipment.RightHand.Name);

        Screen[22].replace(0, 6, "Spell:");         Screen[22].replace(13, Player[nCC].EquipSpell.Name.length(), Player[nCC].EquipSpell.Name);
        sCost = Player[nCC].EquipSpell.WriteCost();
        if(Player[nCC].EquipSpell.Cost != 0)
        {
            Screen[22].replace(14+Player[nCC].EquipSpell.Name.length(), 1, "(");
            Screen[22].replace(15+Player[nCC].EquipSpell.Name.length(), sCost.length(), sCost);
            Screen[22].replace(15+Player[nCC].EquipSpell.Name.length()+sCost.length(), 1, ")");
        }

        Pos = Arena.GetPos(nCC, true);

        Screen[24].replace(0, 9, "Position:");      Screen[24].replace(13, Arena.Objects[Pos].Name.length(), Arena.Objects[Pos].Name);

        Screen[13].replace(46, 11, "ENVIRONMENT");
        Screen[14].replace(46, 11, "===========");

        for(int i = 0; i < Arena.Size; i ++)
        {
          //  cout << endl << "Position[" << i << "]: " << Arena.Positions[i] << endl;
           // system("PAUSE");

            if(Arena.IsEmpty(i) == true)
            {
                Screen[15+Count].replace(46, Arena.Objects[i].Name.length(), Arena.Objects[i].Name);

                Count ++;
            }
        }

        while(Fight == true)
        {
            ClearScreen(Screen, 26, 32);

            switch(fScreenType)
            {

                case -1:
                {
                    Fight = false;
                break;
                }
                case 0:
                {
                    BaseMenu(Screen);
                    DrawScreen(LevelTitle, LevelSub, Screen, 32);
                    fScreenType = BaseInput(Player, nCC, command);

                break;
                }
                case 1:
                {
                    Target(Screen, Enemy);
                    DrawScreen(LevelTitle, LevelSub, Screen, 32);
                    fScreenType = TargetInput(command, Enemy);

                break;
                }
                case 2:
                {
                    Target(Screen, Player);
                    DrawScreen(LevelTitle, LevelSub, Screen, 32);
                    fScreenType = TargetInput(command, Player);

                break;
                }
                case 3:
                {
                    ItemChoice(Screen, Player, nCC, 2);
                    DrawScreen(LevelTitle, LevelSub, Screen, 32);
                    fScreenType = ItemInput(command, Player, nCC, 2);

                break;
                }
                case 4:
                {
                    InteractMenu(Screen);
                    DrawScreen(LevelTitle, LevelSub, Screen, 32);
                    fScreenType = InteractInput();

                break;
                }
                case 5:
                {
                    Movement(Screen, Arena);
                    DrawScreen(LevelTitle, LevelSub, Screen, 32);
                    fScreenType = MoveInput(Arena, command);
                break;
                }
                case 6:
                {
                    EquipMenu(Screen);
                    DrawScreen(LevelTitle, LevelSub, Screen, 32);
                    fScreenType = EquipInput();
                break;
                }
                case 7:
                {
                    SpellMenu(Screen, Player, nCC);
                    DrawScreen(LevelTitle, LevelSub, Screen, 32);
                    fScreenType = SpellInput(command, nCC, Player);
                break;
                }
                case 8:
                {
                    ItemChoice(Screen, Player, nCC, 1);
                    DrawScreen(LevelTitle, LevelSub, Screen, 32);
                    fScreenType = ItemInput(command, Player, nCC, 1);

                break;
                }
                case 9:
                {
                    ItemChoice(Screen, Player, nCC, 3);
                    DrawScreen(LevelTitle, LevelSub, Screen, 32);
                    fScreenType = ItemInput(command, Player, nCC, 3);

                break;
                }
            }
           // system("PAUSE");
        }

        Screen[5+nCC].replace(3, 1, " ");

    }
    else
    {
        Screen[5+nCC].replace(76, 1, "<");
        DrawScreen(LevelTitle, LevelSub, Screen, 32);
        Screen[5+nCC].replace(76, 1, " ");
    }
}





































