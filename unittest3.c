#include "dominion.h"
#include "stdio.h"
// numHandCards test

static int failed = 0;

void myassert(int bool_){
    if(!bool_){
        printf("ASSERT FAILED\n");
        failed = 1;
    }
}

int main(){
    struct gameState game;
    int numplayers = 4;
    int cardnum[] = {5, 3, 4, 2};
    int i = 0;

    // initiate
    game.numPlayers = numplayers;
    for(i = 0; i < numplayers; i++){
        game.handCount[i] = cardnum[i];
    }

    // does the funciton collect the appropriate data?
    for(i = 0; i < numplayers; i++){
        game.whoseTurn = i;
        myassert(numHandCards(&game) == cardnum[i]);
    }

    if (!failed){
        printf("numHandCards() TEST PASSED SUCCESSFULLY\n");
    }else{
        printf("numHandCards() TEST FAILED\n");
    }
    return 0;
}
