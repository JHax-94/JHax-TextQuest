using namespace std;

#include "DiceBoard.h"
#include "Inputs.h"
#include "Combat.h"
#include "Screens.h"

void AI(character Enemy[], character Player[], int nCC, int command[])
{
    command[0] = 9;
}

int DefenceMod(character Defender[], int nCC, int Defence[])
{
    int DefID;
    int DefMod = 0;

    if(Defence[nCC] != -1)
    {
        DefID = Defence[nCC];

        DefMod = Defender[DefID].Str;

        Defence[nCC] = -1;
    }

    return DefMod;
}

void Attack(character Attacker[], character Defender[], int nTarget, int nCC, int Defence[])
{
    //Calculate Damage Done

    int WeaponMod = Attacker[nCC].Equipment.RightHand.Damage;
    int StrMod = Attacker[nCC].Str - Attacker[nCC].Equipment.RightHand.Weight;
    int AgiMod = Attacker[nCC].Agi - Attacker[nCC].Equipment.RightHand.Weight;

    int CharMod;

    int ArmMod;
    int DefMod;
    int ShieldMod;

    int Damage = 0;
    int LHDamage;

    if(StrMod < 0)
    {
        StrMod = 0;
    }
    if(AgiMod < 0)
    {
        AgiMod = 0;
    }

    CharMod = StrMod;

    if(Attacker[nCC].Equipment.RightHand.Bow == true)
    {
        if(AgiMod > StrMod)
        {
            CharMod = AgiMod;
        }
    }


    if(Attacker[nCC].Equipment.RightHandState() == false)
    {
        CharMod = Attacker[nCC].Str/10;
        WeaponMod = Attacker[nCC].Str/5;
    }

    Damage += RollDice(CharMod, WeaponMod);


    if(Attacker[nCC].Equipment.LeftHandState() == 1)
    {
        WeaponMod = Attacker[nCC].Equipment.wLeftHand.Damage;
        StrMod = Attacker[nCC].Str - Attacker[nCC].Equipment.wLeftHand.Weight;

        LHDamage = RollDice(StrMod, WeaponMod);

        if(LHDamage > Damage)
        {
            Damage = LHDamage;
        }
    }

    //Check Traits

    //Calculate DefenceMod

    StrMod = Defender[nTarget].Str - Defender[nTarget].Equipment.Body.Weight;

    if(StrMod < 0)
    {
        StrMod = 0;
    }

    ArmMod = Defender[nTarget].Equipment.Body.Defence;

    if(ArmMod <= StrMod)
    {
        DefMod = ArmMod;
    }
    else
    {
        DefMod = RollDice(StrMod, ArmMod);
    }

    if(Defender[nTarget].Equipment.LeftHandState() == -1)
    {
        StrMod = Defender[nTarget].Str - Defender[nTarget].Equipment.aLeftHand.Weight;
        ArmMod = Defender[nTarget].Equipment.aLeftHand.Defence;

        ShieldMod = RollDice(StrMod, ArmMod);

        if(ShieldMod > DefMod)
        {
            DefMod = ShieldMod;
        }
    }

    DefMod += DefenceMod(Defender, nTarget, Defence);

    Damage = Damage - DefMod/10;

    //Take Damage

    Defender[nTarget].Health[0] -= Damage;

}

void Cast(character Caster[], character Enemy[], int nTarget, int nCC, int Defence[])
{
    //Calculate Power

    int nPower = 0;
    int IntMod;
    int StaffMod;

    IntMod = Caster[nCC].Int - Caster[nCC].EquipSpell.Cost;

    if(IntMod < 0)
    {
        IntMod = 0;
    }

    nPower += RollDice(IntMod, Caster[nCC].EquipSpell.Power);

    StaffMod = Caster[nCC].EquipSpell.Power - Caster[nCC].EquipSpell.Cost;

    if(Caster[nCC].Equipment.RightHand.Staff == true)
    {
        StaffMod -= Caster[nCC].Equipment.RightHand.Weight/10;
    }

    if(StaffMod < 0)
    {
        StaffMod = 0;
    }

    //Check Traits

    //Cast Spell
    //  *Do effect
    //  *Deduct Magic

    nPower -= RollDice(StaffMod);



    switch(Caster[nCC].EquipSpell.Type)
    {
        case 1:
        {
            nPower -= DefenceMod(Enemy, nCC, Defence);
            Enemy[nTarget].Health[0] -= nPower;
            cout << Caster[nCC].FirstName << " casts " << Caster[nCC].EquipSpell.Name << " on " << Enemy[nTarget].FirstName << "!\n\n";
        break;
        }
        case 2:
        {
            for(int i = 0; i < CountAlive(Enemy); i ++)
            {
                nPower -= DefenceMod(Enemy, i, Defence);
                Enemy[i].Health[0] -= nPower;
            }

            cout << Caster[nCC].FirstName << " casts " << Caster[nCC].EquipSpell.Name << " on the enemy!\n\n";


        break;
        }
        case -1:
        {
            Caster[nTarget].Health[0] += nPower;
            cout << Caster[nCC].FirstName << " casts " << Caster[nCC].EquipSpell.Name << " on " << Caster[nCC].FirstName << "!\n\n";
        break;
        }
        case -2:
        {
            for(int i = 0; i < CountAlive(Caster); i ++)
            {
                Caster[i].Health[0] += nPower;
                string Possessive;

                if(Caster[nCC].Gender == "Male")
                {
                    Possessive = "his";
                }
                else
                {
                    Possessive = "her";
                }

                cout << Caster[nCC].FirstName << " casts " << Caster[nCC].EquipSpell.Name << " on " << Possessive << " team!\n\n";

            }
        break;
        }
    }

    Caster[nCC].Magic[0] -= Caster[nCC].EquipSpell.Cost;

    system("PAUSE");
}

