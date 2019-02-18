#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

void beolvas(string fnev, string nev[], float[], int& db);
bool bennevan(string fnev, string nevek[], int db, int& j);

int main()
{
    //ki érte el a legnagyobb pontszamot a 2 zh-n

    const int maxm = 100;
    string anev[maxm], bnev[maxm];
    float apont[maxm], bpont[maxm];
    int adb, bdb;

    ofstream kimenet;
    //beolvasas;

    beolvas("a.txt", anev, apont, adb);
    beolvas("b.txt", bnev, bpont, bdb);

    //metszet

    string nev02[maxm];

    int db2 = 0;
    int pontmax = 0;
    int pontmaxind = 0;
    for(int i = 0; i < adb; ++i)
    {
        apont[i] = pontmax;
        {
            int j;
            //if(bennevan(anev[i], bnev, bdb,j))
            {
                //if(bpont[j] < 0.5)
                {
                    nev02[db2] = anev[i];
                    db2++;
                }
                //maxker
            }
        }
    }

    kimenet.clear();
    kimenet.open("ki2.txt");

    if(kimenet.fail())
    {
        cout << "Nem tudok irni a fajlba." << endl;
        exit(1);

    }
    kimenet << db2 << endl;
    cout << "Legnagyobb pontszamot elerte: " << db2 << endl;

    for(int i = 0; i < db2; ++i)
    {
        kimenet <<nev02[i] << endl;
        cout << nev02[i] << endl;
    }

    kimenet.close();

    return 0;
}

void beolvas(string fnev, string nev[], float sz[], int& db)
{
    ifstream befile;
    befile.open(fnev.c_str());

    if(befile.fail())
    {
        cout << "Nem tudom olvasni a fajlt: " << fnev << endl;
        exit(1);

    }
    befile >> db;

    for(int i = 0; i < db; ++i)
    {
        befile >> nev[i] >> sz[i];
    }
    befile.close();
}

bool bennevan(string nev, string nevek[], int db, int& j)
{
    for(j = 0; j < db && nev != nevek[j]; ++j);
    return j < db;
}
