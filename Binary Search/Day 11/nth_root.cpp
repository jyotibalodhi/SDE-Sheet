double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

double getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-8; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }   
    return low;
}

double findNthRootOfM(int n, long long m) {
	
    double ans = getNthRoot(n,m);
    return ans;
}
