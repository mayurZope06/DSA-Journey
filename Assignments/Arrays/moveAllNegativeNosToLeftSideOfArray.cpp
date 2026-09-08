#include <iostream>
using namespace std;
void moveAllNegstiveToLeft (int *a, int n)
{
    // Dutch National Flag Algorithm (2-  pointer appproach)
    int l = 0, h = n - 1;
    while (l < h)
    {
        if (a[l] < 0 )
            l++;
        else if (a[h] > 0)
            h--;

        else 
        {
            swap(a[l], a[h]);
        }
    }
};
int main()
{
    int a[] = {1, 2, -3, 4, -5, 6};
    int n = sizeof(a)/ sizeof(a[0]);
    moveAllNegstiveToLeft(a, n);
    for (int i = 0; i < n; i++)
        cout<<a[i]<<" ";
        cout<<endl;
    return 0;
}