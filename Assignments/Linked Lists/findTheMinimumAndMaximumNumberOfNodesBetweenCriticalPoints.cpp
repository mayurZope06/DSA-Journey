#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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
        vector<int> nodesBetweenCriticalPoints(ListNode* head)
        {
            vector<int> ans =  {-1, -1}; // min dist, max dist
            ListNode* prev = head;
            if(!prev)
                return ans;
            ListNode* curr = head -> next;
            if(!curr)
                return ans;
            ListNode* nxt = head -> next -> next;
            if(!nxt)
                return ans;
            
            int firstCP = -1;
            int lastCP = -1;
            int minDist = INT_MAX;
            int i = 1;
            while(nxt)
            {
                bool isCP = ((curr -> val > prev -> val && curr -> val > nxt -> val) || (curr -> val < prev -> val && curr -> val < nxt -> val)) ? true : false;

                if(isCP && firstCP == -1)
                {
                    firstCP = i;
                    lastCP = i;
                }
                else if(isCP)
                {
                    minDist = min(minDist, i - lastCP);
                    lastCP = i;
                }
                ++i;
                prev = prev -> next;
                curr = curr -> next;
                nxt = nxt -> next;
            }
            if(lastCP == firstCP)
            {
                // only 1 CP was found;
                return ans;
            }
            else
            {
                ans[0] = minDist;
                ans[1] = lastCP - firstCP;
            }
            return ans;
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
    ListNode* head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(2);

    printList(head);

    Solution s1;
    vector<int> res = s1.nodesBetweenCriticalPoints(head);
    
    for(auto i: res)
    {
        cout << i << endl;
    }
    return 0;
}