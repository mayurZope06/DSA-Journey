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
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
        {
            ListNode* a = headA;
            ListNode* b = headB;

            while(a -> next && b -> next)
            {
                if(a == b)
                {
                    return a;
                }
                a = a -> next;
                b = b -> next;
            }

            if(a -> next == 0 && b -> next == 0 && a != b)
            {
                return 0;
            }

            if(a -> next == 0)
            {
                //B LL is bigger ya equal hai
                //we need to find out how much bigger it is
                int blen = 0;
                while(b -> next)
                {
                    blen++;
                    b = b -> next;
                }
                while(blen--)
                {
                    headB = headB -> next;
                }
            }
            else
            {
                //A LL is bigger.
                //we need to find out how much bigger it is
                int alen = 0;
                while(a -> next)
                {
                    alen++;
                    a = a -> next;
                }
                while(alen--)
                {
                    headA = headA -> next;
                }
            }
            while(headA != headB)
            {
                headA = headA -> next;
                headB = headB -> next;
            }
            return headA;
        }
};

int main() {
    // Creating intersecting linked lists
    // List A: 4 -> 1 \
    //                 -> 8 -> 4 -> 5
    // List B:    5 -> 6 -> 1 /

    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(4);
    intersect->next->next = new ListNode(5);

    ListNode* listA = new ListNode(4);
    listA->next = new ListNode(1);
    listA->next->next = intersect;

    ListNode* listB = new ListNode(5);
    listB->next = new ListNode(6);
    listB->next->next = new ListNode(1);
    listB->next->next->next = intersect;

    Solution s;
    ListNode* result = s.getIntersectionNode(listA, listB);

    if (result)
        cout << "Intersected at '" << result->val << "'" << endl;
    else
        cout << "No intersection." << endl;

    return 0;
}