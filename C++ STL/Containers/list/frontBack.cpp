#include <iostream>
#include <list>
using namespace std;
int main()
{
    list <int> mylist;
    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_back(30);

    cout<<mylist.front()<<endl;
    cout<<mylist.back()<<endl;

    return 0;
    

}