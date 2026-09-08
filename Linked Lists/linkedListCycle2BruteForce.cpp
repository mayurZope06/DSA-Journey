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
        ListNode* detectCycle(ListNode* head)
        {
            unordered_map<ListNode*, bool> m;
            ListNode* temp = head;

            while(temp != NULL)
            {
                if(m[temp] == true)
                {
                    //pehele hi true h cycle present 
                    return temp;
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
            return nullptr;
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