#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	
    
    //as duplicate present therefore there will be a cycle
    //using that apprach to reach the ans in 0(n)
    
    int fast = arr[0];
    int slow = arr[0];
    
   do{
        fast = arr[arr[fast]];
        slow = arr[slow];
    }while(fast != slow);
    
    fast = arr[0];
    
    while(fast != slow){
        fast = arr[fast];
        slow = arr[slow];
    }
    
    return fast;
}
