
// 518. Coin Change II
//     Solved
//         Medium
//             Topics
//                 Companies
//                     You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

//     Return the number of combinations that make up that amount.If that amount of money cannot be made up by any combination of the coins,
//     return 0.

//                You may assume that you have an infinite number of each kind of coin.

//                The answer is guaranteed to fit into a signed 32 -
//                bit integer.

//                Example 1 :

//     Input : amount = 5,
//             coins = [ 1, 2, 5 ] Output : 4 Explanation : there are four ways to make up the amount : 5 = 5 5 = 2 + 2 + 1 5 = 2 + 1 + 1 + 1 5 = 1 + 1 + 1 + 1 + 1 Example 2 :

//     Input : amount = 3,
//             coins = [2] Output : 0 Explanation : the amount of 3 cannot be made up just with coins of 2. Example 3 :

//     Input : amount = 10,
//             coins = [10] Output : 1

// Recursion (Brute Force)	O(2ⁿ * amount)	O(amount) (stack space)	Exponential (worst)
// Memoization (Top-Down)	O(n * amount)	O(n * amount) + O(amount)	Faster but extra space
// Tabulation (Bottom-Up)	O(n * amount)	O(n * amount)	Faster, uses a full DP table
// Space Optimized	O(n * amount)	O(amount)	Best (optimal space)
// class Solution
// {
// public:
//     int recSol(int idx, int t, vector<int> &coins)
//     {
//         // base case
//         if (idx == 0)
//         {
//             if (t % coins[0] == 0)
//                 return 1;
//             else
//                 return 0;
//         }
//         int notTake = recSol(idx - 1, t, coins);

//         int take = 0;
//         if (coins[idx] <= t)
//         {
//             take = recSol(idx, t - coins[idx], coins);
//         }
//         return take + notTake;
//     }
//     int memoSol(int idx, int target, vector<int> &coins,
//                 vector<vector<int>> &dp)
//     {
//         // base case
//         if (idx == 0)
//         {
//             if (target % coins[0] == 0)
//                 return 1;
//             else
//                 return 0;
//         }
//         // if it is already been computed
//         if (dp[idx][target] != -1)
//             return dp[idx][target];
//         int notTake = memoSol(idx - 1, target, coins, dp);
//         int take = 0;
//         if (coins[idx] <= target)
//         {
//             take = memoSol(idx, target - coins[idx], coins, dp);
//         }
//         return dp[idx][target] = take + notTake;
//         // return take + notTake;
//     }
//     int tabuSol(int n, int target, vector<int> &arr)
//     {
//         // base case
//         vector<vector<long long>> dp(
//             n, vector<long long>(target + 1, 0)); // Used long long

//         // Initializing base condition
//         for (int i = 0; i <= target; i++)
//         {
//             if (i % arr[0] == 0)
//                 dp[0][i] = 1;
//             // Else condition is automatically fulfilled,
//             // as dp array is initialized to zero
//         }

//         for (int ind = 1; ind < n; ind++)
//         {
//             for (int t = 0; t <= target; t++)
//             {
//                 long long notTaken = dp[ind - 1][t];

//                 long long taken = 0;
//                 if (arr[ind] <= t)
//                     taken = dp[ind][t - arr[ind]];

//                 dp[ind][t] = notTaken + taken;
//             }
//         }

//         return dp[n - 1][target];
//         // vector<vector<long long>> dp(n, vector<long long>(target + 1, 0));
//         // for (int t = 0; t <= target; t++) {
//         //     dp[0][t] = (t % coins[0] == 0);
//         //     // if (t % coins[0] == 0) {
//         //     //     dp[0][t] = 1;
//         //     // }
//         // }
//         // for (int i = 1; i < n; i++) {
//         //     for (int j = 0; j <= target; j++) {
//         //         long long notTake = dp[i - 1][j];
//         //         long long take = 0;
//         //         if (coins[i] <= j) {
//         //             take = dp[i][j - coins[i]];
//         //         }

//         //         dp[i][j] = take + notTake;
//         //     }
//         // }
//         // return dp[n - 1][target];
//     }

//     // most optimized sol
//     long long optimizedSol(int n, int amount, vector<int> &coins)
//     {
//         vector<uint64_t> prev(amount + 1, 0);

//         // Initialize base condition
//         for (int i = 0; i <= amount; i++)
//         {
//             if (i % coins[0] == 0)
//                 prev[i] = 1;
//         }

//         for (int ind = 1; ind < n; ind++)
//         {
//             vector<uint64_t> cur(amount + 1, 0);
//             for (int target = 0; target <= amount; target++)
//             {
//                 uint64_t notTaken = prev[target];

//                 uint64_t taken = 0;
//                 if (coins[ind] <= target)
//                     taken = cur[target - coins[ind]];

//                 cur[target] = notTaken + taken;
//             }
//             prev = cur;
//         }

//         return prev[amount];
//     }
//     int change(int amount, vector<int> &coins)
//     {
//         int idx = coins.size();
//         // vector<vector<int>> dp(idx, vector<int>(amount + 1, -1));
//         // return recSol(idx-1, amount,coins);
//         // return memoSol(idx - 1, amount, coins, dp);
//         // return tabuSol(idx, amount, coins);
//         return optimizedSol(idx, amount, coins);
//     }
// };