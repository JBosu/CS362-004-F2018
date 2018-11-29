/*
Jonathan Baldwin
CS362 Fall 2018, Assignment 3
unittest1.c
testing: int compare(const void* a, const void* b)
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

	int a = 1;
	int b = 2;
	const void* x = &a;
	const void* y = &b;
	int result;

	printf("--------Testing compare() Function--------\n");
	printf("Test 1: a = 1, b = 2, result should be -1\n");
	result = compare(x, y);
	if(result == -1){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else
		printf("TEST FAILED\n");
	printf("\n");

/*****************************************************************/
	a = 2;
	b = 1;
	printf("Test 2: a = 2, b = 1, result should be 1\n");
	result = compare(x, y);
	if(result == 1){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else
		printf("TEST FAILED\n");

	printf("\n");

/*****************************************************************/
	a = 2;
	b = 2;
	printf("Test 3: a = 2, b = 2, result should be 0\n");
	result = compare(x, y);
	if(result == 0){
		printf("TEST SUCCESSFULLY COMPLETED - PASS\n");
	} 
	else
		printf("TEST FAILED\n");

	printf("End of unittest1.\n");
	printf("\n");


	return 0;
}