#include <iostream>
#include <queue>
using namespace std;

class Solution
{
    public:
        int peopleAwareOfSecret(int n, int delay, int forget) {
            const int M = 1e9 + 7;
            int cur = 0;
            int ans = 1;  // persons who know about secret.
            queue<pair<int, int>> delayQ, forgetQ; // <uss din, kitne new logo ko secret pata laga>
            delayQ.push({1, 1});
            forgetQ.push({1, 1});
            
            for(int i = 1; i <= n; ++i) {
                // step 1: active spreader and person know about secret kam kro
                if(!forgetQ.empty() && forgetQ.front().first + forget <= i) {
                    auto front = forgetQ.front();
                    forgetQ.pop();
                    auto no = front.second;
                    ans = (ans - no + M) % M;
                    cur = (cur - no + M) % M;
                }
        
                // step 2: make new active spreaders
                if(!delayQ.empty() && delayQ.front().first + delay <= i) {
                    auto front = delayQ.front();
                    delayQ.pop();
                    cur = (cur + front.second) % M; // active kar diya
                }
        
                // step 3: spread the secret
                if(cur > 0) {
                    ans = (ans + cur) % M;
                    delayQ.push({i, cur});
                    forgetQ.push({i, cur});
                }
            }
            return ans;
        }
        
};

int main()
{
    int n = 7, delay = 2, forget = 4;
    Solution s1;
    cout << s1.peopleAwareOfSecret(n, delay, forget);
    return 0;
}