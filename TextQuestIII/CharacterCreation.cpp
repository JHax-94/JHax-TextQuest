#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

#include "Screens.h"
#include "Inputs.h"
#include "Save.h"

#include "characters.h"
#include "towns.h"


void CreateCharacter(character Player[3], string TempRace, string TempGender, string TempFirstName, string TempLastName, int TempRaceID)
{
    int Health[2];
    int Magic[2];
    int Location[2];
    int Str;
    int Agi;
    int Int;

    spell StarterSpells[11];


    if(TempRaceID == 0)
    {
        Health[0] = 150;
        Health[1] = 150;
        Magic[0] = 0;
        Magic[1] = 0;
        Location[0] = 1;
        Location[1] = 0;
        Str = 65;
        Agi = 50;
        Int = 35;


    }
    else if(TempRaceID == 1)
    {
        Health[0] = 150;
        Health[1] = 150;
        Magic[0] = 50;
        Magic[1] = 50;
        Location[0] = 2;
        Location[1] = 0;
        Str = 70;
        Agi = 70;
        Int = 10;

        StarterSpells[0] = ElvenAura;
    }
    else if(TempRaceID == 2)
    {
        Health[0] = 165;
        Health[1] = 165;
        Magic[0] = 75;
        Magic[1] = 75;
        Location[0] = 3;
        Location[1] = 0;
        Str = 70;
        Agi = 20;
        Int = 60;

        StarterSpells[0] = Fireball;
        StarterSpells[1] = Lightning;
    }
    else if(TempRaceID == 3)
    {
        Health[0] = 100;
        Health[1] = 100;
        Magic[0] = 200;
        Magic[1] = 200;
        Location[0] = 4;
        Location[1] = 0;
        Str = 20;
        Agi = 20;
        Int = 110;

        StarterSpells[0] = Fireball;
        StarterSpells[1] = Lightning;
        StarterSpells[2] = Heal;
        StarterSpells[3] = AncientPower;

    }
    else if(TempRaceID == 4)
    {
        Health[0] = 175;
        Health[1] = 175;
        Magic[0] = 0;
        Magic[1] = 0;
        Location[0] = 5;
        Location[1] = 0;
        Str = 90;
        Agi = 50;
        Int = 10;


    }
    else if(TempRaceID == 5)
    {
        Health[0] = 125;
        Health[1] = 125;
        Magic[0] = 100;
        Magic[1] = 100;
        Location[0] = 6;
        Location[1] = 0;
        Str = 30;
        Agi = 60;
        Int = 60;

        StarterSpells[0] = Fireball;
        StarterSpells[1] = Heal;
        StarterSpells[2] = ElvenAura;

    }

    Player[0].AssignStats(true, 0, Health, Magic, Location, Str, Agi, Int, TempRaceID, 0, TempFirstName, TempLastName, TempRace, TempGender, NullQuests, StarterSpells);

    cout << "PLAYER" << endl;
    cout << "======" << endl;

    Player[0].DisplayStats();

}



