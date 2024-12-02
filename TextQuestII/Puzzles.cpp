#include<string>
#include<iostream>
#include<cstdlib>

using namespace std;

#include"screens.h"

int Riddle0(string Screen[32])
{
    string answer;

    int result = 0;
    bool Loop;
    int stringLength;
    int i;

    system("CLS");

    Screen[2] = "===============================SIDE ROOM==========RIDDLE WALL==========S=======\n";
    Screen[3] = "                                                                               \n";
    Screen[4] = "  A voice calls out to you from the diresction of the wall. It sounds as if    \n";
    Screen[5] = "  says:                                                                        \n";
    Screen[6] = "                                                                               \n";
    Screen[7] = "                        'What serves but also deserts?'                        \n";
    Screen[8] = "                                                                               \n";
    Screen[9] = "              Speak the answer to reveal the secret of this wall...            \n";
    Screen[10]= "                                                                               \n";
    Screen[11]= "                                                                               \n";
    Screen[12]= "                                                                               \n";
    Screen[13]= "                                                                               \n";
    Screen[14]= "                                                                               \n";
    Screen[15]= "                                                                               \n";

    drawScreen(Screen, 32);

    Loop = true;
    while(Loop == true)
    {
        cin.sync();

        getline(cin, answer);

        stringLength = answer.length();

        for(i = 0; i < stringLength; i ++)
        {
            answer.at(i) = toupper(answer.at(i));
        }
        if(answer == "A SPOON")
        {
            result = 1;
            Loop = false;
        }
        else if(answer == "SPOON")
        {
            result = 1;
            Loop = false;
        }
        else if(answer == "A DUCK")
        {
            cout << "She's a witch!\nNothing happens...\n";
        }
        else if(answer == "GIVE UP")
        {
            Loop = false;
        }
        else
        {
            cout << "Nothing happens...\n";
        }
    }
    return result;
}

bool Riddle1(string Screen[32])
{
    string answer;

    bool success = false;
    bool Loop;

    int i;
    int stringLength;

    Screen[2]  = "===============================DEAD END===========RIDDLE WALL==========S=======\n";
    Screen[3]  = "                                                                               \n";
    Screen[4]  = "                                                                               \n";
    Screen[5]  = "         A MAN POINTS TO A PAINTING OF HIS FAMILY AND SAYS:                    \n";
    Screen[6]  = "                                                                               \n";
    Screen[7]  = "              'BROTHERS AND SISTERS HAVE I NONE, BUT THIS MAN'S FATHER         \n";
    Screen[8]  = "                              IS MY FATHER'S SON.'                             \n";
    Screen[9]  = "                                                                               \n";
    Screen[10] = "  Speak who the man points to in order to know the secrets of this wall...     \n";
    Screen[11] = "                                                                               \n";
    Screen[12] = "                                                                               \n";
    Screen[13] = "                                                                               \n";
    Screen[14] = "                                                                               \n";
    Screen[15] = "                                                                               \n";

    Loop = true;

    while(Loop == true)
    {
        drawScreen(Screen, 32);

        cout << "What is your response? ";

        cin.sync();

        getline(cin, answer);

        stringLength = answer.length();

        for(i = 0; i < stringLength; i ++)
        {
            answer.at(i) = toupper(answer.at(i));
        }

        if(answer == "HIM" || answer == "HIMSELF")
        {
            success = true;
            Loop = false;
        }
        else if(answer == "GIVE UP")
        {
            Loop = false;
        }
        else
        {
            cout << "The wall does not react...\n\n";
            system("PAUSE");
        }
    }




    return success;
}

