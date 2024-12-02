#ifndef BATTLECOMMANDS_H_INCLUDED
#define BATTLECOMMANDS_H_INCLUDED

int Attack(bool player, int nCC, int CharacterStats[3][7], int CharacterInventory[3][14], int Enemy[3][8]);
int CastAttack(bool player, int SpellType, int nCC, int CharacterStats[3][7], int CharacterInventory[3][14], int Enemy[3][8]);
int CastHeal(int nCC, int SpellType, int CharacterStats[3][7], int CharacterInventory[3][14], int Enemy[3][8], bool player);
int Use(int nCC, int CharacterInventory[3][14]);
int Defend(bool player, int nCC, int CharacterStats[3][7], int Enemy[3][8]);

#endif // BATTLECOMMANDS_H_INCLUDED
