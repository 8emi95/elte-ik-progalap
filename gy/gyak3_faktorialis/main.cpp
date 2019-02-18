#include <iostream>

using namespace std;

int main()
{
    int64_t fakt = 1;
    cout << "Kerek egy szamot: " << endl;
    cin >> fakt;
    int k = 15;
    for (int i = 2; i <= k; ++i)
    {
        fakt *= i;
    }
    cout << fakt << endl;
    return 0;
}
