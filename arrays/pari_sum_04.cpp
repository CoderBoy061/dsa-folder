#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// this is Brute force approach - whihc TC - O(n^2);
// vector<int> pairSum(vector<int> &arr, int n, int target)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] + arr[j] == target)
//             {
//                 return {i, j};
//             }
//         }
//     }
//     return {-1, -1};
// }

// let's use two pointer approcah

/*

    Approach=>
            1. first we will calculate the starting and ending points, then sum up the both element, if the pair sum is bigger than the target, means the ending element is bigger, so reduce the ending point, means end--;
            2. If the pair sum is lesser than the target sum, simply means starting element is low, just update the starting index, start++
            3. If the sum is equal to the target, then simply return the starting and ending element
            4. Top most important thing, the array should be sorted, make sure the arrary should be shorted

*/

vector<int> pairSumTwoPointer(vector<int> &arr, int n, int target)
{
    int start = 0, end = n - 1;
    while (start < end)
    {
        // means the apir sum is bigger than the target
        if ((arr[start] + arr[end]) > target)
        {
            end--;
        }
        // means the pair sum is smaller than target
        else if ((arr[start] + arr[end]) < target)
        {
            start++;
        }
        else
        {
            return {start, end};
        }
    }
    return {-1, -1};
}

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;
    int n = nums.size();
    vector<int> ans;
    // ans = pairSum(nums, n, target);
    ans = pairSumTwoPointer(nums, n, target);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}