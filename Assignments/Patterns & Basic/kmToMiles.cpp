#include <iostream>
using namespace std;

float kmToMiles (float km)
{
    float _1kmMile = 0.621371;
    float miles = km * _1kmMile;
    return miles;
}
int main()
{
    float km;
    cout << "Tell me km: " << endl;
    cin >> km;

    float miles = kmToMiles(km);
    cout << "Miles = " << miles << endl;
    return 0;
}