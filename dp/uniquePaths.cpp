
// =======================================================62. Unique Paths=========================

// class Solution {
//     public:
//         // basic recrusion TC  - O(2*m*n) Sc - m-i + n-1
//         int recSolve(int m, int n) {
//             if (m == 0 && n == 0)
//                 return 1;
//             if (m < 0 || n < 0)
//                 return 0;
//             int up = recSolve(m - 1, n);
//             int left = recSolve(m, n - 1);
    
//             return left + up;
//         }
    
//         int memoSol(int m, int n, vector<vector<int>>& dp) {
    
//             if (m == 0 && n == 0)
//                 return 1;
//             if (m < 0 || n < 0)
//                 return 0;
    
//             if (dp[m][n] != -1)
//                 return dp[m][n];
    
//             int up = memoSol(m - 1, n, dp);
//             int left = memoSol(m, n - 1, dp);
    
//             return dp[m][n] = left + up;
//         }
//         int tabSol(int m, int n) {
//             vector<vector<int>> dp(m, vector<int>(n, -1));
    
//             for (int i = 0; i < m; i++) {
//                 for (int j = 0; j < n; j++) {
//                     if (i == 0 && j == 0) {
//                         dp[0][0] = 1;
//                     } else {
//                         int up = 0, left = 0;
//                         if (i > 0)
//                             up = dp[i - 1][j];
//                         if (j > 0)
//                             left = dp[i][j - 1];
//                         dp[i][j] = left + up;
//                     }
//                 }
//             }
//             return dp[m - 1][n - 1];
//         }
//         int uniquePaths(int m, int n) {
//             // return recSolve(m - 1, n - 1);
//             // vector<vector<int>> dp(m, vector<int>(n, -1));
//             return tabSol(m, n);
//             // return memoSol(m - 1, n - 1, dp);
//         }
//     };