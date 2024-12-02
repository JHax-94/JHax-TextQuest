#include<iostream>
#include<string>
#include<cstdlib>


using namespace std;

#include"screens.h"

string Screen[32];

void ViewStats(int CharacterStats[3][7], string CharacterInfo[3][3])
{
    int stringLength;
    int i;
    int j;

    cout << endl;

    for(i = 0; i < 3; i ++)
    {
        if(CharacterStats[i][0] != 0)
        {
            stringLength = CharacterInfo[i][0].length();

            cout << CharacterInfo[i][0] << endl;
            for(j = 0; j < stringLength; j ++)
            {
                cout << "=";
            }
            cout << endl;

            cout << "Health: " << CharacterStats[i][0] << "/" << CharacterStats[i][5] << endl;
            cout << "Magic: "  << CharacterStats[i][1] << "/" << CharacterStats[i][6] << endl;
            cout << "Race: "   << CharacterInfo[i][2] << endl;
            cout << "Gender: " << CharacterInfo[i][1] << endl;
            cout << endl;
        }
    }


    system("PAUSE");

    return;
}

void ViewInventory(int CharacterStats[3][7], string CharacterInfo[3][3], int CharacterInventory[3][14], int Keys[])
{
    int stringLength;
    int i;
    int j;

    cout << endl;

    for(i = 0; i < 3; i ++)
    {
        if(CharacterStats[i][0] != 0)
        {
            stringLength = CharacterInfo[i][0].length();

            cout << CharacterInfo[i][0] << endl;
            for(j = 0; j < stringLength; j ++)
            {
                cout << "=";
            }
            cout << endl;

            if(CharacterInventory[i][0] != 0)
            {
                cout << CharacterInventory[i][0] << " x Plate Armour" << endl;
            }
            if(CharacterInventory[i][1] != 0)
            {
                cout << CharacterInventory[i][1] << " x Leather Armour" << endl;
            }
            if(CharacterInventory[i][2] != 0)
            {
                cout << CharacterInventory[i][2] << " x Sword" << endl;
            }
            if(CharacterInventory[i][3] != 0)
            {
                cout << CharacterInventory[i][3] << " x Black Knight's Sword" << endl;
            }
            if(CharacterInventory[i][4] != 0)
            {
                cout << CharacterInventory[i][4] << " x Bow" << endl;
            }
            if(CharacterInventory[i][5] != 0)
            {
                cout << CharacterInventory[i][5] << " x Dragon Strike Bow" << endl;
            }
            if(CharacterInventory[i][6] != 0)
            {
                if(CharacterInventory[i][6] == 1)
                {
                    cout << CharacterInventory[i][6] << " x Arrow" << endl;
                }
                else
                {
                    cout << CharacterInventory[i][6] << " x Arrows" << endl;
                }
            }
            if(CharacterInventory[i][7] != 0)
            {
                cout << CharacterInventory[i][7] << " x Staff" << endl;
            }
            if(CharacterInventory[i][8] != 0)
            {
                cout << CharacterInventory[i][8] << " x Staff of the Ancients" << endl;
            }
            if(CharacterInventory[i][9] != 0)
            {
                cout << CharacterInventory[i][9] << " x Pointed Stick" << endl;
            }
            if(CharacterInventory[i][10] != 0)
            {
                cout << CharacterInventory[i][10] << " x Rusty Spoon" << endl;
            }
            if(CharacterInventory[i][11] != 0)
            {
                cout << CharacterInventory[i][11] << " x Health Potion" << endl;
            }
            if(CharacterInventory[i][12] != 0)
            {
                cout << CharacterInventory[i][12] << " x Magic Potion" << endl;
            }
            if(CharacterInventory[i][13] != 0)
            {
                cout << CharacterInventory[i][13] << " x Rusty Spoon on a Stick" << endl;
            }
        }

        cout << endl;
    }

    cout << "KEYS" << endl;
    cout << "====" << endl;


    if(Keys[0] != 0)
    {
        cout << "Rusty Key" << endl;
    }
    if(Keys[1] != 0)
    {
        cout << "Shiny Key" << endl;
    }
    if(Keys[2] != 0)
    {
        cout << "Black Key" << endl;
    }
    if(Keys[3] != 0)
    {
        cout << "Gold Key" << endl;
    }
    cout << endl;
    system("PAUSE");
}


