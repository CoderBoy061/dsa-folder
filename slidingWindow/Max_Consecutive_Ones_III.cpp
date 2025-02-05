#include <iostream>
#include <vector>

using namespace std;

// brute force solution
/*
    In the brute force the outer loop will run n times, where the inner loop will near near about n time, so we can say the overall Tc- O(n^2) and SC-O(1), because we are not using any extra space

*/
int maxOne(vector<int> &nums, int k, int n)
{
    //

    int mxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int zeros = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[j] == 0)
                zeros++;
            else if (zeros <= k)
            {
                int len = j - i + 1;
                mxLen = max(mxLen, len);
            }
        }
    }
    return mxLen;
}

int optimizedMaxOne(vector<int> &nums, int k, int n)
{
    int left = 0;
    int right = 0;
    int maxLen = 0;
    int zeros = 0;

    while (right < n)
    {

        // check if the element is equal to 0
        if (nums[right] == 0)
            zeros++; // if it is 0, the update the zeros count

        if (zeros > k)
        { // if the zeros count become more than the permisibble, lets auusme k=2 and if the zero becomes 3 , the we have to update the left pointer and if we found that the left elemtn is 0, we can decreement the size of the zero to make a maximum window
            if (nums[left] == 0) zeros--; // decrementing the zeros count if the left is 0
            left++; // updatiung the left pointer by one
        }
        if (zeros <= k)
        { // if the zeros count is less than or equal to kay, then we can take the size of the window and update the max length
            int len = right - left + 1;
            maxLen = max(maxLen, len);
        }

        right++; // moving the right pointer to its next, because only the right pointer will move un till we got specfic condtion
    }
}

int main()
{
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    int n = nums.size();
    // int ans = maxOne(nums, k, n);
    int ans = optimizedMaxOne(nums, k, n);
    cout << ans << endl;

    return 0;
}