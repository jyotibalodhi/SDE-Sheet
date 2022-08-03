

int cutRod(vector<int> &nums, int x)
{
    int n = nums.size();
    vector<int> prev(x+1,0), curr(x+1,0);
    
    for(int i=0;i<=x;i++){
        // rodlength will be 0+1 =1
        // No of units of rodlength 1 to make length x 
        prev[i] = i * nums[0];
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=x;j++){
            
            int notTake = prev[j];
            int take = INT_MIN;
            int length = i+1;
            if(length <= j)
                take = nums[i] + curr[j-length];

            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
	return prev[x];
}
