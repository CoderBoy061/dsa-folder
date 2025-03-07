
// TC - O(n+e)
// Sc - O(n+e)
// vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
//     // this is zero based indexisng graph and also the adj matrix is given, so we have to conver it into the adlist
//     int v = adj.size(); // taking the size of the adj list
//     vector<int>ans; // for returning the ans
//     vector<bool>visited(v, false); // viisted list, 
//     //vecause its a 0 based oindsexing graph so we are just taking the v, if it is 1 base then we would take v+1
//     queue<int>q;
//     q.push(0); // because its a 0 based indexing
//     visited[0] = true;

//     while(!q.empty()){
//         int node = q.front();
//         q.pop();
//         ans.push_back(node); // pushing the node inside the array

//         for(auto neighbour : adj[node]){
//             if(!visited[neighbour]){
//                 q.push(neighbour);
//                 visited[neighbour]= true;
//             }
//         }
//     }
//     return ans;
// }