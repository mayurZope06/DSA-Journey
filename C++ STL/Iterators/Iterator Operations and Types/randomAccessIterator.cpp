#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> arr = {10, 20, 30, 40, 50};

    vector <int> :: iterator it = arr.begin();
    while (it != arr.end())
    {
        *it = *it + 7;
        cout<<*it<< " ";

        it++;

    }
     
     cout<<endl;
    vector <int> :: iterator itr = arr.end();
    while (itr != arr.begin())
    {
        itr--;
        cout<<*itr<< " ";
    }

    return 0;

}