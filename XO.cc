#include <iostream>
#include <string>
#include <limits>

using namespace std;

string board[10], pl, pl1, pl2;
void boardfunc(), checkfunc(), resetboard(), draw(), lose();
void player11(), player22(), engine1(), engine2(), XO();
int player, c = 0, player1, player2, choice, sc1 = 0, sc2 = 0, hm;

int main (){

    XO();

    return 0;
}

void XO(){
    cout << " 1 PLAYER - ENTER '1'\n2 PLAYERS - ENTER '2'\n   QUIT - ENTER '0'\n";    cin >> choice;
    cout << "\n LET'S START THE GAME !!!\n";
    pl = "PLAYER";  pl1 = "PLAYER X";   pl2 = "PLAYER O";
    while(1)
        if (choice == 1){
            resetboard();
            engine1();
            cout << "\n      RETRY - ENTER '1'\nSWITCH TO 2 PLAYERS - ENTER '2'\n      QUIT  - ENTER '0'\n";   cin >> choice;
        }
        else if (choice == 2){
            resetboard();
            engine2();
            cout << "\nSWITCH TO 1 PLAYER - ENTER '1'\n     RETRY - ENTER '2'\n     QUIT  - ENTER '0'\n";   cin >> choice;
        }   else break;
}

void checkfunc(){
    boardfunc();
    cout << pl << ": "; cin >> player;
    while (!cin.good() || (player != 1 && player != 2 && player != 3 && player != 4 && player != 6
    && player != 7 && player != 8 && player != 9 || board[player] == "X" || board[player] == "O")){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        boardfunc();
        cout << "    PLAY A VALID MOVE !" << endl;
        cout << pl << ": "; cin >> player;
    }
    board[player] = "O";
}
void lose(){
    boardfunc();
    cout << "    You Lose !" << endl;
}
void draw(){
    boardfunc();
    cout << "    Draw !" << endl;
}
void boardfunc(){
    cout << "     |     |     " << endl;
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << endl;
    cout << "     |     |     " << endl << endl;
}

void resetboard(){
    board[1] = "1";     board[2] = "2";     board[3] = "3";
    board[4] = "4";     board[5] = "5";     board[6] = "6";
    board[7] = "7";     board[8] = "8";     board[9] = "9";
}

