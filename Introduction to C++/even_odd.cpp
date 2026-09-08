#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int num;
    cout<<"Enter number :"<<endl;
    cin>>num;
    if ((num&1)==0)
    {
        cout<<num<<" is even number"<<endl;
    }
    else{
        cout<<num<<" is odd number"<<endl;
    }
}