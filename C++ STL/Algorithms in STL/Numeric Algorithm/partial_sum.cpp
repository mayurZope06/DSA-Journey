#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;
int main()
{
    vector <int> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);
    first.push_back(4);

    vector <int> result (first.size());
    partial_sum (first.begin(), first.end(), result.begin());

    for (int a : result)
        cout<<a<<" ";
    cout<<endl;

    return 0 ;
}