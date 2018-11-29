/*
Jonathan Baldwin
CS362 Fall 2018, Assignment 3
unittest4.c
testing: shuffle()

*/


//#include "dominion.c"
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main(){

	struct gameState G;
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, great_hall};

	initializeGame(numPlayers, k, seed, &G);

/**************************************************************/	
	int result1 = shuffle(0, &G);
	printf("-----------Testing shuffle() Function----------\n");
	printf("Test 1: shuffle and confirm it completed successfully. Expect return 0.\n");
	if(result1 == 0){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else
		printf("TEST FAILED\n");
	printf("\n");

/**************************************************************/
	printf("Test 2: check player 1 cards in hand. Should be 5 cards in hand.\n");
	int numOfCards = G.handCount[0];
	if(numOfCards == 5){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else
		printf("TEST FAILED\n");
	printf("\n");
/**************************************************************/
	printf("Test 3: check player 1 played cards. Should be 0 cards played.\n");
	int numPlayed = G.playedCards[0];
	if(numPlayed == 0){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else
		printf("TEST FAILED\n");
	printf("\n");

/**************************************************************/
	printf("Test 4: check player 1 discard count. Should be 0 cards discarded.\n");
	int numDiscard = G.discardCount[0];
	if(numDiscard == 0){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else
		printf("TEST FAILED\n");
	printf("\n");

/**************************************************************/
	printf("Test 5: cards held for player out of range. Should return an error.\n");
	int result = G.discardCount[5];
	if(result >= 0){
		printf("TEST FAILED. This should return an error\n");
		printf("Result: %d \n", result);
	} 
	else
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");

	printf("End of unittest4.\n");
	printf("\n");
	
	return 0;
}