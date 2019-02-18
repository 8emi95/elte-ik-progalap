#include <iostream>

using namespace std;

const int MAXC = 1000;
const int MAXK = 100;

typedef struct
{
    int ceg;
    int dolgozo;
    int ev;
    int nem;
} Kozvetitesek;

void beolvas(int &C, int &K,Kozvetitesek kozv[MAXK])
{
    cin >> C >> K;
    for(int i = 0 ; i < K ; i++)
    {
        cin >> kozv[i].ceg;
        cin >> kozv[i].dolgozo;
        cin >> kozv[i].ev;
        cin >> kozv[i].nem;
    }
}

void A_feladat(int &C, int &K,Kozvetitesek kozv[MAXK])
{
    int holgyek=0, urak=0;
    for(int i=0; i < K; i++)
    {
        if(kozv[i].nem==0)
        {
            holgyek++;
        }
        if(kozv[i].nem==1)
        {
            urak++;
        }
    }
    cout << holgyek << " " << urak;
}

int B_feladat(int &C, int &K,Kozvetitesek kozv[MAXK])
{
    int cegek=1, j=0;
    for(int i=1; i < K; i++)
    {
        j=0;
        while(kozv[i].ceg!=kozv[j].ceg && j < i)
        {
            j++;
        }
        if(j>=i)
        {
            cegek++;
        }
    }
    return cegek;
}

void C_feladat(int &C, int &K,Kozvetitesek kozv[MAXK])
{
    int ceg[C];
    for(int i=0; i < C; i++)
    {
        ceg[i]=0;
        for(int j=0; j < K; j++)
        {
            if (kozv[j].ceg==i+1)
            {
                ceg[i]++;
            }
        }
    }
    for(int i=0; i < C; i++)
    {
        cout << ceg[i] << " ";
    }
}

void D_feladat(int &C, int &K,Kozvetitesek kozv[MAXK])
{
    Kozvetitesek kozvetites2[MAXK];
    for(int i = 0; i < K; i++)
    {
        kozvetites2[i].ceg = kozv[i].ceg;
        kozvetites2[i].dolgozo = kozv[i].dolgozo;
        kozvetites2[i].ev = kozv[i].ev;
        kozvetites2[i].nem = kozv[i].nem;
    }
    for(int i = 0; i < K-1; i++)
    {
        for(int j = 0; j < K-1; j++)
        {
            if(kozvetites2[j].ev > kozvetites2[j+1].ev)
            {
                Kozvetitesek seged;
                seged.ceg = kozvetites2[j].ceg;
                seged.dolgozo = kozvetites2[j].dolgozo;
                seged.ev = kozvetites2[j].ev;
                seged.nem = kozvetites2[j].nem;

                kozvetites2[j].ceg = kozvetites2[j+1].ceg;
                kozvetites2[j].dolgozo = kozvetites2[j+1].dolgozo;
                kozvetites2[j].ev = kozvetites2[j+1].ev;
                kozvetites2[j].nem = kozvetites2[j+1].nem;

                kozvetites2[j+1].ceg = seged.ceg;
                kozvetites2[j+1].dolgozo = seged.dolgozo;
                kozvetites2[j+1].ev = seged.ev;
                kozvetites2[j+1].nem = seged.nem;
            }
            if(kozvetites2[j].ev == kozvetites2[j+1].ev && kozvetites2[j].nem == 1 && kozvetites2[j+1].nem == 0)
            {
                Kozvetitesek seged;
                seged.ceg = kozvetites2[j].ceg;
                seged.dolgozo = kozvetites2[j].dolgozo;
                seged.ev = kozvetites2[j].ev;
                seged.nem = kozvetites2[j].nem;

                kozvetites2[j].ceg = kozvetites2[j+1].ceg;
                kozvetites2[j].dolgozo = kozvetites2[j+1].dolgozo;
                kozvetites2[j].ev = kozvetites2[j+1].ev;
                kozvetites2[j].nem = kozvetites2[j+1].nem;

                kozvetites2[j+1].ceg = seged.ceg;
                kozvetites2[j+1].dolgozo = seged.dolgozo;
                kozvetites2[j+1].ev = seged.ev;
                kozvetites2[j+1].nem = seged.nem;
            }
        }
    }
    for(int i = 0; i < K; i++)
    {
        cout << kozvetites2[i].dolgozo << " ";
    }
    cout << endl;
}

int main()
{
    Kozvetitesek kozv[MAXK];
    int C, K;
    beolvas(C,K,kozv);
    A_feladat(C,K,kozv);
    cout << endl;
    cout << B_feladat(C,K,kozv) << endl;
    C_feladat(C,K,kozv);
    cout << endl;
    D_feladat(C,K,kozv);
    cout << endl;
    return 0;
}
