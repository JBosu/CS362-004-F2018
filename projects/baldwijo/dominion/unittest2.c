/*
Jonathan Baldwin
CS362 Fall 2018, Assignment 3
unittest2.c
testing: int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7,
		  int k8, int k9, int k10)
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

	struct gameState G, G2;
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, great_hall};

	int result1 = initializeGame(numPlayers, k, seed, &G);

/**************************************************************/	
	printf("------Testing initializeGame() Function------\n");
	printf("Test 1: initialize 10 unique Kingdom Cards and 2 players.\n");
	if(result1 == 0){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else
		printf("TEST FAILED\n");
	printf("\n");

/***************************************************************/
	printf("Test 2: initialize 2 duplicate Kingdom Cards and 2 players.\n");
	printf("Expected result should throw an error.\n");
	int k2[10] = {adventurer, smithy, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, great_hall};
	int result2 = initializeGame(numPlayers, k2, seed, &G2);
	if(result2 == -1){
			printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
			printf("This correctly resulted in an error for duplicate K card.\n");
		} 
		else
			printf("TEST FAILED\n");
		printf("\n");

/*****************************************************************/
	printf("Test 3: initialize only 9 Kingdom Cards and 2 players.\n");
	printf("Expected result should throw an error.\n");
	int k3[10] = {adventurer, smithy, village, minion, mine, cutpurse,
			sea_hag, tribute, great_hall};
	int result3 = initializeGame(numPlayers, k3, seed, &G2);
	if(result3 == -1){
			printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
		} 
		else
			printf("TEST FAILED\n");
		printf("\n");

/*****************************************************************/
	numPlayers = 5;
	printf("Test 4: initialize game with 5 players, which exceeds the max allowed.\n");
	printf("Expected result should throw an error.\n");
	int k4[10] = {adventurer, smithy, village, minion, mine, cutpurse,
			sea_hag, tribute, great_hall, village};
	int result4 = initializeGame(numPlayers, k4, seed, &G2);
	if(result4 == -1){
			printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
		} 
		else
			printf("TEST FAILED\n");

	printf("End of unittest2.\n");
	printf("\n");
	
	return 0;
}