void DefendBump(int Defence[], int From, int To)
{
    for(int i = 0; i < 3; i ++)
    {
        if(Defence[i] == From)
        {
            Defence[i] = 0;
        }
        else if(Defence[i] == To)
        {
            Defence[i] = From;
        }
    }
}

void Defend(int Defence[], int command[], int nCC)
{
    Defence[command[1]] = (nCC+1);
}

void UseItem(character User[], int nCC, int command[])
{
    if(User[nCC].Inventory[command[1]]->iType == 2)
    {
        potion *UsePotion = dynamic_cast<potion*>(User[nCC].Inventory[command[1]]);

        if(UsePotion->Type == 1)
        {
            User[nCC].Health[0] += UsePotion->Modifier;
        }
        else if(UsePotion->Type == 2)
        {
            User[nCC].Magic[0] += UsePotion->Modifier;
        }


        User[nCC].Inventory[command[1]]->Quantity --;
    }
}

void Interact()
{

}

void Move(int MoveTo, int nCC, arena Arena, bool PlayerOn)
{
    Arena.ChangePos(nCC, MoveTo, PlayerOn);
}

void ChangeEquip(character Player[], int command[], int nCC, bool PlayerOn)
{
    bool YN;
    if(PlayerOn == true)
    {
        if(Player[nCC].Inventory[command[1]]->iType == 1)
        {
            if(Player[nCC].Equipment.RightHandState() == true)
            {
                cout << "Equip to left hand? ";
                YN = YesNo();
                if(YN == true)
                {
                    Player[nCC].Equip(command[1], 2);
                }
                else
                {
                    Player[nCC].Equip(command[1], 3);
                }
            }
        }
        else if(Player[nCC].Inventory[command[1]]->iType == 3)
        {
            armour *NewArmour = dynamic_cast<armour*>(Player[nCC].Inventory[command[1]]);
            if(NewArmour->BodyArmour == true)
            {
                Player[nCC].Equip(command[1], 0);
            }
            else
            {
                Player[nCC].Equip(command[1], 1);
            }
        }
    }
}

void ChangeSpell(character Player[], int nCC, int command[])
{
    Player[nCC].EquipSpell = Player[nCC].Spells[command[1]];
}

bool DoCommand(character Player[], character Enemy[], arena Arena, int nCC, bool PlayerOn, int command[], int Defence[], bool& FightOn)
{
    bool TurnOn = true;

    switch(command[0])
    {

        case -1:
        {
            FightOn = false;
            TurnOn = false;
        break;
        }
        case 1:
        {
            Attack(Player, Enemy, command[1], nCC, Defence);

            cout << Player[nCC].FirstName << " attacks " << Enemy[command[1]].FirstName << "!\n\n";
            TurnOn = false;
            system("PAUSE");
        break;
        }
        case 2:
        {
            Cast(Player, Enemy, command[1], nCC, Defence);
            TurnOn = false;
        break;
        }
        case 3:
        {
            Defend(Defence, command, nCC);

            TurnOn = false;
        break;
        }
        case 4:
        {
            UseItem(Player, nCC, command);

            TurnOn = false;
        break;
        }
        case 5:
        {
            Interact();

            TurnOn = false;
        break;
        }
        case 6:
        {
            Move(command[1], nCC, Arena, PlayerOn);

            cout << Player[nCC].FirstName << " moves to " << Arena.Objects[command[1]].Name << "!\n\n";


            TurnOn = false;
            system("PAUSE");

        break;
        }
        case 7:
        {
            ChangeEquip(Player, command, nCC, PlayerOn);
        break;
        }
        case 8:
        {
            ChangeSpell(Player, nCC, command);
        break;
        }
        case 9:
        {
            cout << Player[nCC].FirstName << " does nothing!\n\n";
            system("PAUSE");

            TurnOn = false;
        break;
        }


        cout << "Butt stuff!\n\n";
        system("PAUSE");
    }

    return TurnOn;


}

