int maximumProduct(vector<int> &nums, int n)
{
	  
        int curr=1;
        int maxSum = -11;
        
        for(int i=0;i<n;i++){
            curr *= nums[i];
            maxSum = max(maxSum, curr);
            
            if(curr == 0) curr =1;
        }
        
        curr =1;
        
         for(int i=n-1;i>=0;i--){
            curr *= nums[i];
            maxSum = max(maxSum, curr);
            
            if(curr == 0) curr =1;
        }
        
        return maxSum;
}
