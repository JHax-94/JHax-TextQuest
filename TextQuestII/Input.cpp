#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

int i;
bool Loop;
int StringLength;

bool YesNo()
{
    bool response;
    string UserInput;
    int stringLength;

    Loop = true;

    while(Loop == true)
    {
        cin.sync();

        getline(cin, UserInput);

        stringLength = UserInput.length();

        for(i = 0; i < stringLength; i++)
        {
            UserInput.at(i) = toupper(UserInput.at(i));
        }

        if(UserInput == "YES")
        {
            response = true;
            Loop = false;
        }
        else if(UserInput == "Y")
        {
            response = true;
            Loop = false;
        }
        else if(UserInput == "NO")
        {
            response = false;
            Loop = false;
        }
        else if(UserInput == "N")
        {
            response = false;
            Loop = false;
        }
        else
        {
            cout << "Not a valid input!\n";
            cout << "Please enter again: ";
        }
    }
    return response;
}


//===================================================================================================================================================
//===========================================INPUT POTION============================================================================================
//===================================================================================================================================================


int InputPotion(int nCC, int CharacterInventory[3][14])
{
    string sPotion;
    int nPotion;

    cout << "Potions in inventory: " << endl;

    if(CharacterInventory[nCC][11] != 0)
    {
        cout << CharacterInventory[nCC][11] << " x Health Potion\n";
    }
    if(CharacterInventory[nCC][12] != 0)
    {
        cout << CharacterInventory[nCC][12] << " x Magic Potion\n";
    }

    Loop = true;

    while(Loop == true)
    {
        cout << endl << "Which potion would you like to use? ";

        cin.sync();
        getline(cin, sPotion);

        StringLength = sPotion.length();

        for(i = 0; i < StringLength; i++)
        {
            sPotion.at(i) = toupper(sPotion.at(i));
        }

            if(sPotion == "HEALTH" || sPotion == "HEALTH POTION" || sPotion == "H" || sPotion == "HP")
            {
                if(CharacterInventory[nCC][11] != 0)
                {
                    nPotion = 1;
                    Loop = false;

                    CharacterInventory[nCC][11] --;
                }
                else if(CharacterInventory[nCC][11] == 0)
                {
                    cout << "You do not have this potion!\n";
                }
            }
            else if(sPotion == "MAGIC" || sPotion == "MAGIC POTION" || sPotion == "M" || sPotion == "MP")
            {
                if(CharacterInventory[nCC][12] != 0)
                {
                    nPotion = 2;
                    Loop = false;

                    CharacterInventory[nCC][12] --;
                }
                else if(CharacterInventory[nCC][12] == 0)
                {
                    cout << "You do not have this potion!\n";
                }
            }
            else if(sPotion == "BACK" || sPotion == "<")
            {
                nPotion = -1;
                Loop = false;
            }
            else
            {
                cout << "No such potion exists!\n";
            }
    }
    return nPotion;
}


//===================================================================================================================================================
//==============================================INPUT SPELL==========================================================================================
//===================================================================================================================================================
int InputSpell(int nCC, string CharacterInfo[3][3])
{
    string Spell;
    int SpellType;

    cout << "Which spell would you like to cast?" << endl;
    cout << "Known spells: " << endl;
    if(nCC == 2)
    {
        cout << "Fireball" << endl;
        cout << "Lightning Bolt" << endl;
        cout << "Heal" << endl;
    }
    if(CharacterInfo[nCC][2] == "Elf" || CharacterInfo[nCC][2] == "Lupine")
    {
        cout << "Elven Aura" << endl;
    }
    if(nCC != 2 && CharacterInfo[nCC][2] == "Dwarf")
    {
        cout << "Fireball" << endl;
        cout << "Heal" << endl;
    }
    if(CharacterInfo[nCC][2] == "Ancient")
    {
        cout << "Ancient Power" << endl;
    }
    cout << endl;

    cin.sync();
    getline(cin, Spell);

    StringLength = Spell.length();

    for(i = 0; i < StringLength; i++)
    {
        Spell.at(i) = toupper(Spell.at(i));
    }

    if(Spell == "FIREBALL" || Spell == "F" || Spell == "FB")
    {
        SpellType = 0;
    }
    else if(Spell == "LIGHTNING BOLT" || Spell == "L" || Spell == "LB")
    {
        SpellType = 1;
    }
    else if(Spell == "HEAL" || Spell == "H")
    {
        SpellType = 2;
    }
    else if(Spell == "ANCIENT POWER" || Spell == "AP")
    {
        SpellType = 3;
    }
    else if(Spell == "ELVEN AURA" || Spell == "EA")
    {
        SpellType = 4;
    }
    else if(Spell == "BACK" || Spell == "<")
    {
        SpellType = 5;
    }

    return SpellType;
}

