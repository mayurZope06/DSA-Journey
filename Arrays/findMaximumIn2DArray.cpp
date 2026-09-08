#include <iostream>
#include <limits.h>
using namespace std;
int findMaximumIn2DArray (int arr[][4], int rowSize, int colSize)
{
    int maxAns = INT_MIN;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            maxAns = max(arr[i][j],maxAns);
        }
    }
    return maxAns;
}
int main()
{
    int arr[3][4] = {
                        {10,11,12,13}, {20,21,22,-2}, {31,32,44,55} };

    int rowSize = 3;
    int colSize = 4;
    int maxAns = findMaximumIn2DArray (arr,rowSize,colSize);
    cout<<"max num:"<<maxAns<<endl;

    return 0;
}