// Shortest Path in Undirected
// Difficulty: MediumAccuracy: 49.98%Submissions: 127K+Points: 4Average Time: 20m
// You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.
// Overall Time Complexity: O((V + E) log V).
// class Solution {
//   public:
//     // Function to find the shortest path from source to all other nodes
//     vector<int> shortestPath(vector<vector<pair<int, int>>>& adj, int src) {
//       int v = adj.size();
//         // Min-heap priority queue {distance, node}
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         vector<int> dist(v, INT_MAX);

//         // Initialize source node
//         dist[src] = 0;
//         pq.push({0, src});  // {distance, node}

//         while (!pq.empty()) {
//             int dis = pq.top().first;   // Distance from source
//             int node = pq.top().second; // Current node
//             pq.pop();

//             for (auto it : adj[node]) {
//                 int adjNode = it.first;  // Neighboring node
//                 int edgeWeight = it.second; // Edge weight

//                 // Relaxation step
//                 if (dis + edgeWeight < dist[adjNode]) {
//                     dist[adjNode] = dis + edgeWeight;
//                     pq.push({dist[adjNode], adjNode});
//                 }
//             }
//         }
//         return dist;
//     }
// };

