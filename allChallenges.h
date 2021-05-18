
#ifndef _ALLCHALENNGES
#define _ALLCHALENNGES

#define MAX_ARRAY_SIZE 100

#include <stdbool.h>

extern void hexString2Byte(char* hexString, int len, int* byteArray);
extern bool singleByteXOR(int* ciphertext, char key, int len);

#endif