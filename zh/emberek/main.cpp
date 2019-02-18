#include <iostream>

using namespace std;

const int MAXN = 100;

struct ember
{
    int kor;
    int fizu;
};

void beolvas(int &N, ember emberek[MAXN])
{
    cin >> N;
    for (int i = 0; i < N ; i++)
    {
        cin >> emberek[i].kor;
        cin >> emberek[i].fizu;
    }
}

int A_feladat(const int &N, ember emberek[MAXN])
{
    int legidosebb = 0;
    for(int i = 1; i < N ; i++)
    {
        if (emberek[i].kor > emberek[legidosebb].kor)
        {
            legidosebb = i;
        }
    }
    return legidosebb+1;
}
int B_feladat(const int &N, ember emberek[MAXN])
{
    int db = 0;
    for (int i = 0; i < N ; i++)
    {
        if(emberek[i].kor > 40 && emberek[i].fizu < 200000)
        {
            db++;
        }
    }
    return db;
}
int C_feladat(const int &N, ember emberek[MAXN])
{
    int hanyfele=1;
    for(int i=1, j=0; i<N; i++)
    {
        while(j<i && emberek[i].kor!=emberek[j].kor)
        {
            j++;
        };
        if(j==i)
        {
            hanyfele++;
        }
        j=0;
    }
    return hanyfele;
}
void D_feladat(const int &N, ember emberek[MAXN])
{
    int szam=0, sorsz[N];
    for(int i=0; i<N; i++)
    {
        if(emberek[i].kor<30)
        {
            sorsz[szam++]=i+1;
        }
    }
    cout<<szam<<" "; for(int i=0; i<szam; i++) cout<<sorsz[i]<<" ";
}

int main()
{
    ember emberek[MAXN];
    int N;

    beolvas(N, emberek);
    cout << A_feladat(N, emberek) << endl;
    cout << B_feladat(N, emberek) << endl;
    cout << C_feladat(N, emberek) << endl;
    D_feladat(N,emberek);
}
