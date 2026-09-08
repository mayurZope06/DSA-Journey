#include <iostream>
using namespace std;
double BSPrecision (int n)
{
    double s = 0;
    double e = n;
    double ans = 0;
    while ((e - s) > 0.000000001)
    {
        double mid = (s + e) / 2;
        double sqr = mid * mid;
        if (sqr <= n)
        {
            ans = mid;
            s = mid + 0.000000000000000000000000001;
        }
        else    
            e = mid - 0.000000000000000000000000001;
    }
    return ans;
}
int main()
{
    int n = 63;
    double ans = BSPrecision (n);
    printf("Precison Sqrt: %.9f \n", ans);

    return 0;
}