// 322. Coin Change
// Medium
// Topics
// Companies
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0

// class Solution
// {
// public:
//     int recSolve(int idx, int target, vector<int> &coins)
//     {
//         // base case
//         if (idx == 0)
//         {
//             if (target % coins[0] == 0)
//                 return target / coins[0];
//             else
//                 return 1e9;
//         }

//         int notTake = 0 + recSolve(idx - 1, target, coins);
//         int take = INT_MAX;
//         if (coins[idx] <= target)
//         {
//             take = 1 + recSolve(idx, target - coins[idx], coins);
//         }
//         return min(take, notTake);
//     }
//     int memoSol(int idx, int target, vector<int> &coins,
//                 vector<vector<int>> &dp)
//     {
//         if (idx == 0)
//         {
//             if (target % coins[0] == 0)
//                 return target / coins[0];
//             else
//                 return 1e9;
//         }
//         if (dp[idx][target] != -1)
//             return dp[idx][target];
//         int notTake = 0 + recSolve(idx - 1, target, coins);
//         int take = INT_MAX;
//         if (coins[idx] <= target)
//         {
//             take = 1 + recSolve(idx, target - coins[idx], coins);
//         }
//         return dp[idx][target] = min(take, notTake);
//     }

//     int tabuSol(int n, int target, vector<int> &coins)
//     {
//         vector<vector<int>> dp(n, vector<int>(target + 1, 1e9));
//         for (int t = 0; t <= target; t++)
//         {
//             if (t % coins[0] == 0)
//             {
//                 dp[0][t] = t / coins[0];
//             }
//             else
//             {
//                 dp[0][t] = 1e9;
//             }
//         }

//         for (int i = 1; i < n; i++)
//         {
//             for (int j = 0; j <= target; j++)
//             {
//                 int notTake = 0 + dp[i - 1][j];
//                 int take = 1e9;
//                 if (coins[i] <= j)
//                 {
//                     take = 1 + dp[i][j - coins[i]];
//                 }

//                 dp[i][j] = min(take, notTake);
//             }
//         }
//         return dp[n - 1][target];
//     }

//     int coinChange(vector<int> &coins, int amount)
//     {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector(amount + 1, -1));
//         // int ans =  recSolve(n - 1, amount, coins);
//         // int ans = memoSol(n - 1, amount, coins, dp);
//         int ans = tabuSol(n, amount, coins);
//         if (ans >= 1e9)
//             return -1;
//         return ans;
//     };
// };