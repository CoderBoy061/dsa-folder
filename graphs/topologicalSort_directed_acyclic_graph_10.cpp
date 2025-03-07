// in topological sort the u should always comes before v

// suppos there is an edge between 1 ={2,3}

// Topological sorting is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge ( u \rightarrow v ), vertex ( u ) comes before ( v ) in the ordering. This is useful in scenarios like task scheduling, where certain tasks must be completed before others.

// Graph Representation
// Adjacency List: This is a common way to represent a graph. Each vertex has a list of all the vertices it points to. For example, if there is an edge from vertex 1 to vertices 2 and 3, the adjacency list would look like:

// Stack: A stack is used to store the vertices in the topological order. We perform a Depth-First Search (DFS) on the graph, and as we finish exploring a vertex, we push it onto the stack. The stack will then contain the vertices in reverse topological order.

// Algorithm Steps
// Initialize:

// An adjacency list to represent the graph.
// A boolean array to keep track of visited vertices.
// A stack to store the topological sort.
// DFS Traversal:

// For each vertex, if it is not visited, perform a DFS.
// In the DFS function, mark the current vertex as visited.
// Recursively visit all the adjacent vertices.
// After visiting all adjacent vertices, push the current vertex onto the stack.
// Extract Topological Order:

// Pop all vertices from the stack to get the topological order.
// Example Code
// Here is an example implementation in C++:

// Explanation
// Graph Representation:

// The graph is represented using an adjacency list adj.
// adj[0] contains [1, 2] indicating edges from vertex 0 to vertices 1 and 2.
// DFS Traversal:

// The topologicalSortUtil function performs DFS and pushes vertices onto the stack after exploring all adjacent vertices.
// Topological Order:

// The topologicalSort function initializes the stack and visited array, and calls the DFS helper for each vertex.
// Finally, it prints the vertices in topological order by popping from the stack.
// This approach ensures that each vertex appears before all vertices it points to, satisfying the requirements of a topological sort.
// // class Solution {
//   public:
//     void topoSortDFS(int i,vector<int>& visited, vector<vector<int>> &adj, stack<int>& s ) {
//         visited[i]= true;
//         for(auto it : adj[i]){
//             if(!visited[it]) {
//                 topoSortDFS(it,visited,adj,s);
//             }
//         };
//         s.push(i);
//     }
//     // Function to return list containing vertices in Topological order.
//     vector<int> topologicalSort(vector<vector<int>>& adj) {
//         // Your code here
//         int n = adj.size();
//         // vector<vector<int>> adjList(n);
//         vector<int>visited(n,false);
//         vector<int>ans;
//         stack<int>s;
        
//         // //preparing the adj list
        
//         // for(int i=0;i<n;i++){
//         //     int u = adj[i][0];
//         //     int v = adj[i][1];
//         //     // becausr this is a directed graph, so that edge would be between 1 way, only u to v
//         //     adjList[u].push_back(v);
//         // }
        
//         for(int i=0;i<n;i++){
//             if(!visited[i]) {
//                 // call the dfs function
//                  topoSortDFS(i, visited, adj,s);
//             }
//         }
        
//         while(!s.empty()){
//             ans.push_back(s.top());
//             s.pop();
//         }
//         return ans;
        
//     }
// };


// using bfs Kahn's algorithm

    // vector<int> topologicalSort(vector<vector<int>>& adj) {
    //     int n = adj.size();
    //     vector<int> indegree(n, 0);  // Initialize indegree for all vertices to 0
    //     vector<int> ans;
        
    //            // Calculate indegree of all nodes
    //     for (int i = 0; i < n; i++) {
    //         for (int v : adj[i]) {
    //             indegree[v]++;  // Increase indegree of the destination node
    //         }
    //     }
        
    //     queue<int>q;
        
    //     for(int i=0;i<n;i++){
    //         if(indegree[i]==0){
    //             q.push(i);
    //         }
    //     }
        
    //     while(!q.empty()){
    //         int front = q.front();
    //         q.pop();
            
    //         ans.push_back(front);
            
    //         for(auto it: adj[front]){
    //             indegree[it]--;
    //             if(indegree[it]==0){
    //                 q.push(it);
    //             }
    //         }
    //     }
        
    
    //     return ans;
        
    // }