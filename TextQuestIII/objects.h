#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED

#include<string>

using namespace std;

class object
{
    public:

    int ID;
    string Name;
    bool Interactions[10];

    object()
    {
        ID = 0;

        Name = "Empty";
        for(int i = 0; i < 10; i ++)
        {
            Interactions[i] = false;
        }
    }
    object(int NewID, string NewName, bool NewInteractions[])
    {
        ID = NewID;
        Name = NewName;
        for(int i; i < 10; i ++)
        {
            Interactions[i] = NewInteractions[i];
        }
    }

    object(const object& NewObject)
    {
        ID = NewObject.ID;
        Name = NewObject.Name;
        for(int i; i < 10; i ++)
        {
            Interactions[i] = NewObject.Interactions[i];
        }
    }


    object operator= (const object& OldObject)
    {
        ID = OldObject.ID;
        Name = OldObject.Name;
        for(int i = 0; i < 10; i ++)
        {
            Interactions[i] = OldObject.Interactions[i];
        }

        return *this;
    }

};

extern object NullObject;
extern object CampFire;

#endif // OBJECTS_H_INCLUDED
