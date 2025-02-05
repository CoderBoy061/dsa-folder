
// The Time complexsity DFS of an Un-directed graph is - O(N) + (2*E)
// The Space complexity DFS of an Un-Directed graph is -
// O(N) - for answer
// O(N) - for Visited
// O(N) - for stack space

// Everything will be the same for directed graph, but the time complexity will be changed
// like O(N) + (E)

// Un-Directed Graph
// Traversal for Un-Directed Graph
#include <iostream>
#include <vector>
using namespace std;

class Solution{

    public:
        void dfsCall( int node , vector<vector<int>> &adj , int visited[] , vector<int> &ans){
            // marking the current node as visited
            visited[node]=1;
            // pusing the current node inside the answer array
            ans.push_back(node);
            // visiting the neighbour if its neighbour
            for(auto it: adj[node]){
                // if the current neighbour node is node visited then the recurion call will be perform for that node 
                if(!visited[it]){
                    dfsCall(it,adj, visited,ans);
                }

            }

        }
        // the adjancency list will be given in the question itself
        vector<int>dfs(vector<vector<int>> adj){
            // taking the size of the Node/Vertexes if it is not given
            int v = adj.size();

            //making the visited array to keep tracking of the visited node
            int visited[v] ={0};
            // the start index will be different based on the question
            int startIndex= 0;
            vector<int>ans;
            dfsCall(startIndex, adj, visited,ans);
        }
};
// int main(){


//     return 0;
// }