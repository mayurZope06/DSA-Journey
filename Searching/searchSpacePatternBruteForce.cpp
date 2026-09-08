#include <iostream>
using namespace std;
int mySqrt(int n)
{
    int s= 0;
    int e = n;
    int ans =0;
    while (s <= e)
    {
        int mid = (s + e) >> 1;
        if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e =mid - 1;
        
    }
    return ans;
}
double myPrecisionSqrt(int n)
{
    double sqrt = mySqrt(n);
    int precision = 13;
    double step = 0.1;
    while (precision--)
    {
        double j = sqrt;
        while (j*j <= n)
        {
            sqrt = j;
            j += step;
        }
        step /= 10;
    }
    return sqrt;
}
int main()
{
    int  n = 63;
    double ans = myPrecisionSqrt(n);
    printf("Precision Sqrt: %.13f \n", ans);

    return 0;
}
