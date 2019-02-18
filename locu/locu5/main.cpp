#include <iostream>

using namespace std;

const int maxn=10000;
//const int maxa=3000;

void beolvas(int adatok[maxn], int &N)
{
    cin >> N; //mérési pontok száma
    for (int i = 0; i < N; ++i)
    {
        cin >> adatok[i];
    }
}

int main()
{
    int adatok[maxn];
    int N = 0;
    //cout << "Hello world!" << endl;
    beolvas(adatok,N);

    int db = 0; //arvizek darabszama
    int seged[maxn];
    int i,j = 0;
    while (i < N)
    {
        j = i;
        if (adatok[i] > 800)
        {
            seged[db] = i+1;
            db++;
            while (j < N && adatok[j] > 800)
            {
                j++;
            }
            seged[db] = j;
            db++;
        }
        i = j+1;
    }
    cout << db/2 << endl;
    for (int i = 0; i < db; ++i)
    {
        cout << seged[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < db-1; ++i)
    {
        cout << seged[i+1]-seged[i]+1 << " ";
        ++i;
    }
    return 0;
}
