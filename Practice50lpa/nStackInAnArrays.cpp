#include <iostream>
using namespace std;

class NStack {
    int *a, *top, *next;
    int n;
    int size;
    int freeSpot;
    public:
        NStack(int _n, int _s) : n(_n), size(_s) {
            freeSpot = 0;
            a = new int [size];
            top = new int[n];
            next = new int [size];

            for(int i = 0; i < n; i++) {
                top[i] -= 1;
            }
            for(int i = 0; i < size; i++) {
                next[i] = i + 1;
            }
            next[size - 1]  = -1;
        }
        bool push(int x, int m) {
            if(freeSpot == - 1) {
                return false;
            }
            int i = freeSpot;

            freeSpot = next[i];

            a[i] = x;

            next[i] = top[m - 1];

            top[m - 1] = i;

            return true;
        }
        bool pop(int m) {
            if(top [m - 1] == -1 ) {
                return -1;
            }
            int index = top[m - 1];
            top[m - 1 ] = next[index];
            int popped = a[index];
            next[index] = freeSpot;
            freeSpot = index;
            return popped;
        }
        ~NStack() {
            delete [] a;
            delete [] top;
            delete [] next;
        }
};

int main()
{
    NStack s(3, 6);
    cout << s.push(10, 1) << endl;
    cout << s.push(10, 1) << endl;
    cout << s.push(10, 1) << endl;
    cout << s.push(14, 2) << endl;
    cout << s.push(15, 3) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(2) << endl;
    return 0;
}