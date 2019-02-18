#include <iostream>
#define maxN 1000

using namespace std;

struct Wine
{
    int value, price;
};

int minimum(Wine T[maxN], const int N);
int felt_max(Wine T[maxN], const int N);
int hanyfele(Wine T[maxN], const int N);
void kivalogatas(Wine T[maxN], const int N);

int main()
{

    Wine data[maxN];
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> data[i].value >> data[i].price;
    }

    /*//beolvasás ellenõrzése
    for (int i = 0; i < N; i++)
    {
        clog << data[i].value << " " << data[i].price << endl;
    }
    clog << "--\n";*/

    cout << minimum(data, N) + 1 << endl;
    cout << felt_max(data, N) << endl;
    cout << hanyfele(data, N) << endl;
    kivalogatas(data, N);

    return 0;
}

int minimum(Wine T[maxN], const int N)
{
    int index = 0;
    for (int i = 1; i < N; i++)
    {
        if (T[i].value < T[index].value)
        {
            index = i;
        }
    }
    return index;
}

int felt_max(Wine T[maxN], const int N)
{
    bool volt = false;
    int index = 0;
    for (int i = 1; i < N; i++)
    {
        if (T[i].value > 1000 && T[i].price > T[index].price)
        {
            index = i;
            volt = true;
        }
    }

    if (volt)
    {
        return T[index].price;
    }

    return -1;
}

int hanyfele(Wine T[maxN], const int N)
{
    int db = 0;
    int j;
    for (int i = 0; i < N; i++)
    {
        j = 0;
        while (j < i && T[i].price != T[j].price)
        {
            j++;
        }
        if (j == i)
        {
            db++;
        }
    }
    return db;
}

void kivalogatas(Wine T[maxN], const int N)
{
    int X[N];
    int db = 0;
    int j;

    for (int i = 0; i < N; i++)
    {
        X[i] = -1;
    }
    for (int i = 1; i < N; i++)
    {
        j = 0;
        while (j < i && T[i].value > T[j].value)
        {
            j++;
        }
        if (j == i)
        {
            X[db] = i + 1;
            db++;
        }
    }
    cout << db << " ";
    for (int i = 0; i < db; i++)
    {
        cout << X[i] << " ";
    }
}
