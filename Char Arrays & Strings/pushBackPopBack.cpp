#include <iostream>
using namespace std;
int main()
{
    string str;
    str.push_back('l');
    str.push_back('o');
    str.push_back('v');
    str.push_back('e');
    str.pop_back();
    cout<<str<<endl;
    return 0;
}