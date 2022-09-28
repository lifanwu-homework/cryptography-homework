#pragma once
void Add_subkey(unsigned char plaintext[4][4], unsigned char subkeys[4][44], int n)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			plaintext[i][j] ^= subkeys[i][j + 4 * n];
	}
}

void changebytes(unsigned char cipher[4][4])//sbox change
{
	for (int i = 0; i < 16; i++)cipher[0][i] = sbox[cipher[0][i]];
}

void shiftrows(unsigned char cipher[4][4])//shift the rows
{
	unsigned char temp;
	temp = cipher[1][0], cipher[1][0] = cipher[1][1], cipher[1][1] = cipher[1][2], cipher[1][2] = cipher[1][3], cipher[1][3] = temp;
	temp = cipher[2][0], cipher[2][0] = cipher[2][2], cipher[2][2] = temp;
	temp = cipher[2][1], cipher[2][1] = cipher[2][3], cipher[2][3] = temp;
	temp = cipher[3][0], cipher[3][0] = cipher[3][3], cipher[3][3] = cipher[3][2], cipher[3][2] = cipher[3][1], cipher[3][1] = temp;
}

static unsigned char x2time(unsigned char x)
{
	if (x & 0x80)
	{
		return (((x << 1) ^ 0x1B) & 0xFF);
	}
	return x << 1;
}
/*������*3�˷� The x2time() function */
static unsigned char x3time(unsigned char x)
{
	return (x2time(x) ^ x);
}
/*������*4�˷� The x4time() function */
static unsigned char x4time(unsigned char x)
{
	return (x2time(x2time(x)));
}
/*������*8�˷� The x8time() function */
static unsigned char x8time(unsigned char x)
{
	return (x2time(x2time(x2time(x))));
}
/*������9�˷� The x9time() function */
static unsigned char x9time(unsigned char x)	//9:1001
{
	return (x8time(x) ^ x);
}
/*������*B�˷� The xBtime() function */
static unsigned char xBtime(unsigned char x)	//B:1011
{
	return (x8time(x) ^ x2time(x) ^ x);
}
/*������*D�˷� The xDtime() function */
static unsigned char xDtime(unsigned char x)	//D:1101
{
	return (x8time(x) ^ x4time(x) ^ x);
}
/*������*E�˷� The xEtime() function */
static unsigned char xEtime(unsigned char x)	//E:1110
{
	return (x8time(x) ^ x4time(x) ^ x2time(x));
}

void mixColumn(unsigned char cipher[4][4])//mix the Column
{
	char temp[4] = { 0 };
	for (int j = 0; j < 4; j++)
	{
		temp[0] = x2time(cipher[0][j]) ^ x3time(cipher[1][j]) ^ cipher[2][j] ^ cipher[3][j];
		temp[1] = cipher[0][j] ^ x2time(cipher[1][j]) ^ x3time(cipher[2][j]) ^ cipher[3][j];
		temp[2] = cipher[0][j] ^ cipher[1][j] ^ x2time(cipher[2][j]) ^ x3time(cipher[3][j]);
		temp[3] = x3time(cipher[0][j]) ^ cipher[1][j] ^ cipher[2][j] ^ x2time(cipher[3][j]);
		for (int i = 0; i < 4; i++)cipher[i][j] = temp[i];
	}
}

void encrypt(unsigned char plaintext[4][4], unsigned char subkeys[4][44], unsigned char cipher[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cipher[i][j] = plaintext[i][j];
		}
	}
	Add_subkey(cipher, subkeys, 0);
	for (int i = 1; i <= 9; i++)//the wheel function
	{
		changebytes(cipher);
		shiftrows(cipher);
		mixColumn(cipher);
		Add_subkey(cipher, subkeys, i);
	}
	changebytes(cipher);
	shiftrows(cipher);
	Add_subkey(cipher, subkeys, 10);
}