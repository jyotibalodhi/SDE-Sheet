#include<bits/stdc++.h>
#define pi  pair<int,int>
vector<int> dijkstra(vector<vector<int>> &vec, int v, int e, int src) {
    
    unordered_map<int, vector<pair<int,int>>> adj;
    vector<int> dis(v,INT_MAX);   // answer array
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    
    //creating adjancy list
    for(int i=0;i<e;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];
        
        adj[u].push_back({wt,v});
        adj[v].push_back({wt,u});
    }
    
    dis[src] =0;
    pq.push({0,src});
    
   while( !pq.empty() ){
       
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        for( auto it :adj[prev]){
            int next = it.second;
            int nextDist = it.first;
            if( dis[next] > dis[prev] + nextDist){
                dis[next] = dis[prev] + nextDist;
                pq.push(make_pair(dis[next], next));
            }
        }
   }
    return dis;
    
}
