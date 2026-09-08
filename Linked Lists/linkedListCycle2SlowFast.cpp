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
            while(slow != fast)
            {
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow; // starting point
        }
};

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

    ListNode* loopStart = solution.detectCycle(head);
    cout << loopStart -> val;

    // Clean up memory
    // Note: Avoid cleaning memory when there's a cycle, or handle it properly
    fourth->next = NULL; // Break the cycle before deleting
    delete fourth;
    delete third;
    delete second;
    delete head;

    return 0;
}