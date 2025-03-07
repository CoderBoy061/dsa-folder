// Time Complexity (TC):
// The time complexity is O(n), where n is the number of nodes in the tree. This is because each node is visited exactly once.

// Space Complexity (AS):
// The space complexity is O(n) in the worst case (e.g., a skewed tree), as the queue can hold up to n nodes.

// In a balanced tree, the space complexity is O(w), where w is the maximum width of the tree (number of nodes at the last level).
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> ans;
//         // base case
//         if (root == NULL)
//             return ans;

//         queue<pair<TreeNode*, int>> q;
//         int maxLevel = INT_MIN; // to track the level of the tree
//         q.push({root, 0}); // pushing the first node and its level

//         while (!q.empty()) {
//             pair<TreeNode*, int> top = q.front();
//             q.pop();
//             TreeNode* node = top.first;
//             int level = top.second;

//             if (level > maxLevel) {
//                 ans.push_back(node->val);
//                 maxLevel = level;
//             }

//             // now go to right side, because we have to take the right most node
//             if (node->right) {
//                 q.push({node->right, level + 1}); // increement the level
//             }
//             // go to the left and incement the level as well. but stiill it
//             // will take the right most invccase both side are present, if not
//             // then it will take the left node and its data
//             if (node->left) {
//                 q.push({node->left, level + 1});
//             }
//         }
//         return ans;
//     }
// };