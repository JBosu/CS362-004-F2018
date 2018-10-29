/*
Jonathan Baldwin
CS362 Fall 2018, Assignment 3
cardtest3.c
testing for great_halls
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Great Halls"


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
	shuffle(currentPlayer, &G);

	printf("-------------Testing %s Card---------------\n", TESTCARD);
	printf("Test 1: actions should increase by 2.\n");

	memcpy(&testG, &G, sizeof(struct gameState));
	int curActions = testG.numActions;
	printf("Player 1 actions before call to great_halls: %d\n", curActions);

	cardGreat_halls(currentPlayer, &testG, handpos);
	int updateActions = testG.numActions;
	printf("Player 1 actions after call to great_halls: %d\n", updateActions);

	if(updateActions - curActions == 2){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else{
		printf("TEST FAILED. Actions did not increase by 2.\n");
		printf("\n");
	}
	printf("\n");
	//*************************************************************************
	printf("Test 2: card count should increase by 1.\n");

	memcpy(&testG, &G, sizeof(struct gameState));
	int curCardCount = testG.handCount[currentPlayer];
	printf("Player 1 card count before call to great_halls: %d\n", curCardCount);

	cardGreat_halls(currentPlayer, &testG, handpos);
	int updateCardCount = testG.handCount[currentPlayer];
	printf("Player 1 card count after call to great_halls: %d\n", updateCardCount);

	if(updateCardCount - curCardCount == 1){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else{
		printf("TEST FAILED. Card count did not increase by 1.\n");
		printf("\n");
	}
	printf("\n");

	printf("End of cardtest4.\n");
	printf("\n");
	return 0;
}