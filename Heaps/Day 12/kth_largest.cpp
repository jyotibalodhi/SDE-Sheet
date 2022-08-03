#include<bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
      sort(arr.begin(), arr.end());
    vector<int> new_arr;
    new_arr.push_back(arr[k-1]);
    new_arr.push_back(arr[n-k]);
       
        return new_arr;
        
}