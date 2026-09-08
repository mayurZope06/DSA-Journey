#include <iostream>
#include <queue>
using namespace std;

class RecentCounter
{
    queue<int> q;

    public:
        int ping(int t)
        {
            // 1.
            q.push(t);

            //2. pop invalid req. older, older than t - 3000
            while(!q.empty() && q.front() < (t - 3000))
            {
                q.pop();
            }

            //3.now q has only number of recent calls : R = [ t - 3000, t]
            return q.size();
        }
};

int main()
{
    RecentCounter rc;
    cout << rc.ping(100) << endl;
    cout << rc.ping(3001) << endl;
    cout << rc.ping(3002) << endl;
    return 0;
}