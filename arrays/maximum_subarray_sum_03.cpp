#include <iostream>
#include <limits.h>
using namespace std;

/*
    ***Follow up questions
    1. Why we reset the currenSum after maxSum operation?
    => We do that because, in some cases, the array could contains only negative vales, in that cases, if we reset the currentSum before maxSum, then the answer will be 0, whihc is wrong. the answer should be in -integers

*/
// here we will follow the Kadane's Algo - TC - O(n)
int maximumSubarraySum(int arr[], int n)
{
    int currSum = 0, maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        // adding the current value for calculating the currentSum
        currSum += arr[i];
        maxSum = max(currSum, maxSum);

        // if the currentSum in less than0 or in -negative characters, then simply reset the value of current sum
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}
int main()
{
    int nums[6] = {5, 10, 20, 1, 4, 3};
    int maxSum = INT_MIN;
    int n = 6;

    // this is Brute force approach, which TC - O(n^2);
    for (int st = 0; st < n; st++)
    {
        int currSum = 0;

        for (int end = st; end < n; end++)
        {
            // int his loop, we just need to add the value of end, because we are already getting the first part in the curSum itself
            currSum = currSum + nums[end];
            maxSum = max(currSum, maxSum);
        }
    }

    // using Kadane's algo



    return 0;
}