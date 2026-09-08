#include <iostream>
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
        Node* copyRandomList (Node* head)
        {
            if(!head)
                return 0;
            
            //Step 1 : clone A -> A'
            Node* it = head; // iterate over old head

            while(it)
            {
                Node* clonedNode = new Node(it -> val);
                clonedNode -> next = it -> next;
                it -> next = clonedNode;
                it = it -> next -> next;
            }

            //Step 2 : Assign random links of A' with th helper of A
            it = head;
            while(it)
            {
                Node* clonedNode = it -> next;
                clonedNode -> random = it -> random ? it -> random -> next : nullptr;
                it = it -> next -> next;
            }

            //Step 3 : Detach A from A
            it = head;
            Node* clonedHead = it -> next;
            while(it)
            {
                Node* clonedNode = it -> next;
                it -> next = it -> next -> next;
                
                if(clonedNode -> next)
                {
                    clonedNode -> next = clonedNode -> next -> next;
                }
                it = it -> next;
            }
            return clonedHead;
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