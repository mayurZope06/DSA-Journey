#include <iostream>
using namespace std;

int fact (int n)
{
    int fact = 1;
    for (int i = 1; i <=n; i++)
    {
        fact = fact * i;
    }
    return fact;
}
int main()
{
    int n;
    cin >> n;

    int ans = fact(n);
    cout << "Factorial of " << n << " is: " <<ans << endl; 
    return 0;
}