#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    public:
        ListNode* hasCycle(ListNode* head)
        {
            ListNode* slow = head;
            ListNode* fast = head;

            while (fast != NULL)
            {
                fast = fast -> next;
                if(fast != NULL)
                {
                    fast = fast -> next;
                    slow = slow -> next;

                    if(fast == slow)
                        return fast;
                }
            }
            return nullptr;
        }
        ListNode* detectCycle(ListNode* head)
        {
                //Step 1 : Check if loop is there or not
            ListNode* fast = hasCycle(head);
            if(!fast) 
                return nullptr;
            
            //fast is non-null means, cycle is there
            //Let's find starting point of cycle
            ListNode* slow = head;
            //now move slow and fast ptr with 1x speed and return where thry meet
            ListNode* prev = 0;
            while(slow != fast)
            {
                slow = slow -> next;
                prev = fast;
                fast = fast -> next;
            }
            prev -> next = NULL;
            return head; // starting point
        }
};

void print(ListNode* head)
{
    ListNode* temp = head;
    while(temp != NULL)
    {
        cout << temp -> val << "->";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}


int main()
{
    // Create a linked list with a cycle
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    // Creating a cycle: fourth->next points to second
    fourth->next = second;

    // Solution object
    Solution solution;

    ListNode* removedLoop = solution.detectCycle(head);
    print(removedLoop);

    // Clean up memory
    // Note: Avoid cleaning memory when there's a cycle, or handle it properly
    fourth->next = NULL; // Break the cycle before deleting
    delete fourth;
    delete third;
    delete second;
    delete head;

    return 0;
}

// gfg
// struct Node
// {
//     int data;
//     Node* next;

//     Node(int val)
//     {
//         data = val;
//         next = NULL;
//     }
// };

// class Solution {
// public:
//     // Function to detect a cycle and return the meeting point of slow and fast pointers
//     Node* hasCycle(Node* head) {
//         Node* slow = head;
//         Node* fast = head;

//         while (fast != NULL && fast->next != NULL) {
//             fast = fast->next->next;
//             slow = slow->next;

//             if (fast == slow)
//                 return fast; // Cycle detected
//         }
//         return nullptr; // No cycle
//     }

//     // Function to remove a loop in the linked list
//     void removeLoop(Node* head) {
        
//         //Step 1 : Check if loop is there or not
//             if(!head)
//                 return;
//             Node* fast = hasCycle(head);
//             if(!fast) 
//                 return ;
            
//             //fast is non-null means, cycle is there
//             //Let's find starting point of cycle
//             Node* slow = head;
        
//             if(slow == fast)
//             {
//                 while(fast -> next != slow)
//                 {
//                     fast = fast -> next;
//                 }
//                 fast -> next = nullptr;
//                 return;
//             }
//             //now move slow and fast ptr with 1x speed and return where thry meet
//             Node* prev = 0;
//             while(slow != fast)
//             {
//                 slow = slow -> next;
//                 prev = fast;
//                 fast = fast -> next;
//             }
            
//             prev -> next = nullptr;
                    
//              // starting point
//     }
// };


