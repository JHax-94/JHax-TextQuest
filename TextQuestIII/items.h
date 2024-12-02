#ifndef ITEMS_H_INCLUDED
#define ITEMS_H_INCLUDED
#include<cstdlib>
#include <iostream>
#include<sstream>
#include<fstream>

class item
{
    public:

    string Name;
    int Value;
    int Quantity;
    int iType;
        /*
         * 0 ITEM
         * 1 WEAPON
         * 2 POTION
         * 3 ARMOUR
        */
    item()
    {
        Name = "Empty";
        Value = 0;
        Quantity = 0;
        iType = 0;
    }

    item(string NewName, int NewValue, int NewQuantity)
    {
        Name = NewName;
        Value = NewValue;
        Quantity = NewQuantity;
        iType = 0;
    }

    item(const item& OldItem)
    {
        Name = OldItem.Name;
        Value = OldItem.Value;
        Quantity = OldItem.Quantity;
        iType = 0;
    }

    virtual ~item() {};

    void WriteItem(string Screen[], int i);

    friend ostream& operator<<(ostream &out, item Item)
    {
        out << Item.iType << endl;
        out << Item.Name << endl;
        out << Item.Value << endl;
        out << Item.Quantity;
        return out;
    }

    friend istream& operator>>(istream &in, item Item)
    {
        in.sync();
        getline(in, Item.Name); // in.ignore();
        in >> Item.Value; in.ignore(512, '\n');
        in >> Item.Quantity; in.ignore(512, '\n');
        return in;
    }

};

class weapon : public item
{
    public:

    int Damage;
    int Weight;
    bool TwoHanded;
    bool Bow;
    bool Staff;

    weapon()
    {
        Damage = 0;
        Weight = 0;
        TwoHanded = false;
        Bow = false;
        Staff = false;
        iType = 1;
    }

    weapon(string NewName, int NewValue, int NewQuantity, int NewDamage,
            int NewWeight, bool NewTwoHanded, bool NewBow, bool NewStaff)
    {
        Name = NewName;
        Value = NewValue;
        Quantity = NewQuantity;
        Damage = NewDamage;
        Weight = NewWeight;
        TwoHanded = NewTwoHanded;
        Bow = NewBow;
        Staff = NewStaff;
        iType = 1;
    }

    weapon(const weapon& OldWeapon)
    {
        Name = OldWeapon.Name;
        Value = OldWeapon.Value;
        Quantity = OldWeapon.Quantity;
        Damage = OldWeapon.Damage;
        Weight = OldWeapon.Weight;
        TwoHanded = OldWeapon.TwoHanded;
        Bow = OldWeapon.Bow;
        Staff = OldWeapon.Staff;
        iType = 1;
    }

    weapon operator= (const weapon* OldWeapon)
    {
        Name = OldWeapon->Name;
        Value = OldWeapon->Value;
        Quantity = OldWeapon->Quantity;
        Damage = OldWeapon->Damage;
        Weight = OldWeapon->Weight;
        TwoHanded = OldWeapon->TwoHanded;
        Bow = OldWeapon->Bow;
        Staff = OldWeapon->Staff;
        iType = 1;

        return *this;
    }

    friend ostream& operator<< (ostream& out, weapon Weapon)
    {
        out << Weapon.iType << endl;
        out << Weapon.Name << endl;
        out << Weapon.Value << endl;
        out << Weapon.Quantity << endl;
        out << Weapon.Damage << endl;
        out << Weapon.Weight << endl;
        out << Weapon.TwoHanded << endl;
        out << Weapon.Bow << endl;
        out << Weapon.Staff;
        return out;
    }

    friend istream& operator>> (istream& in, weapon &Weapon)
    {
        in.sync();
        getline(in, Weapon.Name); // in.ignore();
        in >> Weapon.Value; in.ignore(512, '\n');
        in >> Weapon.Quantity; in.ignore(512, '\n');
        in >> Weapon.Damage; in.ignore(512, '\n');
        in >> Weapon.Weight; in.ignore(512, '\n');
        in >> Weapon.TwoHanded; in.ignore(512, '\n');
        in >> Weapon.Bow; in.ignore(512, '\n');
        in >> Weapon.Staff; in.ignore(512, '\n');
        return in;
    }

};

class potion : public item
{
    public:

    int Type;
    /*
        * 1 HEALTH
        * 2 MAGIC
    */

    int Modifier;

    potion()
    {
        Type = 0;
        Modifier = 0;
        iType = 2;
    }

    potion(string NewName, int NewValue, int NewQuantity, int NewType, int NewModifier)
    {
        Name = NewName; //cout << "Name: " << Name << endl;
        Value = NewValue; //cout << "Value: " << Value << endl;
        Quantity = NewQuantity; //cout << "Quantity: " << Quantity << endl;
        Type = NewType; //cout << "Type: " << Type << endl;
        Modifier = NewModifier; //cout << "Modifier: " << Modifier << endl;

       // iType = 2; cout << "iType: " << iType << endl;
       // system("PAUSE");
    }
    potion(const potion &OldPotion)
    {
        Name = OldPotion.Name;
        Value = OldPotion.Value;
        Quantity = OldPotion.Quantity;
        Type = OldPotion.Type;
        Modifier = OldPotion.Modifier;
        iType = 2;
    }

