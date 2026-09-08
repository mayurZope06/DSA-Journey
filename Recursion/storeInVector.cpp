#include <iostream>
#include <vector>
using namespace std;

void printAllOdds (int arr[], int n, int index, vector<int> &ans)
{
    //base case
    if (index == n)
        return;
    
    if((arr[index]) & 1)
        ans.push_back(arr[index]);

    printAllOdds(arr, n, index + 1, ans);
}
int main()
{
    int arr[] = {10, 11, 12, 13, 14, 15, 16};
    int size = 7;
    int index = 0;
    vector <int> ans;
    printAllOdds(arr, size, index, ans);
    for (auto num : ans)
        cout<<num<<" ";

    return 0;
}