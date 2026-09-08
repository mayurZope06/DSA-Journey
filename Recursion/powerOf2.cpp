#include <iostream>
using namespace std;

int pow (int n )
{
    //b(ase case
    if (n == 0)
        return 1;
    
    //recursive relation
    //pow(n) = 2 * pow(n-1)
    int recKaAns = pow (n - 1);
    int finalAns = 2 * recKaAns;
    return finalAns;
}
int main()
{
    cout << pow(10);
    return 0;
}