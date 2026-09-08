#include <iostream>
using namespace std;
int main()
{
    int arr[10]; //declare
    //error int brr [];
    int crr[] = {10,20,40,70};    //initialize
    int drr[4] = {0};

    cout<<drr[0]<<endl;
    cout<<crr[1]<<endl;
    cout<<crr[4]<<endl;//garbage value

    return 0;    

}