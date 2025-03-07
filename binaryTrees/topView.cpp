// Time Complexity (TC): O(n) (each node is visited once, and map operations are logarithmic in the number of unique levels).

// Auxiliary Space (AS): O(n + h) (queue takes O(n) and map takes O(h)).
// class Solution
// {
// public:
//     // Function to return a list of nodes visible from the top view
//     // from left to right in Binary Tree.
//     vector<int> topView(Node *root)
//     {
//         // code here
//         vector<int> ans;
//         // base case
//         if (root == NULL)
//             return ans;
//         // now take a map to store the value ans its level
//         map<int, int> mp; // first - level, second - data

//         queue<pair<Node *, int>> q; // first will store the node and second will store the level position of that node

//         // push the root inside queue
//         q.push({root, 0}); // pushing the root and its level inside the queue;

//         // check untill q gets empty
//         while (!q.empty())
//         {
//             // take out the first element from the queue

//             pair<Node *, int> top = q.front();
//             q.pop(); // poping the front element

//             Node *node = top.first; // taking the node from the pair

//             int level = top.second;

//             // let check inisde the map if the level is already present or not?

//             if (mp.find(level) == mp.end())
//                 mp[level] = node->data; // mapping the level and its first data

//             // now check of left if exists
//             if (node->left)
//             {
//                 q.push({node->left, level - 1});
//             }
//             if (node->right)
//             {
//                 q.push({node->right, level + 1});
//             }
//         }

//         for (auto it : mp)
//         {
//             ans.push_back(it.second);
//         }
//         return ans;
//     }
// };
