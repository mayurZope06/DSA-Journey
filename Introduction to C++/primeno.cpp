#include <iostream>
using namespace std;
bool isPrime(int number)
{
    for (int i=2; (i<=number-1); i++)
    {
        if (number % i ==0)
        {
        //not a prime
            return false;
        }
    }

    //agar aap yaha tak aagyae ho 
    //iska matlab app prime ho
    return true;
}
int main()
{
    int inp;
    cin>>inp;
    bool ans = isPrime(inp);
    if(ans == true)
    {
        cout<<"Prime";
    }
    else
    {
        cout<<"Not Prime";
    }
    return 0;
}