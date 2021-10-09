#include <iostream>
using namespace std;
int main()
{
    int r, i, j, k = 1;
    cin >> r;
    k = r - 1;
    for (j = 1; j <= r; j++)
    {
        for (i = 1; i <= k; i++)
        {
            cout << " ";
        }
        k--;
        cout << "*";
        for (i = 2; i < 2 * j - 1; i++)
        {
            cout << " ";
        }
        if (j > 1)
            cout << "*";
        cout << endl;
    }
    k = 1;
    for (j = 1; j <= r - 1; j++)
    {
        for (i = 1; i <= k; i++)
        {
            cout << " ";
        }
        k++;
        cout << "*";
        for (i = 2; i < 2 * (r - j) - 1; i++)
        {
            cout << " ";
        }
        if (j < r - 1)
            cout << "*";
        cout << endl;
    }
}