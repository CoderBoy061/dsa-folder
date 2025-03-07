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

//  TC- O(n), SC-O(1) 
// ================================we used morris traversal over here=================================
// class Solution {
//     public:
//         void flatten(TreeNode* root) {
//             if (root == NULL)
//                 return;
//             TreeNode* curr = root;
//             while (curr != NULL) {
//                 // check if the left side is exists for the current node
//                 if (curr->left != NULL) {
//                     TreeNode* prev = curr->left;
//                     // check if the right side exists for the prev node
//                     while (prev->right) {
//                         prev = prev->right; // updating the prev wiht its right
//                                             // child/node
//                     }
    
//                     prev->right = curr->right;
//                     curr->right = curr->left;
//                     curr->left = NULL;
//                 }
    
//                 curr = curr->right;
//             }
//         }
//     };