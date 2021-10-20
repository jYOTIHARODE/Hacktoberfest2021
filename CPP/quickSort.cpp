#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int s, int e)
{
    int piv = arr[e];
    int i = s;
    for (int j = s; j < e; j++)
    {
        if (arr[j] <= piv)
            swap(arr[i++], arr[j]);
    }
    swap(arr[i], arr[e]);

    return i;
}

void quicksort(int arr[], int l, int r)
{
    if (l < r)
    {
        int temp = partition(arr, l, r);
        quicksort(arr, l, temp - 1);
        quicksort(arr, temp + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    quicksort(arr, 0, n - 1); //taking last index as pivot element

    for (auto x : arr)
        cout << x << " ";
    return 0;
}

//code contributed by atharv-bhadange