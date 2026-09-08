#include <iostream>
using namespace std;
void printEvenInsideRange(int start,int end)
{
    cout<<"Even Numbers:"<<endl;
    for (int i=start; i<=end; i++)
    {
        int n=i;
        if(!(n&1))
        {
            cout<<n<<endl;
        }
    }
}
void printOddInsideRange(int start,int end)
{
    cout<<"Odd Numbers:"<<endl;
    for (int i=start; i<=end; i++)
    {
        int n=i;
        if(n&1)
        {
            cout<<n<<endl;
        }
    }
}
int main()
{
    int start,end;
    cout<<"Enter the range for even odd number:"<<endl;
    cin>>start>>end;
    printEvenInsideRange(start,end);
    printOddInsideRange(start,end);
    return 0;
}