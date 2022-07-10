 #include<bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    //Kahn's algorithm
    
        unordered_map<int, vector<int>> adj(v);  // adjancy list
        vector<int> ind(v,0);                 // visited array
        queue<int> q;
    
    //adjancy list
     for(int i=0; i< edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
    //indegree array
        for(int i=0;i<v;i++){
           for(auto it: adj[i]){
               ind[it]++;
           }
        }
    
    for(int i=0;i<v;i++){
        if(ind[i]==0) q.push(i);
    }
    
    vector<int> ans;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        ans.push_back(node);   // topological sorting
        
        for(auto it: adj[node]){
            ind[it]--;
            if(ind[it]==0)
                q.push(it);
        }
    }
        return ans;
}