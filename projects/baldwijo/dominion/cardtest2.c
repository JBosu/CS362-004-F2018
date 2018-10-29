/*
Jonathan Baldwin
CS362 Fall 2018, Assignment 3
cardtest1.c
testing for adventurer card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Adventurer"


int main(){

	//int cardChange = 0;
	int currentPlayer = 0;
	//int handpos = 0;
	int tempHand[0];

	struct gameState G, testG;
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, great_hall};

	initializeGame(numPlayers, k, seed, &G);

	printf("-------------Testing %s Card---------------\n", TESTCARD);
	printf("Test 1: discard card should increase.\n");

	memcpy(&testG, &G, sizeof(struct gameState));
	int curDisCount = testG.discardCount[currentPlayer];
	printf("player 1 discard count before call to adventurer: %d\n", curDisCount);

	cardAdventurer(0, &testG, currentPlayer, tempHand, 0);
	int updateDisCount = testG.handCount[currentPlayer];
	printf("player 1 discard count after call to adventurer: %d\n", updateDisCount);

	if(updateDisCount - curDisCount != 0){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else{
		printf("TEST FAILED. Discard did not increase.\n");
	}
	printf("\n");	
	
/*****************************************************************************/
	printf("Test 2: card count should change.\n");

	memcpy(&testG, &G, sizeof(struct gameState));
	int curCardCount = testG.handCount[currentPlayer];
	printf("Player 1 card count before call to adventurer: %d\n", curCardCount);

	cardAdventurer(0, &testG, currentPlayer, tempHand, 0);
	int updateCardCount = testG.handCount[currentPlayer];
	printf("Player 1 card count after call to adventurer: %d\n", updateCardCount);

	if(updateDisCount - curDisCount != 0){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else{
		printf("TEST FAILED. Card did not increase.\n");
	}


	printf("End of cardtest2.\n");
	printf("\n");
	return 0;
}