/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// TC-O(n)
// SC - O(h), worst case O(n) incase of skewed tree 
// class Solution {
//     public:
//         bool solve(TreeNode* root, long long min, long long max){
//             if(root == NULL) return true;
    
//             if(root->val >=max || root->val <=min) return false;
    
//             return solve(root->left, min , root->val) && solve(root->right , root->val, max);
//         }
//         bool isValidBST(TreeNode* root) {
//             long long int min = -1000000000000, max = 1000000000000;
//             return solve(root, min,max);
//         }
//     };