#pragma once

void fileload(char cipher[], int& length)//load the cipher
{
	memset(cipher, 0, MAX_LENGTH);
	int temp;
	FILE* fp = fopen("cipher.txt", "rb");
	for (length = 0; (temp = fgetc(fp)) != EOF; length++)
	{
		if (temp <= 'Z' && temp >= 'A')
			cipher[length] = temp - 'A' + 'a';
		else if (temp < 'z' && temp>'a')cipher[length] = temp;
		else
		{
			length--;
		}
	}

}

void all_alpha_frequence(char* S, int alpha_frequence[])//获得所有单字符的频数
{
	memset(alpha_frequence, 0, 26 * sizeof(int));
	for (int i = 0; S[i]; i++)
	{
		alpha_frequence[S[i] - 'a']++;
	}
}

void all_double_alpha_frequence(char* S, int double_alpha_frequence[26][26])
{
	memset(double_alpha_frequence, 0, sizeof(double_alpha_frequence));
	for (int i = 0; S[i + 1]; i++)
	{
		double_alpha_frequence[S[i] - 'a'][S[i + 1] - 'a']++;
	}
}

void all_triple_alpha_frequence(char* S, int triple_alpha_frequence[26][26][26])
{
	memset(triple_alpha_frequence, 0, sizeof(triple_alpha_frequence));
	for (int i = 0; S[i + 2]; i++)
	{
		triple_alpha_frequence[S[i] - 'a'][S[i + 1] - 'a'][S[i + 2] - 'a']++;
	}
}


void save_alpha_frequence(int alpha_frequence[])
{
	FILE* fp = NULL;
	if ((fp = fopen("alpha_frequence.txt", "wb")) <= 0)perror("file open error");
	for (int i = 0; i < 26; i++)
	{
		fprintf(fp, "%d ", alpha_frequence[i]);
	}
	fclose(fp);
}

void save_doubel_frequence(int double_alpha_frequence[26][26])
{
	FILE* fp = NULL;
	if ((fp = fopen("double_alpha_frequence.txt", "wb")) <= 0)perror("file open error");
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{

			fprintf(fp, "%d ", double_alpha_frequence[i][j]);


		}
	}
	fclose(fp);
}

void save_triple_alpha_frequence(int triple_alpha_frequence[26][26][26])
{
	FILE* fp = NULL;
	if ((fp = fopen("triple_alpha_frequence.txt", "wb")) <= 0)perror("file open error");

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			for (int k = 0; k < 26; k++)
			{
				if (triple_alpha_frequence[i][j][k])
				{
					fprintf(fp, "%c%c%c %d\n", i + 'a', j + 'a', k + 'a', triple_alpha_frequence[i][j][k]);
				}
			}
		}
	}
	fclose(fp);
}