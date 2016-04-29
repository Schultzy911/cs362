#include "dominion.h"
#include "stdio.h"
// Test whoseTurn()

static int failed = 0;
void myassert(int bool_){
    if(!bool_){
        printf("ASSERT FAILED\n");
        failed = 1;
    }
}

int main(){
   struct gameState game;

   // initiate
   game.numPlayers = 4;
   game.whoseTurn = 2;
   myassert(whoseTurn(&game) == 2);
   if (!failed){
       printf("whoseTurn() TEST PASSED SUCCESSFULLY\n");
   }else{
       printf("whoseTurn() TEST FAILED\n");
   }
   return 0;
}
