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
        ListNode* recursive(ListNode* l1, ListNode* l2, int carry = 0)
        {
            if (!l1 && !l2 && !carry)
                return 0;
            
            int a = l1 ? l1 -> val : 0;
            int b = l2 ? l2 -> val : 0;

            int sum = a + b + carry;
            int digit = sum % 10;
            carry = sum / 10;

            //build the ans LL
            ListNode* ans = new ListNode(digit);
            ans -> next = recursive(l1 ? l1 -> next : l1, l2 ? l2 -> next : l2, carry);

            return ans;
        }
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            return recursive(l1, l2);
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
    ListNode* l1 = new ListNode(8);
    l1 -> next = new ListNode(5);
    l1 -> next -> next = new ListNode(9);

    ListNode* l2 = new ListNode(4);
    l2 -> next = new ListNode(7);
    l2 -> next -> next = new ListNode(8);
    l2 -> next -> next -> next = new ListNode(5);

    print(l1);
    print(l2);

    Solution s1;
    ListNode* res = s1.addTwoNumbers(l1, l2);
    print(res);
    return 0;
}