#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "wordle.h"    //code requirement 5
#include "wordlestat.h"

using namespace std;
//write the record to the file
void write(char chess, int success)
{    //success = 0 if the player cant pass the wordle, success = 1 if the player pass it
    ofstream fout("Wordle_Record.txt", ios::app);    //code requirement 4
    
    if (fout.fail())
    {
        cout << "Fail to open Wordle_Record.txt" << endl;
        exit(1);
    }

    
    fout << chess << " " << success << endl;
    fout.close();
}

//switch the chess
void switchchess(char &chess)
{
    if (chess == '#')
    {
        chess = '@';
    }
    else
    {
        chess = '#';
    }
}
//return true if all positions are filled, return false if there is position empty
bool drawcondition(vector<char> board[], int columns)
{                   //input: board, number of columns
    for (int c=0; c<columns; ++c)
    {
        for (int r=0; r<board[c].size(); ++r)
        {
            if (board[c][r] == '.') //if the position is '.', it is empty
            {
                return false;
            }
        }
    }
    return true;
}
//return true if win conditions are met, return false if no one wins
bool wincondition(vector<char> board[], char chess, int columns)
{                  //input: board, chess(#/@), number of columns
    int r_size = board[0].size();
    int sum;      //sum equals 4 if chess piece form a line of 4

    for (int r=0; r<r_size; ++r)   //check if the chess piece form a line of 4 in horizontal
    {
        for (int c=0; c<columns-3;++c)
        {
            sum = 0;
            for (int s=0; s<4;++s)
            {
                if (board[c+s][r] == chess)
                {
                    sum += 1;
                }
            }
            if (sum == 4)
            {
                return true;
            }
        }
    }

    for (int c=0; c<columns; ++c)   //check if the chess piece form a line of 4 in vertical
    {
        for (int r=0; r<r_size-3;++r)
        {
            sum = 0;
            for (int s=0; s<4;++s)
            {
                if (board[c][r+s] == chess)
                {
                    sum += 1;
                }
            }
            if (sum == 4)
            {
                return true;
            }
        }
    }

    for (int c=0; c<columns-3; ++c)   //check if the chess piece form a line of 4 in right diagonal
    {
        for (int r=0; r<r_size-3;++r)
        {
            sum = 0;
            for (int s=0; s<4;++s)
            {
                if (board[c+s][r+s] == chess)
                {
                    sum += 1;
                }
            }
            if (sum == 4)
            {
                return true;
            }
        }
    }

    for (int c=columns-1; c>2; --c)   //check if the chess piece form a line of 4 in left diagonal
    {
        for (int r=0; r<r_size-3;++r)
        {
            sum = 0;
            for (int s=0; s<4;++s)
            {
                if (board[c-s][r+s] == chess)
                {
                    sum += 1;
                }
            }
            if (sum == 4)
            {
                return true;
            }
        }
    }

    return false;
}
//make change to the board according to player's move
void move(vector<char> board[], char command, char chess, int columns)
{         //input: board, column that player insert the chess piece (A/B/...), chess (#/@), number of columns
    int pos = command - 65;
    int size = board[pos].size();
    for (int r = size-1; r >= 0; --r)
    {
        if (board[pos][r] == '.')
        {
            board[pos][r] = chess;
            return;
        }
    }
}
//check validity of user's move, return false if it is invalid
bool check(vector<char> board[], char input[], int columns)
{          //input: board, input from user, number of columns
    if (strlen(input) != 1)
    {
        return false;
    }
    if (input[0] <'A' || input[0] > 'Z')
    {
        return false;
    }
    int pos = input[0] - 65;
    if (pos >= columns)
    {
        return false;
    }
    int size = board[pos].size();
    for (int r = size-1; r >= 0; --r)
    {
        if (board[pos][r] == '.')
        {
            return true;
        }
    }
    return false;
}
//print out the board
void printboard(int columns, int rows, vector<char> board[])
{             //input: number of columns, number of rows, board
    cout << endl;
    for (int r=0; r<rows;++r)
    {
        cout << rows-r << " ";      //rows (1-9)
        for (int c=0; c<columns; ++c)
        {
            cout << board[c][r] << " ";
        }
        cout << " " << endl;
    }
    char column = 'A';
    cout << "  ";
    for (int c=0; c<columns;++c)
    {
        cout << column << " ";    //columns (A-I)
        ++column;
    }
    cout << "\n" << endl;

}
//create the board
void createboard(int columns,int rows, vector<char> board[])
{                  //input: number of columns, number of rows, board
    for (int c=0; c<columns; ++c)
    {
        for (int r=0; r<rows; ++r)
        {
            board[c].push_back('.');    //positions that are empty are denoted by '.'
        }
    }
}
//check the validity of input of size of the board, return false if the requirements are not met
bool checknum(char input[])
{           //input: input from user
    if (strlen(input) != 1)  //length of input need to be 1
    {
        return false;
    }
    if (input[0] < '1' || input[0] > '9')  //input need to be ranged from 1-9
    {
        return false;
    }
    return true;
}
//get the number of rows and columns from user
void size(int &columns, int &rows)
{

    char input1[50], input2[50]; //input1 and input2 store the input from the user

    cout << "number of columns(1-9): ";
    cin >> input1;
    while (checknum(input1) != true)  //check validity of input1
    {
        cout << "\nINVALID SIZE" << endl;  //loop until the input is correct
        cout << "number of columns (1-9): ";
        cin >> input1;
    }
    columns = input1[0] - 48;

    cout << "number of rows(1-9): ";
    cin >> input2;
    while (checknum(input2) != true)  //check validity of input2
    {
        cout << "\nINVALID SIZE" << endl;
        cout << "number of rows (1-9): ";
        cin >> input2;
    }
    rows = input2[0] - 48;
}

