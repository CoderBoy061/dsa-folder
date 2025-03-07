// space complexity of this aproach is O(E), because we are only storing pone edge, which from U to V
// Directed Graph
// Traversal for Directed Graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj)
{
    // calculation the size of node/vertexes
    int v = adj.size();
    // storing the answer of the bfs technique
    vector<int> bfs;
    // visited list to mark if the node is already visited or not
    vector<bool> visited(v, false);
    queue<int> q;
    // pusing the first element into the queue and marking the first element as true, because this is a 1 indexing graph not 0
    q.push(1);
    visited[1] = true;
    // traverse the entire queue, untill it gets empty
    while(!q.empty()) {
        int node = q.front(); // taking the front node
        q.pop(); // poping the first node/element from the queue and putting it into the bfs array 
        bfs.push_back(node);
        // traversing the neighbours element of the node
        for(auto it: adj[node]){
            if(!visited[it]){
                visited[it]= 1;
                q.push(it);
            }
        }

    }
    return bfs;
};

int main()
{
    int n, m;
    cin >> n >> m;
    // for 1 based indexing
    // for 0 based indexing, adjust the matrix based on 0
    // it is a 1 based indexing graph
    vector<vector<int>> adj(n + 1); // Adjacency list for 1-based indexing
    vector<int> answer;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // this is a dircted graph and the edge can only go from u to v not v to u
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    answer = bfs(adj);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}