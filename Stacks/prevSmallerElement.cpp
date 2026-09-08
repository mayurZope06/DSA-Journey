#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void prevSmallerElement(int arr[], int n, vector<int> &ans)
{
    stack<int> s;
    s.push(-1);

    //fark sirf iss wale loop ka hai
    for(int i = 0; i < n; i++)
    {
        int element = arr[i];
        while(s.top() > element)
        {
            s.pop();
        }
        //yaha agye mtlb stack top koi chhoota element hai
        ans.push_back(s.top());
        s.push(arr[i]);
    }
}

int main()
{
    int arr[] = {8, 4, 6, 2, 3};
    int n = 5;
    vector<int> ans;
    prevSmallerElement(arr, n, ans);

    for(auto i: ans)
    {
        cout << i << " ";
    }
    return 0;
}