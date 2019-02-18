#include <iostream>

using namespace std;

int main()
{

    //statikus helyfoglal�s� t�mb
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
    //t�mb elemeinek ki�rat�sa
    cout << "A tomb elemei: ";
    for (int i = 0; i < n; ++i)
    {
        cout << h[i] << ", ";
    }
    cout << h[n-1] << ";" << endl;

    //maximum-kiv�laszt�s (5 naponk�nt mozg� �tlag, legmagassabb �tlaghoz tartoz� els� nap + maximum)
    int index = 0;
    int osszeg = h[0]+h[1]+h[2]+h[3]+h[4];
    int max = osszeg/5;
    for (int i = 0; i < n-5; ++i)
    {
        osszeg = osszeg - h[i];
        osszeg = osszeg + h[i+5];
        if (max < osszeg/5)
        {
            max = osszeg/5;
            index = i+1;
        }
    }
    cout << "Legmagasabb atlaghoz tartozo elso nap es maximum: " << index+1 << ", " << max << endl;
    return 0;
}
