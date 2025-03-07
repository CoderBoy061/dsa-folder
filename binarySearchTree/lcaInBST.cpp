// steps: 
//     1. run the loop untill root becomes nullptr
//     2. if the root->val is greater than the given two nodes go to the left part, because we need the smaller vale
//     3. if not go to the right part, because we need bigger values
//     4. if both are not matching means the current root element is the ancestor
//     5. If not fouund in the loop, means the root is null, simply return NULL 
//      TC -O(n), SC-O(1)

// class Solution {
//     public:
//         TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//             while (root != NULL) {
//                 if (root->val < p->val && root->val < q->val) {
//                     root = root->right;
//                 } else if (root->val > p->val && root->val > q->val) {
//                     root = root->left;
//                 } else{
//                     return root;
//                 }
//             }
//              return NULL;
           
//         }
//     };