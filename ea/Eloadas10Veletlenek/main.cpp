//név: Gipsz Jakab
//ETR-azonosító: GIJAAFT.ELTE
//drótposta-cím: Gibs@elte.hu
//Feladat:
//  Véletlen tesztadatok generálása fájlba, a "tengeres" feladatokhoz.
//Specifikáció:
//  Be: N ELEME EGÉSZ [tesztadatok száma]
//      NEu,NAm ELEME EGÉSZ [Európára, Amerikára esõ mérési adatok "várható" száma]
//      PSzig ELEME VALÓS [szigetre esés valószínûsége]
//      MaxMag ELEME EGÉSZ [a generálható legnagyobb magasság]
//  Ki: Mag ELEME TÖMB[1..N:EGÉSZ]
//  Ef: NEu,NAm>=1 ÉS N>=NEu+NAm ÉS
//      PSzig ELEME [0..1) ÉS
//      MaxMag>0
//  Uf: Mag[1],Mag[N] ELEME [1..MaxMag] ÉS
//      LÉTEZIK eu ELEME [1..NEu]: LÉTEZIK am ELEME [1..NAm]:
//         BÁRMELY i ELEME [1..eu]: Mag[i] ELEME [1..MaxMag] ÉS Mag[eu+1]=0 ÉS
//         BÁRMELY i ELEME [N-am+1..N]: Mag[i] ELEME [1..MaxMag] ÉS Mag[am-1]=0 ÉS
//         BÁRMELY i ELEME [eu+1..N-am]: Mag[i] ELEME [0..MaxMag]
//  Megjegyzés: nem foglalkoztunk valószínûségi elvárásokkal!

#include <iostream>
#include <fstream>
//#include <time.h>//csak a 'srand(time(NULL))' rand()-inicializáláshoz kell!
#include <stdlib.h>//Code::Blocks 10.05-höz már kell a system kedvéért

using namespace std;

//Paraméterbeolvasás:
//beolvassa a mnN..mxN közötti egész számot (mxN<mnN => végtelen)
void be_int(string kerd, int &n, int mnN, int mxN, string uz);
//beolvassa a mnN..mxN közötti valós számot (mxN<mnN => végtelen)
void be_float(string kerd, float &x, float mnN, int mxN, string uz);
//Fájlba generálás:
void fajlbaGeneralas(string fN, int n, int nEu, int nAm, float pT, int mxM);
void billentyureVar();

int main()
{
    //Bemenet:
    int N,NEu,NAm,MaxMag;
    float PSzig;
    //Kimenet:
    const string fN="tenger.csv";//kimeneti fájl neve

    //srand(time(NULL));//rand()-inicializáláshoz kell!
    //adatok beolvasása:
    be_int("Europai pontok (varhato) szama",NEu,1,0,"Hibas termeszetes szam!");
    be_int("Amerikai pontok (varhato) szama",NAm,1,0,"Hibas termeszetes szam!");
    be_int("Meresi pontok szama",N,NEu+NAm,0,"Hibas termeszetes szam!");
    be_float("Tengeri pontok valoszinusege",PSzig,0,1,"Hibas valos szam!");
    be_int("Legnagyobb magassag",MaxMag,1,0,"Hibas termeszetes szam!");

    //a lényeg:
    fajlbaGeneralas(fN,N,NEu,NAm,PSzig,MaxMag);

    billentyureVar();
    return 0;
}

//Fájlba generálás:
void fajlbaGeneralas(string fN, int n, int nEu, int nAm, float pT, int mxM)
//Uf: N sorban, soronként egyetlen 0..mxM közötti egész szám ...
//    l. még a fenti Uf-t
{
    ofstream oF(fN.c_str());
    int eu=rand()%nEu+1;//Európa hossza
    int am=rand()%nAm+1;//Amerika hossza
    for(int i=1;i<=eu;++i)
    {
      oF << rand()%mxM+1 << endl;
    }
    //TODO: lehet, h. Európának még nincs vége!
    for(int i=eu+1;i<=n-am;++i)
    {
      if (rand()/(RAND_MAX+1.0)<pT)
      {
        oF << rand()%mxM+1 << endl;
      }
       else
      {
        oF << 0 << endl;
      }
    }
    //TODO: lehet, h. Amerika már elkezdõdött!
    for(int i=n-am+1;i<=n;++i)
    {
      oF << rand()%mxM+1 << endl;
    }
    oF.close();
}

//beolvassa a mnN..mxN közötti egész számot (mxN<mnN => végtelen)
void be_int(string kerd, int &n, int mnN, int mxN, string uz)
{
    bool hiba;
    string tmp;

    do{
      if (mxN>=mnN)
      {
        cout << kerd << " (" << mnN << ".." << mxN << "):"; cin >> n;
        hiba=cin.fail() || n<mnN || n>mxN;
      }
        else
      {
        cout << kerd << " (" << mnN << "..):"; cin >> n;
        hiba=cin.fail() || n<mnN;
      }
      if (hiba)
      {
        cout << uz << endl;
        cin.clear(); getline(cin,tmp,'\n');
      }
    }while(hiba);
}

//beolvassa a mnN..mxN közötti valós számot (mxN<mnN => végtelen)
void be_float(string kerd, float &x, float mnN, int mxN, string uz)
{
    bool hiba;
    string tmp;

    do{
      if (mxN>=mnN)
      {
        cout << kerd << " (" << mnN << ".." << mxN << "):"; cin >> x;
        hiba=cin.fail() || x<mnN || x>mxN;
      }
        else
      {
        cout << kerd << " (" << mnN << "..):"; cin >> x;
        hiba=cin.fail() || x<mnN;
      }
      if (hiba)
      {
        cout << uz << endl;
        cin.clear(); getline(cin,tmp,'\n');
      }
    }while(hiba);
}

void billentyureVar()
{
    system("pause");
}
