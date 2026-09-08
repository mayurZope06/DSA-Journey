#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool checkEven (int a)
{
    return a%2 == 0;
}
int main()
{
    vector <int> arr(5);
    arr[0] = 11;
    arr[1] = 20;
    arr[2] = 11;
    arr[3] = 40;
    arr[4] = 11;

    int ans = count_if (arr.begin(), arr.end(), checkEven);
    cout<<ans<<endl;

    return 0;
    
}