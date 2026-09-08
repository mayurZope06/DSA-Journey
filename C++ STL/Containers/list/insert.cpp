#include <iostream>
#include <list>
using namespace std;
int main()
{
    list <int> first;
    first.push_back(10);
    first.push_back(20);
    first.push_back(30);

    first.insert(first.begin(),100);
    list <int> :: iterator it = first.begin();
    while (it != first.end())
    {
        cout<<*it<<" ";
        it++;
    }
    return 0;


}