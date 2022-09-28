
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include "table.h"
#include "init_key.h"
#include "encrypt.h"
#include "decrypt.h"
int main()
{
	unsigned char key[4][4] = {0};
	unsigned char sub_key[4][44] = {0};
	unsigned char plaintext[4][4] = {0};
	unsigned char cipher[4][4] = {0};
	unsigned char decode[4][4] = {0};

	FILE *fp_key = fopen("key.txt", "rb");
	FILE *fp_plaintext = fopen("plaintext.txt", "rb");
	FILE *fp_cipher = fopen("cipher.txt", "wb");

	fread(key, sizeof(unsigned char), sizeof(key), fp_key);
	fclose(fp_key);

	generate_subkey(key, sub_key);
	
	while (!feof(fp_plaintext))//read all the plaintext and encrypt them,store all the cipher in cipher.txt
	{
		memset(plaintext,0,sizeof(plaintext));
		fread(plaintext, sizeof(unsigned char), sizeof(plaintext), fp_plaintext);
		encrypt(plaintext, sub_key, cipher);
		fwrite(cipher, sizeof(unsigned char), sizeof(cipher), fp_cipher);
	}
	fclose(fp_plaintext);
	fclose(fp_cipher);
	
	FILE *fp_decode = fopen("decode.txt", "wb");
	fp_cipher = fopen("cipher.txt", "rb");
	
	while (!feof(fp_cipher))//read all the cipher and decrypt them,store the decode answer in decode.txt
	{
		memset(cipher,0,sizeof(cipher));
		fread(cipher, sizeof(unsigned char), sizeof(cipher), fp_cipher);
		decrypt(cipher, sub_key, decode);
		fwrite(decode, sizeof(unsigned char), sizeof(decode), fp_decode);
	}

	fclose(fp_decode);
	fclose(fp_cipher);
}