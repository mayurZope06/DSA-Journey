#include <iostream>
using namespace std;

void printZerosAndOnes (int arr[], int size)
{
    int zeroCount = 0;
    int oneCount = 0;

    for (int i = 0; i < size; i++)
    {
        int currElement = arr[i];
        if(currElement == 0)
        {
            zeroCount++;
        }
        if(currElement == 1)
        {
            oneCount++;
        }
    }
    cout<<"Total Zeros :"<<zeroCount<<endl;
    cout<<"Total Ones :"<<oneCount<<endl;
}
int main()
{
    int arr[100];
    int size;
    cout<<"Enter the number of elements :"<<endl;
    cin>>size;

    for(int i = 0; i < size; i++)
    {
        cout<<"Enter the input value for index "<<i<<endl;
        cin>>arr[i];
    }
    printZerosAndOnes ( arr , size);
    return 0;
}