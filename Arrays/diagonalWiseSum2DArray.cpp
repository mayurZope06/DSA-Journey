#include <iostream>
using namespace std;

void printDiagonalSum (int arr[][3], int rowSize, int colSize)
{
    int sum = 0;

    for (int i = 0; i < rowSize; i++)
    {
        sum = sum + arr[i][i];
    }
    cout<<sum<<endl;
}
int main()
{
    int arr[3][3] = { {10,10,10}, 
                      {10,15,20}, 
                      {30,30,30} 
                    };
    int rowSize = 3;
    int colSize = 3;
    printDiagonalSum(arr , rowSize, colSize);

    return 0;

}