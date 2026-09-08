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
        int getLength(ListNode* head)
        {
            int len = 0;
            while(head)
            {
                ++len;
                head = head -> next;
            }
            return len;
        }
        ListNode* rotateRight(ListNode* head, int k)
        {
            if(!head)
                return 0;
            
            int len = getLength(head);
            int actualRotateK = (k % len);
            if(actualRotateK == 0)
                return head;
            
            int newLastNodePos = len - actualRotateK - 1;

            ListNode* newLastNode = head;
            for(int i = 0; i < newLastNodePos; i++)
            {
                newLastNode = newLastNode -> next;
            }
            ListNode* newHead = newLastNode -> next;
            newLastNode -> next = 0;

            ListNode* it = newHead;
            while(it -> next)
            {
                it = it -> next;
            }
            it -> next = head;
            return newHead;
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
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printList(head);

    Solution s1;
    int k = 2;
    ListNode* res = s1.rotateRight(head, k);
    printList(res);
    return 0;
}