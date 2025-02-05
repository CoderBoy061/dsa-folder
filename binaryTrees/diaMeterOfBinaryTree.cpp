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
    A diameter is the distnace between any two nodes.
    every tree can have left diameter, right dia merter and left+right diameter, so we have to take the maximum of them


*/
// class Solution {

// public:
// here the overall Tc- O(n^2) - because we are calling two fucntions, dismter and height
// SC - O(height of the Tree)
// int height(TreeNode* root) {
//     if(root == NULL) return 0;

//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);
//     int ans = max(leftHeight + rightHeight) +1;
//     return ans ;
// }
// int diameter(TreeNode* root) {
//     int ans = 0;
//     if (root == NULL)
//         return ans;
//     int leftDia = diameter(root->left);
//     int rightDia = diameter(root->right);
//     int bothSide = height(root->left) + height(root->right);
// }

/*
   we can optimize it further, like we can take the diamer and height both from the recursive call, so we can reduce the TC
   here the Tc- o(n) and Auxilary SC - 0(height of the tree)
*/

// pair<int,int> solve(TreeNode* root) {

//     if(root == nullptr) return {0,0};
//     // now take out the left diamter and height together
//     pair<int,int>left = solve(root->left);
//     pair<int,int>right = solve(root->right);

//     int leftDia = left.first;
//     int rightDia = right.first;
//     int bothDia = left.second + right.second
//     pair<int,int>ans ;
//     ans.first = max(leftDia,max(rightDia,bothDia));
//     and.second = max(leftDia, rightDia) +1;
// }
//  int diameter(TreeNode* root) {
//     return solve.first;

//     }
// };