#include "dominion.h"
#include "stdio.h"
// test buyCard

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
    int i = 0;

    // initiate
    game.numPlayers = numplayers;

    // starting hand
    game.whoseTurn = 0;
    game.phase = 0;
    game.handCount[0] = 1;
    game.discardCount[0] = 0;
    game.deckCount[0] = 0;
    game.hand[0][0] = smithy;
    game.numBuys = 2;
    game.numActions = 1;
    game.coins = 0;
    for(i = 0; i <= treasure_map; i++)
        if (i != smithy)
						// all cards
            game.supplyCount[i] = 10;
        else // there are no smithy cards
            game.supplyCount[i] = 0;
		// will not be able to purchase
    myassert(buyCard(silver, &game) == -1);

    // gold to purchase with
    game.hand[0][0] = gold;
    game.coins = 3;
		// no smithys
    myassert(buyCard(smithy, &game) == -1);
    myassert(buyCard(village, &game) == 0);
		// discard contains 1
    myassert(game.discardCount[0] == 1);
		// subtract from supply
    myassert(game.supplyCount[village] == 9);
		// no more coins
    myassert(game.coins == 0);
		// subtract buy
    myassert(game.numBuys == 1);


    if (!failed){
        printf("buyCard() test passed successfully!\n");
    }else{
        printf("buyCard() test FAILED\n");
    }
    return 0;
}
