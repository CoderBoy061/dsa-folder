// TC- O(m * n log(m * n))
// SC-  O(n*m)

// class Solution {
//     public:
//         int minimumEffortPath(vector<vector<int>>& heights) {
//             int row = heights.size();    // Total number of rows
//             int col = heights[0].size(); // Total number of columns
    
//             // Min heap (Priority Queue) for Dijkstra
//             priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
//                            greater<>>
//                 pq;
    
//             // Distance array initialized with INF
//             vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
    
//             // Directions for moving up, down, left, right
//             int dx[4] = {-1, 1, 0, 0};
//             int dy[4] = {0, 0, -1, 1};
    
//             // Start from (0,0) with 0 effort
//             pq.push({0, 0, 0}); // {effort, row, col}
//             dist[0][0] = 0;
    
//             while (!pq.empty()) {
//                 auto [effort, r, c] = pq.top();
//                 pq.pop();
    
//                 // If reached the last cell, return the answer
//                 if (r == row - 1 && c == col - 1)
//                     return effort;
    
//                 // Explore 4 directions
//                 for (int i = 0; i < 4; i++) {
//                     int newR = r + dx[i];
//                     int newC = c + dy[i];
    
//                     if (newR >= 0 && newR < row && newC >= 0 && newC < col) {
//                         // Calculate new effort
//                         int newEffort =
//                             max(effort, abs(heights[newR][newC] - heights[r][c]));
    
//                         // If new effort is smaller, update distance and push to
//                         // heap
//                         if (newEffort < dist[newR][newC]) {
//                             dist[newR][newC] = newEffort;
//                             pq.push({newEffort, newR, newC});
//                         }
//                     }
//                 }
//             }
//             return 0; // Should never reach here
//         }
//     };