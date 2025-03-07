/*
1048. Longest String Chain
Solved
Medium
Topics
Companies
Hint
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.



Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.


*/

// class Solution
// {
// public:
//     bool ifPossible(string &s1, string &s2)
//     {
//         if (s1.size() != s2.size() + 1)
//             return false;
//         int i = 0, j = 0;
//         while (i < s1.size())
//         {
//             if (j < s2.size() && s1[i] == s2[j])
//             {
//                 i++;
//                 j++;
//             }
//             else
//                 i++;
//         }
//         if (i == s1.size() && j == s2.size())
//             return true;
//         else
//             return false;
//     }
//     static bool comp(string &s1, string &s2) { return s1.size() < s2.size(); }
//     int longestStrChain(vector<string> &words)
//     {
//         sort(words.begin(), words.end(), comp);
//         int n = words.size();
//         vector<int> dp(n, 1);
//         int maxi = 1;
//         for (int i = 0; i <= n - 1; i++)
//         {
//             for (int prev_index = 0; prev_index <= i - 1; prev_index++)
//             {
//                 if (ifPossible(words[i], words[prev_index]) &&
//                     1 + dp[prev_index] > dp[i])
//                 {
//                     dp[i] = 1 + dp[prev_index];
//                 }
//             }

//             if (dp[i] > maxi)
//                 maxi = dp[i];
//         }
//         return maxi;
//     }
// };