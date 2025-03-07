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

// TC - O(n) - recrusive  + O(n) - array
// AS - O(n)- Vector + O(h) - tree 
// class Solution {
// public:
//     void solve(TreeNode* root, int k, vector<int> path, int& count) {
//         if (root == NULL)
//             return;
//         path.push_back(root->val);

//         // call for left path
//         solve(root->left, k, path, count);
//         solve(root->right, k, path, count);

//         long long sum = 0;
//         int size = path.size();
//         // traverse the array in revrese
//         for (int i = size - 1; i >= 0; i--) {
//             sum += path[i];
//             if (sum == k)
//                 count++;
//         }
//         // everytime when goginto child not root, we have to remove the chaind
//         // data from the vector
//         path.pop_back();
//     }
//     int pathSum(TreeNode* root, int k) {
//         vector<int> path;
//         int count = 0;
//         solve(root, k, path, count);
//         return count;
//     }
// };