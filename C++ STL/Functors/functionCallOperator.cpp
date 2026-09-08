#include <iostream>
using namespace  std;
class FunctorOne
{
    public:
        bool operator () (int a, int b)
        {
            return a>b;
        }

};
int main()
{
    FunctorOne cmp;

    if (cmp(10,5) == true)
        cout<<" 10 is greater than 5"<<endl;
    else    
        cout<<" 10 is less than 5";

    return 0;
}