#include <iostream>

using namespace std;

const int MAXK = 30;
const int MAXN = 366;

void beolvas(int &N,int &K,int &dT, int t[MAXK])
{
    cin >> N >> K >> dT;
    for (int i=0;i<K;++i)
    {
        cin >> t[i];
    }
}

void A_feladat(int &N,int &K,int &dT,int t[MAXK],int &maxi,int napok[MAXN])
{
    for (int i=0;i<N;++i) {
        napok[i]=0;
    }
    for (int i=0;i<K;++i) {
        for (int j=t[i]-dT-1;j<t[i]+dT-1;++j) {
            ++napok[j];
        }
    }
    for (int i=0;i<N;++i) {
        cout << napok[i] << " ";
        if (napok[i]>napok[maxi]) {
            maxi=i;
        }
    }
}

int B_feladat(int &N,int &K,int &dT, int t[MAXK],int &maxi,int napok[MAXN])
{
    int maxdT;
    if (napok[maxi]>1) {
        maxdT=dT-1;
    }
    else {
        maxdT=N/K;
    }
    int napok2[366];
    napok2[maxi]=2;
    while ((napok2[maxi]>1) && (maxdT>0)) {
        for (int i=0;i<N;++i) {
            napok2[i]=0;
        }
        for (int i=0;i<K;++i) {
            for (int j=t[i]-maxdT-1;j<t[i]+maxdT-1;++j) {
                ++napok2[j];
            }
        }
        maxi=0;
        for (int i=0;i<N;++i) {
            if (napok2[i]>napok2[maxi]) {
                maxi=i;
            }
        }
        if (napok2[maxi]>1) {
            --maxdT;
        }
    }
    return maxdT;
}

void C_feladat(int &N,int &K,int &dT,int t[MAXK],int &maxi, int napok[MAXN])
{
    int intdb=0;
    for (int i=0;i<N;++i) {
        if (((i==0) && (napok[i]==0))
            || ((i>0) && (napok[i]==0) && (napok[i-1]!=0))) {
            ++intdb;
        }
    }
    cout << intdb << " ";
    int intkezd=0;
    for (int i=0;i<N;++i) {
        if (((i==0) && (napok[i]==0))
            || ((i>0) && (napok[i]==0) && (napok[i-1]!=0))) {
            intkezd=i;
            cout << intkezd+1 << " ";
        }
        if (((i>0) && (napok[i]!=0) && (napok[i-1]==0))) {
            cout << i << " ";
        }
        else if ((i==N-1) && (napok[i]==0)) {
            cout << i+1 << " ";
        }
    }
}

void D_feladat(int &N,int &K,int &dT,int t[MAXK],int &maxi,int napok[MAXN])
{
    int i=0;
    int balrahely,jobbrahely;
    do {
        if (i==0) {
            balrahely=t[i]-dT-1;
        }
        else {
            balrahely=t[i]-t[i-1]-2*dT;
        }
        if (i<K-1) {
            jobbrahely=t[i+1]-t[i]-2*dT;
        }
        else {
            jobbrahely=N-t[i]-dT+1;
        }
        ++i;
    } while (
        (i<K) &&
        (
         ((balrahely>=0) && (jobbrahely>=0)) ||
         ((balrahely<=0) && (jobbrahely<=0)) ||
         ((balrahely<0) && (balrahely*(-1)>jobbrahely)) ||
         ((jobbrahely<0) && (jobbrahely*(-1)>balrahely))
        )
    );
    if ((i>=K) &&
        (
         ((balrahely>=0) && (jobbrahely>=0)) ||
         ((balrahely<=0) && (jobbrahely<=0)) ||
         ((balrahely<0) && (balrahely*(-1)>jobbrahely)) ||
         ((jobbrahely<0) && (jobbrahely*(-1)>balrahely))
        )) {
        cout << 0;
    }
    else {
        cout << i;
    }
}



int main()
{
    int N,K,dT;
    int t[MAXK];
    int napok[MAXN];
    int maxi = 0;
    beolvas(N,K,dT,t);
    A_feladat(N,K,dT,t,maxi,napok);
    cout << endl;
    cout << B_feladat(N,K,dT,t,maxi,napok) << endl;
    C_feladat(N,K,dT,t,maxi,napok);
    cout << endl;
    D_feladat(N,K,dT,t,maxi,napok);
    cout << endl;
    return 0;
}
