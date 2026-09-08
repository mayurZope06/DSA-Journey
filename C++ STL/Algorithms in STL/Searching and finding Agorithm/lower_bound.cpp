#include <iostream>
#include  <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector <int > arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);

    auto it = lower_bound(arr.begin(), arr.end(), 35);

    cout<<*it<<endl;

    return 0;
}