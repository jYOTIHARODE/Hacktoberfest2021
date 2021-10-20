#include<bits/stdc++.h>
using namespace std;

int main(){
    //declaration
    int A[3][4]; //3rows 4columns
    //or
    int *a[3]; //array of pointers
    //2D array in heap
    //pointers in stack
    a[0]= new int[4]; //row0
    a[1]= new int[4]; //row1
    a[2]= new int[4]; //row2
    //or
    //everything in heap using double pointer

    int **b;
    b= new int*[3];
    b[0]= new int[4]; 
    b[1]= new int[4];
    b[2]= new int[4];

    delete []a;
    delete []b;

    //---input---
    int n,m;
    cin >> n >> m;
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> arr[i][j];
        }
    }
    //---output---
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    ///Spiral order traversal///
    int row_start = 0, col_start = 0, row_end = n-1, col_end = m-1;
    while(row_start<=row_end && col_start<=col_end)
    {
        //for row_start
        for(int col=col_start; col<=col_end; col++)
        {
            cout << arr[row_start][col] << " ";
        }
        row_start++;
    
        //column end
        for(int row=row_start; row<=row_end; row++)
        {
            cout << arr[row][col_end] << " ";
        }
        col_end--;

        //row end
        for(int col=col_end; col>=col_start; col--)
        {
            cout << arr[row_end][col] << " ";
        }
        row_end--;
        
        //column start
        for(int row=row_end; row>=row_start; row--)
        {
            cout << arr[row][col_start] << " ";
        }
        col_start++;
    }

    ////Transpose of Matrix////
    cout << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(j>i)
            {
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    //***************note different input***************
    //Matrix multiplication
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int a[n1][n2];
    int b[n2][n3];

    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i=0; i<n2; i++)
    {
        for(int j=0; j<n3; j++)
        {
            cin >> b[i][j];
        }
    }

    int multi[n1][n3];

    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n3; j++)
        {
            int sum = 0;
            for(int k=0; k<n2; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            multi[i][j] = sum;
            cout << multi[i][j] << " ";
        }
        cout << endl;
    }

//***************note input***************
    //Finding elements
    int target; 
    cin >> target;
    int mat[n][m];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> mat[i][j];
        }
    }
    bool found = false;
    int r = 0, c = n - 1;

    while (r < m && c >= 0) 
    {
    if (mat[r][c] == target) 
        {
            found = true;
        }
        mat[r][c] > target ? c-- : r++;
    }
    if (found)
    cout << "Found";
    else
    cout << "Not Found";

    return 0;
}