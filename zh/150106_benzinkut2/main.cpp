#include <iostream>

using namespace std;

struct Benzinkut
{
    int Tav;
    int Tank;
};

int main()
{
    int hossz;
    int tankDb;
    int kezdoBenzin;
    int fogyLit;

    cin >> hossz >> tankDb >> kezdoBenzin >> fogyLit;
    Benzinkut adatok[tankDb];
    for (int i = 0; i < tankDb; ++i)
    {
        cin >> adatok[i].Tav >> adatok[i].Tank;
    }

    //a) mennyi benzin lesz az út végén
    int szuksegesBenzin = hossz / 100 * fogyLit;
    int osszBenzin = kezdoBenzin;
    for (int i = 0; i < tankDb; ++i)
    {
        osszBenzin += adatok[i].Tank;
    }
    cout << osszBenzin - szuksegesBenzin << endl;

    //aktuális benzinmennyiség kiszámítása a többi feladathoz
    int aktBenzin = kezdoBenzin;
    int aktBenz[tankDb];
    int aktBenz_ind = 0;
    for (int i = 0; i < tankDb; ++i)
    {
        if (i == 0)
        {
            aktBenzin = kezdoBenzin - (adatok[i].Tav / 100 * fogyLit) + adatok[i].Tank;
            aktBenz[i] = aktBenzin;
            aktBenz_ind++;
        }
        else
        {
            aktBenzin += adatok[i].Tank - ((adatok[i].Tav - adatok[i-1].Tav) / 100 * fogyLit);
            aktBenz[i] = aktBenzin;
            aktBenz_ind++;
        }
    }

    //b) hány literes az üzemanyagtartály [aktbenzin maximuma]
    int tartaly = 0;
    int maxAktBenz = 0;
    for (int i = 0; i < tankDb; ++i)
    {
        if (aktBenz[i] > aktBenz[maxAktBenz])
        {
            tartaly = aktBenz[i];
            maxAktBenz = i;
        }
    }
    cout << tartaly << endl;

    //c) legkorábbi benzinkút száma, amikor már nem kellett volna tankolni
    int osszTank = kezdoBenzin;
    int osszTankolas[tankDb];
    int osszTankolas_ind = 0;
    for (int i = 0; i < tankDb; ++i)
    {
        osszTank += adatok[i].Tank;
        osszTankolas[i] = osszTank;
        osszTankolas_ind++;
    }

    int j = 0;
    if (kezdoBenzin >= szuksegesBenzin)
    {
        cout << 0 << endl;
    }
    else
    {
        while (!(osszTankolas[j] - szuksegesBenzin >= 0))
        {
            j++;
        }
        bool van = (j < tankDb);
        if (van)
        {
            cout << j + 1 << endl;
        }
    }

    //d) mely benzinkutaknál lett több a benzin, mint az elõzõ tankolás után
    int db = 0;
    int tobbBenz[tankDb];
    for (int i = 0; i < tankDb; ++i)
    {
        if (aktBenz[i] > aktBenz[i-1])
        {
            tobbBenz[db] = i + 1;
            db++;
        }
    }
    cout << db << " ";
    for (int i = 0; i < db; ++i)
    {
        cout << tobbBenz[i] << " ";
    }
    cout << endl;

    //e) leghosszabb olyan 2 benzinkút közötti szakasz hossza, amikor a benzin folyamatosan a kezdeti benzinmennyiség, vagy annál több volt
    int i = 0;
    int k = 0;
    int kezdFelett[tankDb];
    int kezdFelett_ind = 0;
    while (i < tankDb - 1)
    {
        k = i + 1;
        if (aktBenz[i] >= kezdoBenzin)
        {
            k = i;
            while (k < tankDb - 1 && aktBenz[k] >= kezdoBenzin)
            {
                k++;
            }
            kezdFelett[kezdFelett_ind] = adatok[k].Tav - adatok[i].Tav;
            kezdFelett_ind++;
        }
        i = k;
    }

    int maxKezdFelett = 0;
    int maxHossz = 0;
    for (int i = 0; i < kezdFelett_ind; ++i)
    {
        if (kezdFelett[i] > kezdFelett[maxKezdFelett])
        {
            maxHossz = kezdFelett[i];
            maxKezdFelett = i;
        }
        else if (kezdFelett_ind == 1)
        {
            maxHossz = kezdFelett[i];
        }
    }
    cout << maxHossz;

    return 0;
}
/*
2000 4 40 7
400 20
500 80
800 30
1200 30
*/
