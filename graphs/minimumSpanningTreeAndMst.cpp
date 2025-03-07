// #include <iostream>
// #include <queue>
// #include <vector>
// #include <tuple>
// using namespace std;

// TC = O(MlogN)
// Sc = O(m+n)

// vector<pair<int, int>> primsMST(int n, vector<vector<pair<int, int>>> &adj){
//     priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>>pq; // declaring the priority queue
//     vector<int> visited(n,0); // for track node is already visited or not?
//     vector<pair<int,int>> mstEdges;

//     pq.push({0,0,-1});  // pushing the src node into the pq, {weight,node,parent}
//     int sum =0; // to track the sum of minimum spanning tree

//     while(!pq.empty()){
//         auto [wt,node,parent] = pq.top(); // taking out the parent, node, and its weight
//         pq.pop();
//         if(visited[node]== true) continue; // if the current nide is already visted, do nothing just continute
//         visited[node] = true; // if not visted then markling it as true

//         sum+=wt;
//         if(parent != -1) mstEdges.push_back({parent, node});

//         for(auto[adjNode, adjWt] : adj[node]){
//             if(!visited[adjNode]){
//                 pq.push({adjWt, adjNode, node});
//             }
//         }
//     }
//     return mstEdges;
// }
// int main()
// {
//     int n = 5;
//     vector<vector<pair<int, int>>> adj(n);
//     adj[0] = {{1, 2}, {3, 6}};
//     adj[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
//     adj[2] = {{1, 3}, {4, 7}};
//     adj[3] = {{0, 6}, {1, 8}};
//     adj[4] = {{1, 5}, {2, 7}};

//     vector<pair<int, int>> mst = primsMST(n, adj);
//     cout << "MST Edges: ";
//     for (auto [p, c] : mst)
//         cout << "(" << p << " -> " << c << ") ";

//     return 0;
// }