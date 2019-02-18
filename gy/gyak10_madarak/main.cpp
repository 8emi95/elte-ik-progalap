#include <iostream>
#include <string>
#include <stdlib.h> //csak ez kell pluszban

//lehet fv-nyel es nelkule is vizsgan

using namespace std;

void beolvas(int v[5][20], string h[5], int &, int &);

//a) egyes helyeken hanyfele madar
int szamlal(int v[5][20], int  h_f[], int&, int&);

int main()
{
    int n, m;
    int t[5][20];
    int h_f[5];
    string hely[5];

    beolvas(t,hely,n,m);
    int szam=szamlal(t,h_f,n,m);
    if(szam>0) //if nelkul is ki lehet iratni
    {
        cout<<"Az egyes helyeken a kovetkezo fajok: "<<endl;
        for(int i=0; i<n; ++i)
        {
            cout<<h_f[i]<<" ";
        }
    }
    cout<<endl; //ne folyjanak egymasra a sorok

    return 0;
}

void beolvas(int v[5][20], string h[5], int& n, int&m)
{
    cout << "Adja meg a helyek szamat (n<5 es madarfaj m<20): " << endl;
    cin>>n>>m;

    cout<<"Adjam eg a fajokat az egyes helyeken: "<<endl;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin>>v[i][j];
        }
    }

    cout<<"Adja meg a helysegek neveit: "<<endl;
    for(int i=0; i<n; ++i)
    {
        cin>>h[i];
    }
}

int szamlal(int v[5][20], int h_f[5], int&n, int&m)
{
    for(int i=0; i<n; ++i)
    {
        int db = 0;
        for(int j=0; j<m; ++j)
        {
            if(v[i][j]>0)
            {
                db++;
            }
        }
        h_f[i]=db;
    }
    return n;
}
