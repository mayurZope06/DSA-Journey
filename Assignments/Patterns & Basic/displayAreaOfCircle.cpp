#include <iostream>
using namespace std;

float circleArea (float radius)
{
    float area = 3.14 * radius * radius;
    return area;
}
int main()
{
    float radius;
    cin >> radius;
    float area = circleArea(radius);
    cout << "Area of circle: " << area << endl;

    return 0;
}