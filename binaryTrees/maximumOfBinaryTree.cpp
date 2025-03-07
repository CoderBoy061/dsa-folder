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
// ===================================TC-O(n), SC-O(n) ===============================
// class Solution {
//     public:
//         int widthOfBinaryTree(TreeNode* root) {
//             int maxWidth = 0;
//             if (!root)
//                 return maxWidth;
    
//             queue<pair<TreeNode*, long long>>
//                 q;            // first node and second for its index
//             q.push({root, 0}); // pusing the first levele and its index wihihc is 0
    
//                 while (!q.empty()) {
//                 int size = q.size(); // size of every element which is inserted in
//                                      // evenry level
//                 long long first = 0;
//                 long long last = 0;
//                 long long minIndex =
//                     q.front()
//                         .second; // taking the minIndex to normalize the indices
//                 for (int i = 0; i < size; i++) {
//                     auto [node, index] =
//                         q.front(); // taking the fist element from the queue
//                     q.pop();       // removing the first element
    
//                     index -= minIndex;
//                     if (i == 0)
//                         first = index;
//                     if (i == size - 1)
//                         last = index;
    
//                     if (node->left)
//                         q.push({node->left, 2 * index + 1});
//                     if (node->right)
//                         q.push({node->right, 2 * index + 2});
//                 }
//                 maxWidth = max(maxWidth, int(last - first + 1));
//             }
//             return maxWidth;
//         }
//     };