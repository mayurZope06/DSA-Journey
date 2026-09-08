#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left, *right;
        Node(int val):data(val), left(0), right(0){}
    };
    
    class Solution{
    public:
        Node* insert(Node* root, int val, int& succ){
            if(!root) return new Node(val);
            if(val >= root->data){
                root->right = insert(root->right, val, succ);
            }
            else{
                succ = root->data;
                root->left = insert(root->left, val, succ);
            }
            return root;
        }
    
        vector<int> findLeastGreater(vector<int> &arr, int n) {
            vector<int> ans(arr.size(), -1);
            Node* root = 0;
            for(int i=arr.size()-1;i>=0;--i){
                int succ = -1;
                root = insert(root, arr[i], succ);
                ans[i] = succ;
            }
            return ans;
        }
    };

    int main() {
        vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
        int n = arr.size();
        
        Solution sol;
        vector<int> result = sol.findLeastGreater(arr, n);
        
        cout << "Output: ";
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
        
        return 0;
    }
    