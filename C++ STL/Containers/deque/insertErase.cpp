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

    dq.insert (dq.begin(),101);
    cout<<dq[0]<<endl;
    cout<<dq.size()<<endl;
    dq.erase(dq.begin(),dq.end());

    cout<<dq.size()<<endl;
    return 0;
}