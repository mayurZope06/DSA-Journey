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
        bool hasCycle(ListNode* head)
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
                    {
                        //cycle present
                        return true;
                    }
                }
            }
            //loop se bahar, cycle absent
            return false;
        }
};

int main() {
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

    if (solution.hasCycle(head)) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    // Clean up memory
    // Note: Avoid cleaning memory when there's a cycle, or handle it properly
    fourth->next = NULL; // Break the cycle before deleting
    delete fourth;
    delete third;
    delete second;
    delete head;

    return 0;
}