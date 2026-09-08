#include <iostream>
#include <unordered_map>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> map;
    string ans = "Yes";

    //map hashing using a1
    for(int i = 0; i < n; i++)
    {
        map[a1[i]]++;
    }
    //check whether all elements of a2 present in a1
    for(int i = 0; i < m; ++i)
    {
        if(map.find(a2[i]) == map.end())
        {
            ans = "No";
            break;
        }
        else
        {
            //present
            if(map[a2[i]] > 0)
            {
                map[a2[i]]--;
            }
            else
            {
                ans = "No";
                break;
            }
        }
    }
    return ans;
}

int main()
{
    int a1[] = {11, 7, 1, 13, 21, 3, 7, 3};
    int a2[] = {11, 3, 7, 1, 7};
    int n = sizeof(a1)/ sizeof(a1[0]);
    int m = sizeof(a2)/ sizeof(a2[0]);
    string res = isSubset(a1, a2, n, m);
    cout << res;
    return 0;
}