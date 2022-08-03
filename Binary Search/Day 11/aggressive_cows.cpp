bool isPossible(vector<int> arr, int n, int c, int dis){
    int cnt=1;
    int pos = arr[0];
    
    for(int i=1;i<n;i++){
        if(arr[i]-pos >= dis){
            pos = arr[i];
            cnt++;
        } 
        if(cnt ==c ) return true;
    }
    
    return false;
}


int chessTournament(vector<int> arr , int n ,  int c){
	// Write your code here
    
    sort(arr.begin(),arr.end());
    
    int low = 1;
    int high = arr[n-1]-arr[0];
    
    int res=-1;
    
    while(low <=high){
        int mid = low+(high-low)/2;
        
        if(isPossible(arr,n,c,mid)){
            res = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    
    return res;
}