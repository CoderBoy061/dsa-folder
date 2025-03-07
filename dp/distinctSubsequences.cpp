// 115. Distinct Subsequences
//     Solved
//         Hard
//             Topics
//                 Companies
//                     Given two strings s and t,
//     return the number of distinct subsequences of s which equals t.

//                The test cases are generated so that the answer fits on a 32 -
//                bit signed integer.

//                Example 1 :

//     Input : s = "rabbbit",
//             t = "rabbit" Output : 3 Explanation : As shown below, there are 3 ways you can generate "rabbit" from s.rabbbit rabbbit rabbbit Example 2 :

//     Input : s = "babgbag",
//             t = "bag" Output : 5 Explanation : As shown below, there are 5 ways you can generate "bag" from s.babgbag babgbag babgbag babgbag babgbag

// In the recursive logic, we set the base case too if(i<0 ) and if(j<0) but we can’t set the dp array’s index to -1. Therefore a hack for this issue is to shift every index by 1 towards the right.
// First we initialize the dp array of size [n+1][m+1] as zero.
// Next, we set the base condition (keep in mind 1-based indexing), we set the first column’s value as 1 and the first row as 1.
// Similarly, we will implement the recursive code by keeping in mind the shifting of indexes, therefore S1[i] will be converted to S1[i-1]. Same for S2.
// At last, we will print dp[N][M] as our answer.

// class Solution
// {
// public:
//     int numDistinct(string s, string t)
//     {
//         int n = s.size();
//         int m = t.size();

//         vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

//         for (int i = 0; i <= n; i++)
//             dp[i][0] = 1;

//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 if (s[i - 1] == t[j - 1])
//                 {
//                     dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//                 }
//                 else
//                 {
//                     dp[i][j] = dp[i - 1][j];
//                 }
//             }
//         }
//         return (int)dp[n][m];
//     }
// };