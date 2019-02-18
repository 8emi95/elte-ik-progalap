#include <iostream>

using namespace std;

const int MAXN = 1000;

typedef struct
{
    int kezdo;
    int vegzo;
} dfeladat;

void beolvas(int &N,int orhely[MAXN])
{
    cin >> N;
    for(int i = 0; i < N ; i++)
    {
        cin >> orhely[i];
    }
}

int A_feladat(int &N, int orhely[MAXN])
{
    int orzottek=0;
    for(int i=0; i<N-1; i++)
    {
        if(orhely[i]>0 || orhely[i+1]>0)
        {
            orzottek++;
        }
    }
    return orzottek;
}

int B_feladat(int &N, int orhely[MAXN],int szakaszok[MAXN])
{

    for(int i=1; i<N; i++)
    {
        szakaszok[i]=0;
        if(orhely[i-1]>0 || orhely[i]>0)szakaszok[i-1]=1;
        if(orhely[i-1]>0 && orhely[i]>0)szakaszok[i-1]=2;
    }
    int kellmeg=0;
    for(int i=0; i<N-1; i++)
    {
        if(szakaszok[i]==0)
        {
            kellmeg++;
            i++;
        }
    }
    return kellmeg;
}

int C_feladat(int &N, int orhely[MAXN],int szakaszok[MAXN])
{
    int cfeladat=0;
    while(cfeladat<N-1 && szakaszok[cfeladat]!=0)
    {
        cfeladat++;
    }
    if(cfeladat==N-1)cfeladat=0;
    return cfeladat+1;
}

void D_feladat(int &N, int orhely[MAXN],int szakaszok[MAXN])
{
    int j=0;
    dfeladat vedett_sorok[N];
    int db=0;
    for(int i=0; i<N-1; i++)
    {
        if(szakaszok[i]==2)
        {
            vedett_sorok[db].kezdo=i+1;
            j=i+1;
            while(j<N-1 && szakaszok[j]==2)
            {
                j++;
            }
            vedett_sorok[db++].vegzo=j+1;
            i=j;
        }
    }

    int maxdb=0;

    for(int i=0; i<db; i++)
    {
        if(vedett_sorok[i].vegzo-vedett_sorok[i].kezdo > vedett_sorok[maxdb].vegzo-vedett_sorok[maxdb].kezdo)
        {
            maxdb=i;
        }
    }
    cout << vedett_sorok[maxdb].kezdo << " " << vedett_sorok[maxdb].vegzo;
}

int main()
{
    int N;
    int orhely[MAXN];
    int szakaszok[MAXN];
    beolvas(N,orhely);
    cout << A_feladat(N, orhely) << endl;
    cout << B_feladat(N, orhely,szakaszok) << endl;
    cout << C_feladat(N, orhely,szakaszok) << endl;
    D_feladat(N, orhely,szakaszok);
    cout << endl;
    return 0;
}
