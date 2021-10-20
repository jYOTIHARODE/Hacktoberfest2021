#include<iostream>//recursion
using namespace std;
int fun(int n)
{
  if(n>0)
  {
    return fun(n-1)+n;
  }
  return 0;
}
int main()
{
  int a=5;
  cout<<fun(a);
}

#include<iostream>//static recursion
using namespace std;
int fun(int n)
{ static int x=0;
  if(n>0)
  { 
    x++;
    return fun(n-1)+x;
  }
  return 0;
}
int main()
{
  int a=5;
  cout<<fun(a);
  return 0;
}

//tree recursion
#include<iostream>
using namespace std;
void fun(int n)
{
  if(n>0)
  {
    cout<<n<<" ";
    fun(n-1);
    fun(n-1);//function is called more than once in a single loop
  }
  
}
int main(){
  fun(3);
  return 0;
}

//indirect recursion
#include<iostream>
using namespace std;
void funB(int n);//function prototype (in this case funB had to be mentioned first)
void funA(int n)
{
  if(n>0)
  {
    cout<<n<<endl;
    funB(n-1);
  }
}
void funB(int n)
{
  if(n>1)
  {
    cout<<n<<endl;
    funA(n/2);
  }
}
int main()
{
  funA(20);
  return 0;
}

//nested recursion
#include<iostream>
using namespace std;
int fun(int n)
{
  if(n>100)
  {
    return(n-10);
  }
  else 
  {
    return fun(fun(n+11));//nested function calling itself
  }
}
int main(){
  int t;
  t=fun(95);
  cout<<t<<endl;
}

//recursive function to find out the sum of first n natural numbers
//sum(n)=sum(n-1)+n
#include<iostream>
using namespace std;
int sum(int n)
{
  if(n==0)
  {
    return 0;
  }
  else
  {
    int t;
    t=sum(n-1)+n;//make a recursive call
    return t;
  }
}  
int main()
{
  int total;
  total=sum(5);
  cout<<total;
  return 0;
}

//to find factorial of a number using recursion
#include<iostream>
using namespace std;
int fact(int n)
{
  if(n==1 || n==0)
  {
    return 1;
  }
  else
  {
    int t;
    t=n*fact(n-1);
    return t;
  }
}
int main()
{
  int result;
  result=fact(5);
  cout<<result;
  return 0;
}

// recursion using power function
#include<iostream>
using namespace std;
int power(int m,int n)
{
  if(n==0)
  {
    return 1;
  }
  else
  {
    return power(m,n-1)*m; //recursive call
  }
}
int main()
{
  int t;
  t=power(2,9);
  cout<<t;
  return 0;
}

//implementing taylor series using recursion
#include<iostream>
using namespace std;
double e(int x, int n)
{
  static double p=1,f=1;
  double r;
  if(n==0)
  {
    return 1;
  }
  r=e(x,n-1);
  p=p*x;
  f=f*n;
  return r+p/f;
}
int main()
{
  cout<<e(1,10);
  return 0;
}
