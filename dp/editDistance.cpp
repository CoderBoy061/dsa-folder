/*
72. Edit Distance
Solved
Medium
Topics
Companies
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character


Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/

// class Solution
// {
// public:
//     int f(int i, int j, string &s1, string &s2)
//     {
//         // base case
//         if (i < 0)
//             return j + 1;
//         if (j < 0)
//             return i + 1;

//         if (s1[i] == s2[j])
//             return 0 +
//                    f(i - 1, j - 1, s1, s2); // if matched then we do nothing,
//                                             // just shrinking the strings

//         return 1 + min(f(i - 1, j, s1, s2),
//                        min(f(i, j - 1, s1, s2), f(i - 1, j - 1, s1, s2)));
//     }
//     int memoSol(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
//     {
//         // Base cases
//         if (i < 0)
//             return j + 1;
//         if (j < 0)
//             return i + 1;
//         if (dp[i][j] != -1)
//             return dp[i][j];
//         if (s1[i] == s2[j])
//             return dp[i][j] = 0 + memoSol(s1, s2, i - 1, j - 1, dp);

//         // Minimum of three choices:
//         // 1. Replace the character at S1[i] with the character at S2[j]
//         // 2. Delete the character at S1[i]
//         // 3. Insert the character at S2[j] into S1
//         else
//             return dp[i][j] = 1 + min(memoSol(s1, s2, i - 1, j - 1, dp),
//                                       min(memoSol(s1, s2, i - 1, j, dp),
//                                           memoSol(s1, s2, i, j - 1, dp)));
//     }
//     int minDistance(string word1, string word2)
//     {
//         int n = word1.size();
//         int m = word2.size();
//         // vector<vector<int>> dp(n, vector<int>(m, -1));
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//         // Initialize the first row and column
//         for (int i = 0; i <= n; i++)
//         {
//             dp[i][0] = i;
//         }
//         for (int j = 0; j <= m; j++)
//         {
//             dp[0][j] = j;
//         }

//         // Fill in the DP table
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 if (word1[i - 1] == word2[j - 1])
//                 {
//                     // If the characters match, no additional cost
//                     dp[i][j] = dp[i - 1][j - 1];
//                 }
//                 else
//                 {
//                     // Minimum of three choices:
//                     // 1. Replace the character at S1[i-1] with S2[j-1]
//                     // 2. Delete the character at S1[i-1]
//                     // 3. Insert the character at S2[j-1] into S1
//                     dp[i][j] = 1 + min(dp[i - 1][j - 1],
//                                        min(dp[i - 1][j], dp[i][j - 1]));
//                 }
//             }
//         }

//         // The value at dp[n][m] contains the edit distance
//         return dp[n][m];
//         // return f(n - 1, m - 1, word1, word2);
//         // return memoSol(word1, word2, n - 1, m - 1, dp);
//     }
// };