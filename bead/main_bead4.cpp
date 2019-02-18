#include<iostream>

using namespace std;

const int MaxN = 10000;

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
	int j = 0;
	int i = 0;
	int seged[MaxN];
	int k = 0;
	while(i < N)
	{
		j = i + 1;
		if(Adatok[i] <= 800 )
		{
			j = i;
			while( j < N && Adatok[j] <= 800)
			{
				j++;
			}
			seged[k] = i+1;
			k++;
			seged[k] = j;
			k++;
		}
		i = j;
	}
	cout << k/2 << endl;
	for(int i = 0; i < k; ++i)
	{
		cout << seged[i] << " ";
	}
	if(k > 3) 
	{
		cout << endl;
		int seged2[N];
		int db = 0;
		for(int i = 2; i < k; i++)
		{
			cout << seged[i]-seged[i-1] << " ";
			seged2[db] = seged[i]-seged[i-1];
			db++;
			i++;
		}
		cout << endl;
		int min = 0;
		for(int i = 1; i < db; ++i)
		{
			if(seged2[i] < seged2[min])
			{
				min = i;
			}
		}
		cout << seged[2*min] << " " << seged[2*min+1] << " ";
		cout << seged[2*min+2] << " " << seged[2*min+3];
	}
}


int main()
{
	int Adatok[MaxN];
	int N;
	Beolvas(Adatok,N);
	Result(Adatok,N);
}