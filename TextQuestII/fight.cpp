#include<iostream>
#include<time.h>
#include<cstdlib>

using namespace std;
#include"Info.h"
#include"screens.h"
#include"Input.h"
#include"BattleCommands.h"
#include"AI.h"

string GetEnemyName(int Enemy[3][8], int target)
{
    string EnemyName[] =
    {
        " ",
        "Dummy",
        "Goblin",
        "Troll",
        "Skeleton",
        "Warlock",
        "Ogre",
        "Dragon",
        "Hellhound",
        "Pirate"
    };

    string CEnemyName;

    if(Enemy[(target - 1)][5] == 1)
    {
        CEnemyName = EnemyName[1];
    }
    else if(Enemy[(target - 1)][5] == 2)
    {
        CEnemyName = EnemyName[2];
    }
    else if(Enemy[(target - 1)][5] == 3)
    {
        CEnemyName = EnemyName[3];
    }
    else if(Enemy[(target - 1)][5] == 4)
    {
        CEnemyName = EnemyName[4];
    }
    else if(Enemy[(target - 1)][5] == 5)
    {
        CEnemyName = EnemyName[5];
    }
    else if(Enemy[(target - 1)][5] == 6)
    {
        CEnemyName = EnemyName[6];
    }
    else if(Enemy[(target - 1)][5] == 7)
    {
        CEnemyName = EnemyName[7];
    }
    else if(Enemy[(target - 1)][5] == 8)
    {
        CEnemyName = EnemyName[8];
    }
    else if(Enemy[(target - 1)][5] == 9)
    {
        CEnemyName = EnemyName[9];
    }
    else
    {
        CEnemyName = EnemyName[0];
    }

    return CEnemyName;
}

void TakeDamage(bool player, int damage, int target, int CharacterStats[3][7], int CharacterInventory[3][14], int Enemy[3][8], int block[6])
{
    int defence = 10;
    int i;

    if(player == true)
    {
        if(Enemy[(target-1)][5] == 1)
        {
            defence -= 5;
        }
        else if(Enemy[(target-1)][5] == 2)
        {
            defence -= 2;
        }
        else if(Enemy[(target-1)][5] == 3)
        {
           defence += 2;
        }
        else if(Enemy[(target-1)][5] == 4)
        {
            defence += 3;
        }
        else if(Enemy[(target-1)][5] == 5)
        {
            defence = 10;
        }
        else if(Enemy[(target-1)][5] == 6)
        {
            defence += 5;
        }
        else if(Enemy[(target-1)][5] == 7)
        {
            defence += 15;
        }
        else if(Enemy[(target-1)][5] == 8)
        {
            defence += 2;
        }
        else if(Enemy[(target-1)][5] == 9)
        {
            if(Enemy[(target-1)][6] == 150)
            {
                defence += 6;
            }
            else
            {
                defence += 2;
            }
        }
        if(block[target+2] != 0)
        {
            defence = defence*block[target+2];

            block[target+2] = 0;
        }
        Enemy[(target-1)][0] -= damage/defence;
    }
    else if(player == false)
    {
        if(CharacterInventory[(target-1)][0] != 0)
        {
            defence += 6;
        }
        else if(CharacterInventory[(target-1)][1] != 0)
        {
            defence += 2;
        }

        if(block[target - 1] != 0)
        {
            defence = defence*block[target - 1];

            block[target-1] = 0;
        }

        CharacterStats[(target-1)][0] -= damage/defence;
    }

    for(i = 0; i < 3; i++)
    {
        if(Enemy[i][0] < 0)
        {
            Enemy[i][0] = 0;
        }
        if(CharacterStats[i][0] < 0)
        {
            CharacterStats[i][0] = 0;
        }
    }

    return;
}


