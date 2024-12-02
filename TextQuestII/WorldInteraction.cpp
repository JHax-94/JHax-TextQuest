#include <iostream>
#include <cstdlib>

using namespace std;

#include"Input.h"
#include"dice.h"
#include"screens.h"
#include"Info.h"


bool Assassin(int CharacterStats[3][7], int CharacterInventory[3][14], int Enemy[3][8], int nCC)
{
    int weapon;
    int Roll;
    bool success;
    weapon = WeaponInput(nCC, CharacterStats, CharacterInventory);
    if(weapon == 3 || weapon == 4)
    {
        CharacterInventory[nCC][6] -= 2;
    }



    Roll = RollDice(weapon);

    if(Roll >= 3)
    {
        success = true;
    }
    else
    {
        success = false;
    }

    return success;
}


int Sneak(int CharacterStats[3][7], int CharacterInventory[3][14], int Enemy[3][8], int nCC)
{
    int Perception;
    int i;
    int N;
    int Dice;
    int Roll;
    int sneak;
    bool success;
    bool Assassinate;

    for(i = 0; i < 3; i++)
    {
        if(Enemy[i][3] != 0)
        {
            N ++;

            Perception += Enemy[i][3];
        }
    }

    Perception = Perception/N;

    if(Perception >= CharacterStats[nCC][3])
    {
        Dice = 1;
    }
    else
    {
        Dice = 2;
    }

    Roll = RollDice(Dice);

    if(Roll >= 6)
    {
        sneak = 1;
    }
    else
    {
        sneak = 0;
    }

    if(sneak == 1)
    {
        cout << "Attempt assassination? ";

        Assassinate = YesNo();

        if(Assassinate == true)
        {
           success = Assassin(CharacterStats, CharacterInventory, Enemy, nCC);

           if(success == true)
           {
               for(i = 0; i < 3; i++)
               {
                   Enemy[i][0] = 0;
               }
           }
           else if(success == false)
           {
               sneak = 0;
           }
        }
    }

    return sneak;
}

int MoveTable()
{
    int move;
    bool YN;
    int command;
    int die;
    bool Loop;

    cout << "You move the table closer to the bookshelves and climb on top.\n";
    cout << "The shiny object is just out of reach.\n\n";

    cout << "Try to climb shelves? ";

    YN = YesNo();

    if(YN == true)
    {
        cout << "\nBooks begin to fall!\n\n";
        cout << "Do you:\n\n";
        cout << "Dodge" << endl;
        cout << "Bat the books away" << endl;
        cout << "Keep Climbing" << endl;
        cout << "Hold On" << endl << endl;
        Loop = true;
        while(Loop == true)
        {
            command = Input();

            if(command == 100)
            {
                die = RollDice(5);

                if(die == 1)
                {
                    cout << endl << "You jump to the side and manage to grab onto another shelf! \nYou continue upwards and reach the shiny object!\n\n";
                    move = 1;
                }
                else if(die == 2)
                {
                    cout << endl << "You jump to the side and grab onto another shelf! \nBut it breaks in half, burying you under a pile of books!\n\n";
                    move = -1;
                }
                else if(die == 3)
                {
                    cout << endl << "You jump to the side and try to grab onto a shelf! \nBut you miss and crash into the ground, seriously hurting yourself!\n\n";
                    move = -2;
                }
                Loop = false;
            }
            else if(command == 101)
            {
                cout << endl << "You try to bat away at the falling books, but you lose \nbalance and fall off the shelves, seriously hurting yourself!\n\n";
                move = -2;
                Loop = false;
            }
            else if(command == 102)
            {
                cout << endl << "You keep moving into the shower of ancient tomes, but one \nhits you in the head! You fall to your death!\n\n";
                move = -1;
                Loop = false;
            }
            else if(command == 103)
            {
                cout << endl << "You hold on tight to the shelves! \nThe books batter you a little bit, but you come out unhurt. \nYou continue climbing and reach the shiny object!\n\n";
                move = 1;
                Loop = false;

            }
            else
            {
                cout << "This is not a valid command at the moment!\n";
                cout << "Please enter again: ";
            }
        }
    }
    else if(YN == false)
    {
        move = 0;
    }
    system("PAUSE");

    return move;
}

