#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    // pair <datatype 1, dt 2> name;
    //pair <int, char>A;
    //pair <int, char > A(4, 't');
    //pair <int, char>A ={4,'t'};
    //pair <int, char> A = make_pair(4, 't');

    //access
    //cout<<A.first<<" "<<A.second<<" "<<endl;

    //How to use fill in 2D-Array
    int arr[4][3] = { {1,2,3}, {5,6,7}, {9,10,11}, {12,13,14}};

    //fill
    fill(&arr[0][0], &arr[0][0] + (4*3), -1);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        
    }
    

    return 0;

}