#include <iostream>
#include <cmath>

using namespace std;

void beolvas(float h[], int);

struct maximum
{
    float ertek;
    int index;
};

maximum maxker (float h[], int);

int main()
{
    const int max = 100;
    float h[max];
    int db;
    do
    {
        cout << "Adja meg hany napon mertek homersekletet (1 <= db <= " << max << "): ";
        cin >> db;
    }while (db <= 1 || db > max);

    beolvas(h,db);

    maximum m;
    m = maxker(h,db);

    /*maximum m;
    m = maxker (h,db);*/
    cout << "erteke " << m.ertek << " a kov helyen " <<m.index +1 << endl;

    return 0;
}

void beolvas(float h[], int db)
{
    cout << "Adja meg a napi atlaghomersekleteket: " << endl;
    for (int i = 0; i < db; ++i)
    {
        cout << i+1 << ". nap: ";
        cin >> h[i];
    }
}

maximum maxker(float h[], int db)
{
    maximum m;
    m.ertek = h[0];
    m.index = 0;

    for (int i = 1; i < db; ++i)
    {
        if (m.ertek < h[i])
        {
            m.ertek = h[i];
            m.index = i;
        }
    }
    return m;
}
