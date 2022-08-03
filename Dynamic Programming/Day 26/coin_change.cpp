#include<bits/stdc++.h>

long countWaysToMakeChange(int *nums, int n, int x)
{
        vector<long> prev(x+1,0), curr(x+1,0);
        
        for(int i=0;i<=x;i++){
            if( i%nums[0]==0) 
                prev[i] = 1;
        }

        
        for(int i=1;i<n;i++){
            for(int j=0;j<=x;j++){
                long take = 0;
                
                if(j>= nums[i]){
                    take = curr[j- nums[i]];
                }
                long notTake = prev[j];

                curr[j]= take + notTake;
            }
            prev = curr;
        }
        
        return prev[x];
}