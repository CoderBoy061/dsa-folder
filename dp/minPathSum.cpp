
// 64. Minimum Path Sum
// Solved
// Medium
// Topics
// Companies
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.
// class Solution {
//     public:
//         int recSol(int m, int n, vector<vector<int>>& grid) {
//             if (m == 0 && n == 0)
//                 return grid[0][0];
//             if (m < 0 || n < 0)
//                 return 1e9;
//             int up = grid[m][n] + recSol(m - 1, n, grid);
//             int left = grid[m][n] + recSol(m, n - 1, grid);
//             return min(up, left);
//         }
//         int memoSol(int m, int n, vector<vector<int>>& grid,
//                     vector<vector<int>>& dp) {
//             if (m == 0 && n == 0)
//                 return grid[0][0];
//             if (m < 0 || n < 0)
//                 return 1e9;
//             if (dp[m][n] != -1)
//                 return dp[m][n];
//             int up = grid[m][n] + memoSol(m - 1, n, grid, dp);
//             int left = grid[m][n] + memoSol(m, n - 1, grid, dp);
//             return dp[m][n] = min(up, left);
//         }
//         int tabuSol(int m, int n, vector<vector<int>>& grid) {
//             vector<vector<int>> dp(m, vector<int>(n, 0));
//             for (int i = 0; i < m; i++) {
//                 for (int j = 0; j < n; j++) {
//                     if (i == 0 && j == 0)
//                         dp[i][j] = grid[0][0];
//                     else {
//                         int up = INT_MAX, left = INT_MAX;
//                         if (i > 0)
//                             up = grid[i][j] + dp[i - 1][j];
//                         if (j > 0)
//                             left = grid[i][j] + dp[i][j - 1];
//                         dp[i][j] = min(left, up);
//                     }
//                 }
//             }
//             return dp[m - 1][n - 1];
//         }
//         int minPathSum(vector<vector<int>>& grid) {
//             int m = grid.size();
//             int n = grid[0].size();
//             // vector<vector<int>> dp(m, vector<int>(n, -1));
//             // return memoSol(m - 1, n - 1, grid, dp);
//             return tabuSol(m, n, grid);
//             // return recSol(m - 1, n - 1, grid);
//         }
//     };