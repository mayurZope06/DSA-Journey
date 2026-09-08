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
        ListNode* mergeNodes(ListNode* head)
        {
            if(!head)
                return 0;
            
            ListNode* slow = head, *fast = head -> next, *newLastNode = 0;
            int sum = 0;
            while(fast)
            {
                if(fast -> val != 0)
                {
                    sum += fast -> val;
                }
                else
                {
                    //fast -> val == 0
                    slow -> val = sum;
                    newLastNode = slow;
                    slow = slow -> next;
                    sum = 0;
                }
                fast = fast -> next;
            }
            ListNode* temp = slow;

            //Just formed new list
            newLastNode -> next = 0;

            //Deleting old List
            while(temp)
            {
                ListNode* nxt = temp -> next;
                delete temp;
                temp = nxt;
            }
            return head;
        }
};

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    ListNode* head = new ListNode(0);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next = new ListNode(0);

    printList(head);

    Solution s1;
    
    ListNode* res = s1.mergeNodes(head);
    printList(res);
    return 0;
}