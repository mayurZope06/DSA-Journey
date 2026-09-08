#include <iostream>
#include <queue>
using namespace std;
int main()
{
    deque <int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(40);
    dq.push_front(100);
    dq.push_front(200);
    dq.push_front(300);

    dq.pop_front();
    dq.pop_back();

    cout<<dq.size()<<endl;
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;

    if (dq.empty() == true)
        cout<<"Deque is empty."<<endl;
    else
        cout<<"Deque is not empty."<<endl;

    return 0;
    
}