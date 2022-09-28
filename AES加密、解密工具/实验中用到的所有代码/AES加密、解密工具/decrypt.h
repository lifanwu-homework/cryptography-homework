#pragma once
void anti_changebytes(unsigned char cipher[4][4])
{
	for (int i = 0; i < 16; i++)cipher[0][i] = contrary_sbox[cipher[0][i]];
}

void anti_shiftrows(unsigned char cipher[4][4])
{
	unsigned char temp;
	temp = cipher[1][0], cipher[1][0] = cipher[1][3], cipher[1][3] = cipher[1][2], cipher[1][2] = cipher[1][1], cipher[1][1] = temp;
	temp = cipher[2][0], cipher[2][0] = cipher[2][2], cipher[2][2] = temp;
	temp = cipher[2][1], cipher[2][1] = cipher[2][3], cipher[2][3] = temp;
	temp = cipher[3][0], cipher[3][0] = cipher[3][1], cipher[3][1] = cipher[3][2], cipher[3][2] = cipher[3][3], cipher[3][3] = temp;
}

void anti_mixColumn(unsigned char cipher[4][4])
{
	char temp[4] = { 0 };
	for (int j = 0; j < 4; j++)
	{
		temp[0] = xEtime(cipher[0][j]) ^ xBtime(cipher[1][j]) ^ xDtime(cipher[2][j]) ^ x9time(cipher[3][j]);
		temp[1] = x9time(cipher[0][j]) ^ xEtime(cipher[1][j]) ^ xBtime(cipher[2][j]) ^ xDtime(cipher[3][j]);
		temp[2] = xDtime(cipher[0][j]) ^ x9time(cipher[1][j]) ^ xEtime(cipher[2][j]) ^ xBtime(cipher[3][j]);
		temp[3] = xBtime(cipher[0][j]) ^ xDtime(cipher[1][j]) ^ x9time(cipher[2][j]) ^ xEtime(cipher[3][j]);
		for (int i = 0; i < 4; i++)cipher[i][j] = temp[i];
	}
}

void decrypt(unsigned char plaintext[4][4], unsigned char subkeys[4][44], unsigned char cipher[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cipher[i][j] = plaintext[i][j];
		}
	}
	Add_subkey(cipher, subkeys, 10);
	anti_shiftrows(cipher);
	anti_changebytes(cipher);
	for (int i = 9; i >= 1; i--)
	{
		Add_subkey(cipher, subkeys, i);
		anti_mixColumn(cipher);
		anti_shiftrows(cipher);
		anti_changebytes(cipher);
	}
	Add_subkey(cipher, subkeys, 0);
}
