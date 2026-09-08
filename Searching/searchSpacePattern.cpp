#include <iostream>

using namespace std;
class Solution
{
    public:
        int mySqrt(int x)
        {
            int s = 0;
            int e = x;
            long long int mid = s + (e-s) / 2;
            int ans = -1;

            while (s <= e)
            {
                long long int product = mid * mid ;
                if (product == x)
                    return mid;
                if (mid * mid < x)
                {
                    ans = mid;
                    s = mid + 1;
                }
                else{
                    e = mid - 1;
                }
                mid = s + (e - s) / 2;
            }
            return ans;
        }
};
int main()
{
    int x;
    cout<<"Enter a number to find its Sqrt: "<<endl;
    cin>>x;

    Solution s;
    int result = s.mySqrt(x);
    cout<<"Sqrt of "<<x<<" is: "<<result<<endl;
    return 0;
}