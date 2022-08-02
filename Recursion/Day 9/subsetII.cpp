#include<bits/stdc++.h>

void solve(int ind, int n, vector<int> &arr, vector<vector<int>> &ans,vector<int> ds){
    
    ans.push_back(ds);
    
    
    for(int i=ind;i<n;i++){
        if(i != ind && arr[i]==arr[i-1]) continue;
        //take
        ds.push_back(arr[i]);
        solve(i+1,n,arr,ans,ds);

        //not take
        ds.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    solve(0,n,arr,ans,{});
    
    return ans;
}