int BlackKnightConv(string Screen[32], string CharacterInfo[3][3], int CharacterInventory[3][14], int nCC)
{
    int response = 0;
    int PlayerInput;
    int i;

    bool Loop;
    bool Continue;

    Screen[16] = "  Black Knight: Greetings travellers. You have done well to come so far. Tell  \n";
    Screen[17] = "                me, why are you here?                                          \n";
    Screen[19] = "  Reply to the Black Knight:                                                   \n";
    Screen[20] = "  1 - 'We ran into the cave attempting to escape from the Reidlosian Army, and \n";
    Screen[21] = "       fought our way down here floor by floor.'                               \n";
    Screen[22] = "  2 - 'It is of no concern to you.'                                            \n";
    Screen[23] = "  3 - 'We're leaving now.'                                                     \n";

    Loop = true;

    while(Loop == true)
    {
        drawScreen(Screen, 32);

        cin.sync();

        cin >> PlayerInput;

        if(PlayerInput == 1)
        {
            response ++;
            Loop = false;
            Continue = true;

            cout << "\n  Black Knight: Ah, you have undertaken a great task indeed.\n\n";

            system("PAUSE");

        }
        else if(PlayerInput == 2)
        {
            response --;
            Loop = false;
            Continue = true;

            cout << "\n  Black Knight: Very well.\n\n";

            system("PAUSE");
        }
        else if(PlayerInput == 3)
        {
            Loop = false;
            Continue = false;
            cout << "\n Black Knight: Farewell...\n\n";
            system("PAUSE");
        }
        else
        {
            cout << "This is not a valid reply!\n\n";

            system("PAUSE");
        }
    }

    if(Continue == true)
    {
        Screen[16] = "  Black Knight: Would you like to hear my story?                               \n";
        Screen[17] = "                                                                               \n";
        Screen[19] = "  Reply to the Black Knight:                                                   \n";
        Screen[20] = "  1 - 'Yes, please, tell us.'                                                  \n";
        Screen[21] = "  2 - 'I'd rather poke my eyes out with a pointed stick.'                      \n";
        Screen[22] = "  3 - 'We're leaving now.'                                                     \n";


        while(Loop == true)
        {
            drawScreen(Screen, 32);

            cin.sync();
            cin >> PlayerInput;

            if(PlayerInput == 1)
            {
                response ++;
                Loop = false;
                Continue = true;
                cout << "\n  Black Knight: Very well, I shall tell you my tale.\n\n";

                system("PAUSE");
            }
            else if(PlayerInput == 2)
            {
                response --;
                Loop = false;
                Continue = false;
                cout << "\n  Black Knight: Then you shall go on without warning.\n\n";
                system("PAUSE");
            }
            else if(PlayerInput == 3)
            {
                Loop = false;
                Continue = false;
                cout << "\n Black Knight: Farewell...\n\n";
                system("PAUSE");
            }
            else
            {
                cout << "This is not a valid reply!\n\n";

                system("PAUSE");
            }
        }
    }

    if(Continue == true)
    {
        Screen[16] = "  Black Knight: Nearly 200 years ago I ventured into a cave not unlike this    \n";
        Screen[17] = "                one. I was curious and the intrigue pulled me in! During my    \n";
        Screen[18] = "                adventure I stumbled upon an ancient weapon. The only weapon   \n";
        Screen[19] = "                in existence that is capable of breaking through the thick     \n";
        Screen[20] = "                scales of a dragon. No one knows quite how it works, some sort \n";
        Screen[21] = "                of magic, from before the time of even the Ancients. After I   \n";
        Screen[22] = "                left the cave I assembled a group of like minded adventurers   \n";
        Screen[23] = "                and came here to defend the ancient weapon. But being in this  \n";
        Screen[24] = "                cave has had a strange effect on us all. You cannot leave this \n";
        Screen[25] = "                place without the weapon.                                      \n";
        Screen[27] = "  Reply to the Black Knight:                                                   \n";
        Screen[28] = "  1 - 'Where can I find this weapon?'                                          \n";
        Screen[29] = "  2 - 'I think we'll take our chances without your mystical weapon.'           \n";
        Screen[30] = "  3 - 'We're leaving now.'                                                     \n";

        Loop = true;

        while(Loop == true)
        {
            drawScreen(Screen, 32);

            cin.sync();

            cin >> PlayerInput;

            if(PlayerInput == 1)
            {
                Loop = false;
                Continue = true;
                cout << "\n  Black Knight: Very well, I shall tell you.\n\n";
                system("PAUSE");
            }
            else if(PlayerInput == 2)
            {
                Loop = false;
                Continue = false;
                cout << "\n  Black Knight: You cannot leave without it.\n                You would've been wise to hear my words.\n\n";

                system("PAUSE");
            }
            else if(PlayerInput == 3)
            {
                Loop = false;
                Continue = false;
                cout << "\n  Black Knight: Very well, but you cannot leave without it.\n\n";
                system("PAUSE");
            }
            else
            {
                cout << "\nThis is not a valid reply!\n\n";
                system("PAUSE");
            }
        }
    }

    if(Continue == true)
    {
        if(CharacterInventory[0][3] != 0 || CharacterInventory[1][3] != 0 || CharacterInventory[2][3] != 0)
        {
            cout << "\n  Black Knight: Ah, brave warrior, I see you carry my old sword.\n                It served me well, it's good to see it put to good use.\n\n";
            system("PAUSE");
            response ++;
        }

        if(PlayerInput == 1 && response >= 3)
        {

            Screen[16] = "  Black Knight: The ancient weapon lies in a room hidden past a secret passage \n";
            Screen[17] = "                in the library.                                                \n";
            Screen[18] = "                No wait...it was by the armoury...oh good heavens I've         \n";
            Screen[19] = "                completely forgotten! However, the Warlock should know. Ah!    \n";
            Screen[20] = "                You may find him in his lair, that's definitely at the end of  \n";
            Screen[21] = "                a secret passage in the library! It should be in the North     \n";
            Screen[22] = "                Western corner, just go there and push past the North wall.    \n";
            Screen[23] = "                Tell him I sent you and he will tell you where the weapon lies.\n";
            Screen[24] = "                                                                               \n";
            Screen[25] = "  Reply to the Black Knight:                                                   \n";
            Screen[26] = "  1 - 'Thank you, we shall go at once!'                                        \n";
            Screen[27] = "  2 - 'We're leaving now.'                                                     \n";
            Screen[28] = "                                                                               \n";
            Screen[29] = "                                                                               \n";
            Screen[30] = "                                                                               \n";

            response = 100;

            Loop = true;

            while(Loop == true)
            {
                drawScreen(Screen, 32);

                cin.sync();

                cin >> PlayerInput;

                if(PlayerInput == 1)
                {
                    cout << "\n  Black Knight: Thank you for your visit. Now, I think I can rest.\n\n";
                    Loop = false;
                    system("PAUSE");
                }
                else if(PlayerInput == 2)
                {
                    cout << "\n  Black Knight: Farewel...\n\n";
                    Loop = false;
                    system("PAUSE");
                }
            }
        }
    }

    for(i = 16; i <= 30; i ++)
    {
        Screen[i] = "                                                                               \n";
    }

    return response;
}


