/*

1 | 2 | 3
---------
4 | 5 | 6     << is the setup of the board
---------
7 | 8 | 9

Enter one number, one player at a time

Example:
1       << This would be Player 1
2       << This would be Player 2
5       << This would be Player 1
3       << This would be Player 2
9       << This would be Player 1

The above example would run the program with Player 1 as a winner.

Created by William R. Owens "owensjrw", An old dog tring to learn a new trick.
*/

#include <stdio.h>
#define ASCII_ONE 49

int main (void) {

// Set Variables for game.
  char tictactoe_board[9] = {'1','2','3','4','5','6','7','8','9'};
  short squares_used = 0;
  short player = 1;
  char square;

//Start game.
  for(short win = 0; win != 1;) {

//Print board.
    printf("%c | %c | %c\n", tictactoe_board[0],tictactoe_board[1],tictactoe_board[2]);
    puts("---------");
    printf("%c | %c | %c\n", tictactoe_board[3],tictactoe_board[4],tictactoe_board[5]);
    puts("---------");
    printf("%c | %c | %c\n", tictactoe_board[6],tictactoe_board[7],tictactoe_board[8]);

//Get input from players
    printf("Player %d what square do you want? ", player);
    fflush(stdin);  // Was an attempt to flush the stdin buffer
    scanf(" %1c", &square); // ?? How to fix ability to cheat ??
    puts("\n");

//Check for valid input
    if((square < '1') || (square > '9')) {
      puts("Square does not exist!\nPlease try again\n");
      }

//Check is square is used or add player token to square.
    if((square >= '1') && (square <= '9')) {
      if(tictactoe_board[square - ASCII_ONE] == 'O' || tictactoe_board[square - ASCII_ONE] == 'X') {
        puts("That square is already taken, please choose again.\n");
      } else if(player == 1) {
        tictactoe_board[square - ASCII_ONE] = 'X';
        squares_used++;
      } else {
        tictactoe_board[square - ASCII_ONE] = 'O';
        squares_used++;
      }
    }

//Check for win or tie game.
    if(((tictactoe_board[0] == tictactoe_board[1]) && (tictactoe_board[1] == tictactoe_board[2])) ||
       ((tictactoe_board[3] == tictactoe_board[4]) && (tictactoe_board[4] == tictactoe_board[5])) ||
       ((tictactoe_board[6] == tictactoe_board[7]) && (tictactoe_board[7] == tictactoe_board[8])) ||
       ((tictactoe_board[0] == tictactoe_board[3]) && (tictactoe_board[3] == tictactoe_board[6])) ||
       ((tictactoe_board[1] == tictactoe_board[4]) && (tictactoe_board[4] == tictactoe_board[7])) ||
       ((tictactoe_board[2] == tictactoe_board[5]) && (tictactoe_board[5] == tictactoe_board[8])) ||
       ((tictactoe_board[0] == tictactoe_board[4]) && (tictactoe_board[4] == tictactoe_board[8])) ||
       ((tictactoe_board[6] == tictactoe_board[4]) && (tictactoe_board[4] == tictactoe_board[2]))) {

      printf("%c | %c | %c\n", tictactoe_board[0],tictactoe_board[1],tictactoe_board[2]);
      puts("---------");
      printf("%c | %c | %c\n", tictactoe_board[3],tictactoe_board[4],tictactoe_board[5]);
      puts("---------");
      printf("%c | %c | %c\n", tictactoe_board[6],tictactoe_board[7],tictactoe_board[8]);

      printf("** Congragulations Player %d. You have won the game. **\n", player);
      win = 1;
    } else if (squares_used == 9){
      printf("%c | %c | %c\n", tictactoe_board[0],tictactoe_board[1],tictactoe_board[2]);
      puts("---------");
      printf("%c | %c | %c\n", tictactoe_board[3],tictactoe_board[4],tictactoe_board[5]);
      puts("---------");
      printf("%c | %c | %c\n", tictactoe_board[6],tictactoe_board[7],tictactoe_board[8]);

      puts("Tie Game. Better luck next time.\n");
      win = 1;
    } else {
      player == 1 ? (player = 2) : (player = 1);
    }
  }
}