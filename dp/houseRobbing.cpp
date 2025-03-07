// LEETCODE - 198 - House Robber You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// class Solution {
//     public:
//         // plain recursion
//         // Tc - Exponential
//         int sol1(int idx, vector<int>& nums) {
//             if (idx == 0)
//                 return nums[0];
//             if (idx < 0)
//                 return 0;
//             int pick = nums[idx] + sol1(idx - 2, nums);
//             int notPick = 0 + sol1(idx - 1, nums);

//             return max(pick, notPick);
//         }
//         // using memoizatio
//         int sol2(int idx, vector<int>& nums, vector<int>& dp) {
//             if (idx == 0)
//                 return nums[0];
//             if (idx < 0)
//                 return 0;
//             if (dp[idx] != -1)
//                 return dp[idx];
//             int pick = nums[idx] + sol2(idx - 2, nums, dp);
//             int notPick = 0 + sol2(idx - 1, nums, dp);

//             return dp[idx] = max(pick, notPick);
//         }
//         // Tabulation (Bottom-up DP)
//         int sol3(vector<int>& nums) {
//             int n = nums.size();
//             if (n == 0)
//                 return 0;
//             if (n == 1)
//                 return nums[0];
//             vector<int> dp(n, 0);
//             dp[0] = nums[0];
//             dp[1] = max(nums[0], nums[1]);

//             for (int i = 2; i < n; i++) {
//                 int pick = nums[i] + dp[i - 2]; // Include current house
//                 int notPick = dp[i - 1];        // Exclude current house
//                 dp[i] = max(pick, notPick);
//             }
//             return dp[n - 1];
//         }
//         // Optimized Space Complexity (O(1) space)
//         int sol4(vector<int>& nums) {
//             int n = nums.size();
//             if (n == 0)
//                 return 0;
//             if (n == 1)
//                 return nums[0];

//             int prev2 = nums[0];
//             int prev1 = max(nums[0], nums[1]);

//             for (int i = 2; i < n; i++) {
//                 int curr = max(nums[i] + prev2, prev1);
//                 prev2 = prev1;
//                 prev1 = curr;
//             }
//             return prev1;
//         }
//         int rob(vector<int>& nums) {
//             int n = nums.size();
//             // vector<int> dp(n, -1);
//             // return sol3(nums);
//             return sol4(nums);
//             // dp[0] = nums[0];
//             // int negative = 0;

//             // for (int i = 1; i < n; i++) {
//             //     if (i > 2)
//             //         int pick = nums[i] + dp[i - 2];
//             //     if (i > 1) {
//             //         pick += dp[i - 2];
//             //     }
//             //     int notPick = 0 + dp[i - 1];
//             //     dp[i] = max(pick, notPick);
//             // }

//             // for (int i = 1; i < n; i++) {
//             //     int pick = nums[i] + dp(i - 2, nums);
//             //     int notPick = 0 + dp(i - 1, nums);
//             //     dp[i] = max(pic,notPick);
//             // }
//             // return dp[n - 1];

//             // return sol2(n - 1, nums,dp);
//             // return sol3(n - 1, nums);
//             // return sol1(n - 1, nums);
//         }
//     };