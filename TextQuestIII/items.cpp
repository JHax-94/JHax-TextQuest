#include<sstream>

using namespace std;
#include "items.h"

string Test = "Test";
item NullItem;
item TestItem(Test, 50, 1);
item TestItemB(TestItem);

weapon IronSword("Iron Sword", 100, 1, 60, 20, false, false, false);
weapon BasicStaff("Basic Staff", 100, 1, 15, 10, true, false, true);
weapon HunterBow("Hunter's Bow", 100, 1, 50, 10, true, true, false);

potion WeakHealth("Weak Health", 25, 1, 1, 15);
potion WeakMagic("Weak Magic", 25, 1, 2, 15);

/*
potion TestPotionA("TestPotionA" , 50, 1, 1, 50);
potion TestPotionB("TestPotionB" , 50, 1, 1, 50);
potion TestPotionC("TestPotionC" , 50, 1, 1, 50);
potion TestPotionD("TestPotionD" , 50, 1, 1, 50);
potion TestPotionE("TestPotionE" , 50, 1, 1, 50);
potion TestPotionF("TestPotionF" , 50, 1, 1, 50);
potion TestPotionG("TestPotionG" , 50, 1, 1, 50);
potion TestPotionH("TestPotionH" , 50, 1, 1, 50);
potion TestPotionI("TestPotionI" , 50, 1, 1, 50);
potion TestPotionJ("TestPotionJ" , 50, 1, 1, 50);
*/
armour OrderRecruitPlate("Order Recruit Plate Armour", 150, 1, 70, 90, true);
armour ApprenticeRobes("Apprentice Robes", 150, 1, 10, 10, true);
armour OrderChainMail("Order Chain Mail", 150, 1, 35, 20, true);







void item::WriteItem(string Screen[], int i)
{
    stringstream convert;

    string sQuantity;
    int NameLength;
    int QuantityLength;

    convert << Quantity;
    sQuantity = convert.str();

    NameLength = Name.length();
    QuantityLength = sQuantity.length();


    Screen[i].replace(5, NameLength, Name);
    if(Quantity != 0)
    {
        Screen[i].replace(5+NameLength, 2+QuantityLength, " x" + sQuantity);
    }
}

bool LoadOut::BodyState()
{
    bool State = false;

    if(Body.Name != "Empty")
    {
        State = true;
    }

    return State;
}

bool LoadOut::RightHandState()
{
    bool State = false;

    if(RightHand.Name != "Empty")
    {
        State = true;
    }

    return State;
}

int LoadOut::LeftHandState()
{
    int LeftHandState = 0;

    if(aLeftHand.Name != "Empty")
    {
        LeftHandState = -1;
    }
    else if(wLeftHand.Name != "Empty")
    {
        LeftHandState = 1;
    }

    return LeftHandState;
}
