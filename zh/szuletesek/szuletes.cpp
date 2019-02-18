#include <iostream>
#define maxN 100

using namespace std;

struct Szuletes
{
    int ho, nap, db;
};

int A_fel(Szuletes T[], const int N);
void B_fel(Szuletes T[], const int N);
void C_fel(Szuletes T[], const int N);
void D_fel(Szuletes T[], const int N);

int main()
{
    int N;
    Szuletes T[maxN];

    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> T[i].ho>> T[i].nap >> T[i].db;
    }

    for (int i=0; i<N; i++)
    {
        clog<< T[i].ho <<" "<< T[i].nap<<" " << T[i].db<< endl;
    }

    clog << "---\n";
    cout << A_fel(T, N)<<endl;
    B_fel(T, N);
    C_fel(T, N);
    cout <<0;
}
int A_fel(Szuletes T[], const int N)
{
    int s=0;
    for (int i=0; i<N; i++)
    {
        s+= T[i].db;
    }
    return s;
}
void B_fel(Szuletes T[], const int N)
{
    int max_ind=1;

    int tmp;
    int mxtmp=T[max_ind].db-T[max_ind-1].db;
    for (int i=2; i<N; i++)
    {
        tmp= (T[i].db-T[i-1].db);
        if (tmp>=mxtmp)
        {
            max_ind=i;
            mxtmp=T[max_ind].db-T[max_ind-1].db;
        }

    }

    if (mxtmp>0)
    {
        cout << T[max_ind].ho << " "<< T[max_ind].nap;

    }
    else cout << 0;

    cout << endl;

}
void C_fel(Szuletes T[], const int N)
{
    if (T[0].ho!=1)
        cout <<"IGEN "<<1<<endl;
    else
    {
        int i=1;
        while (i<N and (T[i].ho-1==T[i-1].ho or T[i].ho==T[i-1].ho))
            i++;

        if (i!=N)
            cout << "IGEN "<< T[i-1].ho+1<<endl;
        else
        {
            if (T[N-1].ho==12)cout << "NEM\n";
            else cout << "IGEN "<<T[N-1].ho+1<<endl;

        }

    }
}
void D_fel(Szuletes T[], const int N)
{



}

