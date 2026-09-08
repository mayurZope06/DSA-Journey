#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue <int> first;
    queue <int> second;

    first.push(10);
    first.push(20);
    second.push(100);
    second.push(200);

    first.swap(second);
    cout<<first.front()<<" "<<first.back()<<endl;

    return 0;
}