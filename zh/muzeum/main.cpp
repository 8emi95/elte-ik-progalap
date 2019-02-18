#include <iostream>

using namespace std;

const int MAXN = 1000;
const int MAXM = 1000;

typedef struct
{
    int mettol;
    int meddig;
} Or;

void beolvas(int &N,int &M, Or orok[MAXN])
{
    cin >> M >> N;
    for (int i = 0 ; i < N ; i++)
    {
        cin >> orok[i].mettol;
        cin >> orok[i].meddig;
    }
}

int A_feladat(int &N,int &M,Or orok[MAXN])
{
    int maxn = 0, maxnap = 0;
    for(int i=0; i<N; i++)
    {
        if( (orok[i].meddig-orok[i].mettol+1) > (orok[maxn].meddig-orok[maxn].mettol+1) )
        {
            maxn=i;
        }
    }
    maxnap = (orok[maxn].meddig-orok[maxn].mettol+1);
    return maxnap;
}

void B_feladat(int &N, int &M, Or orok[MAXN],int napok[MAXM])
{
    for(int i=0; i < M; i++)
    {
        napok[i]=0;
        for(int j=0; j < N; j++)
        {
            if(i+1 >= orok[j].mettol && i+1 <= orok[j].meddig)
            {
                napok[i]++;
            }
        }
    }
    for (int i=0; i < M ; i++)
    {
        cout << napok[i] << " ";
    }
}

int C_feladat(int &N, int &M, Or orok[MAXN],int napok[MAXM])
{
    int maxor = 0;
    for(int i = 1; i < M; i++)
    {
        if(napok[i] > napok[maxor])
        {
            maxor=i;
        }
    }
    return maxor+1;
}

void D_feladat(int &N,int &M, Or orok[MAXN],int napok[MAXM])
{
    int sorozatok[M], j=0;
    for(int i=0; i < M; i++)
    {
        sorozatok[i]=0;
        if(napok[i] < 2)
        {
            j=i;
            do
            {
                sorozatok[i]++;
                j++;
            }
            while(napok[j]<=1 && j < M);
        }
    }
    int maxsor=0;
    for(int i=0; i < M; i++)
    {
        if(sorozatok[i] > sorozatok[maxsor])
        {
            maxsor=i;
        }
    }
    if(sorozatok[maxsor]==0)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << maxsor+1 << " " << maxsor+sorozatok[maxsor] << endl;
    }
}

int main()
{
    Or orok[MAXN];
    int napok[MAXM];
    int N,M;
    beolvas(N,M,orok);
    cout << A_feladat(N,M,orok) <<endl ;
    B_feladat(N,M,orok,napok);
    cout << endl;
    cout << C_feladat(N,M,orok,napok) << endl;
    D_feladat(N,M,orok,napok);
    return 0;
}
