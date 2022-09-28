#pragma once

void g_function(unsigned char w[4], int j)//复杂函数g
{
	unsigned char temp = w[0];
	w[0] = w[1];
	w[1] = w[2];
	w[2] = w[3];
	w[3] = temp;
	for (int i = 0; i < 4; i++)w[i] = sbox[w[i]];
	w[0] ^= Rcon[j / 4 - 1];
}


void generate_subkey(unsigned char key[4][4], unsigned char subkeys[4][44])//子密钥生成
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			subkeys[i][j] = key[i][j];
		}
	}
	for (int j = 4; j < 44; j++)
	{
		if (j % 4 == 0) {//对于4的整数列，要将j-1列的值经复杂函数g变换后在与j-4列异或
			unsigned char temp[4] = { 0 };
			for (int i = 0; i < 4; i++)temp[i] = subkeys[i][j - 1];
			g_function(temp, j);
			for (int i = 0; i < 4; i++)subkeys[i][j] = temp[i] ^ subkeys[i][j - 4];
		}
		else {//对于非4的整数列，这一列的值就是j-1列与j-4列的异或
			for (int i = 0; i < 4; i++)subkeys[i][j] = subkeys[i][j - 1] ^ subkeys[i][j - 4];
		}
	}
}