// 39. Combination Sum
// Solved
// Medium
// Topics
// Companies
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
// frequency
//  of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:

// Input: candidates = [2], target = 1
// Output: []

// class Solution {
// public:
//     void getAllCombi(vector<int>& arr, int idx, int target,
//                      vector<vector<int>>& ans, vector<int>& combine) {
//         // Base case: if target is met
//         if (target == 0) {
//             ans.push_back(combine);
//             return;
//         }
//         // Base case: if target becomes negative or idx is out of bounds
//         if (target < 0 || idx >= arr.size()) {
//             return;
//         }
//         combine.push_back(arr[idx]);
//         getAllCombi(arr, idx, target - arr[idx], ans,
//                     combine); // Allow reuse of the same element

//         combine.pop_back(); // Backtrack

//         // Exclude the current number and move to the next
//         getAllCombi(arr, idx + 1, target, ans, combine);
//     }

//     vector<vector<int>> combinationSum(vector<int>& arr, int target) {

//         vector<vector<int>> ans;
//         vector<int> combine;
//         // Sort the array to process combinations in a consistent order
//         sort(arr.begin(), arr.end());  (nlogn)

//         getAllCombi(arr, 0, target, ans, combine);

//         return ans;
//     }
// };