void engine1(){
    
    board[5] = "X";
    checkfunc();
    switch (player){
        case 1: board[9] = "X";
            checkfunc();
            switch (player){
                case 2: board[3] = "X";
                    checkfunc();
                    switch (player){
                        case 4: board[6] = "X";
                            lose(); break;
                        case 6: board[7] = "X";
                            lose(); break;
                        case 7: board[6] = "X";
                            lose(); break;
                        case 8: board[7] = "X";
                            lose(); break;
                    } break;
                case 3: board[2] = "X";
                    checkfunc();
                    switch (player){
                        case 4: board[8] = "X";
                            lose(); break;
                        case 6: board[8] = "X";
                            lose(); break;
                        case 7: board[8] = "X";
                            lose(); break;
                        case 8: board[4] = "X";
                            checkfunc();
                            switch (player){
                                case 6: board[7] = "X";
                                    draw(); break;
                                case 7: board[6] = "X";
                                    lose(); break;
                            } break;
                    } break;
                case 4: board[7] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[3] = "X";
                            lose(); break;
                        case 3: board[8] = "X";
                            lose(); break;
                        case 6: board[3] = "X";
                            lose(); break;
                        case 8: board[3] = "X";
                            lose(); break;
                    } break;
                case 6: board[7] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[3] = "X";
                            lose(); break;
                        case 3: board[8] = "X";
                            lose(); break;
                        case 4: board[3] = "X";
                            lose(); break;
                        case 8: board[3] = "X";
                            lose(); break;
                    } break;
                case 7: board[4] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[6] = "X";
                            lose(); break;
                        case 3: board[6] = "X";
                            lose(); break;
                        case 6: board[2] = "X";
                            checkfunc();
                            switch (player){
                                case 8: board[3] = "X";
                                    draw(); break;
                                case 3: board[8] = "X";
                                    lose(); break;
                            } break;
                        case 8: board[6] = "X";
                            lose(); break;
                    } break;
                case 8: board[3] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[6] = "X";
                            lose(); break;
                        case 4: board[6] = "X";
                            lose(); break;
                        case 6: board[7] = "X";
                            lose(); break;
                        case 7: board[6] = "X";
                            lose(); break;
                    } break;
            } break;
        case 2: board[1] = "X";
            checkfunc();
            switch (player){
                case 3: board[9] = "X";
                    lose(); break;
                case 4: board[9] = "X";
                    lose(); break;
                case 6: board[9] = "X";
                    lose(); break;
                case 7: board[9] = "X";
                    lose(); break;
                case 8: board[9] = "X";
                    lose(); break;
                case 9: board[7] = "X";
                    checkfunc();
                    switch (player){
                        case 3: board[4] = "X";
                            lose(); break;
                        case 4: board[3] = "X";
                            lose(); break;
                        case 6: board[3] = "X";
                            lose(); break;
                        case 8: board[4] = "X";
                            lose(); break;
                    } break;
            } break;
        case 3: board[7] = "X";
            checkfunc();
            switch (player){
                case 1: board[2] = "X";
                    checkfunc();
                    switch (player){
                        case 4: board[8] = "X";
                            lose(); break;
                        case 6: board[8] = "X";
                            lose(); break;
                        case 8: board[6] = "X";
                            checkfunc();
                            switch (player){
                                case 4: board[7] = "X";
                                    draw(); break;
                                case 9: board[4] = "X";
                                    lose(); break;
                            } break;
                        case 9: board[8] = "X";
                            lose(); break;
                    } break;
                case 2: board[1] = "X";
                    checkfunc();
                    switch (player){
                        case 4: board[9] = "X";
                            lose(); break;
                        case 6: board[9] = "X";
                            lose(); break;
                        case 8: board[4] = "X";
                            lose(); break;
                        case 9: board[4] = "X";
                            lose(); break;
                    } break;
                case 4: board[9] = "X";
                    checkfunc();
                    switch (player){
                        case 1: board[8] = "X";
                            lose(); break;
                        case 2: board[1] = "X";
                            lose(); break;
                        case 6: board[8] = "X";
                            lose(); break;
                        case 8: board[1] = "X";
                            lose(); break;
                    } break;
                case 6: board[9] = "X";
                    checkfunc();
                    switch (player){
                        case 1: board[8] = "X";
                            lose(); break;
                        case 2: board[1] = "X";
                            lose(); break;
                        case 4: board[8] = "X";
                            lose(); break;
                        case 8: board[1] = "X";
                            lose(); break;
                    } break;
                case 8: board[1] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[4] = "X";
                            lose(); break;
                        case 4: board[9] = "X";
                            lose(); break;
                        case 6: board[9] = "X";
                            lose(); break;
                        case 9: board[4] = "X";
                            lose(); break;
                    } break;
                case 9: board[6] = "X";
                    checkfunc();
                    switch (player){
                        case 1: board[4] = "X";
                            lose(); break;
                        case 2: board[4] = "X";
                            lose(); break;
                        case 4: board[2] = "X";
                            checkfunc();
                            switch (player){
                                case 1: board[8] = "X";
                                    lose(); break;
                                case 8: board[1] = "X";
                                    draw(); break;
                            } break;
                        case 8: board[4] = "X";
                            lose(); break;
                    } break;
            } break;
        case 4: board[1] = "X";
            checkfunc();
            switch (player){
                case 2: board[9] = "X";
                    lose(); break;
                case 3: board[9] = "X";
                    lose(); break;
                case 6: board[9] = "X";
                    lose(); break;
                case 7: board[9] = "X";
                    lose(); break;
                case 8: board[9] = "X";
                    lose(); break;
                case 9: board[3] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[7] = "X";
                            lose(); break;
                        case 6: board[2] = "X";
                            lose(); break;
                        case 7: board[2] = "X";
                            lose(); break;
                        case 8: board[7] = "X";
                            lose(); break;
                    } break;
            } break;
        case 6: board[3] = "X";
            checkfunc();
            switch (player){
                case 1: board[7] = "X";
                    lose(); break;
                case 2: board[7] = "X";
                    lose(); break;
                case 4: board[7] = "X";
                    lose(); break;
                case 7: board[1] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[9] = "X";
                            lose(); break;
                        case 4: board[2] = "X";
                            lose(); break;
                        case 8: board[9] = "X";
                            lose(); break;
                        case 9: board[2] = "X";
                            lose(); break;
                    } break;
                case 8: board[7] = "X";
                    lose(); break;
                case 9: board[7] = "X";
                    lose(); break;
            } break;
        case 7: board[3] = "X";
            checkfunc();
            switch (player){
                case 1: board[4] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[6] = "X";
                            lose(); break;
                        case 6: board[8] = "X";
                            checkfunc();
                            switch (player){
                                case 2: board[9] = "X";
                                    draw(); break;
                                case 9: board[2] = "X";
                                    lose(); break;
                            } break;
                        case 8: board[6] = "X";
                            lose(); break;
                        case 9: board[6] = "X";
                            lose(); break;
                    } break;
                case 2: board[9] = "X";
                    checkfunc();
                    switch (player){
                        case 1: board[6] = "X";
                            lose(); break;
                        case 4: board[1] = "X";
                            lose(); break;
                        case 6: board[1] = "X";
                            lose(); break;
                        case 8: board[6] = "X";
                            lose(); break;
                    } break;
                case 4: board[1] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[9] = "X";
                            lose(); break;
                        case 6: board[2] = "X";
                            lose(); break;
                        case 8: board[9] = "X";
                            lose(); break;
                        case 9: board[2] = "X";
                            lose(); break;
                    } break;
                case 6: board[1] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[9] = "X";
                            lose(); break;
                        case 4: board[2] = "X";
                            lose(); break;
                        case 8: board[9] = "X";
                            lose(); break;
                        case 9: board[2] = "X";
                            lose(); break;
                    } break;
                case 8: board[9] = "X";
                    checkfunc();
                    switch (player){
                        case 1: board[6] = "X";
                            lose(); break;
                        case 2: board[6] = "X";
                            lose(); break;
                        case 4: board[1] = "X";
                            lose(); break;
                        case 6: board[1] = "X";
                            lose(); break;
                    } break;
                case 9: board[8] = "X";
                    checkfunc();
                    switch (player){
                        case 1: board[2] = "X";
                            lose(); break;
                        case 2: board[4] = "X";
                            checkfunc();
                            switch (player){
                                case 1: board[6] = "X";
                                    lose(); break;
                                case 6: board[1] = "X";
                                    draw(); break;
                            } break;
                        case 4: board[2] = "X";
                            lose(); break;
                        case 6: board[2] = "X";
                            lose(); break;
                    } break;
            } break;
        case 8: board[7] = "X";
            checkfunc();
            switch (player){
                case 1: board[3] = "X";
                    lose(); break;
                case 2: board[3] = "X";
                    lose(); break;
                case 3: board[1] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[4] = "X";
                            lose(); break;
                        case 4: board[9] = "X";
                            lose(); break;
                        case 6: board[9] = "X";
                            lose(); break;
                        case 9: board[4] = "X";
                            lose(); break;
                    } break;
                case 4: board[3] = "X";
                    lose(); break;
                case 6: board[3] = "X";
                    lose(); break;
                case 9: board[3] = "X";
                    lose(); break;
            } break;
        case 9: board[1] = "X";
            checkfunc();
            switch (player){
                case 2: board[7] = "X";
                    checkfunc();
                    switch (player){
                        case 3: board[4] = "X";
                            lose(); break;
                        case 4: board[3] = "X";
                            lose(); break;
                        case 6: board[3] = "X";
                            lose(); break;
                        case 8: board[4] = "X";
                            lose(); break;
                    } break;
                case 3: board[6] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[4] = "X";
                            lose(); break;
                        case 4: board[8] = "X";
                            checkfunc();
                            switch (player){
                                case 2: board[7] = "X";
                                    draw(); break;
                                case 7: board[2] = "X";
                                    lose(); break;
                            } break;
                        case 7: board[4] = "X";
                            lose(); break;
                        case 8: board[4] = "X";
                            lose(); break;
                    } break;
                case 4: board[3] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[7] = "X";
                            lose(); break;
                        case 6: board[2] = "X";
                            lose(); break;
                        case 7: board[2] = "X";
                            lose(); break;
                        case 8: board[7] = "X";
                            lose(); break;
                    } break;
                case 6: board[3] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[7] = "X";
                            lose(); break;
                        case 4: board[2] = "X";
                            lose(); break;
                        case 7: board[2] = "X";
                            lose(); break;
                        case 8: board[7] = "X";
                            lose(); break;
                    } break;
                case 7: board[8] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[6] = "X";
                            checkfunc();
                            switch (player){
                                case 3: board[4] = "X";
                                    lose(); break;
                                case 4: board[3] = "X";
                                    draw(); break;
                            } break;
                        case 3: board[2] = "X";
                            lose(); break;
                        case 4: board[2] = "X";
                            lose(); break;
                        case 6: board[2] = "X";
                            lose(); break;
                    } break;
                case 8: board[7] = "X";
                    checkfunc();
                    switch (player){
                        case 2: board[4] = "X";
                            lose(); break;
                        case 3: board[4] = "X";
                            lose(); break;
                        case 4: board[3] = "X";
                            lose(); break;
                        case 6: board[3] = "X";
                            lose(); break;
                    } break;
            } break;
    }
}

