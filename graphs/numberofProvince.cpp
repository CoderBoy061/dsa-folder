// Using Normal DFS 

// class Solution {
//     public:
//         void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
//             visited[node] = 1; // Mark the current node as visited
//             for (int i = 0; i < isConnected.size(); i++) {
//                 // Check if there is a connection and the neighbor is not visited
//                 if (isConnected[node][i] == 1 && !visited[i]) {
//                     dfs(i, isConnected, visited);
//                 }
//             }
//         }
//         int findCircleNum(vector<vector<int>>& isConnected) {
//             int v = isConnected.size(); // Number of nodes
//             vector<int> visited(v, 0);  // Visited array
//             int cnt = 0;
//             for (int i = 0; i < v; i++) {
//                 if (visited[i] == 0) { // If node is not visited
//                     cnt++;             // Increment province count
//                     dfs(i, isConnected,
//                         visited); // Perform DFS to visit all connected nodes
//                 }
//             }
    
//             return cnt; // Return the count of provinces
//         }
//     };

// Using Disjoint Set 