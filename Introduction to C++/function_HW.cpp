#include <iostream>
#include <math.h>
using namespace std;
void printCounting ()
{
    for (int i = 0; i<=100; i++)
    {
        cout<<i<<endl;
    }
}
float toFindSI (float principleAmounnt, float rate, float timePeriod)
{
    int SI = (principleAmounnt*rate*timePeriod)/100;
    return SI;
}
bool printPrimeNums1To100(int n)
{   
    if (n == 1 || n==0) return false;
    
    for (int i = 2; i<n; i++)
    {
        if (n%i==0) return false;
    }

    return true;
}
void voting (int age)
{
    if (age>=18)
    {
        cout<<"You are eligible for voting"<<endl;
    }
    else{
        cout<<"You are not eligible for voting"<<endl;
    }
}
double SIP (double p, double r, double n)
{
    //double futureValue = p*(pow(1+r,n-1) / r)*(1+r);
    double futureValue = p*(pow(1+r,n-1))*(1+r)/r;
    return futureValue;
}
int main()
{
    printCounting();

    int SI_result = toFindSI(10000,6,2);
    cout<<"Simple Intrest :"<<SI_result<<endl;

    int n=100;
    for (int i=1; i<=n; i++)
    {
        if(printPrimeNums1To100(i))
        {
            cout<<i<<" "<<endl;
        }
    }
    

    int age =18;
    voting(age);

    double futureVal = SIP(45000, 5, 4);
    cout<<"SIP :"<<futureVal<<endl;

    return 0;
}