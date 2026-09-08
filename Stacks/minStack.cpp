#include <iostream>
#include <vector>
using namespace std;

class MinStack
{
    public:
        //array
        vector<pair< int, int>> v; // pair => {value, minimum element till  now}

        void push(int val)
        {
            if(v.empty())
            {
                v.push_back({val, val});
                return;
            }

            // int min = val;
            // if(v.back().second < min)
            // {
            //     min = v.back().second;
            // }
            // v.push_back({val, min});

            v.push_back({val, v.back().second < val ? v.back().second : val});
        }

        void pop()
        {
            v.pop_back();
        }
        
        int top()
        {
            return v.back().first;
        }

        int getMin()
        {
            return v.back().second;
        }
};

int main()
{
    MinStack st;
    
    st.push(5);
    st.push(2);
    st.push(8);
    st.push(1);

    cout << "Top element: " << st.top() << endl;    // 1
    cout << "Minimum element: " << st.getMin() << endl; // 1

    st.pop();
    cout << "Top element after pop: " << st.top() << endl;    // 8
    cout << "Minimum element after pop: " << st.getMin() << endl; // 2

    return 0;
    
    return 0;
}