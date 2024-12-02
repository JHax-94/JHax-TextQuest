#ifndef TOWNS_H_INCLUDED
#define TOWNS_H_INCLUDED

#include<iostream>
#include<cstdlib>

#include"buildings.h"

class town
{
    protected:
    int TownSize;

    public:

    int ID;
    int MapLocation[2];
    int Compass[4][2];
    string Name;
    //building Town[32];
    building * Town;

    town operator= (const town& NewTown)
    {
        /*
        town TempTown;

        cout << "TempTown" << endl;
        cout << "========" << endl;
        cout << "ID = " << TempTown.ID << endl;
        cout << "Map Location = (" << TempTown.MapLocation[0] << TempTown.MapLocation[1] << ")" << endl;
        cout << "TownSize = " << TempTown.TownSize << endl;
        cout << "Name = " << TempTown.Name << endl;
        cout << "Buildings: " << endl;
        for(int i = 0; i < TempTown.TownSize; i ++)
        {
            cout << "Name = " << TempTown.Town[i].Name << endl;
            cout << "Header = " << TempTown.Town[i].Header << endl;
        }

        system("PAUSE");
        */
        ID = NewTown.ID;
        TownSize = NewTown.TownSize;
        for(int i = 0; i < 2; i ++)
        {
            MapLocation[i] = NewTown.MapLocation[i];
        }

        Name = NewTown.Name;

        Town = new building[NewTown.TownSize];

        for(int i = 0; i < NewTown.TownSize; i++)
        {/*
                TempTown.Town[i].ID = NewTown.Town[i].ID;
                TempTown.Town[i].Name = NewTown.Town[i].Name;
                TempTown.Town[i].Header = NewTown.Town[i].Header;*/

                Town[i] = NewTown.Town[i];
        }
        for(int i = 0; i < 4; i ++)
        {

            Compass[i][0] = NewTown.Compass[i][0];
            Compass[i][1] = NewTown.Compass[i][1];
        }


        /*
        cout << "TempTown - RETURN" << endl;
        cout << "=================" << endl;
        cout << "ID = " << TempTown.ID << endl;
        cout << "Map Location = (" << TempTown.MapLocation[0] << TempTown.MapLocation[1] << ")" << endl;
        cout << "TownSize = " << TempTown.TownSize << endl;
        cout << "Name = " << TempTown.Name << endl;
        cout << "Buildings: " << endl;
        for(int i = 0; i < TempTown.TownSize; i ++)
        {
            cout << "Name = " << TempTown.Town[i].Name << endl;
            cout << "Header = " << TempTown.Town[i].Header << endl;
        }
        */



        return *this;

    }

    town()
    {
        ID = 0;
        MapLocation[0] = 0;
        MapLocation[1] = 0;
        TownSize = 1;
        Name = " ";
     //   Town = building[32];

        Town = new building[TownSize];

        building Null;

        Town[0] = Null;

        for(int i = 0; i < 4; i ++)
        {
            Compass[i][0] = -1;
            Compass[i][1] = -1;
        }




        /*
        cout << "NULL Town Initialised:" << endl;
        cout << "ID = " << ID << endl;
        cout << "Map Location = (" << MapLocation[0] << MapLocation[1] << ")" << endl;
        cout << "TownSize = " << TownSize << endl;
        cout << "Name = " << Name << endl;
        cout << "Buildings: " << endl;
        for(int i = 0; i < TownSize; i ++)
        {
            cout << "Name = " << Town[i].Name << endl;
            cout << "Header = " << Town[i].Header << endl;
        }

        system("PAUSE");
        */

    }

    town(int NewID, int NewMapLocation[2], int NewCompass[4][2], int NewTownSize, string NewName, building NewTown[])
    {
        ID = NewID;
        MapLocation[0] = NewMapLocation[0];
        MapLocation[1] = NewMapLocation[1];
        TownSize = NewTownSize;
        Name = NewName;

        //cout << "TownSize = " << TownSize << endl;

      //  system("PAUSE");

        Town = new building[TownSize];

        for(int i = 0; i < TownSize; i ++)
        {

            Town[i] = NewTown[i];
           // Town[i].ID = NewTown[i].ID;
          //  cout << "Town[" << i << "] ID = " << Town[i].ID << endl;
            //Town[i].Name = NewTown[i].Name;
            //cout << "Town[" << i << "] Name = " << Town[i].Name << endl;
            //Town[i].Header = NewTown[i].Header;
            //cout << "Town[" << i << "] Header = " << Town[i].Header << endl;
          //  system("PAUSE");
        }
        for(int i = 0; i < 4; i ++)
        {
            Compass[i][0] = NewCompass[i][0];
            Compass[i][1] = NewCompass[i][1];
        }
    }
};

#endif // TOWNS_H_INCLUDED
