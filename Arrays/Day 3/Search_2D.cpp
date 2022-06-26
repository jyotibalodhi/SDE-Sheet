#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
  
    // All rows and columns of the matrix are sorted
    // therefore can make use of binary Search O(log(m*n))
    
    if(target < mat[0][0] || target > mat[m-1][n-1]) return false;
    
    int l=0;
    int h = m*n-1;  // last element index in 1D
    
    while(l<=h){
        int mid = l+(h-l) /2;
        
        int val = mat[mid/n][mid%n];
        
        if(val == target) return true;
        if(val < target) l=mid+1;
        else h=mid-1;
    }
    
    return false;
}