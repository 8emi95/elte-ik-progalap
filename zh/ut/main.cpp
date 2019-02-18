#include <iostream>

using namespace std;

const int MAXM = 200;
const int MAXN = 1000;

typedef struct
{
    int K;
    int V;
} Felujitasok;

void beolvas(int &N,int &M, Felujitasok feluj[MAXM])
{
    cin >> N;
    cin >> M;
    for(int i = 0; i < M ; i++)
    {
        cin >> feluj[i].K;
        cin >> feluj[i].V;
    }
}

int A_feladat(int &N,int &M, Felujitasok feluj[MAXM])
{
    int legrovidebb = 0;
    for(int i = 0; i < M; i++)
    {
        if(feluj[i].V-feluj[i].K < feluj[legrovidebb].V-feluj[legrovidebb].K)
        {
            legrovidebb=i;
        }
    }
    return feluj[legrovidebb].V-feluj[legrovidebb].K;
}

int B_feladat(int &N,int &M, Felujitasok feluj[MAXM])
{
    int kmszelvenyek[N], van=-2;
    for(int i=1; i <= N; i++)
    {
        kmszelvenyek[i-1]=0;
        for(int j=0; j < M; j++)
        {
            if(i >= feluj[j].K && i <= feluj[j].V)
            {
                kmszelvenyek[i-1]++;
            }
        }
    }
    for(int i=N-1; i >= 0; i--)
    {
        if(kmszelvenyek[i]>=3)van=i;
    }
    return van+1;
}

int C_feladat(int &N,int &M, Felujitasok feluj[MAXM],int felujitatlan_szakaszok[MAXN])
{
    for(int i=0; i<=N; i++)
    {
        felujitatlan_szakaszok[i]=0;
        for(int j=0; j<M; j++)
        {
            if(feluj[j].K <= i && feluj[j].V >= i)
            {
                felujitatlan_szakaszok[i]++;
            }
        }
    }
    int kellmeg=0;
    for(int i=0; i <= N; i++)
    {
        if(felujitatlan_szakaszok[i]==0)
        {
            kellmeg++;
        }
    }
    return kellmeg;
}

int D_feladat(int &N,int &M, Felujitasok feluj[MAXM],int felujitatlan_szakaszok[MAXN])
{
    int szakaszok[N], db=0, j=0;
    j=0;
    for(int i=0; i<=N; i++)
    {
        if(felujitatlan_szakaszok[i]==0)
        {
            j=i;
            do
            {
                j++;
            }
            while(felujitatlan_szakaszok[j]==0 && j<=N);
            szakaszok[db++]=j-i;
            i=j;
        }
    }
    int maxszakasz=0;
    for(int i=0; i < db; i++)
    {
        if(szakaszok[i]>szakaszok[maxszakasz])
        {
            maxszakasz=i;
        }
    }
    return szakaszok[maxszakasz];
}

int main()
{
    Felujitasok feluj[MAXM];
    int N, M;
    int felujitatlan_szakaszok[MAXN];
    beolvas(N,M,feluj);
    cout << A_feladat(N,M,feluj) <<endl;
    cout << B_feladat(N,M,feluj) << endl;
    cout << C_feladat(N,M,feluj,felujitatlan_szakaszok) << endl;
    cout << D_feladat(N,M,feluj,felujitatlan_szakaszok) <<endl;
    return 0;
}
