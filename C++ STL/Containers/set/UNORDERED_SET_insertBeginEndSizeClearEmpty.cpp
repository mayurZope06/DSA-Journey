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

    unordered_set<int> :: iterator it = st.begin();
    while(it != st.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
    cout<<st.size()<<endl;
    st.clear();
    cout<<st.size()<<endl;

    if(st.empty())
        cout<<"Set is empty."<<endl;
    else
        cout<<"Set is not empty."<<endl;

    return 0;


}