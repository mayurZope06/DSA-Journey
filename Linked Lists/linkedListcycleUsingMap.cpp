#include <iostream>
#include <unordered_map>
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
            unordered_map<ListNode*, bool> m;
            ListNode* temp = head;

            while(temp != NULL)
            {
                if(m[temp] == true)
                {
                    //pehlese hi true h
                    //cycle present
                    return true;
                }
                else
                {
                    //pehlese true nahi h, yaani false
                    //toh main true visit krra hu ise
                    m[temp] = true;
                }
                temp = temp -> next;
            }
            //agar yaha tk pahuchgye ho, iska mtlab loop se bahar aagye hoo
            //iska mtlab link list poori traverse hogyi
            //ans end me NULL milgaya
            //no cycle present
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