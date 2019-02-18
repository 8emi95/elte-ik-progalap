#include <iostream>

using namespace std;

const int MAXN = 100;

typedef struct
{
    int alap;
    int ar;
}lakas;

void beolvas(int &N, lakas lakasok[MAXN])
{
    cin >> N;
    for (int i = 0; i < N ; i++)
    {
        cin >> lakasok[i].alap;
        cin >> lakasok[i].ar;
    }
}

int A_feladat (int &N, lakas lakasok[MAXN])
{
    int legdragabb = 0;
    for(int i = 1; i < N; i++)
    {
        if(lakasok[i].ar > lakasok[legdragabb].ar)
        {
            legdragabb = i;
        }
    }
    return legdragabb+1;
}

int B_feladat (int &N, lakas lakasok[MAXN])
{
    int db = 0;
    for (int i = 0; i < N ; i++)
    {
        if (lakasok[i].alap > 100 && lakasok[i].ar < 40)
        {
            db++;
        }
    }
    return db;
}

int C_feladat(int &N, lakas lakasok[MAXN])
{
    int hanyfele=1;
    for (int i = 1, j = 0; i < N ; i++)
    {
        while(j < i && lakasok[i].alap != lakasok[j].alap)
        {
            j++;
        };
        if (j==i)
        {
            hanyfele++;
        }
        j=0;
    }
    return hanyfele;
}

void D_feladat(int &N, lakas lakasok[MAXN])
{
    int szama[N];
    int szamdb = 0;
    for(int i = 0; i < N; i++)
    {
        if(lakasok[i].ar > 100)
        {
            szama[szamdb] = i+1;
            szamdb++;
        }
    }
    cout << szamdb << " ";
    for(int i = 0; i < szamdb; i++)
    {
        cout << szama[i] << " ";
    }
}

int main()
{
    lakas lakasok[MAXN];
    int N;
    beolvas(N, lakasok);
    cout << A_feladat(N, lakasok) << endl;
    cout << B_feladat(N, lakasok) << endl;
    cout << C_feladat(N, lakasok) << endl;
    D_feladat(N, lakasok);
    return 0;
}
