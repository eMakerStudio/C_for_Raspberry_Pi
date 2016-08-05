
#ifndef PLAY_GAME_H_ /* header guard: prevents multiple inclusion */
#define PLAY_GAME_H_


enum Turn { USER, COMPUTER };
enum Result { PLAYING, WIN, LOSE, DRAW };

enum Result play_game(enum Turn turn);
int getint_from_user(char* message);


#endif
