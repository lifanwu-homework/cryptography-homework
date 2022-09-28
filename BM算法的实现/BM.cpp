
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LFSR.h"



int main()
{
    LFSR a;
    int seq[]={0,0,1,0,1,1,0,1};
    a.BM(seq,8);
    printf("L:%d\n",a.L);
    a.print();
}


