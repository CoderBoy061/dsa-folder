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
// TC -O(n)
// SC-O(h) worst case O(n)- incase of skewed tree 
// class Solution {
//     public:
//     // we are follwoign inorder traversal  LNR
//         int solve(TreeNode* root, int& i, int k) {
//             // if root null just send -1
//             if (root == NULL)
//                 return -1;
//                 //first left call
//             int left = solve(root->left, i, k);
//             // if it is not -1, it the ans 
//             if (left != -1)
//                 return left;
//             // if not then we are incremeting the i++
//             i++;
//             // check if the i is == k means the root's is the answer
//             if (i == k)
//                 return root->val;
//             // go to the lft simple
//             return solve(root->right, i, k);
//         }
//         int kthSmallest(TreeNode* root, int k) {
    
//             int i = 0;
//             return solve(root, i, k);
//         }
//     };