
// Time Complexity:
// Time Complexity: O(k * E), where E is the number of edges (flights). Each state is processed at most k+1 times for each node.

// Space Complexity: O(n * k), where n is the number of nodes (airports), and k is the number of stops allowed.

// class Solution {
//     public:
//         int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
//                               int k) {
//             // Create the adjacency list to depict airports and flights in the form
//             // of a graph
//             vector<pair<int, int>> adj[n];
//             for (auto it : flights) {
//                 adj[it[0]].push_back({it[1], it[2]});
//             }
    
//             // Create a queue which stores the node and their distances from the
//             // source in the form of {stops, {node, dist}} with ‘stops’ indicating
//             // the no. of nodes between src and current node.
//             queue<pair<int, pair<int, int>>> q;
//             q.push({0, {src, 0}}); // {stops, {src, 0}}
    
//             // Distance array to store the updated distances from the source
//             vector<int> dist(n, 1e9);
//             dist[src] = 0;
    
//             // Iterate through the graph using a queue, like in BFS or Dijkstra's
//             // with a stop constraint
//             while (!q.empty()) {
//                 auto it = q.front();
//                 q.pop();
//                 int stops = it.first;
//                 int node = it.second.first;
//                 int cost = it.second.second;
    
//                 // If we exceed the stop limit, do nothing further for this path
//                 if (stops > k)
//                     continue;
    
//                 // Explore all neighbors of the current node
//                 for (auto iter : adj[node]) {
//                     int adjNode = iter.first;
//                     int edW = iter.second;
    
//                     // If we find a cheaper cost or the path is valid, update the
//                     // queue and dist
//                     if (cost + edW < dist[adjNode] && stops <= k) {
//                         dist[adjNode] = cost + edW;
//                         q.push({stops + 1, {adjNode, cost + edW}});
//                     }
//                 }
//             }
    
//             // If the destination node is unreachable, return -1
//             // else return the calculated distance from src to dst
//             if (dist[dst] == 1e9)
//                 return -1;
//             return dist[dst];
//         }
//     };