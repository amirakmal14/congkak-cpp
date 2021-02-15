// List of function headers
#include <iostream>
#include <iomanip> //contains setw().
#include <string.h> //contains strcmp().
#include <string>
#include <conio.h> //contains getch().
#include<windows.h>

#define KAMPUNGSIZE 16 //declaring global constant.

using namespace std;

//List of function prototype
void welcomemenu(void);
void gameplay(void);
void playersignup(void);
void congkak(void);
void reset(void);
void MoveMarbles(void);
bool validatePassword(int y);
void rules(void);
string getpass(const char *prompt, bool show_asterisk);
string registerPassword(void);

//Initializing size of arrays
string player1;
string player2;
string player1pswrd;
string player2pswrd;
int kampung[KAMPUNGSIZE];

int main()
{
    cout<<"\n\t\t\t WELCOME TO CONGKAK GAME"<<endl;
    cout<<"\n\t************************************************************";
    cout<<"\n\n\tCREATED BY :";
    cout<<"\n\t1.AMIR AKMAL";
    cout<<"\n\t2.NURKAMALIA";
    cout<<"\n\t3.AMEER AIMAN";
    cout<<"\n\t4.AMIRA DEURASEH\n\n";
    system("pause"); //pause the program until user hit any button to continue

    welcomemenu();
}


void welcomemenu ()
{
    char enter;
    system("cls"); //Clear the output screen
    cout<<"\n\t\t\tWELCOME TO CONGKAK GAME";
    cout<<"\n\t************************************************************";
    //display unique lines shape
    cout<<"\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 USER MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
    cout<<"\n\t\t\t1.PLAY";
    cout<<"\n\t\t\t2.HOW TO PLAY";
    cout<<"\n\t\t\t3.EXIT";
    cout<<"\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";

    cout<<"\n\n\t\tEnter your choice: ";
    cin>>enter;
    switch(enter) //Player's choice
    {
        case '1':
            gameplay(); //start the game
            break;

        case '2':
            rules(); //display the rules and regulations of the game
            welcomemenu();
            break;

        case '3':
            system("cls"); //quit game
            cout<<"\n\n\n\n\n\n\n\a\a\t\tThank You For Playing.. See You Again !\n\n\n\n\n";
            return;
            break;

        default:
            cout<<"\n\t\t*invalid input*\n\a"; //wrong user input.User has to re-enter.
            system("pause");
            welcomemenu();
            break;
    }

}

void gameplay() //function to start game
{
    playersignup();
    reset();
    congkak();
    MoveMarbles();
}

void playersignup() //function for players to signup their name and password
{
    system("cls"); //Clear output screen of previous display
    cout<<"\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PLAYER SIGNUP \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
    cout<<"\n\t\tPlease enter Player 1 name: ";
    getline (cin, player1);
    getline (cin, player1);
    player1pswrd = registerPassword();

    system("cls"); //Clear output screen of previous display
    cout<<"\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PLAYER SIGNUP \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
    cout<<"\n\t\tPlease enter Player 2 name: ";
    getline (cin, player2);
    player2pswrd = registerPassword();
}

string registerPassword(void)
{
    string password;
    string reEnteredPassword;
    bool isValidPassword = false;

    do{
        password = getpass("\n\t\tPlease enter your password: ",true);
        reEnteredPassword = getpass("\n\t\tPlease re-enter your password: ",true);

        isValidPassword = password == reEnteredPassword;
        if (!isValidPassword){
            cout<<"\n\t\tPassword is not match! Please re-enter your password"<<endl;
        }
    }while(!isValidPassword);

    return password;
}

void congkak(void) //function to display the congkak
{
    system("cls"); //Clear the output screen
    cout<<"\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CONGKAK \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
    cout << "Let's Play!\n\n";
    cout << "\t\t\tPLAYER 1 : "<<player1<<"\n";
    cout << " o------------------------------------------------------------o" <<endl;
    cout << "/            A1    A2    A3    A4    A5    A6    A7            \\  " <<endl;
    cout << "|   /----\\  /--\\  /--\\  /--\\  /--\\  /--\\  /--\\  /--\\  /----\\    |" <<endl;
    cout << "|   |    |  " ;

    for(int i = 0; i < 7; i++)
    cout << "|" << setw(2)<<kampung[i] << "|  ";

    cout << "|    |    |" <<endl;
    cout << "|   |    |  \\--/  \\--/  \\--/  \\--/  \\--/  \\--/  \\--/  |    |    |" <<endl;
    cout << "|P2 |" << setw(3)<<kampung[15]
    << " |                                            |"
    << setw(3) <<kampung[7] << " | P1 |" <<endl;
    cout << "|   |    |  /--\\  /--\\  /--\\  /--\\  /--\\  /--\\  /--\\  |    |    |" <<endl;
    cout << "|   |    |  " ;

    for(int i = 14; i >= (KAMPUNGSIZE - 8); i--)
    cout << "|" << setw(2)<<kampung[i] << "|  ";

    cout << "|    |    |" <<endl;
    cout << "|   \\----/  \\--/  \\--/  \\--/  \\--/  \\--/  \\--/  \\--/  \\----/    |" <<endl;
    cout << "\\            B7    B6    B5    B4    B3    B2    B1             /" <<endl;
    cout << " o-------------------------------------------------------------o" <<endl;
    cout << "\t\t\tPLAYER 2 : "<<player2<<"\n";
}

