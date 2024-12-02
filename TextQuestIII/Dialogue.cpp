#include <cstdlib>
#include <sstream>

using namespace std;

#include "Screens.h"
#include "Dialogue.h"
#include "Inputs.h"

void ClearRegion(string Screen[])
{
    for(int i = 21; i < 32; i ++)
    {
        Screen[i].replace(25, 54, "                                                      ");
    }
}

bool CheckQuest(character Player[], int nCC, int ChQuestID, int ChCurrentStage)
{
    bool QuestOn = false;

    if((Player[nCC].ActiveQuests[0].QuestID == ChQuestID && Player[nCC].ActiveQuests[0].CurrentStage == ChCurrentStage) ||
       (Player[nCC].ActiveQuests[1].QuestID == ChQuestID && Player[nCC].ActiveQuests[1].CurrentStage == ChCurrentStage) ||
       (Player[nCC].ActiveQuests[2].QuestID == ChQuestID && Player[nCC].ActiveQuests[2].CurrentStage == ChCurrentStage))
    {
        QuestOn = true;
    }

    return QuestOn;
}

int GetQuest(character Player[], int nCC, int ChQuestID)
{
    int QuInd;

    for(int i = 0; i < 3; i ++)
    {
        if(Player[nCC].ActiveQuests[i].QuestID == ChQuestID)
        {
            QuInd = i;
        }
    }

    return QuInd;
}

void WriteOptions(string Options[], int nOptions, string Screen[], int LastLine)
{
    for(int i = 0; i < nOptions; i ++)
    {
        stringstream convert;

        int StringLength = Options[i].length();
        int Index;
        Index = i+1;
        string sIndex;
        convert << Index;
        sIndex = convert.str();

        Screen[LastLine+2+i].replace(25, 4+StringLength, sIndex + " - " + Options[i]);
    }
}

