#include<bits/stdc++.h>

 bool dfs(int node, vector<int> &vis, vector<int> &dfsVis, unordered_map<int, vector<int>> &adj){
     
        vis[node]=1;  // mark visited
        dfsVis[node] =1;
     
        for(auto it: adj[node]){
            if(dfsVis[it]) return true;
            else if(!vis[it] && dfs(it, vis, dfsVis, adj))
                    return true;
        }
     
     dfsVis[node]=0;
     return false;
      
    }
    


int detectCycleInDirectedGraph(int v, vector < pair < int, int >> & edges) {
 
     unordered_map<int, vector<int>> adj(v);  // adjancy list
        vector<int> vis(v+1,0);                 // visited array
        vector<int> dfsVis(v+1,0);
    
     for(int i=0; i< edges.size();i++){
            adj[edges[i].first].push_back(edges[i].second);
        }
        
        
        for(int i=1;i<=v;i++){
            if(!vis[i]){
                if(dfs(i, vis, dfsVis, adj)) return 1;
            }
        }
        
        return 0;
}