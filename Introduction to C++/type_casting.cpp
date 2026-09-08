#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    // Implicit Type Casting
    
    // int to float
    int num1 = 10;
    float num2 = 5.5;
    float result = num1+num2; 
    cout<<result<<endl; 

    //char to int
    char ch = 'A';
    int x = ch+1;
    cout<<x<<endl;

    //int to char
    int a = 97;
    char any = a;
    cout<<any<<endl;

    char g = 'B';
    int gg = g;
    cout<<gg<<endl;

    // Explicit Type Casting

    //double to int
    double pi=3.14159265;
    int intpi=(int)pi;
    cout<<intpi<<endl;

    //float to char
    float floatingNumber = 65.35;
    char charValue = (char)floatingNumber;
    cout<<charValue<<endl;

    //int to float
    int aaa =10;
    int b =30;
    float c=aaa/b;
    cout<<c<<endl;

    return 0;
}