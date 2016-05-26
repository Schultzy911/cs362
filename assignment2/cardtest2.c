#include "dominion.h"
// testing Great Hall

int testGreatHall(int* failed){
    struct gameState g;

    int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};
    int r = initializeGame(2, k, 5, &g);
    int cards = g.handCount[0];
    int actions = g.numActions;

    cardEffect(great_hall, 0, 0, 0, &g, 0, &r);
    // card state and name will suffice
    myassert(failed, cards == g.handCount[0], "greatHall provides one additional card");
    myassert(failed, actions == g.numActions, "greatHall allows one additional action");

    return 0;
}
