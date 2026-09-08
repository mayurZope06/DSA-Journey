#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N = 0;
        auto it = head; // ListNode* it = head;
        while(it)
        {
            N++;
            it = it -> next;
        }
        // determine size of each part/ bucket
        int partSize = N / k;
        int extraNodes = N % k; // divide bucket by bucket

        vector<ListNode*> ans (k, nullptr);
        it = head;
        for(int i = 0; i < k && it; i++)
        {
            ans[i] = it;
            int currentPartSize = partSize + (extraNodes-- > 0 ? 1 : 0);

            for(int j = 0; j < currentPartSize - 1; j++)
            {
                it = it -> next;
            }
            auto nextPartStarting = it -> next;
            it -> next = nullptr;
            it = nextPartStarting;
        }
        return ans;
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
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    ListNode* sixth = new ListNode(6);
    ListNode* seventh = new ListNode(7);
    ListNode* eigth = new ListNode(8);
    ListNode* nineth = new ListNode(9);
    ListNode* tenth = new ListNode(10);
    ListNode* eleventh = new ListNode(11);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eigth;
    eigth->next = nineth;
    nineth->next = tenth;
    tenth->next = eleventh;

    print(head);

    Solution s1;
    vector<ListNode*> res = s1.splitListToParts(head, 3);
    for(auto i: res)
        print(i);
    return 0;
}