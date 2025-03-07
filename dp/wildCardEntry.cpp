/*

44. Wildcard Matching
Solved
Hard
Topics
Companies
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

*/

// class Solution
// {
// public:
//     bool checkForStar(string &p, int j)
//     { // Checking in pattern now
//         for (int i = 1; i <= j; i++)
//         {
//             if (p[i - 1] != '*')
//                 return false;
//         }
//         return true;
//     }

//     bool isMatch(string s, string p)
//     {
//         int n = s.size();
//         int m = p.size();
//         vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false)); // Fixed m+1
//         dp[0][0] = true;

//         // Initialize first row (when s is empty)
//         for (int j = 1; j <= m; j++)
//         {
//             dp[0][j] = checkForStar(p, j); // Fixed to check in p
//         }

//         // Initialize first column (when p is empty)
//         for (int i = 1; i <= n; i++)
//         {
//             dp[i][0] = false; // Pattern empty cannot match non-empty string
//         }

//         // Fill DP table
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 if (s[i - 1] == p[j - 1] ||
//                     p[j - 1] == '?')
//                 { // Check pattern p
//                     dp[i][j] = dp[i - 1][j - 1];
//                 }
//                 else if (p[j - 1] == '*')
//                 { // Star condition
//                     dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
//                 }
//                 else
//                 {
//                     dp[i][j] = false;
//                 }
//             }
//         }
//         return dp[n][m];
//     }
// };