#include <iostream>
#include <stdlib.h>

using namespace std;

struct Benzinkut
{
    int Tavolsag;
    int Tankolt;
};

int main()
{
    //alapadatok beolvasása
    int UtHossza;
    int TankolasokSzama;
    int Benzin;
    int Fogyasztas;

    cin >> UtHossza >> TankolasokSzama >> Benzin >> Fogyasztas;

    Benzinkut Kutak[TankolasokSzama];
    for (int i = 0; i < TankolasokSzama; i++)
    {
        Benzinkut kut;
        cin >> kut.Tavolsag >> kut.Tankolt;
        Kutak[i] = kut;
    }

    //a) mennyi benzin lesz az út végén
    int BenzinMennyiseg = Benzin - ((UtHossza / 100) * Fogyasztas);
    for (int i = 0; i < TankolasokSzama; i++)
    {
        BenzinMennyiseg = BenzinMennyiseg + Kutak[i].Tankolt;
    }
    cout << BenzinMennyiseg << endl;

    //b) hány literes az üzemanyagtartály [Gyakorlatilag maximumkeressuk minden idopillanatban (egyszerusitve minden tankolas UTAN) az aktualis benzin mennyiseget]
    int tartaly = Benzin; // Alapbol biztosan volt benne valamennyi
    int aktualisUzemanyag = Benzin;
    int aktualisTavolsag = 0;
    for (int i = 0; i < TankolasokSzama; i++)
    {
        int haladt = Kutak[i].Tavolsag - aktualisTavolsag;
        aktualisTavolsag = Kutak[i].Tavolsag;
        int fogyaszt = Fogyasztas * (haladt / 100); // Elhasznaltunk annyi benzint, amennyi a ket kut kozotti tavolsagnak kell
        aktualisUzemanyag = aktualisUzemanyag - fogyaszt + Kutak[i].Tankolt; // Beletankoltunk annyit, amennyit
        if (aktualisUzemanyag > tartaly)
        {
            tartaly = aktualisUzemanyag;
        }
    }
    cout << tartaly << endl;

    //c) legkorábbi benzinkút száma, amikor már nem kellett volna tankolni
    int benzinMenny = Benzin; // Alapbol volt benzinunk
    // Minden benzinkutra kiszamoljuk, hogy annal a benzinkutnal mennyi uzemanyagunk van
    int aktTav = 0;
    int KutSorszam = 0; // Kimeneti valtozo

    if ((Fogyasztas * (UtHossza / 100)) <= Benzin) // Ha a kezdeti benzinnel eljutnank a celba, akkor nem kellett volna sehol se tankolni. A kutsorszam-ot 0-n hagyjuk
    {
        KutSorszam = 0;
    }
    else
    {
        for (int i = 0; i < TankolasokSzama; i++)
        {
            int tavolsagKulonbseg = Kutak[i].Tavolsag - aktTav;
            aktTav = Kutak[i].Tavolsag;
            benzinMenny = benzinMenny - (Fogyasztas * (tavolsagKulonbseg / 100) ) + Kutak[i].Tankolt; // A benzinMenny az aktualis (i-edik) kutrol indulva letezo benzin mennyisege
            // Akkor elegendo ennel a kutnal tankolni (es utana mar sehol mashol), ha innen a meglevo uzemanyaggal celba ertunk volna
            int tavolsagACelig = UtHossza - aktTav;
            int fogyasztasACelig = Fogyasztas * (tavolsagACelig / 100);
            if (fogyasztasACelig <= benzinMenny) // Ettol a kuttol eljutunk a celpontba
            {
                KutSorszam = i + 1; // +1 indexkonverzio (ez lassan olyan lesz mint Mosi tenzoroperacio-maniaja XD), mivel i nullatol szamoz
                break; // Eljutnank a celig, minek vizsgalni tovabb...
            }
        }
    }
    cout << KutSorszam << endl;

    //d) mely benzinkutaknál lett több a benzin, mint az elõzõ tankolás után
    int aktuBenzin = Benzin;
    int aktuTav = 0;
    int elozoTankolasBenzinje = Benzin;
    int Db = 0;
    int JoKutakIndexei[TankolasokSzama];
    for (int i = 0; i < TankolasokSzama; i++)
    {
        int tavolsagKulonbseg = Kutak[i].Tavolsag - aktuTav;
        aktuTav = Kutak[i].Tavolsag;
        aktuBenzin = aktuBenzin - (Fogyasztas * (tavolsagKulonbseg / 100) ) + Kutak[i].Tankolt; // aktuBenzin: a jelenlegi (i-dik) kuton torteno tankolas utani mennyiseg
        if (aktuBenzin > elozoTankolasBenzinje) // Melyik benzinkutnal lett TOBB a benzin, mint amennyi az ELOZO tankolas UTAN volt. Tehat ha most tobb van benne, mint amennyivel az elozo kutrol indult, akkor az aktualis kut jo.
        {
            JoKutakIndexei[Db] = i;
            Db++;
        }
        elozoTankolasBenzinje = aktuBenzin; // a kovetkezo ciklusmagra "kimentjuk" az aktualis indulo uzemanyag-mennyiseget
    }
    cout << Db;
    for (int i = 0; i < Db; i++) // Kiirjuk az osszes jo kut azonositojat
    {
        cout << " " << (JoKutakIndexei[i] + 1); // +1, mivel ott index volt tarolva (0-tol), de nekunk sorszam kell (1-tol)
    }
    cout << endl;

    //e) leghosszabb olyan 2 benzinkút közötti szakasz hossza, amikor a benzin folyamatosan a kezdeti benzinmennyiség, vagy annál több volt
    /*
    Elindulunk egy kuttol... elkezdjuk nezni attol a kuttol az osszes tovabbi kutig a benzin mennyiseget
    Ha a kuttol kezdve egy kutnal mar Benzin ala csokken, kilepunk es elmentjuk a tavolsagat a szakasznak
    Majd a kovetkezo kuttol vizsgaljuk ugyanigy...
    */
    int kezdo = 0;
    int maxTavolsag = 0;
    while (kezdo < (TankolasokSzama - 1)) // TankolasokSzama - 1, mivel az utolso kuttol felesleges ujabb szakaszt inditani
    {
        int benzinKezdopontban = Benzin; // Kiszamoljuk a benzin mennyiseget a kezdopontban
        int aktuTav = 0;
        for (int i = 0; i <= kezdo; i++)
        {
            int tavolsagKulonbseg = Kutak[i].Tavolsag - aktuTav;
            aktuTav = Kutak[i].Tavolsag;
            benzinKezdopontban = benzinKezdopontban - (Fogyasztas * (tavolsagKulonbseg / 100) ) + Kutak[i].Tankolt;
        }
        if (benzinKezdopontban < Benzin)
        {
            kezdo++;
            continue;
        }
        int utolso = kezdo + 1;
        while (utolso < TankolasokSzama)
        {
            /*
            Elkezdem egyesevel nezni a ket kut kozott a benzin mennyiseget
            Kiszamoljuk mennyi benzin van az autoban a kutra erkezeskor
            A kezdo pontban aktuTav km-re voltunk az utazas kezdetetol
            */
            int ketKutTavolsaga = Kutak[utolso].Tavolsag - Kutak[kezdo].Tavolsag;
            int fogyaszt = Fogyasztas * (ketKutTavolsaga / 100); // ennyit fogyasztottunk
            int tankol = 0;
            for (int i = kezdo + 1; i < utolso; i++) // Ennyi tankoltunk osszesen a ket kut kozott
            {
                tankol += Kutak[i].Tankolt;
            }

            if ((benzinKezdopontban - fogyaszt + tankol) < Benzin) // Nem jo, lephetunk a kovetkezo KEZDO kutra
            {
                break; // Ez kinyirja az utolso-t leptetgeto while ciklust
            }
            else // Ha nem lett kevesebb benzinunk beerkezeskor, mint a kezdeti, akkor ez a szakasz meg jo. (Es ilyekor csak a kovetkezo szakasz-zaro kutra lepunk.)
            {
                // Kiszamoljuk a ket kut tavolsagat es megnezzuk az nagyobb-e, mint az ismert ket leghosszabb szakasz hossza (A kiszamolast par sorral feljebb a ketKutTavolsaga valtozoban megtettuk)
                if (ketKutTavolsaga > maxTavolsag)
                {
                    maxTavolsag = ketKutTavolsaga;
                }
                // Barmi is legyen az if kimenete, itt csak az utolsot leptetjuk, hiszen meg vizsgalhatunk tovabbi szakaszokat
            }
            utolso++;
        }
        kezdo++;
    }
    cout << maxTavolsag << endl;

    return 0;
}
