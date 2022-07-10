#include<bits/stdc++.h>

 bool dfs(int node,int prev, vector<int> &vis, unordered_map<int, vector<int>> adj){
        vis[node]=1;  // mark visited
     
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, node, vis, adj))
                    return true;
                vis[it] =1;
            }
            else if( it != prev) return true;
        }
     return false;
      
    }

string cycleDetection (vector<vector<int>>& arr, int v, int m)
{
   
        // cycle detection in graph
        
        unordered_map<int, vector<int>> adj;  // adjancy list
        vector<int> vis(v+1,0);                 // visited array
        
        
        //making an adjancy list
        for(int i=0; i< arr.size();i++){
            
            int u = arr[i][0];
            int v = arr[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=1;i<=v;i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj)) return "Yes";
            }
        }
        
        return "No";
}
