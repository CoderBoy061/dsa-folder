// 424. Longest Repeating Character Replacement
//     Medium
//         Topics
//             Companies
//                 You are given a string s and an integer k.You can choose any character of the string and change it to any other uppercase English character.You can perform this operation at most k times.

//     Return the length of the longest substring containing the same letter you can get after performing the above operations.


// Brute Force

// TC- O(n^2), SC - O(256)
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int maxLen = 0;

//         // Try every possible substring starting from index i
//         for (int i = 0; i < s.length(); i++) {
//             unordered_map<char, int> mpp;  // Frequency map for the current window
//             int maxFreq = 0;  // Maximum frequency of a character in the current window

//             // Try every possible substring starting from index j
//             for (int j = i; j < s.length(); j++) {
//                 mpp[s[j]]++;  // Increment the frequency of character s[j]
//                 maxFreq = max(maxFreq, mpp[s[j]]);  // Update the max frequency

//                 // If the current window size minus the max frequency exceeds k, 
//                 // it means we need more than k replacements, so break the loop.
//                 if (j - i + 1 - maxFreq > k) {
//                     break;  // We can't make this window valid, no need to continue expanding.
//                 }

//                 // Otherwise, update the maximum length of a valid window
//                 maxLen = max(maxLen, j - i + 1);
//             }
//         }

//         return maxLen;
//     }
// };
