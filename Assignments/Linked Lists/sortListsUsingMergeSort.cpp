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
        ListNode* findMid(ListNode* head)
        {
            ListNode* slow = head;
            ListNode* fast = head -> next;

            while(fast  && fast -> next)
            {
                slow = slow -> next;
                fast = fast -> next -> next;
            }
            return slow;
        }

        ListNode* merge(ListNode* left, ListNode* right)
        {
            if(left == 0)
                return right;

            if(right == 0)
                return left;

            ListNode* ans = new ListNode(-1);
            ListNode* mptr = ans;

            while(left && right)
            {
                if(left -> val <= right -> val)
                {
                    mptr -> next = left;
                    mptr = left;
                    left = left -> next;
                }
                else
                {
                    mptr -> next = right;
                    mptr = right;
                    right = right -> next;
                }
            }
            if(left)
                mptr -> next = left;
            if(right)
                mptr -> next = right;

            return ans -> next;
        }

        ListNode* sortList(ListNode* head)
        {
            if(head == 0 || head -> next == 0)
            {
                return head;
            }

            //Break LL into two halves using mid node
            ListNode* mid = findMid(head);
            ListNode* left = head;
            ListNode* right = mid -> next;
            mid -> next = 0;

            //sort RE
            left = sortList(left);
            right = sortList(right);

            //merge both left ans and right LL's
            ListNode* mergedLL = merge(left, right);
            return mergedLL;
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
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    printList(head);

    Solution s1;
    ListNode* res = s1.sortList(head);
    printList(res);
    return 0;
}