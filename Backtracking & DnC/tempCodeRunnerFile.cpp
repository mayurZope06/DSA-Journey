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