void HumanInfo()
{
    Screen[0]  = "===============================================================================\n";
    Screen[1]  = "=============================INFORMATION=======================================\n";
    Screen[2]  = "============================RACES - HUMAN======================================\n";
    Screen[3]  = "                                                                               \n";
    Screen[4]  = "  A brave and relatively young race in Textopia, often considered upstartish   \n";
    Screen[5]  = "  by some of the older races, especially the elves and the ancients. Although  \n";
    Screen[6]  = "  the fact that Oryx, leader of The Order is Human has done a great service to \n";
    Screen[7]  = "  the reputation of humanity. Humans tend to be strong and relatively agile,   \n";
    Screen[8]  = "  although are less intelligent than other races and lack any inate magical    \n";
    Screen[9]  = "  abilities of the older races, often lending them to ridicule. However human  \n";
    Screen[10] = "  mages are gaining in popularity and are often respected by the rest of the   \n";
    Screen[11] = "  magical establishment, perhaps rather back handedly for their determination  \n";
    Screen[12] = "  to overcome the fact that they are not born with magical ability and instead \n";
    Screen[13] = "  must undergo fairly intense training to gain it.                             \n";
    Screen[14] = "  Humans however are gradually gaining power as unlike other races they aren't \n";
    Screen[15] = "  naturally geared towards certain abilities, which makes them very adaptable. \n\n";

    drawScreen(Screen, 32);

    system("PAUSE");
    EmptyScreen(Screen);
    system("CLS");
    return;

}

void ElfInfo()
{
    Screen[0]  = "===============================================================================\n";
    Screen[1]  = "=============================INFORMATION=======================================\n";
    Screen[2]  = "=============================RACES - ELF=======================================\n";
    Screen[3]  = "                                                                               \n";
    Screen[4]  = "  Elves are a proud race, though often look down on by the ancients. Elves are \n";
    Screen[5]  = "  naturally talented when it comes to magic, and are also very agile. However, \n";
    Screen[6]  = "  elves are often quite brittle as their upbringing is largely focused on      \n";
    Screen[7]  = "  honing their magical skills. Some elves rebel against this and leave the     \n";
    Screen[8]  = "  glades that most elves call home. These rebels roam the dark forests of      \n";
    Screen[9]  = "  Textopia with a bow in hand often forming small pseudo-families.             \n";
    Screen[10] = "  Wild elves are often called back by their homes in times of need and in the  \n";
    Screen[11] = "  majority of case they respond. Since the races were united under The Order   \n";
    Screen[12] = "  and the Reidlos, almost every elf is used in an army due to their excellent  \n";
    Screen[13] = "  skills in the battlefield.                                                   \n\n";

    drawScreen(Screen, 32);

    system("PAUSE");
    EmptyScreen(Screen);
    system("CLS");
    return;
}

void OrcInfo()
{
    Screen[0]  = "===============================================================================\n";
    Screen[1]  = "=============================INFORMATION=======================================\n";
    Screen[2]  = "=============================RACES - ORC=======================================\n";
    Screen[3]  = "                                                                               \n";
    Screen[4]  = "  The Orcish hordes are the largest military groups in the whole of Textopia,  \n";
    Screen[5]  = "  every single Orc is trained to fight as soon as they can hold a weapon.      \n";
    Screen[6]  = "  The hordes lack discipline and have very little grasp of strategy. Every     \n";
    Screen[7]  = "  now and then a chief or shaman of will gain power enough to unite the hordes \n";
    Screen[8]  = "  and occassionally form fairly well organised armies. Since the advent of     \n";
    Screen[9]  = "  the Reidlos and The Order, the hordes have been even more split than usual.  \n";
    Screen[10] = "  In fighting is rife, but some hordes saw power and respectability in the     \n";
    Screen[11] = "  larger organisations. Although a fair number of hordes remain unaligned and  \n";
    Screen[12] = "  often cause problems for both factions.                                      \n\n";

    drawScreen(Screen, 32);

    system("PAUSE");
    EmptyScreen(Screen);
    system("CLS");
    return;
}

