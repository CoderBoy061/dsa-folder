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
    for zigzag traversl we have to traverse level order but first level will be left to right and second level will be right to left and we have to  follow the same process untill it gets null

    // we can take a varibale to detrermin weather we have to put left to right or right to left;
    everything is same as level order traverasal, but only one tweak
    // after every level travseral we have to update the leftToRight its opposite state of its current statte

*/
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         // base case
//        vector<vector<int>> result;
//         if (root == NULL)
//             return result;

//         queue<TreeNode*> q;

//         q.push(root);
//         bool leftToRight = true;

//         while (!q.empty()) {
//             // get the sixe of the queye
//             int size = q.size();
//             vector<int> level(size);

//             for (int i = 0; i < size;
//                  i++) { // traverse the enetire size/element of the queye
//                 TreeNode* node = q.front(); // taking the front node
//                 q.pop();                    // poping the current front node

//                 int index = leftToRight ? i : (size-1-i);

//                 level[index] = node->val;

//                 // now check its neighbour nodes
//                 if(node->left != NULL) q.push(node->left);
//                 if(node->right != NULL) q.push(node->right);
//             }
//             result.push_back(level);

//             leftToRight = !leftToRight; // always opposite of the current state 
//         }
//         return result;
//     }
// };