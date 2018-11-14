/*
Jonathan Baldwin
CS362 Fall 2018
Assign 4

Testing for smithy card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "Smithy"
#define MIN 0
#define MAX 3
#define MIN_PLYR 2
#define MAX_PLYR 4


int main(){
	srand(time(NULL));

	printf("-------------Testing %s Card---------------\n", TESTCARD);
	//loop to run multiple random values
	for(int n = 1; n < 51; n++){

		//initializing game to test
		struct gameState G, testG;
		int seed = 1000;
		int numPlayers = (rand() % (MAX_PLYR - MIN_PLYR + 1)) + MIN_PLYR;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
				sea_hag, tribute, smithy, great_hall};

		initializeGame(numPlayers, k, seed, &G);

		int currentPlayer = (rand() % (MAX - MIN + 1)) + MIN;
		int handpos = 0;
		
		printf("Test %d: current player should receive 3 cards\n", n);

		memcpy(&testG, &G, sizeof(struct gameState));
		int curCardCount = testG.handCount[currentPlayer];
		printf("player %d card count before call to smithy: %d\n", currentPlayer, curCardCount);

		cardSmithy(currentPlayer, &testG, handpos);
		int updateCardCount = testG.handCount[currentPlayer];
		printf("player %d card count after call to smithy: %d\n", currentPlayer, updateCardCount);

		if(updateCardCount - curCardCount == 3){
			printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
		} 
		else{
			printf("TEST FAILED. Count did not increase by 3.\n");
			
		}
		printf("\n");

	/******************************************************************************/
		printf("Test %d: current player discard should occur.\n", n);

		memcpy(&testG, &G, sizeof(struct gameState));
		int curDisCount = testG.discardCount[currentPlayer];
		printf("Player %d discard count before call to smithy: %d\n", currentPlayer, curDisCount);

		cardSmithy(currentPlayer, &testG, handpos);
		int updateDisCount = testG.discardCount[currentPlayer];
		printf("Player %d discard count after call to smithy: %d\n", currentPlayer, updateDisCount);

		if(updateDisCount - curDisCount >= 1){
			printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
		} 
		else{
			printf("TEST FAILED. Discard count did not change.\n");
			
		}
	}
	printf("End of randomtestcard1.\n");
	printf("\n");
	return 0;
}
