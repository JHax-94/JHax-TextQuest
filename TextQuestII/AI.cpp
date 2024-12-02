using namespace std;

#include"dice.h"

int GetTarget(int nCC, int Enemy[3][8], int CharacterStats[3][7])
{
    int target;
    bool Loop = true;
    int roll;

    if(Enemy[nCC][5] == 2 || Enemy[nCC][5] == 3 || Enemy[nCC][5] == 6 || Enemy[nCC][5] == 5 || Enemy[nCC][5] == 9)
    {
        while(Loop == true)
        {
            target = RollDice(5);

            if(CharacterStats[target-1][0] != 0)
            {
                Loop = false;
            }
        }
    }
    else if(Enemy[nCC][5] == 4 || Enemy[nCC][5] == 7)
    {
        int Target[3];
/*        if(CharacterStats[0][0] != 0 && CharacterStats[1][0] != 0 && CharacterStats[2][0] != 0)
        {
            Loop = true;
            while(Loop == true)
            {
                target = RollDice(5);

                if(target == 3)
                {
                    if(CharacterStats[target-1][0] >= CharacterStats[0][0])
                    {
                        target = 1;
                    }
                    else
                    {
                        target = 3;
                    }
                }

                if(CharacterStats[target-1][0] >= CharacterStats[target][0])
                {
                    target = target + 1;
                }
                if(CharacterStats[target-1][0] != 0)
                {
                        Loop = false;
                }
            }
        }*/
        Loop = true;
        while(Loop == true)
        {
            Target[0] = CharacterStats[0][0];
            Target[1] = CharacterStats[1][0];
            Target[2] = CharacterStats[2][0];

            target = 0;

            if(Target[0] < Target[1])
            {
                target = 1;
            }
            if(Target[target] < Target[2])
            {
                target = 2;
            }

            target ++;

            roll = RollDice(16);

            if(Enemy[nCC][5] == 4)
            {
                if(roll >= 7)
                {
                    target = RollDice(5);
                }
            }
            else if(Enemy[nCC][5] == 7)
            {
                if(roll == 10)
                {
                    target = RollDice(5);
                }
            }
            if(CharacterStats[(target-1)][0] != 0)
            {
                Loop = false;
            }


        }
    }
    else if(Enemy[nCC][5] == 8)
    {
        int i;
        int j;

        i = 0;
        j = 1;

        if((CharacterStats[i][0] > CharacterStats[j][0]) && (CharacterStats[j][0] != 0))
        {
            i = j;
        }

        j = 2;

        if((CharacterStats[i][0] > CharacterStats[j][0]) && (CharacterStats[j][0] != 0))
        {
            i = j;
        }

        target = i + 1;


    }
    return target;
}

int GetHealTarget(int nCC, int Enemy[3][8])
{
    int target = 0;

    if(Enemy[0][0] == 0)
    {
        target = 1;
    }
    if(Enemy[1][0] == 0)
    {
        target = 2;
    }
    if(Enemy[2][0] == 0)
    {
        target = 0;
    }

    if(Enemy[target][0] >= Enemy[1][0] && Enemy[1][0] != 0)
    {
        target = 1;
    }

    if(Enemy[target][0] >= Enemy[2][0] && Enemy[2][0] != 0)
    {
        target = 2;
    }


    if(Enemy[nCC][5] == 7)
    {
        target = nCC;
    }

    return target;
}

int DummyAI()
{
    int command;
        command = 6;
    return command;
}

int GoblinAI(int nCE, int Enemy[3][8])
{
    int command;

    int Ally1;
    int Ally2;

    int Die;

    if(nCE == 0)
    {
        Ally1 = 1;
        Ally2 = 2;
    }
    else if(nCE == 1)
    {
        Ally1 = 0;
        Ally2 = 2;
    }
    else if(nCE == 2)
    {
        Ally1 = 0;
        Ally2 = 1;
    }

    if(Enemy[Ally1][0] != 0 && Enemy[Ally2][0] != 0)
    {
        if(Enemy[nCE][0] > 20)
        {
            command = 7;
        }
        else if(Enemy[nCE][0] <= 20)
        {
            Die = RollDice(13);

            if(Die >= 80)
            {
                command = 7;
            }
            else
            {
                command = 17;
            }
        }
    }
    else if(Enemy[Ally1][0] != 0 || Enemy[Ally2][0] != 0)
    {
        if(Enemy[nCE][0] > 20)
        {
            command = 7;
        }
        else if(Enemy[nCE][0] <= 20)
        {
            Die = RollDice(13);

            if(Die >= 50)
            {
                command = 7;
            }
            else
            {
                command = 17;
            }
        }
    }
    else
    {
        command = 7;
    }

    return command;
}

int TrollAI(int nCE, int Enemy[3][8])
{
    int command;
    int die;

    die = RollDice(13);

    if(die < 30)
    {
        command = 6;
    }
    else if(die >= 30)
    {
        command = 7;
    }

    return command;
}

int SkeletonAI(int nCE, int Enemy[3][8])
{
    int command;
    command = 7;

    return command;
}

int WarlockAI(int nCE, int Enemy[3][8])
{
    int command;

    if(Enemy[nCE][1] > 10)
    {
        command = 10;
    }
    else
    {
        command = 7;
    }

    return command;
}

