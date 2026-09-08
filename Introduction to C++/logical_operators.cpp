#include <iostream>
using namespace std;
int main()
{
    // AND 
    bool cond1 = true;
    bool cond2 = true;
    bool cond3 = false;

    if (cond1 && cond2 && cond3)
    {
        cout<<"All conditions are true"<<endl;
    }
    else{
        cout<<"All conditions are not true"<<endl;
    }

    // OR

    bool condi1 = (10>5);
    bool condi2 = (5>=5);
    bool condi3 = (2!=2);

    if (condi1 || condi2 || condi3)
    {
        cout<<"At least one condition is true"<<endl;
    }
    else{
        cout<<"All conditions are false";
    }

    // NOT 
    bool condition = (5!=10);
    cout<<!condition<<endl;

    bool condition1 = false;
    cout<<!condition1<<endl;

    return 0;
}