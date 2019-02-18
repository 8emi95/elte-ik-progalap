#include <iostream>

using namespace std;

const int MAXN = 10000;

/*
paraméterek zárójelben
(int b) - számot vár
&b - referencia, memóriacímet ad oda
*/
void Beolvas(int Tomb[MAXN], int &N)
{
    cout << "hany db szam legyen? ";
    cin >> N;
    cout << "a szamok: " << endl;
    for (int i = 0; i < N; ++i)
    {
        cin >> Tomb[i];
    }
}

//összegzés
int Sum (int Tomb[MAXN], int N)
{
    int S = 0;
    for (int i = 0; i < N; ++i)
    {
        S = S + Tomb[i];
    }
    return S;
}

//megszámlálás
int Count(int Tomb[MAXN], int N)
{
    int Db = 0;
    for (int i = 0; i < N; ++i)
    {
        if (Tomb[i] % 2 == 0)
        {
            Db++;
        }
    }
    return Db;
}

//eldöntés
bool Van(int Tomb[MAXN], int N)
{
    bool Van = false;
    int i = 0;
    while (i <= N && !Van)
    {
        Van = (Tomb[i] == 4);
        ++i;
    }
    return Van;
}

//kiválasztás - 1. páratlan
int Kiv(int Tomb[MAXN], int N)
{
    int Ind = 0;
    while (!(Tomb[Ind] % 2 == 1))
    {
        ++Ind;
    }
    return Ind;
}

int main() //maint keresi meg és futtatja elõször mindig
{
    int N;
    int Tomb[MAXN];
    Beolvas(Tomb,N);
    cout << "megadott szamok (beolvasas ellenorzese):" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << Tomb[i] << endl;
    }
    cout << "[osszegzes] szamok osszege: " << Sum(Tomb,N) << endl;
    cout << "[megszamlalas] ennyi paros van: " << Count(Tomb,N) << endl;
    cout << "[eldontes] volt negyes? (1 igen 0 nem): " << Van(Tomb,N) << endl;
    cout << "[kivalasztas] elso paratlan: " << Tomb[Kiv(Tomb, N)] << endl;
    return 0;
}
