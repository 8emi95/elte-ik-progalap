#include <iostream>

using namespace std;

int main()
{
    //int egesz[5] = {3, 21, 8, 27, 48};

    //statikus helyfoglal�s� t�mb
    const int max_m = 100; //max m�ret, konstans - fut�si id�ben nem v�ltoztathat rajta a program
    int v[max_m]; //100 lesz a t�mb m�rete
    int n; //db
    do
    {
        cout << "adja meg a tomb elemszamat (1 es " << max_m << " kozott): ";
        cin >> n;
        //cout << "" << endl; //if, amivel megvizsg�lom h n j�-e
    }while (n <= 1 || n > max_m);
    cout << "adja meg a tomb elemeit: " << endl;
    for (int i = 0; i < n; ++i) //0t�l n-1ig megy
    {
        cout << i + 1 << ". elem: ";
        cin >> v[i];
    }
    //t�mb elemeinek ki�rat�sa
    for (int i = 0; i < n; ++i)
    {
        cout << v[i] << ", ";
    }
    cout << v[n-1] << ";" << endl;

    return 0;
}
