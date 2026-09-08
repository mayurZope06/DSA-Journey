#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector <int> arr(5);
    arr[0] = 11;
    arr[1] = 20;
    arr[2] = 10;
    arr[3] = 20;
    arr[4] = 12;

    sort (arr.begin(), arr.end());
    for (int a : arr)
        cout<<a<<" ";
    cout<<endl;
    reverse(arr.begin(), arr.end());
    for (int a1 :arr)
        cout<<a1<<" ";

    return 0;
}

