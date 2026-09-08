#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
    public:
        stack<int> s1, s2;

        void push(int x)
        {
            s1.push(x);
        }

        int pop()
        {
            int pop = -1;
            if(!s2.empty())
            {
                pop = s2.top();
            }
            else
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                pop = s2.top();
            }
            s2.pop();
            return pop;
        }

        int peek()
        {
            int front = -1;
            if(!s2.empty())
            {
                front = s2.top();
            }
            else
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                front = s2.top();
            }
            return front;
        }

        bool empty()
        {
            return s1.empty() && s2.empty();
        }
};

int main()
{
    MyQueue mq;
    mq.push(1);
    mq.push(2);
    mq.push(3);
    cout << mq.peek() << endl;
    mq.pop();
    cout << mq.peek() << endl;
    mq.pop();
    mq.push(4);
    mq.pop();
    mq.pop();
    cout << mq.empty() << endl;
    return 0;
}