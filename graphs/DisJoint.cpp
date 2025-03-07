#include <iostream>
#include <vector>
using namespace std;

// Both Method works in O(4 alpha)
class DisJoint
{
    vector<int> parent, rank, size;

public:
    DisJoint(int node)
    {
        parent.resize(node + 1);
        rank.resize(node + 1, 0);
        size.resize(node + 1);
        for (int i = 0; i <= node; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]); // recursion with path compression
    }

    void unionByRank(int u, int v)
    {
        int up_u = findUParent(u);
        int up_v = findUParent(v);

        if (up_u == up_v)
            return;

        // jodi u er parent choto hoy v er parent er theke, tahole borotar sathe choto take join krte hobe
        if (rank[up_u] < rank[up_v])
        {
            parent[up_v] = up_u;
        }
        // jodi v er parent choto hoy u er parent er theke, tahole borotar sathe choto take join krte hobe
        else if (rank[up_v] < rank[up_u])
        {
            parent[up_u] = up_v;
        }
        // mane dutor e rank soman, so fadak pore na, jekono tar sathe join dili cholbe
        else
        {
            parent[up_u] = up_v;
        }
    }
    void unionBySize(int u, int v)
    {
        int up_u = findUParent(u);
        int up_v = findUParent(v);
        if (up_u == up_v)
            return;
        if (size[up_u] < size[up_v])
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else
        {
            parent[up_v] = up_u;
            size[up_u] = size[up_v];
        }
    }
};
int main()
{

    return 0;
}