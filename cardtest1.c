#include "dominion.h"
// testing Village

int testVillage(int* failed){
    struct gameState g;

    int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};
    int r = initializeGame(2, k, 5, &g);
    g.whoseTurn = 0;
    int cards = g.handCount[0];
    int actions = g.numActions;

    cardEffect(village, 0, 0, 0, &g, 0, &r);
    // card state and name will suffice
    myassert(failed, cards == g.handCount[0], "Village provides one additional card");
    myassert(failed, actions+1 == g.numActions, "Village allows two additional actions");



    return 0;
}
