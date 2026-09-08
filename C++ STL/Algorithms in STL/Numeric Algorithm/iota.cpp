#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;
int main()
{
    vector <int> first(5);

    iota (first.begin(), first.end(),250);

    for(int a : first)
        cout<<a<<" ";
    
    return 0;
}
