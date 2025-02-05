#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

/*
    Majority element means, the element which appears n/2 times in the given array
    here is the example, the majority element is 1, because it apprears 3 times
    because the size of the vector is 6, n/2 means 3, and two appears 3 times
*/

// Brute Force approach - TC - O(n^2)
int majorityElement(vector<int> &nums)
{
    // for storing the frequency of the element
    int freq = 0;
    for (auto value : nums)
    {
        for (auto element : nums)
        {
            if (element == value)
            {
                freq++;
            }
        }

        if (freq > nums.size() / 2)
            return value;
    }
    return -1;
}

// Using Moore's Voting Algorithm

/*
    Moore's Voting Algorithm states that, first maintain a frequency variable and answer variable and initialize with then 0. Now loop and check
    the frequency of every element. if the element is == 0, then simply store that the elemtn into ans varibale
    then check if the nums[i] == ans, means we are stainding into the same elemet, in that case simply update the frequency, otherwise -- the value of frequency

    TC of Moore's Algo is O(n)

*/

int majorityElemntUsingMoores(vector<int> &nums)
{
    int freq = 0, ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (freq == 0)
        {
            ans = nums[i];
        }
        // means we are standing in the same element
        if (ans == nums[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2, 1, 1, 1};

    cout << "The majority element is  " << majorityElemntUsingMoores(nums) << endl;

    return 0;
}