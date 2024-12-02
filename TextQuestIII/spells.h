#ifndef SPELLS_H_INCLUDED
#define SPELLS_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

class spell
{
    public:

        string Name;
        int Type;
            /*
             *  0 NULL
             *  1 OFFENSIVE SINGLE TARGET
             *  2 OFFENSIVE MULTI-TARGET
             * -1 DEFENSIVE SINGLE TARGET
             * -2 DEFENSIVE MULTI-TARGET
            */

        int Power;
        int Cost;

    spell()
    {
        Name = "None";
        Type = 0;
        Power = 0;
        Cost = 0;
    }

    spell(string NewName, int NewType, int NewPower, int NewCost)
    {
        Name = NewName;
        Type = NewType;
        Power = NewPower;
        Cost = NewCost;
    }

    spell operator= (const spell& OldSpell)
    {
        Name = OldSpell.Name;
        Type = OldSpell.Type;
        Power = OldSpell.Power;
        Cost = OldSpell.Cost;

        return *this;
    }

    friend ostream& operator<< (ostream &out, spell Spell)
    {
        out << Spell.Name << endl;
        out << Spell.Type << endl;
        out << Spell.Power << endl;
        out << Spell.Cost << endl;

        return out;
    }

    friend istream& operator >> (istream& in, spell &Spell)
    {
        in.sync();
        getline(in, Spell.Name);
        in >> Spell.Type;   in.ignore(512, '\n');
        in >> Spell.Power;  in.ignore(512, '\n');
        in >> Spell.Cost;   in.ignore(512, '\n');

        return in;
    }

    string WriteCost();
};

//OFFENSIVE SINGLE-TARGET
    extern spell Fireball;
    extern spell Lightning;

//DEFENSIVE SINGLE-TARGET
    extern spell Heal;

// DEFENSIVE MULTI-TARGET
    extern spell ElvenAura;

//OFFENSIVE MULTI-TARGET
    extern spell AncientPower;

#endif // SPELLS_H_INCLUDED
