#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

#include"Input.h"
#include"dice.h"

int ThroneRoomA()
{
    int inv = 0;
    cout << "You tap the Eastern Wall, it sounds hollow. But it's too tough to simply knock down." << endl << endl;
    system("PAUSE");

    return inv;
}

int ThroneRoomB()
{
    int inv = 0;
    cout << "You pull on the candle, hoping it's some sort of lever. But it simply snaps off." << endl << endl;
    system("PAUSE");

    return inv;
}

int ThroneRoomC()
{
    int inv = -1;
    cout << "You manage to wiggle a brick out of the wall. A spider bites your hand, its venom quickly takes effect\nand kills you." << endl << endl;

    system("PAUSE");
    return inv;

}

int ThroneRoomD()
{
    int inv = 1;
    cout << "Behind the painting is a lever, you pull on it and the wall slides away, \nrevealing a secret passage." << endl << endl;
    system("PAUSE");
    return inv;
}

int InvestigateThroneRoom()
{
    int InvChoice;

    int investigate;
    bool YN;
    bool Loop;

    cout << endl << "The eastern wall looks a little thin." << endl;
    cout << "A candle fixture on the wall looks a little loose." << endl;
    cout << "Some of the bricks appear loose." << endl;
    cout << "A painting behind the throne is hanging lopsided." << endl << endl;

    cout << "Continue investigating? ";

    YN = YesNo();

    if(YN == true)
    {
        cout << "What would like to investigate?" << endl << endl;
        cout << "1 - Eastern Wall" << endl;
        cout << "2 - Candle Fixture" << endl;
        cout << "3 - Loose Bricks" << endl;
        cout << "4 - Painting" << endl;
        cout << "5 - Give Up" << endl << endl;

        Loop = true;

        while(Loop == true)
        {
            cin >> InvChoice;

            if(InvChoice == 5)
            {
                investigate = 0;
                Loop = false;
            }
            else if(InvChoice == 1)
            {
                investigate = ThroneRoomA();
                Loop = false;
            }
            else if(InvChoice == 2)
            {
                investigate = ThroneRoomB();
                Loop = false;
            }
            else if(InvChoice == 3)
            {
                investigate = ThroneRoomC();
                Loop = false;
            }
            else if(InvChoice == 4)
            {
                investigate = ThroneRoomD();
                Loop = false;
            }
            else
            {
                cout << "This is not a valid choice!";
                cout << "Please enter again: ";
            }
        }
    }
    else
    {
        investigate = 0;
    }

    return investigate;

}

void InvestigateDockHouse(int CharacterStats[3][7], int CharacterInventory[3][14], bool& DockHouse)
{
    bool YN;
    int i;
    int MagicDie;
    int HealthDie;

    cout << "You enter the dock house...\n\n";

    system("PAUSE");

    if(DockHouse == true)
    {
        cout << "The dock house is empty.\n\n";
        system("PAUSE");
    }
    else
    {
        cout << "The dock house is full of potions!\n\nWould you like to take some? ";

        YN = YesNo();

        if(YN == true)
        {
            for(i = 0; i < 3; i ++)
            {
                if(CharacterStats[i][0] != 0)
                {
                    MagicDie = RollDice(16);
                    HealthDie = RollDice(16);

                    CharacterInventory[i][11] += HealthDie;
                    CharacterInventory[i][12] += MagicDie;
                }
            }
            DockHouse = true;
        }
    }

    cout << "You leave the dock house...\n\n";
    system("PAUSE");

    return;
}
