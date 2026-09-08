#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
    public:
        queue<int> q;

        void push(int x)
        {
            q.push(x);
            for(int i = 0; i < q.size() - 1; ++i)
            {
                int front = q.front();
                q.pop();
                q.push(front);
            }
        }
        int pop()
        {
            int top = q.front();
            q.pop();
            return top;
        }
        int top()
        {
            return q.front();
        }
        bool empty()
        {
            return q.empty();
        }
};

int main()
{
    MyStack ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);

    cout << ms.top() << endl;
    ms.pop();
    cout << ms.top() << endl;
    ms.pop();
    ms.pop();
    cout << ms.empty() << endl;

    return 0;
}