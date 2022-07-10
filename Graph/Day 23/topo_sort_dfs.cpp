 #include<bits/stdc++.h>

 void dfs(int node, vector<int> &vis, stack<int> &stk, unordered_map<int, vector<int>> &adj){
     
        vis[node]=1;  // mark visited
     
        for(auto it: adj[node]){
            if(!vis[it])
                dfs(it, vis, stk, adj);
        }
     
        stk.push(node);
    }
    

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
        unordered_map<int, vector<int>> adj(v);  // adjancy list
        vector<int> vis(v,0);                 // visited array
        stack<int> stk;
    
     for(int i=0; i< edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i, vis, stk, adj) ;
            }
        }
    
    vector<int> ans;
    
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
        
        return ans;
}