#include<bits/stdc++.h>

 bool cycle(int v, vector<int> &vis, unordered_map<int, vector<int>> adj){
        
        queue<pair<int, int>> q;   // pair of curr, prev node
        q.push({v, -1}); 
        vis[v]=1;
        
        while(!q.empty()){
            int node = q.front().first;
            int prev = q.front().second;
            
            q.pop();

            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push({it, node});
                    vis[it]=1;
                }
                else if(it != prev) return true;
            }
        }
        
        return false;
    }

string cycleDetection (vector<vector<int>>& arr, int v, int m)
{
   
        // cycle detection in graph
        
    if(v == 1 || m==0) return "No";
    
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
                if(cycle(i, vis, adj)) return "Yes";
            }
        }
        
        return "No";
}
