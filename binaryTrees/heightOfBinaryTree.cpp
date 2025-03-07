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
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         int ans = 0;
//         if (root == NULL)
//             return ans;

//         int leftHeight = maxDepth(root->left); // calculate the left height
//         int rightHeight = maxDepth(root->right); // calculate the right heiight
//         ans = max(leftHeight, rightHeight) + 1; // get the max of both height and add 1 for root node
//         return ans;
//     }
// };