//===================================================================================================================================================
//==============================================INPUT TARGET=========================================================================================
//===================================================================================================================================================

int HealTarget(int SpellType, int CharacterStats[3][7])
{
    int target;

    if(SpellType == 4)
    {
        target = 4;
    }
    else
    {

        Loop = true;
        while(Loop == true)
        {

            cout << endl << "Choose a target from your own team to heal (1-3): ";

            cin >> target;

            if(CharacterStats[(target-1)][0] == 0)
            {
                cout << "You cannot heal a dead character!";
            }
            else
            {
                Loop = false;
            }
        }
    }
    return target;
}



int InputTarget(int Enemy[3][8])
{
    bool Loop = true;
    int target;

    while(Loop == true)
    {
        cout << "Choose a target(1-3): ";
        cin >> target;

        if(target == 1 && Enemy[0][0] == 0)
        {
            cout << "This target is dead!\n";
        }
        else if(target == 2 && Enemy[1][0] == 0)
        {
            cout << "This target is dead!\n";
        }
        else if(target == 3 && Enemy[2][0] == 0)
        {
            cout << "This target is dead!\n";
        }
        else if(target >= 4 || target <= 0)
        {
            cout << "This is not a target!\n";
        }
        else
        {
            Loop = false;
        }
    }

    return target;
}




