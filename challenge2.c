#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "allChallenges.h"

void hexString2Byte(char* hexString, int len, int* byteArray);

// Fixed XOR
void challenge2() {


	static const char string1[] = "1c0111001f010100061a024b53535009181c";
	static const char string2[] = "686974207468652062756c6c277320657965";
	char left, right;
	size_t slength = strlen(string1);
	size_t dlength = slength / 2;
	int i, j = 0;

	int byteArray1[MAX_ARRAY_SIZE];
	int byteArray2[MAX_ARRAY_SIZE];
	int result[MAX_ARRAY_SIZE];

	printf("String 1: %s \n", string1);
	printf("String 2: %s \n", string2);


	hexString2Byte(&string1, slength, byteArray1);
	hexString2Byte(&string2, slength, byteArray2);

	// convert to byte first
	for (i = 0; i < slength; i += 2, j++) {

		left = string1[i];
		right = string1[i + 1];
		byteArray1[j] = ((byteMap(left) << 4) | (byteMap(right)));

		left = string2[i];
		right = string2[i + 1];
		byteArray2[j] = ((byteMap(left) << 4) | (byteMap(right)));

	}

	printf("String1 XOR String2: \n");

	for (i = 0; i < dlength; i++)
	{
		result[i] = byteArray1[i] ^ byteArray2[i];
		printf("%x ", result[i]);
	}

	return 0;
}

void hexString2Byte(char* hexString, int len, int * byteArray) {

	char left, right;
	int i, j = 0;
	
	for (i = 0; i < len; i += 2, j++) {

		left = hexString[i];
		right = hexString[i + 1];
		byteArray[j] = ((byteMap(left) << 4) | (byteMap(right)));
	}
}
