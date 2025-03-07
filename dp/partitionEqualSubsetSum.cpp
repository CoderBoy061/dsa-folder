// 416. Partition Equal Subset Sum
// Solved
// Medium
// Topics
// Companies
// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
// TC - O(n*target)
// Sc - O(n*target)
// class Solution
// {
// public:
//     // bool memoSolve(int n, int target ,vector<int>& nums ,vector<vector<int>>
//     // &dp) {
//     //     if(target ==0) return true;
//     //     if(n == 0) return (nums[0]==target);
//     //     if(dp[n][target] != -1) return dp[n][target];
//     //     bool notTake = memoSolve(n-1,target,nums,dp);
//     //     bool take = false;
//     //     if(nums[n] <= target){
//     //         take = memoSolve(n-1,target-nums[n],nums,dp);
//     //     }

//     //     return dp[n][target] = take || notTake;

//     // }
//     bool canPartition(vector<int> &nums)
//     {
//         int n = nums.size();
//         int totSum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             totSum += nums[i];
//         }
//         if (totSum % 2)
//             return false;

//         int target = totSum / 2;
//         vector<vector<int>> dp(n, vector<int>(target + 1, 0));
//         // base case
//         for (int i = 0; i < n; i++)
//         {
//             dp[i][0] = true;
//         }
//         if (nums[0] <= target)
//             dp[0][nums[0]] = true;
//         // Fill in the DP table using a bottom-up approach
//         for (int ind = 1; ind < n; ind++)
//         {
//             for (int k = 1; k <= target; k++)
//             {
//                 bool notTaken = dp[ind - 1][k];
//                 bool taken = false;
//                 if (nums[ind] <= k)
//                     taken = dp[ind - 1][k - nums[ind]];

//                 // Update the DP table
//                 dp[ind][k] = notTaken || taken;
//             }
//         }
//         return dp[n - 1][target];
//     }
// };