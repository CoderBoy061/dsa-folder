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

    A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

    leftHright - rightHeight <=1
    In the Burte force, we are checing the left side and then right right. After that we are checking the height difference for both side and taking the absolute value
    then comparing the three varibnale and returning the result
    So- TC will be O(n^2) - calling the height and isbalnaced both fucntion
    SC - 0(height of the tree)


*/
// class Solution { // Brute Force
// public:
//     int height(TreeNode* root) {
//         if (root == NULL)
//             return 0;
//         int left = height(root->left);
//         int right = height(root->right);
//         int ans = max(left, right) + 1;
//         return ans;
//     }
//     bool isBalanced(TreeNode* root) {

//         if (root == NULL)
//             return true;

//         // check the left subtree
//         bool left = isBalanced(root->left);
//         bool right = isBalanced(root->right);

//         bool diff = abs(height(root->left) - height(root->right)) <= 1;

//         if (left && right && diff) {
//             return true;
//         }

//         return false;
//     }
// };

// we can optimize it, by getting the height and can check if the every nodes are balanced or not?
// we can use the same approach what we used to calculate the diamter of a binary tree

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

//     pair<int, bool> solve(TreeNode* root) {
//         if (root == NULL)
//             return {0, true};
//         // call for the left subtree
//         pair<int, bool> left = solve(root->left);
//         pair<int, bool> right = solve(root->right);
//         bool diff = abs(left.first - right.first) <= 1;

//         if (left.second && right.second && diff) {
//             return {max(left.first, right.first) + 1, true};
//         }
//         return {max(left.first, right.first) + 1, false};
//     }

//     bool isBalanced(TreeNode* root) {

//         if (root == NULL)
//             return true;

//         return solve(root).second;

//     }
// };