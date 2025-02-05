#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {1, 1, 0, 0, 0, 2, 2, 2, 1, 1};

    // now the Brute force TC - O(nlogn)
    // sort(nums.begin(), nums.end());

    // now optimized using two pass TC -O(2n)- if we ignore the constant it will be O(n)
    // int zeros = 0, ones = 0, twos = 0;

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i] == 0)
    //         zeros++;
    //     else if (nums[i] == 1)
    //         ones++;
    //     else
    //         twos++;
    // }
    // int idx=0;
    // for (int i = 0; i < zeros; i++)
    // {
    //     nums[idx++] = 0;
    // }
    // for (int i = 0; i < ones; i++)
    // {
    //     nums[idx++] = 1;
    // }
    // for (int i = 0; i < twos; i++)
    // {
    //     nums[idx++] = 2;
    // }

    // Optimal, DUTCH NATIONAL FLAG ALGO
    // we can use three pointer approach TC - O(n)

    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++,mid++;
        }
        else if (nums[mid] == 1)
            mid++;

        else
        {
            swap(nums[high], nums[mid]);
            high--;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}