

/*

Shortest path in Directed Acyclic Graph
Difficulty: MediumAccuracy: 48.48%Submissions: 154K+Points: 4Average Time: 20m
Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

TC - O(V+E)
SC - O(V+E)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
     void topo(int src, vector<pair<int, int>> adj[], int visited[], stack<int>& s) {
        visited[src] = 1;
        for (auto it : adj[src]) {
            if (!visited[it.first]) {  // Use it.first (neighbor node)
                topo(it.first, adj, visited, s);
            }
        }
        s.push(src);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V]; // Corrected adjacency list
        
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }

        int visited[V] = {0};
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topo(i, adj, visited, st);
            }
        }

        // Corrected distance initialization
        vector<int> dist(V, INT_MAX);
        dist[0] = 0; // Starting node is 0

        while (!st.empty()) {
            int top = st.top();
            st.pop();

            if (dist[top] != INT_MAX) { // Ensure only processed nodes update distance
                for (auto it : adj[top]) {
                    int v = it.first;  // Neighbor node
                    int wt = it.second; // Weight
                    
                    if (dist[top] + wt < dist[v]) {
                        dist[v] = dist[top] + wt;
                    }
                }
            }
        }

        // Replace INT_MAX with -1 (to indicate unreachable nodes)
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};


