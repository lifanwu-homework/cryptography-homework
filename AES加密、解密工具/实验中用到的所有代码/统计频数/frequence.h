#pragma once
#pragma once

#define MAXN 256

void all_alpha_frequence(unsigned char* S, int alpha_frequence[MAXN])//������е��ַ���Ƶ��
{
	for (int i = 0; i<MAX_LENGTH-1; i++)
	{
		alpha_frequence[S[i]]++;
	}
}

void all_double_alpha_frequence(unsigned char* S, int double_alpha_frequence[MAXN][MAXN])
{
	for (int i = 0; i<MAX_LENGTH-2; i++)
	{
		double_alpha_frequence[S[i]][S[i + 1]]++;
	}
}

// void all_triple_alpha_frequence(char* S, int triple_alpha_frequence[26][26][26])
// {
// 	for (int i = 0; S[i + 2]; i++)
// 	{
// 		triple_alpha_frequence[S[i]][S[i + 1] - 'a'][S[i + 2] - 'a']++;
// 	}
// }


void save_alpha_frequence(int alpha_frequence[])
{
	FILE* fp = NULL;
	if ((fp = fopen("alpha_frequence.txt", "wb")) <= 0)perror("file open error");
	for (int i = 0; i < MAXN; i++)
	{
		fprintf(fp, "%d ", alpha_frequence[i]);
	}
	fclose(fp);
}

void save_double_frequence(int double_alpha_frequence[MAXN][MAXN])
{
	FILE* fp = NULL;
	if ((fp = fopen("double_alpha_frequence.txt", "wb")) <= 0)perror("file open error");
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{

			fprintf(fp, "%d ", double_alpha_frequence[i][j]);
		}
	}
	fclose(fp);
}

// void save_triple_alpha_frequence(int triple_alpha_frequence[26][26][26])
// {
// 	FILE* fp = NULL;
// 	if ((fp = fopen("triple_alpha_frequence.txt", "wb")) <= 0)perror("file open error");

// 	for (int i = 0; i < 26; i++)
// 	{
// 		for (int j = 0; j < 26; j++)
// 		{
// 			for (int k = 0; k < 26; k++)
// 			{
// 				//if (triple_alpha_frequence[i][j][k])
// 				{
// 					fprintf(fp, "%d ", triple_alpha_frequence[i][j][k]);
// 				}
// 			}
// 		}
// 	}
// 	fclose(fp);
// }