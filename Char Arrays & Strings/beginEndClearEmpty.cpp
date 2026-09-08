#include <iostream>
using namespace std;
int main()
{
    string name = "Mayur Zope";
    auto it = name.begin();
    while (it != name.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
    name.clear();
    if (name.empty())
        cout<<"Srting is Empty"<<endl;
    else    
        cout<<"String is not empty";

    return 0;
}