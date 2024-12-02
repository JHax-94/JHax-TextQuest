#include<string>

using namespace std;

void ApplyRace(string CharacterInfo[3][3], int CharacterStats[3][7], int nCC)
{
            if(CharacterInfo[nCC][2] == "Human")
            {
                CharacterStats[nCC][0] += 25;
                CharacterStats[nCC][2] += 10;
                CharacterStats[nCC][4] -= 10;
                CharacterStats[nCC][5] = 125;
            }
            else if(CharacterInfo[nCC][2] == "Elf")
            {
                CharacterStats[nCC][1] += 50;
                CharacterStats[nCC][2] -= 40;
                CharacterStats[nCC][3] += 20;
                CharacterStats[nCC][4] += 20;
                CharacterStats[nCC][5] = 100;
                CharacterStats[nCC][6] += 50;
            }
            else if(CharacterInfo[nCC][2] == "Orc")
            {
                CharacterStats[nCC][0] += 50;
                CharacterStats[nCC][2] += 70;
                CharacterStats[nCC][3] -= 30;
                CharacterStats[nCC][4] -= 40;
                CharacterStats[nCC][5] = 150;
            }
            else if(CharacterInfo[nCC][2] == "Dwarf")
            {
                CharacterStats[nCC][1] += 100;
                CharacterStats[nCC][2] += 20;
                CharacterStats[nCC][3] -= 40;
                CharacterStats[nCC][4] += 20;
                CharacterStats[nCC][5] = 100;
                CharacterStats[nCC][6] += 100;
            }
            else if(CharacterInfo[nCC][2] == "Lupine")
            {
                CharacterStats[nCC][1] += 50;
                CharacterStats[nCC][2] += 25;
                CharacterStats[nCC][3] += 20;
                CharacterStats[nCC][4] -= 40;
                CharacterStats[nCC][5] = 100;
                CharacterStats[nCC][6] += 50;
            }
            else if(CharacterInfo[nCC][2] == "Ancient")
            {
                CharacterStats[nCC][1] += 400;
                CharacterStats[nCC][2] -= 45;
                CharacterStats[nCC][3] -= 45;
                CharacterStats[nCC][4] += 90;
                CharacterStats[nCC][5] = 100;
                CharacterStats[nCC][6] += 400;
            }
}
