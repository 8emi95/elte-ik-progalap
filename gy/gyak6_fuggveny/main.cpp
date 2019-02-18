#include <iostream>
#include <cmath>

using namespace std;

void beolvas(float h[], int);
int szamlal(float h[], int);

int main()
{
    const int max = 100;
    float h[max];
    int db;
    int eredmeny;
    do
    {
        cout << "Adja meg hany napon mertek homersekletet (1 <= db <= " << max << "): ";
        cin >> db;
    }while (db <= 1 || db > max);

    beolvas(h,db);
    eredmeny = szamlal(h,db);
    if (eredmeny == 0)
    {
        cout << "Nem volt ilyen." << endl;
    }
    else
    {
        cout << eredmeny << "-szer volt tobb mint 10 °C kulonbseg egymas utani napokon." << endl;
    }
    return 0;
}

void beolvas (float h[], int db) //nevet kell adni!
{
    cout << "Adja meg a napi atlaghomersekleteket: " << endl;
    for (int i = 0; i < db; ++i)
    {
        cout << i+1 << ". nap: ";
        cin >> h[i];
    }
}

int szamlal (float h[], int db) //tobb mint 10 C° kül napok között
{
    int darab = 0;
    for (int i = 0; i < db-1; ++i)
    {
        if (fabs(h[i]-h[i+1]) > 10)
        {
            ++darab;
        }
    }
    return darab;
}
