/*
Jonathan Baldwin
CS362 Fall 2018, Assignment 3
unittest3.c
testing: getCost()
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

	
	int result1 = getCost(0);
	printf("-----------Testing getCost() Function------------\n");
	printf("Test 1: get cost for Curse card. Expected cost is 0.\n");
	if(result1 == 0){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else
		printf("TEST FAILED\n");
	printf("\n");
	
/*****************************************************************/	
	result1 = getCost(1);
	printf("Test 2: get cost for Estate card. Expected cost is 2.\n");
	if(result1 == 2){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else
		printf("TEST FAILED\n");
	printf("\n");

/*****************************************************************/
	result1 = getCost(26);
	printf("Test 3: get cost for Treasure_map card. Expected cost is 4.\n");
	if(result1 == 4){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else
		printf("TEST FAILED\n");
	printf("\n");

/*****************************************************************/
	result1 = getCost(27);
	printf("Test 4: request card out of enum range. Result should be -1 error.\n");
	if(result1 == -1){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else
		printf("TEST FAILED\n");

	printf("End of unittest3.\n");
	printf("\n");
	
	return 0;
}