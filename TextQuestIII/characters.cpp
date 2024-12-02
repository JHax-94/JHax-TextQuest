#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include<iostream>
#include<cstdlib>
#include"characters.h"
#include"Inputs.h"

void character::DisplayStats()
{

    cout << "Name: " << FirstName << " " << Surname << endl;
    cout << "Race: " << Race << endl;
    cout << "Gender: " << Gender << endl;
    cout << "Health: " << Health[0] << "/" << Health[1] << endl;
    cout << "Magic: " << Magic[0] << "/" << Magic[1] << endl;
    cout << "Strength: " << Str << endl;
    cout << "Agility: " << Agi << endl;
    cout << "Intelligence: " << Int << endl << endl;

    system("PAUSE");

}

int character::FullNameLength()
{
   int Length = FirstName.length() + Surname.length() + 1;
   return Length;
}

void character::SaveData(string FileName[3], int nCC)
{
    ofstream SaveData;
    int i;

    SaveData.open(FileName[nCC].c_str());

    SaveData << FirstName << endl;
    SaveData << Surname << endl;
    SaveData << Gender << endl;
    SaveData << Race << endl;
    SaveData << RaceID << endl;
    SaveData << Str << endl;
    SaveData << Agi << endl;
    SaveData << Int << endl;
    for(i = 0; i < 2; i ++)
    {
        SaveData << Health[i] << endl;
        SaveData << Magic[i] << endl;

    }
    for(i = 0; i < 3; i ++)
    {
        SaveData << Location[i] << endl;
        SaveData << ActiveQuests[i].QuestID << endl;
        SaveData << ActiveQuests[i].CurrentStage << endl;
    }

    for(i = 0; i < 10; i++)
    {
       // cout << "Name: " << Inventory[i]->Name << endl;
       // cout << "iType: " << Inventory[i]->iType << endl;

       // system("PAUSE");

        if(Inventory[i]->iType == 0)
        {
            SaveData << *Inventory[i] << endl;
        }
        else if(Inventory[i]->iType == 1)
        {
            weapon *NewWeapon = dynamic_cast<weapon*>(Inventory[i]);

            SaveData << *NewWeapon << endl;
        }
        else if(Inventory[i]->iType == 2)
        {
            potion *NewPotion = dynamic_cast<potion*>(Inventory[i]);

           /* cout << "Name: " << NewPotion->Name << endl;
            cout << "Value: " << NewPotion->Value << endl;
            cout << "Quantity: " << NewPotion->Quantity << endl;
            cout << "Type: " << NewPotion->Type << endl;
            cout << "Modifier: " << NewPotion->Modifier << endl;
            cout << "iType: " << NewPotion->Modifier << endl;
            system("PAUSE");*/

            SaveData << *NewPotion << endl;
        }
        else if(Inventory[i]->iType == 3)
        {
            armour *NewArmour = dynamic_cast<armour*>(Inventory[i]);

            SaveData << *NewArmour << endl;
        }
    }
    SaveData << Equipment;

    for(i = 0; i < MaxSpells; i ++)
    {
        SaveData << Spells[i];
    }

    SaveData.close();

}

quest LoadQuest(int LoadID, int LoadStage)
{
    quest NewQuest;

    if(LoadID == 1)
    {
        NewQuest = SigningUp;
    }

    NewQuest.NextStage(LoadStage);

    return NewQuest;
}


