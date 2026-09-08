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

    cout<<table.size()<<endl;
    table.erase(table.begin(),table.end());
    cout<<table.size()<<endl;

    return 0;
}