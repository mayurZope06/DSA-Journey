#include <iostream>
using namespace std;
int main()
{
    int arr[2][3];
    int rowSize = 2;
    int colSize = 3;
    // input row wise
    for (int r = 0; r < rowSize; r++)
    {
        for (int c = 0; c < colSize; c++)
        {
            cout<<"Enter the value for Column ("<<r<<","<<c<<"): ";
            cin>>arr[r][c];
        }
    }

    //row wise printing
    cout<<"Printing 2D Array :"<<endl;
    for (int rowIndex = 0; rowIndex < rowSize; rowIndex++)
    {
        for (int colIndex = 0; colIndex < colSize; colIndex++)
        {
            cout<<arr[rowIndex][colIndex]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}