#include <iostream>
using namespace std;
void printDigits (int n)
{
    //base case
    if (n == 0)
        return;
    
    int newNum = n / 10;
    printDigits(newNum);

    int digit = n % 10;
    cout<<digit<< " ";
}
int main()
{
    int n = 389;
    printDigits(n);
    return 0;
}