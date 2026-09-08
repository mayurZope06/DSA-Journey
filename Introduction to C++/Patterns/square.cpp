#include <iostream>
using namespace std;
int main()
{
    // Square pattern 
    for (int row=0; row<4; row++)
    {
        for (int col=0; col<4; col++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
    return 0;
}