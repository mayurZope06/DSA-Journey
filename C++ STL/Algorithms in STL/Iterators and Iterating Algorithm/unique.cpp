#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector <int> arr(6);
    arr[0] = 11;
    arr[1] = 11;
    arr[2] = 11;
    arr[3] = 22;
    arr[4] = 22;
    arr[5] = 33;

    auto it = unique (arr.begin(), arr.end());
    arr.erase(it,arr.end());

    for (int a : arr)
        cout<<a<<" ";
    
    return 0;

}