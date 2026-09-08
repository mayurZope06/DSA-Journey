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
        ListNode* deleteDuplicates (ListNode* head)
        {
            //1 case -> LL is empty
            if (head == NULL)
            {
                return head;
            }
            //2 case -> LL -> single node
            if(head -> next == NULL)
            {
                return head;
            }
            //3 case -> >1 nodes
            //atleast 2 nodes toh pakka hogi
            ListNode* prev = head;
            ListNode* temp = head -> next;

            while(temp != NULL)
            {
                //duplicate check kro
                if(temp -> val == prev -> val)
                {
                    //duplicate found
                    prev -> next = temp -> next;
                    temp -> next = NULL;
                    delete temp;
                }
                else
                {
                    //duplicate not found
                    prev = prev -> next;
                    temp = temp -> next;
                }
                //temp ko set kardo // bhul jata hu
                temp = prev -> next;
            }
            return head;
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
    // Create a sorted linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    cout << "Original List: ";
    printList(head);

    // Remove duplicates
    Solution solution;
    head = solution.deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    // Clean up memory
    ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}