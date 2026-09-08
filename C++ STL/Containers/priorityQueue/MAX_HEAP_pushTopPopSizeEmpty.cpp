#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue <int> pq;
    pq.push(10);
    pq.push(25);
    pq.push(55);
    pq.push(21);

    cout<<pq.top()<<endl;
    pq.pop();

    cout<<pq.top()<<endl;
    pq.pop();

    cout<<pq.top()<<endl;
    cout<<pq.size()<<endl;
    if (pq.empty() == true)
        cout<<"PQ is Empty."<<endl;
    else
        cout<<"PQ is not empty."<<endl;

    return 0;

}