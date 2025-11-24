#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define MAXLENGTH 30
#define MAX_DIE   6
#define N_PLAYER  3

#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

char player_name[N_PLAYER][MAXLENGTH];
int player_position[N_PLAYER];
int player_coin[N_PLAYER];
int player_status[N_PLAYER];
char player_statusString[3][MAXLENGTH] = {"LIVE","DIE","END"};

void printPlayerPosition(int player)
{
     int i;
     for(i=0; i<N_BOARD; i++)
     {
       printf("|");
       if(i == payer_position[player])
       {
            printf("%c",player_name[player][0]");
       }
       else 
       {
            if(board_getBoardStatus(i)== BOARDSTATUS_OK)
              print(" ");
            else
              printf("X");
       }
     }
     printf("\n");

void printPlayerStatus(void);
{
     int i;
     for(i=0; i<N_PLAYER; i++)
     {
             printf("%s : pos %i, coin %i, status %s\n", 
                        player_name[i],
                        player_position[i],
                        player_coin[i],
                        player_statusString[player_status[i]] );
             printPlayerPosition(i);
     }
}

void initPlayer(void)
{
     int i;
     for(i=0; i<N_PLAYER; i++)
     {
              player_position[i] = 0;
              player_coin[i] = 0;
              player_status[i] = PLAYERSTATUS_LIVE;
              printf("Player %i's name: ",i);
              scanf("%s",player_name[i]);
              fflush(stdin);
     }
}



int rolldie(void)
{
    return rand()%MAX_DIE + 1;
}

int main(int argc, char *argv[])
{
  int cnt;
  int turn; // 매번 몇 번째 플레이어 턴인지 저장 필요 
  int dum;
    
  srand( (unsigned)(time(NULL))); //랜덤  
  
  //opening
  printf("===============================\n");
  printf("||      SHARK ISLAND GAME    || \n"); 
  printf("===============================\n\n\n");
  
  //step 1. initialization (player name setting, variables)
  board_initboard();
  initPlayer();
  //player init
  
  //step 2. turn play (do-while)
  cnt=0;
  turn=0;
  do{
     int die_result;
     
     
     if (player_status[turn] != PLAYERSTATUS_LIVE
     {
         turn=(turn+1)%N_PLAYER;   
         continue;        
     }
     
     // 2-1. status printing
     board_printBoardStatus();
    
     //player status(각자)
      printPlayerStatus(); 
  
     // 2-2. roll die
     printf("%s turn!!", player_name[turn]);
     printf("Press any key to roll a die!\n");
     scanf("%d", &dum);
     fflush(stdin);
     die_result=rolldie(); //player turn
  
     // 2-3. move (result) //player turn
      player_position[turn]+=die_result;
      if(player_position[turn] >= N_BOARD -1) // 한 칸 남았는데 주사위가 6 나오면 배열 넘어가는 문제  
      {
           player_position[turn] = N_BOARD-1;
           player_status[turn] = PLAYERSTATUS_END;
      } 
      
      printf("Die result : %i, %s moved to %i\n",
                  die_result,die_result[turn],player_position[turn]);
      
      player_coin[turn] += board_getBoardCoin(player_position[turn]);
      printf("Lucky! %s got %i coins\n",player_name[turn], player_coin[turn]);
      
      
      // 2-4. change turn, shark move
      //change turn
      turn=(turn+1)%N_PLAYER;
      
      //shark move
      if(turn==0)
      {
         int shark_pos = board_stepShark();
         printf("Shark moved to %i\n", shark_pos);
         
         checkDie();
      }
      cnt++;
       
  }while(cnt<5); //game end condition
  
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

// 문제 구역 찾는 법: break point 걸거나 #if 0과 #endif로 코드 막기 
// --> 코드 막았는데  잘 되면 막힌 부분이 문제!! 