//===================================================================================================================================================
//================================================WEAPON INPUT=======================================================================================
//===================================================================================================================================================
int WeaponInput(int nCC, int CharacterStats[3][7], int CharacterInventory[3][14])
{

    int StringLength;
    string sWeapon;
    int nWeapon;


    cout << "What would you like to attack with? " << endl << endl;
    cout << "Weapons in your inventory: " << endl;
    cout << "Hands" << endl;

        if(CharacterInventory[nCC][2] != 0)
        {
            cout << "Sword\n";
        }
        if(CharacterInventory[nCC][3] != 0)
        {
            cout << "Black Knight's Blade\n";
        }
        if(CharacterInventory[nCC][4] != 0)
        {
            cout << "Bow\n";
        }
        if(CharacterInventory[nCC][5] != 0)
        {
            cout << "Dragon Strike Bow\n";
        }
        if(CharacterInventory[nCC][6] != 0)
        {
            cout << CharacterInventory[nCC][6] << " x Arrow\n";
        }
        if(CharacterInventory[nCC][7] != 0)
        {
            cout << "Staff\n";
        }
        if(CharacterInventory[nCC][8] != 0)
        {
            cout << "Staff of the Ancients\n";
        }
        if(CharacterInventory[nCC][9] != 0)
        {
            cout << "Pointed Stick\n";
        }
        if(CharacterInventory[nCC][10] != 0)
        {
            cout << "Rusty Spoon\n";
        }
        if(CharacterInventory[nCC][13] != 0)
        {
            cout << "Rusty Spoon on a Stick\n";
        }

    cout << endl;

   Loop = true;

   while(Loop == true)
   {
        cin.sync();
        getline(cin, sWeapon);

        StringLength = sWeapon.length();

        nWeapon = 72;

        for(i = 0; i < StringLength; i ++)
        {
            sWeapon.at(i) = toupper(sWeapon.at(i));
        }

        if(sWeapon == "HANDS" || sWeapon == "H")
        {
            nWeapon = 0;
            Loop = false;
        }
        else if(sWeapon == "SWORD" || sWeapon == "SW")
        {
            if(CharacterInventory[nCC][2] != 0)
            {
                nWeapon = 1;
                Loop = false;
            }
        }
        else if(sWeapon == "BLACK KNIGHT'S BLADE" || sWeapon == "BKB")
        {
            if(CharacterInventory[nCC][3] != 0)
            {
                 nWeapon = 2;
                Loop = false;
            }
        }
        else if(sWeapon == "BOW" || sWeapon == "B")
        {
            if(CharacterInventory[nCC][4] != 0)
            {
                if(CharacterInventory[nCC][6] != 0)
                {
                    nWeapon = 3;
                    CharacterInventory[nCC][6] --;
                    Loop = false;
                }
            }

        }
        else if(sWeapon == "DRAGON STRIKE BOW" || sWeapon == "DSB")
        {
            if(CharacterInventory[nCC][5] != 0)
            {
                if(CharacterInventory[nCC][6] != 0)
                {
                    nWeapon = 4;
                    CharacterInventory[nCC][6] --;
                    Loop = false;
                }
            }

        }
        else if(sWeapon == "STAFF" || sWeapon == "ST")
        {
            if(CharacterInventory[nCC][7] != 0)
            {
                nWeapon = 5;
                Loop = false;
            }
        }
        else if(sWeapon == "STAFF OF THE ANCIENTS" || sWeapon == "SOTA" || sWeapon == "SA")
        {
            if(CharacterInventory[nCC][8] != 0)
            {
                nWeapon = 6;
                Loop = false;
            }
        }
        else if(sWeapon == "POINTED STICK" || sWeapon == "PS")
        {
            if(CharacterInventory[nCC][9])
            {
                nWeapon = 7;
                Loop = false;
            }
        }
        else if(sWeapon == "RUSTY SPOON" || sWeapon == "RS")
        {
            if(CharacterInventory[nCC][10] != 0)
            {
                nWeapon = 4;
                Loop = false;
            }
        }
        else if(sWeapon == "RUSTY SPOON ON A STICK" || sWeapon == "RSOAS" || sWeapon == "RSS")
        {
            if(CharacterInventory[nCC][13] != 0)
            {
                nWeapon = 18;
                Loop = false;
            }
        }
        else if(sWeapon == "BACK" || "<")
        {
            nWeapon = 69;
            Loop = false;
        }
/*        else
        {
            cout << "Please choose again: ";
        }
*/
        if(nWeapon == 72)
        {
            cout << "Please choose again: ";
        }

    }

    return nWeapon;
}


int CombineItemInput(int nCC, int CharacterInventory[3][14])
{

    int StringLength;
    string sWeapon;
    int nWeapon;


    cout << "What would you like to try to combine with the rusty spoon? " << endl << endl;
    cout << "Potential items: " << endl;

        if(CharacterInventory[nCC][2] != 0)
        {
            cout << "Sword\n";
        }
        if(CharacterInventory[nCC][3] != 0)
        {
            cout << "Black Knight's Blade\n";
        }
        if(CharacterInventory[nCC][4] != 0)
        {
            cout << "Bow\n";
        }
        if(CharacterInventory[nCC][5] != 0)
        {
            cout << "Dragon Strike Bow\n";
        }
        if(CharacterInventory[nCC][7] != 0)
        {
            cout << "Staff\n";
        }
        if(CharacterInventory[nCC][8] != 0)
        {
            cout << "Staff of the Ancients\n";
        }
        if(CharacterInventory[nCC][9] != 0)
        {
            cout << "Pointed Stick\n";
        }

    cout << endl;

   Loop = true;

   while(Loop == true)
   {
        cin.sync();
        getline(cin, sWeapon);

        StringLength = sWeapon.length();

        for(i = 0; i < StringLength; i ++)
        {
            sWeapon.at(i) = toupper(sWeapon.at(i));
        }

        if(sWeapon == "HANDS")
        {
            nWeapon = 0;
            Loop = false;
        }
        else if(sWeapon == "SWORD")
        {
            nWeapon = 1;
            Loop = false;
        }
        else if(sWeapon == "BLACK KNIGHT'S BLADE")
        {
            nWeapon = 2;
            Loop = false;
        }
        else if(sWeapon == "BOW")
        {
            nWeapon = 3;
            Loop = false;
        }
        else if(sWeapon == "DRAGON STRIKE BOW")
        {
            nWeapon = 4;
            Loop = false;
        }
        else if(sWeapon == "STAFF")
        {
            nWeapon = 5;
            Loop = false;
        }
        else if(sWeapon == "STAFF OF THE ANCIENTS")
        {
            nWeapon = 6;
            Loop = false;
        }
        else if(sWeapon == "POINTED STICK")
        {
            nWeapon = 7;
            Loop = false;
        }
        else if(sWeapon == "RUSTY SPOON")
        {
            nWeapon = 17;
            Loop = false;
        }
        else if(sWeapon == "RUSTY SPOON ON A STICK")
        {
            nWeapon = 18;
            Loop = false;
        }
        else
        {
            cout << "Please choose again: ";
        }
    }

    return nWeapon;
}


