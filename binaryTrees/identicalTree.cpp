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
/*

        Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
        TC -O(n) AC - O(height of binary tree)
*/
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         // base case
//         if (p == NULL && q == NULL)
//             return true; // if both are null, means identical

//         if (p != NULL && q == NULL)
//             return false;
//         if (p == NULL && q != NULL)
//             return false;

//         bool left = isSameTree(p->left, q->left);
//         bool right = isSameTree(p->right, q->right);
//         bool rootVal = (p->val == q->val);
//         if (left && right && rootVal)
//             return true;
//         else
//             return false;
//     }
// };