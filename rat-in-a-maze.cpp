#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> v;  //This vector is to store the path of the rat , the initial block of this vector is 0 by default and wherever there will be 1's it'll denote the path

bool RatInAMaze(int **arr, int i, int j, int n)
{
    if (i == n - 1 && j == n - 1)  //Ending condition that rat has reached its destination
    {
        return true;
    }
    else if (i < n && j < n)
    {
        if (arr[i][j] != 1)  //1 in maze ill denote that there is a blockage at that path
        {
            bool f = RatInAMaze(arr, i + 1, j, n); // As theere are 2 possible paths first is to go down ie i+1
            bool s = RatInAMaze(arr, i, j + 1, n); // second to go straight which is j+1
            if (f == true)
            {
                v.push_back(make_pair(i + 1, j)); // this condition is to put the right path in above vector
            }
            if (s == true)
            {
                v.push_back(make_pair(i, j + 1)); // same if there is no blockage we'll put that vertex in vector 
            }
            return f | s; // Oring of the result is done to get the atleast one possible true condition , it'll fail only if both the path will be blocked
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int path[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            path[i][j] = 0;
        }
    }
    cout << RatInAMaze(arr, 0, 0, n)<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        int idx = v[i].first;
        int jdx = v[i].second;
        path[idx][jdx] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << path[i][j];
        }
        cout << endl;
    }
}
