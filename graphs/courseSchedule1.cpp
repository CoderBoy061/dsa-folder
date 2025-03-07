
/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.


🔹 Time Complexity: O(V + E)
🔹 Space Complexity: O(V + E)
*/

// class Solution {
//     public:
//         bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//             int n = prerequisites.size();
//             vector<int> adj[numCourses];
//             vector<int> indegree(numCourses, 0); // Indegree array
//                                                  // Preparing the adjacency list
//             for (auto pre : prerequisites) {
//                 int courseA = pre[0], courseB = pre[1];
//                 adj[courseB].push_back(courseA);
//                 indegree[courseA]++;
//             }
//             queue<int> q;
//             // Pushing nodes with 0 indegree
//             for (int i = 0; i < numCourses; i++) {
//                 if (indegree[i] == 0)
//                     q.push(i);
//             }
    
//             int count = 0;
//             while (!q.empty()) {
//                 int node = q.front();
//                 q.pop();
//                 count++;
    
//                 for (auto next : adj[node]) {
//                     indegree[next]--;
//                     if (indegree[next] == 0)
//                         q.push(next);
//                 }
//             }
    
//             // If count == numCourses, no cycle
//             return count == numCourses;
//         }
//     };