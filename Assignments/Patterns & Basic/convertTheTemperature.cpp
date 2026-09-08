#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector <double> convertTemperature (double celsius)
        {
            double k = celsius + 273.15;
            double f = celsius * 1.80 + 32.00;
            vector <double> v;
            v.push_back(k);
            v.push_back(f);
            return v;
        }
};
int main()
{
    double celsius = 36.50;
    Solution s1;
    vector<double> res = s1.convertTemperature(celsius);
    for (auto a:  res)
    {
        cout << a << " ";
    }
    return 0;
}