int OgreAI(int nCE, int Enemy[3][8])
{
    int command;
    int dice;

    dice = RollDice(10);

    if(dice == 1)
    {
        command = 7;
    }
    else
    {
        command = 6;
    }

    return command;

}

int DragonAI(int nCE, int Enemy[3][8])
{
    int command;
    int dice;

    dice = RollDice(16);

    if(Enemy[nCE][0] >= 50)
    {
        if(dice == 1)
        {
            command = 10;

            if(Enemy[nCE][1] <= 20)
            {
                command = 7;
            }
        }
        else
        {
            command = 7;
        }
    }
    else
    {
        if(dice <= 4)
        {
            command = 10;

            if(Enemy[nCE][1] <= 20)
            {
                command = 7;
            }
        }
        else
        {
            command = 7;
        }
    }

    return command;
}

int HellHoundAI(int nCE, int Enemy[3][8])
{
    int command;
    int dice;

    if(Enemy[nCE][0] > 5 && Enemy[nCE][0] < 50)
    {
        dice = RollDice(0);

        if(dice == 1)
        {
            command = 7;
        }
        else
        {
            command = 17;
        }
    }
    else
    {
        command = 7;
    }

    return command;
}

int PirateAI(int nCE, int Enemy[3][8])
{
    int command;
    int dice;

    if(Enemy[nCE][1] > 10)
    {
        dice = RollDice(10);

        if(dice == 1)
        {
            command = 10;
        }
        else
        {
            command = 7;
        }
    }
    else
    {
        command = 7;
    }

    return command;
}

int GetWeapon(int nCE, int Enemy[3][8])
{
    int weapon;

    if(Enemy[nCE][5] == 2)
    {
        if(Enemy[nCE][3] <= 45)
        {
            weapon = 3;
        }
        else
        {
            weapon = 1;
        }
    }
    else if(Enemy[nCE][5] == 3)
    {
        weapon = 3;
    }
    else if(Enemy[nCE][5] == 4)
    {
        weapon = 2;
    }
    else if(Enemy[nCE][5] == 5)
    {
        weapon = 8;
    }
    else if(Enemy[nCE][5] == 6)
    {
        weapon = 5;
    }
    else if(Enemy[nCE][5] == 7)
    {
        weapon = 19;
    }
    else if(Enemy[nCE][5] == 8)
    {
        if(Enemy[nCE][0] > 100)
        {
            weapon = 7;
        }
        else if(Enemy[nCE][0] <= 100)
        {
            weapon = 6;
        }
        else if(Enemy[nCE][0] <= 50)
        {
            weapon = 2;
        }
        else if(Enemy[nCE][0] <= 5)
        {
            weapon = 13;
        }
    }
    else if(Enemy[nCE][5] == 9)
    {
        weapon = 1;
    }

    return weapon;
}

int GetSpell(int nCE, int Enemy[3][8])
{
    int nSpell;
    int dice;

    if(Enemy[nCE][5] == 7)
    {
        if(Enemy[nCE][0] < 50)
        {
            nSpell = 2;
        }
        else
        {
            dice = RollDice(0);

            if(dice == 1)
            {
                nSpell = 0;
            }
            else
            {
                nSpell = 2;
            }
        }
    }
    else
    {
        if(Enemy[nCE][1] > 20)
        {
            dice = RollDice(13);

            if((Enemy[0][0] >= (Enemy[0][6] - 20)) && (Enemy[1][0] >= (Enemy[1][6] - 20)) && (Enemy[2][0] >= (Enemy[2][6] = 20)))
            {
                if(dice >= 51)
                {
                    nSpell = 0;
                }
                else
                {
                    nSpell = 1;
                }
            }
            else
            {
                if(dice >= 26 && dice <= 60)
                {
                    nSpell = 0;
                }
                else if(dice >= 61)
                {
                    nSpell = 1;
                }
                else if(dice <= 25)
                {
                    nSpell = 2;
                }
            }
        }
        else
        {
            nSpell = 0;
        }
    }


    return nSpell;
}

int AI(int Enemy[3][8], int nCE)
{
    int command;

    if(Enemy[nCE][5] == 1)
    {
        command = DummyAI();
    }
    else if(Enemy[nCE][5] == 2)
    {
        command = GoblinAI(nCE, Enemy);
    }
    else if(Enemy[nCE][5] == 3)
    {
        command = TrollAI(nCE, Enemy);
    }
    else if(Enemy[nCE][5] == 4)
    {
        command = SkeletonAI(nCE, Enemy);
    }
    else if(Enemy[nCE][5] == 5)
    {
        command = WarlockAI(nCE, Enemy);
    }
    else if(Enemy[nCE][5] == 6)
    {
        command = OgreAI(nCE, Enemy);
    }
    else if(Enemy[nCE][5] == 7)
    {
        command = DragonAI(nCE, Enemy);
    }
    else if(Enemy[nCE][5] == 8)
    {
        command = HellHoundAI(nCE, Enemy);
    }
    else if(Enemy[nCE][5] == 9)
    {
        command = PirateAI(nCE, Enemy);
    }

    return command;
}
