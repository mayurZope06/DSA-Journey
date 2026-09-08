#include <iostream>
#include <vector>
using namespace  std;
int main()
{
    vector <int> marks;
    marks.push_back(10);
    marks.push_back(20);
    marks.push_back(30);
    marks.push_back(40);

    if (marks.empty() == true)
        cout<<"Vector is empty<<endl";

    else    
        cout<<"Vector is not empty"<<endl;

    return 0;
}