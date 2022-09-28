#pragma once


void extend_replace(char R[32], char R1[48])
{
	char* E_ = (char*)E;
	for (int i = 0; i < 48; i++)
	{
		R1[i] = R[E_[i] - 1];
	}
}

void XOR(char A[], const char B[], int length)
{
	for (int i = 0; i < length; i++)
	{
		A[i] ^= B[i];
	}
}

void S_exchange(const char A[6], char B[4], const char S_box[65])
{
	int pos = 32 * A[0] + 16 * A[5] + 8 * A[1] + 4 * A[2] + 2 * A[3] + A[4];
	int ans = S_box[pos];
	B[0] = (ans & 0x8) >> 3;
	B[1] = (ans & 0x4) >> 2;
	B[2] = (ans & 0x2) >> 1;
	B[3] = (ans & 0x1);
}

void S_box(char R1[48], char ans_R[32])
{
	for (int i = 0; i < 8; i++)
	{
		S_exchange(R1 + 6 * i, ans_R + 4 * i, S_Box[i]);
	}
}

void wheel_function(char L[32], char R[32], char key[48])
{
	char ans_L[32] = { 0 }, ans_R[32] = { 0 }, R1[48] = { 0 };
	for (int i = 0; i < 32; i++)ans_L[i] = R[i];
	extend_replace(R, R1);
	XOR(R1, key, 48);
	S_box(R1, ans_R);
	scramble(ans_R, (char*)P, 32);
	XOR(ans_R, L, 32);
	for (int i = 0; i < 32; i++) {
		L[i] = ans_L[i];
		R[i] = ans_R[i];
	}
}
