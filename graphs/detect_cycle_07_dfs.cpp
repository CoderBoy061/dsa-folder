
// ==============================Detect Cycle using DFS connected undirected graph===========================
// helper function for detect cycle
// bool detectCycleDFS(int srcNode, int parent ,vector<int> &visited,vector<vector<int>> adj ){
//     // marking the first node as visited
//     visited[srcNode]=1;

//     // traversing all the neighbour nodes of the current node
//     for(auto it: adj[srcNode]){
//         // if it is not visited, then call the recursion fucntion again and store the ans again
//         if(!visited[it]){
//             bool ans = detectCycleDFS(it, srcNode , visited, adj);
//             if(ans == 1) return true;
//         } 
//         // if the parent ois not equal to the current node, then it means it a cycle, so simply retunr the true
//         else if(parent != it) {
//             return true;
//         }
//     }
//     return false;

// }


// fucntion will given by the code 
// bool isCycle(vector<vector<int>> adj){

//     // getting the size of vertexes
//     int v = adj.size();
//     // for 1 based indexing
//     if(v==0) return false;
//     vector<int> visited(v+1,0);
    
//     for(int i=0;i<v;i++){
//         if(!visited[i]){
//             bool ans = detectCycle(i,visted,adj);
//             if(ans){
//                 return true;
//             }
//         }
//     }
//     return false;

// }