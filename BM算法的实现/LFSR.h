#define MAX_LENGTH 1000

class LFSR
{
public:
    int L;
    int C[MAX_LENGTH], S[MAX_LENGTH];

public:
    LFSR(/* args */);
    ~LFSR();
    void init_LFSR(int L, int C[], int S[]);
    void print();
    int LFSR_next();
    int distance(int input);
    void BM(int sequence[],int length);

};

LFSR::LFSR(/* args */)
{
    memset(this->C, 0, sizeof(this->C));
    memset(this->S, 0, sizeof(this->S));
}

LFSR::~LFSR()
{
}

void LFSR::init_LFSR(int L, int C[], int S[])
{
    this->L = L;
    for (int i = 0; i < L; i++)
    {
        this->C[i] = C[i];
        this->S[i] = S[i];
    }
}

void LFSR::print()
{
    for (int i = 0; i < L+1; i++)
    {
        printf("%d ",this->C[i]);
    }
    printf("\n");
    // for (int i = 0; i < L; i++)
    // {
    //     printf("%d ",this->S[i]);
    // }
    // printf("\n");
}

int LFSR::LFSR_next() //注意这里的S是一个逆序数组，S[0]=sL-1,S[L-1]=s0=输出,C[0]=1,C[1]=C1,C[]长度为L+1
{
    int sj = 0, out;
    for (int i = 0; i < L; i++)
    {
        sj += C[i+1] * S[i];
    }
    out = S[L - 1];

    for (int i = L - 2; i >= 0; i--)
    {
        S[i + 1] = S[i];
    }
    S[0] = sj % 2;
    return out;
}

int LFSR::distance(int input)
{
    return (input+this->LFSR_next())%2;
}

void LFSR::BM(int sequence[],int length)
{
    int B[MAX_LENGTH],T[MAX_LENGTH];
    memset(B,0,sizeof(B));
    memset(T,0,sizeof(T));
    memset(C,0,sizeof(C));
    memset(S,0,sizeof(S));
    L=0;
    C[0]=1;
    B[0]=1;
    int m=0;
    int j=0;
    int d=0;
    for(int i=0;i<length;i++)
    {
        
        d=sequence[i];
        for(int j=1;j<L+1;j++)
        {
            d^=sequence[i-j]*C[j];
        }
        m++;
        
        if(d==0);
        else{
            
            for (int j = 0; j < MAX_LENGTH; j++)
            {
                T[j]=C[j];
            }
            for (int j = 0; j < MAX_LENGTH; j++)
            {
                if(j-m<0);
                else C[j]^=B[j-m];
            }
            if(2*L<=i){
                L=i+1-L;
                for (int j = 0; j < MAX_LENGTH; j++)
                {
                    B[j]=T[j];
                }
                m=0;
            }
        }
        // printf("\n%d %d %d %d\n",i,L,d,m);
        // for (int j = 0; j < L+1; j++)
        // {
        //     printf("%d ",T[j]);
        // }
        // printf("\n");
        // this->print();
        // for (int j = 0; j < L+1; j++)
        // {
        //     printf("%d ",B[j]);
        // }
        // printf("\n");
    }
}
