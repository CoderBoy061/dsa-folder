// 120. Triangle
// Solved
// Medium
// Topics
// Companies
// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// Example 2:

// Input: triangle = [[-10]]
// Output: -10
// TC - O(n*n)
// SC - O(n*n)
// class Solution
// {
// public:
//     int recSolve(int i, int j, vector<vector<int>> &triangle, int n)
//     {
//         if (i == n - 1)
//             return triangle[n - 1][j];

//         int d = triangle[i][j] + recSolve(i + 1, j, triangle, n);
//         int dia = triangle[i][j] + recSolve(i + 1, j + 1, triangle, n);
//         return min(d, dia);
//     }

//     int memoSol(int i, int j, vector<vector<int>> &triangle, int n,
//                 vector<vector<int>> &dp)
//     {
//         if (i == n - 1)
//             return triangle[n - 1][j];

//         if (dp[i][i] != -1)
//             return dp[i][j];
//         int d = triangle[i][j] + memoSol(i + 1, j, triangle, n, dp);
//         int dia = triangle[i][j] + memoSol(i + 1, j + 1, triangle, n, dp);
//         return dp[i][j] = min(d, dia);
//     }

//     // int tabuSol(int i, int j, vector<vector<int>>& triangle, int n) {}
//     int minimumTotal(vector<vector<int>> &triangle)
//     {
//         int n = triangle.size();
//         // vector<vector<int>> dp(n, vector<int>(n, -1));
//         vector<vector<int>> dp(n, vector<int>(n, 0));
//         for (int i = 0; i < n; i++)
//         {
//             dp[n - 1][i] = triangle[n - 1][i];
//         }
//         for (int i = n - 2; i >= 0; i--)
//         {
//             for (int j = i; j >= 0; j--)
//             {
//                 int d = triangle[i][j] + dp[i + 1][j];
//                 // memoSol(i + 1, j, triangle, n, dp);
//                 int dia = triangle[i][j] + dp[i + 1][j + 1];

//                 dp[i][j] = min(d, dia);
//                 // memoSol(i + 1, j + 1, triangle, n, dp);
//             }
//         }
//         return dp[0][0];

//         // return memoSol(0, 0, triangle, n, dp);
//         // return recSolve(0, 0, triangle, n);

// vector<int> front(n, 0), cur(n, 0);
// for (int i = 0; i < n; i++)
// {
//     front[i] = triangle[n - 1][i];
// }
// for (int i = n - 2; i >= 0; i--)
// {
//     for (int j = i; j >= 0; j--)
//     {
//         int d = triangle[i][j] + front[j];
//         // memoSol(i + 1, j, triangle, n, dp);
//         int dia = triangle[i][j] + front[j + 1];

//         // dp[i][j] = min(d, dia);
//         cur[j] = min(d, dia);
//         // memoSol(i + 1, j + 1, triangle, n, dp);
//     }
//     front = cur;
// }
// // return dp[0][0];
// return front[0];
//     }
// };