void DwarfInfo()
{
    Screen[0]  = "===============================================================================\n";
    Screen[1]  = "=============================INFORMATION=======================================\n";
    Screen[2]  = "============================RACES - DWARF======================================\n";
    Screen[3]  = "                                                                               \n";
    Screen[4]  = "  Unlike many of the races in Textopia, Dwarves are not filled with pride.     \n";
    Screen[5]  = "  A very scientific race, Dwarves have examined the stars and the world under  \n";
    Screen[6]  = "  the ground more than anyone else. Their ancestors are responsible for many   \n";
    Screen[7]  = "  of the caves and dungeons in Textopia. The Dwarves have pioneered ways in    \n";
    Screen[8]  = "  which magic can be used mechanically, giving them a very unique advantage.   \n";
    Screen[9]  = "  Despite having a slightly weaker grasp on magic than some other races the    \n";
    Screen[10] = "  Dwarves are able to focus and manipulate the essences of magic to great      \n";
    Screen[11] = "  effect. Although their short stature limits their agility, although they     \n";
    Screen[12] = "  still remain very desirable to both the Reidlos and The Order.               \n\n";

    drawScreen(Screen, 32);

    system("PAUSE");
    EmptyScreen(Screen);
    system("CLS");
    return;

}

void LupineInfo()
{
    Screen[0]  = "===============================================================================\n";
    Screen[1]  = "=============================INFORMATION=======================================\n";
    Screen[2]  = "============================RACES - LUPINE=====================================\n";
    Screen[3]  = "                                                                               \n";
    Screen[4]  = "  Some wild elves spend so long in the wilderness that they gain the ability   \n";
    Screen[5]  = "  to transform into animals. However, this ability has not been developed to a \n";
    Screen[6]  = "  point where it is stable, and many elves get stuck in a half way stage.      \n";
    Screen[7]  = "  This is in essence what a Lupine is, often thought to be a curse upon the    \n";
    Screen[8]  = "  elven race for taking a monopoly over the forests. However, the Lupine and   \n";
    Screen[9]  = "  elves have a good relationship most of the time. The Lupine are strong and   \n";
    Screen[10] = "  agile, but have lost much of the intelligence they once had as elves. Still  \n";
    Screen[11] = "  Lupine have gathered together over the years and formed tribes. A Lupine mage\n";
    Screen[12] = "  is a patricularly interesting case, as Lupine lack the intelligence that     \n";
    Screen[13] = "  makes the elves so talented with magic, but still have a certain natural     \n";
    Screen[14] = "  ability with magic, which allows them to cast very powerful spells, but much \n";
    Screen[15] = "  like the transformation that gave rise to their race, Lupine magic is        \n";
    Screen[16] = "  incredibly unstable. The Lupine tend to rely on their instincts, agility and \n";
    Screen[17] = "  sharp senses make the Lupine formidable rangers and hunters.                 \n\n";

    drawScreen(Screen, 32);

    system("PAUSE");
    EmptyScreen(Screen);
    system("CLS");
    return;
}

void AncientInfo()
{
    Screen[0]  = "===============================================================================\n";
    Screen[1]  = "=============================INFORMATION=======================================\n";
    Screen[2]  = "===========================RACES - ANCIENT=====================================\n";
    Screen[3]  = "                                                                               \n";
    Screen[4]  = "  The Ancients are shrouded in mystery, by far the proudest races in Textopia. \n";
    Screen[5]  = "  However, the Ancients are beginning to fade, despite their extreme magical   \n";
    Screen[6]  = "  ability, they are born naturally frail. So are more or less completely       \n";
    Screen[7]  = "  unable to fight in any other capacity than a mage. One Ancient's knowledge   \n";
    Screen[8]  = "  is passed onto its offspring, meaning Ancients have memories of the very     \n";
    Screen[9]  = "  beginning of time - a secret they guard very closely. Older Ancients have    \n";
    Screen[10] = "  detatched themselves from the struggles of what they see as the lesser races.\n";
    Screen[11] = "  Although the younger members of this species often try to integrate          \n";
    Screen[12] = "  themselves into elven culture, and are often valued for their ability to     \n";
    Screen[13] = "  to teach magic. It is thought that before too long the Ancients will become  \n";
    Screen[14] = "  assimilated into the Elven race. Although the prejudices of some Elven glades\n";
    Screen[15] = "  have created some strong tensions.                                           \n\n";

    drawScreen(Screen, 32);

    system("PAUSE");
    EmptyScreen(Screen);
    system("CLS");
    return;
}


