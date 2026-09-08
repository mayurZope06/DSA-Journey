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

    if(table.find("in") != table.end())
        cout<<"key Found"<<endl;
    else
        cout<<"Key not found"<<endl;

    return 0;
}
