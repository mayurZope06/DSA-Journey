#include <iostream>
#include <limits.h>
using namespace std;

int findMax(int arr[], int sizze) {
    int maxi = INT_MIN;
    for(int i = 0; i < sizze; i++) {
        if(arr[i] > maxi) {
            maxi = arr[i];
        }
    }
    return maxi;
}
int main()
{
    int arr[100];
    int size;
    cin >> size;

    for(int i = 0 ; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Maxi: " << findMax(arr, size) << endl;

    return 0;
}