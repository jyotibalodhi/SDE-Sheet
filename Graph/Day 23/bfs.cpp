#include<bits/stdc++.h>

vector<int> BFS(int v, vector<pair<int, int>> edges)
{
    vector<int> ans;  // answer array
    unordered_map<int, vector<int>> adj;  // adjancy list
    vector<int> vis(v+1,0);  // visited array
    
    for(int i=0;i<edges.size();i++){
        //filling up the adjancy list
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0;i<v;i++)
        sort(adj[i].begin(),adj[i].end());
    
    for(int i=0;i<v ;i++){
        
        if(!vis[i]){  
            //BFS Traversal
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                ans.push_back(node);
                
                for(auto j : adj[node]){
                    if(!vis[j]){
                        q.push(j);
                        vis[j] =1;
                    }
                }
            }
        }
    }
    return ans;
}