void CaveJourney(int CharacterStats[3][7], string CharacterInfo[3][3])
{
    int Die;
    int i;

    Die = RollDice(5);

    if(Die == 1)
    {
        for(i = 0; i < 3; i ++)
        {
            if(CharacterStats[i][3] <= 50)
            {
                CharacterStats[i][0] = 0;

                cout << CharacterInfo[i][0] << " slipped on a rock and died.\n\n";
                system("PAUSE");
            }
        }
    }
    return;
}

bool WarlockHeal(int CharacterStats[3][7])
{
    int Dice;
    int i;

    bool alive = true;
    bool YN;

    cout << "  Warlock: Hmm...healing potion...\n\n";

    system("PAUSE");
    cout << "\n  Warlock: I think this is the right bottle...\n\n";

    cout << "Are you sure you want to drink the potion? ";

    YN = YesNo();

    if(YN == true)
    {
        Dice = RollDice(12);

        if(Dice == 1)
        {
            for(i = 0; i < 3; i ++)
            {
                CharacterStats[i][0] = CharacterStats[i][5];
            }

        }
        else if(Dice == 2)
        {
            for(i = 0; i < 3; i ++)
            {
                CharacterStats[i][0] = 0;
            }
            alive = false;
        }
    }
    else
    {
        cout << "You decline the potion...\n\n";

        system("PAUSE");
    }

    return alive;
}