void Intro(character Player[3])
{
    bool Loop;

    string Screen[32];
    string Title;
    string Subtitle;

    string TempRace;
    string TempGender;
    string TempFirstName; int NameLength;
    string TempLastName;

    string Region;
    string City; int CityLength;

    int CharSelect;
    int TempRaceID;




    ClearScreen(Screen, 32);

    int i;

    Title = "TEXTQUEST III";

    for(i = 0; i < 5; i ++)
    {
        if(i == 0)
        {
            Screen[1] = "  In Textopia, as in all places, the Guardians watch over all...\n";
        }
        if(i == 1)
        {
            Screen[3] = "  They see all that is, all that was, and all that will be...\n";
        }
        if(i == 2)
        {
            Screen[5] = "  Tonight, The Unnamed Guardian, who watches over destiny, will step down\n";
            Screen[6] = "  from The Guardian's Column, and change the fate of Textopia...\n";
        }
        if(i == 3)
        {
            Screen[8] = "  As The Unnamed Guardian leaves, she is confronted by the gatekeeper of the\n";
            Screen[9] = "  Guardian's Column, Trevor...\n";
        }
        if(i == 4)
        {
            Screen[11] = "  Trevor: Unnamed one, what twist of fate are you imposing on the world\n";
            Screen[12] = "  this time?\n";
        }

        DrawScreen(Title, Subtitle, Screen, 32);

        system("PAUSE");
    }

        Screen[14] = "  1 - 'The time of The Upstart has come.' (Human)\n";
        Screen[15] = "  2 - 'Doom from the Wolf's head.' (Lupine)\n";
        Screen[16] = "  3 - 'Fate lies in the Craftsmen.' (Dwarf)\n";
        Screen[17] = "  4 - 'The Forsaken ones will have their redemption.' (Ancient)\n";
        Screen[18] = "  5 - 'Nature will save the world.' (Elf)\n";
        Screen[19] = "  6 - 'Destiny lies in the hands of the Wanderers of the Wastes.' (Orc)\n";
        Screen[20] = "  7 - Information";

        Loop = true;

        while(Loop == true)
        {
            DrawScreen(Title, Subtitle, Screen, 32);

            cin.sync();

            cout << "Enter your choice: ";

            cin >> CharSelect;

            if(CharSelect == 1)
            {
                TempRaceID = 0;
                TempRace = "Human";

                Region = "ORYNDEL";
                City = "Oryldeburg";

                Loop = false;
            }
            else if(CharSelect == 2)
            {
                TempRaceID = 1;
                TempRace = "Lupine";

                Region = "LUPESCRIA";
                City = "Valdyreik";

                Loop = false;
            }
            else if(CharSelect == 3)
            {
                TempRaceID = 2;
                TempRace = "Dwarf";

                Region = "DWEMHILL";
                City = "Dwemenheim";

                Loop = false;
            }
            else if(CharSelect == 4)
            {
                TempRaceID = 3;
                TempRace = "Ancient";

                Region = "ANCIENT'S ISLAND";
                City = "Antiquus-Cuore";

                Loop = false;
            }
            else if(CharSelect == 5)
            {
                TempRaceID = 5;
                TempRace = "Elf";

                Region = "FYNDREL";
                City = "Greycove";

                Loop = false;
            }
            else if(CharSelect == 6)
            {
                TempRaceID = 4;
                TempRace = "Orc";

                Region = "OREMUS";
                City = "Waste's Edge";

                Loop = false;
            }
            else
            {
                cout << "This is not an option!\n\n";
                system("PAUSE");
            }
        }

        ClearScreen(Screen, 14, 20);

        Screen[14] = "  So The Unnamed Guardian travelled to the great city of                       \n";

        CityLength = City.length();

        Screen[14].replace(57, CityLength, City);
        Screen[14].replace(57+CityLength, 3, "...");

        DrawScreen(Title, Subtitle, Screen, 32);

        system("PAUSE");

        ClearScreen(Screen, 32);

        City = UpShift(City);

        Title = Region;
        Subtitle = City += " - SMALL HOUSE";

        Screen[1] = "  A child was born that night, this is the story of how that child went on to\n";
        Screen[2] = "  change Textopia...\n";

        DrawScreen(Title, Subtitle, Screen, 32);

        system("PAUSE");

        Screen[4] = "  Father: Our child is born!\n";

        DrawScreen(Title, Subtitle, Screen, 32);

        system("PAUSE");

        Screen[6] = "  Mother: Is it a boy or a girl?\n";

        DrawScreen(Title, Subtitle, Screen, 32);

        system("PAUSE");

        Screen[8] = "  1 - Male\n";
        Screen[9] = "  2 - Female\n";

        Loop = true;
        while(Loop == true)
        {
            DrawScreen(Title, Subtitle, Screen, 32);

            cin.sync();
            CharSelect = 0;

            cout << "Enter your choice: ";
            cin >> CharSelect;

            if(CharSelect == 1)
            {
                TempGender = "Male";

                Loop = false;
            }
            else if(CharSelect == 2)
            {
                TempGender = "Female";

                Loop = false;
            }
            else
            {
                cout << "This is not an option!\n\n";
                system("PAUSE");
            }
        }

        ClearScreen(Screen, 8, 9);

        if(TempGender == "Male")
        {
            Screen[8] = "  Father: It's a beautiful baby boy! What should we name him?\n";
        }
        else if(TempGender == "Female")
        {
            Screen[8] = "  Father: It's a beautiful baby girl! What should we name her?\n";
        }

        Loop = true;

        while(Loop == true)
        {

            DrawScreen(Title, Subtitle, Screen, 32);

            cout << "Enter character's first name: ";

            cin.sync();

            getline(cin, TempFirstName);

            NameLength = TempFirstName.length();

            if(NameLength <= 12 && NameLength > 0)
            {
                Loop = false;
            }
           else if(NameLength == 0)
            {
                cout << "Character must have a first name!\n\n";

                system("PAUSE");
            }
            else
            {
                cout << "Character name must be 12 letters or less!\n\n";

                system("PAUSE");
            }
        }

        ClearScreen(Screen, 32);

        Title = "TEXTQUEST III";

        Screen[1] = "  The years passed, and              began to grow...\n";

        Screen[1].replace(24, 12, TempFirstName);

        DrawScreen(Title, Screen, 32);

        system("PAUSE");

        Screen[3] = "  10 years later, war broke out...\n";

        DrawScreen(Title, Screen, 32);

        system("PAUSE");

        Screen[5] = "  In the East, the Reidlos had launched attacks on the borders of the Orcs and \n";
        Screen[6] = "  the Elves...\n";

        DrawScreen(Title, Screen, 32);

        system("PAUSE");

        Screen[8] = "  In another 3 years, the Reidlos had taken control of the Wastes. The child's \n";
        Screen[9] = "  father was called away to fight by the Order...\n";

        DrawScreen(Title, Screen, 32);

        system("PAUSE");

        Screen[11] = "  Thanks to the increased number of soldiers provided by the six allied        \n";
        Screen[12] = "  provinces of Textopia, the Reidlos were pushed back from the Wastes...       \n";

        DrawScreen(Title, Screen, 32);

        system("PAUSE");

        Screen[14] = "  However, beyond the mountains to the North of Dwemhill, the Reidlos          \n";
        Screen[15] = "  maintained their armies...\n";

        DrawScreen(Title, Screen, 32);

        system("PAUSE");

        Screen[17] = "  Almost 7 years after the Reidlos were pushed out of the Wastes, Orcish      \n";
        Screen[18] = "  scouts and those either brave or foolish enough to venture into the Wastes  \n";
        Screen[19] = "  began reporting strange happenings out in those harsh lands...\n";

        DrawScreen(Title, Screen, 32);

        system("PAUSE");
                  // "                                                                               \n";
        Screen[21] = "  The Order began conscripting those of suitable age in an attempt to discover \n";
        Screen[22] = "  what was happening...\n";

        DrawScreen(Title, Screen, 32);

        system("PAUSE");

        ClearScreen(Screen, 32);

        Title = Region;
        Subtitle = City += " - TOWN SQUARE";

        for(i = 0; i < 3; i ++)
        {
            if(i == 0)
            {
                         // "                                                                               \n";
                Screen[1] = "  Captain Helx: Oryx the Fourth, Master of the Order has commanded that all    \n";
                Screen[2] = "                capable people above the age of eighteen should be enlisted!   \n";
            }
            if(i == 1)
            {
                        // "                                                                               \n";
                Screen[4] = "  You join the endless queues of potential soldiers and wait in line for a    \n";
                Screen[5] = "  number of hours...\n";

            }
            if(i == 2)
            {
                         // "                                                                               \n";
                Screen[7] = "  Eventually, you reach the front. Captain Helx hands you a piece of paper...  \n";

            }
            DrawScreen(Title, Subtitle, Screen, 32);
            system("PAUSE");
        }

        Screen[9] = "  Captain Helx: Please write your family name at the top.\n";

        Loop = true;

        while(Loop == true)
        {

            DrawScreen(Title, Subtitle, Screen, 32);

            cin.sync();
            cout << "Enter character's family name: ";
            getline(cin, TempLastName);

            NameLength = TempLastName.length();

            if(NameLength <= 12 && NameLength > 0)
            {
                Loop = false;
            }
            else if(NameLength == 0)
            {
                cout << "Character must have a family name!\n\n";
                system("PAUSE");
            }
            else if(NameLength > 12)
            {
                cout << "Family name must be 12 characters or less!\n\n";
                system("PAUSE");
            }
        }
                  // "                                                                               \n";
        Screen[11] = "  Captain Helx: I served with your father when we drove the Reidlos from the   \n";
        Screen[12] = "                Wastes seven years ago. He was a good man...\n";

        DrawScreen(Title, Subtitle, Screen, 32);

        system("PAUSE");

        CreateCharacter(Player, TempRace, TempGender, TempFirstName, TempLastName, TempRaceID);

}


void Tutorial(character Player[3])
{
    string Title;
    string Subtitle;
    string Screen[32];
    string Input;

    ClearScreen(Screen, 32);


    Title = "ORYNDEL";
    Subtitle = "ORYLDEBURG - TRAINING CAMP";

    Player[0].Location[0] = 1;
    Player[0].Location[1] = 0;
    Player[0].Location[2] = 2;

    Screen[1] = "  You travel to Oryldeburg, home of the Order to train before heading off into \n";
    Screen[2] = "  the East...\n";

    DrawScreen(Title, Subtitle, Screen, 32);

    system("PAUSE");

    Screen[4] = "  Captain Helx: Alright recruits, welcome to the Order's training camp. We'll  \n";
    Screen[5] = "                leave you to make yourselves at home for now. Report to the    \n";
    Screen[6] = "                lieutenant of the section you wish to join.                    \n";

    DrawScreen(Title, Subtitle, Screen, 32);

    system("PAUSE");
}
