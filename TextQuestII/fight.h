#ifndef FIGHT_H_INCLUDED
#define FIGHT_H_INCLUDED

int Fight(int CharacterStats[3][7], int CharacterInventory[3][14], string CharacterInfo[3][3], int Enemy[3][8], int Tutorial);
void RestoreHealth(int target, int restore, int CharacterStats[3][7], int Enemy[3][8], bool player);
void RestoreMagic(int nCC, int CharacterStats[3][7]);


#endif // FIGHT_H_INCLUDED
