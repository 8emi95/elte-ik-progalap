#include <iostream>

using namespace std;

int main()
{
    const int maxm = 1000;
    int elso[maxm];
    int utolso[maxm];
    int napok[maxm];

    int n,m;

    cin >> n >> m;

    for(int i = 0; i < m; ++i)
    {
        cin >> elso[i] >> utolso[i];
    }

    //a) leghoszabb ideig szolgálatban lévõ sorszáma
    int maxnap = utolso[0] - elso[0] + 1;

    for (int i = 1; i < m; ++i)
    {
        if((utolso[i] - elso[i] + 1) > maxnap)
        {
            maxnap = utolso[i] - elso[i] + 1;
        }
    }
    cout << maxnap << endl;

    //b) egyes napokon hány õr volt szolgálatban
    for(int j = 0; j < n; ++j)
    {
        int s = 0;
        for(int i = 0; i < m; ++i)
        {
            if(utolso[i] >= j + 1 && elso[i] <= j + 1)
            {
                ++s;
            }
        }
        napok[j] = s;
    }

    for(int i = 0; i < n; ++i)
    {
        cout << napok[i] << " ";
    }
    cout << endl;

    //c) nap sorszáma, amikor a legtöbb õr volt szolgálatban
    int legt = napok[0];
    int max_ind = 0;

    for(int i = 1; i < n; ++i)
    {
        if(napok[i] > legt)
        {
            legt = napok[i];
            max_ind = i;
        }
    }
    cout << max_ind+1 << endl;

    //d) leghosszabb sorozat elsõ + utolsó napja, amikor <2 õr volt szolgálatban
    int legh = 0;
    int maxh = 0;
    int kezd_ind, legh_kezdind, veg_ind, legh_vegind;

    for(int i = 0; i < n; ++i)
    {
        if(napok[i] < 2 && legh == 0)
        {
            ++legh;
            kezd_ind = i;
        }

        if(napok[i] < 2 && legh != 0)
        {
            ++legh;
            veg_ind = i;
        }

        if(legh > maxh)
        {
            maxh = legh;
            legh_kezdind = kezd_ind;
            legh_vegind = veg_ind;
        }
        else
        {
            legh = 0;
        }
    }

    if(maxh > 0)
    {
        cout << legh_kezdind + 1 << " " << legh_vegind + 1;
    }
    else
    {
        cout << 0;
    }

    return 0;
}
