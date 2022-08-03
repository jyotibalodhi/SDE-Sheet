#include<bits/stdc++.h>

bool isPalindrome(string str, int s, int e){
        while(s<e){
            if(str[s] != str[e])
                return false;
            s++;
            e--;
        }
        
        return true;
    }

int palindromePartitioning(string s) {
      int n = s.length();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int minCost =INT_MAX;
            
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost, cost);
                }
            }
            
            dp[i] = minCost;
        }
        
        return dp[0]-1;
}
