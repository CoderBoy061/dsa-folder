// 1319. Number of Operations to Make Network Connected
// Solved
// Medium
// Topics
// Companies
// Hint
// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
// Overoll TC - O(Mα(N)+N)
// overall SC - O(n)
// class DisJoint {

//     public:
//         vector<int> parent, rank, size;
//         DisJoint(int node) {
//             parent.resize(node + 1);
//             rank.resize(node + 1, 0);
//             size.resize(node + 1);
//             for (int i = 0; i <= node; i++) {
//                 parent[i] = i;
//                 size[i] = 1;
//             }
//         }
//         int findUParent(int node) {
//             if (node == parent[node])
//                 return node;
//             return parent[node] =
//                        findUParent(parent[node]); // recursion with path compression
//         }
    
//         void unionByRank(int u, int v) {
//             int up_u = findUParent(u);
//             int up_v = findUParent(v);
    
//             if (up_u == up_v)
//                 return;
    
//             // jodi u er parent choto hoy v er parent er theke, tahole borotar sathe
//             // choto take join krte hobe
//             if (rank[up_u] < rank[up_v]) {
//                 parent[up_v] = up_u;
//             }
//             // jodi v er parent choto hoy u er parent er theke, tahole borotar sathe
//             // choto take join krte hobe
//             else if (rank[up_v] < rank[up_u]) {
//                 parent[up_u] = up_v;
//             }
//             // mane dutor e rank soman, so fadak pore na, jekono tar sathe join dili
//             // cholbe
//             else {
//                 parent[up_u] = up_v;
//             }
//         }
//         // void unionBySize(int u, int v) {
//         //     int up_u = findUParent(u);
//         //     int up_v = findUParent(v);
//         //     if (up_u == up_v)
//         //         return;
//         //     if (size[up_u] < size[up_v]) {
//         //         parent[up_u] = up_v;
//         //         size[up_v] += size[up_u];
//         //     } else {
//         //         parent[up_v] = up_u;
//         //         size[up_u] = size[up_v];
//         //     }
//         // }
//     };
//     class Solution {
//     public:
//         int makeConnected(int n, vector<vector<int>>& connections) {
//             int extra = 0;
//             DisJoint ds(n);
                // O(n+e)
//             for (auto it : connections) {
//                 int u = it[0];
//                 int v = it[1];
    
//                 if (ds.findUParent(u) == ds.findUParent(v)) {
//                     extra++;
//                 } else {
//                     ds.unionByRank(u,v);
//                 }
//             }
//             int cntCompo =0;
// o(n)
//             for(int i=0;i<n;i++){
//                 if(ds.parent[i] == i){
//                     cntCompo++;
//                 }
//             }
//             int ans = cntCompo -1;
//             if(extra >= ans) return ans;
//             return -1;
//         }
//     };