#include <iostream>
using namespace std ;
void extremePrint(int arr[],int n)
{
    int i = 0;
    int j = n-1;

    while (i<=j)
    {
        if( i == j)
        {
                //print only one time
                cout<<arr[i]<<" ";
                break;
        }
        else {
            cout<<arr[i]<<" ";
            i++;
            cout<<arr[j]<<" ";
            j--;
            
        }
    }
}
int main()
{
    int arr []={10,20,30,40,50,60,70};
    int size = 7;
    extremePrint(arr ,size);

    return 0;
}