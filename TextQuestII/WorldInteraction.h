#ifndef WORLDINTERACTION_H_INCLUDED
#define WORLDINTERACTION_H_INCLUDED

int Sneak(int CharacterStats[3][7], int CharacterInventory[3][14], int Enemy[3][8], int nCC);
int MoveTable();
int BlackKnightConv(string Screen[32], string CharacterInfo[3][3], int CharacterInventory[3][14], int nCC);
void CaveJourney(int CharacterStats[3][7], string CharacterInfo[3][3]);
void WarlockConv(string Screen[32], int BlackKnight, int CharacterStats[3][7]);
bool SpoonChest(int CharacterStats[3][7], int CharacterInventory[3][14], string CharacterInfo[3][3]);
void WizardConv(string Screen[32], int CharacterInventory[3][14], int nCC);
void AddPotions(int CharacterInventory[3][14], int CharacterStats[3][7]);

#endif // WORLDINTERACTION_H_INCLUDED
