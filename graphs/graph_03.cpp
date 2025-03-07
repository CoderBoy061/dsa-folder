// space complexity of this aproach is O(E), because we are only storing pone edge, which from U to V
//Directed Graph
#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // for 1 based indexing
    // for 0 based indexing, adjust the matrix based on 0
    // it is a 1 based indexing graph
    vector<int>adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // this is a dircted graph and the edge can only go from u to v not v to u
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    return 0;
}