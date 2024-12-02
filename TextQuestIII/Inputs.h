#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED

#include"arenas.h"
#include"characters.h"

string UpShift(string input);
bool YesNo();
int NumChoice(int Choice);
void OpenWorldInput(string Input, int command[2]);
int TalkInput();

int BaseInput(character Player[], int nCC, int command[2]);
int TargetInput(int command[2], character Targets[]);
int ItemInput(int command[2], character Player[], int nCC, int TestType);
int InteractInput();
int MoveInput(arena Arena, int command[2]);
int EquipInput();
int SpellInput(int command[], int nCC, character Player[]);

#endif // INPUTS_H_INCLUDED
