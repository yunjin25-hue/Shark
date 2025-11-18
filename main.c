#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define 

int rolldie(void)
{
    return rand()%MAX_DIE+1;
}

int main(int argc, char *argv[])
{
  int 
  int  
    
  srand( (unsigned)(time(NULL))); //·£´ý  
  
  //opening
  printf("===============================\n");
  printf("||      SHARK ISLAND GAME    || \n"); 
  printf("===============================\n\n\n");
  
  //step 1. initialization (player name setting, variables)
  board_initboard();
  
  //step 2. turn play (do-while)
  do{
  // 2-1. status printing
  board_printBoardStatus();
  
  // 2-2. roll die
  die_result=rolldie();
  
  
  
  // 2-3. move (result)
  pos+=die_result;
  
  coinResult=board_getBoardCoin([pos);
  
  printf("coin : %i\n";
  
  // 2-4. change turn, shark move
  }while(cnt<5);
  
  //step 3. game end (winner printing)
  
  
  //ending
  printf("\n\n\n\n\n\n\n");
  printf("===============================\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("!!          THE END          !!\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("===============================\n\n");
  
  system("PAUSE");	
  return 0;
}
