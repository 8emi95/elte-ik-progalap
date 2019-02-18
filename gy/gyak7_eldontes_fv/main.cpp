#include <iostream>
//#include <cmath>

using namespace std;

void beolvas (float h[], int);
bool eldontes (float h[], int);

int main()
{
    const int max = 100;
    float h[max];
    int n;
    do
    {
        cout << "Adja meg hany napon mertek homersekletet (1 <= n <= " << max << "): ";
        cin >> n;
    }while (n <= 1 || n > max);

    beolvas(h,n);

    bool van_e = false;

    van_e = eldontes(h,n);

    if (van_e == 1)
    {
         cout << "Volt-e 3 egymas utani napon fagypont alatt a homerseklet: Igen." << endl;
    }
    else
    {
         cout << "Volt-e 3 egymas utani napon fagypont alatt a homerseklet: Nem." << endl;
    }

    return 0;
}

void beolvas (float h[], int n)
{
    cout << "Adja meg a napi atlaghomersekleteket: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << i+1 << ". nap: ";
        cin >> h[i];
    }
}

bool eldontes (float h[], int n)
{
    int i = 0;
    bool van = false;
    while (i < n-2 && !van)
    {
        van = (h[i] < 0 && h[i+1] < 0 && h[i+2]);
        ++i;
    }


    return van;
}
