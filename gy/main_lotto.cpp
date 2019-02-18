#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    const int maxm=100;
    int talal[maxm];
    int nyer[maxm];
    int kik[maxm];

    int db;

    cout<<"Add meg a darabszamot: "<<endl; //bironal ki kell kommentezni
    cin>>db;
    cout<<"Add meg a talaltok szamat es a nyeremenyeket: "<<endl; //kikommentezni
    for(int i=0;i<db;++i)
    {
        cin>>talal[i]>>nyer[i];
    }

    //kik nyertek 100e ft-nal tobbet
    int s=0;
    for(int i=0; i<db; ++i)
    {
        if(nyer[i]>=100000)
        {
            s++;
        }
    }
    cout<<s<<endl;

    //volt-e 5 talalatos, ha igen, az elsot irjuk ki (hanyadik), ha nem volt, -1-et kell irni
    int ember;
    int i=0;
    while((i<db) && (talal[i] != 5))
    {
        ++i;
    }
    if(i<db)
    {
        ember=i+1;
    }
    else
    {
        ember=-1;
    }
    cout<<ember<<endl;

    //kik nem nyertek semmit
    int dbc=0;
    for(int i=0; i<db; ++i)
    {
        if(talal[i]==0)
        {
            kik[dbc]=i+1;
            ++dbc;
        }
    }
    cout<<dbc<<" ";
    for(int i=0; i<dbc; ++i)
    {
        cout<<kik[i]<<" ";
    }

    return 0;
}
