/*
Jonathan Baldwin
CS362 Fall 2018
Assign 4

Testing for adventurer card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "Adventurer"
#define MIN 0
#define MAX 2
#define MIN_PLYR 2
#define MAX_PLYR 4

int main(){
	srand(time(NULL));
	printf("-------------Testing %s Card---------------\n", TESTCARD);
	//loop to run multiple random values
	for(int n = 1; n < 51; n++){
			
			//initialize game info 
			int numPlayers = (rand() % (MAX_PLYR - MIN_PLYR + 1)) + MIN_PLYR;
			//NOTE: i commented out the rand value because it was resulting 
			//in sporatic seg faults
			int currentPlayer = 0; //(rand() % (numPlayers - MIN + 1)) + MIN;
			int tempHand[0];

			struct gameState G, testG;
			int seed = 1000;
			int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
					sea_hag, tribute, smithy, great_hall};

			initializeGame(numPlayers, k, seed, &G);

			
			printf("Test %d: discard card should increase.\n", n);

			memcpy(&testG, &G, sizeof(struct gameState));
			int curDisCount = testG.discardCount[currentPlayer];
			printf("Player %d discard count before call to adventurer: %d\n", currentPlayer, curDisCount);

			//cardAdventurer(0, &testG, currentPlayer, tempHand, 0);
			AdventurerCard(&testG, 0, currentPlayer, tempHand, 0);
			int updateDisCount = testG.handCount[currentPlayer];
			printf("Player %d discard count after call to adventurer: %d\n", currentPlayer, updateDisCount);

			if(updateDisCount - curDisCount != 0){
				printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
			} 
			else{
				printf("TEST FAILED. Discard did not increase.\n");
			}
			printf("\n");	
			
		/*****************************************************************************/
			printf("Test %d: card count should change.\n", n);

			memcpy(&testG, &G, sizeof(struct gameState));
			int curCardCount = testG.handCount[currentPlayer];
			printf("Player %d card count before call to adventurer: %d\n", currentPlayer, curCardCount);

			//cardAdventurer(0, &testG, currentPlayer, tempHand, 0);
			AdventurerCard(&testG, 0, currentPlayer, tempHand, 0);
			int updateCardCount = testG.handCount[currentPlayer];
			printf("Player %d card count after call to adventurer: %d\n", currentPlayer, updateCardCount);

			if(updateDisCount - curDisCount != 0){
				printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
			} 
			else{
				printf("TEST FAILED. Card did not increase.\n");
			}
	}

	printf("End of cardtestadventurer.\n");
	printf("\n");
	return 0;
}