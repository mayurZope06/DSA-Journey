#include <iostream>
#include <vector>
using namespace  std;
int main()
{
    vector <int> marks;
  
    marks.reserve(10);
    cout<<marks.capacity()<<endl;

    return 0;
}
