/*
Jonathan Baldwin
CS362 Fall 2018
Assign 4

Testing for village card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "Village"
#define MIN 0
#define MAX 3
#define MAX_PLYR 4
#define MIN_PLYR 2

int main(){
	srand(time(NULL));

	printf("-------------Testing %s Card---------------\n", TESTCARD);
	//loop to run multiple random values
	for(int n = 1; n < 51; n++){

		//initializing game info		
		int numPlayers = (rand() % (MAX_PLYR - MIN_PLYR + 1)) + MIN_PLYR;
		struct gameState G, testG;
		int seed = 1000;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
				sea_hag, tribute, smithy, great_hall};
		initializeGame(numPlayers, k, seed, &G);
		int currentPlayer = (rand() % (MAX - MIN + 1)) + MIN;
		int handpos = 0;
		shuffle(currentPlayer, &G);
		
		printf("Test %d: actions should increase by 2.\n", n);

		memcpy(&testG, &G, sizeof(struct gameState));
		int curActions = testG.numActions;
		printf("Player %d actions before call to village: %d\n", currentPlayer, curActions);

		cardVillage(currentPlayer, &testG, handpos);
		int updateActions = testG.numActions;
		printf("Player %d actions after call to village: %d\n", currentPlayer, updateActions);

		if(updateActions - curActions == 2){
			printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
		} 
		else{
			printf("TEST FAILED. Actions did not increase by 2.\n");
			printf("\n");
		}
		printf("\n");
		//*************************************************************************
		printf("Test %d: card count should increase by 1.\n", n);

		memcpy(&testG, &G, sizeof(struct gameState));
		int curCardCount = testG.handCount[currentPlayer];
		printf("Player %d card count before call to village: %d\n", currentPlayer, curCardCount);

		cardVillage(currentPlayer, &testG, handpos);
		int updateCardCount = testG.handCount[currentPlayer];
		printf("Player %d card count after call to village: %d\n", currentPlayer, updateCardCount);

		if(updateCardCount - curCardCount == 1){
			printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
		} 
		else{
			printf("TEST FAILED. Card count did not increase by 1.\n");
			printf("\n");
		}
	}
	printf("End of randomtestcard2.\n");
	printf("\n");
	return 0;
}