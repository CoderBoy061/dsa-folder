// 931. Minimum Falling Path Sum
// Solved
// Medium
// Topics
// Companies
// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).


// class Solution
// {
// public:
//     int memoSol(int i, int j, int m, vector<vector<int>> &matrix,
//                 vector<vector<int>> &dp)
//     {
//         // Base Conditions
//         if (j < 0 || j >= m)
//             return 1e9; // Large positive value to avoid selecting this path
//         if (i == 0)
//             return matrix[0][j]; // The first row values remain unchanged

//         if (dp[i][j] != -1)
//             return dp[i][j]; // If already computed, return the stored value

//         // Calculate the minimum path sum by considering three possible moves:
//         // up, left diagonal, and right diagonal
//         int up = matrix[i][j] + memoSol(i - 1, j, m, matrix, dp);
//         int leftDiagonal = matrix[i][j] + memoSol(i - 1, j - 1, m, matrix, dp);
//         int rightDiagonal = matrix[i][j] + memoSol(i - 1, j + 1, m, matrix, dp);

//         // Store the minimum of the three paths in dp
//         return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
//     }
//     int tabulationSol(vector<vector<int>> &matrix)
//     {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         vector<vector<int>> dp(n, vector<int>(m, 0));

//         // Initialize first row with the matrix values itself
//         for (int j = 0; j < m; j++)
//         {
//             dp[0][j] = matrix[0][j];
//         }

//         // Fill the DP table using bottom-up approach
//         for (int i = 1; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 int up = matrix[i][j] + dp[i - 1][j];
//                 int leftDiagonal =
//                     (j > 0) ? matrix[i][j] + dp[i - 1][j - 1] : 1e9;
//                 int rightDiagonal =
//                     (j < m - 1) ? matrix[i][j] + dp[i - 1][j + 1] : 1e9;

//                 dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
//             }
//         }

//         // Find the minimum value in the last row
//         int mini = INT_MAX;
//         for (int j = 0; j < m; j++)
//         {
//             mini = min(mini, dp[n - 1][j]);
//         }

//         return mini;
//     }
//     int minFallingPathSum(vector<vector<int>> &matrix)
//     {
//         return tabulationSol(matrix);
//         // int n = matrix.size();    // Number of rows in the matrix
//         // int m = matrix[0].size(); // Number of columns in the matrix

//         // vector<vector<int>> dp(n, vector<int>(m, -1)); // Memoization table

//         // int mini = INT_MAX; // Initialize the minimum path sum to a large value

//         // // Try all starting points from the last row
//         // for (int j = 0; j < m; j++) {
//         //     int ans = memoSol(n - 1, j, m, matrix, dp);
//         //     mini = min(mini, ans); // Update the minimum path sum
//         // }

//         // return mini; // Return the minimum falling path sum
//     }
// };