void character::LoadData(string FileName[3], int nCC)
{
    ifstream LoadData;
    int i;

    LoadData.open(FileName[nCC].c_str());

    LoadData >> FirstName;
    LoadData >> Surname;
    LoadData >> Gender;
    LoadData >> Race;
    LoadData >> RaceID;
    LoadData >> Str;
    LoadData >> Agi;
    LoadData >> Int;

    MaxSpells = ceil(double(Int/10));

    for(i = 0; i < 2; i ++)
    {
        LoadData >> Health[i];
        LoadData >> Magic[i];
    }
    for(i = 0; i < 3; i ++)
    {
        LoadData >> Location[i];
        LoadData >> ActiveQuests[i].QuestID;
        LoadData >> ActiveQuests[i].CurrentStage;
        ActiveQuests[i] = LoadQuest(ActiveQuests[i].QuestID, ActiveQuests[i].CurrentStage);
    }
    for(i = 0; i < 10; i ++)
    {


        LoadData >> Inventory[i]->iType;
        LoadData.ignore(100, '\n');
      //  LoadData.sync();
       //LoadData >> Inventory[i]->Name >> Inventory[i]->Name;
   /*     getline(LoadData, Inventory[i]->Name);
        LoadData >> Inventory[i]->Value;
        LoadData >> Inventory[i]->Quantity;*/
        if(Inventory[i]->iType == 0)
        {
            LoadData >> *Inventory[i];
        }
        else if(Inventory[i]->iType == 1)
        {
            weapon NewWeapon;
            LoadData >> NewWeapon;
            Inventory[i] = new weapon(NewWeapon);

        }
        else if(Inventory[i]->iType == 2)
        {
           // cout << "Loading Potion...";
          //  system("PAUSE");

            potion NewPotion;
            LoadData >> NewPotion;
            Inventory[i] = new potion(NewPotion);
        }
        else if(Inventory[i]->iType == 3)
        {
            armour NewArmour;
            LoadData >> NewArmour;
            Inventory[i] = new armour(NewArmour);
        }
    }

    LoadData >> Equipment;

    MaxSpells = ceil(double(Int/10));

    Spells = new spell[MaxSpells];

    for(i = 0; i < MaxSpells; i ++)
    {
        LoadData >> Spells[i];
    }

    LoadData.close();
}


void character::GetLocation(int &Reg, int &Twn, int &Bld)
{
    Reg = Location[0];
    Twn = Location[1];
    Bld = Location[2];
}

void character::AddQuest(quest NewQuest)
{
    bool Loop = true;
    int i = 0;

    while(Loop == true)
    {
        if(ActiveQuests[i].QuestID != -1)
        {
            i ++;
        }
        else
        {
            Loop = false;
        }

        if(i == 3)
        {
            Loop = false;
        }
    }

    if(i == 3)
    {
        cout << "You are too busy already to take this quest!\n\n";
        system("PAUSE");
    }
    else
    {
        ActiveQuests[i] = NewQuest;
    }
}


void character::RemoveQuest(quest OldQuest)
{
    for(int i = 0; i < 3; i ++)
    {
        if(ActiveQuests[i].QuestID == OldQuest.QuestID)
        {
            ActiveQuests[i] = NullQuests[i];
        }
    }
}

void character::CheckQuest()
{
    for(int i = 0; i < 3; i ++)
    {
        if(ActiveQuests[i].QuestID != -1)
        {
            if(ActiveQuests[i].QuestID == 1)
            {
                if(ActiveQuests[i].CurrentStage == 7)
                {
                    if(Equipment.BodyState() == true && Equipment.RightHandState() == true)
                    {
                        ActiveQuests[i].NextStage(8);
                    }
                }
            }




        }
    }
}


void character::DropItem(int iChoice)
{
    if(Inventory[iChoice]->Name != "Empty");
    {
        cout << "Are you sure you want to drop this item? ";
        if(YesNo() == true);
        {
            Inventory[iChoice] = new item();
        }
    }
}

void character::AddItem(item &NewItem)
{
    for(int i = 0; i < 10; i ++)
    {
        if(i == 9 && Inventory[i]->Name != "Empty")
        {
            cout << "Not enough room in inventory!\n\n";
            system("PAUSE");
        }
        if(Inventory[i]->Name == "Empty")
        {
            //Inventory[i] = new item;
            Inventory[i] = new item(NewItem);

            i = 10;
        }
        else if(Inventory[i]->Name == NewItem.Name)
        {
            Inventory[i]->Quantity += NewItem.Quantity;
            i = 10;
        }

    }
}

void character::AddWeapon(weapon &NewWeapon)
{
    for(int i = 0; i < 10; i ++)
    {
        if(i == 9 && Inventory[i]->Name != "Empty")
        {
            cout << "Not enough room in inventory!\n\n";
            system("PAUSE");
        }
        if(Inventory[i]->Name == "Empty")
        {
            //Inventory[i] = new weapon;
            Inventory[i] = new weapon(NewWeapon);
            i = 10;
        }
        else if(Inventory[i]->Name == NewWeapon.Name)
        {
            Inventory[i]->Quantity += NewWeapon.Quantity;
            i = 10;
        }

    }
}

