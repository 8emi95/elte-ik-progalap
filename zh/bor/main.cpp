#include <iostream>

using namespace std;

const int MAXN = 100;

typedef struct
{
    int mennyiseg;
    int ar;
}bor;

void beolvas(int &N, bor borok[MAXN])
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> borok[i].mennyiseg;
        cin >> borok[i].ar;
    }
}

int A_feladat(const int &N, bor borok[MAXN])
{
    int legkevesebb = 0;
    for(int i = 1 ; i < N ; i++)
    {
        if(borok[i].mennyiseg < borok[legkevesebb].mennyiseg)
        {
            legkevesebb = i;
        }
    }
    return legkevesebb+1;
}

int B_feladat(const int &N , bor borok[MAXN])
{
    int legdragabb = 0;
	bool log = false;
    for(int i = 0; i < N; i++)
    {
		if(borok[i].mennyiseg > 1000)
		{
			if(log)
			{
				if(borok[i].mennyiseg > 1000 && borok[i].ar > borok[legdragabb].ar)
				{
					legdragabb = i;
				}
			}
			else
			{
				legdragabb = i;
				log = true;
			}
		}
    }
    if(borok[legdragabb].mennyiseg < 1000)
    {
        legdragabb = -1;
    }
    else
    {
        legdragabb = borok[legdragabb].ar;
    }
    return legdragabb;
}

int C_feladat(const int &N, bor borok[MAXN])
{
    int hanyfele = 1;
    for(int i = 1, j = 0; i < N;i++)
    {
        while(j < i && borok[i].ar != borok[j].ar)
        {
            j++;
        };
        if(i==j)
        {
            hanyfele++;
        }
        j = 0;
    }
    return hanyfele;
}

void D_feladat(const int &N, bor borok[MAXN])
{
    int szamuk[MAXN];
    int szamdb=0;
    for(int i = 1,j = 0; i < N; i++)
    {
        while(j < i && borok[j].mennyiseg < borok[i].mennyiseg)
        {
            j++;
        };
        if(j==i)
        {
            szamuk[szamdb]=i+1;
            szamdb++;
        }
        j = 0;
    }
    cout << szamdb << " ";
    for(int i = 0; i < szamdb ; i++)
    {
        cout << szamuk[i] <<" ";
    }
}


int main()
{
    bor borok[MAXN];
    int N;
    beolvas(N, borok);
    cout << A_feladat(N, borok) << endl;
    cout << B_feladat(N, borok) << endl;
    cout << C_feladat(N, borok) << endl;
    D_feladat(N, borok);
    return 0;
}
