#include<bits/stdc++.h>

  bool dfs(vector<int> adj[], int node, vector<int> &color){
        
        if(color[node]==-1) color[node]=1;

        for(auto it: adj[node]){
                if(color[it]==-1){
                    color[it] = 1- color[node];
                    if(!dfs(adj,it,color)) return false;
                }
                else if(color[it]== color[node]) return false;
        }
        
        return true;
    }

bool isGraphBirpatite(vector<vector<int>> &edges) {
 
     int v= edges[0].size();
    
     vector<int> adj[v];
    
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(edges[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
        vector<int> color(v,-1);
    
        for(int i=0;i<v;i++){
          if(color[i]==-1){
              if(!dfs(adj, i, color)) return false;
          }
        }
        
        return true;
}