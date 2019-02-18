#include <iostream>
#include <cstdlib>
#define maxMF 20


using namespace std;

const string nevek[5]={"Zirc", "Szentendrei skanzen", "Sas-hegy", "Kis-Balaton", "Margit-sziget"};

void A_fel(const int T[5][maxMF], const int N);
void B_fel(const int T[5][maxMF], const int N);

int eltInd(const int T[5][maxMF], const int N, const int a, const int b);
void D_fel_max(const int T[5][maxMF], const int N);

int main()
{
    int MF;
    cin >> MF;

    int T[5][maxMF];

    for (int i=0; i<5; i++)
    {
        for (int j=0; j<MF; j++)
        {
            cin >> T[i][j];
        }
    }


    //---kiir
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<MF; j++)
        {
            clog << T[i][j]<< " " ;
        }
        clog << endl;
    }

    A_fel(T, MF);
   B_fel(T, MF);
   cout << eltInd(T, MF, 0, 1)<< endl;
    D_fel_max(T, MF);



    return 0;
}
void A_fel(const int T[5][maxMF], const int N)
{
    int s;

    for(int i=0; i<5;i++)
    {
        s=0;
        for (int j=0; j<N; j++)
        {
            if (T[i][j]!=0) s++;
        }
        cout << s<< " ";
    }

    cout << endl;
}
void B_fel(const int T[5][maxMF], const int N)
{
    int indi=0, indj=0;

int k;
    for (int i=0; i<5; i++)
    {
        if (i==0)k=1; else k=0;
        for (int j=k; j<N; j++)
        {
            if (T[i][j]>T[indi][indj])
            {
                indi=i;indj=j;
            }
        }
    }
    cout << nevek[indi]<< " "<< indj+1<< endl;
}
int eltInd(const int T[5][maxMF], const int N, const int a, const int b)
{
    int s=0;
    int tmp;
    for (int i=0; i<N; i++)
    {
        tmp= T[a][i]-T[b][i];
        s += abs(tmp);
    }

    return s;


}
void D_fel_max(const int T[5][maxMF], const int N)
{
    int indi=0, indj=1;



    for (int i=0; i<5; i++)
    {
        for (int j=i+1; j<5; j++)
        {
            if (eltInd(T, N, i, j)< eltInd(T, N, indi, indj))
            {
                indi=i; indj=j;
            }
        }

    }
    cout << nevek[indi]<< ","<<nevek[indj];


}


