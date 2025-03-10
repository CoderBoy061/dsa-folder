// 33. Search in Rotated Sorted Array
// Solved
// Medium
// Topics
// Companies
// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1

/*

    Approach - The array can be sorted in the ascending order or descending order, but we dont know whihc part is sorted and whihc way?
    So, we can follow the simply binary serahc but in some modify way. 
    After calculting the mid, we can check if the mid is == target? is yes then simply return the mid
    Otherwise, we check decide which part, where our target can lie. So, we can add simple conditons
            if(target <=arr[mid] && target >=arr[mid]) // menas serahc in the left part and elemenate the right part
            else Search in the right part and elemenate the left part
*/

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int st = 0, end = nums.size() - 1;

//         while (st <= end) {
//             int mid = st + (end - st) / 2;
//             if (nums[mid] == target)
//                 return mid;

//             // now we have to check whihc part is sorted

//             if (nums[st] <= nums[mid]) { // means letf part is sorted

//                 if (nums[st] <= target && target <= nums[mid]) {
//                     // update the
//                     end = mid - 1;
//                 } else {
//                     st = mid + 1;
//                 }

//             } else { // means right part is sorted
//                 if (nums[mid] <= target && target <= nums[end]) {
//                     st = mid + 1;
//                 } else {
//                     end = mid - 1;
//                 }
//             }
//         }
//         return -1;
//     }
// };