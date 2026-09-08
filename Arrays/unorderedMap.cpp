#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    unordered_map <int, int> desk_map;

    desk_map[1] = 53;
    desk_map[2] = 54;
    desk_map[3] = 55;

    desk_map[2] = 57;

    // iterate
    unordered_map<int, int> :: iterator it ;
    for (it = desk_map.begin(); it != desk_map.end(); it++)
    {
        int key = it ->first;
        int value = it->second;
        cout<<"Key: "<<key<<" "<<"Value: "<<value<<endl;

    }
    //find ?
    if (desk_map.find(2) != desk_map.end())
    {
        //found
        int value = desk_map[2];
        cout<<"Found: "<<value<<endl;

    }
    else{
        // not found
        cout<<"Not Found"<<endl;
    }
    
    //deletion
    desk_map.erase(2);
    cout<<"After erase: "<<endl;

    for(it = desk_map.begin(); it != desk_map.end(); it++)
    {
         int key = it ->first;
        int value = it->second;
        cout<<"Key: "<<key<<" "<<"Value: "<<value<<endl;
    }

    cout<<"Find 2 again"<<endl;
    if (desk_map.find(2) != desk_map.end())
    {
        //found
        int value = desk_map[2];
        cout<<"Found: "<<value<<endl;

    }
    else{
        // not found
        cout<<"Not Found"<<endl;
    }
    return 0;
}