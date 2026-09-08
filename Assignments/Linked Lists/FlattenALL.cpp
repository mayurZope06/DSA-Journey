#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

Node* merge (Node* a, Node* b)
{
    if(!a)
        return b;
    
    if(!b)
        return a;

    Node* ans = 0; // 0 -> NULL

    if(a -> data < b -> data)
    {
        ans = a;
        a -> bottom = merge(a -> bottom, b);
    }
    else
    {
        ans = b;
        b -> bottom = merge(a, b -> bottom);
    }
    return ans;
}
Node* flatten (Node* root)
{
    if(!root)
        return 0;
    
    Node* mergedLL = merge(root, flatten(root -> next));

    return mergedLL;
}

int main()
{
    // Create a sample linked list (you can modify this)
    Node* root = new Node(5);
    root->next = new Node(7);
    root->next->next = new Node(8);
    root->next->next->next = new Node(30);

    root->bottom = new Node(10);
    root->bottom->bottom = new Node(20);

    root->next->bottom = new Node(19);
    root->next->bottom->bottom = new Node(22);

    root->next->next->bottom = new Node(50);

    root->next->next->next->bottom = new Node(35);
    root->next->next->next->bottom->bottom = new Node(40);
    root->next->next->next->bottom->bottom->bottom = new Node(45);

    // Flatten the linked list
    Node* flattenedList = flatten(root);

    // Print the flattened list
    Node* temp = flattenedList;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->bottom;
    }
    cout << "NULL" << endl;

    return 0;
}