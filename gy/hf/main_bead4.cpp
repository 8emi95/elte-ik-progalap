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
	int i = 0; //szakasz elej�nek indexe
	int j = 0; //szakasz v�g�nek indexe
	int seged[MaxN]; //m�sodik sor elemei
	int k = 0; //m�sodik sor elemeinek indexe
	while(i < N)
	{
		j = i + 1;
		if(Adatok[i] <= 800)
		{
			j = i;
			while(j < N && Adatok[j] <= 800) //j a szakasz v�ge, keress�k h meddig kisebb 800-n�l
			{
				j++;
			}
			seged[k] = i+1; //m�sodik sor k-adik elem�nek �rt�ke, szakasz eleje
			k++; //k�vetkez� �rt�ket (szakasz v�ge) �j indexhez �rja, ne �rja fel�l
			seged[k] = j; //m�sodik sor k+1-edik elem�nek �rt�ke, szakasz v�ge
			k++; //k�vetkez� szakasz elej�t �j indexhez �rja
		}
		i = j; //a szakasz eleje (i) a k�vetkez� szakasz v�ge (j) lesz, onnant�l vizsg�ljuk tov�bb a magass�got, a kett� k�z�ttiekr�l tudjuk h foly�szakasz �rt�kei (ez�rt nem l�ptetj�k sim�n)
	}
	cout << k/2 << endl; //els� sor: szakaszok eleje �s v�ge is benne van a k-ban, k fele a szakaszok sz�ma
	for(int i = 0; i < k; ++i)
	{
		cout << seged[i] << " "; //m�sodik sor: szakaszok elej�t �s v�g�t ki�rjuk
	}
	if(k/2 > 1) //csak akkor �rja ki ha min 2 szakasz van
	{
		cout << endl;
		int seged2[N]; //harmadik sor elemei
		int db = 0; //haramdik sor elemeinek indexe
		for(int i = 2; i < k; i++) //3. �rt�kt�l, 2. szakasz elej�t�l vizsg�ljuk
		{
			cout << seged[i]-seged[i-1] << " "; //harmadik sor: k�vetkez� szakasz elej�b�l kivonjuk az el�z� szakasz v�g�t
			seged2[db] = seged[i]-seged[i-1];
			db++; //k�vetkez� t�vols�got �j indexhez �rja
			i++; //m�g egyszer l�ptetj�k h a k�vetkezp szakasz elej�t�l vizsg�lja, k�l�nben az adott szakasz v�g�t n�zn� csak egyszer l�ptetve
		}
		cout << endl;
		int min = 0;
		for(int i = 1; i < db; ++i) //megvizsg�ljuk az egym�s melletti t�vols�gokat
		{
			if(seged2[i] < seged2[min]) //ha pl a 2. t�vols�g kisebb az 1.-n�l (ha k�t legkisebb van, akkor csak az els�t n�zi, mert nme engedj�k meg az egyenl�s�get)
			{
				min = i; //akkor a 2. lesz az eddigi legkisebb
			}
		}
		cout << seged[2*min] << " " << seged[2*min+1] << " "; //els� szakasz: egy szakasz 2 indexet foglal, a p�ros (2*min) az eleje (0-t�l indul), a p�ratlan (2*min+1) a v�ge
		cout << seged[2*min+2] << " " << seged[2*min+3]; //m�sodik szakasz: csak 2 szakaszt �runk ki
	}
}
