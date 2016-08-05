/* Smart computer decision maker. This algorithm ensures the computer 
 * never loses. 
 *
 * The problem breaks up nicely into a recursive search algorithm, where
 * the computer finds the set of choices that will give the best worst-case
 * result. 
 *
 * This recursive implementation features two functions that recursively 
 * call each other. This permits a natural and intuitive representation of
 * computer/user choice making process. (However it is ridiculously inefficient.)
 *
 * There are shorter, simpler, much more efficient solutions than this
 * to the Tic-Tac-Toe problem.
 *
 * Tim Bailey 2004. */

static int get_computer_decision_set(int state[], int bestset[]);
static void recurse_search(int state[], int choice, enum Turn turn, enum Result *worst);

void get_computer_decision(int state[])
/* Get the computers next move. Computer cannot lose. */
{
    int choice, nbest;    
    int best_set[NUMSTATES];

    nbest = get_computer_decision_set(state, best_set);

    /* Pick a random choice from set of best choices. */
    choice = best_set[rand()%nbest];
    state[choice] = NOUGHT;
    printf("\nComputer's move was %d.\n", choice+1);
}

int get_computer_decision_set(int state[], int best_set[])
/* Get set of equal-best computer decisions given current game state. 
 * Return value: number of equal best choices. */
{
    int i, nbest=0;
    enum Result bestcase = LOSE;

    /* Search for set of choices that give best result. */
    for (i=0; i < NUMSTATES; ++i)
        if (state[i] == NOTHING) {
            enum Result result = WIN;
            recurse_search(state, i, COMPUTER, &result);

            /* New best found if result is better than bestcase. */
            if (result != bestcase && (result == WIN || bestcase == LOSE)) {
                nbest = 0;
                bestcase = result;
            }

            /* Store set of equal best choices */
            if (result == bestcase)
                best_set[nbest++] = i; 
        }

    return nbest;
}

void recurse_search(int state[], int choice, enum Turn turn, enum Result *worst)
/* Recursively search the game decision-tree to find worst possible result. 
 * Worst-case result is returned via the parameter <worst>. */
{
    enum Result result;

    /* Try choice, and check resulting game status */
    state[choice] = (turn==USER) ? CROSS : NOUGHT;
    result = compute_result(state, turn);

    /* If game not over, keep recursing. */
    if (result == PLAYING) {
        int i, nchoice=0;
        int choice_set[NUMSTATES];
        turn = (turn==USER) ? COMPUTER : USER;

        /* Computer only makes smart decisions, but for the user, we search the 
         * entire space of user choices, as the user may do anything. */
        if (turn == COMPUTER) 
            nchoice = get_computer_decision_set(state, choice_set);
        else {
            for (i=0; i<NUMSTATES; ++i)
                if (state[i] == NOTHING)
                    choice_set[nchoice++] = i;
        }

        /* Search set of available choices. */
        for (i=0; i<nchoice; ++i)
            recurse_search(state, choice_set[i], turn, worst);
    }
    else 
    { /* If game finished, see if we have a new worst-case result. */
        if (result == WIN && turn == USER)
            result = LOSE; /* user win means computer lose */

        if (result != *worst && (result == LOSE || *worst == WIN)) /* result is worse */
                *worst = result;
    }

    /* Reset state to value of previous level */
    state[choice] = NOTHING; 
}
