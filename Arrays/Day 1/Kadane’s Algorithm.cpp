#include <limits.h>

long long maxSubarraySum(int arr[], int n)
{
    
    long long max_sum_end= 0;
        long long max_sum = INT_MIN;
        
 
        for(int i=0; i<n; i++){
            max_sum_end = max_sum_end+arr[i];
            if(max_sum_end >max_sum){
                max_sum =max_sum_end;
            }
            if(max_sum_end<0){
                max_sum_end =0;
            }
        }
  // The next line is not required but this question have this limitation 
  //that even if there is no element >= 0 then also the max sum 
  //should be 0
  
        if(max_sum<0)  return 0;    
    return max_sum;
}