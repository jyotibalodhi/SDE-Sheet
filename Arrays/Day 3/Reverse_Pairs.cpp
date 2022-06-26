#include <bits/stdc++.h> 

 int merge(vector<int>& nums, int low,int mid, int high){
        int cnt=0;
        int j=mid+1;
        
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i] > 2LL * nums[j]){
                j++;
            }
            
            cnt += (j-(mid+1));
        }
        
        int l=low,r=mid+1;
        vector<int> temp;
        
       while(l<=mid && r<=high){
           if(nums[l]<=nums[r]) temp.push_back(nums[l++]);
           else temp.push_back(nums[r++]);
       }
        
        while(l<=mid){
            temp.push_back(nums[l++]);
        }
        
        while(r<=high){
            temp.push_back(nums[r++]);
        }
        
        for (int i = low; i <= high; i++) {
             nums[i] = temp[i - low];
        }
        return cnt;

    }
    
    int mergeSort(vector<int>& nums, int low, int high){
        if(low >=high)  return 0;
        
        int mid = (low +(high -low) /2);
        
        int count = mergeSort(nums, low, mid);
        count += mergeSort(nums, mid+1,high);
        count += merge(nums,low, mid, high);
        
        return count;
    }

    int reversePairs(vector<int> &arr, int n){
        return mergeSort(arr, 0,n-1);
    }