void Talk(character Player[3], character NPC, string Screen[], int ID, int nCC, int ScreenType)
{
    int PlayerRaceID = Player[nCC].RaceID;
    int NPCRaceID = NPC.RaceID;
    int nOptions = 0;
    bool TalkOn = true;

    int Reg;
    int Twn;
    int Bld;

    int Index = 0;
    int NewIndex;
    int LastLine;

    int QuInd;

    string Options[10];
    int Indices[10];

    Player[nCC].GetLocation(Reg, Twn, Bld);

    if(PlayerRaceID == NPCRaceID)
    {
        NPCRaceID += 10;
    }

    while(TalkOn == true)
    {

        nOptions = 0;

        ClearRegion(Screen);

        if(ID == 3)
        {
            if(Index == 0)
            {
                Screen[21].replace(25, 43, "Captain Helx: Hello, what can I do for you?");

                LastLine = 21;

                Options[nOptions] = "Who are you?";
                Indices[nOptions] = 1;
                nOptions ++;

                if(Reg == 1 && Twn == 0 && Bld == 2)
                {
                    Options[nOptions] = "What is this place?";
                    Indices[nOptions] = 2;
                    nOptions ++;
                }
                if(CheckQuest(Player, nCC, 1, 0) == true)
                {
                    Options[nOptions] = "What do I need to do here?";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 4;
                    nOptions ++;
                }
                if(CheckQuest(Player, nCC, 1, 8) == true)
                {
                    Options[nOptions] = "What next, sir?";
                    Indices[nOptions] = 12;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 5;
                nOptions ++;



            }
            else if(Index == 1)
            {
                Screen[21].replace(25, 47, "Captain Helx: I'm in charge of recruitment for ");
                Screen[22].replace(25, 47, "The Order. I'll also be leading the expedition ");
                Screen[23].replace(25, 47, "to The Wastes.                                 ");
                LastLine = 23;

                if(Reg == 1 && Twn == 0 && Bld == 2)
                {
                    Options[nOptions] = "What is this place?";
                    Indices[nOptions] = 2;
                    nOptions ++;
                }
                if(CheckQuest(Player, nCC, 1, 0) == true)
                {
                    Options[nOptions] = "What do I need to do here?";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 4;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 5;
                nOptions ++;
            }
            else if(Index == 2)
            {
                Screen[21].replace(25, 47, "Captain Helx: This is The Order's training camp");
                Screen[22].replace(25, 47, "where all new recruits come to get assigned to ");
                Screen[23].replace(25, 47, "their units.                                   ");

                system("PAUSE");

                LastLine = 23;

                Options[nOptions] = "Who are you?";
                Indices[nOptions] = 1;
                nOptions ++;

                if(CheckQuest(Player, nCC, 1, 0) == true)
                {
                    Options[nOptions] = "What do I need to do here?";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 4;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 5;
                nOptions ++;
            }
            else if(Index == 3)
            {
                Screen[21].replace(25, 47, "Captain Helx: You need to sign up to join one  ");
                Screen[22].replace(25, 47, "of the 3 major units. Either frontline         ");
                Screen[23].replace(25, 47, "infantry, the rangers or the spellcasters.     ");


                //system("PAUSE");

                LastLine = 23;

                Options[nOptions] = "I want to be on the frontline!";
                Indices[nOptions] = 6;
                nOptions ++;

                Options[nOptions] = "I want to join the rangers!";
                Indices[nOptions] = 8;
                nOptions ++;

                Options[nOptions] = "I shall join the spellcasters!";
                Indices[nOptions] = 10;
                nOptions ++;

                Options[nOptions] = "I'm not ready to decide yet.";
                Indices[nOptions] = 0;
                nOptions ++;

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 5;
                nOptions ++;
            }
            else if(Index == 4)
            {
                cout << "Would you like to join me?\n\n";
                //system("PAUSE");

                LastLine = 21;

                Options[nOptions] = "Who are you?";
                Indices[nOptions] = 1;
                nOptions ++;

                if(Reg == 1 && Twn == 0 && Bld == 2)
                {
                    Options[nOptions] = "What is this place?";
                    Indices[nOptions] = 2;
                    nOptions ++;
                }
                if(CheckQuest(Player, nCC, 1, 0) == true)
                {
                    Options[nOptions] = "What do I need to do here?";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 5;
                nOptions ++;

            }
            else if(Index == 5)
            {
                TalkOn = false;
            }
            else if(Index == 6)
            {
                Screen[21].replace(25, 47, "Captain Helx: You'll want to talk to Gomlij    ");
                Screen[22].replace(25, 47, "Brokentooth over in the barracks.              ");

                LastLine = 22;

                Options[nOptions] = "Actually, I'm not so sure.";
                Indices[nOptions] = 3;
                nOptions ++;

                Options[nOptions] = "Yes sir!";
                Indices[nOptions] = 7;
                nOptions ++;

            }
            else if(Index == 7)
            {
                QuInd = GetQuest(Player, nCC, 1);

                Player[nCC].ActiveQuests[QuInd].NextStage(1);

                TalkOn = false;
            }
            else if(Index == 8)
            {
                Screen[21].replace(25, 47, "Captain Helx: Go and talk to Elsi Swifteye over");
                Screen[22].replace(25, 47, "at the archery range. Best keep you're head    ");
                Screen[23].replace(25, 47, "down, we've got recruits in today.             ");

                LastLine = 23;

                Options[nOptions] = "Actually, I'm not so sure.";
                Indices[nOptions] = 3;
                nOptions ++;

                Options[nOptions] = "Yes sir!";
                Indices[nOptions] = 9;
                nOptions ++;
            }
            else if(Index == 9)
            {
                QuInd = GetQuest(Player, nCC, 1);
                Player[nCC].ActiveQuests[QuInd].NextStage(2);
                TalkOn = false;
            }
            else if(Index == 10)
            {
                Screen[21].replace(25, 47, "Captain Helx: Talk to Battlemage Lucius over   ");
                Screen[22].replace(25, 47, "at the Wizard's Tower. The arch mage doesn't   ");
                Screen[23].replace(25, 47, "deal with recruits.                            ");

                LastLine = 23;

                Options[nOptions] = "Actually, I'm not so sure.";
                Indices[nOptions] = 3;
                nOptions ++;

                Options[nOptions] = "Yes sir!";
                Indices[nOptions] = 11;
                nOptions ++;
            }
            else if(Index == 11)
            {

                QuInd = GetQuest(Player, nCC, 1);

                Player[nCC].ActiveQuests[QuInd].NextStage(3);

                TalkOn = false;
            }
            else if(Index == 12)
            {
                Screen[21].replace(25, 47, "Captain Helx: Looks like you're ready for some ");
                Screen[22].replace(25, 47, "combat training! Go and fight the training     ");
                Screen[23].replace(25, 47, "dummy!                                         ");

                LastLine = 23;

                Options[nOptions] = "Yes sir!";
                Indices[nOptions] = 13;
                nOptions ++;
            }
            else if(Index == 13)
            {
                QuInd = GetQuest(Player, nCC, 1);

                Player[nCC].ActiveQuests[QuInd].NextStage(9);
            }

           // cout << Screen[21] << endl << endl;

          //  system("PAUSE");

        }
        else if(ID == 4)
        {
            if(Index == 0)
            {
                Screen[21].replace(25, 47, "Gomlij Brokentooth: Greetings, what do you want");
                Screen[22].replace(25, 47, "from me?                                       ");

                LastLine = 22;

                Options[nOptions] = "Who are you?";
                Indices[nOptions] = 1;
                nOptions ++;

                if(Reg == 1 && Twn == 0 && Bld == 2)
                {
                    Options[nOptions] = "What is this place?";
                    Indices[nOptions] = 2;
                    nOptions ++;
                }
                if(CheckQuest(Player, nCC, 1, 1) == true)
                {
                    Options[nOptions] = "I want to be on the frontline.";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 4;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 5;
                nOptions ++;
            }
            else if(Index == 1)
            {
                Screen[21].replace(25, 47, "Gomlij Brokentooth: I'm a veteran of The Order.");
                Screen[22].replace(25, 47, "I've been called back into service because I   ");
                Screen[23].replace(25, 47, "spent my youth as part of a group of Orcs that ");
                Screen[24].replace(25, 47, "scouted The Wastes.                            ");

                LastLine = 24;

                if(Reg == 1 && Twn == 0 && Bld == 2)
                {
                    Options[nOptions] = "What is this place?";
                    Indices[nOptions] = 2;
                    nOptions ++;
                }
                if(CheckQuest(Player, nCC, 1,1))
                {
                    Options[nOptions] = "I want to be on the frontline.";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 4;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 5;
                nOptions ++;
            }
            else if(Index == 2)
            {
                Screen[21].replace(25, 47, "Gomlij Brokentooth: You're in the barracks.    ");
                Screen[22].replace(25, 47, "We toughen people up so their ready to face the");
                Screen[23].replace(25, 47, "Reidlos in battle.                             ");

                LastLine = 23;

                Options[nOptions] = "Who are you?";
                Indices[nOptions] = 1;
                nOptions ++;

                if(CheckQuest(Player, nCC, 1, 1) == true)
                {
                    Options[nOptions] = "I want to be on the frontline.";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 4;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 5;
                nOptions ++;
            }
            else if(Index == 3)
            {
                Screen[21].replace(25, 47, "Gomlij Brokentooth: Hmm, you don't look so     ");
                Screen[22].replace(25, 47, "tough. Best see Asdodsaodo, he'll get you      ");
                Screen[23].replace(25, 47, "kitted out.                                    ");

                LastLine = 23;

                Options[nOptions] = "Yes sir!";
                Indices[nOptions] = 6;
                nOptions ++;
            }
            else if(Index == 4)
            {

            }
            else if(Index == 5)
            {
                TalkOn = false;
            }
            else if(Index == 6)
            {
                QuInd = GetQuest(Player, nCC, 1);
                Player[nCC].ActiveQuests[QuInd].NextStage(4);
                TalkOn = false;
            }

        }
        else if(ID == 5)
        {
            if(Index == 0)
            {
                Screen[21].replace(25, 47, "Elsi Swifteye: Hello, what is it you seek?     ");

                LastLine = 21;

                Options[nOptions] = "Who are you?";
                Indices[nOptions] = 1;
                nOptions ++;

                if(Reg == 1 && Twn == 0 && Bld == 2)
                {
                    Options[nOptions] = "What is this place?";
                    Indices[nOptions] = 2;
                    nOptions ++;
                }
                if(CheckQuest(Player, nCC, 1, 2) == true)
                {
                    Options[nOptions] = "I want to join the rangers.";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 4;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 5;
                nOptions ++;
            }
            else if(Index == 1)
            {
                Screen[21].replace(25, 47, "Elsi Swifteye: I'm a huntress from the forests ");
                Screen[22].replace(25, 47, "of Lupescria. My quarry never escapes. My      ");
                Screen[23].replace(25, 47, "marksmanship is of great value to The Order so ");
                Screen[24].replace(25, 47, "I have been called to fight.                   ");

                LastLine = 24;

                if(Reg == 1 && Twn == 0 && Bld == 2)
                {
                    Options[nOptions] = "What is this place?";
                    Indices[nOptions] = 2;
                    nOptions ++;
                }
                if(CheckQuest(Player, nCC, 1, 2) == true)
                {
                    Options[nOptions] = "I want to join the rangers.";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 4;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 5;
                nOptions ++;
            }
            else if(Index == 2)
            {
                Screen[21].replace(25, 47, "Elsi Swifteye: This is the archery range, we   ");
                Screen[22].replace(25, 47, "train all missile troops here, but we're only  ");
                Screen[23].replace(25, 47, "looking for archers at the moment.             ");

                LastLine = 23;

                Options[nOptions] = "Who are you?";
                Indices[nOptions] = 1;
                nOptions ++;

                if(CheckQuest(Player, nCC, 1, 2) == true)
                {
                    Options[nOptions] = "I want to join the rangers.";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 4;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 5;
                nOptions ++;
            }
            else if(Index == 3)
            {
                Screen[21].replace(25, 47, "Elsi Swifteye: My lieutenant, Crunch Byte will ");
                Screen[22].replace(25, 47, "supply you with all you need.                  ");

                LastLine = 22;

                Options[nOptions] = "Yes ma'am!";
                Indices[nOptions] = 6;
                nOptions ++;
            }
            else if(Index == 4)
            {

            }
            else if(Index == 5)
            {
                TalkOn = false;
            }
            else if(Index == 6)
            {
                QuInd = GetQuest(Player, nCC, 1);
                Player[nCC].ActiveQuests[QuInd].NextStage(5);

                TalkOn = false;
            }
        }
        else if(ID == 6)
        {
            if(Index == 0)
            {
                Screen[21].replace(25, 47, "Battlemage Lucius: What do you want? I'm a busy");
                Screen[22].replace(25, 47, "man.                                           ");

                LastLine = 22;

                Options[nOptions] = "Who are you?";
                Indices[nOptions] = 1;
                nOptions ++;

                if(Reg == 1 && Twn == 0 && Bld == 2)
                {
                    Options[nOptions] = "What is this place?";
                    Indices[nOptions] = 2;
                    nOptions ++;
                }
                if(CheckQuest(Player, nCC, 1, 3) == true)
                {
                    Options[nOptions] = "I want to be a spellcaster.";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 4;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 5;
                nOptions ++;
            }
            else if(Index == 1)
            {
                Screen[21].replace(25, 47, "Battlemage Lucius: I'm a battlemage, and I'm   ");
                Screen[22].replace(25, 47, "far too busy for idle chit chat. Hurry it up.  ");

                LastLine = 22;

                if(Reg == 1 && Twn == 0 && Bld == 2)
                {
                    Options[nOptions] = "What is this place?";
                    Indices[nOptions] = 2;
                    nOptions ++;
                }
                if(CheckQuest(Player, nCC, 1, 3) == true)
                {
                    Options[nOptions] = "I want to be a spellcaster.";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 4;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 5;
                nOptions ++;
            }
            else if(Index == 2)
            {
                Screen[21].replace(25, 47, "Battlemage Lucius: This is the Wizard's Tower  ");
                Screen[22].replace(25, 47, "a store of The Order's knowledge, and a place  ");
                Screen[23].replace(25, 47, "for mages to refine their skills.              ");

                LastLine = 23;

                Options[nOptions] = "Who are you?";
                Indices[nOptions] = 1;
                nOptions ++;

                if(CheckQuest(Player, nCC, 1, 3) == true)
                {
                    Options[nOptions] = "I want to be a spellcaster.";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 4;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 5;
                nOptions ++;
            }
            else if(Index == 3)
            {
                Screen[21].replace(25, 47, "Battlemage Lucius: Go and see Illuvia Fuviel,  ");
                Screen[22].replace(25, 47, "she'll get you your robes and staff.           ");

                LastLine = 22;

                Options[nOptions] = "Yes sir!";
                Indices[nOptions] = 6;
                nOptions ++;
            }
            else if(Index == 4)
            {

            }
            else if(Index == 5)
            {
                TalkOn = false;
            }
            else if(Index == 6)
            {
                QuInd = GetQuest(Player, nCC, 1);
                Player[nCC].ActiveQuests[QuInd].NextStage(6);

                TalkOn = false;
            }
        }
        else if(ID == 7)
        {
            if(Index == 0)
            {
                Screen[21].replace(25, 47, "Asdodsaodo: What do you want? Huh?             ");

                LastLine = 21;

                Options[nOptions] = "Who are you?";
                Indices[nOptions] = 1;
                nOptions ++;

                if(CheckQuest(Player, nCC, 1, 4) == true)
                {
                    Options[nOptions] = "Gomlij Brokentooth sent me.";
                    Indices[nOptions] = 2;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 4;
                nOptions ++;
            }
            else if(Index == 1)
            {
                Screen[21].replace(25, 47, "Asdodsoado: I am Asdodsaodo, honoured with the ");
                Screen[22].replace(25, 47, "rank of chief outfitter for the frontline      ");
                Screen[23].replace(25, 47, "soldiers of the order! None can match the skill");
                Screen[24].replace(25, 47, "with which I supply weapons and armour.        ");

                LastLine = 24;

                if(CheckQuest(Player, nCC, 1, 4) == true)
                {
                    Options[nOptions] = "Gomlij Brokentooth sent me.";
                    Indices[nOptions] = 2;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 4;
                nOptions ++;
            }
            else if(Index == 2)
            {
                Screen[21].replace(25, 47, "Asdodsaodio: Uh...right. Here you are, standard");
                Screen[22].replace(25, 47, "issue Order Heavy Armour and your sword!       ");

                LastLine = 22;

                Player[nCC].AddWeapon(IronSword);
                Player[nCC].AddArmour(OrderRecruitPlate);

                Options[nOptions] = "Thank you!";
                Indices[nOptions] = 5;
                nOptions ++;
            }
            else if(Index == 3)
            {

            }
            else if(Index == 4)
            {
                TalkOn = false;
            }
            else if(Index == 5)
            {
                QuInd = GetQuest(Player, nCC, 1);
                Player[nCC].ActiveQuests[QuInd].NextStage(7);
                TalkOn = false;
            }
        }
        else if(ID == 8)
        {
            if(Index == 0)
            {
                Screen[21].replace(25, 47, "Crunch Byte: How can I help?                   ");

                LastLine = 21;

                Options[nOptions] = "Who are you?";
                Indices[nOptions] = 1;
                nOptions ++;

                if(CheckQuest(Player, nCC, 1, 5) == true)
                {
                    Options[nOptions] = "Huntress Swifteye sent me.";
                    Indices[nOptions] = 2;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 4;
                nOptions ++;
            }
            else if(Index == 1)
            {
                Screen[21].replace(25, 47, "Crunch Byte: I'm huntress Swifteye's protege.  ");
                Screen[22].replace(25, 47, "I'm an expert in trapping and brewing poisons. ");

                LastLine = 22;

                if(CheckQuest(Player, nCC, 1, 5) == true)
                {
                    Options[nOptions] = "Huntress Swifteye sent me.";
                    Indices[nOptions] = 2;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 4;
                nOptions ++;
            }
            else if(Index == 2)
            {
                Screen[21].replace(25, 47, "Crunch Byte: Of course, have some standard     ");
                Screen[22].replace(25, 47, "light armour. You'll have to take a hunting bow");
                Screen[23].replace(25, 47, "the military grade ones ran out on our last    ");
                Screen[24].replace(25, 37, "recruitment drive.                             ");

                LastLine = 24;

                Player[nCC].AddWeapon(HunterBow);
                Player[nCC].AddArmour(OrderChainMail);

                Options[nOptions] = "Thank you!";
                Indices[nOptions] = 5;
                nOptions ++;
            }
            else if(Index == 3)
            {

            }
            else if(Index == 4)
            {
                TalkOn = false;
            }
            else if(Index == 5)
            {
                QuInd = GetQuest(Player, nCC, 1);
                Player[nCC].ActiveQuests[QuInd].NextStage(7);

                TalkOn = false;
            }
        }
        else if(ID == 9)
        {
            if(Index == 0)
            {
                Screen[21].replace(25, 47, "Illuvia Fuviel: Ah, hello, what can I do to    ");
                Screen[22].replace(25, 47, "help?                                          ");

                LastLine = 22;

                Options[nOptions] = "Who are you?";
                Indices[nOptions] = 1;
                nOptions ++;

                if(CheckQuest(Player, nCC, 1, 6) == true)
                {
                    Options[nOptions] = "I'm here on the Battlemage's orders.";
                    Indices[nOptions] = 2;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 4;
                nOptions ++;
            }
            else if(Index == 1)
            {
                Screen[21].replace(25, 47, "Illuvia Fuviel: I'm an apprentive spellcaster, ");
                Screen[22].replace(25, 47, "but I specialise in enchantment, most of the   ");
                Screen[23].replace(25, 47, "robes for the recruits were enchanted by me.   ");

                LastLine = 23;

                if(CheckQuest(Player, nCC, 1, 5) == true)
                {
                    Options[nOptions] = "I'm here on the Battlemage's Orders.";
                    Indices[nOptions] = 2;
                    nOptions ++;
                }
                if(NPC.Disposition >= 80)
                {
                    Options[nOptions] = "Would you like join me?";
                    Indices[nOptions] = 3;
                    nOptions ++;
                }

                Options[nOptions] = "Goodbye!";
                Indices[nOptions] = 4;
                nOptions ++;
            }
            else if(Index == 2)
            {
                Screen[21].replace(25, 47, "Illuvia Fuviel: I see, well, here are your     ");
                Screen[22].replace(25, 47, "robes and wizard's staff.                      ");

                LastLine = 22;

                Player[nCC].AddWeapon(BasicStaff);
                Player[nCC].AddArmour(ApprenticeRobes);

                Options[nOptions] = "Thank you!";
                Indices[nOptions] = 5;
                nOptions ++;
            }
            else if(Index == 3)
            {

            }
            else if(Index == 4)
            {
                TalkOn = false;
            }
            else if(Index == 5)
            {
                QuInd = GetQuest(Player, nCC, 1);
                Player[nCC].ActiveQuests[QuInd].NextStage(7);

                TalkOn = false;
            }

        }



        if(TalkOn == true)
        {

            WriteOptions(Options, nOptions, Screen, LastLine);
            RedrawScreen(Screen, ScreenType, Player, nCC);

            NewIndex = TalkInput();

            Index = Indices[NewIndex];
        }
        //system("PAUSE");
        //TalkOn = false;
    }
    if(PlayerRaceID == NPCRaceID)
    {
        NPCRaceID -= 10;
    }

}
