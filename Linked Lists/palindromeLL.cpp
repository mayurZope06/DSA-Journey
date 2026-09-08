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
        ListNode* getMiddle(ListNode* head, ListNode* &middleNodeKaPrev)
        {
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast != NULL)
            {
                fast = fast -> next;
                if(fast != NULL)
                {
                    fast = fast -> next;
                    middleNodeKaPrev = slow;
                    slow = slow -> next;
                }
            }
            return slow;
        }
        ListNode* reverseList(ListNode* &prev, ListNode* &curr)
        {
            while (curr != NULL)
            {
                ListNode* forward = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = forward;
            }
            return prev;
        }
        bool isPalindrome(ListNode* head)
        {
            if(head == NULL)
            {
                //LL is empty
                return true;
            }
            if(head -> next == NULL)
            {
                //single node
                return true;
            }
            //travel till middle node and break the LL in 2 halves
            ListNode* firstHalfHead = head;
            ListNode* middleNodeKaPrev = NULL;
            ListNode* middleNode = getMiddle(head, middleNodeKaPrev);

            //break
            middleNodeKaPrev -> next = NULL;

            //reverse the second half
            ListNode* prev = NULL;
            ListNode* curr = middleNode;
            ListNode* secondHalfHead = reverseList(prev, curr);

            //compare both the halves and decide T/F
            //even len wale case me dono part ki length equal hogi
            //odd len wale case me second half ki length badi hogi by 1
            //that's why mai comparison haesha first half ki length k hisab se krunga
            ListNode* temphead1 = firstHalfHead;
            ListNode* temphead2 = secondHalfHead;
            while(temphead1 != NULL)
            {
                if(temphead1 -> val != temphead2 -> val)
                {
                    // not a palindrome
                    return false;
                }
                else
                {
                    //data equa; hai, toh, let's move to aage wali nodes
                    temphead1 = temphead1 -> next;
                    temphead2 = temphead2 -> next;
                }
            }
            //agar mai yaha tak pohoch gaya 
            //iska mtlab kahi pr bhi
            //data mismatch nahi hua
            //palindrome hai
            return true;
        }
};

// Function to create a linked list from an array
ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Solution solution;

    // Create a linked list
    int arr[] = {1, 2, 3, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createLinkedList(arr, size);

    cout << "Original Linked List: ";
    printLinkedList(head);

    bool result = solution.isPalindrome(head);
    cout << result;
    return 0;
}