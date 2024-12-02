#include<string>


using namespace std;

#include"Input.h"
#include"dice.h"
#include"AI.h"

int SpellPower(int SpellType)
{
    int power;

    if(SpellType == 0)
    {
        power = 5;
    }
    else if(SpellType == 1)
    {
        power = 1;
    }
    else if(SpellType == 2)
    {
        power = 1;
    }
    else if(SpellType == 3)
    {
        power = 2;
    }

    return power;
}


int Attack(bool player, int nCC, int CharacterStats[3][7], int CharacterInventory[3][14], int Enemy[3][8])
{
    int damage;
    int Stat;
    int Weapon;
    int Die;
    int Die2;
    int Die3;

    if(player == true)
    {
        Weapon = WeaponInput(nCC, CharacterStats, CharacterInventory);
        Die = RollDice(Weapon);
        if(Weapon != 69)
        {
            if(Weapon == 3 || Weapon == 4)
            {
                damage = Die * ((CharacterStats[nCC][2] + (5*CharacterStats[nCC][3]))/6);
            }
            else if(Weapon == 8)
            {
                if(nCC == 0)
                {
                    Stat = 2;
                }
                else if(nCC == 1)
                {
                    Stat = 3;
                }
                else if(nCC == 2)
                {
                    Stat = 4;
                }

                damage = Die*CharacterStats[nCC][Stat];
            }
            else if(Weapon == 9)
            {
                if(nCC == 0)
                {
                    Stat = 2;
                }
                else if(nCC == 1)
                {
                    Stat = 3;
                }
                else if(nCC == 2)
                {
                    Stat = 4;
                }

                Die2 = RollDice(16);
                {
                    if(Die2 >= 7)
                    {
                        Die3 = RollDice(Die2);
                    }

                    Die = Die*Die3;
                }

                damage = Die*CharacterStats[nCC][Stat];
            }
            else
            {
                damage = Die * CharacterStats[nCC][2];
            }

        }
        else
        {
            damage = -1;
        }
    }
    else if(player == false)
    {
        Weapon = GetWeapon(nCC, Enemy);
        Die = RollDice(Weapon);

        damage = Die * Enemy[nCC][2];
    }

    return damage;
}

int CastAttack(bool player, int SpellType, int nCC, int CharacterStats[3][7], int CharacterInventory[3][14], int Enemy[3][8])
{
    int power;
    int Die;
    int damage;

    power = SpellPower(SpellType);

    Die = RollDice(power);

    if(player == true)
    {
        damage = Die * CharacterStats[nCC][4];
        if(CharacterInventory[nCC][7] != 0 && CharacterInventory[nCC][8] == 0)
        {
            Die = RollDice(1);
            damage = damage * Die;
        }
        else if(CharacterInventory[nCC][8] != 0)
        {
            Die = RollDice(2);
            damage = damage * Die;
        }

    }
    else if(player == false)
    {
        damage = Die * Enemy[nCC][4];

        if(Enemy[nCC][5] == 5 && Enemy[nCC][6] == 150)
        {
            Die = RollDice(5);

            damage = Die*damage;
        }
        else if(Enemy[nCC][5] == 5 && Enemy[nCC][6] == 250)
        {
            Die = RollDice(1);

            damage = Die*damage;
        }
        else if(Enemy[nCC][5] == 7)
        {
            Die = RollDice(2);
            damage = Die*damage;
        }
    }

    damage = ((7*damage)/10);

    if(damage > 700)
    {
        damage = 700;
    }

    return damage;

}

int CastHeal(int nCC, int SpellType, int CharacterStats[3][7], int CharacterInventory[3][14], int Enemy[3][8], bool player)
{
    int restore;
    int Die;
    int roll;

    Die = SpellPower(SpellType);

    roll = RollDice(Die);


    if(player == true)
    {
        restore = roll * (CharacterStats[nCC][4]/10);
        if(CharacterInventory[nCC][7] != 0)
        {
            roll = RollDice(1);
            restore = restore * roll;
        }
        else if(CharacterInventory[nCC][8] != 0)
        {
            roll = RollDice(2);
            restore = restore * roll;

        }
    }
    else
    {
        restore = roll * (Enemy[nCC][4]/10);
        if(Enemy[nCC][5] == 5 && Enemy[nCC][6] == 150)
        {
            roll = RollDice(5);

            restore = roll*restore;
        }
        else if(Enemy[nCC][5] == 5 && Enemy[nCC][6] == 250)
        {
            roll = RollDice(1);

            restore = roll*restore;
        }
        else if(Enemy[nCC][5] == 7)
        {
            roll = RollDice(2);
            restore = roll*restore;
        }

    }
    return restore;

}

int Use(int nCC, int CharacterInventory[3][14])
{
    int PotionType;

    PotionType = InputPotion(nCC, CharacterInventory);

    return PotionType;
}

int Defend(bool player, int nCC, int CharacterStats[3][7], int Enemy[3][8])
{
    int strength;
    int block;
    int Dice;

    if(player == true)
    {
        strength = CharacterStats[nCC][2];
    }
    else if(player == false)
    {
         strength = Enemy[nCC][2];
    }

    if(strength < 15)
    {
        Dice = 12;
    }
    else if(strength < 30 && strength >= 15)
    {
        Dice = 11;
    }
    else if(strength < 60 && strength >= 30)
    {
        Dice = 10;
    }
    else if(strength >= 60)
    {
        Dice = 6;
    }

    block = RollDice(Dice);

    return block;
}
