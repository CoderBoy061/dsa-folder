/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself)
/*
    TC - We are traversing each nodes single time so the time complexity will be O(n);
    AS - O(h- height of thr tree), in worst case the height can be O(n)

*/
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

//         // base case
//         if (root == NULL)
//             return NULL;

//         // check if the starting root is ans or not?
//         if (root== p|| root == q) {
//             return root;
//         }

//         TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
//         TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

//         // we can have three case

//         if (leftAns != NULL && rightAns != NULL) {
//             return root;
//         }
//         // if the leftAns is null but right not, in that case we will return the
//         // rightAms;
//         else if (leftAns == NULL && rightAns != NULL) {
//             return rightAns;
//         } else if (leftAns != NULL && rightAns == NULL) {
//             return leftAns;
//         } else
//             return NULL;
//     }
// };