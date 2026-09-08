#include <iostream>
using namespace std;

void printAllDigits(int n)
{
    while (n) // or while (n > 0) // both are same
    {
        int onesPlaceDigit = n % 10;
        cout << "Digit: " << onesPlaceDigit << endl;
        n /= 10;
    }
}

int main()
{
    int n;
    cout << "Enter number to see its digits: " << endl;
    cin >> n;
    printAllDigits(n);
    return 0;
}