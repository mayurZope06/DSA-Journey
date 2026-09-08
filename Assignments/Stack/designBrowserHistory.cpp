#include <iostream>
#include <stack>
using namespace std;

class BrowserHistory
{
    stack<string> browserStack, fwdStack;
    public:
        BrowserHistory(string homepage)
        {
            browserStack.push(homepage);
        }

        void visit(string url)
        {
            //let's clear all forward history
            while(!fwdStack.empty())
            {
                fwdStack.pop();
            }
            browserStack.push(url);
        }

        string back(int steps)
        {
            while(steps--)
            {
                //ek baar back jayege
                if(browserStack.size() > 1)
                {
                    fwdStack.push(browserStack.top());
                    browserStack.pop();
                }
                else
                {
                    //only homepage is present
                    //back not possible
                    break;
                }
            }
            return browserStack.top();
        }

        string forward (int steps)
        {
            while(steps--)
            {
                if(!fwdStack.empty())
                {
                    browserStack.push(fwdStack.top());
                    fwdStack.pop();
                }
                else
                {
                    break;
                }
            }
            return browserStack.top();
        }
};

int main() {
    BrowserHistory browser("leetcode.com");
    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");

    cout << browser.back(1) << endl;    // facebook.com
    cout << browser.back(1) << endl;    // google.com
    cout << browser.forward(1) << endl; // facebook.com
    browser.visit("linkedin.com");
    cout << browser.forward(2) << endl; // linkedin.com (cannot go forward)
    cout << browser.back(2) << endl;    // google.com
    cout << browser.back(7) << endl;    // leetcode.com

    return 0;
}