#include <iostream>

using namespace std;

const int MAXN = 100;

typedef struct
{
    int honap;
    int nap;
    int szuletes;
} szuletesek;

void beolvas(int &N, szuletesek napok[MAXN])
{
    cin >> N;
    for(int i = 0; i < N ; i++)
    {
        cin >> napok[i].honap;
        cin >> napok[i].nap;
        cin >> napok[i].szuletes;
    }
}

int A_feladat(int &N, szuletesek napok[MAXN])
{
    int osszesen=0;
    for(int i=0; i<N; i++)
    {
        osszesen+=napok[i].szuletes;
    }
    return osszesen;
}

void B_feladat(int &N , szuletesek napok[MAXN])
{
    int novekedesek[N-1];
    for(int i=0; i<N-1; i++)
    {
        novekedesek[i]=napok[i+1].szuletes-napok[i].szuletes;
    }
    int maxnov=0;

    for(int i=0; i<N-1; i++)
    {
        if(novekedesek[i]>=novekedesek[maxnov])
        {
            maxnov=i;
        }
    }
    if(novekedesek[maxnov] <= 0 )
    {
        cout << "0";
    }
    else
    {
        cout << napok[maxnov+1].honap << " " << napok[maxnov+1].nap;
    }
}

void C_feladat(int &N, szuletesek napok[MAXN])
{
    int j=0, g=0;
    bool volt=true;
    do
    {
        j++;
        g=0;
        while(g<N && j!=napok[g].honap)
        {
            g++;
        }
        if(g==N)volt=false;
    }
    while(j<=12 && volt==true);
    if(j>12)
    {
        cout << "NEM";
    }
    else
    {
        cout << "IGEN" << " " << j;
    }
}

void D_feladat(int &N , szuletesek napok[MAXN])
{
    int darab = 0;
    int i=0;
    int j=0;
    int z=0;
    while(i < N)
    {
        j = i+1;
        z = i;
        while(j < N && napok[j].szuletes > napok[z].szuletes)
        {
            j++;
            z++;
        };
        if(i != z)
        {
            darab++;
        }
        i = j;
    }
    cout << darab << " ";
    i=0;
    j=0;
    z=0;
    while (i < N)
    {
        j = i+1;
        z = i;
        while(j < N && napok[j].szuletes > napok[z].szuletes)
        {
            j++;
            z++;
        };
        if(i != z)
        {
            cout << napok[i].honap << " ";
            cout << napok[i].nap << " ";
            cout << napok[z].honap << " ";
            cout << napok[z].nap << " ";
        }
        i = j;
    }
}

int main()
{
    szuletesek napok[MAXN];
    int N;
    beolvas(N,napok);
    cout << A_feladat(N,napok) << endl;
    B_feladat(N,napok);
    cout << endl;
    C_feladat(N,napok);
    cout << endl;
    D_feladat(N,napok);
    cout << endl;
    return 0;
}
