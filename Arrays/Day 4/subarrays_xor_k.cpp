#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
   int prex =0;  // prefix XOR
    int count =0;
    
    unordered_map<int,int> umap;
    
    for(int i=0;i<arr.size();i++){
        prex ^= arr[i];
        
        if(prex == x) count++;
        if(umap.find(prex ^ x) != umap.end()){
            count += umap[prex ^ x];
        }
        
        umap[prex]++;
    }
    
    return count;
}