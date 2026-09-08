#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class compare{
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;   
        
        ListNode* head = NULL;
        ListNode* tail = NULL;

        //process first k elements
        //hr list ka pehla element pq me insert karna h
        int totalRows = lists.size();

        for(int row=0; row<totalRows; row++) {
            ListNode* temp = lists[row];
            if(temp != NULL) {
                //if its a valid node
                pq.push(temp);
            }
        }

        //main logic 
        while(!pq.empty()) {
            //front nikalo
            ListNode* front = pq.top();
            pq.pop();
            //ans me insert karo
            if(head == NULL && tail == NULL) {
                //it means i am inserting first node in LL
                head = front;
                tail = front;
            }
            else {
                //it means its not the first node
                tail -> next = front;
                tail = front;
            }
            //agar aage node h toh pq me insert karo 
            if(tail->next != NULL) {
                pq.push(tail->next);
            }                
        }
    return head;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> input = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode*> lists;

    // Convert each vector to a linked list
    for (const auto& vec : input) {
        lists.push_back(createLinkedList(vec));
    }

    Solution sol;
    ListNode* mergedHead = sol.mergeKLists(lists);

    cout << "Merged Linked List: ";
    printLinkedList(mergedHead);

    return 0;
}