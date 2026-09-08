#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector <int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);

    auto it = max_element(arr.begin(), arr.end());
    cout<< *it<<endl;
    auto it1 = min_element(arr.begin(), arr.end());
    cout<< *it1<<endl;

    return 0;
}
