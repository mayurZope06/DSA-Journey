#include <iostream>
using namespace std;

int main()
{
    // 1. swap inbuilt function
    int a =5, b=6;
    swap(a,b);
    cout<<"a :"<<a<<", b:"<<b<<endl;

    // 2. temp variable
    int x=5,y=6;
    int temp = x;
        x = y;
        y = temp;

    cout<<"x: "<<x<<", y: "<<y<<endl;

    // 3. Arithmetic method **interview question
    int m = 5, n = 6;
    m = m+n;
    n = m-n;
    m = m-n;
    cout<<"m:"<<m<<",n:"<<n<<endl;

    // 4. XOR bitwise method **interview question
    int aa=5,bb=6;
    aa = aa ^ bb;
    bb = bb ^ aa;
    aa = aa ^ bb;
    cout<<"aa: "<<aa<<", bb: "<<bb<<endl;

    return 0;
}