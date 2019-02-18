#include <iostream>

using namespace std;

const int maxN = 100;

int main()
{
    //beolvasás
    int n;
    int dobas[maxN][6];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            cin >> dobas[i][j];
        }
    }

    //1. minden versenyzõ legnagyobb értékû dobása
    int max = 0;
    int maxind = 0;
    int maxdob[maxN];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < 6; ++j)
        {
            if (dobas[i][j] > max)
            {
                max = dobas[i][j];
            }
        }
        if (max == -1)
        {
            maxdob[maxind] = 0;
        }
        else
        {
            maxdob[maxind] = max;
        }
        maxind++;
        max = 0;
    }
    for (int i = 0; i < maxind; ++i)
    {
        cout << maxdob[i] << " ";
    }
    cout << endl;

    //2. minden versenyzõ sikeres dobásainak száma
    int db = 0;
    int dbind = 0;
    int dbdob[maxN];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (dobas[i][j] != -1)
            {
                db++;
            }
        }
        dbdob[dbind] = db;
        dbind++;
        db = 0;
    }
    for (int i = 0; i < dbind; ++i)
    {
        cout << dbdob[i] << " ";
    }
    cout << endl;

    //3. minden versenyzõ utolsó sikeres dobásának sorszáma
    int ind = 0;
    int tombind = 0;
    int inddob[maxN];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (dobas[i][j] != -1)
            {
                ind = j;
            }
        }

        if (ind == 0)
        {
            inddob[tombind] = 0;
        }
        else
        {
            inddob[tombind] = ind + 1;
        }
        tombind++;
        ind = 0;
    }
    for (int i = 0; i < tombind; ++i)
    {
        cout << inddob[i] << " ";
    }
    cout << endl;

    //4. megbízható versenyzõk (minden dobása sikeres, max-min >= 500 cm)
    //min dobások
    int min = dobas[0][0];
    int minind = 0;
    int mindob[maxN];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (dobas[i][j] < min && dobas[i][j] != -1)
            {
                min = dobas[i][j];
            }
        }
        if (dbdob[i] == 0)
        {
            mindob[minind] = 0;
        }
        else
        {
            mindob[minind] = min;
        }
        minind++;
        min = dobas[0][0];
    }
    /*cout << "feladaton kivul - min dobasok: ";
    for (int i = 0; i < minind; ++i)
    {
        cout << mindob[i] << " ";
    }
    cout << endl;

    //max min kül ellenõrzés
    int kul = 0;
    cout << "feladaton kivul - max min kul: ";
    for (int i = 0; i < n; ++i)
    {
        cout << maxdob[i] - mindob[i] << " ";
    }
    cout << endl;*/

    int megb[maxN];
    int megb_db = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((maxdob[i] - mindob[i] <= 500) && dbdob[i] == 6)
        {
            megb[megb_db] = i + 1;
            megb_db++;
        }
    }
    cout << megb_db << " ";
    for (int i = 0; i < megb_db; ++i)
    {
        cout << megb[i] << " ";
    }
    cout << endl;

    //verseny gyõztese (ha többen akk 2., 3., stb legnagyobb dobás értéke számít)
    cout << endl;

    return 0;
}

/*
5
7623 7625 7131 7222 7255 7575
-1 -1 3456 3465 3440 -1
7200 7625 7230 7623 7578 7300
5454 5554 5555 5444 -1 5445
-1 100 -1 -1 -1 -1
*/
