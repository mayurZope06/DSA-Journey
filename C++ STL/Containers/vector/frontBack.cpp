#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> marks;
    marks.push_back(10);
    marks.push_back(20);
    marks.push_back(30);
    marks.push_back(40);

    cout<<"Size: "<<marks.size()<<endl;
    marks.pop_back();
    cout<<"Size :"<<marks.size()<<endl;

    cout<<marks.front()<<endl;
    cout<<marks.back()<<endl;

    return 0;
    
}