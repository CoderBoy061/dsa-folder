// 583. Delete Operation for Two Strings
// Solved
// Medium
// Topics
// Companies
// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.

// Example 1:

// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
// Example 2:

// Input: word1 = "leetcode", word2 = "etco"
// Output: 4
// again we will follow the same process how we generated longest common subsequence.
// We know that we should take the longest common staring and jsut need to delete the unmatched string and insert the mastchoing string, We havbe to perform inertion to insert and deletion to delete the unmatched strings
// class Solution
// {
// public:
//     int lcs(string s1, string s2)
//     {
//         int n = s1.size();
//         int m = s2.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
//         for (int i = 0; i <= n; i++)
//         {
//             dp[i][0] = 0;
//         }
//         for (int i = 0; i <= m; i++)
//         {
//             dp[0][i] = 0;
//         }
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 if (s1[i - 1] == s2[j - 1])
//                     dp[i][j] = 1 + dp[i - 1][j - 1];
//                 else
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//         return dp[n][m];
//     }
//     int minDistance(string word1, string word2)
//     {
//         return word1.size() + word2.size() - 2 * lcs(word1, word2);
//     }
// };