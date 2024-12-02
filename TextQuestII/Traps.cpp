using namespace std;

#include"dice.h"

bool TrapOn;

bool TrapA(int nCC, int CharacterStats[3][7])
{
    bool Loop = true;
    int roll;

    while(Loop == true)
    {
        if(CharacterStats[nCC][2] >=60)
        {
            TrapOn = false;
            Loop = false;
            break;
        }
        else if(CharacterStats[nCC][3] >= 70)
        {
            TrapOn = false;
            Loop = false;
            break;
        }
        else if(CharacterStats[nCC][4] >= 80)
        {
            roll = RollDice(3);
            if(roll == 6)
            {
                TrapOn = false;
                Loop = false;
                break;
            }
            else
            {
                TrapOn = true;
                Loop = false;
                break;
            }
        }
        else
        {
            TrapOn = true;
            Loop = false;
            break;
        }
    }

    return TrapOn;
}

bool TrapB(int nCC, int CharacterInventory[3][14])
{
    TrapOn = true;

    if(CharacterInventory[nCC][9] != 0)
    {
        TrapOn = false;
        CharacterInventory[nCC][9] --;
    }
    else if(CharacterInventory[nCC][7] != 0)
    {
        TrapOn = false;
        CharacterInventory[nCC][7] --;
    }
    else if(CharacterInventory[nCC][4] != 0)
    {
        TrapOn = false;
        CharacterInventory[nCC][4] --;
    }

    return TrapOn;
}

bool TrapC(int nCC, int CharacterStats[3][7])
{
    TrapOn = true;

    if(CharacterStats[nCC][3] >= 75)
    {
        TrapOn = false;
    }

    return TrapOn;
}

bool TrapD(int nCC, int CharacterStats[3][7])
{
    TrapOn = true;

    if(CharacterStats[nCC][2] >= 80)
    {
        TrapOn = false;
    }

    return TrapOn;
}

bool TrapE(int nCC, int CharacterStats[3][7])
{
    TrapOn = true;

    if(CharacterStats[nCC][4] <= 70)
    {
        TrapOn = false;
    }

    return TrapOn;
}

bool TrapF(int nCC)
{
    TrapOn = true;

    if(nCC == 0)
    {
        TrapOn = false;
    }

    return TrapOn;
}

bool TrapG(int nCC)
{
    TrapOn = true;

    if(nCC == 1)
    {
        TrapOn = false;
    }

    return TrapOn;
}

bool TrapH(int nCC, int CharacterStats[3][7])
{
    TrapOn = true;

    if(CharacterStats[nCC][3] >= 70)
    {
        TrapOn = false;
    }

    return TrapOn;
}

bool TrapI(int nCC, int CharacterStats[3][7])
{
    TrapOn = true;

    if(CharacterStats[nCC][4] >= 80)
    {
        TrapOn = false;
    }

    return TrapOn;
}
