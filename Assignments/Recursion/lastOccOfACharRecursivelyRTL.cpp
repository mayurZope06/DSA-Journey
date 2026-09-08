#include <iostream>
using namespace std;

void lastOccRTL(string &s, char x, int i, int &ans)
{
    //base case
    if(i < 0)
    {
        return;
    }

    //ek case solution
    if(s[i] == x)
    {
        ans = i;
        return;
    }

    //RE
    lastOccRTL(s, x, i - 1, ans);
}

int main()
{
    string s;
    cin >> s;
    char x;
    cin >> x;
    int ans = -1;
    lastOccRTL(s, x, s.size() - 1, ans);
    cout << ans << endl;
    return 0;
}