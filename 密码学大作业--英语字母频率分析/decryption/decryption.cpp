#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 10000
#define MAX_CHAR 2000

//#include"decryption.h"
#include"frequence.h"
using namespace std;



int main()
{
	char cipher[MAX_LENGTH], plaintext[MAX_LENGTH];
	int length;
	int alpha_frequence[26];
	int double_alpha_frequence[26][26] = { 0 };
	int triple_alpha_frequence[26][26][26] = { 0 };
	fileload(cipher, length);
	all_alpha_frequence(cipher, alpha_frequence);
	all_double_alpha_frequence(cipher, double_alpha_frequence);
	all_triple_alpha_frequence(cipher, triple_alpha_frequence);


	save_alpha_frequence(alpha_frequence);
	save_doubel_frequence(double_alpha_frequence);
	save_triple_alpha_frequence(triple_alpha_frequence);

	system("python alpha_frequence.py");
}