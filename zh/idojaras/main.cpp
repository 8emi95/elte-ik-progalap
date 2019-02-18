#include <iostream>

using namespace std;

const int MAXN = 100;

struct homerseklet
{
    int minh;
    int maxh;
} ;

void beolvas (int &N, homerseklet Napok[MAXN])
{
    cin >> N;
    for(int i = 0; i<N; i++)
    {
        cin >> Napok[i].minh;
        cin >> Napok[i].maxh;
    }
}
int A_feladat (int &N, homerseklet Napok[MAXN])
{
    int db = 0;
    for (int i = 0; i < N; i++)
    {
        if(Napok[i].minh <= 0)
        {
            db++;
        }
    }
    return db;
}
int B_feladat (int &N, homerseklet Napok[MAXN])
{
    int nap = 0;
    for (int i = 1; i < N; i++)
    {
        if(Napok[nap].maxh-Napok[nap].minh < Napok[i].maxh-Napok[i].minh)
        {
            nap = i;
        }
    }
    return nap+1;
}
int C_feladat (int &N, homerseklet Napok[MAXN])
{
    int var = -2;
    for(int i = 1; i < N ; i++)
        if(Napok[i].maxh < Napok[i-1].minh)
        {
            var=i;
            break;
        }
    return var+1;
}
void D_feladat (int &N, homerseklet Napok[MAXN])
{
    int olv[MAXN];
    int dbolv = 0;
    for (int i=0; i < N ; i++)
    {
        if(Napok[i].minh <= 0 && Napok[i].maxh > 0)
        {
            olv[dbolv] = i+1;
            dbolv++;
        }
    }
    cout << dbolv << " ";
    for (int i=0; i < dbolv; i++)
    {
        cout << olv[i] << " ";
    }
}


int main()
{
    homerseklet Napok[MAXN];
    int N;
    int db = 0;
    beolvas(N, Napok);
    cout << A_feladat(N, Napok) << endl;
    cout << B_feladat(N, Napok) <<endl;
    cout << C_feladat(N, Napok)<<endl;
    D_feladat(N, Napok);
    return 0;
}
