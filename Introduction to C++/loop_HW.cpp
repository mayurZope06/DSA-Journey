#include <iostream>
using namespace std;
int main()
{
    // 1 --> 100 couting
    for (int i=1; i<=100; i=i+1)
    {
        cout<<i<<endl;
    }

    // 100 --> 1 counting
    for (int i=100; i>=1; i=i-1)
    {
        cout<<i<<endl;
    }

    // 50 times name
    for (int i=1; i<=50; i=i+1)
    {
        cout<<i<<") Mayur"<<endl;
    }

    // 0--> -10 counting
    for (int i=0; i>=-10; i=i-1)
    {
        cout<<i<<endl;

    }

    // 7 table
    int store,table=7;
    for(int j=1; j<=10; j=j+1)
    {
        store=table*j;
        cout<<store<<endl;
    }

    // A --> Z alphabet
    for (char ch = 'A'; ch<='Z'; ch=ch+1)
    {
        cout<<ch<<endl;
    }

    //a --> z
    for (char ch = 'a'; ch<='z'; ch=ch+1)
    {
        cout<<ch<<endl;
    }
    return 0;
}