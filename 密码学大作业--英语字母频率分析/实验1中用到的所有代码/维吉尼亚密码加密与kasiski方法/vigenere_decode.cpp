#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
using namespace std;

int main()
{
    unsigned char cipher[MAX_LENGTH];
    unsigned char key[]="vigenere";
    int length, key_bias = 0;
    int length_key=0;
    for(length_key=0;key[length_key];length_key++);
    memset(cipher, 0, MAX_LENGTH);

    int temp1 = 0;
    unsigned char temp = 0;
    FILE *fp_plaintext = fopen("cipher.txt", "rb");
    FILE *fp_cipher = fopen("decode.txt", "wb");
    for (length = 0; (temp1 = fgetc(fp_plaintext)) != EOF; )
    {
        temp = (unsigned char)temp1;
            cipher[length] = (temp - 'a'-(key[key_bias]-'a')+26)%26+'a';
            //printf("%c %c %c \n",temp,cipher[length],key[key_bias]);
            key_bias=(key_bias+1)%length_key;
            length++;
        if(length>=MAX_LENGTH)
        {
            length=0;
            fwrite(cipher,sizeof(unsigned char),strlen((const char*)cipher),fp_cipher);
            memset(cipher,0,sizeof(cipher));
        }
    }
    int last_length=0;
    fwrite(cipher,sizeof(unsigned char),strlen((const char*)cipher),fp_cipher);
    
}