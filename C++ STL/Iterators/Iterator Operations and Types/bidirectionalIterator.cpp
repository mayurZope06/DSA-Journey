#include <iostream>
#include <list>
using namespace std;
int main()
{
    list <int> mylist;
    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_back(30);

   /* list <int> :: iterator it = mylist.begin();
    while (it != mylist.end())
    {
        (*it) = (*it) + 2;
        cout<<(*it)<<" ";
        it++;
    }*/
    list <int> :: iterator it = mylist.end();
    while (it != mylist.begin())
    {
        it--;
        (*it) = (*it) + 5;
        cout<<(*it)<<" ";
    }

    return 0;
}