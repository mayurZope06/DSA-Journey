#include <iostream>
#include <vector>
#include <stack>
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
        vector <int> nextLargerNodes(ListNode* head)
        {
            vector<int> ll;
            while(head)
            {
                ll.push_back(head -> val);
                head = head -> next;
            }
            stack<int> st;

            for(int i = 0; i < ll.size(); ++i)
            {
                while(!st.empty() && ll[i] > ll[st.top()])
                {
                    //means ith element is the next greater of the element index present in the stack
                    int kids = st.top();
                    st.pop();
                    ll[kids] = ll[i];
                }
                st.push(i);
            }
            while(!st.empty())
            {
                ll[st.top()] = 0; st.pop();
            }
            ll[ll.size() - 1] = 0;
            return ll;
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
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(7);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(5);

    printList(head);

    Solution s1;
    vector<int> res = s1.nextLargerNodes(head);
    
    for(auto i: res)
    {
        cout << i << " ";
    }
    return 0;
}