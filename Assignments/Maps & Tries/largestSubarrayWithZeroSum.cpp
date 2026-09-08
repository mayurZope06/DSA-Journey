#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
    public:
        int maxLen(int A[], int n)
        {
            unordered_map<int, int> map;
            int csum = 0;
            int ans = 0; // max length of subarray with 0 sum.
            for(int i=0; i<n; ++i){
                
                csum += A[i];
                if(csum == 0){
                    ans = max(ans, i + 1);
                }
                else if(map.find(csum) == map.end()){
                    map[csum] = i;
                }
                else{
                    // map has csum already.
                    ans = max(ans, i - map[csum]);
                }
            }
            return ans;
        }
    };
    

int main()
{
    int A[] = {15,-2, 2, -8, 1, 7, 10, 23};
    int N = sizeof(A) / sizeof(A[0]);
    Solution s1;
    cout << s1.maxLen(A, N) << endl;
    return 0;
}