// Euclid's Algorithm
#include <iostream>
using namespace std;
class Solution
{
    public:
    int gcd (int A, int B)
    {
        if (A == 0) return B;
        if (B == 0) return A;

        while (A > 0 && B > 0)
        {
            if (A > B)
                A = A - B;
            else 
                B = B - A;

        }
        return A == 0 ? B : A;
    }
};
int main()
{
    Solution s1;
    int a = 3;
    int b = 6;
    cout<<s1.gcd(a, b);
    return 0;
}