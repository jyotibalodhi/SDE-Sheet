int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// 0/1 Knapsack Problem
    
   vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    
    // Conditions
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(weights[i-1] <= j){
                int rem = j - weights[i-1];
                dp[i][j] = max(values[i-1] + dp[i-1][rem], dp[i-1][j]);
            }
            else
                dp[i][j]= dp[i-1][j];
        }
    }
    
    return dp[n][w];
}