bool Riddle2(string Screen[32])
{
    string answer;

    bool success = false;
    bool Loop;

        int i;
    int stringLength;

    Screen[2]  = "=============================ANTE CHAMBER=========RIDDLE WALL==========S=======\n";
    Screen[3]  = "                                                                               \n";
    Screen[4]  = "                                                                               \n";
    Screen[5]  = "                 WHAT IS IN LIGHTNING, A ROAD AND ON A TABLE?                  \n";
    Screen[6]  = "                                                                               \n";
    Screen[7]  = "                                                                               \n";
    Screen[8]  = "  Speak the answer to know the secrets of this wall...                         \n";
    Screen[9]  = "                                                                               \n";
    Screen[10] = "                                                                               \n";
    Screen[11] = "                                                                               \n";
    Screen[12] = "                                                                               \n";
    Screen[13] = "                                                                               \n";
    Screen[14] = "                                                                               \n";
    Screen[15] = "                                                                               \n";

    Loop = true;

    while(Loop == true)
    {
        drawScreen(Screen, 32);

        cout << "What is your response? ";

        cin.sync();

        getline(cin, answer);

        stringLength = answer.length();

        for(i = 0; i < stringLength; i ++)
        {
            answer.at(i) = toupper(answer.at(i));
        }

        if(answer == "FORK" || answer == "A FORK")
        {
            success = true;
            Loop = false;
        }
        else if(answer == "GIVE UP")
        {
            Loop = false;
        }
        else
        {
            cout << "The wall does not react...\n\n";
            system("PAUSE");
        }
    }


    Screen[2]  = "=============================ANTE CHAMBER==============================S=======\n";
    Screen[3]  = "                                                                               \n";
    Screen[4]  = "                                                                               \n";
    Screen[5]  = "                                                                               \n";
    Screen[6]  = "                                                                               \n";
    Screen[7]  = "                                                                               \n";
    Screen[8]  = "                                                                               \n";
    Screen[9]  = "                                                                               \n";
    Screen[10] = "                                                                               \n";

    return success;
}






