#include <iostream>
#include <cmath> //fabs

using namespace std;

int main()
{
    const int max = 100;
    int h[max];
    int n;
    do
    {
        cout << "Adja meg hany napon mertek homersekletet (1 <= n <= " << max << "): ";
        cin >> n;
    }while (n <= 1 || n > max);
    cout << "Adja meg a napi atlaghomersekleteket: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << i+1 << ". nap: ";
        cin >> h[i];
    }

    //tömb elemeinek kiíratása - ha jól tároltuk le akk ki tudja írni
    for (int i = 0; i < n-1; ++i)
    {
        cout << h[i] << ", ";
    }
    cout << h[n-1] << ";" << endl;

    int db = 0;
    for (int i = 0; i < n-1; ++i)
    {
        if (fabs(h[i]-h[i+1]) > 10)
        {
            db = db + 1;
        }
        ++i;
    }
    if (db > 0)
    {
        cout << "Ennyiszer volt az egymas utani napokon tobb mint 10 C a kulonbseg: " << db << endl;
    }
    else
    {
        cout << "Nem volt ilyen." << endl;
    }
    return 0;
}
