#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printvv (vector <vector<int>> &v)
{
    for (int i = 0; i < v.size();++i)
    {
        vector <int> &temp = v[i];
        int a = temp[0];
        int b = temp[1];
        cout<<a<<" "<<b<<endl;
    }
    cout<<endl;
}
bool mycompfor1stIndex(vector<int> &a, vector<int> &b)
{
    // return a[1] > b[1]; // descending order
     return a[1] < b[1]; // ascending order
}
int main()
{
    vector <vector<int>> v;
    int n;
    cout<<"Enter Size: "<<endl;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cout<<"Enter a and b: "<<endl;
        cin>>a>>b;

        vector<int>temp;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }
    cout<<"Here are the values."<<endl;
    printvv(v);
    cout<<"Sorted by 1st index."<<endl;
    sort(v.begin(), v.end(), mycompfor1stIndex);
    printvv(v);

    return 0;
}