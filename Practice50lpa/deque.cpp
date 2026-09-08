#include <iostream>
using namespace std;

class Deque {
    private: 
        int *arr;
        int n;
        int front;
        int rear;
    public:
        Deque(int size) {
            arr = new int[size];
            this -> n = size;
            front = -1;
            rear = -1;
        }

        void pushBack(int val) {
            if (rear == n - 1) {
                cout << "Overflow" << endl;
            }
            else if (front == -1 && rear == -1) {
                // inserting first element
                rear++;
                front++;
                arr[rear] = val;
            }
            else {
                //normal flow
                rear++;
                arr[rear] = val;
            }
        }

        void popFront() {
            if (front == -1 && rear == -1) {
                //Queue is empty
                cout << "Underflow" << endl;
            }
            else if (rear == front) {
                //single element 
                arr[rear] = -1;
                front = -1;
                rear = -1;
            }
            else {
                //normal flow
                arr[front] = -1;
                front++;
            }
        }

        void pushFront(int val) {
            if (front == 0) {
                cout << "Overflow" << endl;
            }
            else if (front == -1 && rear == -1) {
                front++;
                rear++;
                arr[front] = val;
            }
            else {
                front--;
                arr[front] = val;
            }
        }

        void popBack() {
            if(front == -1 && rear == -1) {
                cout << "underflow" << endl;
            }
            else if(front == rear) {
                arr[rear] = -1;
                rear = -1;
                front = -1;
            }
            else {
                arr[rear] = -1;
                rear--;
            }
        }

        void print() {
            for(int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    Deque dq(5);

    dq.pushFront(10);
    dq.print();
    dq.pushFront(20);
    dq.print();
    dq.pushBack(15);
    dq.print();
    dq.pushBack(35);
    dq.print();
    dq.pushFront(100);
    dq.print();
    dq.popFront();
    dq.print();
    dq.popFront();
    dq.print();
    dq.popFront();
    dq.print();
    dq.popFront();
    dq.print();
    // dq.popBack();
    // dq.print();
    // dq.popBack();
    // dq.print();
    // dq.popBack();
    // dq.print();
    // dq.popBack();
    // dq.print();
    return 0;
}
