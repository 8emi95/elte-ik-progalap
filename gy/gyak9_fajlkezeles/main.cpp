#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    // a file-neveknek fenntartott valtozok
    string ifname, ofname;

    cout << "Kerem az input file nevet: ";
    cin >> ifname;

    // deklaraljuk a fajl-valtozot
    ifstream infile;

    // megnyitjuk a fajlt
    infile.open(ifname.c_str());

    //Lehetne egyszerre deklaralni es megnyitni:
    //ifstream infile(ifname.c_str());
    //Lehetne igy is:
    //fstream infile;
    //infile.open(ifname.c_str(),ios::in);

    // hibakezeles
    if (infile.fail())
    {
        cout << "Nem tudom olvasasra megnyitni a bemeneti file-t!" << endl;
        exit(1);
    }

    cout << "Kerem az output file nevet: ";
    cin >> ofname;

    // a file-valtozo deklaracioja
    ofstream outfile; //kimenet
    // a kimeneti file megnyitasa
    outfile.open(ofname.c_str());
    //Lehetne egyszerre deklaralni es megnyitni
    //ofstream outfile(ofname.c_str());
    //Lehetne igy is:
    //fstream outfile(ofname.c_str(),ios::out);

    // hibakezeles
    if (outfile.fail())
    {
        cout << "Nem tudom irasra megnyitni a kimeneti file-t!" << endl;
        exit(1);
    }

    // a file-ban talalhato hasznos szamok szama
    int n; //fajlban szamok, elso szam az adatok szama
    // beolvassuk
    infile >> n; //cin helyett infile
    // rogton ki is irjuk
    outfile << n << endl; //cout helyett outfile

    // a tobbi szamot mar ciklussal masoljuk, hiszen tudjuk, nennyi van
    for (int i=0; i<n; ++i)
    {
        int k;
        infile >> k;
        //Ellenorizzuk, hogy nem fogyott-e el ido elott a fajl
        /*
        if (infile.eof()){
            cout<<"A vartnal kevesebb adat van a fajlban!"<<endl;
            exit(1);
        }
        */
        outfile << k << endl;
    }

    // a megnyitott file-ok lezarasaert nem szol a fordito, de kotelezo! maguktol nem zarodnak be
    outfile.close(); //ha ujra akarom futtatni a programot es nincs lezarva akk az utolso entert beolvasasnak veszi
    infile.close();

    return 0;
}