void reset(void) //function to initialize the number of marbles in each holes.
{
    for(int i = 0; i < 7; i++ ){        
        kampung[i] = 7; //All 'Kampung' of player 1 starts with 7
    }

    for(int i = 7; i < 16;i++){
        kampung[i] = 7; //All 'Kampung' of player 2 starts with 7
        kampung[7] = 0; //'Rumah' of player 1 starts with zero
        kampung[15] = 0; //'Rumah' of player 2 starts with zero
    }    
}

void MoveMarbles()
{
    int x, y, j, f, k;
    int move;
    x = 1;

    do //loop starts
    {
        //Player 1 and Player 2 interchange turn to play
        if (x % 2 != 0) //Player 1 is playing
        {
            if(kampung[0] != 0 || kampung[1] != 0 || kampung[2] != 0 || kampung[3] != 0|| kampung[4] != 0 || kampung[5] != 0 || kampung[6] != 0) //when either of the 7 'kampung' still have any marble(s), game continue
            {
                congkak();
                cout<<"\n\nplayer 1 turn";
                if(validatePassword(1)) //Check validity of password for player 1
                {
                    cout<<"enter the 'kampung' you want to move : A";
                    cin>>move;
                    move--; //minus 1 to set it correspond to the array position
                    if (move <= 6 && move >= 0) //Ensure user choose a valid 'kampung' between 1 to 7 only
                    {
                        if (kampung[move] > 0) //Ensure 'kampung' chosen is not empty
                        {
                            f = kampung[move];
                            kampung[move] = 0; //'Kampung' that is chosen will be emptied
                            k = move + 1;
                            for( ; f>0; f--) //start adding marbles to each 'kampung'
                            {
                                if(k <= 14) //end of 'kampung' array not reach
                                {
                                    if (f == 1) //marble is left with 1
                                    {
                                        kampung[k]++;
                                        if(kampung[k] > 1 && k != 7) //if marble drop in 'kampung' containing more than 1 marble,continue movement of marble
                                        {
                                            f = kampung[k] + 1;
                                            kampung[k] = 0;
                                        }
                                        else if(k == 7) //play again if player 1 drop last marble in 'rumah'
                                        {
                                            congkak();
                                            cout<<"\a\nYour turn again Player 1\n";
                                            system("pause");
                                            x--;
                                        }
                                        else if(kampung[k] == 1 && k != 7)
                                        {
                                            //taking marbles from last drop 'kampung' and apposite 'kampung' and add into player 1's 'rumah'
                                            if(k == 6 && kampung[8] != 0)
                                            {
                                                kampung[7] += kampung[8] + 1;
                                                kampung[8] = 0;
                                                kampung[k] = 0;
                                            }
                                            else if(k == 5 && kampung[9] != 0)
                                            {
                                                kampung[7] += kampung[9] + 1;
                                                kampung[9] = 0;
                                                kampung[k] = 0;
                                            }
                                            else if(k == 4 && kampung[10] != 0)
                                            {
                                                kampung[7] += kampung[10] + 1;
                                                kampung[10] = 0;
                                                kampung[k] = 0;
                                            }
                                            else if(k == 3 && kampung[11] != 0)
                                            {
                                                kampung[7] += kampung[11] + 1;
                                                kampung[11] = 0;
                                                kampung[k] = 0;
                                            }
                                            else if(k == 2 && kampung[12] != 0)
                                            {
                                                kampung[7] += kampung[12] + 1;
                                                kampung[12] = 0;
                                                kampung[k] = 0;
                                            }
                                            else if(k == 1 && kampung[13] != 0)
                                            {
                                                kampung[7] += kampung[13] + 1;
                                                kampung[13] = 0;
                                                kampung[k] = 0;
                                            }
                                            else if(k == 0 && kampung[14] != 0)
                                            {
                                                kampung[7] += kampung[14] + 1;
                                                kampung[14] = 0;
                                                kampung[k] = 0;
                                            }
                                        }
                                    }
                                    else //adding one marble to each succeeding 'kampung'
                                    {
                                        kampung[k]++;
                                    }
                                    k++;
                                }
                                else //last kampung position reached
                                {
                                    k = 0; //restart the 'kampung' array position to [0]
                                    f++;
                                }
                            }
                        }
                        else //'kampung' chosen has no marbles
                        {
                            cout<<"\n\aThe kampung is empty ! Please choose another kampung ! \n";
                            system("pause");
                            x--;
                        }
                    }
                    else //'kampung' chosen does not exist
                    {
                        cout<<"\n\aThe kampung is invalid ! Please choose another kampung ! \n";
                        system("pause");
                        x--;
                    }
                }
                else
                x--;
            }
        }
        else //Player 2 is playing
        {
            if(kampung[8] != 0 || kampung[9] != 0 || kampung[10] != 0 || kampung[11] != 0 || kampung[12] != 0 || kampung[13] != 0 || kampung[14] != 0) //when either of the 7 'kampung' still have any marble(s), game continue
            {
                congkak();
                cout<<"\n\nplayer 2 turn";
                if(validatePassword(2)) //Check validity of password
                {
                    cout<<"enter the 'kampung' you want to move : B";
                    cin>>move;
                    move = move + 7; //plus 7 to set it correspond to the array position for player 2's 'kampung'
                    if (move >= 8 && move <= 14) //Ensure player 2 'kampung' array position between 8 to 14 only
                    {
                        if (kampung[move] > 0) //Ensure 'kampung' chosen is not empty
                        {
                            f = kampung[move];
                            kampung[move] = 0;
                            k = move + 1;
                            for( ; f>0; f--) //'Kampung' that is chosen will be emptied
                            {
                                if(k == 7)
                                {
                                    k = 8;
                                    f++;
                                }
                                else if(k > 15)
                                {
                                    k = 0;
                                    f++;
                                }
                                else
                                {
                                    if (f == 1)
                                    {
                                        kampung[k]++;
                                        if(kampung[k] > 1 && k != 15)
                                        {
                                            f = kampung[k] + 1;
                                            kampung[k] = 0;
                                        }
                                        else if(k == 15)
                                        {
                                            congkak();
                                            cout<<"\a\nYour turn again Player 2\n";
                                            system("pause");
                                            x--;
                                        }
                                        else if(kampung[k] == 1 && k != 15)
                                        {
                                            //taking marbles from last drop 'kampung' and apposite 'kampung' and add into player 2's 'rumah'
                                            if(k == 14 && kampung[0] != 0)
                                            {
                                                kampung[15] += kampung[0] + 1;
                                                kampung[0] = 0;
                                                kampung[k] = 0;
                                            }
                                            else if(k == 13 && kampung[1] != 0)
                                            {
                                                kampung[15] += kampung[1] + 1;
                                                kampung[1] = 0;
                                                kampung[k] = 0;
                                            }
                                            else if(k == 12 && kampung[2] != 0)
                                            {
                                                kampung[15] += kampung[2] + 1;
                                                kampung[2] = 0;
                                                kampung[k] = 0;
                                            }
                                            else if(k == 11 && kampung[3] != 0)
                                            {
                                                kampung[15] += kampung[3] + 1;
                                                kampung[3] = 0;
                                                kampung[k] = 0;
                                            }
                                            else if(k == 10 && kampung[4] != 0)
                                            {
                                                kampung[15] += kampung[4] + 1;
                                                kampung[4] = 0;
                                                kampung[k] = 0;
                                            }
                                            else if(k == 9 && kampung[5] != 0)
                                            {
                                                kampung[15] += kampung[5] + 1;
                                                kampung[5] = 0;
                                                kampung[k] = 0;
                                            }
                                            else if(k == 8 && kampung[6] != 0)
                                            {
                                                kampung[15] += kampung[6] + 1;
                                                kampung[6] = 0;
                                                kampung[k] = 0;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        kampung[k]++;
                                    }
                                    k++;
                                }
                            }
                        }
                        else //'kampung' chosen has no marbles
                        {
                            cout<<"\nThe kampung is empty ! Please choose another kampung ! ";
                            system("pause");
                            x--;
                        }
                    }
                    else //'kampung' chosen does not exist
                    {
                        cout<<"\n\aThe kampung is invalid ! Please choose another kampung ! \n";
                        system("pause");
                        x--;
                    }
                }
                else
                x--;
            }
        }
        x++;
    }while(kampung[0] != 0 || kampung[1] != 0 || kampung[2] != 0 || kampung[3] != 0 || kampung[4] != 0 || kampung[5] != 0 || kampung[6] != 0 || kampung[8] != 0 || kampung[9] != 0 || kampung[10] != 0 || kampung[11] != 0 || kampung[12] != 0 || kampung[13] != 0 || kampung[14] != 0); //loop continues as long as both players' kampung have marbles
    
    //Determining the winner of the game
    if(kampung[7] > kampung[15]) //player 1 will win when he/she has more marbles in his/her 'rumah' than player 2
    {
        congkak();
        cout<<"\n\aCongratulation Player 1 : "<<player1<<". You are the winner !! "<<endl;
        system("pause");
        welcomemenu ();
    }
    else if(kampung[7]==kampung[15])       //The game becomes a draw when both players have the same number of marbles in their 'kampung'
    {
        congkak();
        cout<<"\n\aThe game is Draw!! Though Fight! Well Done Player 1: "<<player1<<" and Player 2: "<<player2<<" !"<<endl;
        system("pause");
        welcomemenu ();
    }
    else //player 2 will win when he/she has more marbles in his/her 'rumah' than player 1
    {
        congkak();
        cout<<"\n\aCongratulation Player 2 : "<<player2<<". You are the winner !! "<<endl;
        system("pause");
        welcomemenu ();
    }
}

bool validatePassword(int y) //continue play if password is correct
{
    string password = getpass("\n\t\tPlease enter your password: ",true);
    if(y ==1 && player1pswrd == password || y == 2 && player2pswrd == password)
    {
        cout<<"\n\n\t\t Welcome Player. \n";
        return true;
    }

    cout<<"\n\n\t\tYOU ENTERED WRONG PASSWORD!!.\a\n\t\t";
    system("pause");
    return false;
}

string getpass(const char *prompt, bool show_asterisk)
{
    const char BACKSPACE=8;
    const char RETURN=13;

    string password;
    unsigned char ch=0;

    cout <<prompt;

    while((ch=getch())!=RETURN)
    {
        if(ch==BACKSPACE)
        {
            if(password.length()!=0)
            {
                if(show_asterisk)
                cout <<"\b \b";
                password.resize(password.length()-1);
            }
        }
        else if(ch==0 || ch==224) // handle escape sequences
        {
            getch(); // ignore non printable chars
            continue;
        }
        else
        {
            password+=ch;
            if(show_asterisk) cout <<'*';
        }
    }
  cout <<endl;
  return password;
}


void rules(void) //function for rules of game
{
    system("cls");
    cout<<"+---------------------+"<<endl;
    cout<<"| How to play congkak |"<<endl;
    cout<<"+---------------------+"<<endl;
    cout<<"1. Scoop up all of the shells or seeds in any house on your side. Then drop a shell into the next house and continue depositing one shell into every house in a clockwise fashion. You should also drop a shell into your storehouse each time you pass it, but do not deposit any shells into your opponent's storehouse."<<endl<<endl;
    cout<<"2. Take another turn if you deposit your last shell into your own storehouse. If the last shell that you deposit falls into your own storehouse, then you get to take another turn. In this case, you may scoop up the shells from another of your houses and deposit them into other houses."<<endl<<endl;
    cout<<"3. Skip a turn if you deposit your last shell into one of your opponent�s empty storehouses. Empty storehouses on your opponent's side of the board will create an obstacle for you. During a turn, if you drop your last shell into one of your opponent�s empty houses, then you lose a turn"<<endl<<endl;
    cout<<"4. Collect your opponent's shells if you deposit your last shell into one of your own empty storehouses. The goal of Congkak is to have the most shells in your storehouse at the end of the game. During a turn, if you manage to drop your last shell into an empty house on your side of the board, then you get to collect the shells that are opposite that house."<<endl<<endl;
    cout<<"5. Count up the shells in your storehouse. After you and your opponent have both emptied your houses, the game is over. To determine a winner, count up the shells in your storehouse. Whoever has the most shells is the winner!"<<endl<<endl;
    cout<<"Notes :) *Try your best to avoid your opponent's empty houses so that you do not lose any turns.Take the shells from the corresponding house on your opponent's side of the board and put them into your storehouse.* \n\n"<<endl;
    system("pause");
}
//End of program