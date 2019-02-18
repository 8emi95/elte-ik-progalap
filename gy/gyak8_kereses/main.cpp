#include <iostream>
#include <cmath>

using namespace std;

void beolvas(float[], int);
bool keres(float[], int, float&, int&);

int main()
{
    const int max = 100;
    float adat[max];
    int db, index;
    float h;
    do
    {
        cout << "Adja meg hany napon mertek homersekletet (3 <= db <= " << max << "): ";
        cin >> db;
    }while (db < 3 || db > max);

    beolvas(adat,db);
    bool van_e = keres(adat,db,h,index);

    if(van_e)
    {
        cout << index+1 << ". napon elotte es utana is alacsonyabb volt a homerseklet: " << h << endl;
    }
    else
    {
        cout << "Nem volt olyan nap, ami elott es utan is alacsonyabb volt a homerseklet." << endl;
    }

    return 0;
}

void beolvas (float v[], int db)
{
    cout << "Adja meg a napi atlaghomersekleteket: " << endl;
    for (int i = 0; i < db; ++i)
    {
        cout << i+1 << ". nap: ";
        cin >> v[i];
    }
}

bool keres (float v[], int db, float &h, int &index)
{
    int i = 1;
    bool van = false;
    while(i < db-1 && !van)
    {
        van = (v[i] > 0 && v[i] > v[i-1] && v[i] > v[i+1]);
        ++i;
    }
    if(van)
    {
        h = v[i-1];
        index = i-1;
    }
    return van;
}
