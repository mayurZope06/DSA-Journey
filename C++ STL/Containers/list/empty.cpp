#include <iostream>
#include <list>
using namespace std;
int main()
{
    list <int> mylist;
    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_back(30);
    mylist.push_back(40);
    mylist.push_front(100);
    mylist.pop_back();
    mylist.pop_front();

    cout<<mylist.size()<<endl;
    mylist.clear();
    cout<<mylist.size()<<endl;

    if (mylist.empty() == true)
        cout<<"List is empty"<<endl;
    else   
        cout<<"List is not empty."<<endl;

    return 0;

}