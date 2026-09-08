#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector <int> arr(5);
    arr[0] = 11;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    arr[5] = 60;

    cout<<"Before :"<<endl;
    for (int a : arr)
        cout<<a<<" ";
    cout<<endl;
    rotate (arr.begin(),arr.begin()+3, arr.end());
    cout<<"After :"<<endl;
    for (int a : arr)
        cout<<a<<" ";
    cout<<endl;

    return 0;
}


