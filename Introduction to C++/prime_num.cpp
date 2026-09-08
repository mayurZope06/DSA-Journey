// To print 1 to N prime numbers

#include <iostream>
#include <math.h>
using namespace std;

bool checkPrime(int num)
{
    // We will check first if Num is prime or not
    if (num<=1)
    {
        return false;
    }

    //Check if Num is divisible by any number between [2,n-1]
    for (int i=2; i<num; i++)
    {
        if ((num%i) == 0)
        {
            // kya ye prime hoga --> nahi
            return false;
        }
    }
    // agar me yaha aagaaya means num is not able to be divided by any num between [2,N-1]
    return true;
}
int main()
{
    int num;
    cout<<"Enter number till you want prime numbers :"<<endl;
    cin>>num;
    
    //loop for displaying prime nos from 1 to n
    for(int i=1; i<=num; i++)
    {
        //let's check if i is prime or not
        bool isPrime = checkPrime(i);

        //if i is prime
        if (isPrime)
        {
            cout<<"prime number:"<<i<<endl;
        }
        else{
            cout<<"Non-prime :"<<i<<endl;
        }
    
    }
    return 0;
}