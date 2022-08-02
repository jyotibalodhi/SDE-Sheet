#include<bits/stdc++.h>

void solve(vector<int> &arr, int ind, int n, int k, vector<vector<int>> &ans, vector<int> ds){
    
    if(k==0){
        ans.push_back(ds);
    }
    
    if(ind >= n) return;
    
    for(int i=ind;i<n;i++){ 
        if(i != ind && arr[i]==arr[i-1]) continue;
        
        //take
         ds.push_back(arr[i]);
         solve(arr,i+1,n,k-arr[i],ans,ds);
        
        //not take
        ds.pop_back();
       
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
     sort(arr.begin(),arr.end());
    
    vector<vector<int>> ans;
    solve(arr,0,n,target,ans,{});
    
    return ans;
}
