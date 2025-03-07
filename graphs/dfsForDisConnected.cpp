
// TC- O(V+E)
// SC-O(V+E)
// void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &component) {
//     visited[node] = true;
//     component.push_back(node);

//     for (int neighbor : adj[node]) {
//         if (!visited[neighbor]) {
//             dfs(neighbor, adj, visited, component);
//         }
//     }
// }
// vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
// {
//     vector<vector<int>> adj(V); // Corrected adjacency list initialization
//     vector<vector<int>> ans; // Corrected return type

//     // Prepare the adjacency list
//     for (auto &edge : edges) {
//         int u = edge[0], v = edge[1];
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     vector<bool> visited(V, false); // Track visited nodes

//     // Traverse all components
//     for (int i = 0; i < V; i++) {
//         if (!visited[i]) {
//             vector<int> component;
//             dfs(i, adj, visited, component);
//             ans.push_back(component);
//         }
//     }

//     return ans;
// }