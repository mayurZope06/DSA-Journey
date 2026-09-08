#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool checkEven(int a)
{
    return a%2 == 0;
}
int main()
{
    vector <int> arr(6);
    arr[0] = 10;
    arr[1] = 11;
    arr[2] = 12;
    arr[3] = 13;
    arr[4] = 14;
    arr[5] = 15;

    auto it = partition (arr.begin(), arr.end(),checkEven);
    for (int a : arr)
        cout<<a<<" ";

    return 0;
}

