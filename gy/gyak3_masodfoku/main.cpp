#include <iostream>
#include <math.h> //diszkrimináns megoldásához sqrt() fv.

using namespace std;

int main()
{
    double a, b, c, d;
    cout << "Adja meg a erteket: ";
    cin >> a;
    cout << "Adja meg b erteket: ";
    cin >> b;
    cout << "Adja meg c erteket: ";
    cin >> c;

    if (a==0)
    {
        if (b==0)
        {
            if (c==0)
            {
                cout << "Azonossag.";
            }
            else
            {
                cout << "Nincs ilyen.";
            }
        }
        else
        {
            cout << "A megoldas: " << -c/b;
        }
    }
    else
    {
        d = b*b-4*a*c;
        if (d < 0)
        {
            cout << "Nincs megoldas.";
        }
        if (d == 0)
        {
            cout << "A megoldas: " << -b/2*a;
        }
        if (d > 0)
        {
            cout << "Elso megoldas: " << (-b+sqrt(d))/(2*a) << endl;
            cout << "Masodik megoldas: " << (-b-sqrt(d))/(2*a);
        }
    }
    return 0;
}
