/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// Time Complexity: 
// 𝑂
// (
// 𝑛
// )
// O(n)
// Space Complexity: 
// 𝑂
// (
// 𝑛
// )
// O(n) (excluding the output tree, recursive stack is 
// 𝑂
// (
// log
// ⁡
// 𝑛
// )
// O(logn))
// class Solution {
//     public:
//         TreeNode* solve(vector<int>& nums, int left, int right) {
//             // of the left is greater than right
//             if(left > right) return NULL;
//             // mid 
//             int mid = left +(right-left) / 2;
//             // as we have to create a blanced binary tree so, we will start from the mid
//             TreeNode *root = new TreeNode(nums[mid]);
//             // we all know left side has only smaller elements than root->data
//             root->left = solve(nums,left, mid-1);
//             // right side has greater element than root->data
//             root->right = solve(nums, mid+1, right);
//             return root;
//         }
//         TreeNode* sortedArrayToBST(vector<int>& nums) {
//             // created a node
//             // as the array is sortedwe can use binary serahc 
//             // passing the left, right 
//             return solve(nums, 0, nums.size() - 1);
//         }
//     };