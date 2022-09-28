#pragma once




void sub_encrypt(char sub_plaintext[64], char sub_cipher[64], char sub_key[16][48])
{

	scramble(sub_plaintext, (char*)IP, 64);
	for (int i = 0; i < 16; i++)
	{
		wheel_function(sub_plaintext, sub_plaintext + 32, sub_key[i]);
	}
	char temp;
	for (int i = 0; i < 32; i++)
	{
		temp = sub_plaintext[i];
		sub_plaintext[i] = sub_plaintext[i + 32];
		sub_plaintext[i + 32] = temp;
	}
	scramble(sub_plaintext, (char*)C_IP, 64);
}



void encrypt(char* plaintext, char* cipher, int length)
{
	char sub_key[16][48] = { 0 };
	init_key(sub_key);
	sub_encrypt(plaintext, cipher, sub_key);
	printf("\n");
	for (int i = 0; i < 64; i++)
	{
		printf("%d", plaintext[i]);
	}
}
