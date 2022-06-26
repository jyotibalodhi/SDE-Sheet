#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	
    int cnd=-1;
    int c=0;
    
    for(int i=0;i<n;i++){
        if(c==0){
            cnd = arr[i];
        }
         if(arr[i]==cnd) c++;
        else c--;
    }
    int count=0;
    
      for(int i=0;i<n;i++){
        if(arr[i]== cnd) count++;
    }
    return (count > n/2) ? cnd :-1;
}