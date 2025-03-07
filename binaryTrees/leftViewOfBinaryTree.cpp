// Time Complexity (TC):
// The time complexity is O(n), where n is the number of nodes in the tree. This is because each node is visited exactly once.

// Space Complexity (AS):
// The space complexity is O(n) in the worst case (e.g., a skewed tree), as the queue can hold up to n nodes.

// In a balanced tree, the space complexity is O(w), where w is the maximum width of the tree (number of nodes at the last level).

// class Solution {
// public:
//     vector<int> leftView(Node *root) {
//         vector<int> ans;
//         if (root == NULL) return ans;

//         queue<pair<Node*, int>> q; // node, level
//         q.push({root, 0});

//         int maxLevel = -1; // To track the maximum level reached so far

//         while (!q.empty()) {
//             auto top = q.front();
//             q.pop();

//             Node* node = top.first;
//             int level = top.second;

//             // If this is the first node at this level, add it to the result
//             if (level > maxLevel) {
//                 ans.push_back(node->data);
//                 maxLevel = level;
//             }

//             // Push left child first (to ensure left view)
//             if (node->left) {
//                 q.push({node->left, level + 1});
//             }
//             // Push right child
//             if (node->right) {
//                 q.push({node->right, level + 1});
//             }
//         }

//         return ans;
//     }
// };