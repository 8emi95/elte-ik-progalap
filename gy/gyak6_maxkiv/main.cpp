#include <iostream>

using namespace std;

int main()
{

    //statikus helyfoglalású tömb
    const int max_m = 100;
    int h[max_m];
    int n;
    do
    {
        cout << "Adja meg a tomb elemszamat (1 es " << max_m << " kozott): ";
        cin >> n;
    }while (n <= 1 || n > max_m);
    cout << "Adja meg a tomb elemeit: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << i + 1 << ". elem: ";
        cin >> h[i];
    }
    //tömb elemeinek kiíratása
    cout << "A tomb elemei: ";
    for (int i = 0; i < n; ++i)
    {
        cout << h[i] << ", ";
    }
    cout << h[n-1] << ";" << endl;

    //maximum-kiválasztás (nap sorszáma + értéke)
    int index = 0;
    int maximum = h[0];
    for (int i = 1; i < n; ++i)
    {
        if (maximum < h[i])
        {
            maximum = h[i];
            index = i;
        }
    }
    cout << "Legmagasabb homersekletu nap sorszama es erteke: " << index+1 << ", " << maximum << endl;

    return 0;
}
