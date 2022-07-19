#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
   
    int l=0, r= n-1;
    long maxLeft=INT_MIN, maxRight=INT_MIN;
    long res=0;
    
    while(l<=r){
        if(arr[l] <= arr[r]){
            if(arr[l] >= maxLeft){
                maxLeft = arr[l];
            }
            else
                res += maxLeft - arr[l];
            l++;
        }
        else{
            if(arr[r] >= maxRight){
                maxRight = arr[r];
            }
            else
                res += maxRight - arr[r];
            r--;
        }
    }
    
    return res;
}