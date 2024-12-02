#include<fstream>
#include<string>

using namespace std;

void SaveWorld(int Party[3], int Stage, int ScreenType, bool CompletedQuests[])
{
    ofstream Save;
    int i;

    Save.open("WorldSave.tqs");

    for(i = 0; i < 3; i ++)
    {
        Save << Party[i] << endl;
    }

    Save << Stage << endl;

    Save << ScreenType << endl;

    for(int i = 0; i < 1; i ++)
    {
        Save << CompletedQuests[i] << endl;
    }

    Save.close();
}

void LoadWorld(int Party[3], int &Stage, int &ScreenType, bool CompletedQuests[])
{
    ifstream Load;
    int i;

    Load.open("WorldSave.tqs");

    for(i = 0; i < 3; i ++)
    {
        Load >> Party[i];
    }

    Load >> Stage;

    Load >> ScreenType;

    for(int i = 0; i < 1; i ++)
    {
        Load >> CompletedQuests[i];
    }

    Load.close();
}
