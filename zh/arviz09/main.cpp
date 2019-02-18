#include <iostream>

using namespace std;

const int maxN = 10000; //maximum meresi pont
const int maxA = 3000; //maximum meresi eredmeny

struct Arviz
{
    int kezd, veg;
};

struct Csucspont
{
    int index, meres;
};

void beolvas_konzol(int meresek[],  int & N);
int intervallum_keres(int meresek[], const int N, Arviz szakasz[]); //arvizi szakaszok szamaval ter vissza
void kiir_Arviz(Arviz t[], int N);
void csucspontok(const int meresek[], const int N, const Arviz szakasz[], const int szakasz_n,  Csucspont csucsok[]); //ahany szakasz, annyi csucspont
int max_intervallumban(const int meresek[], const int N, int tol, int ig); //maximum kereses egy tomb intervallumaban
void kiir_Csucsok(Csucspont t[], int N);

int main()
{
    int meresek[maxN];
    int N, szakasz_N;
    Arviz szakasz[maxN+1];
    Csucspont csucsok[maxN+1];

    beolvas_konzol(meresek, N);

    szakasz_N = intervallum_keres(meresek, N, szakasz);
    cout << szakasz_N << endl;

    kiir_Arviz(szakasz, szakasz_N);

    csucspontok(meresek, N, szakasz, szakasz_N, csucsok);
    kiir_Csucsok(csucsok, szakasz_N);
}

void beolvas_konzol(int meresek[],  int & N)
{
    //clog<< "Add meg N-t!\n"; //(cout helyett) clog=consol log, nem latja biro, nem standard kimenet
    cin >> N;
    for (int i=0; i<N; i++)
    {
        //clog << "Add meg " << i+1 << ". meresi eredmenyt: ";
        cin >> meresek[i];
    }
}

int intervallum_keres(int meresek[], const int N, Arviz szakasz[])
{
    int elsofok = 800;
    int db = 0;
    int j;
    for (int i = 0; i < N; i++)
    {
        if ((i == 0 && meresek[i] > elsofok) || (i > 0 && meresek[i] > elsofok && meresek[i-1] < elsofok))
        {
            szakasz[db].kezd = i;
            j = i;
            while(j < N && meresek[j] > elsofok)
            {
                j++;
            }
            szakasz[db].veg = j-1;
            db++;
            //i = j-i;
        }
    }
    return db; //arvizi szakaszok szama
}

void kiir_Arviz(Arviz t[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << t[i].kezd + 1 << " " << t[i].veg + 1 << " ";
    }
    if (N > 0)
    {
        cout << endl;
    }
}

void csucspontok(const int meresek[], const int N, const Arviz szakasz[], const int szakasz_n, Csucspont csucsok[])
{
    int maxind, maxertek;
    int db = 0;
    for (int i = 0; i < szakasz_n; i++)
    {
        maxind = max_intervallumban(meresek, N, szakasz[i].kezd, szakasz[i].veg);
        maxertek = meresek[maxind];
        csucsok[db].index = maxind + 1;
        csucsok[db].meres = maxertek;
        db++;
    }
}

int max_intervallumban(const int meresek[], const int N, int tol, int ig)
{
    if (tol < 0 || ig > N)
    {
        return -1;
    }

    int index = tol;
    for (int i = tol + 1; i <= ig; i++)
    {
        if (meresek[index] < meresek[i])
        {
            index = i;
        }
    }
    return index;
}

void kiir_Csucsok(Csucspont t[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << t[i].index << " " << t[i].meres << " ";
    }
     if (N > 0)
     {
         cout << endl;
     }
}
