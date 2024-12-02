#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <termios.h>        //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>     //STDIN_FILENO

using namespace std;


    string LINUX_CLEAR = "clear";
    string WINDOWS_CLEAR = "cls";

    const char* CLEAR_COMMAND;

    int loop = 1;

    int str;
    int agi;
    int intel;

    int weapstr = 0;
    int weapagi = 0;
    int weapintel = 0;
    int fight = 0;
    int trap = 0;

    int sw = 0;
    int ps = 1;
    int bw = 0;
    int ar = 0;
    int sf = 0;
    int sk = 0;
    int ss = 0;
    int rs = 0;
    int rk = 0;
    int rf = 0;
    int wp = 0;
    int wc = 0;
    int wb = 0;
    int cb = 0;
    int cp = 0;
    int gl = 0;


    int bk = 0;
    int rkey = 0;
    int gk = 0;
    int yk = 0;

    int skey = 0;
    int gkey = 0;
    int bkey = 0;

    int rkeytask = 0;

    int roomA = 0;
    int roomB = 0;
    int roomC = 0;
    int roomD = 0;
    int roomE = 0;
    int roomF = 0;
    int roomG = 0;
    int roomH = 0;
    int roomI = 0;
    int roomJ = 0;
    int roomK = 0;
    int roomL = 0;
    int roomM = 0;
    int roomN = 0;
    int roomO = 0;
    int roomP = 0;
    int roomQ = 0;
    int roomR = 0;
    int roomS = 0;
    int roomT = 0;
    int roomU = 0;
    int roomV = 0;
    int roomW = 0;
    int roomY = 0;
    int roomZ = 0;

    int trap1 = 0;
    int trap2 = 0;
    int trap3 = 0;
    int trap4 = 0;
    int trap5 = 0;
    int trap6 = 0;

    int blueknight = 1;
    int yellowknight = 1;
    int goldknight = 1;
    int blackknight = 1;
    int dragon = 1;

    int tries;

    int skelG = 1;

    int beginGame;
    int level;

    int item = 0;

    string race;
    string enter;
    string name;
    string gender;
    string type;
    string indef;
    string adj;
    string ttext;
    string levelchoice;

    string task;

    string blue;
    string yellow;

    string item1;
    string item2;

    string weapon;

    string take;

    string blackgate;
    
void clearScreen() {
    
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)        
        std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
    #elif defined (__APPLE__)
        system("clear");
    #endif
}
    
    
void drawinventory(){

    string pointstick;
    string sword;
    string bow;
    string arrows;
    string silverfork;
    string silverknife;
    string silverspoon;
    string rustyfork;

    if(ps == 0){
        pointstick = "";
    }
    else if (ps == 1){
        pointstick = "Pointed Stick\n";
    }


    if(sw == 0){
        sword = "";
    }
    else if(sw == 1){
        sword = "Sword\n";
    }



    if(bw == 0){
        bow = "";
    }

    else if(bw == 1){
        bow = "Bow\n";
    }



    if(ar == 0){
        arrows = "";
    }
    else if (ar == 1){
        arrows = "Arrow\n";
    }
    else if (ar >= 2){
        arrows = "Arrows\n";
    }



    if(sf == 0){
        silverfork = "";
    }
    else if(sf == 1){
        silverfork = "Silver Fork\n";
    }



    if(sk == 0){
        silverknife = "";
    }
    else if(sk == 1){
        silverknife = "Silver Knife\n";
    }



    if(ss == 0){
        silverspoon = "";
    }
    else if(ss == 1){
        silverspoon = "Silver Spoon\n";
    }




    if(rf == 0){
        rustyfork = "";
    }
    else if(rf == 1){
        rustyfork = "Rusted Fork\n";
    }

    string rustyknife;

    if(rk == 0){
        rustyknife = "";
    }
    else if(rk == 1){
        rustyknife = "Rusted Knife\n";
    }


    string rustyspoon;

    if(rs == 0){
        rustyspoon = "";
    }
    else if(rs == 1){
        rustyspoon = "Rusty Spoon\n";
    }

    string woodbowl;

    if(wb == 0){
        woodbowl = "";
    }
    else if(wb == 1){
        woodbowl = "Wooden Bowl\n";
    }

    string woodplate;

    if(wp == 0){
        woodplate = "";
    }
    else if(wp == 1){
        woodplate = "Wooden Plate\n";
    }

    string woodcup;

    if(wc == 0){
        woodcup = "";
    }
    else if(wc == 1){
        woodcup = "Wooden Cup\n";
    }

    string cerambowl;

    if (cb == 0){
        cerambowl = "";
    }
    else if(cb == 1){
        cerambowl = "Ceramic Bowl\n";
    }

    string ceramplate;

    if(cp == 0){
        ceramplate = "";
    }
    else if(cp == 1){
        ceramplate = "Ceramic Plate\n";
    }

    string glass;

    if(gl == 0){
        glass = "";
    }
    else if(gl == 1){
        glass = "Glass";
    }


    string redkey;

    if(rkey == 0){
        redkey = "";
    }
    else if(rkey == 1){
        redkey = "Red Key\n";
    }

    string bluekey;

    if(bk == 0){
        bluekey = "";
    }
    else if(bk == 1){
        bluekey = "Blue Key\n";
    }

    string greenacid;

    if (gk == 0){
        greenacid = "";
    }
    else if(gk == 1){
        greenacid = "Green Acid\n";
    }

    string yellowkey;

    if (yk == 0){
        yellowkey = "";
    }
    else if(yk == 1){
        yellowkey = "Yellow Key\n";
    }

    string silverkey;

    if(skey == 0){
        silverkey = "";
    }
    else if(skey == 1){
        silverkey = "Silver Key\n";
    }


    string goldkey;

    if(gkey == 0){
        goldkey = "";
    }
    else if(gkey == 1){
        goldkey = "Gold Key\n";
    }

    string blackkey;
    if(bkey == 0){
        blackkey = "";
    }
    else if(bk == 1){
        blackkey = "Black Key\n";
    }

    cout << endl << "INVENTORY" << endl;
    cout <<         "=========" << endl;
    cout << pointstick << sword << bow;
    if(ar != 0)
    {
        cout << ar << " " << arrows;
    }
    cout << silverfork << silverknife << silverspoon << rustyfork << rustyknife << rustyspoon << cerambowl << ceramplate << glass << woodbowl << woodplate << woodcup;
    cout << endl << redkey << bluekey << greenacid << yellowkey << silverkey << goldkey << blackkey;
    cout << endl << endl;


}

    /*
                                     _ _ _ _ _       _
                                    | H  _ _ X|X    |Y|
                                    |_ _|   | |     |_|
                                            | |    _|J|_
                                            | |_ _|I _  |_ _ _
                                         _ _|G _ _ _| |_ _ _ K|X   _ _ _
                                       X|F _ _|    X   _    | |_ _|     |
                                        | |           |P|   | | | |     |
                                        | |           |_|   |T|U|V|  W  |
                                 _ _ _ _| |  _ _     _|O|_ _| |_|_|     |
                                |E _ _ _ D| |M  |   |  _ Q _ _ S| |_ _ _|
                                |_|     | | |_| |   | | |_|  X|_|
                                | |  _ _| |_ _| |_ _| | |R|
                                | | |B _ A     L     N|X|_|
                                | | |_| |  _ _ _ _ _ _|
                               _| |_| | | |
                              |  C _ _| | |
                              |_ _|     |_|

*/