void WarlockInfo(string Screen[32])
{
    Screen[14] = "  Warlock: Ah, you want to know the location of the great weapon. The only     \n";
    Screen[15] = "           way to find it is walk through the wall to the west of the          \n";
    Screen[16] = "           West of the crossroads in the Great Maze.                           \n";
    Screen[17] = "                                                                               \n";
    Screen[18] = "                                                                               \n";

    system("PAUSE");


    return;
}


void WarlockConv(string Screen[32], int BlackKnight, int CharacterStats[3][7])
{
    bool Loop;
    bool alive = true;
    bool YN;

    int UserInput;

    Screen[14] = "  Warlock: So, what do you four want with an old Warlock like me?              \n";
    Screen[16] = "  Reply to Warlock:                                                            \n";
    Screen[17] = "  1 - 'We need healing!'                                                       \n";

    if(BlackKnight == 100)
    {
        Screen[18] = "  2 - 'The Black Knight sent us.                                               \n";
        Screen[19] = "  3 - 'We have to go.'                                                         \n";
    }
    else
    {
        Screen[18] = "  2 - 'We have to go.'                                                         \n";
    }

    Loop = true;

    while(Loop == true)
    {
        drawScreen(Screen, 32);

        cin.sync();

        cin >> UserInput;

        if(UserInput == 1)
        {
            alive = WarlockHeal(CharacterStats);

            if(alive == true)
            {
                cout << "Would you like to continue the conversation? ";
                YN = YesNo();

                if(YN == false)
                {
                    Loop = false;
                    cout << "  Warlock: Farewell courageous gnomes!\n\n";
                    system("PAUSE");
                }
            }
            else
            {
                Loop = false;
            }
        }
        else if(UserInput == 2 && BlackKnight == 100)
        {
            WarlockInfo(Screen);

            cout << "Would you like to continue the conversation? ";
            YN = YesNo();

            if(YN == false)
            {
                Loop = false;
                cout << "  Warlock: Farewell gallant antelopes!\n\n";
                system("PAUSE");
            }

        }
        else if((UserInput == 3 && BlackKnight == 100) ||(UserInput == 2 && BlackKnight != 100))
        {
            cout << "  Warlock: Farewell brave wombats!\n\n";
            system("PAUSE");

            Loop = false;
        }
    }



    return;
}

bool SpoonChest(int CharacterStats[3][7], int CharacterInventory[3][14], string CharacterInfo[3][3])
{
    bool Loop;
    bool HasSpoon = false;

    int PlayerInput;
    int Selection;

    cout << "You open the chest to find a rusty spoon.\n";
    cout << "Who should take the rusty spoon?\n";
    if(CharacterStats[0][0] != 0)
    {
        cout << "1 - " << CharacterInfo[0][0] << endl;
    }
    if(CharacterStats[1][0] != 0)
    {
        cout << "2 - " << CharacterInfo[1][0] << endl;
    }
    if(CharacterStats[2][0] != 0)
    {
        cout << "3 - " << CharacterInfo[2][0] << endl;
    }
    cout << "0 - Leave the Rusty Spoon where it is.\n";

    Loop = true;

    while(Loop == true)
    {
        cin.sync();

        cin >> PlayerInput;

        Selection = PlayerInput - 1;

        if(CharacterStats[Selection][0] != 0)
        {
            CharacterInventory[Selection][10] = 1;
            cout << CharacterInfo[Selection][0] << " picks up the rusty spoon.\n\n";
            Loop = false;
            system("PAUSE");
            HasSpoon = true;
        }
        else if(CharacterStats[Selection][0] == 0)
        {
            cout << "This character is dead!\n\n";
            system("PAUSE");
        }
        else if(Selection == 0)
        {
            cout << "You decide to leave the Rusty Spoon.\n\n";
            Loop = false;
        }
        else
        {
            cout << "This is not a valid input.\n\n";

            system("PAUSE");
        }
    }
    return HasSpoon;
}

