#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "allChallenges.h"

#define STRING_SIZE 60

void challenge4() {

	FILE* fp;
	char string[STRING_SIZE];
	char* filename = "4.txt";
    int byteArray[MAX_ARRAY_SIZE];
    size_t slength;

	fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file %s", filename);
        return 1;
    }
    int j = 0;
    while (fgets(string, STRING_SIZE, fp) != NULL) {
        slength = strlen(string);
        printf("%s", string);
        hexString2Byte(string, slength, byteArray);

       // if (j != 0) {
            for (char c = 'a'; c <= 'z'; c++) {
                printf("\nkey is: %c\n", c);
                printf("1");
                if (singleByteXOR(byteArray, c, STRING_SIZE / 2))
                {
                    printf("2");
                    break;
                }

            }
        //}
        j++;

        
    }
       
    fclose(fp);

}