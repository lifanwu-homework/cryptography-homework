#pragma once

const double frequence[26] = { 8.19,1.47,3.83,3.91,12.25,2.26,1.71,4.57,7.10,0.14,0.41,3.77,3.34,7.06,7.26,2.89,0.09,6.85,6.36, 9.41,2.58,1.09,1.59,0.21,1.58 ,0.08 };
const char character_sequence[27] = "etaoinrshdclmpufgwybkjvxqz";
struct character
{
	char character;
	int frequence;
	double frequense;
};

int compare(const void* arg1, const void* arg2)//compare the frequence of the character
{
	return ((*(character*)arg1).frequence < (*(character*)arg2).frequence) ? 1 : -1;
}



//the fileload below is designed for solving a cipher in game noita

//void fileload()
//{
//	char origin[9][MAX_LENGTH];
//	int all_length[9] = { 0 };
//	length = 0;
//	for (int i = 0; i < 9; i++)
//	{
//		int j = 0;
//		int temp;
//		char pwd[100] = { 0 };
//		sprintf(pwd, "C:\\Users\\hi\\source\\repos\\decryption\\ÃÜÂë\\ÃÜÂë%d.txt", i + 1);
//		FILE* fp = fopen(pwd, "rb");
//		for (j = 0; (temp = fgetc(fp)) != EOF; j++)
//		{
//			if (temp < '0' || temp>'4') {
//				j--;
//				continue;
//			}
//			origin[i][j] = temp;
//		}
//		all_length[i] = j;
//		for (int k = 0; k + 1 < j; k += 2)
//		{
//			cipher[length] = (origin[i][k] - '0') * 5 + (origin[i][k + 1] - '0') + 'a';
//			length++;
//		}
//	}
//	printf("%d\n", length);
//	memset(all_char, 0, sizeof(all_char));
//	char_num = 0;
//}


//to calculate the frequence of all 26 character in the cipher,stored in the struct character
void statistic(int& char_num, int& length, char cipher[], character all_char[])
{
	memset(all_char, 0, sizeof(all_char));
	char_num = 0;
	bool flag = false;
	for (int i = 0; i < length; i++)
	{
		flag = false;
		for (int j = 0; j < char_num; j++)
		{
			if (all_char[j].character == cipher[i])
			{
				all_char[j].frequence++;
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			all_char[char_num].character = cipher[i];
			all_char[char_num].frequence++;
			char_num++;
		}
	}
	qsort(all_char, char_num, sizeof(character), compare);
	for (int i = 0; i < char_num; i++)
	{
		all_char[i].frequense = 1.0 * all_char[i].frequence / length;
	}
}


//calculate the Index_of_Coincidence of the character
double Index_of_Coincidence(int char_num, int length, character all_char[])
{
	double ans = 0;
	for (int i = 0; i < char_num; i++)
	{
		ans += all_char[i].frequence * (all_char[i].frequence - 1);
	}
	ans = ans / (length * (length - 1));
	printf("\nIndex_of_Coincidence:%lf\n", ans);
	return ans;
}


//according to the frequence,create a map between the cipher and the plaintext
void get_map(const character all_char[], const int char_num, char map[])
{
	for (int i = 0; i < char_num; i++)
	{
		map[all_char[i].character] = character_sequence[i];
	}
}

//using a map to decrypt the cipher,stored in plaintext
void decryption(const char cipher[], char plaintext[], int length, char map[])
{
	memset(plaintext, 0, length + 1);
	for (int i = 0; i < length; i++)
	{
		plaintext[i] = map[cipher[i]];
	}
}

void Next(char* T, int* next) {
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i < strlen(T)) {
		if (j == 0 || T[i - 1] == T[j - 1]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}
int KMP(char* S, char* T) {
	int next[10];
	Next(T, next);
	int i = 1, j = 1;
	while (i <= strlen(S) && j <= strlen(T)) {
		if (j == 0 || S[i - 1] == T[j - 1]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j > strlen(T)) {
		return i - (int)strlen(T);
	}
	return -1;
}

int search(char* S, char* T)
{
	int i = 0, j = 0, count = 0;
	while ((j = KMP(&S[i], T)) != -1)
	{
		i += j;
		count++;
	}
	return count;
}
