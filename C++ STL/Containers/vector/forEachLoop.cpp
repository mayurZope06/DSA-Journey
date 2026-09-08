#include <iostream>
#include <vector>
using namespace  std;
int main()
{
    vector <int> first;
    vector <int> second;
    first.push_back(10);
    first.push_back(11);
    first.push_back(12);
    first.push_back(13);
    second.push_back(100);
    second.push_back(200);
    second.push_back(300);
    second.push_back(400);
    
    first.swap(second);
    cout<<first[0]<<" "<<first[1]<<" "<<first[2]<<" "<<first[3]<<" "<<endl;

    for (int i : first)
        cout<<i<<" ";

    for (int j : second)
        cout<<j<<" ";

    return 0;
}