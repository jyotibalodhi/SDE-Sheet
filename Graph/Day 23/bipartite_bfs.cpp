#include<bits/stdc++.h>

bool isGraphBirpatite(vector<vector<int>> &edges) {
 
     int v= edges[0].size();
    
     vector<int>adj[v];
    
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(edges[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
        vector<int> color(v,-1);
        queue<int> q;
        vector<int> vis(v,0);
        
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
                
                q.push(i);
                int col = 1;
                vis[i]=1;
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    col = color[node];
                    
                    for(auto it: adj[node]){
                        if(color[it]==-1){
                            color[it] = 1 - col;
                            q.push(it);
                        }
                        else if(color[it] == col) return false;
                    }
                }
            }
        }
        
        return true;
}