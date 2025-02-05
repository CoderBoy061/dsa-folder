

/*

    calculate the shortest to reach from one node to another using Djikstra's algorithm
    Complexity:
    Time Complexity:
Insertion and deletion in set take
𝑂
(
log
⁡
𝑛
)
O(logn), so the overall complexity is
𝑂
(
(
𝑉
+
𝐸
)
log
⁡
𝑉
)
O((V+E)logV), where
𝑉
V is the number of vertices and
𝐸
E is the number of edges.
Space Complexity:
𝑂
(
𝑉
+
𝐸
)
O(V+E) for the adjacency list and distance array, plus
𝑂
(
𝑉
)
O(V) for the set.

*/
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
//     // Prepare adjacency list
//     unordered_map<int, list<pair<int, int>>> adj;
//     for (int i = 0; i < edges; i++) {
//         int u = vec[i][0];
//         int v = vec[i][1];
//         int w = vec[i][2];

//         // As this is an undirected graph
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     }

//     // Distance array to store the shortest distances
//     vector<int> distance(vertices, INT_MAX);

//     // Use set to store pairs of {distance, node}
//     set<pair<int, int>> st;

//     // Initialize source node
//     distance[source] = 0;
//     st.insert({0, source});

//     while (!st.empty()) {
//         // Get the node with the smallest distance
//         auto top = *(st.begin());
//         int distanceNode = top.first;
//         int topNode = top.second;

//         // Remove it from the set
//         st.erase(st.begin());

//         // Traverse its neighbors
//         for (auto neighbor : adj[topNode]) {
//             int nextNode = neighbor.first;
//             int edgeWeight = neighbor.second;

//             // Relaxation step
//             if (distanceNode + edgeWeight < distance[nextNode]) {
//                 // If the new distance is smaller, update it
//                 auto record = st.find({distance[nextNode], nextNode});
//                 if (record != st.end()) {
//                     st.erase(record); // Remove old distance from the set
//                 }

//                 // Update the distance and insert the new pair
//                 distance[nextNode] = distanceNode + edgeWeight;
//                 st.insert({distance[nextNode], nextNode});
//             }
//         }
//     }

//     return distance;
// }
