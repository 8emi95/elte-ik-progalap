#include<iostream>

using namespace std;

const int MaxN = 10000;

void Beolvas(int Adatok[],int&);
void Result(int Adatok[],int);

int main()
{
	int Adatok[MaxN];
	int N;
	Beolvas(Adatok,N);
	Result(Adatok,N);
}

void Beolvas(int Adatok[MaxN],int &N)
{
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		cin >> Adatok[i];
	}
}

void Result(int Adatok[MaxN],int N)
{
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
	cout << k/2 << endl; //elsõ sor: szakaszok eleje és vége is benne van a k-ban, k fele a szakaszok száma
	for(int i = 0; i < k; ++i)
	{
		cout << seged[i] << " "; //második sor: szakaszok elejét és végét kiírjuk
	}
	if(k/2 > 1) //csak akkor írja ki ha min 2 szakasz van
	{
		cout << endl;
		int seged2[N]; //harmadik sor elemei
		int db = 0; //haramdik sor elemeinek indexe
		for(int i = 2; i < k; i++) //3. értéktõl, 2. szakasz elejétõl vizsgáljuk
		{
			cout << seged[i]-seged[i-1] << " "; //harmadik sor: következõ szakasz elejébõl kivonjuk az elõzõ szakasz végét
			seged2[db] = seged[i]-seged[i-1];
			db++; //következõ távolságot új indexhez írja
			i++; //még egyszer léptetjük h a következp szakasz elejétõl vizsgálja, különben az adott szakasz végét nézné csak egyszer léptetve
		}
		cout << endl;
		int min = 0;
		for(int i = 1; i < db; ++i) //megvizsgáljuk az egymás melletti távolságokat
		{
			if(seged2[i] < seged2[min]) //ha pl a 2. távolság kisebb az 1.-nél (ha két legkisebb van, akkor csak az elsõt nézi, mert nme engedjük meg az egyenlõséget)
			{
				min = i; //akkor a 2. lesz az eddigi legkisebb
			}
		}
		cout << seged[2*min] << " " << seged[2*min+1] << " "; //elsõ szakasz: egy szakasz 2 indexet foglal, a páros (2*min) az eleje (0-tól indul), a páratlan (2*min+1) a vége
		cout << seged[2*min+2] << " " << seged[2*min+3]; //második szakasz: csak 2 szakaszt írunk ki
	}
}
