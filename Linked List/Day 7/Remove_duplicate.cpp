int removeDuplicates(vector<int> &arr, int n) {
	
    if(n==1) return 1;
    
    int l=0, h=1;
    
    while(h<n){
        if(arr[l] == arr[h]){
            h++;
        }else{
            swap(arr[l+1],arr[h]);
            l++;
            h++;
        }
    }
    
    return l+1;
    
    
}