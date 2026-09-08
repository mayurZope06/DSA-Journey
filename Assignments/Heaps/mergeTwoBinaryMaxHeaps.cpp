#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:

    void heapify(vector<int> &v, int i,int n)
    {
        while(true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int swapIndex = i;

            if(left < n && v[left] > v[i])
            {
                swapIndex = left;
            }
            if(right < n && v[right] > v[swapIndex])
            {
                swapIndex = right;
            }
            if(swapIndex == i)
            {
                break;
            }
            swap(v[i], v[swapIndex]);
            i = swapIndex;
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        //1. merge two heap vectors
        vector<int> c(a.begin(), a.end());
        c.insert(c.end(), b.begin(), b.end());

        //2. Let's heapify vector c.
        for(int i = (c.size() / 2) - 1; i >= 0; --i)
        {
            heapify(c, i, c.size());
        }

        return c;
    }
};


int main()
{
    int n = 4, m =3;

    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    Solution s1;
    vector<int> res = s1.mergeHeaps(a, b, n, m);
    for(auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}