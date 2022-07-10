#include<bits/stdc++.h>


void dfs(int node, vector<int> &vis, unordered_map<int, vector<int>> adj, vector<int> &component){
    
    component.push_back(node);
    vis[node]=1;
    
    for(auto it: adj[node]){
       if(!vis[it]){
           dfs(it, vis, adj, component);
       }
    }
}

vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges)
{
     vector<vector<int>> ans;  // answer array
    unordered_map<int, vector<int>> adj;  // adjancy list
    vector<int> vis(v+1,0);  // visited array
    
    for(int i=0;i<e;i++){
        //filling up the adjancy list
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0;i<v;i++)
        sort(adj[i].begin(),adj[i].end());
    
    for(int i=0;i<v;i++){
        if(!vis[i]){
            vector<int> component;
            dfs(i, vis, adj, component);
            ans.push_back(component);
        }
    }
    
    return ans;
}