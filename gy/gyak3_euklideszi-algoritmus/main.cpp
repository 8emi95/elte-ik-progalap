#include <iostream>

using namespace std;

int main()
{
    int a, b, maradek;

    do
    {
        cout << "Adja meg az elso szamot: ";
        cin >> a;
        if (a <= 0)
        {
            cout << "Termeszetes szamot kerek!" << endl;
        }
    }while (a <= 0);
    do
    {
        cout << "Adja meg a masodik szamot: ";
        cin >> b;
        if (b <= 0)
        {
            cout <<"Termeszetes szamot kerek!" << endl;
        }
    }while (b <= 0);

    if (a < b)
    {
        int cs = a;
        a = b;
        b = cs;
    }

    maradek = a % b;

    while (maradek > 0)
    {
        a = b;
        b = maradek;
        maradek = a % b;
    }

    cout << "Legnagyobb kozos oszto: " << b << endl;
    return 0;
}