int main()
{
    int columns, rows;   //store number of columns and rows
    size(columns,rows);  //get the input from user
    vector <char> *board = new vector<char> [columns];   //use array of vector to store the progress of the board
                                                         //code requirement 2&3
    createboard(columns,rows,board);  //create the board
    printboard(columns,rows,board);   //print out the board

    char end = 'A' + columns - 1;  //end is the last column
    char input[50];     //store the input from users
    char command;       //if the input is valid, the input will be stored in command
    char chess = '#';   //chess piece
    string quit = "q";  //comparison with command
    
    int twice = 0;      //to prevent player making more than 2 moves consecutively.
                        //twice = 0 if player only make one move; twice = 1 if player make 2 consecutive moves
    int success;    //success = 0 if the player cant pass the wordle, success = 1 if the player pass it
    
    cout << "Enter a letter from A-" <<end<<" to insert piece, or enter q to leave the game"<< endl;
    cout << "Player " << chess << ": ";

    cin >> input;
    while (input != quit.substr(0,1) && check(board,input,columns) != true)  //check validity, quit if input is "q"
    {
        cout << "\nINVALID INPUT" << endl;
        cout << "Player " << chess << ": ";
        cin >> input;
    }
    command = input[0];   //store the input
    
    while (command != 'q')
    {
        move(board,command,chess,columns);  //make change to the board according to player's move
        printboard(columns,rows,board);
        if (wincondition(board,chess,columns)==true) //ends if win condition is met
        {
            cout << "\nPlayer " << chess << " wins!" << endl;
            break;
        }
        if (drawcondition(board, columns)==true)  //ends (draw) if all positions are filled
        {
            cout << "\nDraw!" << endl;
            break;
        }
        
        srand(time(NULL));          //code requirement 1
        if (twice == 0)   //to prevent player making more than 2 moves consecutively.
        {
            if (rand() % 100 + 1 < 9)  //player get 8% chance to trigger a bonus -- wordle
            {
                cout << "\ncongrats! player" << chess<< " trigger a bonus! solve the wordle to get an extra move" << endl;
                if (wordle()==true)     //player get an extra move if wordle is solved 
                {
                    success = 1; //success = 0 if the player cant pass the wordle, success = 1 if the player pass it
                    twice = 1;  //twice = 0 if player only make one move; twice = 1 if player make 2 consecutive moves
                    write(chess, success);
                    switchchess(chess); //switching the chess twice implies the same player is making a move
                    printboard(columns,rows,board);
                }
                else
                {
                    success = 0; //success = 0 if the player cant pass the wordle, success = 1 if the player pass it
                    write(chess, success);
                    printboard(columns,rows,board);
                }
            }
        }
        else   //if twice=1 (which means the player has made 2 consecutive moves), the player won't get any bonus
        {
            twice = 0;
        }
        
        switchchess(chess);   //switch to another player's turn
        cout << "Player " << chess << ": ";
        cin >> input;                //quit if the input is "q"  (string quit = "q"; line 244)
        while (input != quit.substr(0,1) && check(board,input,columns) != true) //check validity of input
        {
            cout << "\nINVALID INPUT" << endl;
            cout << "Player " << chess << ": ";
            cin >> input;
        }
        command = input[0];
    }
    if (command == 'q')
    {
        printboard(columns,rows,board);
        cout << "Player " << chess << " quits" << endl;
        switchchess(chess);
        cout << "Player " << chess << " wins!" << endl;
    }
    wordlestat();     //print the stat of wordle by each player
    cout << "ByeBye" << endl;
    delete [] board;
    return 0;
}
