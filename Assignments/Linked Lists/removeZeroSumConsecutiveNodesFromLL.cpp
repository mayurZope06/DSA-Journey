#include <iostream>
#include <unordered_map>
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
        void sanitizeMap(ListNode* head, unordered_map<int, ListNode*> &mp, int csum)
        {
            int temp = csum;

            while(true)
            {
                temp += head -> val;
                if (temp == csum)
                    break;
                
                mp.erase(temp);
                head = head -> next;
            }
        }
        ListNode* removeZeroSumSublists(ListNode* head)
        {
            if(!head || (!head -> next && head -> val == 0))    
                return 0;

            unordered_map <int, ListNode*> mp;
            auto it = head;
            int csum = 0;
            while(it)
            {
                csum += it -> val;
                if(csum == 0)
                {
                    head = it -> next;
                    mp.clear();
                }
                else if(mp.find(csum) != mp.end())
                {
                    sanitizeMap(mp[csum] -> next, mp, csum);
                    mp[csum] -> next = it -> next; 
                }
                else
                {
                    mp[csum] = it;
                }
                it = it -> next;
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    printList(head);

    Solution s1;
    ListNode* res = s1.removeZeroSumSublists(head);
    printList(res);
    return 0;
}