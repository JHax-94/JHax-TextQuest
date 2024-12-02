#include<sstream>

using namespace std;

#include "spells.h"

string spell::WriteCost()
{
    string sCost;
    stringstream Convert;
    Convert << Cost;
    sCost = Convert.str();
    Convert.str("");

    return sCost;
}


spell Fireball("Fireball", 1, 25, 5);
spell Lightning("Lightning", 1, 50, 15);

spell Heal("Heal", -1, 30, 30);

spell ElvenAura("Elven Aura", -2, 20, 50);

spell AncientPower("Ancient Power", 2, 40, 100);
