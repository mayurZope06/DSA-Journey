#include <iostream>
using namespace std;

void merge(int arr[], int s, int e, int mid)
{
    //create left and right arrays
    int leftLength = mid - s + 1;
    int rightLength = e - mid;

    int *leftArr = new int[leftLength];
    int *rightArr = new int[rightLength];

    //fill or copy the left and right arrays
    //copy original array -> values
    //original array ka starting index
    int index = s;

    //copying into left array
    for(int i = 0; i < leftLength; i++)
    {
        leftArr[i] = arr[index];
        index++;
    }

    //copying into right array
    for(int i = 0; i < rightLength; i++)
    {
        rightArr[i] = arr[index];
        index++;
    }

    //merge logic
    int i = 0; 
    int j = 0;
    int mainArrIndex = s;

    while(i < leftLength && j < rightLength)
    {
        if (leftArr[i] < rightArr[j])
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

    //I have handle the 2 cases discussed above in merge 2 sorted arrays wala question
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

    //delete heap memory
    delete [] leftArr;
    delete [] rightArr;
}
void mergeSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
        return;

    int mid = (s + e) / 2;

    //left part recursion se solve karwao
    mergeSort(arr, s, mid);

    //right part recursion se solve karwao
    mergeSort(arr, mid + 1, e);

    //dono parts ko merge kardo
    merge(arr, s, e, mid);
}
int main()
{
    int arr[] = {10, 80, 110, 90, 50, 30, 40, 20};
    int size = 8;
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