#ifndef ARENAS_H_INCLUDED
#define ARENAS_H_INCLUDED

using namespace std;

#include "objects.h"

class arena
{
    public:

    int Size;
    int * Positions;
    object * Objects;

    arena()
    {
        Size = 6;

        Objects = new object[Size];
        for(int i = 0; i < Size; i ++)
        {
            Objects[i] = object();
        }

        Positions = new int[Size];
        for(int i = 0; i < Size; i ++)
        {
            Positions[i] = 0;
        }
    }

    arena(int NewSize, object NewObjects[])
    {
        Size = NewSize;

        Objects = new object[Size];
        for(int i = 0; i < Size; i ++)
        {
            Objects[i] = NewObjects[i];
        }
        Positions = new int[Size];
        for(int i = 0; i < Size; i ++)
        {
            Positions[i] = 0;
        }

    }

    void InitialisePos(int Allies, int Enemies);
    int GetPos(int nCC, bool PlayerOn);
    void ChangePos(int nCC, int MoveTo, bool PlayerOn);
    void BumpPos(int From, int To);
    bool IsEmpty(int Test);



};

extern arena NullArena;
extern arena TrainingCampArena;

#endif // ARENAS_H_INCLUDED
