#include "dominion.h"
// test getCost

int testGetCost(int* failed){
    myassert(failed, getCost(adventurer) == 6, "Adventurer costs 6");
    myassert(failed, getCost(silver) == 3, "Silver costs 3");
    myassert(failed, getCost(estate) == 2, "Estate costs 2");

    return 0;
}
