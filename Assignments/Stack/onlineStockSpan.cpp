#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class stockSpanner
{
    stack <pair<int, int>> st;
    public:
        int next(int price)
        {
            int span = 1;
            while(!st.empty() && st.top().first <= price)
            {
                span += st.top().second;
                st.pop();
            }
            st.push({price, span});
            return span;
        }
};

int main()
{
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    stockSpanner obj;

    for(int price : prices)
    {
        cout << obj.next(price) << " ";
    }

    return 0;
}