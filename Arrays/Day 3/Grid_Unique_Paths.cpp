#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	int k= m+n-2;
    int r = min(m-1, n-1);
    
    double ans = 1.0;
    for(int i=1;i<=r;i++){
        ans = ans * ( k + i -r)/i;
    }
    
    return (int)ans;
}