    potion operator= (const potion *OldPotion)
    {
        Name = OldPotion->Name;
        Value = OldPotion->Value;
        Quantity = OldPotion->Quantity;
        Type = OldPotion->Type;
        Modifier = OldPotion->Modifier;
        iType = 2;

        return *this;

    }

    friend ostream &operator<<(ostream &out, potion Potion)
    {
        out << Potion.iType << endl;
        out << Potion.Name << endl;
        out << Potion.Value << endl;
        out << Potion.Quantity << endl;
        out << Potion.Type << endl;
        out << Potion.Modifier;
        return out;
    }

    friend istream &operator >> (istream &n, potion &Potion)
    {
        n.sync();
        getline(n, Potion.Name);
        n >> Potion.Value; n.ignore(512, '\n');
        n >> Potion.Quantity; n.ignore(512, '\n');
        n >> Potion.Type; n.ignore(512, '\n');
        n >> Potion.Modifier; n.ignore(512, '\n');

        return n;
    }

};

class armour : public item
{
    public:

    int Defence;
    int Weight;
    bool BodyArmour;

    armour()
    {
        Defence = 0;
        Weight = 0;
        BodyArmour = true;
        iType = 3;
    }

    armour(string NewName, int NewValue, int NewQuantity, int NewDefence, int NewWeight, bool NewBodyArmour)
    {
        Name = NewName;
        Value = NewValue;
        Quantity = NewQuantity;
        Defence = NewDefence;
        Weight = NewWeight;
        BodyArmour = NewBodyArmour;
        iType = 3;
    }

    armour(const armour &OldArmour)
    {
        Name = OldArmour.Name;
        Value = OldArmour.Value;
        Quantity = OldArmour.Quantity;
        Defence = OldArmour.Defence;
        Weight = OldArmour.Weight;
        BodyArmour = OldArmour.BodyArmour;
        iType = 3;
    }

    armour operator= (const armour *OldArmour)
    {
        Name = OldArmour->Name;
        Value = OldArmour->Value;
        Quantity = OldArmour->Quantity;
        Defence = OldArmour->Defence;
        Weight = OldArmour->Weight;
        BodyArmour = OldArmour->BodyArmour;
        iType = 3;

        return *this;
    }

    friend ostream& operator<<(ostream &out, armour Armour)
    {
        out << Armour.iType << endl;
        out << Armour.Name << endl;
        out << Armour.Value << endl;
        out << Armour.Quantity << endl;
        out << Armour.Defence << endl;
        out << Armour.Weight << endl;
        out << Armour.BodyArmour;
        return out;
    }

    friend istream& operator >> (istream &n, armour &Armour)
    {
        n.sync();
        getline(n, Armour.Name);
        n >> Armour.Value; n.ignore(512, '\n');
        n >> Armour.Quantity; n.ignore(512, '\n');
        n >> Armour.Defence; n.ignore(512, '\n');
        n >> Armour.Weight; n.ignore(512, '\n');
        n >> Armour.BodyArmour; n.ignore(512, '\n');
        return n;
    }

};

class LoadOut
{
    public:

    armour Body;
    armour aLeftHand;
    weapon wLeftHand;
    weapon RightHand;

    bool BodyState();
    bool RightHandState();
    int LeftHandState();

    friend ostream& operator<<(ostream &out, LoadOut Equipment)
    {
        out << Equipment.Body << endl;
        out << Equipment.aLeftHand << endl;
        out << Equipment.wLeftHand << endl;
        out << Equipment.RightHand << endl;

        return out;
    }

    friend istream& operator>>(istream& in, LoadOut &Equipment)
    {
        in >> Equipment.Body.iType; in.ignore(512, '\n');
        in >> Equipment.Body;
        in >> Equipment.aLeftHand.iType;    in.ignore(512, '\n');
        in >> Equipment.aLeftHand;
        in >> Equipment.wLeftHand.iType;    in.ignore(512, '\n');
        in >> Equipment.wLeftHand;
        in >> Equipment.RightHand.iType;    in.ignore(512, '\n');
        in >> Equipment.RightHand;

        return in;
    }

};

extern item NullItem;
/*extern item TestItem;
extern item TestItemB;*/

extern weapon IronSword;
extern weapon BasicStaff;
extern weapon HunterBow;

extern potion WeakHealth;
extern potion WeakMagic;





/*
extern potion TestPotionA;
extern potion TestPotionB;
extern potion TestPotionC;
extern potion TestPotionD;
extern potion TestPotionE;
extern potion TestPotionF;
extern potion TestPotionG;
extern potion TestPotionH;
extern potion TestPotionI;
extern potion TestPotionJ;
*/
extern armour OrderRecruitPlate;
extern armour ApprenticeRobes;
extern armour OrderChainMail;





#endif // ITEMS_H_INCLUDED
