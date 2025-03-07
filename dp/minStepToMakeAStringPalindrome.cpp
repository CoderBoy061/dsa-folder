
// 1312. Minimum Insertion Steps to Make a String Palindrome
//     Solved
//         Hard
//             Topics
//                 Companies
//                     Hint
//                         Given a string s.In one step you can insert any character at any index of the string.

//     Return the minimum number of steps to make s palindrome.

//     A Palindrome String is one that reads the same backward as well as forward.

//     Example 1 :

//     Input : s = "zzazz" Output : 0 Explanation : The string "zzazz" is already palindrome we do not need any insertions.Example 2 :

//     Input : s = "mbadm" Output : 2 Explanation : String can be "mbdadbm" or "mdbabdm".Example 3 :

//     Input : s = "leetcode" Output : 5 Explanation : Inserting 5 characters the string becomes "leetcodocteel".
// Here we just follow the same approach where we generated all the longest palidndromic subsequence and just finlaly returning the n-fucntion length to get the min step
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
//     int longestPalindromeSubseq(string s)
//     {
//         string t = s;
//         reverse(s.begin(), s.end());
//         return lcs(s, t);
//     }
//     int minInsertions(string s)
//     {
//         return s.size() - longestPalindromeSubseq(s);
//     }
// };