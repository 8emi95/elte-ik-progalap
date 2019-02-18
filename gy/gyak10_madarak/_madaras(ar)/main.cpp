#include <iostream>
#include <stdlib.h>

using namespace std;

void beolvas (int v[5][20], string h[5], int &, int&);
int szamlal (int v[5][20], int h_f[], int&, int&); //int h_f-be fogjuk betenni azt hogy az egyes helyeken hany fele madarat talaltak
void legtobb_madarfaj (int v[5][20], int& n, int& m, string hely[5]);
int elteresi_index(int v[5][20], int& n, int& m);
void legkisebb_elteresi_index (int v[5][20], int& n, int& m, string hely[5]);


int main()
{
    int n=5, m;
    int t[5][20];
    int h_f[5];
    string hely[5];
    hely[0]="Zirc";
    hely[1]="Szentendrei skanzen";
    hely[2]="Sas-hegy";
    hely[3]="Kis Balaton";
    hely[4]="Margit-sziget";


    beolvas(t, hely, n, m);

    int szam=szamlal (t, h_f, n, m);
    if (szam>0)
    {
        //cout << "a kov fajok: " << endl;
        for(int i=0; i<n; ++i)
            cout << h_f[i]<< " "; //space-el kell hogy legyen elválasztva
    }
    cout<<endl; //nem szabad hogy egymásra folyjanak a sorok

    legtobb_madarfaj (t, n, m, hely);

    int elteres=elteresi_index (t, n, m);
    cout << elteres << endl;

    legkisebb_elteresi_index (t, n, m, hely);



    return 0;

}

void beolvas (int v[5][20], string h[5], int &n, int &m)
{
    cin >> m;


    for (int i=0; i<n; ++i)

    {
        for (int j=0; j<m; ++j)
        {
            cin>> v[i][j];
        }

    }
}

int szamlal (int v[5][20], int h_f[5], int& n, int& m)
{
    for (int i=0; i<n; ++i)

    {
        int db=0;
        for (int j=0; j<m; ++j)
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

void legtobb_madarfaj (int v[5][20], int& n, int& m, string hely[5])
{
    int max=0;
    int helyiseg_index;
    int madarfaj_index;
    for (int i=0; i<n; ++i)

    {
        for (int j=0; j<m; ++j)
        {
            if(v[i][j]>max)
            {
                helyiseg_index=i;
                madarfaj_index=j+1;
                max=v[i][j];
            }
        }
    }
    cout << hely[helyiseg_index] << " ";
    cout << madarfaj_index << endl;
}

int elteresi_index (int v[5][20], int& n, int& m)
{
    int elteres=0;
    for (int i=0; i<m; ++i)
    {
        int e=v[0][i]-v[1][i];
        if (e<0)
            e=e*(-1);
        elteres=elteres+e;
    }
    return elteres;
}

void legkisebb_elteresi_index (int v[5][20], int& n, int& m, string hely[5])
{
    int elso_index=0, masodik_index=1;
    int elteres=v[0][0]-v[1][0];
    if (elteres<0)
        elteres=elteres*(-1); //abszolutertek helyett

    for (int kulso=0; kulso<n; ++kulso)
    {
        for (int belso=0; belso<n; ++belso)
        {
            if (kulso!=belso)
            {
                for (int i=0; i<m; ++i)
                {
                    int t=v[kulso][i]-v[belso][i];
                    if (t<0)
                        t=t*(-1);
                    if (t<elteres)
                    {
                        elteres=t;
                        elso_index=kulso;
                        masodik_index=belso;
                    }
                }

            }
        }
    }
  cout << hely[elso_index] << ", " << hely[masodik_index];
}
