#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
    public:
        int findPairs(long long a[], long long n)
        {
            unordered_map<int, bool> map;

            //pairs
            for(int i = 0; i < n; i++)
            {
                for(int j = i + 1; j < n; j++)
                {
                    int sum = a[i] + a[j];
                    
                    if(map.find(sum) != map.end())
                    {
                        return true;
                    }
                    else
                    {
                        map[sum] = true;
                    }
                }
            }
            return false;
        }
};

int main()
{
    long long a[] = {3, 4, 7, 1, 2, 9, 8};
    long long n = sizeof(a)/sizeof(a[0]);

    Solution s1;
    cout << s1.findPairs(a, n);
    return 0;
}