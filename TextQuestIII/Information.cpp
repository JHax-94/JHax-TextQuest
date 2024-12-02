#include<cstdlib>
#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

#include "Screens.h"

#include "maps.h"

void Menu()
{
    int Choice;

    bool MenuOn;

    string Title;
    string Subtitle;
    string Screen[32];

    ClearScreen(Screen, 32);

    MenuOn = true;

    while(MenuOn == true)
    {
        Title = "INFORMATION";
        Subtitle = "MENU";

        Screen[1] = "  1 - History\n";
        Screen[2] = "  2 - Races\n";
        Screen[3] = "  3 - Maps\n";
        Screen[4] = "  4 - \n";
        Screen[5] = "  5 - Main Menu\n";

        DrawScreen(Title, Subtitle, Screen, 32);

        cout << "Please select: ";
        cin >> Choice;

        switch(Choice)
        {
            case 1:
            {

            break;
            }
            case 2:
            {

            break;
            }
            case 3:
            {
               MapMenu();

            break;
            }
            case 4:
            {

                break;
            }
            case 5:
            {

                MenuOn = false;
            break;
            }
            default:
            {
                cout << "This is not an option!\n\n";
                system("PAUSE");
            break;
            }


        }
    }
}
