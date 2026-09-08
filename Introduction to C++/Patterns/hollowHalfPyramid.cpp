#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter value of n:"<<endl;
    cin>>n;

    for (int row = 0; row < n; row++)
    {
        int totCol = row + 1;
        for (int col = 0; col < totCol; col++)
        {
            if (row == 0 ||row == 1|| row == n-1)
            {
                cout<<"* ";
            }
            else
            {
                if (col == 0 || col == totCol-1) // or (col == 0 || col == row)
                {
                    cout<<"* ";
                }
                else
                {
                    cout<<"  ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}