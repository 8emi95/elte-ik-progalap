#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAXMF = 20;
const int N = 5;

void beolvas(int& mf, int m[N][MAXMF])
{
    cin >> mf;
    for (int i = 0; i < 5 ; i++){
        for(int j = 0; j < mf ; j++){
           cin >> m[i][j];
        }
    }
}

void A_feladat(int& mf, int m[N][MAXMF])
{
    int darab[MAXMF];
    int db=0;
    for (int i = 0; i < 5 ; i++){
        for(int j = 0; j < mf ; j++){
           if(m[i][j] != 0)
           {
               db++;
           }
        }
        darab[i] = db;
        db = 0;
    }
    for(int i = 0; i < 5; i++)
    {
        cout << darab[i]<< " ";
    }
}

void B_feladat(int mf, int m[N][MAXMF])
{
    const string varosok[N] = {"Zirc", "Szentendrei skanzen", "Sas-hegy","Kis-Balaton", "Margit-sziget"};
    int melyik[N];
    int legtobb = 0;
     for (int i = 0; i < 5 ; i++){
        legtobb = 0;
        for(int j = 0; j < mf ; j++){
                if (m[i][j] > m[i][legtobb])
                {
                    legtobb = j;
                }
        melyik[i] = legtobb;
        }
     }
     legtobb = 0;
     for (int i = 0; i < 5 ; i++)
     {
         if (m[i][melyik[i]] > m[legtobb][melyik[legtobb]])
         {
             legtobb = i;
         }
     }
     cout << varosok[legtobb] << " " << melyik[legtobb]+1;
}

int C_feladat (int mf, int m[N][MAXMF], int i, int j)
{
    int s = 0;
    for(int k = 0; k < mf; k++){
        s = s + abs(m[i][k]-m[j][k]);
    }
    return s;
}

void D_feladat(int mf, int m[N][MAXMF], int& mini ,int &minj)
{
    mini = 0;
    minj = 1;
    int minert = C_feladat(mf, m , 0, 1);
    for(int i = 0; i < 4 ; i++){
        for(int j = i+1; j < 5; j++)
        {
            if(C_feladat(mf,m,i,j)<minert)
            {
                mini = i;
                minj = j;
                minert = C_feladat(mf,m,i,j);
            }
        }
    }
}

int main()
{
    int mf;
    int m[N][MAXMF];
    const string varosok[N] = {"Zirc", "Szentendrei skanzen", "Sas-hegy","Kis-Balaton", "Margit-sziget"};

    beolvas(mf,m);

    //a
    A_feladat(mf,m);
    cout << endl;
    //b
    B_feladat(mf,m);
    cout << endl;
    //c
    cout << C_feladat(mf,m,0,1) << endl;
    //d
    int mini, minj;
    D_feladat(mf, m , mini, minj);
    cout <<varosok[mini] << "," << varosok[minj] << endl;
    return 0;
}
