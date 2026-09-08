#include <iostream>
using namespace std;
int main()
{
    int arr[3][2] = {
                        {10,20},
                        {30,40},
                        {50,60}
    };
    int rowSize = 3;
    int colSize = 2;
    //Square matrix
    for (int r = 0; r < rowSize; r++)
    {
        for(int c = 0; c < colSize; c++)
        {
        cout<<arr[c][r]<<" ";
        }
        cout<<endl;
    }

    //column wise
    for(int col = 0; col < colSize; col++)
    {
        for (int row = 0; row < rowSize; row++)
        {
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    // Diagonal Matrix
    for (int i = 0; i < rowSize; i++)
    { 
       
       cout<<arr[i][i]<<" ";
    }
    cout<<endl;
    for (int r = 0; r < rowSize; r++)
    {
        for (int col = 0; col < colSize; col++)
        {
            if ( r == col)
            {
                cout<<arr[r][col]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}