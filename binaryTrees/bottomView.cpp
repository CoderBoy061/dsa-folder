


// Time Complexity (TC): O(n) (each node is visited once, and map operations are logarithmic in the number of unique levels).

// Auxiliary Space (AS): O(n + h) (queue takes O(n) and map takes O(h)).
// class Solution {
//   public:
//     vector <int> bottomView(Node *root) {
//         // Your Code Here
//         vector<int>ans;
//         // base case
//         if(root == NULL) return ans;
        
//         // we will be needing a queue
//         queue<pair<Node*,int>>q;  //first- for storing the node, second- for level 
//         map<int,int>mp; // first- level, second- node->val
        
//         // push the first element 
//         q.push({root, 0});
        
//         // check untill queue gets empty
//         while(!q.empty()){
//             // taking the front element
            
//             pair<Node*,int> top = q.front();
//             q.pop();
            
//             Node* node = top.first;
//             int level = top.second;
            
//             // just insert into the map, because map will store the latest element of the level
//             // like first level 0 - 20, 3, 10 , so our ultimate will be 10
//             // just insert, do not check if exist or not? at the end it will tsore the last vale
//             mp[level] = node->data;
            
//             // now traverse to the left and put the value
//             if(node->left){
//                 q.push({node->left, level-1});
                
//             }
//             if(node->right){
//                 q.push({node->right, level+1});
//             }
            
//         }
//         for(auto it: mp){
//             ans.push_back(it.second);
//         }
//         return ans;
//     }
// };



