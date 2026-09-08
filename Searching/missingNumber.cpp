#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
    public:
        int missingNumber(vector <int> &arr)
        {
            sort(arr.begin(),arr.end());
            int ansIndex = -1;
            int n = arr.size();

            int s = 0;
            int e = n - 1;
            int mid = s + (e - s) / 2;
            while (s <= e)
            {
                int number = arr[mid];
                int index = mid;
                int diff = number - index;

                if (diff == 0)
                    s = mid + 1;
                else if (diff == 1)
                {
                    ansIndex = mid ;
                    e = mid - 1;
                }

                mid = s + (e - s) / 2;
            }
            if (ansIndex == -1)
                return n;
                
            return ansIndex;
            

        }
};
int main()
{
    vector <int> arr {0, 1, 3, 4};
    Solution s1;
    int ans = s1.missingNumber(arr);
    cout<<"Missing Number: "<<ans<<endl;

    return 0;

}