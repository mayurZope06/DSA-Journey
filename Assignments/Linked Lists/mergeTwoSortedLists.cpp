#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    public:
        ListNode* mergeTwoLists (ListNode* left, ListNode* right)
        {
            if(left == 0)
                return right;
            
            if(right == 0)
                return left;

            ListNode* ans = new ListNode(-1);
            ListNode* mptr = ans;

            while(left && right)
            {
                if(left -> val <= right -> val)
                {
                    mptr -> next = left;
                    mptr = left;
                    left = left -> next;
                }
                else
                {
                    mptr -> next = right;
                    mptr = right;
                    right = right -> next;
                }
            }
            if(left)
                mptr -> next = left;
            
            if(right)
                mptr -> next = right;

            return ans -> next;
        }
};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating two sorted linked lists
    ListNode* left = new ListNode(1);
    left->next = new ListNode(2);
    left->next->next = new ListNode(4);

    ListNode* right = new ListNode(1);
    right->next = new ListNode(3);
    right->next->next = new ListNode(4);

    cout << "Original Lists: " << endl;
    cout << "Left: ";
    printList(left);
    cout << "Right: ";
    printList(right);

    // Merge the two lists
    Solution solution;
    ListNode* merged = solution.mergeTwoLists(left, right);

    cout << "Merged List: ";
    printList(merged);

    // Clean up memory
    ListNode* temp;
    while (merged != nullptr) {
        temp = merged;
        merged = merged->next;
        delete temp;
    }

    return 0;
}