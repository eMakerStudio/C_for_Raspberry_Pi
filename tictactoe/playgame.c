#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "playgame.h"

enum { NOTHING, CROSS, NOUGHT };
#define NUMSTATES                9
#define CHECK_CHOICE(c,state)    ((c)>=0 && (c)<NUMSTATES && state[c]==NOTHING)

/* private functions */
static void get_user_decision(int state[]);
static void get_computer_decision(int state[]);
static void plot_state(int state[]);
static enum Result compute_result(int state[], enum Turn turn);

/*
 * Function definitions below...
 */

enum Result play_game(enum Turn turn)
/* Get move alternately from user and computer, and plot resulting
 * table. Loop until we have a winner and return game result.
 *
 * Arguments: turn - who has first go
 * Return value: result - final game outcome: win, lose, draw */
{
    enum Result result = PLAYING;
    int state[NUMSTATES], i;

    for (i = 0; i < NUMSTATES; ++i) /* initialise board */
        state[i] = NOTHING;

    while (result == PLAYING) {
        if (turn == USER) 
            get_user_decision(state);
        else 
            get_computer_decision(state);

        /* After each move, print table and see if we have a winner. */
        plot_state(state);
        result = compute_result(state, turn);        
        if (result == WIN && turn == COMPUTER) /* computer won means user lost */
            result = LOSE;

        turn = (turn==USER) ? COMPUTER : USER;        
    } 

    return result;
}

void get_user_decision(int state[])
/* Get users next move. */
{
    int choice;

    while(1) {
        choice = getint_from_user("\nYour turn (1 - 9): ") - 1;
        if (CHECK_CHOICE(choice, state) == 1)
            break;
        printf("Error: Invalid choice. Try again...\n");
    }
    state[choice] = CROSS;
}

#if 1 /* Dumb computer */

void get_computer_decision(int state[])
/* Get the computers next move. 
 * This implementation is dumb as a post; just a random choice. */
{
    int choice = -1;
    while (CHECK_CHOICE(choice, state) == 0)
        choice = rand()%NUMSTATES;
    state[choice] = NOUGHT;
    printf("\nComputer's move was %d.\n", choice+1);
}

#else /* Smart computer */

#include "smarts.c"

#endif

static char* makeline(char* line, int* state, int i)
/* Converts a char array to contain certain characters.
 * Implementation is dependent on plot_state() below. */
{
    int j = i+3, k = 0;
    for (; i<j; ++i, k+=2)
        switch(state[i])
        {
        case NOTHING: line[k] = ' '; break;
        case CROSS:   line[k] = 'X'; break;
        case NOUGHT:  line[k] = 'O'; break;
        default: assert(0); /* can't happen */
        }
    return line;
}

void plot_state(int state[])
/* Print ASCII plot of current state of game. */
{
    char line1[] = "1|2|3\n";
    char line2[] = "-----\n";
    printf("\n\t%s", makeline(line1, state, 0));
    printf("\t%s", line2);
    printf("\t%s", makeline(line1, state, 3));
    printf("\t%s", line2);
    printf("\t%s", makeline(line1, state, 6));
}

enum Result compute_result(int state[], enum Turn turn)
/* Determine if the game is over, and if so who won (or a draw).
 * This function is specific to a 3x3 game; will need to modify
 * for a more general game. In particular, it contains a lot of
 * "magic numbers", which is not good practice. 
 * Returns WIN (meaning current turn won), DRAW, or PLAYING. */
{
    int i, tag;
    tag = (turn == USER) ? CROSS : NOUGHT;

    /* Check for row win */
    for (i=0; i<9; i += 3)
        if (state[i]==tag && state[i+1]==tag && state[i+2]==tag)
            return WIN;

    /* Check for column win */
    for (i=0; i<3; ++i)
        if (state[i]==tag && state[i+3]==tag && state[i+6]==tag)
            return WIN;

    /* Check for diagonal win */
    if (state[0]==tag && state[4]==tag && state[8]==tag)
        return WIN;
    if (state[2]==tag && state[4]==tag && state[6]==tag)
        return WIN;

    /* Check for draw: all states used. */
    for (i=0; i<NUMSTATES; ++i)
        if (state[i] == NOTHING)
            return PLAYING;

    return DRAW;
}

int getint_from_user(char* message)
/* Print a message that requests the user to input an integer.
 * Read in value, and if invalid input, keep asking. */
{
    char buff[256];
    int val; 

    while(1) {
        printf(message);
        fgets(buff, sizeof(buff), stdin);
        if (sscanf(buff, "%d", &val) == 1)
            break;
        printf("Error: Invalid input - must be an integer.\n");
    }

    return val;
}
