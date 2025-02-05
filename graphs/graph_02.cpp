// space complexity of this aproach is O(2E)
//Undirected Graph
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}