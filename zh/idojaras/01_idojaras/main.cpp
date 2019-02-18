#include <iostream>

using namespace std;

const int maxN = 100;
struct homerseklet
{
    int minHom;
    int maxHom;
};

int main()
{
    homerseklet napok[maxN];

    //beolvasás
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> napok[i].minHom >> napok[i].maxHom;
    }

    //a) azon napok száma, amikor fagyni fog
    int db = 0;
    for (int i = 0; i < n; ++i)
    {
        if (napok[i].minHom <= 0)
        {
            db++;
        }
    }
    cout << db << endl;

    //b) legnagyobb kül min és max között (ha több van -> legkisebb sorszámút)
    int maxKul = 0;
    for (int i = 1; i < n; ++i)
    {
        if (napok[i].maxHom - napok[i].minHom > napok[maxKul].maxHom - napok[maxKul].minHom)
        {
            maxKul = i;
        }
    }
    cout << maxKul + 1 << endl;

    //c) 1 nap, amikor max kisebb elõzõ min-nál (több -> legkisebb sorszámú; nincs -> -1)
    int ind = 1;
    while (!(napok[ind].maxHom < napok[ind-1].minHom))
    {
        ind++;
    }
    bool van = (ind < n);
    if (van)
    {
        cout << ind + 1 << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    //d) napok száma és sorszámai, ahol fagyni és olvadni is fog
    int d[maxN];
    int d_db = 0;
    for (int i = 0; i < n; ++i)
    {
        if (napok[i].minHom <= 0 && napok[i].maxHom > 0)
        {
            d[d_db] = i + 1;
            d_db++;
        }
    }
    cout << d_db << " ";
    for (int i = 0; i < d_db; ++i)
    {
        cout << d[i] << " ";
    }

    return 0;
}
