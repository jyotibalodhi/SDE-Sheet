#include<bits/stdc++.h>

int longestSubSeg(vector<int> &arr , int n, int k){  
    
    int start=0, maxLen=0;
    int zero =0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            zero++;
        }
         if(zero>k){
             while(zero>k){
                 if(arr[start]==0){
                     zero--;
                 }
                 start++;
             }
         }
        maxLen=max(maxLen,i-start+1);
    }
    
    return maxLen;
}
