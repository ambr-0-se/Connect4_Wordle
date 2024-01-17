#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "wordlestat.h"

using namespace std;
//read from file to get players' stat on wordle, and print their statistics out
void wordlestat()
{
    ifstream fin("Wordle_Record.txt");    //Code requirement 4
    if (fin.fail())
    {
        cout << "Error in opening Wordle_Record.tx" << endl;
        exit(1);
    }
    
    char player;   //player refers to @ / #
    int success;   //success = 0 if player fails the wordle
    double num1 = 0, win1 = 0, num2 = 0, win2 = 0;  //num1 counts how many times player# attempt wordle
    string str;                                     //win1 stores how many times player# pass the wordle
    while (getline(fin,str))
    {
        istringstream iss(str);
        iss >> player;
        if (player == '#')
        {
            num1 += 1;
            iss >> success;
            if (success == 1) 
            {
                win1 += 1;
            }
        }
        else if (player == '@')
        {
            num2 += 1;             // num2 counts how many times player@ attempt wordle 
            iss >> success;
            if (success == 1)      // win2 store how many times player# pass the wordle
            {
                win2 += 1;
            }
        }
    }
    fin.close();
    
    double rate1, rate2;
    if (num1 == 0) {
        rate1 = 0;
    }
    else {
        rate1 = win1/num1;
    }
    if (num2 == 0) {
        rate2 = 0;
    }
    else {
        rate2 = win2/num2;
    }
    
    cout << "Wordle stat of Player # -> Round: " << num1 << " Win: " << win1 << " Win rate: ";
    cout << fixed << setprecision(4) << rate1 << endl;
    cout.unsetf(ios_base::floatfield);  
    cout << "Wordle stat of Player @ -> Round: " << num2 << " Win: " << win2 << " Win rate: ";
    cout << fixed << setprecision(4) << rate2 << endl;
}