void drawmap(){

    string map1a = "      ";
    string map1b = "        ";
    string map1c = "   ";
    string map1d = "     ";
    string map1e = "   ";
    string map1f = "                  ";

    string map2a = "      ";
    string map2b = "        ";
    string map2c = "    ";
    string map2d = "    ";
    string map2e = "   ";
    string map2f = "                  ";

    string map3a = "      ";
    string map3b = "     ";
    string map3c = "   ";
    string map3d = "   ";
    string map3e = "     ";
    string map3f = "   ";
    string map3g = "                  ";


    string map4a = "              ";
    string map4b = "   ";
    string map4c = "   ";
    string map4d = "  ";
    string map4e = "   ";
    string map4f = " ";
    string map4g = "                 ";

    string map5a = "              ";
    string map5b = "   ";
    string map5c = "      ";
    string map5d = " ";
    string map5e = "        ";
    string map5f = "           ";

    string map6a = "          ";
    string map6b = "   ";
    string map6c = "    ";
    string map6d = "      ";
    string map6e = " ";
    string map6f = "         ";
    string map6g = " ";
    string map6h = "  ";
    string map6i = "       ";

    string map7a = "          ";
    string map7b = "   ";
    string map7c = "        ";
    string map7d = " ";
    string map7e = "  ";
    string map7f = "   ";
    string map7g = "   ";
    string map7h = "   ";
    string map7i = "  ";
    string map7j = " ";
    string map7k = "       ";


    string map8a = "          ";
    string map8b = "   ";
    string map8c = "           ";
    string map8d = "   ";
    string map8e = "   ";
    string map8f = "  ";
    string map8g = " ";
    string map8h = " ";
    string map8i = " ";
    string map8j = " ";
    string map8k = " ";
    string map8l = "      ";

    string map9a = "          ";
    string map9b = "   ";
    string map9c = "           ";
    string map9d = " ";
    string map9e = " ";
    string map9f = " ";
    string map9g = "   ";
    string map9h = "  ";
    string map9i = " ";
    string map9j = " ";
    string map9k = " ";
    string map9l = " ";
    string map9m = " ";
    string map9n = "      ";


    string map10a = "          ";
    string map10b = "   ";
    string map10c = " ";
    string map10d = "     ";
    string map10e = "   ";
    string map10f = "     ";
    string map10g = "  ";
    string map10hi = " ";
    string map10hii = "  ";
    string map10i = " ";
    string map10j = " ";
    string map10k = " ";
    string map10l = " ";
    string map10m = " ";
    string map10n = "      ";

    string map11a = "          ";
    string map11b = "    ";
    string map11c = "     ";
    string map11d = "   ";
    string map11e = "    ";
    string map11f = "   ";
    string map11g = "      ";
    string map11h = " ";
    string map11i = "       ";

    string map12a = "          ";
    string map12b = "    ";
    string map12c = "     ";
    string map12d = "   ";
    string map12e = "   ";
    string map12f = " ";
    string map12g = "   ";
    string map12h = "   ";
    string map12j = "   ";
    string map12i = "        ";

    string map13a = "      ";
    string map13b = "    ";
    string map13c = "   ";
    string map13d = "   ";
    string map13e = "   ";
    string map13f = "   ";
    string map13g = "   ";
    string map13h = " ";
    string map13i = "   ";
    string map13j = "    ";
    string map13k = " ";
    string map13l = "         ";

    string map14a = "      ";
    string map14b = "    ";
    string map14c = " A ";
    string map14d = "      ";
    string map14e = "   ";
    string map14f = "   ";
    string map14g = " ";
    string map14h = "   ";
    string map14i = "              ";

    string map15a = "      ";
    string map15b = "    ";
    string map15c = "|  ";
    string map15d = "      ";
    string map15e = "      ";
    string map15f = "                  ";

    string map16a = "          ";
    string map16b = "| |";
    string map16c = "                              ";

    string map17a = "          ";
    string map17b = "| |";
    string map17c = "                              ";

    string map18a = "          ";
    string map18b = "|_|";
    string map18c = "                              ";




    if(roomB == 1){

        map13b = " _ _";
        map14b = "|B _";

            if(roomB == 1 && bk == 0){
                map15b = "|_| ";
                }
            else if(roomB == 1 && bk == 1){
                map15b = "| | ";

                }
    }

    if(roomC == 1){

        map18a = "|_ _|     ";

        if(roomB == 1 && roomE == 1){
            map13a = "  | | ";
            map14a = "  | | ";
            map15a = "  | | ";
            map16a = " _| |_| | ";
            map17a = "|  C _ _| ";
            }
        else if(roomB == 1 && roomE == 0){
            map16a = " _   _| | ";
            map17a = "|  C   _| ";
            }
        else if (roomB == 0 && roomE == 1){
            map13a = "  | | ";
            map14a = "  | | ";
            map15a = "  | | ";
            map16a = " _| |     ";
            map17a = "|  C      ";
            }
        }

    if (roomD == 1){
        map11b = " D| ";
        map12b = "| | ";
        map13c = "| |";

    }

    if(roomE == 1){
    map10a = "   _ _ _ _";
    map11a = "  |E _ _ _";

    }


        if(roomE == 1 && bk == 0){
            map12a = "  |_|     ";
        }
        else if(roomE == 1 && bk == 1){
            map12a = "  | |     ";
        }


    if(roomF == 1){
        map6b = " _ ";
        map7b = "|F ";
        map8b = "| |";
        map9b = "| |";
        map10b = "| |";
    }
    if(trap1 == 2){
        map7a = "         X";
    }
    if(roomG == 1){
        map6c = "_|G ";
        map7c = "_ _|    ";
    }
    if(roomY == 1){
        map1c = " _ ";
        map3d = "| |";
        map4b = "| |";
        map5b = "| |";
    }
    if(roomY == 1 && trap2 == 2){
        map2c = " Y|X";
    }
    else if(roomY == 1 && trap2 == 0){
        map2c = " Y| ";
    }


    if(roomH == 1){

        map1b = " _ _ _ _";
        map2b = "| H  _ _";
        map3b = "|_ _|";
    }

    if(roomI == 1){
           map4d = " _";
        map5c = "_ _|I ";
        map6d = "_ _ _|";
    }
    if(trap3 == 0){
        map7d = " ";
    }
    else if(trap3 == 2){
        map7d = "X";
    }

    if(roomJ == 1){
        map4e = "|J|";
        map5d =  "_";
    }
    if(roomJ == 1 && rkey == 0){
        map3f = " _ ";
    }
    else if(roomJ == 1 && rkey == 1){
        map3f = "   ";
    }


    if(roomK == 1){
         map4f = "_";
        map5e = "  |_ _ _";
        map6f = "|_ _ _ K|";
    }
    if(trap4 == 2){
        map6g = "X";
    }
    else{
        map6g = " ";
    }

    if(roomL == 1){
        map13d = "_ _";
        map14d = "    L ";
        map15d = "_ _ _ ";
    }

    if(roomM == 1){
        map10d = " _ _ ";
        map11c = "|M  |";
        map12c = "|_| |";
          map13e = "| |";
    }

    if(roomN == 1){
        map13f = "_ _";
           map14f = " N|";
        map15e = "_ _ _|";
    }
    if(trap5 == 2){
        map14g = "X";
    }

    if(roomO == 1){

        map10f = " _|O|";
        map11e = "|  _";
        map12e = "| |";
        map13g = "| |";
    }

    if(roomO == 1 && gk == 0){

        map9e = "_";
    }
    if(roomO == 1 && gk == 1){

        map9e = " ";
    }


    if(roomP == 1){

        map7f = " _ ";
        map8d = "|P|";
        map9d = "|";
        map9f = "|";
    }

    if(roomQ == 1){

        map10g =  "_ ";
        map11f = " Q ";
    }
    if(roomQ == 1 && yk == 0){

        map12g = "|_|";
    }
    else if(roomQ == 1 && yk == 1){

        map12g = "| |";
    }

    if(roomR == 1){

        map13i = "|R|";
        map14h = "|_|";

    }

    if(roomS == 1 || roomT == 1){

        map10hi = "_";
    }

    if(roomS == 1){

            map10j = "_";
        map11g = "_ _ S|";
        map12j =    "|_|";
    }

    if(trap6 == 2){

        map13k = "X";
    }

    if(roomT == 1){

        map8f = "| ";
        map9h = "|T";
        map10hii = "| ";
    }
    if(roomT == 1 && roomK == 1){

        map7h = "| |";

    }
    if(roomT == 1 && skey == 0){

        map8g = "|";
        map9i = "|";
        map10i = "|";
    }
    else if (roomT == 1 && skey == 1){

        map8g = " ";
        map9i = " ";
        map10i = " ";
        }

    if(roomU == 1){
        map7i = "_ ";
        map8h = " ";
        map9j = "U";
        map10j = "_";
    }
    if(roomU == 1 && gkey == 0){
        map8i = "|";
        map9k = "|";
        map10k = "|";
    }
    else if(roomU == 1 && gkey == 1){
        map8i = " ";
        map9k = " ";
        map10k = " ";
    }

    if(roomV == 1){
        map7j = "_";
        map8j = " ";
        map9l = "V";
        map10l = "_";
    }
    if(roomV == 1 && bkey == 0){
        map8k = "|";
        map9m = "|";
        map10m = "|";
    }
    else if(roomV == 1 && bkey == 1){
        map8k = " ";
        map9m = " ";
        map10m = " ";
    }

    if(roomW == 1){
        map6i = " _ _ _ ";
        map7k = "|     |";
        map8l =  "     |";
        map9n =  "  W  |";
        map10n = "     |";
       map11i = "|_ _ _|";
    }

    if(roomZ == 1){
        map1e = " _ ";
        map2e = "|Z|";
        map3f = "| |";
    }

// Map Output
    cout << endl <<  "MAP" << endl;
    cout << "===" << endl;
    cout << map1a << map1b << map1c << map1d << map1e << map1f << endl;
    cout << map2a << map2b << map2c << map2d << map2e << map2f << endl;
    cout << map3a << map3b << map3c << map3d << map3e << map3f << map3g << endl;
    cout << map4a << map4b << map4c << map4d << map4e << map4f << map4g << endl;
    cout << map5a << map5b << map5c << map5d << map5e << map5f << endl;
    cout << map6a << map6b << map6c << map6d << map6e << map6f << map6g << map6h << map6i << endl;
    cout << map7a << map7b << map7c << map7d << map7e << map7f << map7g << map7h << map7i << map7j << map7k << endl;
    cout << map8a << map8b << map8c << map8d << map8e << map8f << map8g << map8h << map8i << map8j << map8k << map8l << endl;
    cout << map9a << map9b << map9c << map9d << map9e << map9f << map9g << map9h << map9i << map9j << map9k << map9l << map9m << map9n << endl;
    cout << map10a << map10b << map10c << map10d << map10e << map10f << map10g << map10hi << map10hii << map10i << map10j << map10k << map10l << map10m << map10n << endl;
    cout << map11a << map11b << map11c << map11d << map11e << map11f << map11g << map11h << map11i << endl;
    cout << map12a << map12b << map12c << map12d << map12e << map12f << map12g << map12h << map12j << map12i << endl;
    cout << map13a << map13b << map13c << map13d << map13e << map13f << map13g << map13h << map13i << map13j << map13k << map13l << endl;
    cout << map14a << map14b << map14c << map14d << map14e << map14f << map14g << map14h << map14i << endl;
    cout << map15a << map15b << map15c << map15d << map15e << map15f << endl;
    cout << map16a << map16b << map16c << endl;
    cout << map17a << map17b << map17c << endl;
    cout << map18a << map18b << map18c << endl << endl;


}

void initialise() {
    
    #if defined _WIN32
        CLEAR_COMMAND = WINDOWS_CLEAR.c_str();
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        CLEAR_COMMAND = LINUX_CLEAR.c_str();
    #elif defined (__APPLE__)
        CLEAR_COMMAND = LINUX_CLEAR.c_str();
    #endif
    
    system(CLEAR_COMMAND);
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore();
}


void pressKey()
{
    /// Nabbed from stack overflow: https://stackoverflow.com/questions/1449324/how-to-simulate-press-any-key-to-continue
    
    //the struct termios stores all kinds of flags which can manipulate the I/O Interface
    //I have an old one to save the old settings and a new 
    static struct termios oldt, newt;
    printf("Press any key to continue....\n");

    //tcgetattr gets the parameters of the current terminal
    //STDIN_FILENO will tell tcgetattr that it should write the settings
    // of stdin to oldt
    tcgetattr( STDIN_FILENO, &oldt);
    //now the settings will be copied 
    newt = oldt;

    //two of the c_lflag will be turned off
    //ECHO which is responsible for displaying the input of the user in the terminal
    //ICANON is the essential one! Normally this takes care that one line at a time will be processed
    //that means it will return if it sees a "\n" or an EOF or an EOL
    newt.c_lflag &= ~(ICANON | ECHO );      

    //Those new settings will be set to STDIN
    //TCSANOW tells tcsetattr to change attributes immediately. 
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);

    //now the char wil be requested
    getchar();

    //the old settings will be written back to STDIN
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);

}

void waitForAnyKey()
{
    pressKey();
}

string textInput()
{
    string returnVal;
    
    getline(cin, returnVal);
    
    return returnVal;
}

