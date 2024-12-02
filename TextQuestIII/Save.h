#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

void SaveWorld(int Party[3], int Stage, int ScreenType, bool CompletedQuests[]);
void LoadWorld(int Party[3], int &Stage, int &ScreenType, bool CompletedQuests[]);

#endif // SAVE_H_INCLUDED
