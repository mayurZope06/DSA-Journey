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

    cout<<table.at("in")<<endl;
    table.at("in") = "India2";
    cout<<table.at("in")<<endl;
    table ["in"] = "India3";
    cout<<table.at("in")<<endl;

    return 0;
}