//===================================================================================================================================================
//================================================CHARACTER INPUT====================================================================================
//===================================================================================================================================================

string InputRace()
{
    string race;
    Loop = true;

    while(Loop == true)
    {
        cout << "Race: ";

        cin.sync();
        getline(cin, race);

        StringLength = race.length();

        for(i = 0; i < StringLength; i ++)
        {
            race.at(i) = toupper(race.at(i));
        }
        if(race == "HUMAN")
        {
            race = "Human";
            Loop = false;
        }
        else if(race == "ELF")
        {
            race = "Elf";
            Loop = false;
        }
        else if(race == "ORC")
        {
            race = "Orc";
            Loop = false;
        }
        else if(race == "DWARF")
        {
            race = "Dwarf";
            Loop = false;
        }
        else if(race == "LUPINE")
        {
            race = "Lupine";
            Loop = false;
        }
        else if(race == "ANCIENT")
        {
            race = "Ancient";
            Loop = false;
        }
        else
        {
            cout << "This is not a race!\n";
        }
    }

    return race;
}

string InputName()
{
    string name;
    Loop = true;

    while(Loop == true)
    {
        cin.sync();
        cout << "Name: ";

        getline(cin, name);

        if(name.length() > 10)
        {
            cout << "Name must be less than 10 characters long!" << endl;
        }
        else if(name.length() == 0)
        {
            cout << "Character must have a name!" << endl;
        }
        else
        {
            Loop = false;
        }
    }

    return name;
}

string InputGender()
{
    string gender;
    cin.sync();

    Loop = true;

    while(Loop == true)
    {
        cout << "Gender: ";

        getline(cin, gender);

        StringLength = gender.length();

        for(i = 0; i < StringLength; i ++)
        {
            gender.at(i) = toupper(gender.at(i));
        }

        if(gender == "MALE")
        {
            gender = "Male";
            Loop = false;
        }
        else if(gender == "FEMALE")
        {
            gender = "Female";
            Loop = false;
        }
        else
        {
            cout << gender << " is not a gender!" << endl;
        }
    }
    return gender;
}

//===================================================================================================================================================
//===================================================================================================================================================
//===================================================================================================================================================

//===================================================================================================================================================
//===================================================== FUNCTION==============================================================================
//===================================================================================================================================================

