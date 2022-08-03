#include<bits/stdc++.h> 

int cutLogs(int k, int n)
{
  vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == 1) 
                    dp[i][j] = j;
                else if (j == 1) 
                    dp[i][j] = 1;
                else
                {
                    int ans = INT_MAX, temp = 0, l = 0, h = j;
                    while (l <= h)
                    {
                        int m = l + (h - l) / 2;
                        int take = dp[i - 1][m - 1];
                        int notTake = dp[i][j - m];
                        temp = 1 + max(take, notTake);
                        if (take < notTake)
                            l = m + 1;
                        else
                            h = m - 1;
                        ans = min(ans, temp);
                    }
                    dp[i][j] = ans;
                }
            }
        }
        return dp[k][n];
}
