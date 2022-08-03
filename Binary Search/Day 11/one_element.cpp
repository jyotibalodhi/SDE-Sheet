int uniqueElement(vector<int> arr, int n)
{
    
    //I got you Nobita
    
	int s=0;
    int e=n-1;
    
    while(s<=e){
        int mid = s +(e-s)/2;

        if(arr[mid] != arr[mid -1] && arr[mid]!= arr[mid+1])
            return arr[mid];                         // found it
        
        else if(arr[mid-1] == arr[mid]){
            if((mid - s +1)%2 == 0)  // left side even, so unique no. at right
            {
                s = mid+1;
            }
            else{
               e = mid-2; 
            }
        }else{
            if((mid - s)%2 == 0) 
            {
                s = mid+2;
            }
            else{
               e = mid-1; 
            }
        }
    }
    
    return -1;
}
