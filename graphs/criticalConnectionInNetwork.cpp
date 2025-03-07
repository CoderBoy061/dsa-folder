// /
// 1192. Critical Connections in a Network
// Solved
// Hard
// Topics
// Companies
// Hint
// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Return all critical connections in the network in any order.
// TC - O(V+2E)
// O(V+2E)+O(V)+O(V)+O(V)+O(V)+O(V)=O(V+2E)

// / class Solution {
//     private:
//         int timer = 1;
//         void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj,
//                  int tin[], int low[], vector<vector<int>>& bridges) {
//             vis[node] = 1;
//             tin[node] = low[node] = timer; // intiaally both will be 1;
//             timer++;                       // increement the timer
//             for (auto it : adj[node]) {
//                 if (it == parent)
//                     continue; // if the adjancemt is the aprent himself, then just
//                               // continue, do nothing
//                 if (vis[it] == 0) {
//                     dfs(it, node, vis, adj, tin, low, bridges);
//                     low[node] = min(low[node], low[it]);
//                     if (low[it] > tin[node]) {
//                         bridges.push_back({it, node});
//                     }
//                 } else {
//                     low[node] =
//                         min(low[node],
//                             low[it]); // updating the stesp and taking the minimum
//                 }
//             }
//         };
    
//     public:
//         vector<vector<int>> criticalConnections(int n,
//                                                 vector<vector<int>>& connections) {
//             vector<vector<int>> adj(n);
    
//             // preapring the graph
//             for (auto it : connections) {
//                 adj[it[0]].push_back(it[1]);
//                 adj[it[1]].push_back(it[0]);
//             }
//             vector<int> vis(n, 0); // 0 based graph
//             int low[n];
//             int tin[n];
//             vector<vector<int>> bridges;
//             dfs(0, -1, vis, adj, tin, low, bridges);
//             return bridges;
//         }
//     };