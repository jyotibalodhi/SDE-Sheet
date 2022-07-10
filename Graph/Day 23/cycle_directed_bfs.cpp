 #include<bits/stdc++.h>
 
int detectCycleInDirectedGraph(int v, vector < pair < int, int >> & edges) {
 
        unordered_map<int, vector<int>> adj(v);  // adjancy list
        queue<int> q;
        vector<int> ind(v+1,0);                 // indegree array

    
     for(int i=0; i< edges.size();i++){
            adj[edges[i].first].push_back(edges[i].second);
        }
        
        
       //indegree array
        for(int i=1;i<=v;i++){
           for(auto it: adj[i]){
               ind[it]++;
           }
        }
    
    for(int i=1;i<=v;i++){
        if(ind[i]==0) q.push(i);
    }

    int cnt =0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        cnt++;  
        
        for(auto it: adj[node]){
            ind[it]--;
            if(ind[it]==0)
                q.push(it);
        }
    }
        return (cnt != v);
}