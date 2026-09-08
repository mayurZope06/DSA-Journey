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

    cout<<dq[3]<<endl;
    cout<<dq.at(3)<<endl;

    return 0;
}