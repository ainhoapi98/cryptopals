#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "allChallenges.h"

static char byteToBase64[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
								'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
								'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
								'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
								'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
								'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
								'w', 'x', 'y', 'z', '0', '1', '2', '3',
								'4', '5', '6', '7', '8', '9', '+', '/' };


int* hex2Byte(char* hexString);

// Convert hex to base64
int challenge1() {

	printf("Convert hex to base64");
	const char hexString[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	int j = 0, i = 0;
	char left, right;
	size_t slength = strlen(hexString);
	size_t dlength = slength / 2;

	int byteArray[MAX_ARRAY_SIZE];

	for (i = 0; i < slength; i += 2, j++) {

		left = hexString[i];
		right = hexString[i + 1];
		byteArray[j] = ((byteMap(left) << 4) | (byteMap(right)));
		//*byteArray = byte;
		printf("%x ", byteArray[j]);

	}


	printf("Base64 String: \n");
	char base64String[MAX_ARRAY_SIZE];
	// BYTES TO BASE64
	for (int i = 0; i < j; i++) {

		base64String[i] = (char)byteToBase64[byteArray[i]];
		printf("%c", base64String[i]);
	}

	return 0;
}



int byteMap(char c) {

	char a = toupper(c);
	//printf(" %c \n", a);
	switch (a) {
	case '0': return 0x00;
	case '1': return 0x01;
	case '2': return 0x02;
	case '3': return 0x03;
	case '4': return 0x04;
	case '5': return 0x05;
	case '6': return 0x06;
	case '7': return 0x07;
	case '8': return 0x08;
	case '9': return 0x09;
	case 'A': return 0x0A;
	case 'B': return 0x0B;
	case 'C': return 0x0C;
	case 'D': return 0x0D;
	case 'E': return 0x0E;
	case 'F': return 0x0F;
	}

}
