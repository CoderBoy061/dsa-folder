// fuction given in the programm
<<<<<<< HEAD
=======
// ==================================Detect cycle in the Undirected connected graphs================================
// ===========================  TC - O(n+2e)
// ===========================  SC - O(n) 
>>>>>>> dev2

// fucntion we need to prepare
// bool detectCycle(int srcNode , vector<int> &visited, vector<vector<int>> adj) {

//     visited[srcNode] = 1;
//     queue<pair<int,int>>q;
//     q.push({srcNode, -1});

//     while(!q.empty()) {
//         int front = q.front().first;
//         int parent = q.front().second;
//         q.pop();

//         for(auto it: adj[front]){

//             // if it is visited and not the parent node
//             if(visited[it] && parent != it){
//                 return true;
//             } else if(!visited[it]){
//                 visited[it] =1;
//                 q.push({it,parent});
                
//             }
//         }
//     }
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