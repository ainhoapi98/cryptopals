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

	//for (int i = 0; i < slength / 2; i++) printf("%x ", byteArray[i]);

	for (char c = 'a'; c <= 'z'; c++) 
		if (singleByteXOR(byteArray, c, slength / 2)) printf("key is: %c\n", c);;
	
}

bool singleByteXOR(int* ciphertext, char key, int len) {

	char result [MAX_ARRAY_SIZE];
	int ok_char = 0, spec_char = 0;

	for (int i = 0; i < len; i++) {

		printf("%x ", ciphertext[i]);
		result[i] = ciphertext[i] ^ key;
		if (isalpha(result[i])) ok_char++;
		else spec_char++;
	}
	if (spec_char < (len / 4)) {
		printf("RESULT: %s ", result);
		return true;
	}
	else return false;

}