bool CheckFight(bool &Victory, character Player[], character Enemy[])
{
    bool FightOn = true;

    if(CountAlive(Player) == 0)
    {
        Victory = false;
        FightOn = false;
    }
    else if(CountAlive(Enemy) == 0)
    {
        Victory = true;
        FightOn = false;
    }

    return FightOn;
}

void BumpParty(character TestParty[], arena Arena, int Defence[])
{
    for(int i = 0; i < 2; i ++)
    {
        if(TestParty[i].Health[0] == 0)
        {
            for(int j = i+1; j < 3; j ++)
            {
                if(TestParty[j].Health[0] != 0)
                {

                    if(TestParty[j].player == false)
                    {
                        Arena.BumpPos( -(j+1), -(i+1) );
                    }
                    else
                    {
                        Arena.BumpPos(j+1, i+1);
                    }

                    DefendBump(Defence, j, i);

                    TestParty[i] = TestParty[j];
                    TestParty[j].ReNull();
                    i = -1;
                }
            }
        }
    }
}


void CheckBounds(character TestParty[])
{
    for(int i = 0; i < 3; i ++)
    {
        TestParty[i].BoundHealth();
        TestParty[i].BoundMagic();
    }
}

int NextTurn(bool &PlayerOn, int nCC, character Player[], character Enemy[])
{
    bool Loop = true;
    while(Loop == true)
    {
        if(PlayerOn == true)
        {
            PlayerOn = false;

            if(Enemy[nCC].Health[0] != 0)
            {
                Loop = false;
            }
        }
        else
        {
            PlayerOn = true;
            nCC ++;

            if(nCC == 3)
            {
                nCC = 0;
            }

            if(Player[nCC].Health[0] != 0)
            {
                Loop = false;
            }
        }
    }
    return nCC;
}

void RegenMagic(character Party[], int nCC)
{
    Party[nCC].Magic[0] += (Party[nCC].Int/10);

    CheckBounds(Party);
}

void ResetDefence(int Defence[], int nCC)
{
    for(int i = 0; i < 3; i ++)
    {
        if(Defence[i] == nCC)
        {
            Defence[i] = -1;
        }
    }

}

bool fight(character Player[3], character Enemy[3], arena Arena)
{
    int nCC = 2;
    bool PlayerOn = false;
    bool FightOn = true;
    bool Victory = false;
    bool TurnOn;
    int PlayerDefence[3] = {-1, -1, -1};
    int EnemyDefence[3] = {-1, -1, -1};
    int command[2] = {0, 0};

/*
    cout << endl << "Allies: " << CountAlive(Player) << endl;
    cout << endl << "Enemies: " << CountAlive(Enemy) << endl;

    system("PAUSE");
*/
    Arena.InitialisePos(CountAlive(Player), CountAlive(Enemy));

    while(FightOn == true)
    {
        nCC = NextTurn(PlayerOn, nCC, Player, Enemy);

        TurnOn = true;

        if(PlayerOn == false)
        {
            RegenMagic(Enemy, nCC);
            ResetDefence(EnemyDefence, nCC);
        }
        else
        {
            RegenMagic(Player, nCC);
            ResetDefence(PlayerDefence, nCC);
        }

        BumpParty(Player, Arena, PlayerDefence);
        BumpParty(Enemy, Arena, EnemyDefence);

        while(TurnOn == true)
        {
            FightScreen(Player, Enemy, Arena, nCC, PlayerOn, command);

            if(PlayerOn == false)
            {
                AI(Enemy, Player, nCC, command);

                TurnOn = DoCommand(Enemy, Player, Arena, nCC, PlayerOn, command, EnemyDefence, FightOn);
            }
            else
            {
                TurnOn = DoCommand(Player, Enemy, Arena, nCC, PlayerOn, command, PlayerDefence, FightOn);
            }
        }
        CheckBounds(Player);
        CheckBounds(Enemy);



        FightOn = CheckFight(Victory, Player, Enemy);
    }

    if(Victory == true)
    {
        cout << "You are victorious!\n\n";
        system("PAUSE");
    }
    else
    {
        cout << "You have been defeated!\n\n";
        system("PAUSE");
    }

    return Victory;
}
