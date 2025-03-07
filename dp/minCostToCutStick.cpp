// 1547. Minimum Cost to Cut a Stickdfhdfldfj

// class Solution
// {
// public:
//     int dp[102][102]; // Memoization table

//     int solve(int i, int j, vector<int> &cuts)
//     {
//         if (i > j)
//             return 0; // No cuts left in this segment

//         if (dp[i][j] != -1)
//             return dp[i][j]; // Memoized result

//         int minCost = INT_MAX;
//         for (int k = i; k <= j; k++)
//         {
//             int cost = cuts[j + 1] - cuts[i - 1] + solve(i, k - 1, cuts) +
//                        solve(k + 1, j, cuts);
//             minCost = min(minCost, cost);
//         }

//         return dp[i][j] = minCost;
//     }
//     int minCost(int n, vector<int> &cuts)
//     {
//         cuts.push_back(0);
//         cuts.push_back(n);
//         sort(cuts.begin(), cuts.end());

//         int m = cuts.size();
//         vector<vector<int>> dp(m, vector<int>(m, 0));

//         for (int length = 2; length < m;
//              length++)
//         { // Start from segment length 2
//             for (int i = 0; i < m - length; i++)
//             {
//                 int j = i + length;
//                 dp[i][j] = INT_MAX;

//                 for (int k = i + 1; k < j; k++)
//                 {
//                     dp[i][j] = min(dp[i][j],
//                                    (cuts[j] - cuts[i]) + dp[i][k] + dp[k][j]);
//                 }
//             }
//         }
//         return dp[0][m - 1]; // Full stick cut cost
//     }
// };