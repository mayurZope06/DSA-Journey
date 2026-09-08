#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue <int, vector <int>, greater <int>> pq;
    pq.push(100);
    pq.push(50);
    pq.push(75);

    cout<<pq.top()<<endl;

    pq.pop();

    cout<<pq.top()<<endl;

    pq.pop();

    cout<<pq.top()<<endl;

    return 0;
}