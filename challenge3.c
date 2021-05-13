#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "allChallenges.h"

// Single-byte XOR cipher
void challenge3() {

	char encodedHex [] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
	int byteArray[MAX_ARRAY_SIZE];
	size_t slength = strlen(encodedHex);

	hexString2Byte(encodedHex, slength, byteArray);

	for (char c = 'a'; c < 'z'; c++) {
		printf("\nkey is: %c\n", c);
		singleByteXOR(byteArray, c, slength / 2);
	}

	// result is 'x' --> COOKING !!!!!!!!

}

void singleByteXOR(int* ciphertext, char key, int len) {

	char result [MAX_ARRAY_SIZE];

	for (int i = 0; i < len; i++) {

		result[i] = ciphertext[i] ^ key;
	}
	printf("%s ", result);

}