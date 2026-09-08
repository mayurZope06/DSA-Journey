#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout<<q.size()<<endl;

    q.pop();
    cout<<q.size()<<endl;

    if(q.empty() == true)
        cout<<"Queue is empty."<<endl;
    else    
        cout<<"Queue is not empty."<<endl;

    cout<<"Front: "<<q.front()<<endl;
    cout<<"Back: "<<q.back()<<endl;

    return 0;
    
}