#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 1000

//#define MAX_CHAR 2000
//#include"decryption.h"
#include"frequence.h"
using namespace std;



int main()
{
	unsigned char plaintext[MAX_LENGTH];
	int alpha_frequence[MAXN];
	int double_alpha_frequence[MAXN][MAXN] = { 0 };
	//int triple_alpha_frequence[MAXN][MAXN][MAXN] = { 0 };

	memset(alpha_frequence, 0, sizeof(alpha_frequence));
	memset(double_alpha_frequence, 0, sizeof(double_alpha_frequence));
	//memset(triple_alpha_frequence, 0, sizeof(triple_alpha_frequence));

	
	FILE* fp = fopen("plaintext.txt", "rb");
	
	while (!feof(fp))
	{
		memset(plaintext,0,sizeof(plaintext));
		fread(plaintext,sizeof(unsigned char),sizeof(plaintext),fp);
		all_alpha_frequence(plaintext,alpha_frequence);
		all_double_alpha_frequence(plaintext,double_alpha_frequence);
	}
	save_alpha_frequence(alpha_frequence);
	save_double_frequence(double_alpha_frequence);
	

	//system("python alpha_frequence.py");
}