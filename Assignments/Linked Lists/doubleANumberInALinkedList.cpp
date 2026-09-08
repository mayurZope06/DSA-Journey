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
        void Solve(ListNode* head, int &carry)
        {
            if(!head)
                return;

            Solve(head -> next, carry);

            //1 case solve
            int prod = head -> val * 2 + carry;
            head -> val = prod % 10;
            carry = prod / 10;
        }
        ListNode* doubleLeft (ListNode* head)
        {
            int carry = 0;
            Solve(head, carry);

            if(carry)
            {
                ListNode* carryNode = new ListNode(carry);
                carryNode -> next = head;
                head = carryNode;
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
    ListNode* head = new ListNode(1);
    head->next = new ListNode(8);
    head->next->next = new ListNode(9);

    // ListNode* head = new ListNode(9);
    // head->next = new ListNode(9);
    // head->next->next = new ListNode(9);

    printList(head);

    Solution s1;
    ListNode* res = s1.doubleLeft(head);
    printList(res);
    return 0;
}