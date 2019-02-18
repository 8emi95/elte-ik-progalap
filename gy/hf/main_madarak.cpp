#include <iostream>
#include <stdlib.h>

using namespace std;

const int maxmf = 20;

int main()
{
    int n = 5;
    int m; //madárfajok száma
    int adatok[5][maxmf];

    //beolvasás
    cin >> m;
    for(int i = 0; i < n; ++i) //helységek
    {
        for(int j = 0; j < m; ++j) //madárfajok száma az adott helységben
        {
            cin >> adatok[i][j];
        }
    }

    //az egyes helyeken hányféle madár fordult elõ
    int hanyfele[5]; //fajták darabszámát tartalmazza
    for(int i = 0; i < n; ++i)
    {
        int db = 0;
        for(int j = 0; j < m; ++j)
        {
            if(adatok[i][j] > 0)
            {
                db++;
            }
        }
        hanyfele[i] = db;
    }

    for(int i = 0; i < n; ++i)
    {
        cout << hanyfele[i] << " ";
    }
    cout << endl;

    //mely helyen fordult elõ valamely fajtából a legtöbb példány, hányadik fajta madárból
    string hely[5];
    hely[0]="Zirc";
    hely[1]="Szentendrei skanzen";
    hely[2]="Sas-hegy";
    hely[3]="Kis-Balaton";
    hely[4]="Margit-sziget";

    int max = 0;
    int h_i; //helység indexe
    int m_i; //madárfaj indexe

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(adatok[i][j] > max)
            {
                h_i = i; //a hely ahol a legtöbb van a madárfajból
                m_i = j+1; //a legtöbb példányú madárfaj indexe 1-tõl)
                max = adatok[i][j];
            }
        }
    }

    cout << hely[h_i] << " ";
    cout << m_i << endl;

    //zirc és szentendrei skanzen eltérési indexe
    int elteres = 0;
    for(int k = 0; k < m; ++k)
    {
        int ei = adatok[0][k] - adatok[1][k];
        if(ei < 0)
        {
            ei = ei*(-1);
        }
        elteres = elteres + ei;
    }
    cout << elteres << endl;

    //melyik két különbözõ helyszín eltérési indexe a legkisebb
    int ind1 = 0; //elsõ hely indexe
    int ind2 = 0; //második hely indexe
    int elteres2 = adatok[0][0]-adatok[1][0];
    if(elteres2 < 0)
    {
        elteres2 = elteres2*(-1);
    }

    for(int elso = 0; elso < n; ++elso)
    {
        for(int masodik = 0; masodik < n; ++masodik)
        {
            if(elso != masodik)
            {
                for(int i = 0; i < m; ++i)
                {
                    int ei2 = adatok[elso][i]-adatok[masodik][i];
                    if(ei2 < 0)
                    {
                        ei2 = ei2*(-1);
                    }
                    if(ei2 < elteres2)
                    {
                        elteres2 = ei2;
                        ind1 = elso;
                        ind2 = masodik;
                    }
                }
            }
        }
    }
    cout << hely[ind1] << "," << hely[ind2];

    return 0;
}
