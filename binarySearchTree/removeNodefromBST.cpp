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
// Tc - Best Case O(logN) worst case O(n)?
// SC - Best Case O(logN) worst case O(n)
// class Solution {
//     public:
//         TreeNode* minFromRight(TreeNode* node) {
//             while (node->left) {
//                 node = node->left;
//             }
//             return node;
//         }
//         TreeNode* deleteNode(TreeNode* root, int key) {
//             if (root == NULL)
//                 return NULL;
//             else if (root->val > key) {
//                 root->left = deleteNode(root->left, key);
//             } else if (root->val < key) {
//                 root->right = deleteNode(root->right, key);
//             } else {
    
//                 // handle login for 0 child
//                 if (root->left == NULL && root->right == NULL) {
//                     delete root;
//                     return NULL;
//                 }
    
//                 // handle logic for left child
//                 else if (root->left != NULL && root->right == NULL) {
//                     TreeNode* temp = root->left;
//                     delete root;
//                     return temp;
//                 }
    
//                 else if (root->left == NULL && root->right != NULL) {
//                     TreeNode* temp = root->right;
//                     delete root;
//                     return temp;
//                 } else {
//                     TreeNode* nodeToReplace = minFromRight(root->right);
//                     root->val = nodeToReplace->val;
//                     root->right = deleteNode(root->right, nodeToReplace->val);
//                 }
//             }
    
//             return root;
//         }
//     };