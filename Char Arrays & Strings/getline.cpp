#include <iostream>
using namespace std;
int main()
{
    char arr[100];
    cout<<"Enter input: "<<endl;
    cin.getline(arr, 80, '\t');
    cout<<endl<<arr<<endl;

    return 0;
}
