#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    forward_list <int> list;

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    forward_list <int> :: iterator it = list.begin();
    while (it != list.end())
    {
        (*it) = (*it) + 5;
        it++;

    }
    it = list.begin();
    while (it != list.end())
    {
        cout<< *it <<" ";
        it++;
    }
    return 0;
}