#include<bits/stdc++.h>

struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u; 
    }
    else {
        parent[v] = u;
        rank[u]++; 
    }
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	
    vector<node> vec;
    
    for(int i=0;i<m;i++){
        int u = graph[i][0];
        int v = graph[i][1];
        int wt = graph[i][2];
        
        vec.push_back(node(u,v,wt));
    }
    
    sort(vec.begin(),vec.end(),comp);
    
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    
    for(int i=0;i<n;i++) parent[i] = i;
    
    int cost=0;

    for(auto it: vec){
        if(findPar(it.v,parent) != findPar(it.u,parent)){
            cost += it.wt;
            unionn(it.u,it.v,parent,rank);
        }
    }
    
    return cost;
}