void engine2(){

    while (c == 0){
        player11();
        if (c != 0){
            cout << "   DRAW !" << endl;
            boardfunc();
            break;
        }
        if (board[1] == "X" && board[2] == "X" && board[3] == "X" ||
        board[4] == "X" && board[5] == "X" && board[6] == "X" ||
        board[7] == "X" && board[8] == "X" && board[9] == "X" ||
        board[1] == "X" && board[4] == "X" && board[7] == "X" ||
        board[2] == "X" && board[5] == "X" && board[8] == "X" ||
        board[3] == "X" && board[6] == "X" && board[9] == "X" ||
        board[1] == "X" && board[5] == "X" && board[9] == "X" ||
        board[3] == "X" && board[5] == "X" && board[7] == "X"){
            boardfunc();
            cout << "   " << pl1 <<" WON THE GAME !!!" << endl;
            sc1++;
            break;
    }
        player22();
        if (board[1] == "O" && board[2] == "O" && board[3] == "O" ||
        board[4] == "O" && board[5] == "O" && board[6] == "O" ||
        board[7] == "O" && board[8] == "O" && board[9] == "O" ||
        board[1] == "O" && board[4] == "O" && board[7] == "O" ||
        board[2] == "O" && board[5] == "O" && board[8] == "O" ||
        board[3] == "O" && board[6] == "O" && board[9] == "O" ||
        board[1] == "O" && board[5] == "O" && board[9] == "O" ||
        board[3] == "O" && board[5] == "O" && board[7] == "O"){
            boardfunc();
            cout << "   " << pl2 <<" WON THE GAME !!!" << endl;
            sc2++;
            break;
        }
    }
    cout << "\n" << pl1 << "   " << sc1 << " - " << sc2 << "   " << pl2 << endl;
}

