#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map <string,string> table;

    table ["in"] = "India";
    table.insert(make_pair("en","England"));

    pair <string,string> p;
    p.first ="br";
    p.second = "Brazil";
    table.insert(p);

    unordered_map <string, string> :: iterator it = table.begin();
    while (it != table.end())
    {
        pair <string, string> p=*it;
        cout<<p.first<<" "<<p.second<<endl;
        it++;
    }
    return 0;
}