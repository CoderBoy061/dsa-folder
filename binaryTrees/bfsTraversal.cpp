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
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>>ans;
//         if(root == NULL) return ans;
//         queue<TreeNode*>q;
//         q.push(root); // pushing the root data

//         while(!q.empty()){ // traverse untill the queue become empty
//             int size = q.size();
//             vector<int>level;
//             for(int i=0;i<size;i++){
//                 TreeNode *node = q.front();  // taking the first elemt
//                 q.pop(); // removing that elemtn from queue

//                 // checking if the lest is exiasts
//                 if(node->left != NULL) q.push(node->left);
//                 if(node->right !=NULL) q.push(node->right);
//                 level.push_back(node->val);
//             }
//             ans.push_back(level);
//         }
//         return ans;
//     }
// };