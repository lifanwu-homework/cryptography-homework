#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 10001

//#define MAX_CHAR 2000
//#include"decryption.h"
#include"frequence.h"
using namespace std;



int main()
{
	char cipher[MAX_LENGTH], plaintext[MAX_LENGTH];
	int length, round = 0;
	int alpha_frequence[26];
	int double_alpha_frequence[26][26] = { 0 };
	int triple_alpha_frequence[26][26][26] = { 0 };
	memset(cipher, 0, MAX_LENGTH);
	memset(alpha_frequence, 0, sizeof(alpha_frequence));
	memset(double_alpha_frequence, 0, sizeof(double_alpha_frequence));
	memset(triple_alpha_frequence, 0, sizeof(triple_alpha_frequence));

	int temp1 = 0;
	unsigned char temp = 0;
	FILE* fp = fopen("plaintext.txt", "rb");
	for (length = 0; (temp1 = fgetc(fp)) != EOF; length++)
	{
		temp = (unsigned char)temp1;
		if (temp <= 'Z' && temp >= 'A')
			cipher[length] = temp - 'A' + 'a';
		else if (temp <= 'z' && temp >= 'a')cipher[length] = temp;
		else
		{
			length--;
		}
		if (length >= MAX_LENGTH - 10)
		{
			all_alpha_frequence(cipher, alpha_frequence);
			all_double_alpha_frequence(cipher, double_alpha_frequence);
			all_triple_alpha_frequence(cipher, triple_alpha_frequence);
			memset(cipher, 0, MAX_LENGTH);
			round++;
			length = -1;
			//printf("%d alpha have been statistics!\n", round * (MAX_LENGTH - 9));

		}
	}

	all_alpha_frequence(cipher, alpha_frequence);
	all_double_alpha_frequence(cipher, double_alpha_frequence);
	all_triple_alpha_frequence(cipher, triple_alpha_frequence);
	printf("%d alpha have been statistics!", round * (MAX_LENGTH - 9) + length);

	save_alpha_frequence(alpha_frequence);
	save_doubel_frequence(double_alpha_frequence);
	save_triple_alpha_frequence(triple_alpha_frequence);

	system("python alpha_frequence.py");
}