void RaceInfo()
{
    int InfoChoice;
    int RaceInfoOn = 1;
    while(RaceInfoOn == 1)
    {
        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "================================RACES==========================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  Type the number of the section you want to read:                             \n";
        Screen[5]  = "                                                                               \n";
        Screen[6]  = "      1 - Human                                                                \n";
        Screen[7]  = "      2 - Elf                                                                  \n";
        Screen[8]  = "      3 - Orc                                                                  \n";
        Screen[9]  = "      4 - Dwarf                                                                \n";
        Screen[10] = "      5 - Lupine                                                               \n";
        Screen[11] = "      6 - Ancient                                                              \n";
        Screen[12] = "      7 - Back                                                                 \n";

        drawScreen(Screen, 32);

        cin >> InfoChoice;

        if(InfoChoice == 1)
        {
            HumanInfo();
        }
        else if(InfoChoice == 2)
        {
            ElfInfo();
        }
        else if(InfoChoice == 3)
        {
            OrcInfo();
        }
        else if(InfoChoice == 4)
        {
            DwarfInfo();
        }
        else if(InfoChoice == 5)
        {
            LupineInfo();
        }
        else if(InfoChoice == 6)
        {
            AncientInfo();
        }
        else if(InfoChoice == 7)
        {
            RaceInfoOn = 0;
            return;
        }
   }
}


