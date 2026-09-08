#include <iostream>
using namespace std;

class Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
}

int main()
{
    return 0;
}