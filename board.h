#define BOARDSTATUS_OK          1 //원래 board.c에 있었던 것 
#define BOARDSTATUS_NOK         0 //main.c에서도 쓰려면 board.h에 넣어 줘야 함 
#define N_BOARD                 20

void board_printBoardStatus(void);
int board_getBoardStatus(int pos);
int board_getBoardCoin(int pos);
void board_initBoard(void);