void PickUp(int CharacterInventory[3][14], int RoomItems[14], int nCC)
{
    string Item;

    cout << "Items in room: \n";
 //   for(i = 0; i < 8; i++)
   // {
        if(RoomItems[0] != 0)
        {
            cout << RoomItems[0] << " x Plate Armour\n";
        }
        if(RoomItems[1] != 0)
        {
            cout << RoomItems[1] << " x Leather Armour\n";
        }
        if(RoomItems[2] != 0)
        {
            cout << RoomItems[2] << " x Sword\n";
        }
        if(RoomItems[3] != 0)
        {
            cout << RoomItems[3] << " x Black Knight's Blade\n";
        }
        if(RoomItems[4] != 0)
        {
            cout << RoomItems[4] << " x Bow\n";
        }
        if(RoomItems[5] != 0)
        {
            cout << RoomItems[5] << " x Dragon Strike Bow\n";
        }
        if(RoomItems[6] != 0)
        {
            cout << RoomItems[6] << " x Arrow\n";
        }
        if(RoomItems[7] != 0)
        {
            cout << RoomItems[7] << " x Staff\n";
        }
        if(RoomItems[8] != 0)
        {
            cout << RoomItems[8] << " x Staff of the Ancients\n";
        }
        if(RoomItems[9] != 0)
        {
            cout << RoomItems[9] << " x Pointed Stick\n";
        }
        if(RoomItems[10] != 0)
        {
            cout << RoomItems[10] << " x Rusty Spoon\n";
        }
        if(RoomItems[11] != 0)
        {
            cout << RoomItems[11] << " x Health Potion\n";
        }
        if(RoomItems[12] != 0)
        {
            cout << RoomItems[12] << " x Magic Potion\n";
        }
   // }
    cout << "What item would you like to pick up? ";
    cin.sync();
    getline(cin, Item);

      StringLength = Item.length();

    for(i = 0; i < StringLength; i ++)
    {
        Item.at(i) = toupper(Item.at(i));
    }

    if(Item == "PLATE ARMOUR")
    {
            if(RoomItems[0] >= 1)
            {
                RoomItems[0] --;
                CharacterInventory[nCC][0] ++;
            }
            else if(RoomItems[0] == 0)
            {
                cout << "There is no plate armour in this room!" << endl;
                system("PAUSE");
            }
    }
    else if(Item == "LEATHER ARMOUR")
    {
        if(RoomItems[1] >=1)
        {
            RoomItems[1] --;
            CharacterInventory[nCC][1] ++;
        }
        else if(RoomItems == 0)
        {
            cout << "There is no leather armour in this room" << endl;
            system("PAUSE");
        }
    }
    else if(Item == "ARMOUR")
    {
        if(RoomItems[1] >= 1 && RoomItems[0] == 0)
        {
            RoomItems[1] --;
            CharacterInventory[nCC][1] ++;
        }
        else if(RoomItems[0] >= 1 && RoomItems[1] == 0)
        {
            RoomItems[0] --;
            CharacterInventory[nCC][0] ++;
        }
        else if(RoomItems[0] == 0 && RoomItems[1] == 0)
        {
            cout << "There is no armour in this room!" << endl;
            system("PAUSE");
        }
        else if(RoomItems[0] >= 1 && RoomItems[1] >= 1)
        {
            cout << "Please specify which type of armour you wish to pick up!" << endl;
            system("PAUSE");
        }
    }

    else if(Item == "SWORD")
    {

        if(RoomItems[2] >= 1)
        {
            RoomItems[2] --;
            CharacterInventory[nCC][2] ++;
        }
        else if(RoomItems[2] == 0)
        {
            cout << "There is no sword in this room!" << endl;
            system("PAUSE");
        }
    }
    else if(Item == "BLACK KNIGHT'S BLADE")
    {
        if(RoomItems[3] >= 1)
        {
            RoomItems[3] --;
            CharacterInventory[nCC][3] ++;
        }
        else if(RoomItems[3] == 0)
        {
            cout << "The Black Knight's blade is not in this room!" << endl;
            system("PAUSE");
        }
    }
    else if(Item == "BOW")
    {
        if(RoomItems[4] >= 1)
        {
            RoomItems[4] --;
            CharacterInventory[nCC][4] ++;
        }
        else if(RoomItems[4] == 0)
        {
            cout << "There is no bow in this room!" << endl;
            system("PAUSE");
        }
    }
    else if(Item == "DRAGON STRIKE BOW")
    {
        if(RoomItems[5] >= 1)
        {
            RoomItems[5] --;
            CharacterInventory[nCC][5] ++;
        }
        else if(RoomItems[5] == 0)
        {
            cout << "The Dragon Strike Bow is not in this room!" << endl;
        }
    }
    else if(Item == "ARROW")
    {
        if(RoomItems[6] >= 1)
        {
            RoomItems[6] --;
            CharacterInventory[nCC][6] ++;
        }
        else if(RoomItems[6] == 0)
        {
            cout << "There are no arrows in this room!" << endl;
        }
    }
    else if(Item == "ARROWS")
    {
        if(RoomItems[6] >= 1)
        {
            CharacterInventory[nCC][6] += RoomItems[6];
            RoomItems[6] = 0;
        }
        else if(RoomItems[6] == 0)
        {
            cout << "There are no arrows in this room!" << endl;
        }
    }
    else if(Item == "STAFF")
    {
        if(RoomItems[7] >= 1)
        {
            RoomItems[7] --;
            CharacterInventory[nCC][7] ++;
        }
        else if(RoomItems[7] == 0)
        {
            cout << "There is no staff in this room!" << endl;
        }
    }
    else if(Item == "STAFF OF THE ANCIENTS")
    {
        if(RoomItems[8] >= 0)
        {
            RoomItems[8] --;
            CharacterInventory[nCC][8] ++;
        }
        else if(RoomItems[8] == 0)
        {
            cout << "The Staff of the Ancients is not in this room!" << endl;
        }
    }
    else if(Item == "POINTED STICK")
    {
        if(RoomItems[9] >= 1)
        {
            RoomItems[9] --;
            CharacterInventory[nCC][9] ++;
        }
        else if(RoomItems[9] == 0)
        {
            cout << "There is no pointed stick in this room!";
        }
    }
    else if(Item == "RUSTY SPOON")
    {
        if(RoomItems[10] >= 1)
        {
            RoomItems[10] --;
            CharacterInventory[nCC][10] ++;
        }
        else if(RoomItems[10] == 0)
        {
            cout << "There is no rusty spoon in this room!";
        }
    }
    else if(Item == "HEALTH POTION")
    {
        if(RoomItems[11] >= 1)
        {
            RoomItems[11] --;
            CharacterInventory[nCC][11] ++;
        }
        else if(RoomItems[11] == 0)
        {
            cout << "There are no health potions in this room!";
        }
    }
    else if(Item == "MAGIC POTION")
    {
        if(RoomItems[12] >= 1)
        {
            RoomItems[12] --;
            CharacterInventory[nCC][12] ++;
        }
        else if(RoomItems[12] == 0)
        {
            cout << "There are no magic potions in this room!";
        }
    }


    else if(Item == "HEALTH POTIONS")
    {
        if(RoomItems[11] >= 1)
        {
            CharacterInventory[nCC][11] += RoomItems[11];
            RoomItems[11] = 0;
        }
        else if(RoomItems[11] == 0)
        {
            cout << "There are no potions in this room!";
        }
    }
    else if(Item == "MAGIC POTIONS")
    {
        if(RoomItems[12] >= 1)
        {
            CharacterInventory[nCC][12] += RoomItems[12];
            RoomItems[12] = 0;
        }
        else if(RoomItems[12] == 0)
        {
            cout << "There are no magic potions in this room!";
        }
    }
    else if(Item == "NONE")
    {
        return;
    }
    else
    {
        cout << "This is not an item!";
    }



    return;
}
//===================================================================================================================================================
//=========================================================INPUT FUNCTION============================================================================
//===================================================================================================================================================

