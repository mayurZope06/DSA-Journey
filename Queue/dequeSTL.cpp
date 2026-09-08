#include <iostream>
#include <queue>
using namespace std;

int main()
{
    //douly-ended queue 
    deque<int> dq;
    //insertion
    dq.push_front(10);
    //10
    dq.push_front(30);
    //10 30
    dq.push_front(50);
    //10 30 50
    dq.push_back(70);
    ///70 10 30 50;
    dq.push_back(100);
    //100 70 10 30 50
    cout << dq.size() << endl;
    cout << dq.empty() << endl;
    cout << dq.front() << endl;
    cout << dq.back() << endl;

    //removal;
    dq.pop_front();
    cout << dq.front() << endl;
    dq.pop_back();
    cout << dq.back() << endl;
    
    return 0;
}