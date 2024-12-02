#ifndef CHARACTERS_H_INCLUDED
#define CHARACTERS_H_INCLUDED

#include<string>
#include<math.h>

using namespace std;

#include "spells.h"
#include "quests.h"
#include "items.h"


class character
{
    public:

    bool player;

    int ID;
    int Health[2];
    int Magic[2];
    int Location[3];

    int Str;
    int Agi;
    int Int;
    int RaceID;

    int Disposition;

    int MaxSpells;

    string FirstName;
    string Surname;
    string Race;
    string Gender;

    quest ActiveQuests[3];

    LoadOut Equipment;

    item* Inventory[10];

    spell* Spells;
    spell EquipSpell;

    void DisplayStats();

    character(bool Newplayer, int NewID, int NewHealth, int NewMagic, int NewLocation[3], int NewStr, int NewAgi, int NewInt, int NewRaceID, int NewDisp,
               string NewFirstName, string NewSurname, string NewRace, string NewGender, quest NewActiveQuests[3], spell NewSpells[])
    {
        player = Newplayer;

        ID = NewID;
        Health[0] = NewHealth;
        Health[1] = NewHealth;
        Magic[0] = NewMagic;
        Magic[1] = NewMagic;
        Location[0] = NewLocation[0];
        Location[1] = NewLocation[1];
        Location[2] = NewLocation[2];

        Str = NewStr;
        Agi = NewAgi;
        Int = NewInt;
        RaceID = NewRaceID;

        Disposition = NewDisp;

        double dMaxSpells = Int/10;
        MaxSpells = ceil(dMaxSpells);



        FirstName = NewFirstName;
        Surname = NewSurname;
        Race = NewRace;
        Gender = NewGender;

        ActiveQuests[0] = NewActiveQuests[0];
        ActiveQuests[1] = NewActiveQuests[1];
        ActiveQuests[2] = NewActiveQuests[2];

        for(int i = 0; i < 10; i ++)
        {
            Inventory[i] = new item();
        }

        Spells = new spell[MaxSpells];

        for(int i = 0; i < MaxSpells; i ++)
        {
            Spells[i] = NewSpells[i];
        }
    }

    character()
    {
        quest NullQuest;

        player = false;
        ID = -1;
        Health[0] = 0;
        Health[1] = 0;
        Magic[0] = 0;
        Magic[1] = 0;
        Location[0] = 0;
        Location[1] = 0;
        Location[2] = 0;

        Str = 0;
        Agi = 0;
        Int = 0;
        RaceID = -1;

        Disposition = 0;

        MaxSpells = 0;

        FirstName = "";
        Surname = "";
        Race = "";
        Gender = "";

        ActiveQuests[0] = NullQuest;
        ActiveQuests[1] = NullQuest;
        ActiveQuests[2] = NullQuest;

        for(int i = 0; i < 10; i ++)
        {
            Inventory[i] = new item();
        }

        Spells = new spell[1];

    }



    void AssignStats(bool Newplayer, int NewID, int NewHealth[2], int NewMagic[2], int NewLocation[2], int NewStr, int NewAgi, int NewInt, int NewRaceID, int NewDisp,
                    string NewFirstName, string NewSurname, string NewRace, string NewGender, quest NewActiveQuests[3], spell NewSpells[])
    {
        player = Newplayer;

        ID = NewID;

        Health[0] = NewHealth[0];
        Health[1] = NewHealth[1];
        Magic[0] = NewMagic[0];
        Magic[1] = NewMagic[1];
        Location[0] = NewLocation[0];
        Location[1] = NewLocation[1];
        Location[2] = NewLocation[2];

        Str = NewStr;
        Agi = NewAgi;
        Int = NewInt;
        RaceID = NewRaceID;

        Disposition = NewDisp;

        double dMaxSpells = Int/10;
        MaxSpells = ceil(dMaxSpells);

        FirstName = NewFirstName;
        Surname = NewSurname;
        Race = NewRace;
        Gender = NewGender;

        ActiveQuests[0] = NewActiveQuests[0];
        ActiveQuests[1] = NewActiveQuests[1];
        ActiveQuests[2] = NewActiveQuests[2];

        for(int i = 0; i < 10; i ++)
        {
            Inventory[i] = new item();
        }

        Spells = new spell[MaxSpells];

        for(int i = 0; i < MaxSpells; i ++)
        {
            Spells[i] = NewSpells[i];
        }


    }

    character operator= (const character& OldCharacter)
    {
        player = OldCharacter.player;

        ID = OldCharacter.ID;
        Health[0] = OldCharacter.Health[0];
        Health[1] = OldCharacter.Health[1];
        Magic[0] = OldCharacter.Magic[0];
        Magic[1] = OldCharacter.Magic[1];
        Location[0] = OldCharacter.Location[0];
        Location[1] = OldCharacter.Location[1];
        Location[2] = OldCharacter.Location[2];

        Str = OldCharacter.Str;
        Agi = OldCharacter.Agi;
        Int = OldCharacter.Int;
        RaceID = OldCharacter.RaceID;

        Disposition = OldCharacter.Disposition;

        MaxSpells = OldCharacter.MaxSpells;

        FirstName = OldCharacter.FirstName;
        Surname = OldCharacter.Surname;
        Race = OldCharacter.Race;
        Gender = OldCharacter.Gender;

        ActiveQuests[0] = OldCharacter.ActiveQuests[0];
        ActiveQuests[1] = OldCharacter.ActiveQuests[1];
        ActiveQuests[2] = OldCharacter.ActiveQuests[2];

        for(int i = 0; i < 10; i ++)
        {
            Inventory[i] = new item();
        }

        Spells = new spell[MaxSpells];



        return *this;
    }

    int FullNameLength();

    void SaveData(string FileName[3], int nCC);

    void LoadData(string FileName[3], int nCC);

    void GetLocation(int &Reg, int &Twn, int &Bld);

    void AddQuest(quest NewQuest);

    void RemoveQuest(quest OldQuest);

    void CheckQuest();

    void DropItem(int iChoice);

    void AddItem(item &NewItem);

    void AddWeapon(weapon &NewWeapon);

    void AddPotion(potion &NewPotion);

    void AddArmour(armour &NewArmour);

    void Equip(int iChoice, int eChoice);

    void Unequip(int eChoice);

    string GetName();
    string WriteCurHealth();
    string WriteMaxHealth();
    string WriteCurMagic();
    string WriteMaxMagic();
    string WriteStr();
    string WriteAgi();
    string WriteInt();

    void WriteStats(string CharacterStats[7]);

    int KnownSpells();

    void BoundHealth();
    void BoundMagic();

    void ReNull();

};
/*
int Health100[2] = {100, 100};
int Magic0[2] = {0, 0};
int OryTrCmp[3] = {1, 0, 2};

character CaptainHelx(false, Health100, Magic0, OryTrCmp, 150, 50, 50, 0, "Captain", "Helx", "Human", "Male");
*/

#endif // CHARACTERS_H_INCLUDED
