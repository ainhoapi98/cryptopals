#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "allChallenges.h"
#include <openssl/aes.h>

void challenge7() {
	char key[] = "YELLOW SUBMARINE";
    FILE* fp;
    char* filename = "7.txt";
    
    AES_KEY aes_key;
    char* ciphertext, plaintext;
    int fsize;
   
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file %s", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    plaintext = (char*)malloc(fsize * sizeof(char));
    fread(plaintext, sizeof(char), fsize, fp);
            printf("file size is:\n%d\n",fsize);
            printf("Source is:\n%s\n",plaintext);
            printf("strlen is: \n%d\n",strlen(plaintext));
    fclose(fp);

    /*size_t pos = ftell(fp);    // Current position
    fseek(fp, 0, SEEK_END);    // Go to end
    size_t length = ftell(fp); // read the position which is the size
    fseek(fp, pos, SEEK_SET);
    */

    ciphertext = (char*)malloc(fsize * sizeof(char));



    //AES_set_decrypt_key(key, 128, &aes_key);


//    AES_ecb_encrypt(&ciphertext, &plaintext, &aes_key, AES_DECRYPT);



}