void player11(){
    boardfunc();
    cout << "\n   " << pl1 << ":  ";    cin >> player1;
    
    while (!cin.good() || (player1 != 1 && player1 != 2 && player1 != 3 && player1 != 4 && player1 != 5 && player1 != 6
        && player1 != 7 && player1 != 8 && player1 != 9 || board[player1] == "X" || board[player1] == "O")){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        boardfunc();
        cout << "    PLAY A VALID MOVE !" << endl;
        cout << "\n   " << pl1 << ":  ";    cin >> player1;
    }
    switch (player1){
    case 1: board[1] = "X"; break;
    case 2: board[2] = "X"; break;
    case 3: board[3] = "X"; break;
    case 4: board[4] = "X"; break;
    case 5: board[5] = "X"; break;
    case 6: board[6] = "X"; break;
    case 7: board[7] = "X"; break;
    case 8: board[8] = "X"; break;
    case 9: board[9] = "X"; break;
    
    }
    if (board[1] != "1" && board[2] != "2" && board[3] != "3" && board[4] != "4" && 
    board[5] != "5" && board[6] != "6" && board[7] != "7" && board[8] != "8" && board[9] != "9"){
        cout << " GAME OVER !" << endl;
        c++;
    }
}

void player22(){
    boardfunc();
    cout << "\n   " << pl2 << ":  ";    cin >> player2;
    while (!cin.good() || (player2 != 1 && player2 != 2 && player2 != 3 && player2 != 4 && player2 != 5 && player2 != 6
    && player2 != 7 && player2 != 8 && player2 != 9 || board[player2] == "X" || board[player2] == "O")){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        boardfunc();
        cout << "    PLAY A VALID MOVE !" << endl;
        cout << "\n   " << pl2 << ":  ";    cin >> player2;
    }

    switch (player2){
        case 1: board[1] = "O"; break;
        case 2: board[2] = "O"; break;
        case 3: board[3] = "O"; break;
        case 4: board[4] = "O"; break;
        case 5: board[5] = "O"; break;
        case 6: board[6] = "O"; break;
        case 7: board[7] = "O"; break;
        case 8: board[8] = "O"; break;
        case 9: board[9] = "O"; break;
    }
}