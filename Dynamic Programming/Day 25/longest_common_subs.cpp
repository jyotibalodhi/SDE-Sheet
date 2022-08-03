#include<bits/stdc++.h>

int solve(string s, string t, int i, int j, vector<vector<int>> &dp){
    if(i<0 || j<0)  // any of the string gets over
        return 0;
    
    if(dp[i][j] != -1)  return dp[i][j];
    if(s[i]== t[j])  // if char matches
        return dp[i][j]= 1 +  solve(s,t,i-1,j-1,dp);
    
    //if does not match
    return dp[i][j] = max( solve(s,t,i,j-1,dp),  solve(s,t,i-1,j,dp));
        
}


int lcs(string s, string t)
{
	int  i = s.length();
    int j = t.length();
    
    vector<vector<int>> dp(i+1, vector<int>(j+1,0));
    return solve(s,t,i-1,j-1,dp);
}