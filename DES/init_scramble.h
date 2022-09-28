#pragma once
void load_key(char key[8][8])
{
	char temp[9];
	FILE* key_fp = fopen("key.txt", "rb");
	for (int i = 0; i < 8; i++)
	{
		fscanf(key_fp, "%s", temp);
		for (int j = 0; j < 8; j++)
		{
			key[i][j] = temp[j];
		}
	}
}


void scramble_PC_1(char origin_cipher[8][8], char scramb_cipher[8][7])
{
	int pos;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			pos = PC_1[i][j];
			scramb_cipher[i][j] = origin_cipher[pos / 8][pos % 8 - 1];
		}
	}
}

void left_shift(char* key_)
{
	char temp;
	temp = key_[0];
	for (int i = 0; i < 27; i++)
	{
		key_[i] = key_[i + 1];
	}
	key_[27] = temp;
}



void scramble_PC_2(char key_[56], char sub_key[48])
{
	char* PC_2_ = (char*)PC_2;
	for (int i = 0; i < 48; i++)
	{
		sub_key[i] = key_[PC_2_[i] - 1];
	}
}

void generate_sub_key(char key[8][7], char sub_key[16][48])
{
	char* key_ = (char*)key;
	for (int i = 0; i < 16; i++)
	{
		if (move_time[i] == 1)
		{
			left_shift(key_);
			left_shift(key_ + 28);
		}
		if (move_time[i] == 2)
		{
			left_shift(key_);
			left_shift(key_);
			left_shift(key_ + 28);
			left_shift(key_ + 28);
		}

		scramble_PC_2(key_, sub_key[i]);
	}
}

void init_key(char sub_key[16][48])
{
	char key[8][8], key1[8][7];
	load_key(key);
	scramble_PC_1(key, key1);
	generate_sub_key(key1, sub_key);
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 48; j++) {
			sub_key[i][j] = sub_key[i][j] - '0';
		}
	}
}

void scramble(char A[], const char scramble_table[], int length)
{
	char scramble_text[64];
	for (int i = 0; i < length; i++)
		scramble_text[i] = A[scramble_table[i] - 1];
	for (int i = 0; i < length; i++)
		A[i] = scramble_text[i];
}
