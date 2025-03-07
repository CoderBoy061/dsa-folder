// 81. Search in Rotated Sorted Array II
// Solved
// Medium
// Topics
// Companies
// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

// You must decrease the overall operation steps as much as possible.

 

// Example 1:

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
// Example 2:

// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false


/*

    This question is the same as the previous one, but it can contains duplicates. so the approach wuill be same, but we can add a seprate conditon 
    to element the serach space just checki if(arr[low]== arr[mid] && arr[mid] == arr[end]) low++, end-- ; continue

*/

// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         int s = 0, end = nums.size() - 1;
//         while (s <= end) {
//             int mid = s + (end - s) / 2;
//             if (nums[mid] == target)
//                 return true;

//             if (nums[s] == nums[mid] && nums[mid] == nums[end]) {
//                 s++;
//                 end--;
//                 continue;
//             }

//             // now check for which part is sorter

//             // means the left part is sorted, we can perform the binary serashc
//             // in the left part
//             if (nums[s] <= nums[mid]) {
//                 // if the target is greater than or equal to nums[s] && target
//                 // is lwer than equal to mid
//                 if (target >= nums[s] && target <= nums[mid]) {
//                     // means we have to update the end
//                     end = mid - 1;
//                 } else {
//                     s = mid + 1;
//                 }
//             } else {
//                 // means the right part is sorted
//                 if (target >= nums[mid] && target <= nums[end]) {
//                     s = mid + 1;
//                 } else {
//                     end = mid - 1;
//                 }
//             }
//         }

//         return false;
//     }
// };