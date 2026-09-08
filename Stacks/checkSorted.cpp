#include <iostream>
#include <stack>
#include <climits>
using namespace std;

bool checkSorted(stack <int> &s, int element1)
{
    //base case
    if(s.empty())
    {
        //iska mtlab, l stack poora compare ho chuka h, and poora sorted hai
        return true;
    }

    //1 case solve karna h
    int element2 = s.top();
    s.pop();
    if(element2 < element1)
    {
        //iska mtlab aage check kr skte h
        bool aageKaAns = checkSorted(s, element2);
        s.push(element2);
        return aageKaAns;
    }
    else
    {
        //iska mtlb sorted hi nahi h, aage check krne ki need hi nahi h
        return false;
    }
}

int main()
{
stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  int element1 = INT_MAX;
  cout << checkSorted(s,element1) << endl;
    return 0;
}