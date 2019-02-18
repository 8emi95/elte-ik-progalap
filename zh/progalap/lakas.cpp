#include <iostream>

using namespace std;

const int maxN=100;

struct Lakas
{
    int ter, ar;
};

int A_fel_max(Lakas T[], const int N);
int B_fel_megsz(Lakas T[], const int N);
int C_fel_megsz(Lakas T[], const int N);
void D_fel(Lakas T[], const int N);

int main()
{

    int N;
    Lakas T[maxN];


    cin >> N;

    for (int i=0; i<N; i++)
    {
        cin >> T[i].ter >> T[i].ar;
    }


    for (int i=0; i<N; i++)
    {
        clog<< T[i].ter <<" " << T[i].ar<< endl;
    }


    cout << A_fel_max(T, N)<< endl;
    cout << B_fel_megsz(T, N)<< endl;

    cout << C_fel_megsz(T, N)<< endl;

    D_fel(T, N);



    return 0;
}
int A_fel_max(Lakas T[], const int N)
{
    int index=0;

    for (int i=1; i<N; i++)
    {
        if (T[i].ar>T[index].ar) index=i;
    }

    return index+1;
}
int B_fel_megsz(Lakas T[], const int N)
{
    int s=0;

    for (int i=0; i<N; i++)
    {
        if(T[i].ter>100 and T[i].ar<40)
            s++;
    }

    return s;
}
int C_fel_megsz(Lakas T[], const int N)
{
    int s=0;
    int j;
    for (int i=0; i<N; i++)
    {
        j=0;
        while (j<i and T[i].ter!=T[j].ter)
            j++;

        if (j==i) s++;

    }
    return s;
}
void D_fel(Lakas T[], const int N)
{

    int seged[maxN];
    int db=0;
    for (int i=0; i<N; i++)
    {
        if (T[i].ar>100)
        {
            seged[db]=i+1;
            db++;
        }
    }
    cout << db<< " " ;
    for (int i=0; i<db; i++)
    {
        cout << seged[i]<< " ";
    }
}