void character::AddPotion(potion &NewPotion)
{
    for(int i = 0; i < 10; i ++)
    {
        if(i == 9 && Inventory[i]->Name != "Empty")
        {
            cout << "Not enough room in inventory!\n\n";
            system("PAUSE");
        }
        if(Inventory[i]->Name == "Empty")
        {
            //Inventory[i] = new potion;
            Inventory[i] = new potion(NewPotion);
           /* cout << "Name: " << NewPotion.Name << endl;
            cout << "Value: " << NewPotion.Value << endl;
            cout << "Quantity: " << NewPotion.Quantity << endl;
            cout << "Type: " << NewPotion.Type << endl;
            cout << "Modifier: " << NewPotion.Modifier << endl;
            cout << "iType: " << NewPotion.iType << endl;
            system("PAUSE");

            cout << "NAME: " << Inventory[i]->Name << endl;
            cout << "iType: " << Inventory[i]->iType << endl;
*/
            i = 10;
        }
        else if(Inventory[i]->Name == NewPotion.Name)
        {
            Inventory[i]->Name += NewPotion.Quantity;
            i = 10;
        }

    }
}

void character::AddArmour(armour &NewArmour)
{
    for(int i = 0; i < 10; i ++)
    {
        if(i == 9 && Inventory[i]->Name != "Empty")
        {
            cout << "Not enough room in inventory!\n\n";
            system("PAUSE");
        }
        if(Inventory[i]->Name == "Empty")
        {
            //Inventory[i] = new armour;
            Inventory[i] = new armour(NewArmour);


            i = 10;
        }
        else if(Inventory[i]->Name == NewArmour.Name)
        {
            Inventory[i]->Name += NewArmour.Quantity;
            i = 10;
        }

    }
}

void character::Equip(int iChoice, int eChoice)
{
    if(Inventory[iChoice]->iType == 0)
    {
        cout << "Cannot equip this item!\n\n";
        system("PAUSE");
    }
    else if(Inventory[iChoice]->iType == 1)
    {
        weapon *NewWeapon = dynamic_cast<weapon*>(Inventory[iChoice]);


        if(eChoice == 2)
        {
            Equipment.wLeftHand = NewWeapon;      //new weapon(Inventory[iChoice]);
            Inventory[iChoice] = new item();

            cout << "Left Hand Weapon: " << Equipment.wLeftHand.Name << endl;
            cout << "Damage: " << Equipment.wLeftHand.Damage << endl;
            cout << "Weight: " << Equipment.wLeftHand.Weight << endl;
            cout << "Two Handed? " << Equipment.wLeftHand.TwoHanded << endl;
        }
        else if(eChoice == 3)
        {
            Equipment.RightHand = NewWeapon;  //new weapon(Inventory[iChoice]);
            Inventory[iChoice] = new item();

            cout << "Right Hand Weapon: " << Equipment.RightHand.Name << endl;
            cout << "Damage: " << Equipment.RightHand.Damage << endl;
            cout << "Weight: " << Equipment.RightHand.Weight << endl;
            cout << "Two Handed? " << Equipment.RightHand.TwoHanded << endl;
        }
        else
        {
            cout << "Cannot equip this item here!\n\n";
            system("PAUSE");
        }
    }
    else if(Inventory[iChoice]->iType == 2)
    {
        cout << "Cannot equip this item!\n\n";
        system("PAUSE");
    }
    else if(Inventory[iChoice]->iType == 3)
    {
        armour *NewArmour = dynamic_cast<armour*>(Inventory[iChoice]);

        if(eChoice == 0)
        {
            Equipment.Body = NewArmour;
            Inventory[iChoice] = new item();
        }
        else if(eChoice == 1)
        {
            Equipment.Body = NewArmour;
            Inventory[iChoice] = new item();
        }
        else
        {
            cout << "Cannot equip this item here!\n\n";
            system("PAUSE");
        }
    }
}

