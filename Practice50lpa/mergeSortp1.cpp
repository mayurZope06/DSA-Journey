#include <iostream>
using namespace std;

void merge (int arr[], int s, int e, int mid)
{
    int leftLength = mid - s + 1;
    int rightLength = e - mid;

    int *leftArr = new int[leftLength];
    int *rightArr = new int[rightLength];

    int index = s;

    for(int i = 0; i < leftLength; i++)
    {
        leftArr[i] = arr[index];
        index++;
    }
    for(int i = 0; i < rightLength; i++)
    {
        rightArr[i] = arr[index];
        index++;
    }

    int i = 0;
    int j = 0;
    int mainArrIndex = s;

    while(i < leftLength && j < rightLength)
    {
        if(leftArr[i] < rightArr[j])
        {
            arr[mainArrIndex] = leftArr[i];
            i++;
            mainArrIndex++;
        }
        else
        {
            arr[mainArrIndex] = rightArr[j];
            j++;
            mainArrIndex++;
        }
    }
    while(i < leftLength)
    {
        arr[mainArrIndex] = leftArr[i];
        i++;
        mainArrIndex++;
    }
    while(j < rightLength)
    {
        arr[mainArrIndex] = rightArr[j];
        j++;
        mainArrIndex++;
    }
    delete[] leftArr;
    delete[] rightArr;

}

void mergeSort(int arr[], int s, int e)
{
    if(s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);

    mergeSort(arr, mid + 1, e);
    
    merge(arr, s, e, mid);
}

int main()
{
    int arr[] = { 10, 36, 54, 78, 10, 25, 96, 87, 36, 74, 52 ,74, 36};
    int size = sizeof(arr)/ sizeof(arr[0]);
    int s = 0;
    int e = size - 1;

    cout << "Before: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " "; 
    }
    cout << endl;

    mergeSort(arr, s, e);

    //printing entire sorted array
    cout << "After: " <<endl;
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}