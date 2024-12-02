using namespace std;

#include "quests.h"

bool CompletedQuests[1];


string SigningUpMessages[10][3] =
{
    {"Use the Talk # command to talk to Captain Helx.", " "},  // 0
    {"Talk to Gomlij Brokentooth at the barracks.", "Get to the barracks using Go #.", " "},      // 1
    {"Talk to Elsi Swifteye at the archery range.", "Get to the archery range using Go #.", " "},      // 2
    {"Talk to Battlemage Lucius at the wizard's tower.", "Get to the wizard's tower using Go #.", " "}, // 3
    {"Get equipment from Asdodsaodo."},                   // 4
    {"Get equipment from Crunch Byte."},                  // 5
    {"Get equipment from Illuvia Fuviel."},               // 6
    {"Go to Inventory and equip new weapons and armour.", "Type Inventory to go to your inventory.", "Use the Equip # command."},// 7
    {"Return to the training camp and talk to Helx.", " ", " "},    // 8
    {"Use the Fight # command to attack the Dummy.", " ", " "}      // 9
};

quest SigningUp(1, 0, 10, "Signing Up: ", SigningUpMessages);

quest NullQuests[3] =
{
    quest(),
    quest(),
    quest()
};


void quest::Reward()
{
    if(QuestID == 1)
    {
        CompletedQuests[0] = true;
    }
}


void quest::WriteStage(string Screen[], int Line)
{
    int NameLength = QuestName.length();
    int MessageLength;
    Screen[Line].replace(0, NameLength, QuestName);

    for(int i = 0; i < 3; i ++)
    {
        MessageLength = Messages[CurrentStage][i].length();
        Screen[Line+1+i].replace(0, MessageLength, Messages[CurrentStage][i]);
    }
}

void quest::NextStage(int NewStage)
{
    CurrentStage = NewStage;
}

