#include <iostream>

using namespace std;

const int maxN = 100;
struct utazas
{
    int tav;
    int ar;
};

int main()
{
    utazas ut[maxN];

    //beolvas�s
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> ut[i].tav >> ut[i].ar;
    }

    //a) legt�volabbi v�ros sorsz�ma (t�bb -> legkisebb sorsz�m�)
    int legtavolabbi = 0;
    for (int i = 1; i < n; ++i)
    {
        if (ut[i].tav > ut[legtavolabbi].tav)
        {
            legtavolabbi = i;
        }
    }
    cout << legtavolabbi + 1 << endl;

    //b) 1000 km-n�l k�zelebbiek k�z�l a legdr�g�bb
    int legdragabb = 0;
    bool ezer = false;
    for (int i = 0; i < n; ++i)
    {
        if (ut[i].tav < 1000)
        {
            if (ezer)
            {
                if (ut[i].ar > ut[legdragabb].ar)
                {
                    legdragabb = i;
                }
            }
            else
            {
                legdragabb = i;
                ezer = true;
            }
        }
    }
    if (ut[legdragabb].tav >= 1000)
    {
        legdragabb = -1;
    }
    else
    {
        legdragabb = ut[legdragabb].ar;
    }
    cout << legdragabb << endl;

    //c) h�nyf�le �r, amelyr�l egy�rtelm� v�ros �s �r (aka nincs t�bb bel�le)
    int hanyfele = 0;
    bool van = false;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j && ut[i].ar == ut[j].ar)
            {
                van = true;
            }
        }
        if (van == false) //true lenne ha h�nyf�le k�l �r k�ne
        {
            hanyfele++;
        }
        van = false;
    }
    cout << hanyfele << endl;

    //d) v�rosok sz�ma �s sorsz�mai ahova >100ft/km
    int d[maxN];
    int db = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ut[i].ar / ut[i].tav >= 100) //feladat 100n�l nagyobbat �r
        {
            d[db] = i + 1;
            db++;
        }
    }
    cout << db << " ";
    for (int i = 0; i < db; ++i)
    {
        cout << d[i] << " ";
    }
/*
6
50 30000
1900 200000
2000 150000
900 38000
600 150000
2100 30000
*/
    return 0;
}
