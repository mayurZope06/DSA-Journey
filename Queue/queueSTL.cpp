#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    //insertion
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    //front 
    cout << q.front() << endl;
    //removal 
    q.pop();
    cout << q.front() << endl;
    //size
    cout << q.size() << endl;
    //empty
    cout << q.empty() << endl;
    //rear element
    cout << q.back() << endl;

    //printing
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}