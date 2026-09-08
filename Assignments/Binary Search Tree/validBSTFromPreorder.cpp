#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void build(int& i, int min, int max, vector<int>& A) 
{
    if (i >= A.size()) {
        return;
    }

    // Check if current element is within valid range
    if (A[i] > min && A[i] < max) 
    {
        int rootData = A[i++];  // Pick the current element as root
        build(i, min, rootData, A);  // Build left subtree
        build(i, rootData, max, A);  // Build right subtree
    }
}

int solve(vector<int>& A) 
{
    int min = INT_MIN, max = INT_MAX;
    int i = 0;

    // Build the BST using preorder and check if valid
    build(i, min, max, A);

    // If all elements are processed, return 1 (valid BST), else 0
    return i == A.size();
}

int main() {
    vector<int> A = {10, 5, 1, 7, 40, 50};  // Valid Preorder of BST
    int result = solve(A);

    if (result) {
        cout << "The given array represents a valid BST." << endl;
    } else {
        cout << "The given array does NOT represent a valid BST." << endl;
    }

    return 0;
}
