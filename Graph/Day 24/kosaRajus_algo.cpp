#include <bits/stdc++.h>

void dfs(int node, stack<int> &st, vector<int> &vis, unordered_map<int, vector<int>> &adj) {
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj); 
        }
    }
    
    st.push(node); 
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[], vector<int>  &scc) {
    scc.push_back(node);
    vis[node] = 1; 
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose,scc); 
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    
       unordered_map<int, vector<int>> adj(v);  // adjancy list
        vector<int> vis(v,0);                

    
     for(int i=0; i< edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
    
   stack<int> st;
    for(int i = 0;i<v;i++) {
        if(!vis[i]) {
            dfs(i, st, vis, adj); 
        }
    } 
    
    vector<int> transpose[v]; 
    
    for(int i = 0;i<v;i++) {
        vis[i] = 0; 
        for(auto it: adj[i]) {
            transpose[it].push_back(i); 
        }
    }
    
    vector<vector<int>> ans;
    while(!st.empty()) {
        int node = st.top();
        st.pop(); 
        if(!vis[node]) {
            vector<int> scc;
            revDfs(node, vis, transpose,scc); 
            ans.push_back(scc);
        }
    }
    
    return ans;
}