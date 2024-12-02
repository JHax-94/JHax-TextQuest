#include<iostream>
#include<cstdio>
#include<time.h>
#include<cstdlib>

using namespace std;

int RollDice(int Dice)
{
    int Roll;

    if(Dice == 0)
    {
        Roll = rand() % 2 + 1;
    }
    else if(Dice == 1)
    {
        Roll = rand() % 6 + 1;
    }
    else if(Dice == 2)
    {
        Roll = rand() % 12 + 1;
    }
    else if(Dice == 3)
    {
        Roll = rand() % 6 + 1;
    }
    else if(Dice == 4)
    {
        Roll = rand() % 12 + 1;
    }
    else if(Dice == 5)
    {
        Roll = rand() % 3 + 1;
    }
    else if(Dice == 6)
    {
        Roll = rand() % 6 + 1;
    }
    else if(Dice == 7)
    {
        Roll = rand() % 3 + 1;
    }
    else if(Dice == 8)
    {
        Roll = rand() % 6 + 1;
    }
    else if(Dice == 9)
    {
        Roll = rand() % 5 + 1;
    }
    else if(Dice == 10)
    {
        Roll = rand() % 4 + 1;
    }
    else if(Dice == 11)
    {
        Roll = rand() % 3 + 1;
    }
    else if(Dice == 12)
    {
        Roll = rand() % 2 + 1;
    }
    else if(Dice == 13)
    {
        Roll = rand() % 100 + 1;
    }
    else if(Dice == 14)
    {
        Roll = rand() % 25 + 1;
    }
    else if(Dice == 15)
    {
        Roll = rand() % 3;
    }
    else if(Dice == 16)
    {
        Roll = rand() % 10 + 1;
    }
    else if(Dice == 17)
    {
        Roll = rand() % 25 + 1;
    }
    else if(Dice == 18)
    {
        Roll = rand() % 50 + 1;
    }
    else if(Dice == 19)
    {
        Roll = rand() % 15 + 1;
    }

    return Roll;

}
