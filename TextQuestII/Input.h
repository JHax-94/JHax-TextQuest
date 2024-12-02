#include<string>

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

bool YesNo();
int HealTarget(int SpellType, int CharacterStats[3][7]);
int InputSpell(int nCC, string CharacterInfo[3][3]);
int InputTarget(int Enemy[3][8]);
int InputPotion(int nCC, int CharacterInventory[3][14]);
int WeaponInput(int nCC, int CharacterStats[3][7], int CharacterInventory[3][14]);
int CombineItemInput(int nCC, int CharacterInventory[3][14]);
string InputName();
string InputGender();
string InputRace();
void PickUp(int CharacterInventory[3][14], int RoomItems[14], int nCC);
int Input();

#endif // INPUT_H_INCLUDED
