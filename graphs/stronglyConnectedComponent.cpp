//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// OTC = O(2 * V+E)
// SC - O(2*V)
class Solution {
  private:
    void dfs(int node, vector<int>&vis, stack<int>&st,vector<vector<int>> &adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,st,adj);
            }
        }
        
        st.push(node);
    }
    void dfs2(int node, vector<int>&vis,vector<vector<int>> &adj2){
        vis[node]=1;
        for(auto it: adj2[node]){
            if(!vis[it]){
                dfs2(it, vis,adj2);
            }
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        // O(2*V)
        vector<int>vis(V,0);
        stack<int>st;
        // step-1 perfrom the dfs to sort all the edges based on the finishing time and store it into the stack
        // TC - O(V+E)
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        
        // step-2, revser the graph
        
        vector<vector<int>> adj2(V);
        // TC - O(V+E)
        for(int i=0;i<V;i++){
            vis[i] = 0; // reinitializing the visited array to 0, so it can be reuseable
            for(auto it: adj[i]){
                adj2[it].push_back(i); // reversing the edges
            }
        }
        int scc =0;
        // O(V+E)
        while(!st.empty()){
            int top = st.top();
            st.pop();
            
            if(!vis[top]){
                scc++;
                dfs2(top, vis, adj2);
            }
        }
        return scc;
         
    }
};
