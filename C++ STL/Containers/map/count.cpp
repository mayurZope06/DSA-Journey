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

    if (table.count("in") == 0)
        cout<<"key not found"<<endl;
    if (table.count ("in") == 1)
        cout<<"key found"<<endl;

    return 0;
}