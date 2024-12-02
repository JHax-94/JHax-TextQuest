#ifndef QUESTS_H_INCLUDED
#define QUESTS_H_INCLUDED

#include <string>

class quest
{
    public:

    int QuestID;
    int CurrentStage;
    int TotalStages;
    string QuestName;
    string ** Messages;




    quest()
    {
        QuestID = -1;
        CurrentStage = 0;
        TotalStages = 1;
        QuestName = "None";
        Messages = new string*[1];
        Messages[0] = new string[3];
        Messages[0][0] = " ";
        Messages[0][1] = " ";
        Messages[0][2] = " ";
    }

    quest(int NewQuestID, int NewStage, int NewTotalStage, string NewQuestName, string NewMessages[][3])
    {
        QuestID = NewQuestID;
        CurrentStage = NewStage;
        TotalStages = NewTotalStage;
        QuestName = NewQuestName;
        Messages = new string*[NewTotalStage];

        for(int i = 0; i < TotalStages; i ++)
        {
            Messages[i] = new string[3];

            Messages[i][0] = NewMessages[i][0];
            Messages[i][1] = NewMessages[i][1];
            Messages[i][2] = NewMessages[i][2];
        }
    }

    quest operator= (const quest& OldQuest)
    {
        QuestID = OldQuest.QuestID;
        CurrentStage = OldQuest.CurrentStage;
        TotalStages = OldQuest.TotalStages;
        QuestName = OldQuest.QuestName;
        Messages = new string*[TotalStages];


        for(int i = 0; i < TotalStages; i ++)
        {
            Messages[i] = new string[3];

            Messages[i][0] = OldQuest.Messages[i][0];
            Messages[i][1] = OldQuest.Messages[i][1];
            Messages[i][2] = OldQuest.Messages[i][2];
        }

        return *this;
    }

    void Reward();

    void WriteStage(string Screen[], int Line);

    void NextStage(int NewStage);

};

extern quest NullQuests[3];

extern quest SigningUp;

extern bool CompletedQuests[1];



#endif // QUESTS_H_INCLUDED