void CombineItems(int CharacterInventory[3][14], int nCC)
{
    int item;

    int i;

    if(CharacterInventory[0][10] != 0)
    {
        nCC = 0;
    }
    else if(CharacterInventory[1][10] != 0)
    {
        nCC = 1;
    }
    else if(CharacterInventory[2][10] != 0)
    {
        nCC = 2;
    }

    for(i = 3; i != 0; i --)
    {

        item = CombineItemInput(nCC, CharacterInventory);

        if(item == 7)
        {
            cout << "The wizard casts his spell...\n\n";

            system("PAUSE");

            cout << "The Pointed Stick and Rusty Spoon meld together, as if joined by some \nmystical force!\n\n";
            system("PAUSE");

            CharacterInventory[nCC][10] = 0;
            CharacterInventory[nCC][9] = 0;
            CharacterInventory[nCC][13] = 1;

            i = 1;
        }
        else
        {
            cout << "The wizard casts his spell...\n\n";

            system("PAUSE");

            cout << "Nothing happens...\n\n";

            system("PAUSE");
        }
    }
    return;
}

void WizardConv(string Screen[32], int CharacterInventory[3][14], int nCC)
{
    bool YN;

    int i;

    Screen[17] = "  Wizard: Ah, very well, you have defeated me.                                 \n";

    if(CharacterInventory[0][10] != 0 || CharacterInventory[1][10] != 0 || CharacterInventory[2][10] != 0)
    {
        Screen[18] = "          I sense the presence of the Rusty Spoon. I have studied Ancient      \n";
        Screen[19] = "          magic at great length. Though the Spoon predates the Ancients by     \n";
        Screen[20] = "          millenia, they had an obsession with it for aeons. Some Ancient      \n";
        Screen[21] = "          enchanters believed it was possible to make it even more powerful by \n";
        Screen[22] = "          combining it with something that has no discernable power of its own.\n";
        Screen[23] = "          I believe I've found the spell that allows such a combination to     \n";
        Screen[24] = "          happen. However, I only have the ability to try the spell three      \n";
        Screen[25] = "          times. Do you want me to try?                                        \n";

        drawScreen(Screen, 32);

        cout <<  "Do you want the wizard to try and combine the rusty spoon with something? ";
        YN = YesNo();

        if(YN == true)
        {
            CombineItems(CharacterInventory, nCC);
        }
        else
        {
            cout << "  Wizard: Hmm...very well. Farewell.\n\n";
            system("PAUSE");
        }
    }
    else
    {
        Screen[17] = "          At this moment in time, you have no use for me. Return should you    \n";
        Screen[18] = "          stumble across a weapon of great power. Farewell.                    \n";

        system("PAUSE");
    }

    for(i = 18; i <= 25; i ++)
    {
        Screen[i] = "                                                                               \n";
    }
    Screen[17] = "  There is a table covered in old manuscripts and ancient tomes. The wizard's  \n";
    Screen[18] = "  tower continues East and West. An old wizard faces the window.               \n";


    return;
}

void AddPotions(int CharacterInventory[3][14], int CharacterStats[3][7])
{
    int i;
    int MagicDie;
    int HealthDie;

    for(i = 0; i < 3; i ++)
    {
        if(CharacterStats[i][0] != 0)
        {
            MagicDie = RollDice(16);
            HealthDie = RollDice(16);

            CharacterInventory[i][11] += HealthDie;
            CharacterInventory[i][12] += MagicDie;
        }
    }
    return;
}
