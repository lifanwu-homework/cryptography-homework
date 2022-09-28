#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include"tables.h"
#include"init_scramble.h"
#include"wheel_function.h"
#include"encrypt.h"

int main()
{
	char plaintext[] = "0110110010010101001010100101010010100101100100101010011010100101";
	for (int i = 0; i < 64; i++)
		plaintext[i] = plaintext[i] - '0';
	char cipher[64];
	encrypt(plaintext, cipher, 64);
}
