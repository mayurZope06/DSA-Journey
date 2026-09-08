#include <iostream>
#include <vector>
using namespace std;

void printSubSequences(string str, int i, string output, vector <string> &ans)
{
    if ( i == str.length())
    {
        ans.push_back(output);
        return;
    }
    char ch = str[i];

    // include ch
    printSubSequences(str, i + 1, output + ch, ans);

    // exclude ch
    printSubSequences(str, i + 1, output, ans);
}
int main()
{
    string str = "abc";
    string output = " ";
    int index = 0;

    vector <string> ans;
    printSubSequences(str, index, output, ans);
    cout << ans.size() << endl;

    for (auto i : ans)
    {
        cout << i << endl;
    }
    
    return 0;
}