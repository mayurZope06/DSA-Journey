#include <iostream>
using namespace std;

bool checkPrime(int n)
{
    int i = 2;
    for(i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    bool isPrime = checkPrime(n);
    if(isPrime)
    {
        cout << "Prime.\n";
    }
    else
    {
        cout << "Not a prime.\n";
    }
    return 0;
}