void RestoreHealth(int target, int restore, int CharacterStats[3][7], int Enemy[3][8], bool player)
{
    int i;

    if(player == true)
    {
        if(target == 4)
        {
            for(i = 0; i <= 2; i ++)
            {
                if(CharacterStats[i][0] != 0)
                {
                    CharacterStats[i][0] += restore;
                }
            }
        }
        else
        {
            CharacterStats[(target-1)][0] += restore;
        }

        for(i = 0; i < 3; i ++)
        {
            if(CharacterStats[i][0] > CharacterStats[i][5])
            {
                CharacterStats[i][0] = CharacterStats[i][5];
            }
        }
    }
    else if(player == false)
    {
        Enemy[target][0] += restore;

        if(Enemy[target][0] > Enemy[target][6])
        {
            Enemy[target][0] = Enemy[target][6];
        }
    }
}

void RestoreMagic(int nCC, int CharacterStats[3][7])
{
    CharacterStats[nCC][1] += 25;

    if(CharacterStats[nCC][1] >= CharacterStats[nCC][6])
    {
        CharacterStats[nCC][1] = CharacterStats[nCC][6];
    }

    if(CharacterStats[nCC][1] == 0)
    {
        cout << endl << "Potion was ineffective!\n\n";
    }
    else
    {
        cout << endl << "Magic restored!\n\n";
    }
}

