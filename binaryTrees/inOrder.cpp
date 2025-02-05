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

// InOrder => Left,Root,Right
// class Solution {
// public:
//     void inOrderTraverse(TreeNode* root, vector<int>& ans) {

//         if (root == NULL) {
//             return;
//         }

//         inOrderTraverse(root->left, ans);
//         ans.push_back(root->val);
//         inOrderTraverse(root->right, ans);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         inOrderTraverse(root, ans);
//         return ans;
//     }
// };