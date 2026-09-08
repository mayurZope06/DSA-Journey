#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int sumofmimmaxofallwindowofsizek(vector<int> nums, int k)
{
    deque<int> dq, dq2;
    int ans = 0;
    
    //first window of k size
    for(int i = 0; i < k; i++)
    {
        //chota element remove krde

        while(!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        //bada element remove krdo
        while(!dq2.empty() && nums[i] <= nums[dq2.back()])
        {
            dq2.pop_back();
        }

        //inserting index, so we can checkout of window element
        dq.push_back(i);
        dq2.push_back(i);
    }
    ans += nums[dq.front()] + nums[dq2.front()];

    //remaining windows ko process
    for(int i = k; i < nums.size(); i++)
    {
        //out of window element ko remove krdala
        if(!dq.empty() && dq.front() < i - k + 1) // or if(!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        if(!dq2.empty() && dq2.front() < i - k + 1) // or if(!dq2.empty() && i - dq2.front() >= k)
        {
            dq2.pop_front();
        }

        //ab firse current element k liye chhote lement ko remove krrna hai
        while(!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }

        while(!dq2.empty() && nums[i] <= nums[dq2.back()])
        {
            dq2.pop_back();
        }

        //inserting index, so that we can checkout of window element
        dq.push_back(i);
        dq2.push_back(i);

        //current window ka answer store krna hai
        ans += nums[dq.front()] + nums[dq2.front()];
    }
    return ans;
}

int main()
{
    vector< int> v{2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << sumofmimmaxofallwindowofsizek(v, k) << endl;
    return 0;
}