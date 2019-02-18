#include <iostream>

using namespace std;

const int MAXN = 100;

typedef struct
{
    int tavolsag;
    int ar;
} ut;

void beolvas(int &N, ut utazas[MAXN])
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> utazas[i].tavolsag;
        cin >> utazas[i].ar;
    }
}

int A_feladat(int &N, ut utazas[MAXN])
{
    int legtavolabb = 0;
    for (int i = 1; i < N ; i++)
    {
        if (utazas[i].tavolsag > utazas[legtavolabb].tavolsag)
        {
            legtavolabb = i;
        }
    }
    return legtavolabb+1;
}

int B_feladat (const int &N, ut utazas[MAXN])
{
    int legdragabb = 0;
	bool log = false;
    for(int i = 0; i < N; i++)
    {
		if(utazas[i].tavolsag<1000)
		{
			if(log)
			{
				if(utazas[i].ar >= utazas[legdragabb].ar)
				{
					legdragabb=i;
				}
			}
			else
			{
				legdragabb=i;
				log = true;
			}
		}
    }
    if(utazas[legdragabb].tavolsag>=1000)
    {
        legdragabb=-1;
    }
    else
    {
        legdragabb = utazas[legdragabb].ar;
    }
    return legdragabb;
}

int C_feladat(const int &N, ut utazas[MAXN])
{
    int hanyfele = 0;
    bool vane=false;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0 ; j < N; j++)
        {
            if (j!=i && utazas[j].ar == utazas[i].ar)
            {
                vane = true;
            }
        }
        if(vane==false)
        {
            hanyfele++;
        }
        vane=false;
    }
    return hanyfele;
}

void D_feladat(const int &N, ut utazas[MAXN])
{
    int szamuk[MAXN];
    int szamdb = 0;
    for(int i = 0; i < N; i++)
    {
        if(utazas[i].ar/utazas[i].tavolsag >= 100)
        {
            szamuk[szamdb] = i+1;
            szamdb++;
        }
    }
    cout << szamdb <<" ";
    for (int i = 0; i < szamdb ; i++)
    {
        cout << szamuk[i] << " ";
    }
}

int main()
{
    ut utazas[MAXN];
    int N;
    beolvas(N, utazas);
    cout << A_feladat(N,utazas) <<endl;
    cout << B_feladat(N, utazas) << endl;
    cout << C_feladat(N, utazas) << endl;
    D_feladat(N, utazas);
    return 0;
}
