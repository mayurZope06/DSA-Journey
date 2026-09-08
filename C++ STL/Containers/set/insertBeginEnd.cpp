#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> st;
    st.insert(10);
    st.insert(15);
    st.insert(8);
    st.insert(4);
    
    set <int> :: iterator it = st.begin();

    while (it != st.end())
    {
        cout<<*it<<" ";
        it++;
    }
    return 0;
}