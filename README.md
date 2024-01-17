# Connect4_Wordle

Description of game:
The game will be *Connect4 with a twist of Wordle*. 
 
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Game Rules: 
1. There are two players in the game, player@ and player#.
2. Each player takes turns to input a chess piece into a column. 
3. The chess piece of player@ is '@' and the chess piece of player# is '#'.
4. When a player’s chess pieces form a line of 4 either vertically, horizontally or diagonally, the player wins.
 
5. After each turn, the player will have a 8% chance to win a bonus move. 
6. If a bonus is triggered, the player needs to solve the Wordle. 
7. If the Wordle is solved, the player can input an extra piece; if not, it is the next player's turn. Keep in mind that each player can at most input 2 chess   pieces consecutively.
 
8. In Wordle, the player has to guess a randomly-generated word. 
9. The player can choose whether he/she wants to guess a 5-letter word, 6-letter word or a 7-letter word.
10. The number of guesses a player gets depends on the size of the word. (5 guesses for a 5-letter word, 6 guesses for a 6-letter word and 7 guesses for a 7-letter word)
11. In each try, the player will guess any one word. 
12. After each try, the computer will output the player's guess letter by letter in the following way:
    a) If the letter is uppercase, it means it is the correct letter in the correct position. 
    b) If the letter is lowercase, it means the letter is in the word but it is at the wrong position. 
    c) If the letter is not in the word, it means the letter is not in the word. 
13. This output after each guess serves as a hint for the player's next guess.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Features:
1. Size of board: Players can choose the size of the board (i.e. number of rows and columns) in Connect4.
2. Bonus chance: Players will get a chance to input an extra piece if they can win the Wordle. The probability will be 0.08.
3. Size of word: Players can choose the size of the word they guess in Wordle.
4. Wordle statistics: rounds, wins and win rate of both players

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Coding Requirements:
1. Generation of random game sets or events:
   - In the Wordle portion of the game, the computer will randomly generate a word from the word list for the player to guess.
2. Data structures for storing game status:
   - use array of vector to store the board
   - use char array to store the word in wordle
4. Dynamic memory management:
   - In Connect4, Players can choose the size of the board before each game by picking the number of rows and columns. 
   - In Wordle, Players can also choose the size of the word they guess. (5/6/7-letter word)
   - The game will only store the previous game status if the players pause/quit the game before completing it.
5. File input/output (e.g., for loading/saving game status):
   - Output Wordle wins player by player into a file
6. Program codes in multiple files:
   - Function for connect4
   - Function for Wordle
   - File for storing Wordle wins
   - Function for printing Wordle statistics
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Compilation and execution instructions:
1. Upload all the files onto academy 11
2. Type "make connect4" in the Terminal Emulator
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
This repo is co-created by Ambrose and @Ishika https://github.com/lshika?tab=repositories
It is created during the class ENGG1340_COMP2113 at HKU during 2022 Fall.
