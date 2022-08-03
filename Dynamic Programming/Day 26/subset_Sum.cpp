bool subsetSumToK(int n, int k, vector<int> &arr) {
    // 0/1 Knapsack variation
    
    bool dp[n+1][k+1];
    
    //initialization
   for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    
    for (int i = 1; i <= k; i++)
        dp[0][i] = false;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(arr[i-1] <= j){
                int rem = j - arr[i-1];
                dp[i][j] = (dp[i-1][rem] || dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    
    return dp[n][k];
    
}