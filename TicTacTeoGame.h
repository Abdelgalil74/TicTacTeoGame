
#ifndef TICTACTEOGAME_H_
#define TICTACTEOGAME_H_

#define E_OK        0
#define E_NOT_OK    1


void TicTacTeoGame_VoidInitializeGame(void);

void TicTacTeoGame_VoidShowGame(void);

sint32 TicTacTeoGame_sint32CheckWinner(const sint8 X_O);

sint32 TicTacTeoGame_sint32Player_X_O(const sint32 index,const sint8 X_O);

void TicTacTeoGame_VoidMultiPlayersMode(void);

void TicTacTeoGame_VoidEasySinglePlayersMode(void);
void TicTacTeoGame_VoidHardSinglePlayersMode(void);

void TicTacTeoGame_VoidEasySmartAlgorithm(void);
void TicTacTeoGame_VoidHardSmartAlgorithm(void);


#endif // _TICTACTEOGAME_H_
