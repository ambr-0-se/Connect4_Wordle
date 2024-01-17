#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <ctype.h>
#include <cstring>
#include "wordle.h"

using namespace std;

// function prototypes
void generate_word(char * &word, string wordlist[], int wordSize);
bool correct_guess(char * guess, char * word, int wordSize);
void input_guess(char * &guess, int wordSize);
void print_result(char * guess, char * word, int wordSize);
bool in_word(char letter, char * word, int wordSize);


// function to pass win/lose result of bonus chance by playing wordle
// output: true if player wins wordle, false if player loses wordle
bool wordle()
{
  // word lists of 50 words by word size (5,6,7)
  string words5[50] = {"after", "swung", "mourn", "soupy", "blend", "shack", "joint", "zebra", "slope", "prune",
                       "awake", "taint", "porch", "quake", "smile", "hover", "offer", "spade", "spend", "unite",
                       "hilly", "caper", "grade", "cheap", "gnome", "crook", "clout", "vomit", "where", "madam",
                       "speak", "cache", "spoon", "flick", "based", "tense", "clasp", "split", "rogue", "swift",
                       "plump", "braze", "trail", "cleft", "hedge", "frank", "fully", "clash", "ghoul", "arson"};
  string words6[50] = {"bridal", "atomic", "cereal", "bought", "jargon", "gather", "sunday", "finite", "factor", "combat",
                       "barred", "sizzle", "fiesta", "rebate", "divide", "depart", "farmer", "tragic", "rattle", "exhale",
                       "invade", "admire", "binary", "patrol", "subtly", "tumble", "stride", "wretch", "undone", "stress",
                       "coward", "flower", "bother", "garden", "stolen", "spoilt", "trance", "deadly", "rename", "mental",
                       "middle", "aspire", "shriek", "embark", "purely", "gentle", "basket", "eraser", "inject", "script"};
  string words7[50] = {"unbound", "debacle", "cockpit", "average", "goddess", "octagon", "chemist", "patient", "topcoat", "discard",
                       "tornado", "squeeze", "leakage", "emotive", "acquire", "sparkle", "reserve", "bluffed", "outward", "special",
                       "upright", "twinkle", "passion", "evolved", "pasture", "subject", "journey", "pointer", "tumbler", "servant",
                       "pioneer", "diagram", "sorcery", "patriot", "blaster", "compass", "revenge", "whether", "brawler", "flutter",
                       "convene", "amplify", "crochet", "desired", "furnish", "mystery", "glisten", "posture", "willing", "skyward"};

  
  // take player's input for word size to play Wordle
  int wordSize = 0;
  cout << "Choose a word size (5, 6 or 7?): ";
  cin >> wordSize;


  char * word = new char [wordSize + 1];     // create a dynamic char array to store the word 
  
  // generate word according to word size
  if (wordSize == 5)
  {
    generate_word(word, words5, 5);
  }
  else if (wordSize == 6)
  {
    generate_word(word, words6, 6);
  }
  else
  {
    generate_word(word, words7, 7);
  }
  
  
  // print simple wordle instructions for player
  cout << endl;
  cout << "Uppercase -> correct letter, correct position" << endl;
  cout << "Lowercase -> correct letter, wrong position" << endl;
  cout << "\'_\' -> wrong letter" << endl;
  cout << endl;
 
  
  bool endgame = false;
  int numOfGuesses = 0;     // to ensure number of guesses don't exceed allowed guesses (= size of word)
  
  char * guess = new char [wordSize + 1];     // create another dynamic char array to store player's guess

  while (!endgame)
  {
    // win output when the player guesses the word correctly
    if (correct_guess(guess, word, wordSize) && numOfGuesses != 0)
    {
      cout << "Correct! You got an extra move!" << endl;
      delete [] guess;
      delete [] word;
      return true;     // pass win to connect4 game
    }
    // game over output when the player's guesses finish
    else if (numOfGuesses == wordSize)
    {
      cout << "Game over. You lose your move. :(" << endl;
      delete [] guess;
      delete [] word;
      return false;     // pass lose to connect4 game
    }
    // take next input guess and print result of guess
    else
    {
      input_guess(guess, wordSize);     // take user's input and store it in the dynamic array guess points to      
      print_result(guess, word, wordSize);     // print result of player's guess letter by letter
      
      numOfGuesses++;    
    }
  }
}


// function to generate a random word from wordlist according to chosen word size and store in a dynamic char array 
// input: dynamic char array -> to store word,    string array -> wordlist of appropriate word size,    int -> word size
void generate_word(char * &word, string wordlist[], int wordSize)
{
  const char * genChar = new char[wordSize+1] ;     // constant dynamic char array to temporarily store the random word
  
  // random word generation
  srand(time(NULL));
  genChar = wordlist[rand()%50].c_str();     // convert the word into a c-string to store in genChar

  for (int i = 0; i < wordSize; ++i)
  {
    word[i] = genChar[i];     // copy genChar to word
  }
}


// function to check if the guess is correct so game can be ended
// input: dynamic char array -> stores guess,    dynamic char array -> stores word to be guesses,    int -> word size
// output: true if guess is correct, false if guess is wrong
bool correct_guess(char * guess, char * word, int wordSize)
{
  for (int i = 0; i < wordSize; ++i)
  {
    if (guess[i] != word[i])
    {
      return false;
    }
  }
  return true;
}


// function to take guess input from player and store it in a dynamic char array 
// input: dynamic char array -> store guess input,    int -> word size
void input_guess(char * &guess, int wordSize)
{
  int i = 0;
  string word;     // initially store guess in a string

  cout << "Guess a " << wordSize << "-letter word: ";
  cin >> word;
  
  // take input until input is valid
  while (word.length() != wordSize)
  {
      cout << "invalid input" << endl;
      cout << "Guess a " << wordSize << "-letter word: ";
      cin >> word;
  }
  
  // copy contents of string word into dynamic char array guess
  for (int i=0; i<wordSize;++i)
  {
      guess[i] = tolower(word[i]);     // tolower() in case player inputs capital letters
  }
  cout << endl;
}


// function to print the guess character by character in uppercase letter/lowercase/'_' as a hint for the next guess
// input: dynamic char array -> guess of player,    dynamic char array -> word to be guessed,    int -> word size
void print_result(char * guess, char * word, int wordSize)
{
  for (int i = 0; i < wordSize; ++i)
  {
    if (guess[i] == word[i])
    {
      cout << char(toupper(guess[i])) << ' ';     // print letter in uppercase if correct letter, correct position
    }
    else if (in_word(guess[i], word, wordSize))     
    {
      cout << char(tolower(guess[i])) << ' ';     // print letter in lowercase if correct letter, wrong position
    }
    else
    {
      cout << "_ ";     // print '_' blank if wrong letter
    }
  }
  cout << endl;
}


// function to check if a letter is in the word
// input: char -> letter to be checked,    dynamic char array -> word to be guessed,    int -> word size
// output: true if letter in word, false if not
bool in_word(char letter, char * word, int wordSize)
{
  for (int i = 0; i < wordSize; ++i)
  {
    if (word[i] == letter)
      return true;
  }
  return false;
}
