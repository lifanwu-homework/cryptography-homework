
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LFSR.h"

void fileload(int seq[MAX_LENGTH],int length)
{
    FILE *fp_cipher=fopen("cipher.txt","rb");
    unsigned char temp[MAX_LENGTH]={0};
    fread(temp,sizeof(unsigned char),length/8+1,fp_cipher);
    memset(seq,0,sizeof(MAX_LENGTH));
    for(int i=0;i<length;i++)
    {
        seq[i]=(temp[i/8]&(1<<(i%8)))?1:0;
    }
}

int main()
{
    int length=160000;//length of all the bit
    LFSR a;
    int seq[MAX_LENGTH]={0};//store the sequence,one bit for a integer
    fileload(seq,length);
    a.BM(seq,length);//计算线性反馈移位寄存器
	// for(int i=0;i<length;i++)
    // {
    //     printf("%d ",seq[i]);
    // }
    printf("length:%d\nL:%d\n",length,a.L);
    //a.print();
}