int Input()
{
    string UserInput;
    int StringLength;
    int command;
    Loop = true;


    while(Loop == true)
    {

        cin.sync();
        getline(cin, UserInput);

        StringLength = UserInput.length();

        for(i = 0; i < StringLength; i ++)
        {
            UserInput.at(i) = toupper(UserInput.at(i));
        }

    //    cout << UserInput << endl;

        if(UserInput == "GET UP")
        {
            command = 0;
            Loop = false;
        }
        else if(UserInput == "PICK UP")
        {
            command = 1;
            Loop = false;
        }
        else if(UserInput == "NORTH")
        {
            command = 2;
            Loop = false;
        }
        else if(UserInput == "N")
        {
            command = 2;
            Loop = false;
        }
        else if(UserInput == "EAST")
        {
            command = 3;
            Loop = false;
        }
        else if(UserInput == "E")
        {
            command = 3;
            Loop = false;
        }
        else if(UserInput == "SOUTH")
        {
            command = 4;
            Loop = false;
        }
        else if(UserInput == "S")
        {
            command = 4;
            Loop = false;
        }
        else if(UserInput == "WEST")
        {
            command = 5;
            Loop = false;
        }
        else if(UserInput == "W")
        {
            command = 5;
            Loop = false;
        }
        else if(UserInput == "SKIP")
        {
            command = 6;
            Loop = false;
        }
        else if(UserInput == "ATTACK")
        {
            command = 7;
            Loop = false;
        }
        else if(UserInput == "A")
        {
            command = 7;
            Loop = false;
        }
        else if(UserInput == "CAST")
        {
            command = 10;
            Loop = false;
        }
        else if(UserInput == "C")
        {
            command = 10;
            Loop = false;
        }
        else if(UserInput == "USE")
        {
            command = 11;
            Loop = false;
        }
        else if(UserInput == "U")
        {
            command = 11;
            Loop = false;
        }
        else if(UserInput == "DEFEND")
        {
            command = 17;
            Loop = false;
        }
        else if(UserInput == "D")
        {
            command = 17;
            Loop = false;
        }
        else if(UserInput == "VIEW INVENTORY")
        {
            command = 12;
            Loop = false;
        }
        else if(UserInput == "INVENTORY")
        {
            command = 12;
            Loop = false;
        }
        else if(UserInput == "VI")
        {
            command = 12;
            Loop = false;
        }
        else if(UserInput == "HELP")
        {
            command = 13;
            Loop = false;
        }
        else if(UserInput == "INFO")
        {
            command = 13;
            Loop = false;
        }
        else if(UserInput == "?")
        {
            command = 13;
            Loop = false;
        }
        else if(UserInput == "SAVE")
        {
            command = 14;
            Loop = false;
        }
        else if(UserInput == "SWITCH")
        {
            command = 16;
            Loop = false;
        }
        else if(UserInput == "VIEW MAP")
        {
            command = 8;
            Loop = false;
        }
        else if(UserInput == "MAP")
        {
            command = 8;
            Loop = false;
        }
        else if(UserInput == "VM")
        {
            command = 8;
            Loop = false;
        }
        else if(UserInput == "INVESTIGATE")
        {
            command = 9;
            Loop = false;
        }
        else if(UserInput == "EXAMINE")
        {
            command = 9;
            Loop = false;
        }
        else if(UserInput == "SNEAK")
        {
            command = 18;
            Loop = false;
        }
        else if(UserInput == "SNEAK PAST")
        {
            command = 18;
            Loop = false;
        }
        else if(UserInput == "CHARGE")
        {
            command = 19;
            Loop = false;
        }
        else if(UserInput == "CHALLENGE")
        {
            command = 20;
            Loop = false;
        }
        else if(UserInput == "MOVE")
        {
            command = 21;
            Loop = false;
        }
        else if(UserInput == "SPEAK")
        {
            command = 22;
            Loop = false;
        }
        else if(UserInput == "TALK")
        {
            command = 22;
            Loop = false;
        }
        else if(UserInput == "VIEW STATS")
        {
            command = 23;
            Loop = false;
        }
        else if(UserInput == "VS")
        {
            command = 23;
            Loop = false;
        }
        else if(UserInput == "STATS")
        {
            command = 23;
            Loop = false;
        }
        else if(UserInput == "END")
        {
            command = -1;
            Loop = false;
        }
        else if(UserInput == "EXIT")
        {
            command = -1;
            Loop = false;
        }
        else if(UserInput == "QUIT")
        {
            command = -1;
            Loop = false;
        }
        else if(UserInput == "DODGE")
        {
            command = 100;
            Loop = false;
        }
        else if(UserInput == "BAT")
        {
            command = 101;
            Loop = false;
        }
        else if(UserInput == "KEEP CLIMBING")
        {
            command = 102;
            Loop = false;
        }
        else if(UserInput == "CLIMB")
        {
            command = 102;
            Loop = false;
        }
        else if(UserInput == "HOLD ON")
        {
            command = 103;
            Loop = false;
        }
        else if(UserInput == "HOLD")
        {
            command = 103;
            Loop = false;
        }

        else
        {
            cout << "Unrecognised command!" << endl;
            cout << "Please enter again: ";
        }

      //  cout << "Command = " << command << endl;

        system("PAUSE");
    }

    return command;
}
