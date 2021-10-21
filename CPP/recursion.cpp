#include <bits/stdc++.h>
using namespace std;

int fun2(int n)
{
    static int x = 0; //recursion with static variable
    if (n > 0)
    {
        x++;
        return fun2(n - 1) + x;
        //x++;
    }
    return 0;
}

int fun1(int n)
{
    if (n > 0)
    {
        return fun1(n - 1) + n;
    }
    return 0;
}

//funtion calling itself once--> linear recursion
//funtion calling itself more than once--> *tree recursion*
void fun(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        fun(n - 1);
        fun(n - 1);
    } //number of calls = summation of GP -->2^0 + 2^1 + 2^2 +...+ 2^n = 2^(n+1)-1
      // Hence time complexity is O(2^n) space is O(n)
}

//Nested recursion
int funr(int n)
{
    if (n > 100)
        return n - 10;
    else
        return funr(funr(n + 11));
}

//sum of n natural numbers

int sumofn(int n)
{

    if (n != 1)
        return (sumofn(n - 1) + n);
    else
        return 1;
}

//factorial
int fact(int n)
{
    if (n != 0)
        return n * fact(n - 1);
    else
        return 1;
}

//power
int pow(int m, int n)
{
    if (n > 0)
    {
        if (n % 2 != 0)
            return m * pow(m * m, (n - 1) / 2);
        else
            return pow(m * m, n / 2);
    }
    else
        return 1;
}

//Taylor series e^x
//need to use static variable as we can't return multiple values
double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;

    if (n == 0)
        return 1;

    r = e(x, n - 1);
    p *= x;
    f *= n;
    return r + p / f;

    //total O(n^2) multiplications are performed
}

//Taylor series by Horners rule
//O(n) multiplications are performed

double TaylorSeries(int x, int n)
{
    static double r = 1;

    if (n == 0)
        return r;
    r = 1 + (double(x) / n) * r;
    return TaylorSeries(x, n - 1);
}

//Fibbonacci series
int fib_recur(int n)
{
    if (n <= 1)
        return n;
    return fib_recur(n - 1) + fib_recur(n - 2); //excessive recursion
}

int memo[10];

int fib_recur_fast(int n)
{
    if (n <= 1)
    {
        memo[n] = n;
        return n;
    }

    if (memo[n - 1] == -1)
        memo[n - 1] = fib_recur_fast(n - 1);
    if (memo[n - 2] == -1)
        memo[n - 2] = fib_recur_fast(n - 2);
    memo[n] = memo[n - 1] + memo[n - 2];
    return memo[n - 1] + memo[n - 2];
}

int fib_it(int n)
{
    int a = 0, b = 1, s;
    if (n <= 1)
        return n;
    for (int i = 2; i <= n; i++)
    {
        s = a + b;
        a = b;
        b = s;
    }
    return s;
}

//***************************main***********************************

int main()
{
    cout << fib_recur(7) << endl; //O(2^n)
    cout << fib_it(7) << endl;    //O(n)
    for (int i = 0; i < 10; i++)
        memo[i] = -1;
    cout << fib_recur_fast(7) << endl; //O(n)
}

//nCr using recursion

int nCr(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    if (n < r)
        return -1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r); //nCr= n-1Cr + n-1Cr-1
}

//Tower of Hanoi problem
//              from  auxilary  to
void ToH(int n, int a, int b, int c)
{ //a,b,c are tower numbers
    if (n > 0)
    {
        ToH(n - 1, a, c, b);
        cout << a << "->" << c << " | ";
        ToH(n - 1, b, a, c);
    }
    //O(2^n)
}

//back-tracking
//algo to find out all permutation of string if repetition of words is NOT allowed
void perm(char s[], int n)
{
    static char res[4];
    static int flag[4] = {0}; //remove static to find out all permutation if repetition of words is allowed
    int i;
    if (s[n] == '\0')
    {
        res[n] = '\0';
        cout << res << endl;
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (!flag[i])
            {
                res[n] = s[i];
                flag[i] = 1;
                perm(s, n + 1);
                flag[i] = 0;
            }
        }
    }
}

void perm2(string s, int l, int h) //initially l=0,h=size-1;
{
    int i;
    if (l == h)
    {
        cout << s << endl;
    }
    else
    {
        for (i = l; i <= h; i++)
        {
            swap(s[l], s[i]);
            perm2(s, l + 1, h);
            swap(s[l], s[i]);
        }
    }
}
