#include <iostream>

using namespace std;

const int MaxN = 1000;

int Osszegzes(int X[MaxN], int N)
{
    int S = 0;
    for(int i = 0; i < N; ++i)
    {
        S = S + X[i];
    }
    return S;
}

unsigned int Megszamlalas(int X[MaxN], int N)
{
    unsigned int Db = 0;
    for(int i = 0; i < N; ++i)
    {
        if( X[i] % 2 == 0)
        {
            Db = Db + 1;
        }
    }
    return Db;
}

int main()
{
    /*
    Bemenet :   N eleme Természetes szám (tömb mérete)
                X^N tömb (Egész számok)
    */
    int N;
    bool rossz;
    do
    {
        cout << "Hany elemu lesz a tomb? : ";
        cin >> N;
        rossz = !(N >= 0 && N <= 1000) || cin.fail();
        if(rossz)
        {
            cout << "Termeszetes szamot kerek!" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }
    while(rossz);
    int X[N];
    for(int i = 0; i < N; ++i)
    {
        do
        {
            cout << "Kerem az " << i + 1 << "-edik szamot: ";
            cin >> X[i];
            rossz = cin.fail();
            if(rossz)
            {
                cout << "Nem jo az ertek!" << endl;
                cin.clear();
                cin.ignore(1000,'\n');
            }
        }while(rossz);
    }

    // Összegzés!!!!!!
    /*
    Bemenet : -
    Kimenet : S (Egész szám)
    Elõfeltétel : -
    Utófeltétel : S := i=1 SZUMMA N { X[i] }
    */
    cout << "Osszeg : " << Osszegzes(X,N) << endl;

    // Megszámlálás!!!!
    /*
    Bemenet : T : Egész számokból -> Logika
    Kimenet : Db : Természetes szám
    Elõfeltétel : -
    Utófeltétel : Db := { T(X[i]) } i=1 SZUMMA N { 1 }
    */
    cout << "Paros szamok dabarszama: " << Megszamlalas(X,N) << endl;
    //Maximum Kiválasztás!!!!
    /*
    Bemenet : -
    Kimenet : Max (természetes szám)
    Elõfeltétel : N > 0
    Utófeltétel : 1 <= Max <= N , Minden i(1..N) X[i] <= X[Max]
    */

    unsigned int Max = 0;
    for(int i = 1; i < N; ++i)
    {
        if(X[i] > X[Max])
        {
            Max = i;
        }
    }
    cout << "Legnagyobb elem: " << X[Max] << endl;

    //Eldöntés
    /*
    Bemenet : T : Egész számból -> logika
    Kimenet : Van : Logika
    Elõfeltétel : -
    Utófeltétel : Van = Létezik i(1<=i<=N):T(X[i])
    */
    int i = 0;
    bool Van = false;
    while (i < N && !Van)
    {
        Van = (X[i] % 2 == 0);
        i++;
    }
    cout << "Volt? : " << Van << endl;

    //Kiválasztás
    /*
    Bemenet : T : Egészbõl -> Logika
    Kimenet : Ind : Természetes szám
    Elõfeltétel : N > 0 && Létezik i(1<=i<=N):T(X[i])
    Utófeltétel : 1<=Ind<=N && T(X[Ind])
    */
    int Ind = 0;
    while( !(X[Ind] % 3 == 0) )
    {
        Ind++;
    }
    cout << "Keresett elem : " << X[Ind] << endl;

    //Keresés
    /*
    Bemenet : T : Egészbõl -> Logikaiba
    Kimenet :   Van : Logika
                Ind : Természetes szám
    Elõfeltétel : -
    Utófeltétel : Van = Létezik i(1<=i<=N):T(X[i]) és Van->1<=Ind<=N && T(X[Ind])
    */
    int j = 0;
    while( !(X[j] % 3 == 0) )
    {
        j++;
    }
    bool Van2 = (j < N);
    if(Van2)
    {
        cout << "Letezik az elem : " << X[j] << endl;
    }
    else
    {
        cout << "Nem letezik!" << endl;
    }
    return 0;
}
