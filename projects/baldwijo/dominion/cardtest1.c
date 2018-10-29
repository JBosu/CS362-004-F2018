/*
Jonathan Baldwin
CS362 Fall 2018, Assignment 3
cardtest1.c
testing for smithy card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Smithy"


int main(){

	//int cardChange = 0;
	int currentPlayer = 0;
	int handpos = 0;

	struct gameState G, testG;
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, great_hall};

	initializeGame(numPlayers, k, seed, &G);

	printf("-------------Testing %s Card---------------\n", TESTCARD);
	printf("Test 1: current player should receive 3 cards\n");

	memcpy(&testG, &G, sizeof(struct gameState));
	int curCardCount = testG.handCount[currentPlayer];
	printf("player 1 card count before call to smithy: %d\n", curCardCount);

	cardSmithy(currentPlayer, &testG, handpos);
	int updateCardCount = testG.handCount[currentPlayer];
	printf("player 1 card count after call to smithy: %d\n", updateCardCount);

	if(updateCardCount - curCardCount == 3){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else{
		printf("TEST FAILED. Count did not increase by 3.\n");
		
	}
	printf("\n");

/******************************************************************************/
	printf("Test 2: current player discard should occur.\n");

	memcpy(&testG, &G, sizeof(struct gameState));
	int curDisCount = testG.discardCount[currentPlayer];
	printf("Player 1 discard count before call to smithy: %d\n", curDisCount);

	cardSmithy(currentPlayer, &testG, handpos);
	int updateDisCount = testG.discardCount[currentPlayer];
	printf("Player 1 discard count after call to smithy: %d\n", updateDisCount);

	if(updateDisCount - curDisCount >= 1){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else{
		printf("TEST FAILED. Discard count did not change.\n");
		
	}

	printf("End of cardtest1.\n");
	printf("\n");
	return 0;
}