#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
    public:
        Node* helper (Node* head, unordered_map<Node*, Node*> &mp)
        {
            if(head == 0) // NULL
                return 0;

            Node* newHead = new Node(head -> val);
            mp[head] = newHead;

            newHead -> next = helper(head -> next, mp);

            if(head -> random)
                newHead -> random = mp[head -> random];

            return newHead;
        }
        Node* copyRandomList (Node* head)
        {
            unordered_map<Node*, Node*> mp;

            //old node -> new node
            return helper(head, mp);
        }
};

int main()
{
    // Example usage:
    // 1 -> 2 -> 3 
    // random pointers: 1 -> 3, 2 -> 1, 3 -> NULL

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->random = head->next->next; 
    head->next->random = head;

    Solution solution;
    Node* clonedHead = solution.copyRandomList(head);

    // Print the cloned list (for verification)
    Node* curr = clonedHead;
    while (curr) {
        cout << curr->val << " ";
        if (curr->random) {
            cout << "-> " << curr->random->val;
        }
        cout << endl;
        curr = curr->next;
    }

    return 0;
}