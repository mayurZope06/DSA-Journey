#include <iostream>
using namespace std;
int main()
{
    // Input 

    int arr[10];

    for (int index = 0; index < 10; index++)
    {
        cout<<"Enter the value of box index :"<<index<<endl;

        cin>>arr[index];
    }

    //Output

    for (int index = 0; index < 10; index++)
    {
        cout<<arr[index]<<" ";
    }
    return 0;
}