
// bool detectCycle(int node, vector<int>& visited, vector<int>& dfsVisited, vector<int> adj[]){

//   // mark the first node and dfs call isvidited

//   visited[node]=1;
//   dfsVisited[node]=1;

//   for(auto neighbour : adj[node]){
//     if(!visited[neighbour]){
//       bool ans = detectCycle(neighbour,visited, dfsVisited, adj);
//       if(ans) return true; 
//     }else if(dfsVisited[neighbour]) return true;
//   }
// markiing the dsfVidisted as false
//   dfsVisited[node]= false;
//   return false;
// }
// int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
//   // Write your code here.

//   // preparing the adjacency list

//   // taking n+1, because its a 1 based indexing graph
//   vector<int> adj[n+1];
//   vector<int>dfsVisited(n+1,0);
//   vector<int>visted(n+1,0);
//   if(n==0) return false;
//   for(int i=0;i<edges.size();i++){
//     int u = edges[i].first;
//     int v = edges[i].second;
//     // because its a directed graph, then the direction will be one direction
//     adj[u].push_back(v);
//   }
//   for(int i=1;i<=n;i++){
//     if(!visted[i]){
//       bool ans = detectCycle(i,visted,dfsVisited,adj);
//       if(ans){
//         return true;
//       }
//     }
//   }
//   return false;
// }