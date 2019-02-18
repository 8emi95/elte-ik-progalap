#include <iostream>

using namespace std;
/*név kor nem kereset mióta város
1 átlagfizu
2 nõk fizetése
3 van-e nõ 50+ 100e- fizu
4 város, 1950 elõtt óta dolgozik (feltesszük h létezik)
5 nõ, bp, 150e - minden adata (feltesszük h létezik)
6 adatok csökkenõ rendezése kereset szerint
*/

const int MAXN = 10000;

struct dolgozo
{
    string nev;
    int kor;
    bool nem; //ffi true, nõ false
    int kereset;
    int miota;
    string varos;
};

/*
referencia  h ott van mert ugynazon a memóriacímen dolgozik, kevésbé memóriaigényes
nélküle 2 memóriacím lenne
*/
void beolvas(dolgozo adatok[MAXN], int &db)
{
    cout << "Hany dolgozo legyen? ";
    cin >> db;
    char seged;
    for (int i = 0; i < db; ++i)
    {
        cout << i+1 << ". dolgozo neve: ";
        cin >> adatok[i].nev;
        cout << i+1 << ". dolgozo kora: ";
        cin >> adatok[i].kor;
        cout << i+1 << ". dolgozo neme (N/F): ";
        cin >> seged;
        if (seged == 'N')
        {
            adatok[i].nem = false;
        }
        else
        {
            adatok[i].nem = true;
        }
        cout << i+1 << ". dolgozo keresete: ";
        cin >> adatok[i].kereset;
        cout << i+1 << ". dolgozo miota dolgozik a cegnel: ";
        cin >> adatok[i].miota;
        cout << i+1 << ". dolgozo melyik varosban lakik: ";
        cin >> adatok[i].varos;
    }

}

//1
float atlagfizu (dolgozo adatok[MAXN], int &db)
{
    float osszkereset = 0;
    for (int i = 0; i < db; ++i)
    {
        osszkereset = osszkereset + adatok[i].kereset;
    }
    cout << "A dolgozok atlagizetese: " << osszkereset/db << endl;
    return osszkereset;
}

//2
int noifizetes (dolgozo adatok[MAXN], int &db)
{
    int noosszkereset = 0;
    for (int i = 0; i < db; ++i)
    {
        if (adatok[i].nem == false)
        {
            noosszkereset = noosszkereset + adatok[i].kereset;
        }
    }
    cout << "Nok fizetese osszesen: " << noosszkereset << endl;
    return noosszkereset;
}

//3
bool otvenesnokevesfizu (dolgozo adatok[MAXN], int &db)
{
    bool van = false;
    int i = 0;
    while (i <= db && !van)
    {
        van = (adatok[i].kor > 50 && adatok[i].nem == false && adatok[i].kereset < 100);
        ++i;
    }
    cout << "Van-e 50 feletti 100 alatti fizetesu no (0 nincs 1 van): " << van << endl;
    return van;
}

//4
int regivarosa (dolgozo adatok[MAXN], int &db)
{
    int ind = 0;
    while (!(adatok[ind].miota < 1950))
    {
        ++ind;
    }
    cout << "Az 1950 elott ota dolgozo lakhelye: " << adatok[ind].varos << endl;
    return ind;
}

//5
int nobp150 (dolgozo adatok[MAXN], int &db)
{
    int Ind = 0;
    while (!(adatok[Ind].nem == false && adatok[Ind].kereset == 150 && adatok[Ind].varos == "Budapest"))
    {
        ++Ind;
    }
    cout << "150 fizetesu budapesti no adatai: " << adatok[Ind].nev << " " << adatok[Ind].kor << " " << adatok[Ind].miota << endl;
    return Ind;
}

//6
void rendezes (const dolgozo adatok[MAXN], const int N)
{
    dolgozo seged[N];
    for (int i = 0; i < N; ++i)
    {
        seged[i] = adatok[i];
    }
    dolgozo csere; //csak így tudod átadni
    for (int i = 0; i < N; ++i)
    {
        for (int j = i+1; j < N; ++j)
        {
            if (seged[i].kereset < seged[j].kereset)
            {
                csere = seged[i];
                seged[i] = seged[j];
                seged[j] = csere;
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        cout << seged[i].nev << " ";
        cout << seged[i].kor << " ";
        cout << seged[i].nem << " ";
        cout << seged[i].kereset << " ";
        cout << seged[i].miota << " ";
        cout << seged[i].varos << " " << endl;
    }
}

int main()
{
    dolgozo adatok[MAXN];
    int db = 0;
    beolvas(adatok,db);
    atlagfizu(adatok,db);
    noifizetes(adatok,db);
    otvenesnokevesfizu(adatok,db);
    regivarosa(adatok,db);
    nobp150(adatok,db);
    rendezes(adatok,db);
    return 0;
}
