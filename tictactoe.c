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
Edits and collaboration with Moriarty1982.
*/

#include <stdio.h>

int main()
{
    char board[] = {'1','2','3','4','5','6','7','8','9'};
    int player = 1;
    int moves = 0;
    int game_end = 0;
    int input;
    
    do {
        printf("%c | %c | %c\n", board[0], board[1], board[2]);
        puts("---------");
        printf("%c | %c | %c\n", board[3], board[4], board[5]);
        puts("---------");
        printf("%c | %c | %c\n\n", board[6], board[7], board[8]);
        
        if (game_end == 1) {
            printf("** Congragulations Player %d. You have won the game. **\n", player);
            break;
        }
        
        int is_num;
        do {
            printf("Player %d what square do you want? ", player);
            is_num = scanf(" %d", &input);
            while(getchar() != '\n');
        } while (is_num != 1 || (input < 1 || input > 9));
        input--;
        
        if (board[input] == 'X' || board[input] == 'O') {
            puts("That square is already taken, please choose again.\n");
            continue;
        }

        board[input] = player == 1 ? 'X' : 'O';
        moves++;
        
        if (
            (board[0] == board[1] && board[1] == board[2]) ||
            (board[3] == board[4] && board[4] == board[5]) ||
            (board[6] == board[7] && board[7] == board[8]) ||
            (board[0] == board[3] && board[3] == board[6]) ||
            (board[1] == board[4] && board[4] == board[7]) ||
            (board[2] == board[5] && board[5] == board[8]) ||
            (board[0] == board[4] && board[4] == board[8]) ||
            (board[2] == board[4] && board[4] == board[6])
        ){
            game_end = 1;
            continue;
        } else if (moves == 9) {
            puts("Tie Game. Better luck next time.\n");
            break;
        } else {
            player = player == 1 ? 2 : 1;
        }
    } while (1);
}
