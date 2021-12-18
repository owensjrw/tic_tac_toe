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
  int throwaway = 0;

//Start game.
  for(short win = 0; win != 1;) {

//Print board.
    printf("%c | %c | %c\n", tictactoe_board[0],tictactoe_board[1],tictactoe_board[2]);
    puts("---------");
    printf("%c | %c | %c\n", tictactoe_board[3],tictactoe_board[4],tictactoe_board[5]);
    puts("---------");
    printf("%c | %c | %c\n", tictactoe_board[6],tictactoe_board[7],tictactoe_board[8]);

//Get input from players
    input: //Label for loopback if square is taken or square does not exist
    printf("Player %d what square do you want? ", player);
    //Loop to get input from player to ensure player cannot cheat
    while((throwaway < 1) || (throwaway >9)){
      printf("You must choose one open square \n");
      scanf("%i", &throwaway);
    }
    square = throwaway + '0';  //Converts thowaway int to char
    throwaway = 0;  //Resets throwaway to keep loop from being foreverloop
    puts("\n");

//Check for valid input
    if((square < '1') || (square > '9')) {
      puts("Square does not exist!\nPlease try again\n");
      goto input; //Send back to input
      }

//Check is square is used or add player token to square.
    if((square >= '1') && (square <= '9')) {
      if(tictactoe_board[square - ASCII_ONE] == 'O' || tictactoe_board[square - ASCII_ONE] == 'X') {
        puts("That square is already taken, please choose again.\n");
        goto input; //Send back to input
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
