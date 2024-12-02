#ifndef BUILDINGS_H_INCLUDED
#define BUILDINGS_H_INCLUDED
#include<iostream>
#include<string>
#include<cstdlib>

#include"characters.h"


using namespace std;

class building
{

    public:

    int ID;
    string Name;
    string Header;
    bool Adj[9];
    int nResidents;
    character * Residents;

    string Picture[18];

    building operator= (const building& NewBld)
    {

/*
        NewBld.DisplayInfo();

        cout << "NewBld" << endl;
        cout << "======" << endl;
        cout << NewBld.ID << endl;
        cout << NewBld.Name << endl;
        cout << NewBld.Header << endl;
*/
        ID = NewBld.ID;
        Name = NewBld.Name;
        Header = NewBld.Header;

        for(int i = 0; i < 9; i ++)
        {
            Adj[i] = NewBld.Adj[i];
        }

        nResidents = NewBld.nResidents;

        Residents = new character[nResidents];

        for(int i = 0; i < nResidents; i ++)
        {
            Residents[i] = NewBld.Residents[i];
        }


/*
        cout << "TempBld - RETURN" << endl;
        cout << "================" << endl;
        cout << TempBld.ID << endl;
        cout << TempBld.Name << endl;
        cout << TempBld.Header << endl;
*/
        return *this;

    }

    building(int NewID, string NewName, string NewHeader, bool NewAdj[], int NewnResidents, character NewResidents[])
    {
        ID = NewID;
        Name = NewName;
        Header = NewHeader;

        for(int i = 0; i < 9; i ++)
        {
            Adj[i] = NewAdj[i];
        }

        nResidents = NewnResidents;

        Residents = new character[nResidents];

        for(int i = 0; i < NewnResidents; i ++)
        {
            Residents[i] = NewResidents[i];
        }


        /*
        cout << "New Building Initialised:" << endl;
        cout << "ID = " << ID << endl;
        cout << "Name = " << Name << endl;
        cout << "NewHeader = " << Header << endl;
        system("PAUSE");
        */

    }
    building()
    {
        ID = -1;
        Name = " ";
        Header = " ";
        for(int i = 0; i < 9; i ++)
        {
            Adj[i] = false;
        }

        nResidents = 0;

        Residents = new character[1];

        character Null;

        Residents[0] = Null;

    }



    void AddName(string NewName);
    void AddHeader(string NewHeader);
    void DisplayInfo();

    string GetName();
    string GetHeader();
};

#endif // BUILDINGS_H_INCLUDED
