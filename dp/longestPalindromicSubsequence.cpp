
// 516. Longest Palindromic Subsequence
//     Solved
//         Medium
//             Topics
//                 Companies
//                     Given a string s,
//     find the longest palindromic subsequence's length in s.

//         A subsequence is a sequence that can be derived from another sequence by deleting some or
//         no elements without changing the order of the remaining elements.

//         Example 1 :

//     Input : s = "bbbab" Output : 4 Explanation : One possible longest palindromic subsequence is "bbbb".Example 2 :

//     Input : s = "cbbd" Output : 2 Explanation : One possible longest palindromic subsequence is "bb".

// We followed the same approach whihc we fololowed for the l9ongest common subsequence problme.

// class Solution {
//     public:
//         int lcs(string s1, string s2) {
//             int n = s1.size();
//             int m = s2.size();
//             vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
//             for (int i = 0; i <= n; i++) {
//                 dp[i][0] = 0;
//             }
//             for (int i = 0; i <= m; i++) {
//                 dp[0][i] = 0;
//             }
//             for (int i = 1; i <= n; i++) {
//                 for (int j = 1; j <= m; j++) {
//                     if (s1[i - 1] == s2[j - 1])
//                         dp[i][j] = 1 + dp[i - 1][j - 1];
//                     else
//                         dp[i][j] =
//                             max(dp[i - 1][j], dp[i][j - 1]);
//                 }
//             }
//             return dp[n][m];
//         }
//         int longestPalindromeSubseq(string s) {
//             string t = s;
//             reverse(s.begin(), s.end());
//             return lcs(s, t);
//         }
//     };