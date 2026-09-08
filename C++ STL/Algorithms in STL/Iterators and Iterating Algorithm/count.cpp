#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector <int> arr(5);
    arr[0] = 11;
    arr[1] = 20;
    arr[2] = 11;
    arr[3] = 40;
    arr[4] = 11;

    int target = 11;
    int ans = count (arr.begin(), arr.end(), target);
    cout<<ans<<endl;

    return 0;
    
}