int main(){

    initialise();
    
    bool gameOn = true;
    while (gameOn != false)
    {

    cout << "===============================================================================\n";
    cout << "============================TEXT QUEST=========================================\n";
    cout << "===============================================================================\n";
    cout << " v1.0.3\n";
    cout << "\nInstructions:\nIn TextQuest you play as a customised character roving through a mysterious \ncave. To do this you must type your desired choice and press enter.\nAll compass directions must be spelt correctly, including capitals!\nOther commands must start with capitals as well and tend to be one \nword, for example, if you are given\nthe option to take and object or leave it you must type 'Take',\nas opposed to 'Take Object'.\nHowever, if you want to use an item from your inventory it must be typed exactly as it appears in the inventory.\nFor example if you wanted to use the mighty pointed stick you would type\n'Pointed Stick'. Again, capitals are important!\n\nGame Designed and Written by Joshua Haxell\n\n\n\n";
    cout << "Dare you enter? (Yes/No)\n\n";

    reinput:
    enter = textInput();
    
    if(enter == "Yes")
    {
        beginGame = 1;
    }
    else if(enter == "No")
    {
        gameOn = false;
    }
    else
    {
        cout << "Please enter again: ";
        goto reinput;
    }


        switch(beginGame){

        case 1:


            system(CLEAR_COMMAND);
            cout << "===============================================================================\n";
            cout << "============================TEXT QUEST=========================================\n";
            cout << "===============================================================================\n";
            cout << endl << "Please enter your character's name: ";
            
            name = textInput();
            cout << endl << "Please choose your character's gender: ";
            gender = textInput();
            
            cout << endl << "Please choose your character's race: " << endl;
            cout << endl << "Human";
            cout << endl << "Elf";
            cout << endl << "Orc";
            cout << endl << "Dwarf" << endl << endl;
            
            race = textInput();


            bool raceSelected = false;
            do
            {
                raceSelected = true;
                
                if(race == "Human"){

                indef = "a";
                adj = "human";

                str = 6;
                agi = 5;
                intel = 4;
                }

                else if(race == "Elf"){

                indef = "an";
                adj = "elven";

                str = 3;
                agi = 6;
                intel = 6;
                }

                else if(race == "Orc"){

                indef = "an";
                adj = "orcish";

                str = 8;
                agi = 4;
                intel = 3;
                }

                else if(race == "Dwarf"){

                indef = "a";
                adj = "dwarven";

                str = 6;
                agi = 3;
                intel = 6;
                }

                else
                {
                    cout << "Enter race again!" << endl;
                    race = textInput();
                    raceSelected = false;
                }
            }
            while(!raceSelected);
            
            system(CLEAR_COMMAND);

            cout << "===============================================================================\n";
            cout << "============================TEXT QUEST=========================================\n";
            cout << "===============================================================================\n";

            cout << endl << "Please choose a class for your character: " << endl;
            cout << endl << "Warrior";
            cout << endl << "Ranger";
            cout << endl << "Mage" << endl << endl;
            type = textInput();

            bool typeSelected = false;

            do 
            {
                typeSelected = true;
                if(type == "Warrior"){

                str += 1;

                ttext = "warrior";

                }
                else if(type == "Ranger"){

                    if(race == "Elf")
                    {
                        agi += 2;
                    }
                    else
                    {
                        agi += 1;
                    }
                ttext = "ranger";
                }
                else if(type == "Mage"){

                intel += 1;

                ttext = "mage";
                }
                else
                {
                    cout << "Please choose type again!" << endl;
                    type = textInput();
                    typeSelected = false;
                }
            }
            while(!typeSelected);
/*
            cout << endl << "Name: " << name << endl;
            cout << "Gender: " << gender << endl;
            cout << "Race: " << race << endl;
            cout << "Class: " << type << endl;
            cout << "Strength: " << str << endl;
            cout << "Agility: " << agi << endl;
            cout << "Intelligence: " << intel << endl << endl;
*/
            waitForAnyKey();
            system(CLEAR_COMMAND);

            cout << "===============================================================================\n";
            cout << "============================TEXT QUEST=========================================\n";
            cout << "===============================================================================\n";

            cout << endl << "Our story concerns a brave " << adj << " " << ttext << " called " << name << ".";
            cout << endl << "Once upon a time, " << name << " came across a dark, murky cave, and decided to venture\ninside...\n\n" << endl;

            waitForAnyKey();
            system(CLEAR_COMMAND);

            cout << "===============================================================================\n";
            cout << "============================TEXT QUEST=========================================\n";
            cout << "===============================================================================\n";

            cout << endl;

           // cout << "INVENTORY:                                                       MAP           \n";

            cout << "You come across an old wooden door leading into a cave." << endl;
            cout << endl << "Would you like to enter? (Yes/No) ";
            bool Loop = true;

            while(Loop == true)
            {

                levelchoice = textInput();

                if(levelchoice == "Yes"){
                level = 1;

                Loop = false;
                }
                else if (levelchoice == "No"){
                level = 0;
                Loop = false;
                }
                else
                {
                    cout << "Unrecognised command, please enter again! ";
                }
            }
            newlevel:

            switch (level){

//=================================================================================================================================================================
//=================================================================================================================================================================
                case 0:


                    cout << "You walk away from the cave, but curiosity gets the better of you, so you \nreturn.\n\n";

                    waitForAnyKey();

                    level = 1;

                    goto newlevel;

                break;

//=================================================================================================================================================================
//=================================================================================================================================================================

                case 1:

                system(CLEAR_COMMAND);

                cout << "===============================================================================\n";
                cout << "============================TEXT QUEST=========================================\n";
                cout << "==============================ROOM A===========================================\n\n";

                    roomA = 1;

                    drawmap();
                    drawinventory();

                    cout << "After entering the cave, you walk until you reach a 3 way split in the path. \nYou mark the room on your map as A." << endl;
                    cout << endl << "Would you like to go North, West, South or East? ";
                    levelchoice = textInput();



                    if(levelchoice == "North"){

                    level = 4;

                    goto newlevel;
                    }
                    else if(levelchoice == "South"){
                    cout << endl << "You are a coward!\n\n";
                    waitForAnyKey();
                    gameOn = false;
                    }
                    else if(levelchoice == "East"){

                    level = 12;

                    goto newlevel;
                    }
                    else if(levelchoice == "West"){

                    level = 2;

                    goto newlevel;

                    }
                    else{

                    cout << "Unrecognised command!" << endl << endl;

                    waitForAnyKey();
                    goto newlevel;

                    }



    break;


//=================================================================================================================================================================
//=================================================================================================================================================================
            case 2:


                system(CLEAR_COMMAND);

                cout << "===============================================================================\n";
                cout << "============================TEXT QUEST=========================================\n";
                cout << "==============================ROOM B===========================================\n\n";

                    roomB = 1;


            drawmap();
            drawinventory();

                if(bk == 0){

                    cout << "You arrive at a blue door, it is clearly tightly locked.\nYou try to shove the door open but it won't give!";
                    cout << endl << "Your only choice is to turn back!\n" << endl << endl;

                    waitForAnyKey();

                    level = 1;
                    goto newlevel;
                }

                else if (bk == 1){

                    cout << "The blue door opens after you turn the key in the lock.\n";
                    cout << "Do you head East to A or head South down the corridor? ";
                    levelchoice = textInput();

                    if(levelchoice == "East"){
                        level = 1;
                        goto newlevel;

                    }

                    else if(levelchoice == "South"){
                        level = 3;
                        goto newlevel;
                    }
                    else
                    {
                        cout << "Unrecognised command!" << endl;
                        waitForAnyKey();
                        goto newlevel;

                    }


                }






   //     switch(level)
        break;

//=================================================================================================================================================================
//=================================================================================================================================================================
       case 3:

            system(CLEAR_COMMAND);


                cout << "===============================================================================\n";
                cout << "============================TEXT QUEST=========================================\n";
                cout << "==================ROOM C===LAIR OF THE BLUE KNIGHT=============================\n\n";


                    roomC = 1;

                drawmap();
                drawinventory();

                if(blueknight == 1){

                    cout << "As you enter the room you see a knight, dressed in blue.\n";
                    cout << "Blue Knight: I was an adventurer like you once, then I\n";
                    cout << "             got trapped in this godforsaken dungeon!\n";
                    cout << "             If you can lift the curse then I could be free!\n";
                    cout << "             but if you fail in this task I shall be cursed to\n";
                    cout << "             loneliness once more! How can I be sure you'll be\n";
                    cout << "             successful?\n\n";

                    waitForAnyKey();

                    cout << endl << "You must prove your worth to the blue knight! Will you: ";
                    cout << endl << "Pickpocket";
                    cout << endl << "Fight";
                    cout << endl << "Persuade\n\n";

                    reinputblue:

                    blue = textInput();

                    if(blue == "Pickpocket" && agi >= 6){

                        cout << name << ": Woah, you're crazy! I'm leaving!\n\n";
                        cout << "As you move to leave the room the Blue Knight turns\nhis back to you, giving you the perfect opportunity to steal his shiny key!\n\n";


                        skey = 1;
                        blueknight = 0;

                        cout << "Would you like to leave through the North door or East door? ";

                        redoblue:
                        levelchoice = textInput();

                        if(levelchoice == "North"){
                        level = 5;
                        goto newlevel;
                        }
                        else if(levelchoice == "East"){
                        level = 2;
                        goto newlevel;
                        }
                        else
                        {
                            cout << "Unrecognised command!" << endl;
                            waitForAnyKey();
                            goto redoblue;
                        }
                    }
                    else if(blue == "Pickpocket" && agi <= 5){

                        cout << name << ": Woah, you're crazy! I'm leaving!\n\n";
                        cout << "As you move to leave the room the Blue Knight turns\nhis back to you, giving you the perfect/nopportunity to steal his shiny key!\nBut you stumble as you reach for his belt and alert him to\nyour presence!\nThe Blue Knight deems you unworthy and chops off your head!/n/n";

                        waitForAnyKey();
                        gameOn = false;
                    }

                    else if(blue == "Fight"){

                        weaponloop:
                        cout << "Choose a weapon from your inventory to fight with! ";

                        weapon = textInput();

                        if(weapon == "Pointed Stick" && ps == 0){
                        cout << "You have no pointed stick!\n";
                        goto weaponloop;
                        }
                        else if(weapon == "Pointed Stick" && ps == 1){
                            weapstr = str;
                        }

                        else if(weapon == "Sword" && sw == 0){
                        cout << "You have no sword!\n";
                        goto weaponloop;
                        }
                        else if(weapon == "Sword" && sw == 1){
                            weapstr = str + 1;
                        }
                        else if(weapon == "Sword" && sw == 2){
                            weapstr = str + 2;
                        }

                        else if(weapon == "Bow" && (bw == 0 || ar == 0)){
                            cout << "You do not have both a bow and at least 1 arrow!\n";
                            goto weaponloop;
                        }
                        else if(weapon == "Bow" && (bw >= 1 && ar >=1)){
                            weapagi = agi + bw;
                            ar --;
                        }
                        else if(weapon != "Bow" || weapon != "Sword" || weapon != "Pointed Stick")
                        {
                            cout << "Unrecognised command!" << endl;
                            waitForAnyKey();
                            goto weaponloop;
                        }

                        if(weapstr >= 1){
                        fight = weapstr;
                        }
                        else if(weapagi >= 1){
                        fight = weapagi;
                        }
                        else if(weapintel >= 1){
                        fight = weapintel;
                        }

                        if(fight >= 7){
                            cout << "You engage in combat with the Blue Knight, after a furious battle\nyou emerge victorious!\nYou take the knight's silver key and sword!\n\n";
                            skey = 1;
                            sw = 1;
                            blueknight = 0;
                            waitForAnyKey();
                            cout << "Would you like to leave through the North or East door? ";

                            reinputC1:

                            levelchoice = textInput();
                            if(levelchoice == "North"){
                            level = 5;
                            goto newlevel;
                            }
                            else if(levelchoice == "East"){
                            level = 2;
                            goto newlevel;
                            }
                            else
                            {
                                cout << "Unrecognised command!" << endl;
                                waitForAnyKey();
                                goto reinputC1;
                            }
                        }
                        else if(fight <= 6){
                        cout << "You engage in combat with the Blue Knight, but you are slain\ndue to his superior experience.\nYou are dead!";

                        waitForAnyKey();
                        gameOn = false;
                        }
                        weapstr = 0;
                        weapagi = 0;
                        weapintel = 0;
                        fight = 0;
                    }

                    else if(blue == "Persuade" && intel >= 6){

                        cout << name << ": Come on, sir knight, I'm sure you don't get people\ncoming through here very often\nthis could be your last chance at\nfreedom!";
                        cout << endl << endl;
                        waitForAnyKey();
                        cout << "Blue Knight: Oh, I suppose you're right!\nHere, take this key, and my sword!";
                        cout << endl << endl;

                        waitForAnyKey();
                        skey = 1;
                        sw = 1;
                        blueknight = 0;

                        cout << "Would you like to leave through the North or East door?";
                        levelchoice = textInput();

                        reinputC2:
                        if(levelchoice == "North"){
                            level = 5;
                            goto newlevel;
                        }
                        else if(levelchoice == "East"){
                            level = 2;
                            goto newlevel;
                        }
                        else
                        {
                            cout << "Unrecognised command!" << endl;
                            waitForAnyKey();
                            goto reinputC2;
                        }
                    }
                    else if(blue == "Persuade" && intel <=5){
                        cout << name << ": Look, I don't like you and you don't like me,\njust give me the damn key!\n";
                        cout << endl << endl;
                        waitForAnyKey();
                        cout << "Blue Knight: I'm afraid I don't much like your tone!\n";
                        cout << "The Blue Knight draws his sword and stabs you through the heart\nfor your insolence!\n";

                        waitForAnyKey();

                        gameOn = false;
                    }
                    else
                    {
                        cout << "Unrecognised command!" << endl;
                        waitForAnyKey();
                        goto reinputblue;

                    }


                }
                else if(blueknight == 0){
                    cout << "You return to the Blue Knight's Lair.\nWould you like to leave through the North or East door?\n";
                    levelchoice = textInput();
                    if(levelchoice == "North"){
                    level = 5;
                    goto newlevel;
                    }
                    else if(levelchoice == "East"){
                    level = 2;
                    goto newlevel;
                    }
                    else
                    {
                        cout << "Unrecognised command!" << endl;
                        waitForAnyKey();
                        goto newlevel;
                    }

                }



            break;




//=================================================================================================================================================================
//=================================================================================================================================================================


            case 4:

                system(CLEAR_COMMAND);
                cout << "===============================================================================\n";
                cout << "============================TEXT QUEST=========================================\n";
                cout << "==============================ROOM D===========================================\n\n";

                roomD = 1;

                drawmap();
                drawinventory();

                cout << "You reach a split in the path, would you like to go North, South or West?\n";
                levelchoice = textInput();
                if(levelchoice == "North"){
                    level = 6;
                    goto newlevel;
                }
                else if(levelchoice == "South"){
                    level = 1;
                    goto newlevel;
                }
                else if(levelchoice == "West")
                {
                    level = 5;
                    goto newlevel;
                }
                else
                {
                    cout << "Unrecognised command!" << endl;
                    waitForAnyKey();
                    goto newlevel;
                }

            break;


//=================================================================================================================================================================
//=================================================================================================================================================================

         case 5:

                system(CLEAR_COMMAND);

                cout << "===============================================================================\n";
                cout << "============================TEXT QUEST=========================================\n";
                cout << "==============================ROOM E===========================================\n\n";

                roomE = 1;

                drawmap();
                drawinventory();

                  if(bk == 0){

                    cout << "You arrive at a blue door, it is clearly tightly locked.\nYou try to shove the door open but it won't give!";
                    cout << endl << "Your only choice is to turn back!\n" << endl << endl;

                    waitForAnyKey();

                    level = 4;
                    goto newlevel;
                }
                else if (bk == 1){

                    cout << "The blue door opens after you turn the key in the lock.\n";
                    cout << "Do you head East to D or head South down the corridor? ";
                    levelchoice = textInput();

                    if(levelchoice == "East"){
                        level = 4;
                        goto newlevel;

                    }

                    else if(levelchoice == "South"){
                        level = 3;
                        goto newlevel;
                    }
                    else
                    {
                        cout << "Unrecognised command!" << endl;
                        waitForAnyKey();
                        goto newlevel;
                    }
                }

            break;

//=================================================================================================================================================================
//=================================================================================================================================================================

        case 6:

                system(CLEAR_COMMAND);

                cout << "===============================================================================\n";
                cout << "============================TEXT QUEST=========================================\n";
                cout << "==============================ROOM F===========================================\n\n";

                roomF = 1;

                drawmap();
                drawinventory();

                cout << "You reach a crossroads.\nDo you go East, South or West? ";
                levelchoice = textInput();
                cout << endl;

                if(levelchoice == "East"){
                    level = 7;
                    goto newlevel;
                }
                else if(levelchoice == "South"){
                    level = 4;
                    goto newlevel;
                }
                else if(levelchoice == "West"){

                if(trap1 == 0){
                    trap1 = 1;

                    cout << "You begin to walk down the corridor when suddenly you hear\na mechanical click.\nArrows then fly out of the wall at you!\n\n";

                        waitForAnyKey();
                    cout << endl;

                    trap = agi + intel;

                    if(trap >= 10){
                        cout << "You judge the trajectory and speed of the arrows\nperfectly and dodge them just in time\nthey clatter to the floor and you pick them up!\n";
                        ar += 4;

                        trap = 0;
                        trap1 = 2;

                        waitForAnyKey();

                        level = 6;
                        goto newlevel;

                    }
                    else if(trap <= 9){
                        cout << "The next thing you know you find yourself with \n4 arrows embedded in your chest!\n\nYou are dead!";

                        waitForAnyKey();

                        gameOn = false;
                    }
                }
                else if(trap1 == 2){
                    cout << "You examine the intricately placed crossbows in the wall.\nThen walk back the way you came.\n\n";
                    level = 6;
                    waitForAnyKey();
                    goto newlevel;
                }

                }
                else
                {
                    cout << "Unrecognised command!" << endl;
                    waitForAnyKey();
                    goto newlevel;
                }



        break;



//=================================================================================================================================================================
//=================================================================================================================================================================

        case 7:

            system(CLEAR_COMMAND);

                cout << "===============================================================================\n";
                cout << "============================TEXT QUEST=========================================\n";
                cout << "==============================ROOM G===========================================\n\n";

            roomG = 1;

            drawmap();
            drawinventory();

            if(skelG == 1){

                cout << "You see a skeleton leant against the wall holding a bow, do you take the bow or leave it? ";

                take = textInput();

                cout << endl;

                if(take == "Take"){
                cout << "You try to wrestle the bow out of the skeleton's cold, dead grasp\nBut suddenly it stirs and grabs your arm!\n\n";
                waitForAnyKey();
                cout << endl;
                    if(type == "Warrior"){

                    cout << "You punch the skeleton with all your might and it shatters!\n";
                    }
                    if(type == "Ranger"){
                    cout << "You slide out of the skeleton's grip and tie its legs with \nwire so it trips over, smashing to pieces as it hits the ground!\n";
                    }
                    if(type == "Mage"){
                    cout << "You cast a fire spell at the skeleton, sending it\n running in the opposite direction, it drops the bow.";
                    }
                bw = 1;
                ar += 2;
                skelG = 0;
                }
                else if(take == "Leave"){
                cout << "You decide the wisest choice is to leave the skeleton as it is.\n";
                }
                else
                {
                    cout << "Unrecognised command!" << endl;
                    waitForAnyKey();
                    goto newlevel;
                }

            }
            else if(skelG == 0){
                cout << "You come to a crossroads\n";
            }



                cout << "Would you like to go North, East, or West? ";
                levelchoice = textInput();
                if(levelchoice  == "North"){
                    level = 24;
                    goto newlevel;
                }
                if(levelchoice == "East"){
                    level = 9;
                    goto newlevel;
                }

                if(levelchoice == "West"){
                    level = 6;
                    goto newlevel;
                }
                else
                {
                    cout << "Unrecognised command!" << endl;
                    waitForAnyKey();
                    goto newlevel;
                }
            break;

//=================================================================================================================================================================
//=================================================================================================================================================================

        case 8:

            system(CLEAR_COMMAND);


                cout << "===============================================================================\n";
                cout << "============================TEXT QUEST=========================================\n";
                cout << "==============================ROOM H===========================================\n\n";

                roomH = 1;

                drawmap();
                drawinventory();
                cout << "After walking down a corridor, you arrive at a dead end.\n";

                if(bk == 0){
                    cout << "You find a blue key!\n";
                    bk = 1;
                }
                else if(bk == 1){
                    cout << "The room is empty.\n";
                }

                cout << "You return down the corridor.\n\n";

                level = 24;
                waitForAnyKey();
                goto newlevel;

    break;
//=================================================================================================================================================================
//=================================================================================================================================================================

        case 9:

            system(CLEAR_COMMAND);

                cout << "===============================================================================\n";
                cout << "============================TEXT QUEST=========================================\n";
                cout << "==============================ROOM I===========================================\n\n";

            roomI = 1;

            drawmap();
            drawinventory();

            cout << "You reach a crossroads.\n";
            cout << "Would you like to go East, South or West.\n";
            levelchoice = textInput();
            if(levelchoice == "East"){
                level = 10;
                goto newlevel;
            }
            else if(levelchoice == "South"){
                if(trap3 == 0){
                    trap3 = 1;

                    cout << "You walk south down the corridor and see that\none of the bricks in the wall is slightly loose.\nAfter pulling it out the wall begins to crumble and fall.\n";

                    waitForAnyKey();

                    trap = (agi*2) + str;
                    if(trap >= 15){
                        cout << "You manage to dodge most of the falling rocks but get trapped!\nThanks to your strength you are able to break free!\nYou find a bow behind the crumbled wall which\nseems to be infused with some ancient power!\n";
                        bw = 2;
                        trap3 = 2;
                        trap = 0;
                        level = 9;

                        waitForAnyKey();
                        goto newlevel;

                    }
                    else if(trap <= 10){
                        cout << "You are entombed under bricks and rubble and remain there forever!\n";
                        cout << "You are dead!\n\n";

                        system(CLEAR_COMMAND);

                        waitForAnyKey();

                        gameOn = false;

                    }
                }
                else if(trap3 == 2){
                    cout << "You search through the rubble for something interesting\nbut find nothing!\nSo you return to room I.\n\n";

                    waitForAnyKey();

                    level = 9;
                    goto newlevel;
                }

            }
            else if(levelchoice == "West"){
                level = 7;
                goto newlevel;
            }
            else
            {
                cout << "Unrecognised command!" << endl;
                waitForAnyKey();
                goto newlevel;
            }

    break;

//=================================================================================================================================================================
//=================================================================================================================================================================

        case 10:

            system(CLEAR_COMMAND);

                cout << "===============================================================================\n";
                cout << "============================TEXT QUEST=========================================\n";
                cout << "==============================ROOM J===========================================\n\n";

            roomJ = 1;

            drawmap();
            drawinventory();

                cout << "You reach a red door.\n";
                if(rkey == 0){
                    cout << "You try to force the door but it won't budge!\n";
                    cout << "Would you like to go East or West? ";
                    levelchoice = textInput();
                    if(levelchoice == "East"){
                        level = 11;
                        goto newlevel;
                    }
                    else if(levelchoice == "West"){
                        level = 9;
                        goto newlevel;
                    }
                    else
                    {
                        cout << "Unrecognised command!" << endl;
                        waitForAnyKey();
                        goto newlevel;
                    }
                }
                else if(rkey == 1){
                    cout << "You try the red key in the door and it swings open!\n";
                    cout << "Would you like to go North, East or West? ";
                    levelchoice = textInput();

                    if(levelchoice == "North"){
                        level = 25;
                    goto newlevel;
                    }
                    else if(levelchoice == "East"){
                        level = 11;
                        goto newlevel;
                    }
                    else if(levelchoice == "West"){
                        level = 9;
                        goto newlevel;
                    }
                    else
                    {
                        cout << "Unrecognised command!" << endl;
                        waitForAnyKey();
                        goto newlevel;
                    }

                }

            break;

//=================================================================================================================================================================
//=================================================================================================================================================================

            case 11:

                system(CLEAR_COMMAND);

                    cout << "===============================================================================\n";
                    cout << "============================TEXT QUEST=========================================\n";
                    cout << "==============================ROOM K===========================================\n\n";

                roomK = 1;

                drawmap();
                drawinventory();

                cout << "You reach a turn in the road.\nWould you like to go East, South or West?\n";
                levelchoice = textInput();

                if(levelchoice == "East"){

                    if(trap4 == 0){

                    trap4 = 1;

                    cout << "A gate falls down behind you trapping you in a seemingly\nempty niche!";

                    trap = intel;

                    if(trap == 10){

                        cout << "You examine your surroundings carefully and\ncreate a system of pullies using the belts of your armour.\n\n";

                        trap4 = 2;

                        trap = 0;

                        level = 11;
                        waitForAnyKey();

                        goto newlevel;
                    }
                    else{

                        cout << "You are trapped forever!\n";
                        cout << "You will eventually be dead!\n\n";
                        waitForAnyKey();

                        gameOn = false;
                        break;
                    }
                    }

                    else if(trap4 == 2){

                        cout << "The niche remains empty.\nYou return to K on your map\n\n";

                        waitForAnyKey();

                        level = 11;

                        goto newlevel;
                    }
                }
                if(levelchoice == "South"){
                    level = 20;
                    goto newlevel;
                }
                if(levelchoice == "West"){
                    level = 10;
                    goto newlevel;
                }
                else
                {
                    cout << "Unrecognised command!" << endl;
                    waitForAnyKey();
                    goto newlevel;
                }

        break;
//=================================================================================================================================================================
//=================================================================================================================================================================

            case 12:

                system(CLEAR_COMMAND);

                    cout << "===============================================================================\n";
                    cout << "============================TEXT QUEST=========================================\n";
                    cout << "==============================ROOM L===========================================\n\n";

                    roomL = 1;


                drawmap();
                drawinventory();

                cout << "You see a corridor going off to the North.\nWould you like to go North, East or West? ";
                levelchoice = textInput();

                if(levelchoice == "North"){
                    level = 13;
                    goto newlevel;
                }
                else if(levelchoice == "East"){
                    level = 14;
                    goto newlevel;
                }
                else if(levelchoice == "West"){
                    level = 1;
                    goto newlevel;
                }
                else
                {
                    cout << "Unrecognised command!" << endl;
                    system(CLEAR_COMMAND);
                    goto newlevel;
                }
        break;
//=================================================================================================================================================================
//=================================================================================================================================================================

            case 13:

                system(CLEAR_COMMAND);

                    cout << "===============================================================================\n";
                    cout << "============================TEXT QUEST=========================================\n";
                    cout << "==============================ROOM M===========================================\n\n";

                    roomM = 1;

                    drawmap();
                    drawinventory();

                    if(rkey == 0){
                        retry:

                        cout << "You see a red key high up in the corner of the room.\nDo you try to shoot it down, climb the wall, smash the wall?\nOr leave? ";

                        reinputtask:

                        task = textInput();
                        cout << endl;

                        if(task == "Shoot"){

                            if(bw == 0 || ar == 0){
                                cout << "You cannot do this unless you have a bow and arrows.\n\n";
                                waitForAnyKey();

                                goto retry;
                            }
                            if(bw >= 1 && ar >= 1){

                                weapagi = agi + bw;

                                    if(weapagi >= 6){
                                        cout << "You carefully aim your bow and release an arrow,\nknocking the key from its place and allowing\nit to fall to the floor!\n";
                                        ar --;
                                        rkey = 1;

                                        cout << "You leave to the South.\n\n";

                                        waitForAnyKey();

                                        level = 12;
                                        goto newlevel;
                                    }
                                    else if(weapagi <= 9){
                                        cout << "You carefully aim your bow and release an arrow,\nbut miss!\n\n";
                                        ar --;

                                        waitForAnyKey();

                                        goto retry;
                                    }
                            }

                            }
                            if(task == "Climb"){
                                cout << "You begin to carefully scale the wall towards the key.\n";
                                if(agi >= 6){
                                    cout << "When you reach the top, you grab the key and carefully \nclimb back down.\n\n";

                                    rkey = 1;

                                    cout << "You leave to the South.\n\n";

                                    waitForAnyKey();

                                level = 12;

                                goto newlevel;
                                }
                                else if(agi <= 5){

                                    cout << "When you reach the top, you grab the key, \nbut fall and die!\nYou are dead!\n\n";

                                    waitForAnyKey();

                                    gameOn = false;
                                }
                            }
                            if(task == "Smash"){

                                cout << "You attempt to smash the wall hard enough to \nknock the key free!\n";

                                if(str >= 7){
                                    cout << "The key wobbles and falls into your hands!\n\n";

                                    waitForAnyKey();
                                    rkey = 1;
                                    level = 12;
                                    goto newlevel;
                                }
                                else if(str <= 6){
                                    cout << "The key stays where it is and\n you hurt your hand badly!\n\n";

                                    waitForAnyKey();
                                    str --;
                                    goto retry;
                                }
                            }
                            else if(task == "Leave"){
                                level = 12;
                                goto newlevel;
                            }
                            else
                            {
                                cout << "Unrecognised command!" << endl;
                                cout << "Please enter again!: ";
                                goto reinputtask;
                            }
                        }
                        else if(rkey == 1){
                            cout << "The room is completely empty, so you\nreturn to L.\n\n";

                            waitForAnyKey();

                            level = 12;

                            goto newlevel;
                        }
        break;
//=================================================================================================================================================================
//=================================================================================================================================================================

            case 14:

                system(CLEAR_COMMAND);

                    cout << "===============================================================================\n";
                    cout << "============================TEXT QUEST=========================================\n";
                    cout << "==============================ROOM N===========================================\n\n";

                    roomN = 1;

                    drawmap();
                    drawinventory();

                    if(trap5 == 0){
                    cout << "You reach a split in the path.\nA skeleton lies on the floor with a shield.\nWould you like to go North or West?\nOr take the shield?\n";
                    levelchoice = textInput();

                    if(levelchoice == "North"){
                        level = 15;
                        goto newlevel;
                    }
                    else if(levelchoice == "Take"){
                        trap5 = 1;
                            cout << "The skeleton gets up and begins to attack you!\n\n";
                            waitForAnyKey();

                            weapstr = str + sw;

                            if(weapstr >= 8){
                                cout << "You smash the skeleton with the pointed stick,\nthen push the shield back into it!\nBoth are destroyed in the process!\n\n";

                                trap5 = 2;
                                waitForAnyKey();

                                level = 14;
                                goto newlevel;
                            }
                            else
                            {
                                cout << "The skeleton batters you to death as your \nfutile attempts to fight back make it angrier and angrier!\nYou are dead!\n";
                                waitForAnyKey();
                                gameOn = false;
                            }
                    }
                    else if(levelchoice == "West"){
                        level = 12;
                        goto newlevel;
                    }
                    else
                    {
                        cout << "Unrecognised command!" << endl;
                        waitForAnyKey();
                        goto newlevel;
                    }
                    }
                    else if(trap5 == 2){
                        cout << "You reach a split in the path.\nWould you like to go North, East or West?\n";
                        levelchoice = textInput();
                        if(levelchoice == "North"){
                            level = 15;
                            goto newlevel;
                        }
                        else if(levelchoice == "West"){
                            level = 12;
                            goto newlevel;
                        }
                        else
                        {
                            cout << "Unrecognised command!";
                            waitForAnyKey();
                            goto newlevel;
                        }
                    }
        break;
//=================================================================================================================================================================
//=================================================================================================================================================================

            case 15:

                system(CLEAR_COMMAND);

                    cout << "===============================================================================\n";
                    cout << "============================TEXT QUEST=========================================\n";
                    cout << "==============================ROOM O===========================================\n\n";

                    roomO = 1;

                    drawmap();
                    drawinventory();

                    if(gk == 0){
                        cout << "You reach a green door that appears to be locked!\nYou try to force it but it won't budge!\nWould you like to go East or West?\n";
                        levelchoice = textInput();
                        if (levelchoice == "East"){
                            level = 17;
                            goto newlevel;
                        }
                        else if(levelchoice == "West"){
                            level = 14;
                            goto newlevel;
                        }
                        else
                        {
                            cout << "Unrecognised command!" << endl;
                            waitForAnyKey();
                            goto newlevel;
                        }
                    }
                    if(gk == 1){
                        cout << "You use the Green Acid to melt the lock!\nThe door swings open!\nWould you like to go North, East or West? ";
                        levelchoice = textInput();
                        if(levelchoice == "North"){
                            level = 16;
                            goto newlevel;
                        }
                        else if(levelchoice == "East"){
                            level = 17;
                            goto newlevel;
                        }
                        else if(levelchoice == "West"){
                            level = 14;
                            goto newlevel;
                        }
                        else
                        {
                            cout << "Unrecognised command!" << endl;
                            waitForAnyKey();
                            goto newlevel;
                        }
                    }


        break;
//=================================================================================================================================================================
//=================================================================================================================================================================

            case 16:

                system(CLEAR_COMMAND);

                    cout << "===============================================================================\n";
                    cout << "============================TEXT QUEST=========================================\n";
                    cout << "==================ROOM P===LAIR OF THE YELLOW KNIGHT===========================\n\n";

                    roomP = 1;

                    drawmap();
                    drawinventory();

                    if(yellowknight == 1){

                        cout << "As you walk into the room you see a Knight cowering\nin the corner.\n";
                        cout << "Yellow Knight: W-w-w-who's there?!\n\n";

                        waitForAnyKey();

                        cout << name << ": It is I, " << name << endl << endl;

                        retry2:

                        cout << "You speak a little too loudly, and the Yellow\nKnight begins to run away!\n\nWill you pursue him, paralyse him or try to persuade\nhim to come back?\n";
                        yellow = textInput();

                        if(yellow == "Pursue"){
                            fight = str + agi;
                                if(fight >= 10){
                                    cout << "You catch up to the Yellow Knight and tackle him to the ground!\nHe drops his yellow key and you pick it up,\nleaving the Knight to continue to flee!\n";

                                    yk = 1;
                                    yellowknight = 0;

                                    cout << "You leave the room and return to O.\n\n";
                                    fight = 0;
                                    level = 15;
                                    waitForAnyKey();

                                    goto newlevel;

                                }
                                else if(fight <= 9){
                                    cout << "You cannot catch up to the Yellow Knight\nyour heart tells you that you cannot \ncontinue your quest!\n\n";
                                    waitForAnyKey();
                                    gameOn = false;
                                }

                        }
                        else if(yellow == "Paralyse"){
                            if(bw == 0 || ar == 0){
                                cout << "You need a bow and at least 1 arrow to paralyse!\n";
                                goto retry2;
                            }
                            else if(bw >= 1 || ar >= 1){
                                weapagi = agi + bw;
                                if (weapagi >= 8){
                                    cout << "You hit the Yellow Knight in the back of the leg,\nsending him to the floor, a yellow key falls out of his pocket.\nYou walk over and pick it up!\n";
                                    yk = 1;
                                    ar --;
                                    yellowknight = 0;
                                    cout << "You leave the room and return to the corridor.\n\n";
                                    waitForAnyKey();
                                    level = 15;
                                    goto newlevel;
                                }
                                else if(weapagi <= 7){
                                    cout << "Your shot misses!\nYou sense that your quest is now impossible\nso you leave the cave.\n\n";
                                    waitForAnyKey();
                                    gameOn = false;
                                }
                            }
                        }
                        else if(yellow == "Persuade" && intel >= 6){
                            cout << name << "Ok, Ok, I'm not going to hurt you!\nJust give me your key and I'll leave you in peace!\n\n";

                            waitForAnyKey();

                            cout << "Yellow Knight: Alright, here you go...\n\n";

                            yk = 1;
                            yellowknight = 0;
                            waitForAnyKey();
                            cout << "You leave the room and return to the corridor\n";
                            level = 15;
                            waitForAnyKey();
                            goto newlevel;
                        }
                        else if(yellow == "Persuade" && intel <= 5){
                            cout << name << ": OI! OI! GET BACK HERE!\n\n";
                            waitForAnyKey();
                            cout << "The Yellow Knight runs even faster\nyou sense that your quest is now impossible\nyou leave the cave\n\n";

                            waitForAnyKey();
                            gameOn = false;
                        }
                        else
                        {
                            cout << "Unrecognised command!" << endl;
                            waitForAnyKey();
                            goto retry2;

                        }
                    }

                    else if(yellowknight == 0){
                        cout << "You examine the room again, and find nothing.\nYou leave the room and return to the corridor.\n\n";
                        waitForAnyKey();
                        level = 15;
                        goto newlevel;
                    }



        break;
//=================================================================================================================================================================
//=================================================================================================================================================================

            case 17:

                system(CLEAR_COMMAND);

                    cout << "===============================================================================\n";
                    cout << "============================TEXT QUEST=========================================\n";
                    cout << "==============================ROOM Q===========================================\n\n";

                    roomQ = 1;

                    drawmap();
                    drawinventory();




                    if(yk == 0){
                        cout << "You reach a yellow door, you try to force it open\nbut it won't budge!\n\n";
                        cout << "Would you like to go East or West? ";
                        levelchoice = textInput();
                        if(levelchoice == "East"){
                            level = 19;
                            goto newlevel;
                        }
                        else if(levelchoice == "West"){
                            level = 15;
                            goto newlevel;
                        }
                        else
                        {
                            cout << "Unrecognised command!" << endl;
                            waitForAnyKey();
                            goto newlevel;
                        }
                    }
                    else if(yk == 1){
                        cout << "You try the key in the door and it swings open.\nWould you like to go East, South or West?\n";
                        levelchoice = textInput();
                        if(levelchoice == "East"){
                            level = 19;
                            goto newlevel;
                        }
                        else if(levelchoice == "South"){
                            level = 18;
                            goto newlevel;
                        }
                        else if(levelchoice == "West"){
                            level = 15;
                            goto newlevel;
                        }
                        else
                        {
                            cout << "Unrecognised command!" << endl;
                            waitForAnyKey();
                            goto newlevel;
                        }
                    }

        break;

//=================================================================================================================================================================
//=================================================================================================================================================================

            case 18:

                system(CLEAR_COMMAND);

                    cout << "===============================================================================\n";
                    cout << "============================TEXT QUEST=========================================\n";
                    cout << "=======================ROOM R===DINING HALL====================================\n\n";

                    roomR = 1;

                    drawmap();
                    drawinventory();

                    if(item != 2){

                    cout << "You see two tables laid out for a meal, even though it seems no one has eaten \nhere for centuries.\n";
                    cout << "You think you could probably take two items.\n";
                    cout << "You see the following items: \n";
                    cout << "Rusty Spoon\nRusty Fork\nRusty Knife\nSilver Spoon\nSilver Fork\nSilver Knife\nWooden Bowl\nWooden Plate\nWooden Cup\nCeramic Bowl\nCeramic Plate\nGlass\n\n";
                    cout << "Which items will you take? ";

                    item = 0;

                    while(item == 0){

                        item1 = textInput();

                            if(item1 == "None"){
                                cout << "You decide not to take anything and leave the room!\n\n";
                                waitForAnyKey();

                                level = 17;
                                goto newlevel;
                            }
                            else if (item1 == "Rusty Spoon"){

                                rs = 1;
                                item = 1;

                            }
                            else if(item1 == "Rusty Fork"){

                                rf = 1;
                                item = 1;
                            }
                            else if(item1 == "Rusty Knife"){

                                rk = 1;
                                item = 1;
                            }
                            else if(item1 == "Silver Spoon"){
                                ss = 1;
                                item = 1;
                            }
                            else if(item1 == "Silver Fork"){
                                sf = 1;
                                item = 1;
                            }
                            else if(item1 == "Silver Knife"){
                                sk = 1;
                                item = 1;
                            }
                            else if(item1 == "Wooden Plate"){
                                wp = 1;
                                item = 1;
                            }
                            else if(item1 == "Wooden Bowl"){
                                wb = 1;
                                item = 1;
                            }
                            else if(item1 == "Wooden Cup"){
                                wc = 1;
                                item = 1;
                            }
                            else if(item1 == "Ceramic Bowl"){
                                cb = 1;
                                item = 1;
                            }
                            else if(item1 == "Ceramic Plate"){
                                cp = 1;
                                item = 1;
                            }
                            else if(item1 == "Glass"){
                                gl = 1;
                                item = 1;
                            }
                            else
                            {
                                cout << "Unrecognised command!" << endl;
                                cout << "Please enter again: ";
                            }

                        while(item == 1){

                            item2 = textInput();

                                if(item2 == "Rusty Spoon"){

                                    if(rs == 0){
                                        rs = 1;
                                        item = 2;
                                    }
                                    else if(rs == 1){
                                        cout << "You already have the rusty spoon!\n";
                                    }
                                }
                                else if(item2 == "Rusty Fork"){

                                    if(rf == 0){
                                        rf = 1;
                                        item = 2;
                                    }
                                    else if(rf == 1){
                                        cout << "You already have the rusty fork!\n";

                                    }
                                }
                                else if(item2 == "Rusty Knife"){

                                    if(rk == 0){
                                        rk = 1;
                                        item = 2;
                                    }
                                    else if(rk == 1){
                                        cout << "You already have the rusty knife!\n";
                                    }

                                }
                                else if(item2 == "Silver Spoon"){

                                    if(ss == 0){
                                        ss = 1;
                                        item = 2;
                                    }
                                    else if(ss == 1){
                                        cout << "You already have the silver spoon!";

                                    }
                                }
                                else if(item2 == "Silver Fork"){

                                    if(sf == 0){
                                        sf = 1;
                                        item = 2;
                                    }
                                    else if(sf == 1){
                                        cout << "You already have the silver fork!";

                                    }
                                }
                                else if(item2 == "Silver Knife"){

                                    if(sk == 0){
                                        sk = 1;
                                        item = 2;
                                    }
                                    else if(sk == 1){
                                        cout << "You already have the silver knife!";

                                    }
                                }
                                else if(item2 == "Wooden Plate"){

                                    if(wp == 0){
                                        wp = 1;
                                        item = 2;
                                    }
                                    else if(wp == 1){
                                        cout << "You already have the wooden plate!";

                                    }
                                }
                                else if(item2 == "Wooden Bowl"){

                                    if(wb == 0){
                                        wb = 1;
                                        item = 2;
                                    }
                                    else if(wb == 1){
                                        cout << "You already have the wooden bowl!";

                                    }
                                }
                                else if(item2 == "Wooden Cup"){

                                    if(wc == 0){
                                        wc = 1;
                                        item = 2;
                                    }
                                    else if(wc == 1){
                                        cout << "You already have the wooden cup!";

                                    }
                                }
                                else if(item2 == "Ceramic Bowl"){

                                    if(cb == 0){
                                        cb = 1;
                                        item = 2;
                                    }
                                    else if(cb == 1){
                                        cout << "You already have the ceramic bowl!";

                                    }
                                }
                                else if(item2 == "Ceramic Plate"){

                                    if(cp == 0){
                                        cp = 1;
                                        item = 2;
                                    }
                                    else if(cp == 1){
                                        cout << "You already have the ceramic plate!";
;
                                    }
                                }
                                else if(item2 == "Glass"){

                                    if(gl == 0){
                                        gl = 1;
                                        item = 2;
                                    }
                                    else if(gl == 1){
                                        cout << "You already have the glass!";

                                    }
                                }
                                else
                                {
                                    cout << "Unrecognised command!" << endl;
                                    cout << "Please enter again: ";

                                }
                        }
                    }
                    }
                    else if(item == 2){
                        cout << "Do you want to put back your items?\n";
                        take = textInput();
                        if(take == "Yes"){
                            item = 0;
                            sf = 0;
                            sk = 0;
                            ss = 0;
                            rs = 0;
                            rf = 0;
                            rk = 0;
                            wp = 0;
                            wc = 0;
                            wb = 0;
                            cb = 0;
                            cp = 0;
                            gl = 0;

                            cout << "You return to the corridor.\n\n";
                            waitForAnyKey();
                            level = 17;
                            goto newlevel;
                        }
                        else if(take == "No"){
                            cout << "You return to the corridor.\n\n";
                            waitForAnyKey();
                            level = 17;
                            goto newlevel;
                        }
                        else
                        {
                            cout << "Unrecognised command!" << endl;
                            waitForAnyKey();
                            goto newlevel;
                        }

                    }

                    cout << "You leave the room to the north.\n\n";

                    waitForAnyKey();

                    level = 17;

                    goto newlevel;




        break;
//=================================================================================================================================================================
//=================================================================================================================================================================

            case 19:

                system(CLEAR_COMMAND);

                    cout << "===============================================================================\n";
                    cout << "============================TEXT QUEST=========================================\n";
                    cout << "==============================ROOM S===========================================\n\n";

                    roomS = 1;

                    drawmap();
                    drawinventory();

                    cout << "You reach a crossroads, would you like to go North, South or West? \n";
                    levelchoice = textInput();
                    if(levelchoice == "North"){
                        level = 20;
                        goto newlevel;
                    }
                    else if(levelchoice == "South" && trap6 == 0){
                        trap6 = 1;
                        cout << "You wander down the corridor, when the ground crumbles beneath your feet and starts to fall away!\n\n";
                        if(agi >= 7){
                            cout << "You jump from floor tile to floor tile as the ground continues to fall away,\neventually making it back to the crossroads!";
                            level = 19;
                            trap6 = 2;

                            goto newlevel;
                        }
                        else if(agi <= 6){
                            cout << "You try to make your way back to the corridor, but can't move fast enough!\nYou are dead!\n\n";
                            waitForAnyKey();
                            gameOn = false;
                        }
                    }
                    else if(levelchoice == "South" && trap6 == 2){
                        cout << "You look over the precipice and thank god you were fast enough!\nYou return to the crossroads\n\n";
                        waitForAnyKey();
                        level = 19;
                        goto newlevel;
                    }
                    else if(levelchoice == "West"){
                        level = 17;
                        goto newlevel;
                    }
                    else
                    {
                        cout << "Unrecognised command!" << endl;
                        waitForAnyKey();
                        goto newlevel;
                    }

        break;
//=================================================================================================================================================================
//=================================================================================================================================================================

            case 20:

                system(CLEAR_COMMAND);

                    cout << "===============================================================================\n";
                    cout << "============================TEXT QUEST=========================================\n";
                    cout << "=====================ROOM T===THE SILVER GATE==================================\n\n";

                    roomT = 1;

                    drawmap();
                    drawinventory();

                    cout << "You come to a big silver gate!\n\n";

                    waitForAnyKey();

                    if(skey == 0){
                        cout << "\nYou grab the bars of the gate and shake them furiously, but the gate remains\nshut!\n";
                        cout << "Would you like to go North or South?\n";
                        levelchoice = textInput();
                        if(levelchoice == "North"){
                            level = 11;
                            goto newlevel;
                        }
                        else if(levelchoice == "South"){
                            level = 19;
                            goto newlevel;
                        }
                        else
                        {
                            cout << "Unrecognised command!" << endl;
                            waitForAnyKey();
                            goto newlevel;
                        }
                    }
                    else if(skey == 1){
                        cout << "\nYou turn the silver key in the lock and the gate swings open!\n\n";
                        waitForAnyKey();
                        cout << "Would you like to go North, East or South?\n";
                        levelchoice = textInput();
                        if(levelchoice == "North"){
                            level = 11;
                            goto newlevel;
                        }
                        else if(levelchoice == "East"){
                            level = 21;
                            goto newlevel;
                        }
                        else if(levelchoice == "South"){
                            level = 19;
                            goto newlevel;
                        }
                        else
                        {
                            cout << "Unrecognised command!" << endl;
                            waitForAnyKey();
                            goto newlevel;
                        }
                    }

        break;

//=================================================================================================================================================================
//=================================================================================================================================================================

            case 21:

                system(CLEAR_COMMAND);

                    cout << "===============================================================================\n";
                    cout << "============================TEXT QUEST=========================================\n";
                    cout << "======================ROOM U===THE GOLDEN GATE=================================\n\n";

                    roomU = 1;
                    drawmap();
                    drawinventory();

                    if(goldknight == 1){
                        cout << "You see a golden gate, and a Knight in wonderfully gilded armour.\n";
                        cout << "Golden Knight: I will not fight you until I've had something to drink!\nYou cannot pass without fighting me honourably!\n\n";

                        waitForAnyKey();

                            if(wc == 1 || gl == 1){
                                cout << "You give the fill the cup with mead from the keg to the\nside of the room.\nThen give it to the knight.\n";
                                cout << "Golden Knight: Ah thank you! Now, choose your weapon and we shall do battle!\n\n";

                                wc = 0;
                                gl = 0;

                                waitForAnyKey();
                                tries = 2;

                                tryagain:
                                cout << "Choose either your sword, pointed stick, bow or try to cast a magic spell! (For magic, type Spell, as this is the weapon)\n";

                                if(tries != 0){

                                weapon = textInput();

                                if(weapon == "Sword"){

                                    if(sw >= 1){
                                        cout << "You engage the Knight in honourable combat!\nAfter a tough fight you emerge victorious!\n\n";
                                        waitForAnyKey();
                                        cout << "Golden Knight: You have bested me in single combat! Here is the key to the gate!\n\n";
                                        gkey = 1;
                                        goldknight = 0;
                                        cout << "You open the gate an head through to the next challenge...\n\n";
                                        level = 22;
                                        waitForAnyKey();
                                        goto newlevel;
                                    }
                                    else if(sw == 0){
                                        cout << "You must have a sword for this option!\n\n";
                                        waitForAnyKey();
                                        goto tryagain;
                                    }
                                }
                                else if(weapon == "Pointed Stick")
                                {
                                    if(ps >= 1){
                                        cout << "You engage the Knight in honourable combat!\nAfter a tough fight you emerge victorious!\n\n";
                                        waitForAnyKey();
                                        cout << "Golden Knight: You have bested me in single combat! Here is the key to the gate!\n\n";
                                        gkey = 1;
                                        goldknight = 0;
                                        cout << "You open the gate an head through to the next challenge...\n\n";
                                        level = 22;
                                        waitForAnyKey();
                                        goto newlevel;
                                    }
                                    else if(ps == 0){
                                        cout << "You must have a sword for this option!\n\n";
                                        waitForAnyKey();
                                        goto tryagain;
                                    }

                                }
                                else if(weapon == "Bow"){

                                    if(bw >= 1 && ar >= 1){
                                        cout << "You draw your bow, but the knight swings his sword and cuts it in half!\n";
                                        tries --;
                                        bw = 0;
                                        goto tryagain;
                                    }
                                    else if(bw == 0 || ar == 0){
                                        cout << "You must have a bow and at least one arrow for this option!\n\n";
                                        waitForAnyKey();
                                        goto tryagain;
                                    }
                                }
                                else if(weapon == "Spell"){
                                    cout << "You shoot a ball of fire from your hands, but it simply hits the knight's\narmour!\n";
                                    tries --;
                                    goto tryagain;
                                }
                                else
                                {
                                    cout << "Unrecognised command!" << endl;
                                    cout << "Please enter again: ";
                                    goto tryagain;
                                }

                            }
                            else if(tries == 0){
                                cout << "The Golden Knight has defeated you!\nYou are dead!\n\n";
                                waitForAnyKey();
                                gameOn = false;
                            }
                            }
                            else if(gl == 0 && wc == 0){
                                cout << "You have no way of giving the Knight a drink, so\nyou turn back!\n\n";
                                waitForAnyKey();
                                level = 20;
                                goto newlevel;
                            }
                    }
                    else if(goldknight == 0){
                        cout << "You see the Golden Knight happily drinking by the keg of mead.\nWould you like to go East or West? ";
                        levelchoice = textInput();
                        if(levelchoice == "East"){
                            level = 22;
                            goto newlevel;
                        }
                        else if(levelchoice == "West"){
                            level = 20;
                            goto newlevel;
                        }
                        else
                        {
                            cout << "Unrecognised command!" << endl;
                            waitForAnyKey();
                            goto newlevel;
                        }
                    }
        break;

//=================================================================================================================================================================
//=================================================================================================================================================================

            case 22:

                system(CLEAR_COMMAND);

                    cout << "===============================================================================\n";
                    cout << "============================TEXT QUEST=========================================\n";
                    cout << "======================ROOM V===THE BLACK GATE==================================\n\n";

                    roomV = 1;

                    drawmap();
                    drawinventory();

                    if(blackknight == 1){
                        cout << "An imposing Knight, armoured entirely in Black metal stands before you, it\nis clear you must fight him if you wish to continue.\n\n";
                        tryagain2:
                        cout << "Choose either your sword or your bow, or try to cast a magic spell!\n";

                        weaponloopV:

                        weapon = textInput();

                        if(weapon == "Sword"){

                            if(sw != 0){

                            weapstr = str + sw;
                            }
                            else if(sw == 0){
                                cout << "You must have a sword for this option!\n\n";
                                waitForAnyKey();
                                goto tryagain2;
                            }

                                if(weapstr >= 8){
                                    cout << "Your skill with a sword is second to none!\nYou swiftly prove this to the Black Knight!\n\n";

                                    blackknight = 0;
                                    bkey = 1;

                                    cout << "Black Knight: You have bested me, but I warn you, what lies beyond this gate\nis more terrible than you could ever imagine!\nWould you like to proceed anyway?\n";

                                    blackgate = textInput();

                                    if(blackgate == "Yes"){
                                        level = 23;
                                        goto newlevel;
                                    }
                                    else if(blackgate == "No"){
                                        level = 21;
                                        goto newlevel;
                                    }
                                }
                                else if(weapstr <= 7){

                                    cout << "The Black Knight runs you through with his sword!/nYou are dead!\n\n";
                                    waitForAnyKey();

                                    gameOn = false;
                                }
                        }
                        else if(weapon == "Bow"){

                            if(bw != 0 && ar != 0){

                                weapagi = bw + agi;
                                    if(weapagi >= 8){
                                        cout << "Your honed aim and practiced archery skills allows you to hit the Black Knight\nin a weak part of his armour.\n\n";

                                        blackknight = 0;
                                        bkey = 1;

                                        cout << "Black Knight:  You have bested me, but I warn you, what lies beyond this gate\nis more terrible than you could ever imagine!\nWould you like to proceed anyway?\n";

                                    blackgate = textInput();

                                    if(blackgate == "Yes"){
                                        level = 23;
                                        goto newlevel;
                                    }
                                    else if(blackgate == "No"){
                                        level = 21;
                                        goto newlevel;
                                    }
                                    }
                                    else if(weapagi <= 7){
                                        cout << "Despite loosing an arrow towards your opponent your shots are\nuseless.\nThe Black Knight kills you!\nYou are dead!\n\n";

                                        waitForAnyKey();

                                        gameOn = false;
                                    }
                            }
                            else if(bw == 0 || ar == 0){
                                cout << "You must have a bow and at least one arrow for this option!\n\n";
                                waitForAnyKey();
                                goto tryagain2;
                            }
                        }
                        else if(weapon == "Spell"){
                                weapintel = intel + 1;
                                if(weapintel >= 8){
                                    cout << "You cast a fire spell at the Black Knight, cooking him in his armour!\n\n";

                                    blackknight = 0;
                                    bkey = 1;

                                    cout << "Black Knight: You have bested me, but I warn you, what lies beyond this gate\nis more terrible than you could ever imagine!\nWould you like to proceed anyway?\n";

                                    blackgate = textInput();

                                    if(blackgate == "Yes"){
                                        level = 23;
                                        goto newlevel;
                                    }
                                    else if(blackgate == "No"){
                                        level = 21;
                                        goto newlevel;
                                    }
                                }
                                else if(weapintel <= 7){
                                    cout << "You try to freeze the Black Knight in his armour, but it fails!\nThe Black Knight kills you!\nYou are dead!\n\n";
                                    waitForAnyKey();
                                    gameOn = false;
                                }
                        }
                        else
                        {
                            cout << "Unrecognised command!" << endl;
                            cout << "Please enter again: ";
                            goto weaponloopV;
                        }
                    }
                    else if(blackknight == 0){
                        cout << "Black Knight: Are you ready to enter?\n";
                        blackgate = textInput();
                        if(blackgate == "Yes"){
                            level = 23;
                            goto newlevel;
                        }
                        else if(blackgate == "No"){
                            level = 21;
                            goto newlevel;
                        }
                        else
                        {
                            cout << "Unrecognised command!" << endl;
                            waitForAnyKey();
                            goto newlevel;
                        }
                    }



        break;

//=================================================================================================================================================================
//=================================================================================================================================================================

            case 23:

                system(CLEAR_COMMAND);

                    cout << "===============================================================================\n";
                    cout << "============================TEXT QUEST=========================================\n";
                    cout << "==============================ROOM W===========================================\n\n";

                    if(roomW == 0){
                    tries = 3;
                    }

                    roomW = 1;

                    drawmap();
                    drawinventory();

                    cout << "You enter a large cave like room...\n\n";

                    waitForAnyKey();

                    cout << "Suddenly, a dragon appears from the back of the cave!\n\n";

                    tryagain3:

                    if(tries != 0){
                    cout << "Choose a weapon from your inventory to fight with or try to cast a spell!\n";
                    weapon = textInput();

                        if(weapon == "Rusty Spoon"){

                            cout << "You look at the rusty spoon and wield it!\nPower begins to channel through it, and it begins to glow.\nYou hurl the spoon at the dragon with all your might!\nIt hits the dragon, and the beast shatters into a million pieces!\nYou have succesfully completed TextQuest!\n\n";

                            waitForAnyKey();
                            gameOn = false;
                        }
                        else if(weapon == "Sword"){
                            if(sw != 0){
                                cout << "You swing your sword against the dragon and it smashes hard against\nthe dragon's scales!\n\n";
                                waitForAnyKey();

                                tries --;
                                goto tryagain3;
                            }
                            if(sw == 0){
                                cout << "You must have a sword for this option!\n\n";
                                waitForAnyKey();
                                goto tryagain3;
                            }
                        }
                        else if(weapon == "Bow"){
                            if(bw != 0 && ar != 0){
                                cout << "You quickly fire off an arrow at the dragon, but it bounces off the dragon's scales!\n\n";
                                waitForAnyKey();

                                ar --;
                                tries --;

                                goto tryagain3;
                            }
                            else if(bw == 0 || ar == 0){
                                cout << "You must have a bow and at least one arrow fo rthis option!\n\n";
                                waitForAnyKey();
                                goto tryagain3;
                            }
                        }
                        else if(weapon == "Spell"){
                            cout << "You cast an arc of lightning towards the dragon, but it has no effect!\n\n";

                                tries --;

                            waitForAnyKey();
                            goto tryagain3;
                        }
                        else if(weapon == "Rusty Knife"){
                            if(rk == 0){
                                cout << "You don't have this item!\n\n";

                                waitForAnyKey();

                                goto tryagain3;
                            }
                            else if(rk == 1){
                                cout << "You draw the knife, but the blade breaks as you pull it out!\n\n";
                                waitForAnyKey();
                                goto tryagain3;
                            }
                        }
                        else if(weapon == "Rusty Fork"){
                            if(rf == 1){
                                cout << "As you draw the fork, the prongs break off!\n\n";

                                tries --;

                                waitForAnyKey();

                                goto tryagain3;
                            }
                            else if(rf == 0){
                                cout << "You don't have this item!\n\n";

                                waitForAnyKey();

                                goto tryagain3;
                            }
                        }
                        else if(weapon == "Silver Spoon"){
                            if(ss == 0){
                                cout << "You don't have this item!\n\n";

                                waitForAnyKey();

                                goto tryagain3;
                            }
                            else if(ss == 1){
                                cout << "Don't be ridiculous! A spoon doesn't even have an edge!\n\n";

                                waitForAnyKey();

                                goto tryagain3;
                            }
                        }
                        else if(weapon == "Silver Fork"){
                                if(sf == 1){
                                    cout << "You try to stab the dragon with the fork, but its scales are too strong!\n";
                                    tries --;

                                    waitForAnyKey();

                                    goto tryagain3;
                                }
                                else  if(sf == 0){
                                    cout << "You don't have this item!\n\n";
                                    waitForAnyKey();

                                    goto tryagain3;
                                }
                    }
                    else if(weapon == "Silver Knife"){
                                if(sk == 1){
                                    cout << "You try to stab the dragon with the knife, but its scales are too strong!\n\n";
                                    tries --;

                                    waitForAnyKey();

                                    goto tryagain3;
                                }
                                else  if(sk == 0){
                                    cout << "You don't have this item!\n\n";
                                    waitForAnyKey();

                                    goto tryagain3;
                                }
                    }
                    else if(weapon == "Wooden Plate"){
                        if(wp == 1){
                            cout << "You try to smack the dragon with the plate, but its scales are too strong!\n\n";
                            tries --;

                            waitForAnyKey();

                            goto tryagain3;
                        }
                        else if(wp == 0){
                            cout << "You don't have this item!\n\n";
                            waitForAnyKey();

                            goto tryagain3;
                        }
                    }
                    else if(weapon == "Wooden Bowl"){
                            if(wb == 1){
                            cout << "You try to smack the dragon with the bowl, but its scales are too strong!\n\n";
                            tries --;

                            waitForAnyKey();

                            goto tryagain3;
                        }
                        else if(wb == 0){
                            cout << "You don't have this item!\n\n";
                            waitForAnyKey();

                            goto tryagain3;
                        }
                    }
                    else if(weapon == "Ceramic Plate"){
                        if(cp == 1){
                            cout << "You try to smack the dragon with the plate, but its scales are too strong!\n\n";
                            tries --;

                            waitForAnyKey();

                            goto tryagain3;
                        }
                        else if(cp == 0){
                            cout << "You don't have this item!\n\n";
                            waitForAnyKey();

                            goto tryagain3;
                        }
                    }
                    else if(weapon == "Ceramic Bowl"){
                        if(cb == 1){
                            cout << "You try to smack the dragon with the bowl, but its scales are too strong!\n\n";
                            tries --;

                            waitForAnyKey();

                            goto tryagain3;
                        }
                        else if(cb == 0){
                            cout << "You don't have this item!\n\n";
                            waitForAnyKey();

                            goto tryagain3;
                        }
                    }
                    else if(weapon == "Wooden Cup"){
                            cout << "You don't have this item!\n\n";
                            waitForAnyKey();

                            goto tryagain3;
                    }
                    else if(weapon == "Glass"){
                            cout << "You don't have this item!\n\n";
                            waitForAnyKey();

                            goto tryagain3;
                    }
                    else
                    {
                        cout << "Unrecognised command!" << endl;
                        cout << "Please enter again: ";
                        goto tryagain3;
                    }
                    }
                    if(tries == 0){
                        cout << "The dragon lunges towards you and eats you!\nYou are dead!\n\n";
                        waitForAnyKey();
                        gameOn = false;
                    }

        break;

//=================================================================================================================================================================
//=================================================================================================================================================================

            case 24:

                system(CLEAR_COMMAND);

                    cout << "===============================================================================\n";
                    cout << "============================TEXT QUEST=========================================\n";
                    cout << "==============================ROOM Y===========================================\n\n";

                    roomY = 1;

                    drawmap();
                    drawinventory();

                    cout << "You reach a crossroads do you want to go East, South or West?\n";
                    levelchoice = textInput();

                    if(levelchoice == "East" && trap2 == 0){
                        trap2 = 1;
                        cout << "You walk down the corridor when the wall behind you falls,\nblocking your exit. You see a series of symbols on the walls around you.\n\n";

                        waitForAnyKey();

                        trap = intel + str;

                        if(trap >= 10){
                            cout << "You notice that the pattern of symbols is symmetrical about a certain point.\nOn a hunch you hit that point with all your might and the wall falls \naway. You go down the corridor and return to room Y!\n\n";
                            waitForAnyKey();
                            trap2 = 2;
                            level = 24;
                            goto newlevel;
                        }
                        else if(trap <= 9){
                            cout << "You are trapped here for eternity!\nYou wil eventually be dead!\n\n";
                            waitForAnyKey();
                            gameOn = false;
                        }

                    }
                    else if (levelchoice == "East" && trap2 == 2){
                            cout << "All you can find are crumbled rocks, you return to room Y.\n\n";
                            level = 24;
                            goto newlevel;
                    }
                    else if(levelchoice == "South"){
                        level = 7;
                        goto newlevel;
                    }
                    else if(levelchoice == "West"){
                        level = 8;
                        goto newlevel;
                    }
                    else
                    {
                        cout << "Unrecognised command!" << endl;
                        waitForAnyKey();
                        goto newlevel;
                    }


        break;

//=================================================================================================================================================================
//=================================================================================================================================================================

            case 25:

                system(CLEAR_COMMAND);

                    cout << "===============================================================================\n";
                    cout << "============================TEXT QUEST=========================================\n";
                    cout << "====================ROOM Z===WIZARD'S QUARTERS=================================\n\n";

                    roomZ = 1;

                    cout << "You enter a strange room full of dusty tomes and phials full of vibrantly\ncoloured liquids. There is an old book lying open on a desk.\nDo you want to read it, or go South? \n";
                    levelchoice = textInput();
                    if(levelchoice == "Read"){

                        cout << "The text reads:                                                             \n";
                        cout << "This is the diary of Edgar the Wonderous, Wizard of the Druid Kingdom. I was\n";
                        cout << "trapped in this godforsaken cave after an expedition was sent out from the  \n";
                        cout << "village of Ankr Fjor. First we went about building our own living quarters, \n";
                        cout << "but as we delved we found an ancient dining hall, already completely set out\n";
                        cout << "for a meal! It was worrying to say the least. However we continued to dig   \n";
                        cout << "until we found it. A beast more terrifying than anything I'd ever seen!     \n";
                        cout << "Before we locked it in a dungeon it yelled out a curse that bound us to this\n";
                        cout << "place. One of the knights managed to recover an old scroll that said the    \n";
                        cout << "only way to defeat the beast was with an Ancient Weapon, hidden in the most \n";
                        cout << "unsuspecting places. We searched everywhere, but we couldn't find it. The   \n";
                        cout << "Yellow Knight was the first to lose his mind, locking himself in a room and \n";
                        cout << "destroying the key! Fortunately I have created a solution that should burn  \n";
                        cout << "through the lock! However, I fear I may have been working with the toxic    \n";
                        cout << "solution for too long and I may be incredibly vulnerable to\n\n";

                        cout << "After reading the journal, you leave to the south.\n\n";
                        gk = 1;
                        if(type == "Mage"){
                            intel = 10;
                        }

                        level = 10;
                        waitForAnyKey();
                        goto newlevel;
                    }
                    else if(levelchoice == "South"){
                        level = 10;
                        goto newlevel;
                    }
                    else
                    {
                        cout << "Unrecognised command!" << endl;
                        waitForAnyKey();
                        goto newlevel;
                    }

        break;


//=================================================================================================================================================================
//=================================================================================================================================================================


            }
    /*    case 2:
            gameOn = false;

        break;

        case 3:

            cout << "Please choose again! ";
            cin >> enter;

        break;
*/
        }
  //  }
    }
    return 0;
}

