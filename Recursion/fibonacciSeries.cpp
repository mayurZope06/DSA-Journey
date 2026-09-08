#include <iostream>
using namespace std;

int fib (int n)
{
    //base case
    if (n == 0 || n == 1)
        return n;

        //recursive relation
        //fib(n) = fib(n-1) + fib(n-2);
        int ans = fib(n - 1) + fib(n - 2);
        return ans;
}
int main()
{
    cout<<fib(9)<<endl;

    return 0;
}
