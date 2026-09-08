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

    marks.clear();
    cout<<marks.size()<<endl;

    return 0;
}