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

    if (st.count(15) == 1)
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;

    return 0;
}