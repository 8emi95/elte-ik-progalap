#include <iostream>

using namespace std;

int main()
{
    const int maxm = 100;
    int ev[maxm];
    int fizu[maxm];
    //int hanyfele[maxm]; //c)
    int kik[maxm]; //d)

    int db;
    cout << "Adja meg a darabszamot: ";
    cin >> db;

    cout << "Add meg a talalatok szamat es a nyeremenyeket: " << endl;
    for(int i = 0; i < db; ++i)
    {
        cin >> ev[i] >> fizu[i];
    }

    //a) legid�sebb dolgoz� sorsz�ma
    int maxind = 0;
    for(int i = 1; i < db; ++i)
    {
        if(ev[i] > ev[maxind])
        {
            maxind = i;
        }
    }
    cout << maxind + 1 << endl;

    //b) h�ny 40 �v felettinek van 200e-n�l kisebb fizet�se
    int dbb = 0;
    for(int i = 0; i < db; ++i)
    {
        if(ev[i] > 40 && fizu[i] < 200000)
        {
            dbb++;
        }
    }
    cout << dbb << endl;

    //c) h�nyf�le �letkor� ember van
    int dbc = 0;
    kik[0] = ev[0];
    for(int i = 0; i < db-1; ++i)
    {
        if(ev[i+1] != kik[0])
        {
            int j = 0;
            while(j <= dbc && ev[i+1] != kik[j])
            {
                j++;
            }
            if(j > dbc)
            {
                kik[dbc+1] = ev[i+1];
                dbc++;
            }
        }
    }
    cout << dbc+1 << endl;

    //d) 30 �vn�l fiatalabbak sz�ma �s sorsz�ma (n�vekv� sorrendben) sz�k�zzel elv�lasztva
    /*int dbd = 0;
    for(int i = 0; i < db; ++i)
    {
        if(eletkor[i] < 30)
        {
            kik[dbd] = i;
            dbd++;
        }
    }
    cout << dbd << " ";
    for(int i = 0; i < db; ++i)
    {
        cout << kik[i] << " ";
    }*/

    return 0;
}
