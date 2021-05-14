#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "allChallenges.h"

void challenge5(){

	char string[] = "Burning 'em, if you ain't quick and nimble I go crazy when I hear a cymbal";
	char key [] = "ICE";
	size_t slength = strlen(string);
	int t = 0;
	char result[MAX_ARRAY_SIZE];

	for (int i = 0; i < slength; i++) {
		result[i] = string[i] ^ key[t];
		if (t == 2) t = 0;
		else t++;

		printf("%x ", result[i]);

	}

}