void GetUpInfo()
{
    EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "==========================COMMANDS - GET UP====================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  Use the get up command to get out of your bed at the start of the game.      \n";
        Screen[5]  = "  This command can also be used in battle if a character is knocked down.      \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void PickUpInfo()
{
    EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "==========================COMMANDS - PICK UP===================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  Use the pick up command to pick up items in your current room. This is a two \n";
        Screen[5]  = "  part command. The first part being 'PICK UP', this will then give you a list \n";
        Screen[6]  = "  of all the items in the room! The full name must be typed in order to pick   \n";
        Screen[7]  = "  up that item. For example, simply typing armour will pick up neither plate   \n";
        Screen[8]  = "  or leather armour, in these cases you must type 'PLATE ARMOUR' or 'LEATHER   \n";
        Screen[9]  = "  ARMOUR'. Note that capitals are unnecessary in TextQuest 2, although if you  \n";
        Screen[10] = "  wish to put in capitals that's perfectly fine, as long as everything is      \n";
        Screen[11] = "  spelled correctly.                                                           \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void DirInfo()
{
    EmptyScreen(Screen);
        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "========================COMMANDS - DIRECTIONS==================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The directional commands are 'NORTH', 'SOUTH', 'EAST' and 'WEST'. Although   \n";
        Screen[5]  = "  the first letters can also be used. i.e. 'N', 'S', 'E' and 'W' respectively. \n";
        Screen[6]  = "  Movement is not a two part command so only the direction you wish to move    \n";
        Screen[7]  = "  is required.                                                                 \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void SkipInfo()
{
    EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "===========================COMMANDS - SKIP=====================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The skip command can be used to either skip past points where you are given  \n";
        Screen[5]  = "  the chance to check the information pages, but can also be used in battle to \n";
        Screen[6]  = "  skip your turn.                                                              \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void InfoInfo()
{

    EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "===========================COMMANDS - INFO=====================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The info command can be used at any point to bring up the information pages. \n";
        Screen[5]  = "  The commands 'HELP' and '?' can also be used.                                \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}




void EndInfo()
{
    EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "===========================COMMANDS - EXIT=====================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The exit command is used to end your current game. The commands 'END' and    \n";
        Screen[5]  = "  'QUIT' can also be used.                                                     \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void BattleInfo()
{
    EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "======================COMMANDS - BATTLE COMMANDS===============================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  ATTACK                                                                       \n";
        Screen[5]  = "  ======                                                                       \n";
        Screen[6]  = "  The attack command is used to perform a physical attack on your opponent in  \n";
        Screen[7]  = "  battle. You will have to choose a weapon to attack with from your inventory. \n";
        Screen[8]  = "  The abbreviation 'A' will also work, some weapons can be abbreviated when    \n";
        Screen[9]  = "  attacking.                                                                   \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "  DEFEND                                                                       \n";
        Screen[12] = "  ======                                                                       \n";
        Screen[13] = "  The defend command is used to block enemy attacks, it won't completely       \n";
        Screen[14] = "  enemy's attack but will significantly reduce the damage you take, depending  \n";
        Screen[15] = "  on your character's strength. Abbreviation is 'D'.                           \n";
        Screen[16] = "                                                                               \n";
        Screen[17] = "  CAST                                                                         \n";
        Screen[18] = "  ====                                                                         \n";
        Screen[19] = "  The cast command is used to cast a spell. You will have to enter a spell     \n";
        Screen[20] = "  that your character knows, this will deduct a certain amount of magical      \n";
        Screen[21] = "  from your character. For the heal spell you will target your party rather    \n";
        Screen[22] = "  the enemy. The Elven Aura spell target all characters in a party, so no      \n";
        Screen[23] = "  target input is required. Abbreviation is 'C'.                               \n";
        Screen[24] = "                                                                               \n";
        Screen[25] = "  USE                                                                          \n";
        Screen[26] = "  ===                                                                          \n";
        Screen[27] = "  The use command allows your character to drink either a health or            \n";
        Screen[28] = "  magic potion, if your character has any in his/her inventory. Abbreviation   \n";
        Screen[29] = "  is 'C'. Can be used out of battle.                                           \n";


        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void InvInfo()
{
    EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "======================COMMANDS - VIEW INVENTORY================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The View Inventory command is used to see what items your characters have    \n";
        Screen[5]  = "  with them. Abbreviations are 'VI' and 'INVENTORY'.                           \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void MapInfo()
{
    EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "=========================COMMANDS - VIEW MAP===================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The View Map command is used to see your map. The map us updated with each   \n";
        Screen[5]  = "  room you've visited. Abbreviations are 'MAP' and 'VM'.                       \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void StatsInfo()
{
    EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "========================COMMANDS - VIEW STATS==================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The View Stats command allows you to see relevant information about your     \n";
        Screen[5]  = "  characters, such as their current health and magic energy. Abbreviations are \n";
        Screen[6]  = "  'STATS' and 'VIEW STATS'.                                                    \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void ChallengeInfo()
{
    EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "=========================COMMANDS - CHALLENGE==================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The Challenge command can be used to challenge certain characters to a fight \n";
        Screen[5]  = "  if they don't automatically attack you.                                      \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void TalkInfo()
{
    EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "===========================COMMANDS - TALK=====================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The talk command can be used to engage in conversation with some of the      \n";
        Screen[5]  = "  characters in TextQuest II world. 'SPEAK' also works.                        \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void MoveInfo()
{
    EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "===========================COMMANDS - MOVE=====================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The move command allows you to move certain objects in the TextQuest world.  \n";
        Screen[5]  = "                                                                               \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void InvestigateInfo()
{
    EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "=======================COMMANDS - INVESTIGATE==================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The investigate command can be used to find useful information about the     \n";
        Screen[5]  = "  room you are currently in. 'EXAMINE' also works.                             \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void SaveInfo()
{
    EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "===========================COMMANDS - SAVE=====================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The save command can be used to save your progress for loading again later.  \n";
        Screen[5]  = "  If there are any issues with this command check that the save, worldsave,    \n";
        Screen[6]  = "  charactersave and mapsave .tqs files are in the same folder as the           \n";
        Screen[7]  = "  TextQuestII.exe file.                                                        \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void CommandInfo()
{
    int CommandInfoOn = 1;
    int InfoChoice;

    while(CommandInfoOn == 1)
    {
        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "==============================COMMANDS=========================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  Type the number of the section you want to read:                             \n";
        Screen[5]  = "                                                                               \n";
        Screen[6]  = "      1 - GET UP                                                               \n";
        Screen[7]  = "      2 - PICK UP                                                              \n";
        Screen[8]  = "      3 - INVESTIGATE                                                          \n";
        Screen[9]  = "      4 - Directions                                                           \n";
        Screen[10]  = "      5 - Battle Commands                                                      \n";
        Screen[11] = "      6 - VIEW INVENTORY                                                       \n";
        Screen[12] = "      7 - VIEW MAP                                                             \n";
        Screen[13] = "      8 - CHALLENGE                                                            \n";
        Screen[14] = "      9 - TALK                                                                 \n";
        Screen[15] = "      10 - MOVE                                                                \n";
        Screen[16]  = "      11 - SKIP                                                                \n";
        Screen[17] = "      12 - INFO                                                                \n";
        Screen[18] = "      13 - SAVE                                                                \n";
        Screen[19] = "      14 - EXIT                                                                \n";
        Screen[20] = "      15 - Back                                                                \n";

        drawScreen(Screen, 32);

        cin >> InfoChoice;

        if(InfoChoice == 1)
        {
            GetUpInfo();
        }
        else if(InfoChoice == 2)
        {
            PickUpInfo();
        }
        else if(InfoChoice == 3)
        {
            InvestigateInfo();
        }
        else if(InfoChoice == 4)
        {
            DirInfo();
        }
        else if(InfoChoice == 5)
        {
            BattleInfo();
        }
        else if(InfoChoice == 6)
        {
            InvInfo();
        }
        else if(InfoChoice == 7)
        {
            MapInfo();
        }
        else if(InfoChoice == 8)
        {
            ChallengeInfo();
        }
        else if(InfoChoice == 9)
        {
            TalkInfo();
        }
        else if(InfoChoice == 10)
        {
            MoveInfo();
        }
        else if(InfoChoice == 11)
        {
            SkipInfo();
        }
        else if(InfoChoice == 12)
        {
            InfoInfo();
        }
        else if(InfoChoice == 13)
        {
            SaveInfo();
        }
        else if(InfoChoice == 14)
        {
            EndInfo();
        }
        else if(InfoChoice == 15)
        {
            CommandInfoOn = 0;
            return;
        }
    }
}

void PlateInfo()
{
        EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "=========================ITEMS - PLATE ARMOUR================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  Plate Armour is a strong set of armour that will increase your defence       \n";
        Screen[5]  = "  as long as it is in the character's inventory.                               \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void LeatherInfo()
{
            EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "=======================ITEMS - LEATHER ARMOUR==================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  Leather Armour is a slightly weaker set of armour than the plate, it still   \n";
        Screen[5]  = "  increases defence while in the inventory though.                             \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}
void SwordInfo()
{
            EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "============================ITEMS - SWORD======================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  A simple weapon that provides a slight bonus in combat. More powerful when   \n";
        Screen[5]  = "  used by stronger characters.                                                 \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void BKBInfo()
{
            EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "=====================ITEMS - BLACK KNIGHT'S BLADE==============================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The Black Knight's Blade is a powerful sword, once wielded by a great        \n";
        Screen[5]  = "  adventurer. Through age the sword has developed a keen edge and is infused   \n";
        Screen[6]  = "  with a mysterious and dark power. Provides a considerable bonus when used    \n";
        Screen[7]  = "  in combat and is most useful when used by strong characters. Can be          \n";
        Screen[8]  = "  abbreviated to BKB.                                                          \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void BowInfo()
{
            EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "=============================ITEMS - BOW=======================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The bow is a simple ranged weapon that requires arrows to be used. It        \n";
        Screen[5]  = "  provides a slight advantage in combat. Most effective when used by agile     \n";
        Screen[6]  = "  characters.                                                                  \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void DSBInfo()
{
            EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "======================ITEMS - DRAGON STRIKE BOW================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The Dragon Strike Bow is a powerful bow crafter of Dragon Horn. It requires  \n";
        Screen[5]  = "  arrows to use and provides a considerable advantage in combat. Most          \n";
        Screen[6]  = "  effective when used by agile characters. Can be abbreviated to DSB.          \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void StaffInfo()
{
            EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "============================ITEMS - STAFF======================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The staff is a basic weapon that provides a small advantage in combat and a  \n";
        Screen[5]  = "  reasonable advanatge when casting spells. Most effective being used to cast  \n";
        Screen[6]  = "  spells by an intelligent character. Automatically used in spellcasting if    \n";
        Screen[7]  = "  there aren't any better staffs in the character's inventory.                 \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void SOAInfo()
{
            EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "====================ITEMS - STAFF OF THE ANCIENTS==============================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The Staff of the Ancients is the first ever magical staff that the Ancients  \n";
        Screen[5]  = "  crafted to focus their magical abilities. Provides a relative bonus in       \n";
        Screen[6]  = "  combat and a considerable bonus when casting spells. Automatically used when \n";
        Screen[7]  = "  in the character's inventory.                                                \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void PointedStickInfo()
{
            EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "========================ITEMS - POINTED STICK==================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The pointed stick is the standard issue weapon throughout Textopia. An       \n";
        Screen[5]  = "  apparently harmless weapon that has much more uses than its appearance would \n";
        Screen[6]  = "  suggest. Provides a small bonus in combat. Most effective when used by       \n";
        Screen[7]  = "  a strong character.                                                          \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void HealthPotionInfo()
{
            EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "========================ITEMS - HEALTH POTION==================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The health potion can be used in or out of battle to restore some health.    \n";
        Screen[5]  = "                                                                               \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void MagicPotionInfo()
{
            EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "=========================ITEMS - MAGIC POTION==================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The magic potion can be used to restore some magical energy either in or out \n";
        Screen[5]  = "  of battle.                                                                   \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void ItemInfo()
{
    int CommandInfoOn = 1;
    int InfoChoice;

    while(CommandInfoOn == 1)
    {
        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "================================ITEMS==========================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  Type the number of the section you want to read:                             \n";
        Screen[5]  = "                                                                               \n";
        Screen[6]  = "      1 - Plate Armour                                                         \n";
        Screen[7]  = "      2 - Leather Armour                                                       \n";
        Screen[8]  = "      3 - Sword                                                                \n";
        Screen[9]  = "      4 - Black Knight's Blade                                                 \n";
        Screen[10] = "      5 - Bow                                                                  \n";
        Screen[11] = "      6 - Dragon Strike Bow                                                    \n";
        Screen[12] = "      7 - Staff                                                                \n";
        Screen[13] = "      8 - Staff of the Ancients                                                \n";
        Screen[14] = "      9 - Pointed Stick                                                       \n";
        Screen[15] = "      10 - Health Potion                                                       \n";
        Screen[16] = "      11 - Magic Potion                                                        \n";
        Screen[17] = "      12 - Back                                                                \n";

        cin.sync();
        drawScreen(Screen, 32);

        cin >> InfoChoice;

        if(InfoChoice == 1)
        {
            PlateInfo();
        }
        else if(InfoChoice == 2)
        {
            LeatherInfo();
        }
        else if(InfoChoice == 3)
        {
            SwordInfo();
        }
        else if(InfoChoice == 4)
        {
            BKBInfo();
        }
        else if(InfoChoice == 5)
        {
            BowInfo();
        }
        else if(InfoChoice == 6)
        {
            DSBInfo();
        }
        else if(InfoChoice == 7)
        {
            StaffInfo();
        }
        else if(InfoChoice == 8)
        {
            SOAInfo();
        }
        else if(InfoChoice == 9)
        {
            PointedStickInfo();
        }
        else if(InfoChoice == 10)
        {
            HealthPotionInfo();
        }
        else if(InfoChoice == 11)
        {
            MagicPotionInfo();
        }
        else if(InfoChoice == 12)
        {
            CommandInfoOn = 0;
        }

    }

}

void FireballInfo()
{
                EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "==========================SPELLS - FIREBALL====================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  Fireball is a weak spell that does a small amount of damage.                 \n";
        Screen[5]  = "                                                                               \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void LightningBoltInfo()
{
                EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "=======================SPELLS - LIGHTNING BOLT================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  Lightning Bolt is a more powerful aggressive spell than fireball, but it     \n";
        Screen[5]  = "  costs more magical energy than fireball.                                     \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void HealInfo()
{
                EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "============================SPELLS - HEAL======================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  The heal spell restores the health of an injured party member.               \n";
        Screen[5]  = "                                                                               \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void ElvenAuraInfo()
{
                EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "=========================ITEMS - ELVEN AURA====================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  Elven Aura is a spell that can only be used by Elves and Lupine. It restores \n";
        Screen[5]  = "  the health of all party members.                                             \n";
        Screen[6]  = "                                                                               \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void AncientPowerInfo()
{
                EmptyScreen(Screen);

        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "========================ITEMS - ANCIENT POWER==================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  Ancient power is a spell that can only be cast by Ancients. It is an         \n";
        Screen[5]  = "  aggressive spell that is incredibly powerful, but costs a lot of magical     \n";
        Screen[6]  = "  energy.                                                                      \n";
        Screen[7]  = "                                                                               \n";
        Screen[8]  = "                                                                               \n";
        Screen[9]  = "                                                                               \n";
        Screen[10] = "                                                                               \n";
        Screen[11] = "                                                                               \n";
        Screen[12] = "                                                                               \n";

        drawScreen(Screen, 32);

        system("PAUSE");
        EmptyScreen(Screen);
        system("CLS");
        return;
}

void SpellInfo()
{
    int CommandInfoOn = 1;
    int InfoChoice;

    while(CommandInfoOn == 1)
    {
        Screen[0]  = "===============================================================================\n";
        Screen[1]  = "=============================INFORMATION=======================================\n";
        Screen[2]  = "===============================SPELLS==========================================\n";
        Screen[3]  = "                                                                               \n";
        Screen[4]  = "  Type the number of the section you want to read:                             \n";
        Screen[5]  = "                                                                               \n";
        Screen[6]  = "      1 - Fireball                                                             \n";
        Screen[7]  = "      2 - Lightning Bolt                                                       \n";
        Screen[8]  = "      3 - Heal                                                                 \n";
        Screen[9]  = "      4 - Elven Aura                                                           \n";
        Screen[10] = "      5 - Ancient Power                                                        \n";
        Screen[11] = "      6 - Back                                                                 \n";

        cin.sync();
        drawScreen(Screen, 32);

        cin >> InfoChoice;

        if(InfoChoice == 1)
        {
            FireballInfo();
        }
        else if(InfoChoice == 2)
        {
            LightningBoltInfo();
        }
        else if(InfoChoice == 3)
        {
            HealInfo();
        }
        else if(InfoChoice == 4)
        {
            ElvenAuraInfo();
        }
        else if(InfoChoice == 5)
        {
            AncientPowerInfo();
        }
        else if(InfoChoice == 6)
        {
            CommandInfoOn = 0;
        }
    }
    return;
}

void info()
{
    int InfoOn = 1;
    int choice;

    while(InfoOn == 1)
    {

        string InfoScreen[]  =
        {
            "===============================================================================\n",
            "=============================INFORMATION=======================================\n",
            "==v2.0.0=======================================================================\n",
            "                                                                               \n",
            "  Type the number of the section you want to read:                             \n",
            "                                                                               \n",
            "      1 - History                                                              \n",
            "      2 - Races                                                                \n",
            "      3 - Commands                                                             \n",
            "      4 - Items                                                                \n",
            "      5 - Spells                                                               \n",
            "      6 - Back                                                                 \n",
            "                                                                               \n",
            "  Game designed and created by Joshua Haxell                                   \n",
            "                                                                               \n"
        };

        drawScreen(InfoScreen, 14);

        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                string HistoryScreen[] =
                {
                    "===============================================================================\n",
                    "=============================INFORMATION=======================================\n",
                    "===============================HISTORY=========================================\n",
                    "                                                                               \n",
                    "    TextQuest II takes place 200 years or so after the first TextQuest game,   \n",
                    " those events have however been long forgotten. The world has been war torn    \n",
                    " for the last century, and adventurers no longer wander the rolling plains,    \n",
                    " mysterious forests and ancient caves of Textopia. Two great warring kingdoms  \n",
                    " have emerged over the years out of countless villages and tribes. The dark    \n",
                    " and mysterious Reidlos forever trying to strengthen their clutch on the land. \n",
                    " Lead by the ruthless and militaristic Tresk, the Reidlos desire nothing less  \n",
                    " than total domination. Countered by Oryx an Ancient knight who gained the     \n",
                    " respect from the many tribal chiefs and old adventures than called Textopia   \n",
                    " home. Oryx's original small band of knights gradually grew to be the powerful \n",
                    " army it is today, known only as 'The Order', there goals and motives remain   \n",
                    " shrouded in mystery. Then there are the few villages and smaller tribes that  \n",
                    " have clung on to their independance, though these are often assimilated into  \n",
                    " either The Order or the endless ranks of the Reidlos before too long...       \n",
                    "                                                                               \n",
                    "    Legends tell of an ancient weapon that could sway the tide of the war for  \n",
                    " whoever can find it first. It is said this weapon lies in an old cave that    \n",
                    " was once home to a clan of adventurers, but the knowledge of the old          \n",
                    " secrets of the adventures were closely guarded and the location of this home  \n",
                    " han't been known for a hundred years!                                         \n",
                    "                                                                               \n",
                    "    TextQuest II opens as a soldier in The Order is sent on a long campaign    \n",
                    " against the Reidlos, a campaign that will take the soldier far from their     \n",
                    " home at The Order's stronghold Oryldeburg. And a campaign that will decide the\n",
                    " fate of Textopia for centuries to come!                                       \n",
                    "                                                                               \n"
                };

                drawScreen(HistoryScreen, 30);

                system("PAUSE");
                system("CLS");

            break;
            }

            case 2:
                RaceInfo();
            break;

            case 3:
                CommandInfo();
            break;

            case 4:
                ItemInfo();
            break;

            case 5:
                SpellInfo();
            break;

            case 6:
                InfoOn = 0;
            break;

            default:
                InfoScreen[12] = " * * * Please enter a valid option!                                      * * * \n";
                drawScreen(InfoScreen, 13);

                system("PAUSE");
            break;
        }
    }
    return;
}
