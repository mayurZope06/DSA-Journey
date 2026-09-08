#include <iostream>
using namespace std;

void mixedPyramid(int n)
{
    // UPPER 
    for (int i = 0; i < n; i++)
    {
        // Stars
        for (int j = 0; j < n-i; j++)
            cout<<"* ";

        //Spaces
        for (int j = 0; j < 2*i+1; j++)
            cout<<"  ";

        //Stars
        for (int j = 0; j < n-i; j++)
            cout<<"* ";

        cout<<endl;
    }

    // LOWER
    for (int i = 0; i < n; i++)
    {
        //Stars
        for (int j = 0; j < i+1; j++)
            cout<<"* ";

        //Spaces
        for (int j = 0; j < 2*(n-i)-1; j++)
            cout<<"  ";

        //Stars
        for (int j = 0; j < i+1; j++)
            cout<<"* ";

        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    mixedPyramid(n);
    
    return 0;
}