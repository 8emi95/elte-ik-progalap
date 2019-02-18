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
    Bemenet :   N eleme Term�szetes sz�m (t�mb m�rete)
                X^N t�mb (Eg�sz sz�mok)
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

    // �sszegz�s!!!!!!
    /*
    Bemenet : -
    Kimenet : S (Eg�sz sz�m)
    El�felt�tel : -
    Ut�felt�tel : S := i=1 SZUMMA N { X[i] }
    */
    cout << "Osszeg : " << Osszegzes(X,N) << endl;

    // Megsz�ml�l�s!!!!
    /*
    Bemenet : T : Eg�sz sz�mokb�l -> Logika
    Kimenet : Db : Term�szetes sz�m
    El�felt�tel : -
    Ut�felt�tel : Db := { T(X[i]) } i=1 SZUMMA N { 1 }
    */
    cout << "Paros szamok dabarszama: " << Megszamlalas(X,N) << endl;
    //Maximum Kiv�laszt�s!!!!
    /*
    Bemenet : -
    Kimenet : Max (term�szetes sz�m)
    El�felt�tel : N > 0
    Ut�felt�tel : 1 <= Max <= N , Minden i(1..N) X[i] <= X[Max]
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

    //Eld�nt�s
    /*
    Bemenet : T : Eg�sz sz�mb�l -> logika
    Kimenet : Van : Logika
    El�felt�tel : -
    Ut�felt�tel : Van = L�tezik i(1<=i<=N):T(X[i])
    */
    int i = 0;
    bool Van = false;
    while (i < N && !Van)
    {
        Van = (X[i] % 2 == 0);
        i++;
    }
    cout << "Volt? : " << Van << endl;

    //Kiv�laszt�s
    /*
    Bemenet : T : Eg�szb�l -> Logika
    Kimenet : Ind : Term�szetes sz�m
    El�felt�tel : N > 0 && L�tezik i(1<=i<=N):T(X[i])
    Ut�felt�tel : 1<=Ind<=N && T(X[Ind])
    */
    int Ind = 0;
    while( !(X[Ind] % 3 == 0) )
    {
        Ind++;
    }
    cout << "Keresett elem : " << X[Ind] << endl;

    //Keres�s
    /*
    Bemenet : T : Eg�szb�l -> Logikaiba
    Kimenet :   Van : Logika
                Ind : Term�szetes sz�m
    El�felt�tel : -
    Ut�felt�tel : Van = L�tezik i(1<=i<=N):T(X[i]) �s Van->1<=Ind<=N && T(X[Ind])
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
