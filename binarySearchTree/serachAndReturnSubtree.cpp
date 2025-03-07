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
// TC - for best case  O(logN), for worst O(n)
// SC - O(logN) - best case, worst O(n)
// class Solution {
//     public:
//         TreeNode* searchBST(TreeNode* root, int val) {
    
//             if (root == NULL)
//                 return NULL;
    
//             // check if the root's data is similar to the val
//             if (root->val == val) {
//                 return root;
//             }
//             else if (root->val > val) {
//                 return searchBST(root->left, val);
    
//             } else {
//                 return searchBST(root->right, val);
//             }
//         }
//     };