#include "dominion.h"
// testing adventurer

int testAdventurer(int* failed){
    struct gameState g;
    int i;
    int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};
    int r = initializeGame(2, k, 5, &g);
    g.whoseTurn = 0;
    int cards = g.handCount[0];
    int actions = g.numActions;
    int treasureCards = 0;
    int newTreasureCards = 0;

    // add treasure card if any player's cards contain monetary value
    for(i = 0; i < cards; i++)
        if (g.hand[0][i] == copper || g.hand[0][i] == silver || g.hand[0][i] == gold)
            treasureCards++;

    cardEffect(smithy, 0, 0, 0, &g, 0, &r);
    // card state and name will suffice
    myassert(failed, cards+1 == g.handCount[0], "Adventurer provides two additional cards");
    myassert(failed, actions-1 == g.numActions, "Adventurer does not provide additional actions");
    for(i = 0; i < cards; i++)
        if (g.hand[0][i] == copper || g.hand[0][i] == silver || g.hand[0][i] == gold)
            newTreasureCards++;
    myassert(failed, treasureCards+2 == newTreasureCards, "Adventurer provides two treasure cards");


    return 0;
}
