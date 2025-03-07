
// LeetCode -Accounts Merge Problem
// Tc - O(NlogN+Mα(N))
// SC - O(N+M)
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
//         void unionBySize(int u, int v) {
//             int up_u = findUParent(u);
//             int up_v = findUParent(v);
//             if (up_u == up_v)
//                 return;
//             if (size[up_u] < size[up_v]) {
//                 parent[up_u] = up_v;
//                 size[up_v] += size[up_u];
//             } else {
//                 parent[up_v] = up_u;
//                 size[up_u] = size[up_v];
//             }
//         }
//     };
//     class Solution {
//     public:
//         vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
//             int n = details.size();
//             DisJoint ds(n);
//             unordered_map<string, int> mapMailNode;
    
//             // Step 1: Map emails to a representative node
//             for (int i = 0; i < n; i++) {
//                 for (int j = 1; j < details[i].size(); j++) {
//                     string mail = details[i][j];
//                     if (mapMailNode.find(mail) == mapMailNode.end()) {
//                         mapMailNode[mail] = i;
//                     } else {
//                         ds.unionByRank(i, mapMailNode[mail]); // Merge accounts
//                     }
//                 }
//             }
    
//             // Step 2: Group emails by their representative node
//             vector<vector<string>> mergedMail(n);
//             for (auto& it : mapMailNode) {
//                 string mail = it.first;
//                 int node = ds.findUParent(it.second); // Find representative parent
//                 mergedMail[node].push_back(mail);
//             }
    
//             // Step 3: Prepare the final merged account list
//             vector<vector<string>> ans;
//             for (int i = 0; i < n; i++) {
//                 if (mergedMail[i].empty())
//                     continue; // Skip empty groups
    
//                 sort(mergedMail[i].begin(), mergedMail[i].end()); // Sort emails
//                 vector<string> temp;
//                 temp.push_back(details[i][0]); // Add the person's name
//                 temp.insert(temp.end(), mergedMail[i].begin(), mergedMail[i].end());
//                 ans.push_back(temp);
//             }
    
//             return ans;
//         }
//     };