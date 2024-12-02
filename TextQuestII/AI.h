#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED

int GetTarget(int nCC, int Enemy[3][8], int CharacterStats[3][7]);
int GetHealTarget(int nCC, int Enemy[3][8]);
int GetWeapon(int nCE, int Enemy[3][8]);
int GetSpell(int nCE, int Enemy[3][8]);
int AI(int Enemy[3][8], int nCE);

#endif // AI_H_INCLUDED
