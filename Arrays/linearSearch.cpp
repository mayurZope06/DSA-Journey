#include <iostream>  
using namespace std;

bool findTarget(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        int currentElement = arr[i];

        if (currentElement == target)
        {
            return true;
        }

    }
    return false;
}
// without user input -->
/*int main()
{
    int arr[]= {10,20,30,40,50};
    int size = 5;
    int target = 50;

    bool ans = findTarget(arr,size,target);
    cout<<"Ans :"<<ans<<endl;

    return 0;
}*/

// using user input -->
int main()
{
    int arr[100];
    int size;
    cout<<"Enter the number of the elements:";
    cin>>size;

    for(int i = 0; i < size; i++)
    {
        cout<<"Enter thr input value for index"<<i<<endl;
        cin>>arr[i];
    }
    int target;
    cout<<" ***Enter the value of the target :"<<endl;
    cin>>target;

    bool ans = findTarget(arr,size,target);
    cout<<"Ans :"<<ans<<endl;

    return 0;
}