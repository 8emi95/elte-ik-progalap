#include <iostream>

using namespace std;

int const MaxK = 100000;
int const MaxN = 1000;
int const MaxB = 100;
int const MaxL = 10;

struct Tankolas
{
    int T;
    int M;
};

void beolvas(int &K, int &N,int &B,int &L,Tankolas Tankolasok[MaxN])
{
    cin >> K;
    cin >> N;
    cin >> B;
    cin >> L;
    for (int i = 0; i < N; ++i)
    {
        cin >> Tankolasok[i].T;
        cin >> Tankolasok[i].M;
    }
}

double A_feladat(int const K, int const N,int const B,int const L,Tankolas Tankolasok[MaxN])
{
    int osszegzes = B;
    for (int i = 0; i < N; ++i)
    {
        osszegzes = osszegzes + Tankolasok[i].M;
    }
    double eredmeny;
    eredmeny = osszegzes - ((K / 100) * L);
    return eredmeny;
}

double B_feladat(int const K, int const N,int const B,int const L,Tankolas Tankolasok[MaxN])
{
    double maxbenzin = B - ((Tankolasok[0].T/100)*L) + Tankolasok[0].M;
    double aktual = B - ((Tankolasok[0].T/100)*L) + Tankolasok[0].M;
    for (int i = 1; i < N; ++i)
    {
        if(maxbenzin < (aktual - (((Tankolasok[i].T-Tankolasok[i-1].T)/100)*L)) + Tankolasok[i].M)
        {
            maxbenzin = (aktual - (((Tankolasok[i].T-Tankolasok[i-1].T)/100)*L)) + Tankolasok[i].M;
        }
        aktual = aktual - (((Tankolasok[i].T-Tankolasok[i-1].T)/100)*L) + Tankolasok[i].M;
    }
    if(maxbenzin > B)
    {
        return maxbenzin;
    }
    else
    {
        return B;
    }
}

int C_feladat(int const K, int const N,int const B,int const L,Tankolas Tankolasok[MaxN])
{
    double ossz = (K/100)*L;
    int i = 0;
    ossz = ossz - B;
    while (ossz >= 0 && i < N)
    {
        ossz = ossz - Tankolasok[i].M;
        ++i;
    }
    if(B >= (K/100)*L)
    {
        return 0;
    }
    else
    {
        return i;
    }
}




int main()
{
    Tankolas Tankolasok[MaxN];
    int K;
    int N;
    int B;
    int L;
    beolvas(K,N,B,L,Tankolasok);
    cout << A_feladat(K,N,B,L,Tankolasok) << endl;
    cout << B_feladat(K,N,B,L,Tankolasok) << endl;
    cout << C_feladat(K,N,B,L,Tankolasok) << endl;
    cout << endl;
    cout << endl;
    return 0;
}
