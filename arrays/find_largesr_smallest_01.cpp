#include <iostream>
#include <limits.h>
using namespace std;

int main()
{

    int nums[6] = {5, 10, 20, 1, 4, 3};
    int smallest = INT_MAX;
    int largest = INT_MIN;

    // find the smallest number

    for (int i = 0; i < 6; i++)
    {
        if (nums[i] < smallest)
        {
            smallest = nums[i];
        }
    }
    // find the largest number
    for (int i = 0; i < 6; i++)
    {
        if (nums[i] > largest)
        {
            largest = nums[i];
        }
    }

    cout<<"smallest number is" << smallest << endl;
    cout << "largest number is" << largest;

    return 0;
}