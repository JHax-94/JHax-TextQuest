#include"arenas.h"


object TrainingCampObjects[7] =
{
    object(NullObject),
    object(NullObject),
    object(NullObject),
    object(NullObject),
    object(NullObject),
    object(NullObject),
    object(CampFire)
};

arena NullArena;
arena TrainingCampArena(7, TrainingCampObjects);


void arena::InitialisePos(int Allies, int Enemies)
{
    for(int i = 0; i < Allies; i ++)
    {
        Positions[i] = i+1;
    }

    for(int i = 0; i < Enemies; i ++)
    {
        Positions[i+Allies] = -(i+1);
    }

}

int arena::GetPos(int nCC, bool PlayerOn)
{
    int Position;

    for(int i = 0; i < Size; i ++)
    {
        if(PlayerOn == true)
        {
            if(Positions[i] == (nCC+1))
            {
                Position = i;
            }
        }
        else if(PlayerOn == false)
        {
            if(Positions[i] == -(nCC+1))
            {
                Position = i;
            }
        }
    }
    return Position;
}

void arena::ChangePos(int nCC, int MoveTo, bool PlayerOn)
{
    int CnCC;
    if(PlayerOn == true)
    {
        CnCC = nCC + 1;
    }
    else
    {
        CnCC = -(nCC+1);
    }

    for(int i = 0; i < Size; i ++)
    {
        if(Positions[i] == CnCC)
        {
            Positions[i] = 0;
        }
    }

    Positions[MoveTo] = CnCC;
}

void arena::BumpPos(int From, int To)
{
    for(int i = 0; i < Size; i ++)
    {
        if(Positions[i] == From)
        {

            Positions[i] = 0;

        }
        else if(Positions[i] == To)
        {
            Positions[i] = From;
        }
    }
}

bool arena::IsEmpty(int Test)
{
    bool Empty;


    if(Positions[Test] != 0)
    {
        Empty = false;
    }
    else
    {
        Empty = true;
    }

    return Empty;
}