int Fight(int CharacterStats[3][7], int CharacterInventory[3][14], string CharacterInfo[3][3], int Enemy[3][8], int Tutorial)
{
    string Name;
    string NameB;
    string Gender;

    int Turn = 0;
    bool Loop;
    bool MasterLoop;
    bool SkipTurn = false;
    int command;
    int Result;
    int damage;
    int target;
    int potion;
    int restore;
    int SpellType;
    int block[] = {0, 0, 0, 0, 0, 0};

    bool player;
    bool SpellKnown = false;

    int nCC;
    int nCE;
    int NCE;
    int nPassC;

    int i;

    fightScreen(CharacterInfo, CharacterStats, Enemy, Turn);

    system("PAUSE");

    if(Tutorial == 1)
    {
        fightScreen(CharacterInfo, CharacterStats, Enemy, 0);

        cout << " * * * Welcome to the battle screen. You will see your characters on     * * * \n";
        cout << " * * * your left, and the enemy on your right. The left number on both   * * * \n";
        cout << " * * * sides is the health of that character, and the number on the      * * * \n";
        cout << " * * * right is that character's magical energy.                         * * * \n\n";

        system("PAUSE");

        system("CLS");

        fightScreen(CharacterInfo, CharacterStats, Enemy, 1);

        cout << " * * * During a battle you'll see arrows to the side of a character's    * * * \n";
        cout << " * * * name, this means it is that character's turn to fight.            * * * \n\n";

        system("PAUSE");

        system("CLS");

        fightScreen(CharacterInfo, CharacterStats, Enemy, 0);

        cout << " * * * A battle is over when all characters on either side are dead!     * * * \n\n";

        system("PAUSE");

        system("CLS");

        fightScreen(CharacterInfo, CharacterStats, Enemy, 0);

        cout << " * * * You have 4 commands you can use in battle, Attack, Defend, Cast   * * * \n";
        cout << " * * * and Use for more information type 'INFO', otherwise, continue     * * * \n";
        cout << " * * * onto your first battle by typing 'SKIP'.                          * * * \n\n";

        Loop = true;
        while(Loop == true)
        {
            command = Input();
            if(command == 6)
            {
                Loop = false;
            }
            else if(command == 13)
            {
                info();
            }
            else
            {
                cout << "Invalid command!" << endl;
                cout << "Please enter again!" << endl;
                system("PAUSE");
            }
        }
        Tutorial = 0;
    }


    for(Turn = 1; Turn != 0; Turn ++)
    {

        fightScreen(CharacterInfo, CharacterStats, Enemy, Turn);

        if(CharacterStats[0][0] == 0 && CharacterStats[1][0] == 0 && CharacterStats[2][0] == 0)
        {
            cout << "You have been defeated!\n\n";

            system("PAUSE");
            Turn = 0;
            Result = 0;
        }
        if(Enemy[0][0] == 0 && Enemy[1][0] == 0 && Enemy[2][0] == 0)
        {
            cout << "Congratulations! You are victorious!\n\n";
/*
            for(i = 0; i < 3; i ++)
            {
                if(CharacterStats[i][0] != 0)
                {
                    CharacterStats[i][0] = CharacterStats[i][5];
                }
                else if(CharacterStats[i][6] != 0)
                {
                    CharacterStats[i][1] = CharacterStats[i][6];
                }
            }
*/
            for(i = 0; i < 6; i ++)
            {
                block[i] = 0;
            }

            system("PAUSE");

            Turn = 0;

            Result = 1;
        }

        if(Turn == 0)
        {
            break;
        }

        if(Turn == 1 && CharacterStats[0][0] != 0)
        {
            nCC = 0;
            player = true;
            SkipTurn = false;

            if(CharacterStats[0][1] < CharacterStats[0][6])
            {
               CharacterStats[0][1] += 10;

               if(CharacterStats[0][1] > CharacterStats[0][6])
               {
                   CharacterStats[0][1] = CharacterStats[0][6];
               }
            }
        }
        else if(Turn == 2 && Enemy[0][0] != 0)
        {
            nCE = 0;
            player = false;
            SkipTurn = false;

            Enemy[0][1] += 10;
            if(Enemy[0][1] > Enemy[0][7])
            {
                Enemy[0][1] = Enemy[0][7];
            }


        }
        else if(Turn == 3 && CharacterStats[1][0] != 0)
        {
            nCC = 1;
            player = true;
            SkipTurn = false;

            if(CharacterStats[1][1] < CharacterStats[1][6])
            {
               CharacterStats[1][1] += 10;

               if(CharacterStats[1][1] > CharacterStats[1][6])
               {
                   CharacterStats[1][1] = CharacterStats[1][6];
               }
            }

        }
        else if(Turn == 4 && Enemy[1][0] != 0)
        {
            nCE = 1;
            player = false;
            SkipTurn = false;

            Enemy[1][1] += 10;
            if(Enemy[1][1] > Enemy[1][7])
            {
                Enemy[1][1] = Enemy[1][7];
            }
        }
        else if(Turn == 5 && CharacterStats[2][0] != 0)
        {
            nCC = 2;
            player = true;
            SkipTurn = false;

            if(CharacterStats[2][1] < CharacterStats[2][6])
            {
               CharacterStats[2][1] += 10;

               if(CharacterStats[2][1] > CharacterStats[2][6])
               {
                   CharacterStats[2][1] = CharacterStats[2][6];
               }
            }
        }
        else if(Turn == 6 && Enemy[2][0] != 0)
        {
            nCE = 2;
            player = false;
            SkipTurn = false;

            Enemy[2][1] += 10;
            if(Enemy[2][1] > Enemy[2][7])
            {
                Enemy[2][1] = Enemy[2][7];
            }

        }
        else
        {
            SkipTurn = true;
        }

        if(SkipTurn == false)
        {

        MasterLoop = true;
        while(MasterLoop == true)
        {

            if(player == true)
            {
                nPassC = nCC;

                cout << "\nEnter command: ";
                command = Input();

            }
            else if(player == false)
            {
                nPassC = nCE;
                command = AI(Enemy, nPassC);
            }


            if(command == 7)
            {
                damage = Attack(player, nPassC, CharacterStats, CharacterInventory, Enemy);

                if(damage != -1)
                {
                    if(player == true)
                    {
                        target = InputTarget(Enemy);
                        Name = GetEnemyName(Enemy, target);
                        cout << endl << CharacterInfo[nCC][0] << " attacks " << Name << "!\n\n";
                        system("PAUSE");

                    }
                    else if(player == false)
                    {
                        NCE = nCE +1;
                        target = GetTarget(nCE, Enemy, CharacterStats);
                        Name = GetEnemyName(Enemy, NCE);

                        cout << endl << Name << " attacks " << CharacterInfo[target-1][0] << "!\n\n";
                        system("PAUSE");

                    }
                    TakeDamage(player, damage, target, CharacterStats, CharacterInventory, Enemy, block);

                    MasterLoop = false;
                }

            }
            else if(command == 10)
            {
                if(player == true)
                {
                    Loop = true;
                    while(Loop == true)
                    {
                        SpellKnown = false;
                        SpellType = InputSpell(nCC, CharacterInfo);

                        if(SpellType == 5)
                        {
                            Loop = false;
                            SpellKnown = true;
                        }
                        if(nCC == 2)
                        {
                            if(SpellType == 0)
                            {
                                SpellKnown = true;
                                if(CharacterStats[nCC][1] >= 10)
                                {
                                    Loop = false;
                                    CharacterStats[nCC][1] -= 10;
                                }
                                else
                                {
                                    cout << "Not enough magic to cast this spell!\n";
                                    SpellType = 5;
                                }
                            }
                            else if(SpellType == 1)
                            {
                                SpellKnown = true;
                                if(CharacterStats[nCC][1] >= 20)
                                {
                                    Loop = false;
                                    CharacterStats[nCC][1] -= 20;
                                }
                                else
                                {
                                    cout << "Not enough magic to cast this spell!\n";
                                    SpellType = 5;
                                }
                            }
                            else if(SpellType == 2)
                            {
                                SpellKnown = true;
                                if(CharacterStats[nCC][1] >= 20)
                                {
                                    Loop = false;
                                    CharacterStats[nCC][1] -= 20;
                                }
                                else
                                {
                                    cout << "Not enough magic to cast this spell!\n";
                                    SpellType = 5;
                                }
                            }
                        }
                        if(CharacterInfo[nCC][2] == "Elf" || CharacterInfo [nCC][2] == "Lupine")
                        {
                            if(SpellType == 4)
                            {
                                SpellKnown = true;
                                if(CharacterStats[nCC][1] >= 30)
                                {
                                    Loop = false;
                                    CharacterStats[nCC][1] -= 30;
                                }
                                else
                                {
                                    cout << "Not enough magic to cast this spell!\n";
                                    SpellType = 5;
                                }
                            }
                        }
                        if(CharacterInfo[nCC][2] == "Ancient")
                        {
                            if(SpellType == 3)
                            {
                                SpellKnown = true;
                                if(CharacterStats[nCC][1] >= 60)
                                {
                                    Loop = false;
                                    CharacterStats[nCC][1] -= 60;
                                }
                                else
                                {
                                    cout << "Not enough magic to cast this spell!\n";
                                    SpellType = 5;
                                }
                            }
                        }
                        if(nCC != 2 && CharacterInfo[nCC][2] == "Dwarf")
                        {
                            if(SpellType == 1 || SpellType == 2)
                            {
                                SpellKnown = true;
                                if(CharacterStats[nCC][1] >= 20)
                                {
                                    Loop = false;
                                    CharacterStats[nCC][1] -= 20;
                                }
                                else
                                {
                                    cout << "Not enough magic to cast this spell!\n";
                                    SpellType = 5;
                                }
                            }
                        }


                        if(SpellKnown == false)
                        {
                            cout << "You do not know this spell!\n\n";
                            system("PAUSE");
                        }

                    }



                    if(SpellType == 2)
                    {
                        target = HealTarget(SpellType, CharacterStats);
                        restore = CastHeal(nCC, SpellType, CharacterStats, CharacterInventory, Enemy, player);

                        cout << endl << CharacterInfo[nCC][0] << " casts a spell on " << CharacterInfo[(target-1)][0] << "!\n\n";

                        RestoreHealth(target, restore, CharacterStats, Enemy, player);

                        system("PAUSE");

                        MasterLoop = false;
                    }
                    else if(SpellType == 4)
                    {
                        if(CharacterInfo[nCC][1] == "Male")
                        {
                            Gender = "his";
                        }
                        else if(CharacterInfo[nCC][1] == "Female")
                        {
                            Gender = "her";
                        }
                        target = HealTarget(SpellType, CharacterStats);
                        restore = CastHeal(nCC, SpellType, CharacterStats, CharacterInventory, Enemy, player);

                        cout << endl << CharacterInfo[nCC][0] << " casts a spell on " << Gender << " team.\n\n";

                        RestoreHealth(target, restore, CharacterStats, Enemy, player);

                        system("PAUSE");

                        MasterLoop = false;
                    }
                    else if(SpellType != 5)
                    {
                        target = InputTarget(Enemy);

                        damage = CastAttack(player, SpellType, nPassC, CharacterStats, CharacterInventory, Enemy);

                        Name = GetEnemyName(Enemy, target);

                        cout << endl << CharacterInfo[nCC][0] << " casts a spell on " << Name << "!\n\n";

                        TakeDamage(player, damage, target, CharacterStats, CharacterInventory, Enemy, block);

                        system("PAUSE");

                        MasterLoop = false;
                    }

                }
                else if(player == false)
                {
                    SpellType = GetSpell(nCE, Enemy);

                    if(SpellType == 0)
                    {
                        Enemy[nCE][1] -= 10;
                    }
                    else if(SpellType == 1)
                    {
                        Enemy[nCE][1] -= 20;
                    }
                    else if(SpellType == 2)
                    {
                        Enemy[nCE][1] -= 20;
                    }

                    if(SpellType == 0 || SpellType == 1)
                    {
                        target = GetTarget(nCE, Enemy, CharacterStats);
                        damage = CastAttack(player, SpellType, nCE, CharacterStats, CharacterInventory, Enemy);

                        NCE = nCE + 1;
                        Name = GetEnemyName(Enemy, NCE);

                        cout << endl << Name << " casts a spell on " << CharacterInfo[target-1][0] << "!\n\n";
                        system("PAUSE");

                        TakeDamage(player, damage, target, CharacterStats, CharacterInventory, Enemy, block);
                    }
                    else
                    {
                        target = GetHealTarget(nCE, Enemy);
                        restore = CastHeal(nCE, SpellType, CharacterStats, CharacterInventory, Enemy, player);

                        NCE = nCE + 1;
                        Name = GetEnemyName(Enemy, NCE);
                        NameB = GetEnemyName(Enemy, (target+1));

                        cout << endl << Name << " casts a spell on " << NameB << "!\n\n";
                        system("PAUSE");

                        RestoreHealth(target, restore, CharacterStats, Enemy, player);
                    }

                    MasterLoop = false;
                }


            }
            else if(command == 11)
            {
                if(CharacterInventory[nCC][11] != 0 || CharacterInventory[nCC][12] != 0)
                {
                    potion = Use(nCC, CharacterInventory);
                }
                else
                {
                    cout << "You don't have any potions!\n\n";
                    system("PAUSE");
                }

                if(potion != -1)
                {
                    if(potion == 1)
                    {
                        cout << CharacterInfo[nCC][0] << " uses a health potion!\n\n";

                        RestoreHealth((nCC + 1), 25, CharacterStats, Enemy, true);
                        MasterLoop = false;
                        system("PAUSE");
                    }
                    else if(potion == 2)
                    {
                        cout << CharacterInfo[nCC][0] << " uses a magic potion!\n\n";

                        RestoreMagic(nCC, CharacterStats);
                        MasterLoop = false;

                        system("PAUSE");
                    }


                }


            }
            else if(command == 17)
            {
                MasterLoop = false;
                if(player == true)
                {
                    block[nCC] = Defend(player, nCC, CharacterStats, Enemy);

                    Name = CharacterInfo[nCC][0];
                }
                else if(player == false)
                {
                    NCE = nCE + 3;
                    block[NCE] = Defend(player, nCE, CharacterStats, Enemy);

                    NCE = nCE + 1;

                    Name = GetEnemyName(Enemy, NCE);
                }

                cout << endl << Name << " adopts a defensive stance!\n\n";

                system("PAUSE");
            }
            else if(command == 6)
            {
                MasterLoop = false;
                if(player == true)
                {
                    Name = CharacterInfo[nCC][0];
                }
                else if(player == false)
                {
                    NCE = nCE + 1;
                    Name = GetEnemyName(Enemy, NCE);
                }

                cout << endl << Name << " does nothing!\n\n";

                system("PAUSE");

            }
            else
            {
                cout << "This is not a valid command!";
            }
        }
        fightScreen(CharacterInfo, CharacterStats, Enemy, Turn);
        }
        if(Turn == 6)
        {
            Turn = 0;
        }
    }
    return Result;
}
