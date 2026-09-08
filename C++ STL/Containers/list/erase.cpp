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

    cout<<first.size()<<endl;
    first.erase(first.begin(),first.end());

    cout<<first.size()<<endl;
    return 0 ;

}