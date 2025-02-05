// space complexity of this aproach is O(n*2)
//Undirected Graph

#include <iostream>
using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;
    // for 1 based indexing
    // for 0 based indexing, adjust the matrix based on 0
    // it is a 1 based indexing graph
    int adj[n + 1][m + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}