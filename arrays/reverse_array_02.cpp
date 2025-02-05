#include <iostream>
#include <limits.h>
using namespace std;

int main()
{

    int nums[6] = {5, 10, 20, 1, 4, 3};
    int start = 0, end = 6 - 1;
    // beafore reverse
    for(int i=0;i<6;i++){
        cout << nums[i];
    }
    cout<< endl;

    while (start < end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }

    // after reverse
    for(int i=0;i<6;i++){
        cout << nums[i] ;
    }
     cout<< endl;
}