int Puzzle0(string Screen[32], string CharacterInfo[3][3], int CharacterStats[3][7])
{
    bool Loop;
    bool SecondLoop;

    int result = 0;
    int i;
    int stringLength;
    int nCC;
    string numeral;
    string name;

    system("CLS");

    Screen[2] =  "===============================SIDE ROOM==========PUZZLE WALL==========S=======\n";
    Screen[3] =  "                                                                               \n";
    Screen[4] =  "                                             ____                              \n";
    Screen[5] =  "                          I I II III V VIII |____|                             \n";
    Screen[6] =  "                                                                               \n";
    Screen[7] =  "                                                                               \n";
    Screen[8] =  "                 Carve the next numeral into the wall...                       \n";
    Screen[9] =  "                                                                               \n";
    Screen[10] = "                                                                               \n";
    Screen[11] = "                                                                               \n";
    Screen[12] = "                                                                               \n";
    Screen[13] = "                                                                               \n";
    Screen[14] = "                                                                               \n";
    Screen[15] = "                                                                               \n";

    Loop = true;

    while(Loop == true)
    {
        drawScreen(Screen, 32);

        cin.sync();

        getline(cin, numeral);

        stringLength = numeral.length();

        for(i = 0; i < stringLength; i ++)
        {
            numeral.at(i) = toupper(numeral.at(i));
        }

        if(numeral == "XIII")
        {
            result = 1;

            Screen[5].replace(45, 4, "XIII");

            Screen[10] = " The inscription on the wall glows a deep red and begins to morph...           \n";

            drawScreen(Screen, 32);

            system("PAUSE");

            Screen[8]  = "    The wisdom hidden behind this wall can only be gained by one person. The   \n";
            Screen[9]  = "              wall will move when only one person remains.                     \n";

            Screen[10] = "                                                                               \n";

            drawScreen(Screen, 32);

            cout << "Please type the name of the character you want to stay: ";

            SecondLoop = true;

            while(SecondLoop == true)
            {
                cin.sync();

                getline(cin, name);

                if(name == CharacterInfo[0][0])
                {
                    if(CharacterStats[0][0] != 0)
                    {
                        nCC = 0;
                        Loop = false;
                        SecondLoop = false;
                    }
                    else
                    {
                        cout << "This character is dead!\n";
                        cout << "Please enter again: ";
                    }
                }
                else if(name == CharacterInfo[1][0])
                {
                    if(CharacterStats[1][0] != 0)
                    {
                        nCC = 1;
                        Loop = false;
                        SecondLoop = false;
                    }
                    else
                    {
                        cout << "This character is dead!\n";
                        cout << "Please enter again: ";
                    }
                }
                else if(name == CharacterInfo[2][0])
                {
                    if(CharacterStats[2][0] != 0)
                    {
                        nCC = 2;
                        Loop = false;
                        SecondLoop = false;
                    }
                    else
                    {
                        cout << "This character is dead!\n";
                        cout << "Please enter again: ";
                    }
                }
                else
                {
                    cout << "This is not one of your characters.\n";
                    cout << "Please enter again: ";
                }
            }

                Screen[8] =  "  The rest of the party leave the room...                                      \n";
                Screen[9] =  "                                                                               \n";
                Screen[10] = "  The wall moves to reveal a scroll.            walks up to it and begins to   \n";
                Screen[11] = "  read it. Whilst reading            feels infused with a great power.         \n";

                stringLength = CharacterInfo[nCC][0].length();

                Screen[10].replace(37, stringLength, CharacterInfo[nCC][0]);
                Screen[11].replace(21, stringLength, CharacterInfo[nCC][0]);

                drawScreen(Screen, 32);

                CharacterStats[nCC][4] += 15;

                system("PAUSE");

                Screen[8] = "                turns to leave the secret room and follows the group back to   \n";
                Screen[9] = "            the main corridor.                                                 \n";
                Screen[10]= "                                                                               \n";
                Screen[11]= "                                                                               \n";

                Screen[8].replace(2, 10, CharacterInfo[nCC][0]);

                drawScreen(Screen, 32);

                system("PAUSE");

                Loop = false;
        }
        else if(numeral == "GIVE UP")
        {
            Loop = false;
        }
        else
        {
            Screen[10] =  " The inscription on the wall glows a deep red and begins to morph...           \n";

            drawScreen(Screen, 32);

            system("PAUSE");

            Screen[11] = " The numeral you carved fades away into the wall and nothing else happens.     \n";

            drawScreen(Screen, 32);

            system("PAUSE");

            Screen[10] = "                                                                               \n";
            Screen[11] = "                                                                               \n";

        }
    }

    Screen[2] = "===============================SIDE ROOM===============================S=======\n";
    Screen[3] = "                                                                               \n";
    Screen[4] = "                                                                               \n";
    Screen[5] = "                                                                               \n";
    return result;
}

