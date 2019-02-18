#include<iostream>

using namespace std;

const int MaxN = 10000;

void Beolvas(int Adatok[],int&);
int harmadik(int seged[],int,int seged3[],int&);
int negyedik(int&,int seged3[],int);

int main()
{
	int Adatok[MaxN];
	int N;
	Beolvas(Adatok,N);

	int i = 0; //szakasz elejének indexe
	int j = 0; //szakasz végének indexe
	int seged[MaxN]; //második sor elemei
	int k = 0; //második sor elemeinek indexe
	while(i < N)
	{
		j = i + 1;
		if(Adatok[i] <= 800)
		{
			j = i;
			while(j < N && Adatok[j] <= 800) //j a szakasz vége, keressük h meddig kisebb 800-nál
			{
				j++;
			}
			seged[k] = i+1; //második sor k-adik elemének értéke, szakasz eleje
			k++; //következõ értéket (szakasz vége) új indexhez írja, ne írja felül
			seged[k] = j; //második sor k+1-edik elemének értéke, szakasz vége
			k++; //következõ szakasz elejét új indexhez írja
		}
		i = j; //a szakasz eleje (i) a következõ szakasz vége (j) lesz, onnantól vizsgáljuk tovább a magasságot, a kettõ közöttiekrõl tudjuk h folyószakasz értékei (ezért nem léptetjük simán)
	}
	//első sor
	cout << k/2 << endl; //elsõ sor: szakaszok eleje és vége is benne van a k-ban, k fele a szakaszok száma

	//második sor
	for(int i = 0; i < k; ++i)
	{
		cout << seged[i] << " "; //második sor: szakaszok elejét és végét kiírjuk
	}

	//harmadik sor
	if(k/2 > 1) //csak akkor írja ki ha min 2 szakasz van
	{
		cout << endl;

		int seged3[MaxN]; //harmadik sor elemei
		int db3 = 0; //haramdik sor elemeinek indexe
		harmadik(seged,k,seged3,db3);
		for(int i = 0; i < db3; ++i)
        {
            cout << seged3[i] << " ";
        }
		cout << endl;

    //negyedik sor
		int min = 0;
		negyedik(min,seged3,db3);
		cout << seged[2*min] << " " << seged[2*min+1] << " "; //elsõ szakasz: egy szakasz 2 indexet foglal, a páros (2*min) az eleje (0-tól indul), a páratlan (2*min+1) a vége
		cout << seged[2*min+2] << " " << seged[2*min+3]; //második szakasz: csak 2 szakaszt írunk ki
	}
}

void Beolvas(int Adatok[MaxN],int &N)
{
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		cin >> Adatok[i];
	}
}

int harmadik(int seged[MaxN],int k,int seged3[MaxN],int& db3)
{
    for(int i = 2; i < k; ++i) //3. értéktõl, 2. szakasz elejétõl vizsgáljuk
    {
        seged3[db3] = seged[i]-seged[i-1]; //harmadik sor: következõ szakasz elejébõl kivonjuk az elõzõ szakasz végét
        db3++; //következõ távolságot új indexhez írja
        i++; //még egyszer léptetjük h a következő szakasz elejétõl vizsgálja, különben az adott szakasz végét nézné csak egyszer léptetve
    }
    return db3;
}

int negyedik(int& min,int seged3[],int db3)
{
    for(int i = 1; i < db3; ++i) //megvizsgáljuk az egymás melletti távolságokat
    {
        if(seged3[i] < seged3[min]) //ha pl a 2. távolság kisebb az 1.-nél (ha két legkisebb van, akkor csak az elsõt nézi, mert nem engedjük meg az egyenlõséget)
        {
            min = i; //akkor a 2. lesz az eddigi legkisebb
        }
    }
    return min;
}
