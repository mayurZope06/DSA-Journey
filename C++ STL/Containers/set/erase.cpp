#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<int> st;
    st.insert(10);
    st.insert(15);
    st.insert(8);
    st.insert(4);

    st.erase (st.begin(),st.end());
    cout<<st.size()<<endl;

    return 0;
}