void character::Unequip(int eChoice)
{
    if(eChoice == 1)
    {
        for(int i = 0; i < 10; i ++)
        {
            if(Inventory[i]->Name != "Empty" && i == 9)
            {
                cout << "Not enough room in inventory!\n";
                cout << "Would you like to drop the item? ";
                if(YesNo() == true)
                {
                    Equipment.Body = new armour();
                }
            }
            if(Inventory[i]->Name == "Empty")
            {
                armour OldArmour = Equipment.Body;

                Inventory[i] = new armour(OldArmour);
                Equipment.Body = new armour();


            }

        }
    }
    else if(eChoice == 2)
    {
        for(int i = 0; i < 10; i ++)
        {
            if(Inventory[i]->Name != "Empty" && i == 9)
            {
                cout << "Not enough room in inventory!\n";
                cout << "Would you like to drop the item? ";
                if(YesNo() == true)
                {
                    Equipment.aLeftHand = new armour();

                }
            }
            if(Inventory[i]->Name == "Empty")
            {
                armour OldArmour = Equipment.aLeftHand;

                Inventory[i] = new armour(OldArmour);
                Equipment.aLeftHand = new armour();
            }

        }
    }
    else if(eChoice == 3)
    {
        for(int i = 0; i < 10; i ++)
        {
            if(Inventory[i]->Name != "Empty" && i == 9)
            {
                cout << "Not enough room in inventory!\n";
                cout << "Would you like to drop the item? ";
                if(YesNo() == true)
                {
                    Equipment.wLeftHand = new weapon();
                }
            }
            if(Inventory[i]->Name == "Empty")
            {
                weapon OldWeapon = Equipment.wLeftHand;

                Inventory[i] = new weapon(OldWeapon);
                Equipment.wLeftHand = new weapon();
            }

        }
    }
    else if(eChoice == 4)
    {
        for(int i; i < 10; i ++)
        {
            if(Inventory[i]->Name != "Empty" && i == 9)
            {
                cout << "Not enough room in inventory!\n";
                cout << "Would you like to drop the item? ";
                if(YesNo() == true)
                {
                    Equipment.RightHand = new weapon();
                }
            }
            if(Inventory[i]->Name == "Empty")
            {
                weapon OldWeapon = Equipment.RightHand;

                Inventory[i] = new weapon(OldWeapon);
                Equipment.wLeftHand = new weapon();
            }

        }
    }
}

string character::GetName()
{
    string Name = FirstName + " " + Surname;

    return Name;
}

string character::WriteCurHealth()
{
    stringstream convert;
    string sHealth;

    convert << Health[0];
    sHealth = convert.str();

    convert.str(" ");

    return sHealth;
}

string character::WriteMaxHealth()
{
    stringstream convert;
    string sHealth;

    convert << Health[1];
    sHealth = convert.str();

    convert.str(" ");

    return sHealth;
}

string character::WriteCurMagic()
{
    stringstream convert;
    string sMagic;

    convert << Magic[0];
    sMagic = convert.str();

    convert.str(" ");

    return sMagic;
}

string character::WriteMaxMagic()
{
    stringstream convert;
    string sMagic;

    convert << Magic[1];
    sMagic = convert.str();

    convert.str(" ");

    return sMagic;
}

string character::WriteStr()
{
    stringstream convert;
    string sStrength;

    convert << Str;
    sStrength = convert.str();

    convert.str(" ");

    return sStrength;
}

string character::WriteAgi()
{
    stringstream convert;
    string sAgility;

    convert << Agi;
    sAgility = convert.str();

    convert.str(" ");

    return sAgility;
}

string character::WriteInt()
{
    stringstream convert;
    string sIntelligence;

    convert << Int;
    sIntelligence = convert.str();

    convert.str(" ");

    return sIntelligence;
}

void character::WriteStats(string CharacterStats[7])
{
    CharacterStats[0] = WriteCurHealth();
    CharacterStats[1] = WriteMaxHealth();
    CharacterStats[2] = WriteCurMagic();
    CharacterStats[3] = WriteMaxMagic();
    CharacterStats[4] = WriteStr();
    CharacterStats[5] = WriteAgi();
    CharacterStats[6] = WriteInt();
}

int character::KnownSpells()
{
    int Count = 0;

    for(int i = 0; i < MaxSpells; i ++)
    {
        if(Spells[i].Type != 0)
        {
            Count ++;
        }
    }

    return Count;
}

void character::BoundHealth()
{
    if(Health[0] < 0)
    {
        Health[0] = 0;
    }

    if(Health[0] > Health[1])
    {
        Health[0] = Health[1];
    }
}

void character::BoundMagic()
{
    if(Magic[0] < 0)
    {
        Magic[0] = 0;
    }

    if(Magic[0] > Magic[1])
    {
        Magic[0] = Magic[1];
    }
}

void character::ReNull()
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






