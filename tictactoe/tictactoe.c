/* This program plays a game of tic-tac-toe with the computer.
 * Tim Bailey 2003.
 */
#include <stdio.h>
#include <assert.h>
#include "playgame.h"

/* function prototypes */
void welcome(void);
enum Turn who_goes_first(void);
void gameover_message(enum Result result);
int play_again(void);
void goodbye(void);

/*
 * Function definitions below...
 */

int main(void)
{
    enum Turn turn;
    enum Result result;
    int newgame = 1;

    welcome();

    while (newgame) {
        turn = who_goes_first();
        result = play_game(turn);
        gameover_message(result);
        newgame = play_again();        
    };
    
    goodbye();
    return 0;
}

void welcome(void)
/* Print welcome screen, which says name and rules of game. */
{
    printf("Welcome to TIC-TAC-TOE.\n");
    printf("-----------------------\n\n");
    printf("The object of this game is to get a line of X's\n");
    printf("before the computer gets a line of O's. A line may\n");
    printf("be across, down, or diagonal.\n\n");
    printf("The board is labelled from 1 to 9 as follows:\n\n");
    printf("\t1|2|3\n");
    printf("\t-----\n");
    printf("\t4|5|6\n");
    printf("\t-----\n");
    printf("\t7|8|9\n");
    printf("\n\n");
}

enum Turn who_goes_first(void)
/* Ask whether user wishes to go first */
{
    int decide = getint_from_user("Do you wish to go first (1-Yes, 0-No) ? ");
    if (decide == 1)
        return USER;
    return COMPUTER; /* if user types anything but '1', computer gets first go */
}

void gameover_message(enum Result result)
/* Print game-over message, depending on outcome */
{
    switch(result)
    {
    case WIN:
        printf("\nYou win. Congratulations!!\n\n");
        break;
    case LOSE:
        printf("\nYou lose. Better luck next time.\n\n");
        break;
    case DRAW:
        printf("\nIts a draw. How dull.\n\n");
        break;
    default:
        assert(0); /* can't happen */
    }
}

int play_again(void)
/* Ask if user wants to play again, return 0 (NO) or 1 (YES) */
{
    int again;

bad_practice_just_for_fun:
    again = getint_from_user("Do you wish to play again (1-Yes, 0-No) ? ");
    if (again != 1 && again != 0) {
        printf("Error: Invalid choice.\n");
        goto bad_practice_just_for_fun;
    }

    return again;
}
    
void goodbye(void)
/* Print goodbye message */
{
    printf("\nGoodbye. Thanks for playing.\n");
}
