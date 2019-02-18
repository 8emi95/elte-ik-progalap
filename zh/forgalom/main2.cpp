#include <iostream>

using namespace std;

const int MAXK = 50;
const int MAXN = 300;
const int MAXM = 1500;

typedef struct
{
    int nap;
    int uzlet;
    int termek;
} Jelentes;

typedef struct
{
    int kezdonap;
    int vegnap;
} Szakaszok;

void beolvas(int &K,int &N,int &M,Jelentes Jelentesek[MAXM])
{
    cin >> N >> K >> M;
    for(int i = 0; i < M ; i++)
    {
        cin >> Jelentesek[i].nap;
        cin >> Jelentesek[i].uzlet;
        cin >> Jelentesek[i].termek;
    }
}

int A_feladat(int &K,int &N,int &M,Jelentes Jelentesek[MAXM])
{
    int Max=0;
    for(int i=0; i<M; i++)
    {
        if(Jelentesek[i].termek>Jelentesek[Max].termek)
        {
            Max=i;
        }
    }
    return Jelentesek[Max].termek;
}

int B_feladat(int &K,int &N,int &M,Jelentes Jelentesek[MAXM])
{
    int ennyinap=1, j=0;
    for(int i=1; i<M; i++)
    {
        j=0;
        while(j<i && Jelentesek[i].nap!=Jelentesek[j].nap)
        {
            j++;
        }
        if(j==i)
        {
            ennyinap++;
        }
    }
    return ennyinap;
}

void C_feladat(int &K,int &N,int &M,Jelentes Jelentesek[MAXM])
{
    int uzletek[K];
    for(int i=0; i<K; i++)
    {
        uzletek[i]=0;
    }
    for(int i=0; i<M; i++)
    {
        uzletek[Jelentesek[i].uzlet-1]++;
    }
    int maxuzlet=0;
    for(int i=0; i<K; i++)
    {
        if(uzletek[i] > uzletek[maxuzlet])
        {
            maxuzlet=i;
        }
    }
    cout << maxuzlet+1 << " " << uzletek[maxuzlet];
}

void D_feladat(int &K,int &N,int &M,Jelentes Jelentesek[MAXM])
{
    int k=0, db=0, db2=0, szakaszok[N];
    Szakaszok szakasz2[N];
    int j=0;
    bool jo=true;
    for(int i=1; i <= N; i++)
    {
        j=0;
        while(j<M && Jelentesek[j].nap!=i)
        {
            j++;
        }
        if(j<M)
        {
            szakasz2[db2].kezdonap=i;
            k=i;
            jo=true;
            do
            {
                k++;
                j=0;
                while(j<M && Jelentesek[j].nap!=k)
                {
                    j++;
                }
                if(j==M)jo=false;
            }
            while(jo==true && k <= N);
            szakasz2[db2++].vegnap=k-1;
            szakaszok[db++]=k-i;
            i=k;
        }
    }
    int maxszakasz2=0;
    for(int i=0; i< db2; i++)
    {
        if(szakasz2[i].vegnap-szakasz2[i].kezdonap+1 > szakasz2[maxszakasz2].vegnap-szakasz2[maxszakasz2].kezdonap+1)
        {
            maxszakasz2=i;
        }
    }
    cout << szakasz2[maxszakasz2].kezdonap << " " << szakasz2[maxszakasz2].vegnap;
}

int main()
{
    Jelentes Jelentesek[MAXM];
    int K, M, N;
    beolvas(K,N,M,Jelentesek);
    cout << A_feladat(K,N,M,Jelentesek) << endl;
    cout << B_feladat(K,N,M,Jelentesek) << endl;
    C_feladat(K,N,M,Jelentesek);
    cout << endl;
    D_feladat(K,N,M,Jelentesek);
    cout << endl;
    return 0;
}
