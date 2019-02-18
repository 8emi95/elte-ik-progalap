#include <iostream>

using namespace std;

int main()
{
    //int egesz[5] = {3, 21, 8, 27, 48};

    //statikus helyfoglalású tömb
    const int max_m = 100; //max méret, konstans - futási idõben nem változtathat rajta a program
    int v[max_m]; //100 lesz a tömb mérete
    int n; //db
    do
    {
        cout << "adja meg a tomb elemszamat (1 es " << max_m << " kozott): ";
        cin >> n;
        //cout << "" << endl; //if, amivel megvizsgálom h n jó-e
    }while (n <= 1 || n > max_m);
    cout << "adja meg a tomb elemeit: " << endl;
    for (int i = 0; i < n; ++i) //0tól n-1ig megy
    {
        cout << i + 1 << ". elem: ";
        cin >> v[i];
    }
    //tömb elemeinek kiíratása
    for (int i = 0; i < n; ++i)
    {
        cout << v[i] << ", ";
    }
    cout << v[n-1] << ";" << endl;

    return 0;
}
