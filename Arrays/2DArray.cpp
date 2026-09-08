#include <iostream>
using namespace std;
int main()
{
    //int arr [4][3];

    int arr[3][2]={
                    {10,20},
                    {30,40},
                    {50,60},

                            };
    cout<<arr[2][1]<<endl;

    int rowSize = 3;
    int colsize = 2;
    //row wise
    for (int rowIndex = 0; rowIndex < rowSize; rowIndex++)
    {
        for(int colIndex = 0; colIndex < colsize; colIndex++)
        {
            cout<<arr[rowIndex][colIndex]<<" ";
        }
        cout<<endl;
    }
    return 0;
}