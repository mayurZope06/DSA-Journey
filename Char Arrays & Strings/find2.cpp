#include <iostream>
using namespace std;
int main()
{
    string name = " Hello jee kaise ho saare";
    string word = "kaise ho";
    if (name.find(word) != string :: npos)
        cout<<"found"<<endl;
    else
        cout<<"not found";

    return 0;
}