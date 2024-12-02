#ifndef SCREENS_H_INCLUDED
#define SCREENS_H_INCLUDED

void AddCharacter(string CharacterInfo[3][3], int nCC, string Screen[]);
void EmptyScreen(string Screen[]);
void drawScreen(string Screen[], int ScreenSize);
void fightScreen(string CharacterInfo[3][3], int CharacterStats[3][7], int Enemy[3][8], int Turn);


#endif // SCREENS_H_INCLUDED
