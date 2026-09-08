#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector <int> arr;
    arr.push_back(22);
    arr.push_back(11);
    arr.push_back(55);
    arr.push_back(66);
    arr.push_back(77);

    make_heap(arr.begin(), arr.end());

    arr.push_back(99);
    push_heap(arr.begin(), arr.end());

    for(int a: arr)
        cout<<a<<" ";
    cout<<endl;

    pop_heap(arr.begin(),arr.end());

    arr.pop_back();

    sort_heap(arr.begin(), arr.end());

    for(int a: arr)
        cout<<a<<" ";
    cout<<endl;

    return 0 ;
}