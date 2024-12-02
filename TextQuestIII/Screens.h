#ifndef SCREENS_H_INCLUDED
#define SCREENS_H_INCLUDED

#include"characters.h"
#include"arenas.h"

int CountAlive(character TestParty[3]);
void DrawScreen(string Screen[], int ScreenSize);
void DrawScreen(string Heading, string Screen[], int ScreenSize);
void DrawScreen(string Heading, string SubHeading, string Screen[], int ScreenSize);
void DrawScreen(string Heading, string SubHeading, string Screen[], int ScreenSize, bool compass);
void DrawScreen(string Heading, string SubHeading, string Screen[], string Name, int ScreenSize, bool compass);
void ClearScreen(string Screen[], int ScreenSize);
void ClearScreen(string Screen[], int Start, int Finish);
void OpenWorldScreen(string Screen[], int ScreenType, character Player[], int nCC);
void RedrawScreen(string Screen[], int ScreenType, character Player[], int nCC);
void FightScreen(character Player[], character Enemy[], arena Arena, int nCC, bool PlayerOn, int command[2]);

#endif // SCREENS_H_INCLUDED
