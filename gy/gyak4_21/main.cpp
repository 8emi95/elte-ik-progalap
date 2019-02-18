#include <iostream>

using namespace std;

int main()
{
    const string kartya[] = {"VII", "VIII", "IX", "X", "also", "felso", "kiraly", "asz"};
    const int ertek[] = {7, 8, 9, 10, 2, 3, 4, 11}; //sorrendben "társítja"
    int n, osszeg, i, j;
    string lap;
    bool hiba;
    cout <<"Huszonegyezes\nLehetseges lapok: ";
    for (i = 0; i < 8; ++i) //kívül már deklarálva van, nem kell int
    {
        cout << kartya[i] << " ";
    }
    cout << endl;
    do
    {
        cout << "Hany lapod van? ";
        cin >> n;
        if (n <= 1 || n > 32)
        {
            cout << "Tul sok lap." << endl; //Ilyen lap nincs.
        }
    }while (n <= 1 || n > 32);
    osszeg = 0;
    for (i = 1; i <= n; ++i)
    {
        do
        {
            cout << i << ". lapod: ";
            cin >> lap;
            j = 0;
            while (j < 8 && kartya[j] != lap)
            {
                ++j;
            }
            hiba = (j == 8);
            if (hiba)
            {
                cout << "Nincs ilyen." << endl;
            }
        }while (hiba);
        cout << "Kartya erteke: " << ertek[j] << endl;
        osszeg += ertek[j];
    }
    cout << "Lapjaid osszerteke: " << osszeg << endl;
    return 0;
}
