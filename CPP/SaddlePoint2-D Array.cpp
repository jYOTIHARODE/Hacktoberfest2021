#include<iostream>
using namespace std;
int main(){
int row,col;
cout<<"Enter number of rows: "<<endl;
cin>>row;
cout<<"Enter number of columns: "<<endl;
cin>>col;
int A[row][col];
cout<<"Enter the elements(row wise): "<<endl;
for(int i=0;i<row;i++){
for(int j=0;j<col;j++){
cin>>A[i][j];
}
}
cout<<"Entered matrix: "<<endl;
for(int i=0;i<row;i++){
for(int j=0;j<col;j++){
cout<<A[i][j]<<" ";
}
cout<<endl;
}
bool flag;
for(int i=0;i<row;i++){
int min_row=A[i][0],col_ind=0;
for(int j=1;j<col;j++){
if(min_row > A[i][j]){
min_row=A[i][j];
col_ind=j;
}
}
int k;
for(k=0;k<row;k++)
if(min_row < A[k][col_ind])
break;
if (k == row)
{
cout << "Value of Saddle Point: " << min_row;
flag=true;
}
}
if(flag!=true){
cout<<"Saddle point not present.";
}
return 0;
}