// 1143. Longest Common Subsequence
//     Solved
//         Medium
//             Topics
//                 Companies
//                     Hint
//                         Given two strings text1 and text2,
//     return the length of their longest common subsequence.If there is no common subsequence, return 0.

//     A subsequence of a string is a new string generated from the original string with some
//     characters(can be none) deleted without changing the relative order of the remaining characters.

//     For example,
//     "ace" is a subsequence of "abcde".A common subsequence of two strings is a subsequence that is common to both strings.

//     Example 1 :

//     Input : text1 = "abcde",
//             text2 = "ace" Output : 3 Explanation : The longest common subsequence is "ace" and its length is 3. Example 2 :

//     Input : text1 = "abc",
//             text2 = "abc" Output : 3 Explanation : The longest common subsequence is "abc" and its length is 3. Example 3 :

//     Input : text1 = "abc",
//             text2 = "def" Output : 0 Explanation : There is no such common subsequence, so the result is 0.

//     class Solution
// {
// public:
//     int recSol(int i, int j, string &text1, string &text2)
//     {
//         // base case
//         if (i < 0 || j < 0)
//             return 0;

//         if (text1[i] == text2[j])
//             return 1 + recSol(i - 1, j - 1, text1, text2);
//         return max(recSol(i - 1, j, text1, text2),
//                    recSol(i, j - 1, text1, text2));
//     }

//     int memoSol(int i, int j, string &text1, string &text2,
//                 vector<vector<int>> &dp)
//     {
//         // base case
//         if (i < 0 || j < 0)
//             return 0;
//         if (dp[i][j] != -1)
//             return dp[i][j];
//         if (text1[i] == text2[j])
//             return dp[i][j] = 1 + memoSol(i - 1, j - 1, text1, text2, dp);
//         return dp[i][j] = max(memoSol(i - 1, j, text1, text2, dp),
//                               memoSol(i, j - 1, text1, text2, dp));
//     }

//     int tabuSol(int n, int m, string &text1, string &text2)
//     {
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//         for (int i = 0; i < n; i++)
//             dp[i][0] = 0;
//         for (int j = 0; j < m; j++)
//             dp[0][j] = 0;

//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 if (text1[i - 1] == text2[j - 1])
//                     dp[i][j] = 1 + dp[i - 1][j - 1];
//                 else
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//         return dp[n][m];
//     }
//     int longestCommonSubsequence(string text1, string text2)
//     {
//         int n = text1.size();
//         int m = text2.size();
//         // vector<vector<int>> dp(n, vector<int>(m, -1));
//         // return recSol(n - 1, m - 1, text1, text2);
//         // return memoSol(n - 1, m - 1, text1, text2, dp);
//         return tabuSol(n, m, text1, text2);
//     }
// };