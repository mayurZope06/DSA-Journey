#include <iostream>
using namespace std;

int getSum (int n)
{
    //base case 
    if (n == 1)
        return 1;
    
    //recursive relation
    //sum(n) = getSum (n - 1) + n;
    int ans = getSum(n - 1) + n;
    return ans;

}
int main()
{
    cout<<getSum(5);
    return 0;
}