bool Puzzle1(string Screen[32])
{
    bool success = false;
    bool GiveUp = false;
    bool Loop;

    int StringLength;
    int i;

    string sA;
    string sB;
    string sC;
    string sD;

    Screen[2]  = "============================SIDE ROOM============PUZZLE WALL===========S=======\n";
    Screen[3]  = "                                                                               \n";
 // Screen[4]  = "               THE SPOON WILL END ALL THAT BEGAN WITH THE SWORD                \n";
 // Screen[4]  = "               THS EPOON WILL SND ALL THAT BEGAN WITH THS EWORD                \n";
    Screen[4]  = "               OHS EPTTN WILL SND ALL OHAO BEGAN WIOH OHS EWTRD                \n";
    Screen[5]  = "                                                                               \n";
    Screen[6]  = "                    Carve two pairs of letters to swap...                      \n";
    Screen[7]  = "                                                                               \n";
    Screen[8]  = "                                                                               \n";
    Screen[9]  = "                                                                               \n";
    Screen[10] = "                                                                               \n";
    Screen[11] = "                                                                               \n";
    Screen[12] = "                                                                               \n";
    Screen[13] = "                                                                               \n";
    Screen[14] = "                                                                               \n";
    Screen[15] = "                                                                               \n";


    Loop = true;

    while(Loop == true)
    {
        drawScreen(Screen, 32);

        cin.sync();

        cout << "Carve a letter: ";

        getline(cin, sA);

        StringLength = sA.length();

        for(i = 0; i < StringLength; i ++)
        {
            sA.at(i) = toupper(sA.at(i));
        }

        if(sA == "T" || sA == "E" || sA == "O" || sA == "S")
        {
            cin.sync();

            cout << "Carve the letter you wish to swap this with: ";

            getline(cin, sB);

            StringLength = sB.length();

            for(i = 0; i < StringLength; i ++)
            {
                sB.at(i) = toupper(sB.at(i));
            }

            if((sA == "T" && sB == "O") || (sA == "O" && sB == "T"))
            {
                Screen[4] = "               THS EPOON WILL SND ALL THAT BEGAN WITH THS EWORD                \n";

                Loop = false;
            }
            else if((sA == "E" && sB == "S") || (sA == "S" && sB == "E"))
            {
                Screen[4]  = "               OHE SPTTN WILL END ALL OHAO BEGAN WIOH OHE SWTRD                \n";

                Loop = false;
            }
            else if(sB == "GIVE UP")
            {
                GiveUp = true;
                Loop = false;
            }
            else
            {
                cout << "\n\nThe letters you carved glow for a moment then disappear.\n\n";
                system("PAUSE");
            }
        }
        else if(sA == "GIVE UP")
        {
            GiveUp = true;
            Loop = false;
        }
        else
        {
            cout << "\n\nThe letter you carved glows for a moment then disappears.\n\n";
            system("PAUSE");
        }
    }

    if(GiveUp == false)
    {
        Loop = true;

        while(Loop == true)
        {

            drawScreen(Screen, 32);

            cin.sync();

            cout << "Carve a letter: ";

            getline(cin, sC);

            StringLength = sC.length();

            for(i = 0; i < StringLength; i ++)
            {
                sC.at(i) = toupper(sC.at(i));
            }

            if(((sA == "T" || sA == "O") && (sC == "E" || sC == "S")) || ((sA == "E" || sA == "S") && (sC == "T" || sC == "S")))
            {
                cin.sync();

                cout << "Carve the letter you wish to swap this with: ";

                getline(cin, sD);
                StringLength = sD.length();

                for(i = 0; i < StringLength; i ++)
                {
                    sD.at(i) = toupper(sD.at(i));
                }
                if(((sC == "E" && sD == "S") || (sC == "S" && sD == "E")) || ((sC == "T" && sD == "O") || (sC == "O" && sD == "T")))
                {
                    Screen[4]  = "               THE SPOON WILL END ALL THAT BEGAN WITH THE SWORD                \n";

                    system("PAUSE");

                    Loop = false;
                    success = true;

                }
                else if(sD == "GIVE UP")
                {
                    GiveUp = true;
                    Loop = false;
                }
                else
                {
                    cout << "\n\nThe letters you carved glow for a moment then disappear.\n\n";
                    system("PAUSE");
                }
            }
            else if(sC == "GIVE UP")
            {
                GiveUp = true;
                Loop = false;
            }
            else
            {
                cout << "\n\nThe letter you carved glows for a moment then disappears.\n\n";
                system("PAUSE");
            }
        }
    }

    Screen[2]  = "============================SIDE ROOM==================================S=======\n";
    Screen[3]  = "                                                                               \n";
 // Screen[4]  = "               THE SPOON WILL END ALL THAT BEGAN WITH THE SWORD                \n";
 // Screen[4]  = "               THS EPOON WILL SND ALL THAT BEGAN WITH THS EWORD                \n";
    Screen[4]  = "                                                                               \n";
    Screen[5]  = "                                                                               \n";
    Screen[6]  = "                                                                               \n";
    Screen[7]  = "                                                                               \n";


    return success;
}
