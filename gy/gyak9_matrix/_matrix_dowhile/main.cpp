#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;


    //2. feladat
    //Adott egy m sorbol es n oszlopbol allo egeszeket tartalmazo matrix egy szoveg fajlban.
    //A fajl elso adata a sorok szama, a masodik az oszlopok szama
    //Ezutan kovetkeznek a matrix sorai, egy sorban a szamokat szokoz valasztja el.
    //Az output fajlba irjuk ki eloszor, hogy hany pozitiv osszegu sora van a matrixnak
    //Majd irjuk ki a pozitiv osszegu sorok sorszamat (1.-tol szamozzuk a sorokat)


int sorosszeg(int v[], int n); //kiszamoljuk, eldontjuk h pozitiv-e

int main()
{

    // a file-neveknek fenntartott valtozok
    string befajl, kifajl;
    //fajlvaltozok
    ifstream bemenet;
    ofstream kimenet;

    bemenet.clear(); //ha ujra akarom futtatni

    cout << "Kerem az input file nevet: ";
    cin >> befajl;
    bemenet.open(befajl.c_str());
    do
    {
        cout << "Nem tudom olvasasra megnyitni a bemeneti file-t!" << endl;
    }while(bemenet.fail());
    /*if (bemenet.fail())
    {
        cout << "Nem tudom olvasasra megnyitni a bemeneti file-t!" << endl;
        exit(1);
    }*/

    cout << "Kerem az output file nevet: ";
    cin >> kifajl;
    kimenet.open(kifajl.c_str());
    do
    {
        cout << "Nem tudom irasra megnyitni a kimeneti file-t!" << endl;
    }while(kimenet.fail());
    /*if (kimenet.fail()) //megnyitas ellenorzes
    {
        cout << "Nem tudom irasra megnyitni a kimeneti file-t!" << endl;
        exit(1);
    }*/

    //elore bekerjuk a sorok/oszlopok szamat, do while legyen - stdlib.h akkor nem kell
    int m,n;
    bemenet>>m>>n;
    do
    {
        cout<<"Helytelen matrix meret!"<<endl;
    }while(m<1 || n<1);
    /*if(m<1 || n<1)
    {
        cout<<"Helytelen matrix meret!"<<endl;
        exit(1);
    }*/

    //matrix deklaralasa
    int t[m][n];

    //matrix beolvasasa
    for(int i=0; i<m; ++i)
    {
      for(int j=0; j<n; ++j)
      {
          bemenet>>t[i][j];
      }
    }

    //kivalogatas - pozitiv osszegu sorok
    int sorok[m], db=0; //itt kell deklaralni
    int s; //sorosszeg fv meghivasa - nem kell kezdoertek mert csak meghivjuk
    for(int i=0; i<m; ++i)
    {
        s=sorosszeg(t[i],n); //meghivjuk a sorokat, tudnia kell hany db oszlop van (n)

        if(s>0)
        {
            sorok[db]=i+1;
            db++;
            cout<<"az "<<i+1<<". sor osszege: "<<s<<endl; //ezt konzolra irja nem a kimeneti fajlba
        }
    }

    kimenet<<db<<" pozitiv osszegu sor volt, az: "; //kiiratjuk a pozitiv sorokat
    for(int i=0; i<db; ++i)
    {
        kimenet<<sorok[i]<<"., ";
    }

    kimenet.close();
    bemenet.close();

    return 0;
}

int sorosszeg(int v[], int n)
{
    int s=0; //masik s
    for(int j=0; j<n; ++j)
    {
        s=s+v[j];
    }
    return s;
}
