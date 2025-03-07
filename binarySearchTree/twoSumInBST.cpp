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
// Steps:
//     1. we inOrder traversal of BST returns sorted values, so we can use that approach
//     2. we can sotre the values in a vector and the data will be stored in sorted way\
//     3. Then we can perform two pointer approach in that vector and can return the value true or false 
    // 4. Now the Tc - O(n) - In Tree + O(n)- in the array, Sc-o(n)+ O(n) we are using one array to store and recursion for inorder
// class Solution {
//     public:
//         void inorder(TreeNode* root, vector<int>& in) {
//             if (root == NULL)
//                 return;
//             inorder(root->left, in);
//             in.push_back(root->val);
//             inorder(root->right, in);
//         }
//         bool findTarget(TreeNode* root, int k) {
//             vector<int> inOrder;
//             inorder(root, inOrder);
//             int left = 0;
//             int right = inOrder.size() - 1;
    
//             while (left < right) {
//                 int sum = inOrder[left] + inOrder[right];
//                 if (sum == k)
//                     return true;
//                 else if (sum > k) {
//                     right--;
//                 } else
//                     left++;
//             }
//             return false;
//         }
//     };