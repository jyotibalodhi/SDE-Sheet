int binarySearch(int low, int high, int *arr,int key){
    
    while(low<=high){
        
        int mid = low +(high-low)/2;
        
        if(arr[mid] ==key ){
           return mid;
        }
        else if(arr[mid] < key)
        {
            low = mid+1;
        }
        else{
            high =mid-1;
        }
    }
    
    return -1;
}


int search(int* arr, int n, int key) {
   
    
    if(n==0) return -1;
    if(n==1 && key==arr[0]) return 0;
    else if(n==1 && key != arr[0]) return -1;
    
    
    int low = 0;
    int high =n-1;
    int startInd=0;
    
    while(low<=high){
        
        int mid = low +(high-low)/2;
        
        int next = (mid +1)%n;
        int prev = (mid +n -1)%n;
        
        if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]){
            startInd = mid;
            break;
        }
        else if(arr[0]<= arr[mid]) //first half sorted
        {
            low = mid+1;
        }
        else{
            high =mid-1;
        }
    }
    int ind =-1;
    if(arr[startInd]<=key && arr[n-1]>=key) // key in second half 
    {
        ind = binarySearch(startInd,n-1,arr,key);
    }
    else{  //key in first half
        ind = binarySearch(0,startInd-1,arr,key);
    }
    return ind;
}